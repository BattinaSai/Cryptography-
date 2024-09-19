#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
#define MATRIX_SIZE 25
char playfairMatrix[SIZE][SIZE] = {
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};
void findPosition(char letter, int *row, int *col) {
    if (letter == 'J') letter = 'I'; 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (playfairMatrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encryptDigraph(char a, char b, char *result) {
    int row1, col1, row2, col2;
    findPosition(toupper(a), &row1, &col1);
    findPosition(toupper(b), &row2, &col2);

    if (row1 == row2) {
        result[0] = playfairMatrix[row1][(col1 + 1) % SIZE];
        result[1] = playfairMatrix[row2][(col2 + 1) % SIZE];
    } else if (col1 == col2) {
        result[0] = playfairMatrix[(row1 + 1) % SIZE][col1];
        result[1] = playfairMatrix[(row2 + 1) % SIZE][col2];
    } else {
        result[0] = playfairMatrix[row1][col2];
        result[1] = playfairMatrix[row2][col1];
    }
}
void preprocessPlaintext(char *plaintext, char *output) {
    int len = strlen(plaintext);
    int k = 0;

    for (int i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            output[k++] = toupper(plaintext[i]);
        }
    }
    char finalText[100] = {0};
    int finalIndex = 0;

    for (int i = 0; i < k; i++) {
        finalText[finalIndex++] = output[i];
        if (i + 1 < k && output[i] == output[i + 1]) {
            finalText[finalIndex++] = 'X'; 
        }
    }

    if (finalIndex % 2 != 0) {
        finalText[finalIndex++] = 'X'; 
    }

    strcpy(output, finalText);
}
void encryptPlayfair(char *plaintext) {
    char preparedText[100] = {0};
    preprocessPlaintext(plaintext, preparedText);

    printf("Prepared text (digraphs): %s\n", preparedText);

    printf("Encrypted message: ");
    for (int i = 0; i < strlen(preparedText); i += 2) {
        char digraph[2] = {preparedText[i], preparedText[i + 1]};
        char result[2];
        encryptDigraph(digraph[0], digraph[1], result);
        printf("%c%c", result[0], result[1]);
    }
    printf("\n");
}
int main() {
    char message[] = "Must see you over Cadogan West. Coming at once.";
    printf("Original message: %s\n", message);
    encryptPlayfair(message);

    return 0;
}

