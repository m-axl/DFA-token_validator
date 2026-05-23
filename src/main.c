/**
 * @file main.c
 * @brief Validador de tokens usando Autômato Finito Determinístico (DFA)
 * 
 * Este programa implementa um DFA para validar tokens com o seguinte formato:
 * - Deve começar com um underscore (_)
 * - Seguido por pelo menos uma letra minúscula
 * - Pode conter letras minúsculas e dígitos após as letras iniciais
 * 
 * Padrão: ^_[a-z]+[a-z0-9]*$
 * 
 * Estados do DFA:
 *   Estado 0: Inicial - aguardando '_'
 *   Estado 1: Após '_' - aguardando pelo menos uma letra minúscula
 *   Estado 2: Aceitação - permite letras minúsculas e dígitos
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * main - Função principal do validador de tokens
 * 
 * Utiliza um autômato finito determinístico para validar que um token
 * esteja de acordo com o padrão estabelecido. Lê o token caractere por
 * caractere e realiza transições de estado baseadas no caractere atual.
 * 
 * @return 0 se o token é válido, 1 se há erro
 */
int main () {
    // Cadeia de teste para validar
    // Exemplos válidos: "_token42", "_abc123", "_x"
    // Exemplos inválidos: "token42", "_123", "_T"
    char entered[] = "_token42"; 

    // Variável que armazena o estado atual do DFA
    // 0 = Inicial, 1 = Pós-underscore, 2 = Aceitação
    int estado = 0;

    // Itera sobre cada caractere do token até encontrar o terminador nulo
    for (int i = 0; entered[i] != '\0'; i++) {

        // Caractere atual sendo avaliado
        char c = entered[i]; 
        
        // Máquina de estados determinística
        switch (estado) {
            // Estado 0: Validar primeiro caractere (deve ser '_')
            case 0:
                if (c == '_') {
                    // Transição válida para o estado 1
                    estado = 1;
                } else {
                    // Erro: o primeiro caractere não é um underscore
                    printf("Erro: O token deve começar com '_'\n");
                    return 1;
                }
                break;

            // Estado 1: Validar primeira letra (deve ser minúscula)
            case 1:
                if (c >= 'a' && c <= 'z') {
                    // Transição válida para o estado 2 (aceitação)
                    estado = 2;
                } else {
                    // Erro: o caractere após '_' não é uma letra minúscula
                    printf("Erro: O token deve conter letras minúsculas após '_'\n");
                    return 1;
                }
                break;

            // Estado 2: Validar caracteres posteriores (letras minúsculas ou dígitos)
            case 2:
                if (c >= 'a' && c <= 'z') {
                    // Caractere válido: letra minúscula
                    // Permanece no estado 2
                } else if (c >= '0' && c <= '9') {
                    // Caractere válido: dígito
                    // Permanece no estado 2
                } else {
                    // Erro: caractere não permitido neste estado
                    printf("Erro: O token pode conter apenas letras minúsculas e dígitos após '_'\n");
                    return 1;
                }
                break;
        }
    }
    
    // Se o processamento foi concluído sem erros, o token é válido
    printf("Token válido\n");
    return 0;
}