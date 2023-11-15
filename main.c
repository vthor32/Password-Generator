#include <stdio.h>
#include <time.h>
#include "mtwister.h"

int strlen1(const char* str)
{
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return (i);
}
//Função para gerar senhas
void generate_password(char *password, int length, MTRand *r) {
    int num_IN, spe_IN;
    const char *charset;

    printf("Should the password have numbers? 0/1 (no/yes)\n");
    scanf("%d", &num_IN);
    //printf("%d", num_IN);
    printf("Should the password have special characters? 0/1 (no/yes)\n");
    scanf("%d", &spe_IN);
    //printf("%d", spe_IN);


    if (num_IN == 1 && spe_IN == 1) {
        charset = "!@#$?&*()+-./|',<.>;:¿[]{}^~`=abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    } else if (num_IN == 1) {
        charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    } else if (spe_IN == 1) {
        charset = "!@#$?&*()+-./|',<.>;:¿[]{}^~`=abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    } else {
        charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    const int charset_size = strlen1(charset);
    for (int i = 0; i < length; ++i) {
        int index = (int)(genRand(r) * charset_size);
        password[i] = charset[index];
    }
    password[length] = '\0';
}

int main() {
    int PASSWORD_LENGTH;
    printf("Enter the number of characters of the desired password: \n");
    scanf("%d", &PASSWORD_LENGTH);
    MTRand r = seedRand((unsigned long)time(NULL));
    
    char password[PASSWORD_LENGTH + 1];
    generate_password(password, PASSWORD_LENGTH, &r);
    printf("Senha gerada: %s\n", password);

    return 0;
}
