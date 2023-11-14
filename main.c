#include <stdio.h>
#include <time.h>
#include "mtwister.h"

//Função para retornar os caracteres que podem ser usados na senha
char password_characters(int num_IN,int spe_IN){
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (num_IN == 1 && spe_IN == 1){
        char charset[] = "!@#$?&*()+-./|',<.>;:¿[]{}^~`=abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    }else if(num_IN == 1 && spe_IN == 0){
        char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    }else if(num_IN == 0 && spe_IN == 1){
        char charset[] = "!@#$?&*()+-./|',<.>;:¿[]{}^~`=abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }else{
        
    }
    return charset;
}

//Função para gerar senhas
void generate_password(char *password, int length, MTRand *r){
    int num_IN, spe_IN;
    printf("Should the password have numbers? 0/1 (no/yes) \n");
    scanf("%d", &num_IN);
    printf("Should the password have speecial characters? 0/1 (no/yes) \n");
    scanf("%d", &spe_IN);
    
    const char charset[] = password_characters(num_IN, spe_IN);
    const int charset_size = sizeof(charset) - 1;

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
