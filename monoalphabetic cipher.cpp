#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
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
void generateCipher(char *cipher, const char *keyword) {
    int used[ALPHABET_SIZE] = {0}; 
    int index = 0;
    for (int i = 0; keyword[i] != '\0'; i++) {
        if (!used[toupper(keyword[i]) - 'A']) {
            cipher[index++] = toupper(keyword[i]);
            used[toupper(keyword[i]) - 'A'] = 1;
        }
    }
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        if (!used[letter - 'A']) {
            cipher[index++] = letter;
        }
    }

    cipher[index] = '\0'; 
}
void encrypt(char *plaintext, char *cipher) {
    printf("Encrypted text: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char letter = toupper(plaintext[i]);
            int position = letter - 'A';
            putchar(cipher[position]);
        } else {
            putchar(plaintext[i]); 
        }
    }
    printf("\n");
}
void decrypt(char *ciphertext, char *cipher) {
    printf("Decrypted text: ");
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char letter = toupper(ciphertext[i]);
            for (int j = 0; j < ALPHABET_SIZE; j++) {
                if (cipher[j] == letter) {
                    putchar('A' + j);
                    break;
                }
            }
        } else {
            putchar(ciphertext[i]); 
        }
    }
    printf("\n");
}

int main() {
    char keyword[] = "CIPHER";
    removeDuplicates(keyword); 
    char cipher[ALPHABET_SIZE + 1]; 
    generateCipher(cipher, keyword);
    printf("Keyword: %s\n", keyword);
    printf("Cipher alphabet: %s\n", cipher);
    char plaintext[] = "hello world";
    printf("Plaintext: %s\n", plaintext);
    encrypt(plaintext, cipher);
    char ciphertext[] = "RIJJP UJSJP";
    printf("Ciphertext: %s\n", ciphertext);
    decrypt(ciphertext, cipher);

    return 0;
}

