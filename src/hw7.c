#include "hw7.h"

bst_sf* insert_bst_sf(matrix_sf *mat, bst_sf *root) {
    if (root == NULL) {
        bst_sf *node = malloc(sizeof(bst_sf));
        node->mat = mat;
        node->left_child = NULL;
        node->right_child = NULL;
        return node;
    }
    bst_sf *current = root;
    while (1) {
        if (mat->name < current->mat->name) {
            if (current->left_child == NULL) {
                bst_sf *node = malloc(sizeof(bst_sf));
                node->mat = mat;
                node->left_child = NULL;
                node->right_child = NULL;
                current->left_child = node;
                break;
            }
            current = current->left_child;
        } else if (mat->name > current->nat->name) {
            if (current->right_child == NULL) {
                bst_sf *node = malloc(sizeof(bst_sf));
                node->mat = mat;
                node->left_child = NULL;
                node->right_child = NULL;
                current->right_child = node;
                break;
            }
            current = current->right_child;
        }
    }
    return root;
}

matrix_sf* find_bst_sf(char name, bst_sf *root) {
    bst_sf *current = root;
    while (1) {
        if (current == NULL) {
            break;
        } else if (current->mat->name == name) {
            return current->mat;
        } else if (name < current->mat->name) {
            current = current->left_child;
        } else if (name > current->mat->name) {
            current = current->right_child;
        }
    }
    return NULL;
}

void free_bst_sf(bst_sf *root) {
    if (root == NULL) {
        return;
    }
    if (root->left_child != NULL) {
        free_bst_sf(root->left_child);
    }
    if (root->right_child != NULL) {
        free_bst_sf(root->right_child);
    }
    free(root->mat);
    free(root);
}

matrix_sf* add_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
    matrix_sf *sum = malloc(sizeof(matrix_sf) + mat1->num_rows * mat2->num_cols * sizeof(int));
    sum->name = '?';
    sum->num_rows = mat1->num_rows;
    sum->num_cols = mat1->num_cols;
    for (int i = 0; i < (mat1->num_rows * mat2->num_cols); i++) {
        sum->values[i] = mat1->values[i] + mat2->values[i];
    }
    return sum;
}

matrix_sf* mult_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
    matrix_sf *product = malloc(sizeof(matrix_sf) + mat1->num_rows * mat2->num_cols * sizeof(int));
    product->name = '?';
    product->num_rows = mat1->num_rows;
    product->num_cols = mat2->num_cols;
    for (int i = 0; i < mat1->num_rows; i++) {
        for (int j = 0; j < mat2->num_cols; j++) {
            int sum = 0;
            for (int k = 0; k < mat1->num_cols) {
                sum += mat1->values[i * mat1->num_cols + k] * mat2->values[k * mat2->num_cols + j];
            }
            product->values[i * mat2->num_cols + j] = sum;
        }
    }
    return product;
}

matrix_sf* transpose_mat_sf(const matrix_sf *mat) {
    matrix_sf *transposed = malloc(sizeof(matrix_sf) + mat->num_cols * mat->num_rows * sizeof(int));
    transposed->name = '?';
    transposed->num_rows = mat->num_cols;
    transposed->num_cols = mat->num_rows;
    for (int i = 0; i < mat->num_rows; i++) {
        for (int j = 0; j < mat->num_cols; j++) {
            transposed->values[j * mat->num_rows + i] = mat->values[i * mat->num_cols + j];
        }
    }
    return transposed;
}

matrix_sf* create_matrix_sf(char name, const char *expr) {
    const char *p = expr;

    while (isspace(*p)) { p++; }
    char *end;
    int num_rows = strtol(p, &end, 10);
    p = end;

    while (isspace(*p)) { p++; }
    int num_cols = strtol(p, &end, 10);
    p = end;

    while (isspace(*p)) { p++; }
    assert(*p == '[');
    p++;

    matrix_sf *mat = malloc(sizeof(matrix_sf) + num_cols * num_rows * sizeof(int));
    mat->name = name;
    mat->num_rows = num_rows;
    mat->num_cols = num_cols;

    int row_count = 0;
    int col_count = 0;

    while (*p != ']') {
        while (*p != ';') {
            while (isspace(*p)) { p++; }
            if (*p == ';') {
                break;
            }
            mat->values[row_count * num_cols + col_count] = strtol(p, &end, 10);
            p = end;
            col_count++;
        }
        p++;
        row_count++;
        col_count = 0;
        while (isspace(*p)) { p++; }
    }

    return mat;
}

char* infix2postfix_sf(char *infix) {
    return NULL;
}

matrix_sf* evaluate_expr_sf(char name, char *expr, bst_sf *root) {
    return NULL;
}

matrix_sf *execute_script_sf(char *filename) {
    return NULL;
}

// This is a utility function used during testing. Feel free to adapt the code to implement some of
// the assignment. Feel equally free to ignore it.
matrix_sf *copy_matrix(unsigned int num_rows, unsigned int num_cols, int values[]) {
    matrix_sf *m = malloc(sizeof(matrix_sf)+num_rows*num_cols*sizeof(int));
    m->name = '?';
    m->num_rows = num_rows;
    m->num_cols = num_cols;
    memcpy(m->values, values, num_rows*num_cols*sizeof(int));
    return m;
}

// Don't touch this function. It's used by the testing framework.
// It's been left here in case it helps you debug and test your code.
void print_matrix_sf(matrix_sf *mat) {
    assert(mat != NULL);
    assert(mat->num_rows <= 1000);
    assert(mat->num_cols <= 1000);
    printf("%d %d ", mat->num_rows, mat->num_cols);
    for (unsigned int i = 0; i < mat->num_rows*mat->num_cols; i++) {
        printf("%d", mat->values[i]);
        if (i < mat->num_rows*mat->num_cols-1)
            printf(" ");
    }
    printf("\n");
}
