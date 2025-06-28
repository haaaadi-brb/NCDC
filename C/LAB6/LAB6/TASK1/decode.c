#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 255
#define MAX_LEN     10

// Huffman tree node structure
struct tnode {
    struct tnode* left;
    struct tnode* right;
    int isleaf;
    char symbol;
};

// Global root of the Huffman tree
struct tnode* root = NULL;

/**
 * @function talloc
 * @desc Allocates a new tree node
 */
struct tnode* talloc() {
    struct tnode* p = (struct tnode*)malloc(sizeof(struct tnode));
    if (p != NULL) {
        p->left = p->right = NULL;
        p->symbol = 0;
        p->isleaf = 0;
    }
    return p;
}

/**
 * @function build_tree
 * @desc Builds the Huffman tree from symbol-code mapping in code.txt
 */
void build_tree(FILE* fp) {
    char symbol;
    char strcode[MAX_LEN];
    int items_read, i, len;
    struct tnode* curr = NULL;

    while (!feof(fp)) {
        items_read = fscanf(fp, " %c %s\n", &symbol, strcode);
        if (items_read != 2) break;

        curr = root;
        len = strlen(strcode);

        for (i = 0; i < len; i++) {
            if (strcode[i] == '0') {
                if (curr->left == NULL)
                    curr->left = talloc();
                curr = curr->left;
            } else if (strcode[i] == '1') {
                if (curr->right == NULL)
                    curr->right = talloc();
                curr = curr->right;
            }
        }

        curr->isleaf = 1;
        curr->symbol = symbol;
        printf("inserted symbol: %c\n", symbol);
    }
}

/**
 * @function decode
 * @desc Decodes binary input using the Huffman tree and writes to output
 */
void decode(FILE* fin, FILE* fout) {
    char c;
    struct tnode* curr = root;

    while ((c = getc(fin)) != EOF) {
        if (c == '0')
            curr = curr->left;
        else if (c == '1')
            curr = curr->right;
        else
            continue; // ignore unexpected characters like newline, space

        if (curr->isleaf) {
            fputc(curr->symbol, fout);
            curr = root;
        }
    }
}

/**
 * @function freetree
 * @desc Recursively frees memory for Huffman tree
 */
void freetree(struct tnode* root) {
    if (root == NULL)
        return;
    freetree(root->left);
    freetree(root->right);
    free(root);
}

/**
 * @function main
 * @desc Entry point: builds tree from code.txt, decodes encoded.txt to decoded.txt
 */
int main() {
    const char* IN_FILE = "encoded.txt";
    const char* CODE_FILE = "code.txt";
    const char* OUT_FILE = "decoded.txt";

    FILE* fout;
    FILE* fin;

    root = talloc(); // allocate root node

    // Build tree from code.txt
    fin = fopen(CODE_FILE, "r");
    if (!fin) {
        perror("Error opening code.txt");
        return 1;
    }
    build_tree(fin);
    fclose(fin);

    // Decode encoded.txt
    fin = fopen(IN_FILE, "r");
    fout = fopen(OUT_FILE, "w");
    if (!fin || !fout) {
        perror("Error opening input/output files");
        return 1;
    }

    decode(fin, fout);
    fclose(fin);
    fclose(fout);

    // Free memory
    freetree(root);

    printf("Decoding completed. Output saved in decoded.txt\n");
    getchar(); // pause the program
    return 0;
}
