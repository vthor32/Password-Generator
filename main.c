#include <stdio.h>
#include <time.h>
#include "mtwister.h"
void generate_password(char *password, int length, MTRand *r) {
    const char charset[] = "!@#$?&*()abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int charset_size = sizeof(charset) - 1;

    for (int i = 0; i < length; ++i) {
        int index = (int)(genRand(r) * charset_size);
        password[i] = charset[index];
    }

    password[length] = '\0';
}

int main() {
    int PASSWORD_LENGTH;
    printf("Informe o numero de caracteres da senha desejada: \n");
    scanf("%d", &PASSWORD_LENGTH);
    MTRand r = seedRand((unsigned long)time(NULL));
    
    char password[PASSWORD_LENGTH + 1];
    generate_password(password, PASSWORD_LENGTH, &r);
    printf("Senha gerada: %s\n", password);

    return 0;
}
