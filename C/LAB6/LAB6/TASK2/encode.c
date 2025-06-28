#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 255
#define MAX_LEN     10

struct tnode {
    struct tnode* left;
    struct tnode* right;
    struct tnode* parent;
    struct tnode* next;
    float freq;
    int isleaf;
    char symbol;
};

// Global variables
char code[MAX_SYMBOLS][MAX_LEN];
struct tnode* root = NULL;
struct tnode* qhead = NULL;

// Allocate new tree node
struct tnode* talloc(int symbol, float freq) {
    struct tnode* p = (struct tnode*)malloc(sizeof(struct tnode));
    if (p != NULL) {
        p->left = p->right = p->parent = p->next = NULL;
        p->symbol = symbol;
        p->freq = freq;
        p->isleaf = 1;
    }
    return p;
}

// Priority Queue Insert
void pq_insert(struct tnode* p) {
    struct tnode *curr = qhead, *prev = NULL;

    if (qhead == NULL || p->freq < qhead->freq) {
        p->next = qhead;
        qhead = p;
        return;
    }

    while (curr != NULL && p->freq >= curr->freq) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = p;
    p->next = curr;
}

// Priority Queue Pop (remove front)
struct tnode* pq_pop() {
    if (qhead == NULL)
        return NULL;
    struct tnode* p = qhead;
    qhead = qhead->next;
    p->next = NULL;
    return p;
}

// Generate Huffman code using parent pointer
void generate_code(struct tnode* node, int depth) {
    if (node->isleaf) {
        int symbol = node->symbol;
        code[symbol][depth] = '\0';

        struct tnode* p = node;
        int i = depth - 1;
        while (p->parent != NULL) {
            if (p == p->parent->left)
                code[symbol][i--] = '0';
            else
                code[symbol][i--] = '1';
            p = p->parent;
        }

        printf("built code: %c -> %s\n", symbol, code[symbol]);
    } else {
        if (node->left)  generate_code(node->left, depth + 1);
        if (node->right) generate_code(node->right, depth + 1);
    }
}

// Write code table to file
void dump_code(FILE* fp) {
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        if (code[i][0]) {
            fprintf(fp, "%c %s\n", i, code[i]);
        }
    }
}

// Encode input string using code[]
void encode(const char* str, FILE* fout) {
    while (*str) {
        if (*str == ' ') {
            str++; // skip spaces
            continue;
        }
        fprintf(fout, "%s", code[*str]);
        str++;
    }
}

// Free the Huffman tree
void freetree(struct tnode* node) {
    if (!node) return;
    freetree(node->left);
    freetree(node->right);
    free(node);
}

// Main function
int main() {
    float freq[] = {0.01, 0.04, 0.05, 0.11, 0.19, 0.20, 0.4}; // a-g
    int NCHAR = 7;
    const char* test_string = "abba cafe bad";
    const char* CODE_FILE = "code.txt";
    const char* OUT_FILE = "encoded.txt";
    FILE* fout = NULL;

    memset(code, 0, sizeof(code));

    // Build priority queue
    for (int i = 0; i < NCHAR; i++) {
        pq_insert(talloc('a' + i, freq[i]));
    }

    // Build Huffman tree
    while (qhead && qhead->next) {
        struct tnode* lc = pq_pop();
        struct tnode* rc = pq_pop();
        struct tnode* parent = talloc(0, lc->freq + rc->freq);
        parent->isleaf = 0;
        parent->left = lc;
        parent->right = rc;
        lc->parent = rc->parent = parent;
        pq_insert(parent);
    }

    root = pq_pop();

    // Generate codes
    generate_code(root, 0);

    // Write code.txt
    fout = fopen(CODE_FILE, "w");
    dump_code(fout);
    fclose(fout);

    // Write encoded.txt
    fout = fopen(OUT_FILE, "w");
    printf("original: %s\nencoded: ", test_string);
    encode(test_string, stdout);   // print to screen
    encode(test_string, fout);     // save to file
    fclose(fout);

    // Cleanup
    freetree(root);
    getchar();
    return 0;
}
