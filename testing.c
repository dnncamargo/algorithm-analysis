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
    int rowIndex = 0;
    int** rows = malloc(sizeof(int*) * size);
    char line[128];
    char* token = NULL;
    FILE* fp = fopen(filename,"r");
    if (fp == NULL) {
        fprintf(stderr, "error: while trying to open '%s' for reading\n", filename);
        fclose(fp);
        return NULL;
    } else {
        while (fgets( line, sizeof(line), fp) != NULL && rowIndex < size) {
            int colIndex = 0;
            rows[rowIndex] = malloc(sizeof(int) * size);
            for (token = strtok( line, ";"); token != NULL && colIndex < size; token = strtok(NULL, ";")) {
                rows[rowIndex][colIndex++] = atoi(token);
            }
            rowIndex++;
        }
        fclose(fp);
    }
    return rows;
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
/*


int main(){
    int outer, inner;
   // [outer][inner]
    char charr[5][10] = {{'0', ';', '1', ';', '2', ';', '3', ';', '4', '\0'},
                         {'5', ';', '6', ';', '7', ';', '8', ';', '9', '\0'},
                         {'1', ';', '4', ';', '7', ';', '0', ';', '3', '\0'},
                         {'2', ';', '5', ';', '8', ';', '1', ';', '4', '\0'},
                         {'3', ';', '6', ';', '9', ';', '2', ';', '5', '\0'}};
    printf(":>%s\n\n", charr[1]);

    FILE *fp;  
    char buff[255];//creating char array to store data of file  
    fp = fopen("symmatrix.csv", "r");  

    fscanf(fp, "%s", buff);
    printf("~>%s\n", buff[0]);
    fscanf(fp, "%s", buff);
    printf("~>%s\n", buff[1]);
    fscanf(fp, "%s", buff);
    printf("~>%s\n", buff[2]);
    fscanf(fp, "%s", buff);
    printf("~>%s\n", buff[3]);
    fscanf(fp, "%s", buff);
    printf("~>%s\n", buff[4]);


    while(fscanf(fp, "%[^\n]", buff)!=EOF){  
        printf(":>%s\n", buff );  
    }  
    fclose(fp);  
}
&*/