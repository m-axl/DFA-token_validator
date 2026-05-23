# Validador de Tokens - DFA

Validador de tokens usando **Autômato Finito Determinístico (DFA)** implementado em C.

## Padrão

```
^_[a-z]+[a-z0-9]*$
```

Tokens devem começar com `_`, seguidos de letras minúsculas e opcionalmente dígitos.

**Exemplos válidos:** `_token`, `_token42`, `_x`  
**Exemplos inválidos:** `token`, `_123`, `_Token`

## Uso Rápido

```bash
# Compilar
gcc -o output/main src/main.c

# Executar
./output/main
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
