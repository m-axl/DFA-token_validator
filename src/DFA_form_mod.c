/*
    DFA que reconheça;
    -----------------
    Numeros inteiros positivos, ou seja, sem o sinal de menos e sem o ponto decimal.

    Invalidos - -1, 1.5, .5, 5., abc, 12a, a12, 1a2  |    Validos - 0, 1, 2, 3, 4, 5, 6, 
     1.2.3, 1..2, 1.-2, -1.2, -1.2.3, -1..2, -1.-2   |    123, 456, 789, 1000,

     Regras: 
        1. O número deve começar com um dígito de 0 a 9.
        2. O número pode conter apenas dígitos de 0 a 9.
        3. O número não pode conter sinais de menos ou pontos decimais.
        4. O número deve conter pelo menos um dígito.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    char entrada[] = "123"; // Cadeia de teste para validar
    int estado = 0; // Estado inicial do DFA
    for (int i = 0; entrada[i] != '\0'; i++) {
        char c = entrada[i]; // Caractere atual sendo avaliado

        switch (estado) {
            case 0: // Estado inicial
                if (c >= '0' && c <= '9') {
                    estado = 1; // Transição para o estado de aceitação
                } else {
                    printf("Entrada inválida!\n");
                    return 1;
                }
                break;
            case 1: // Estado de aceitação
                if (c >= '0' && c <= '9') {
                    estado = 1; // Permanece no estado de aceitação
                } else {
                    printf("Entrada inválida!\n");
                    return 1;
                }
                break;
        }
    }
    printf("Entrada válida!\n");
    return 0;
}
