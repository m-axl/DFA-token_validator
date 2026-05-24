# Documentação Técnica - DFA Validators

Projeto de implementação de **Autômatos Finitos Determinísticos (DFA)** em linguagem C.

## 📑 Índice da Documentação

### Validadores Implementados

| Arquivo | Padrão | Descrição |
|---------|--------|-----------|
| [main.c](validador_tokens.md) | `^_[a-z]+[a-z0-9]*$` | Valida tokens com underscore inicial |
| [DFA_form_mod.c](validador_numeros.md) | `^[0-9]+$` | Valida números inteiros positivos |

## 📁 Estrutura do Projeto

```
DFA-token_validator/
├── src/
│   ├── main.c              # Validador de tokens
│   ├── DFA_form_mod.c      # Validador de números
│   └── output/             # Executáveis compilados
├── docs/
│   ├── readme.md           # Este arquivo
│   ├── validador_tokens.md # Documentação detalhada do main.c
│   └── validador_numeros.md # Documentação detalhada do DFA_form_mod.c
├── build/                  # Artefatos de compilação
└── README.md               # Guia rápido do projeto
```

## 🔧 Compilação Rápida

```bash
# Validador de tokens
gcc -Wall -Wextra -O2 -o src/output/main src/main.c

# Validador de números
gcc -Wall -Wextra -O2 -o src/output/DFA_form_mod src/DFA_form_mod.c
```

## 📚 Documentação Detalhada

- **[Validador de Tokens](validador_tokens.md)** - Especificação completa, DFA, algoritmo e implementação do main.c
- **[Validador de Números](validador_numeros.md)** - Especificação completa, DFA, algoritmo e implementação do DFA_form_mod.c

**Sucesso:**
```
Token válido
```

**Erros:**
```
Erro: O token deve começar com '_'
Erro: O token deve conter letras minúsculas após '_'
Erro: O token pode conter apenas letras minúsculas e dígitos após '_'
```

## 7. Análise de Complexidade

### 7.1 Complexidade Temporal
- **Melhor caso:** O(1) - Rejeição no primeiro caractere
- **Caso médio:** O(n) - n caracteres na entrada
- **Pior caso:** O(n) - Percorre toda a cadeia

Onde n é o tamanho da entrada.

### 7.2 Complexidade Espacial
- O(1) - Usa apenas duas variáveis: `estado` e índice do loop

## 8. Casos de Teste

### 8.1 Entrada Válida
- `_a` - Mínimo válido
- `_token` - Padrão simples
- `_token123` - Com dígitos
- `_a1b2c3` - Alternância

### 8.2 Entrada Inválida
- `token` - Sem underscore
- `_` - Só underscore
- `_1` - Dígito logo após `_`
- `_Token` - Maiúscula
- `_token_123` - Underscore no meio
- `_ token` - Espaço


## 09. Referências

- Hopcroft, J. E., Motwani, R., & Ullman, J. D. (2006). *Introduction to Automata Theory, Languages, and Computation*
- Teoria de Autômatos Finitos Determinísticos


---

**Data:** 23 de maio de 2026  

