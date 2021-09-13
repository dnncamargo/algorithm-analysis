#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "symmatrix.csv"

int** rfsqrmatrix(const char*, int);
void printmatrix(int**, int);

int main(int argc, char *argv[]) {
    int size = atoi(argv[1]); // ordem da matriz informada via argv
    int** mat = rfsqrmatrix(FILENAME, size); // lê arquivo csv contendo a matriz
    printmatrix(mat, size);
}

/**
 * Lê uma matriz quadrada de um arquivo separado por vírgulas
 * @param filename nome do arquivo a ser lido
 * @param size ordem da matriz quadrada
 */
int** rfsqrmatrix(const char* filename, int size) {
    
    FILE* fp = fopen(filename,"r");
    if (fp == NULL) {
        fprintf(stderr, "error: while trying to open '%s' for reading\n", filename);
        fclose(fp);
        return NULL;
    } else {
        int i = 0;
        int j = 0;
        int** mat = malloc(sizeof(int*) * size);
        char strline[128];
        char* token = NULL;
        while (fgets( strline, sizeof(strline), fp) != NULL && i < size) {
            
            mat[i] = malloc(sizeof(int) * size);
            for (token = strtok( strline, ";"); token != NULL && j < size; token = strtok(NULL, ";")) {
                mat[i][j++] = atoi(token);
            }
            i++;
        }
        fclose(fp);
        return mat;
    }
}

/**
 * Imprime a matriz
 */
void printmatrix(int** mat, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            printf("%d   ", mat[i][j]);
    putchar('\n');
    }
}