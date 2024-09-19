#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
#define MATRIX_SIZE 25
void removeDuplicates(char *str) {
    int index = 0;
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
        if (j == i) {
            str[index++] = str[i]; 
        }
    }
    str[index] = '\0'; 
}
void generatePlayfairMatrix(char matrix[SIZE][SIZE], const char *keyword) {
    int used[26] = {0};
    int index = 0;
    char letter;
    for (int i = 0; keyword[i] != '\0'; i++) {
        letter = toupper(keyword[i]);
        if (letter == 'J') letter = 'I'; 
        if (!used[letter - 'A']) {
            matrix[index / SIZE][index % SIZE] = letter;
            used[letter - 'A'] = 1;
            index++;
        }
    }
    for (letter = 'A'; letter <= 'Z'; letter++) {
        if (letter == 'J') continue; 
        if (!used[letter - 'A']) {
            matrix[index / SIZE][index % SIZE] = letter;
            used[letter - 'A'] = 1;
            index++;
        }
    }
}
void findPosition(char matrix[SIZE][SIZE], char letter, int *row, int *col) {
    if (letter == 'J') letter = 'I'; // Treat 'J' as 'I'
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void decryptDigraph(char matrix[SIZE][SIZE], char a, char b, char *result) {
    int row1, col1, row2, col2;
    findPosition(matrix, a, &row1, &col1);
    findPosition(matrix, b, &row2, &col2);

    if (row1 == row2) {
        result[0] = matrix[row1][(col1 + SIZE - 1) % SIZE];
        result[1] = matrix[row2][(col2 + SIZE - 1) % SIZE];
    } else if (col1 == col2) {
        result[0] = matrix[(row1 + SIZE - 1) % SIZE][col1];
        result[1] = matrix[(row2 + SIZE - 1) % SIZE][col2];
    } else {
        result[0] = matrix[row1][col2];
        result[1] = matrix[row2][col1];
    }
}
void decryptPlayfair(char *ciphertext, char matrix[SIZE][SIZE]) {
    char digraph[2];
    char result[2];
    printf("Decrypted text: ");
    for (int i = 0; i < strlen(ciphertext); i += 2) {
        digraph[0] = toupper(ciphertext[i]);
        digraph[1] = toupper(ciphertext[i + 1]);
        decryptDigraph(matrix, digraph[0], digraph[1], result);
        printf("%c%c", result[0], result[1]);
    }
    printf("\n");
}
int main() {
    char keyword[] = "KEYWORD";
    removeDuplicates(keyword); 
    char matrix[SIZE][SIZE];
    generatePlayfairMatrix(matrix, keyword);
    printf("Playfair matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    char ciphertext[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    printf("Ciphertext: %s\n", ciphertext);
    decryptPlayfair(ciphertext, matrix);
    return 0;
}

