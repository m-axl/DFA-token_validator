# Documentação Técnica - Validador de Tokens DFA

## 1. Introdução

Este documento apresenta a documentação técnica completa do projeto **Validador de Tokens com DFA** (Autômato Finito Determinístico), implementado em linguagem C.

## 2. Especificação do Problema

### 2.1 Objetivo
Implementar um validador de tokens que aceite apenas tokens que seguem um padrão específico, utilizando teoria de autômatos finitos determinísticos.

### 2.2 Padrão Aceitável
```
^_[a-z]+[a-z0-9]*$
```

**Regras:**
- Deve começar com underscore (`_`)
- Seguido por uma ou mais letras minúsculas
- Pode conter letras minúsculas e dígitos após as letras iniciais
- Rejeita letras maiúsculas, caracteres especiais e espaços

### 2.3 Exemplos
| Entrada | Válido | Motivo |
|---------|--------|--------|
| `_token` | ✓ | Segue padrão |
| `_token42` | ✓ | Letras + dígitos |
| `_x` | ✓ | Mínimo válido |
| `token42` | ✗ | Não começa com `_` |
| `_123` | ✗ | Sem letra após `_` |
| `_Token` | ✗ | Letra maiúscula |
| `_token-42` | ✗ | Caractere especial |

## 3. Autômato Finito Determinístico

### 3.1 Componentes

**Estados:** {0, 1, 2}
- **q₀**: Estado inicial
- **q₁**: Estado intermediário (após underscore)
- **q₂**: Estado de aceitação

**Alfabeto:** {_, a-z, A-Z, 0-9, ...}

**Estado Inicial:** q₀

**Estados Finais:** {q₂} (ao fim da entrada)

### 3.2 Tabela de Transições

| Estado | '_' | [a-z] | [0-9] | Outros |
|--------|-----|-------|-------|--------|
| q₀ | q₁ | ✗ | ✗ | ✗ |
| q₁ | ✗ | q₂ | ✗ | ✗ |
| q₂ | ✗ | q₂ | q₂ | ✗ |

**Legenda:**
- ✓ = Transição válida
- ✗ = Rejeição

### 3.3 Função de Transição (δ)

```
δ(q₀, '_') = q₁
δ(q₁, c ∈ [a-z]) = q₂
δ(q₂, c ∈ [a-z]) = q₂
δ(q₂, c ∈ [0-9]) = q₂
```

## 4. Arquitetura da Solução

### 4.1 Estrutura do Projeto

```
/
├── src/
│   └── main.c              # Implementação do validador
├── docs/
│   └── README.md           # Esta documentação
├── output/
│   └── main               # Executável compilado
├── build/                 # Artefatos de compilação
└── README.md              # Guia rápido
```

### 4.2 Componentes do Código

**Arquivo:** `src/main.c`

**Funções:**
- `main()` - Função principal com lógica do DFA

**Variáveis:**
- `entered[]` - Cadeia de entrada (token a validar)
- `estado` - Estado atual da máquina
- `c` - Caractere atual sendo processado

## 5. Algoritmo

### 5.1 Pseudocódigo

```
função validar_token(entrada: string) → inteiro
    estado ← 0
    para cada caractere c em entrada faça
        se estado = 0 então
            se c = '_' então
                estado ← 1
            senão
                retorna erro("Deve começar com '_'")
            fim se
        senão se estado = 1 então
            se c ∈ [a-z] então
                estado ← 2
            senão
                retorna erro("Deve ter letra após '_'")
            fim se
        senão se estado = 2 então
            se c ∈ [a-z] ou c ∈ [0-9] então
                estado ← 2
            senão
                retorna erro("Caractere inválido")
            fim se
        fim se
    fim para
    retorna sucesso()
fim função
```

## 6. Implementação

### 6.1 Compilação

```bash
gcc -Wall -Wextra -O2 -o output/main src/main.c
```

**Flags:**
- `-Wall` - Avisos padrão
- `-Wextra` - Avisos adicionais
- `-O2` - Otimização nível 2
- `-o` - Arquivo de saída

### 6.2 Execução

```bash
./output/main
```

### 6.3 Saídas

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

## 9. Extensões Futuras

1. **Entrada dinâmica:** Ler de stdin em vez de string fixa
2. **Validação múltipla:** Processar vários tokens
3. **Arquivo:** Validar tokens de arquivo externo
4. **Estatísticas:** Contar válidos/inválidos
5. **Modo interativo:** Interface em tempo real
6. **Tratamento de memória:** Suportar tokens longos

## 10. Referências

- Hopcroft, J. E., Motwani, R., & Ullman, J. D. (2006). *Introduction to Automata Theory, Languages, and Computation*
- Teoria de Autômatos Finitos Determinísticos

## 11. Histórico de Versões

| Versão | Data | Descrição |
|--------|------|-----------|
| 1.0 | 23/05/2026 | Versão inicial |

---

**Data:** 23 de maio de 2026  
**Versão:** 1.0
