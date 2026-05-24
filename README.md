# Validador de Tokens - DFA

Implementação de **Autômatos Finitos Determinísticos (DFA)** em C para validar diferentes padrões.

## Estrutura do Projeto

```
DFA-token_validator/
├── README.md              # Este arquivo
├── src/
│   ├── main.c             # Validador de tokens com formato ^_[a-z]+[a-z0-9]*$
│   ├── DFA_form_mod.c     # Validador de números inteiros positivos
│   └── output/            # Executáveis compilados
├── docs/                  # Documentação adicional
├── build/                 # Arquivos de compilação
└── output/                # Saída do programa
```

## Validadores Implementados

### 1. main.c - Validador de Tokens

Valida tokens com o seguinte padrão:

```
^_[a-z]+[a-z0-9]*$
```

Tokens devem começar com `_`, seguidos de letras minúsculas e opcionalmente dígitos.

**Exemplos válidos:** `_token`, `_token42`, `_x`  
**Exemplos inválidos:** `token`, `_123`, `_Token`

**Estados do DFA:**
- Estado 0: Inicial - aguardando `_`
- Estado 1: Após `_` - aguardando pelo menos uma letra minúscula
- Estado 2: Aceitação - permite letras minúsculas e dígitos

### 2. DFA_form_mod.c - Validador de Números Inteiros Positivos

Valida números inteiros positivos (sem sinal negativo ou casas decimais).

**Padrão:** `^[0-9]+$`

**Exemplos válidos:** `0`, `1`, `123`, `456789`  
**Exemplos inválidos:** `-1`, `1.5`, `.5`, `5.`, `abc`, `12a`

**Estados do DFA:**
- Estado 0: Inicial - aguardando primeiro dígito
- Estado 1: Aceitação - permite dígitos consecutivos

## Compilação e Execução

```bash
# Compilar validador de tokens
gcc -Wall -Wextra -o src/output/main src/main.c
./src/output/main

# Compilar validador de números inteiros
gcc -Wall -Wextra -o src/output/DFA_form_mod src/DFA_form_mod.c
./src/output/DFA_form_mod
```

## Diagrama de Fluxo

```
                    ┌─────────────────┐
                    │  Início         │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ estado = 0      │
                    │ i = 0           │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ Próximo char    │
                    │ = '\0' ?        │
                    └────┬────────┬───┘
                         │ Sim    │ Não
                         │        ▼
                         │    ┌───────────┐
                         │    │ Processar │
                         │    │ Caractere │
                         │    └─────┬─────┘
                         │          │
                         │          ▼
                         │    ┌──────────────────┐
                         │    │ Estado = 0?      │
                         │    │ Char = '_'?      │
                         │    └───┬──────────┬───┘
                         │        │ Sim      │ Não
                         │        │          ▼
                         │        │      ┌──────────┐
                         │        │      │  Erro 1  │
                         │        │      └──────┬───┘
                         │        │             │
                         │        ▼             │
                         │    ┌──────────────────┐
                         │    │ estado = 1       │
                         │    │ Próximo char     │
                         │    └────────┬─────────┘
                         │             │
                         │             ▼
                         │    ┌──────────────────┐
                         │    │ Estado = 1?      │
                         │    │ Char [a-z]?      │
                         │    └───┬──────────┬───┘
                         │        │ Sim      │ Não
                         │        │          ▼
                         │        │      ┌──────────┐
                         │        │      │  Erro 2  │
                         │        │      └──────┬───┘
                         │        │             │
                         │        ▼             │
                         │    ┌──────────────────┐
                         │    │ estado = 2       │
                         │    │ Próximo char     │
                         │    └────────┬─────────┘
                         │             │
                         │             ▼
                         │    ┌──────────────────┐
                         │    │ Estado = 2?      │
                         │    │ Char [a-z0-9]?   │
                         │    └───┬──────────┬───┘
                         │        │ Sim      │ Não
                         │        │          ▼
                         │        │      ┌──────────┐
                         │        │      │  Erro 3  │
                         │        │      └──────┬───┘
                         │        │             │
                         │        ▼             │
                         │    ┌──────────────────┐
                         │    │ Permanecer       │
                         │    │ estado = 2       │
                         │    │ Próximo char     │
                         │    └────────┬─────────┘
                         │             │
                         └─────────┬───┘
                                   │
                                   ▼
                        ┌──────────────────────┐
                        │ Retornar sucesso     │
                        │ (Token válido)       │
                        └──────────────────────┘
```

## Estados do DFA

| Estado | Descrição | Transições |
|--------|-----------|-----------|
| **0** | Inicial | Aceita `_` → Estado 1 |
| **1** | Pós-underscore | Aceita `[a-z]` → Estado 2 |
| **2** | Aceitação | Aceita `[a-z0-9]` → Estado 2 |

## Documentação

- **[Documentação Técnica](docs/README.md)** - Especificação completa, algoritmo e análise
- **[Código Comentado](src/main.c)** - Implementação com documentação inline

## Estrutura

```
├── src/main.c          Código-fonte
├── docs/README.md      Documentação técnica
├── output/main         Executável compilado
└── README.md           Este arquivo
```

---

**Data:** 23 de maio de 2026
