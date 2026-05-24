# Validador de Tokens - Documentação Técnica

## 1. Especificação

### Objetivo
Implementar um validador de tokens que aceite apenas aqueles que seguem o padrão específico utilizando teoria de autômatos finitos determinísticos.

### Padrão Aceitável
```
^_[a-z]+[a-z0-9]*$
```

**Regras:**
- Deve começar com underscore (`_`)
- Seguido por uma ou mais letras minúsculas
- Pode conter letras minúsculas e dígitos após as letras iniciais
- Rejeita letras maiúsculas, caracteres especiais e espaços

### Exemplos

| Entrada | Válido | Motivo |
|---------|--------|--------|
| `_token` | ✓ | Segue padrão |
| `_token42` | ✓ | Letras + dígitos |
| `_x` | ✓ | Mínimo válido |
| `token42` | ✗ | Não começa com `_` |
| `_123` | ✗ | Sem letra após `_` |
| `_Token` | ✗ | Letra maiúscula |
| `_token-42` | ✗ | Caractere especial |

## 2. Autômato Finito Determinístico

### Estados
- **q₀**: Estado inicial
- **q₁**: Estado intermediário (após underscore)
- **q₂**: Estado de aceitação

### Tabela de Transições

| Estado | '_' | [a-z] | [0-9] | Outros |
|--------|-----|-------|-------|--------|
| q₀ | q₁ | ✗ | ✗ | ✗ |
| q₁ | ✗ | q₂ | ✗ | ✗ |
| q₂ | ✗ | q₂ | q₂ | ✗ |

### Função de Transição (δ)

```
δ(q₀, '_') = q₁
δ(q₁, c ∈ [a-z]) = q₂
δ(q₂, c ∈ [a-z]) = q₂
δ(q₂, c ∈ [0-9]) = q₂
```

## 3. Algoritmo

### Pseudocódigo

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

## 4. Implementação

**Arquivo:** `src/main.c`

### Compilação

```bash
gcc -Wall -Wextra -O2 -o src/output/main src/main.c
```

**Flags:**
- `-Wall` - Avisos padrão
- `-Wextra` - Avisos adicionais
- `-O2` - Otimização nível 2

### Execução

```bash
./src/output/main
```

## 5. Estrutura do Código

### Variáveis
- `entered[]` - Cadeia de entrada (token a validar)
- `estado` - Estado atual da máquina
- `c` - Caractere atual sendo processado

### Fluxo
1. Inicializa estado = 0
2. Itera sobre cada caractere da entrada
3. Realiza transições conforme a tabela de estados
4. Retorna sucesso se chegar ao estado final (q₂) ao fim da entrada
5. Retorna erro em transições inválidas
