#include <stdio.h>
#include <string.h>
#define MOD 26
void multiplyMatrix(int a[2][2], int b[2], int result[2]) {
    result[0] = (a[0][0] * b[0] + a[0][1] * b[1]) % MOD;
    result[1] = (a[1][0] * b[0] + a[1][1] * b[1]) % MOD;
}
void hillCipherEncrypt(char plaintext[], int key[2][2], char ciphertext[]) {
    int i, pt[2], ct[2];
    int len = strlen(plaintext);
    for (i = 0; i < len; i += 2) {
        pt[0] = plaintext[i] - 'a';
        pt[1] = plaintext[i + 1] - 'a';
        
        multiplyMatrix(key, pt, ct);
        
        ciphertext[i] = (ct[0] + MOD) % MOD + 'a';
        ciphertext[i + 1] = (ct[1] + MOD) % MOD + 'a';
    }
    ciphertext[len] = '\0';
}
int main() {
    char plaintext[] = "meetme";
    char ciphertext[100];
    int key[2][2] = {
        {9, 4},
        {5, 7}
    };
    hillCipherEncrypt(plaintext, key, ciphertext);
    
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}

