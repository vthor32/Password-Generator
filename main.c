#include <stdio.h>
#include <time.h>
#include "mtwister.h"

//Função calcula tamanho array
int strlen1(const char* str)
{
    if(str == NULL){
        return 0;
    }
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
        charset = "0123456789!@#$?&*()+-./|',<.>;:¿[]{}^~`=abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    } else if (num_IN == 1) {
        charset = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
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

//Função incluir sequencia de caracteres
void include_char(char* password, int which_char, char* sequence){
    int j = 0;
    int password_size = strlen1(password);
    int sequence_size = strlen1(sequence);
    printf("sequence: %s\n", sequence);

    while(j<sequence_size){
        password[which_char - 1] = sequence[j];
        which_char++;
        j++;
    }
    printf("Generated password: %s\n", password);
}

int main() {
    int PASSWORD_LENGTH, seq_spe_IN, which_char;
    char sequence[10];
    printf("Enter the number of characters of the desired password: \n");
    scanf("%d", &PASSWORD_LENGTH);
    MTRand r = seedRand((unsigned long)time(NULL));
    
    char password[PASSWORD_LENGTH + 1];
    generate_password(password, PASSWORD_LENGTH, &r);
    printf("Do you want to include a specific sequence characters in your password? 0/1 (no/yes)\n");
    scanf("%d",&seq_spe_IN);
    if(seq_spe_IN == 1){
        printf("From which character? (number)\n");
        scanf("%d",&which_char);
        printf("Which is your sequece character? \n");
        scanf("%s",sequence);
        include_char(password, which_char, sequence);
    }else if(seq_spe_IN == 0){
        printf("Generated password: %s\n", password);
    }

    return 0;
}
