#include <stdio.h>
#include <string.h>
#include <ctype.h>
void monoalphabeticEncrypt(char* plaintext, char* key, char* ciphertext) {
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
    int i, j;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (isalpha(ch)) {
            if (isupper(ch)) {
                j = ch - 'A';  
                ciphertext[i] = key[j];  
            } else if (islower(ch)) {
                j = ch - 'a';  
                ciphertext[i] = tolower(key[j]);  
            }
        } else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0';
}
int main() {
    char plaintext[100];
    char ciphertext[100];
    char key[] = "QWERTYUIOPLKJHGFDSAZXCVBNM"; 
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    monoalphabeticEncrypt(plaintext, key, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);
    return 0;
}

