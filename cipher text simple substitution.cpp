#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 256

// Function to analyze character frequencies
void analyzeFrequency(char ciphertext[]) {
    int freq[MAX_CHARS] = {0};
    int length = strlen(ciphertext);
    for (int i = 0; i < length; i++) {
        if (isprint(ciphertext[i])) {
            freq[(unsigned char)ciphertext[i]]++;
        }
    }
    printf("Character Frequencies in the Ciphertext:\n");
    for (int i = 0; i < MAX_CHARS; i++) {
        if (freq[i] > 0) {
            printf("'%c' -> %d\n", i, freq[i]);
        }
    }
}

int main() {
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83"
                        "(88)5*†;46(;88*96*?;8)‡(;485);5†2:‡(;4956*2(5—4)8¶8*"
                        ";4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81"
                        "(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?";
    
    analyzeFrequency(ciphertext);
    
    return 0;
}
