#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 256
#define MAX_LEN     64

struct tnode {
    struct tnode* left;
    struct tnode* right;
    struct tnode* parent;
    struct tnode* next;
    float freq;
    int isleaf;
    char symbol;
};

char code[MAX_SYMBOLS][MAX_LEN];
struct tnode* root = NULL;
struct tnode* qhead = NULL;
int char_freq[MAX_SYMBOLS] = {0};

// Allocate a tree node
struct tnode* talloc(int symbol, float freq) {
    struct tnode* p = (struct tnode*)malloc(sizeof(struct tnode));
    if (p) {
        p->left = p->right = p->parent = p->next = NULL;
        p->symbol = symbol;
        p->freq = freq;
        p->isleaf = 1;
    }
    return p;
}

// Insert into priority queue
void pq_insert(struct tnode* p) {
    struct tnode *curr = qhead, *prev = NULL;

    while (curr && p->freq >= curr->freq) {
        prev = curr;
        curr = curr->next;
    }

    p->next = curr;
    if (prev) prev->next = p;
    else qhead = p;
}

// Pop from priority queue
struct tnode* pq_pop() {
    if (!qhead) return NULL;
    struct tnode* p = qhead;
    qhead = qhead->next;
    p->next = NULL;
    return p;
}

// Generate code strings using parent pointers
void generate_code(struct tnode* node, int depth) {
    if (node->isleaf) {
        int symbol = (unsigned char)node->symbol;
        code[symbol][depth] = '\0';
        struct tnode* p = node;
        int i = depth - 1;
        while (p->parent) {
            if (p == p->parent->left)
                code[symbol][i--] = '0';
            else
                code[symbol][i--] = '1';
            p = p->parent;
        }
        printf("built code: %c (%d) -> %s\n", symbol, symbol, code[symbol]);
    } else {
        if (node->left)  generate_code(node->left, depth + 1);
        if (node->right) generate_code(node->right, depth + 1);
    }
}

// Output codes to file
void dump_code(FILE* fp) {
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        if (code[i][0]) {
            fprintf(fp, "%c %s\n", i, code[i]);
        }
    }
}

// Encode input file into binary codes
void encode(FILE* fin, FILE* fout) {
    int c;
    while ((c = fgetc(fin)) != EOF) {
        if (code[c][0]) {
            fputs(code[c], fout);
        }
    }
}

// Free the Huffman tree
void freetree(struct tnode* node) {
    if (!node) return;
    freetree(node->left);
    freetree(node->right);
    free(node);
}

int main() {
    FILE *fin, *fout;
    const char* IN_FILE = "book.txt";
    const char* CODE_FILE = "code.txt";
    const char* OUT_FILE = "encoded.txt";

    memset(code, 0, sizeof(code));
    memset(char_freq, 0, sizeof(char_freq));

    // Step 1: Read file and count frequencies
    fin = fopen(IN_FILE, "r");
    if (!fin) {
        perror("Error opening book.txt");
        return 1;
    }

    int total = 0, c;
    while ((c = fgetc(fin)) != EOF) {
        char_freq[c]++;
        total++;
    }
    fclose(fin);

    // Step 2: Build priority queue
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        if (char_freq[i] > 0) {
            pq_insert(talloc(i, (float)char_freq[i] / total));
        }
    }

    // Step 3: Build Huffman tree
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

    // Step 4: Generate codes
    generate_code(root, 0);

    // Step 5: Save code.txt
    fout = fopen(CODE_FILE, "w");
    if (!fout) {
        perror("Error writing code.txt");
        return 1;
    }
    dump_code(fout);
    fclose(fout);

    // Step 6: Encode book.txt to encoded.txt
    fin = fopen(IN_FILE, "r");
    fout = fopen(OUT_FILE, "w");
    if (!fin || !fout) {
        perror("Error during encoding");
        return 1;
    }
    encode(fin, fout);
    fclose(fin);
    fclose(fout);

    printf("✅ book.txt compressed successfully.\n");
    printf("→ Output files: encoded.txt and code.txt\n");

    freetree(root);
    getchar();
    return 0;
}
