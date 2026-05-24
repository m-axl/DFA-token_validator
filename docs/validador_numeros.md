# Validador de Números Inteiros Positivos - Documentação Técnica

## 1. Especificação

### Objetivo
Implementar um validador de números inteiros positivos que aceite apenas dígitos, sem sinal negativo ou casas decimais, utilizando autômato finito determinístico.

### Padrão Aceitável
```
^[0-9]+$
```

**Regras:**
- Deve conter apenas dígitos (0-9)
- Sem sinal negativo (-)
- Sem ponto decimal (.)
- Sem caracteres alfabéticos ou especiais
- Deve ter pelo menos um dígito

### Exemplos

| Entrada | Válido | Motivo |
|---------|--------|--------|
| `0` | ✓ | Dígito válido |
| `123` | ✓ | Apenas dígitos |
| `456789` | ✓ | Número válido |
| `-1` | ✗ | Sinal negativo |
| `1.5` | ✗ | Ponto decimal |
| `.5` | ✗ | Ponto decimal |
| `5.` | ✗ | Ponto decimal |
| `abc` | ✗ | Letras |
| `12a` | ✗ | Contém letra |
| `1.2.3` | ✗ | Múltiplos pontos |

## 2. Autômato Finito Determinístico

### Estados
- **q₀**: Estado inicial
- **q₁**: Estado de aceitação (dígitos válidos)

### Tabela de Transições

| Estado | [0-9] | Outros |
|--------|-------|--------|
| q₀ | q₁ | ✗ |
| q₁ | q₁ | ✗ |

### Função de Transição (δ)

```
δ(q₀, c ∈ [0-9]) = q₁
δ(q₁, c ∈ [0-9]) = q₁
```

## 3. Algoritmo

### Pseudocódigo

```
função validar_numero(entrada: string) → inteiro
    estado ← 0
    para cada caractere c em entrada faça
        se estado = 0 então
            se c ∈ [0-9] então
                estado ← 1
            senão
                retorna erro("Deve começar com dígito")
            fim se
        senão se estado = 1 então
            se c ∈ [0-9] então
                estado ← 1
            senão
                retorna erro("Apenas dígitos permitidos")
            fim se
        fim se
    fim para
    retorna sucesso()
fim função
```

## 4. Implementação

**Arquivo:** `src/DFA_form_mod.c`

### Compilação

```bash
gcc -Wall -Wextra -O2 -o src/output/DFA_form_mod src/DFA_form_mod.c
```

**Flags:**
- `-Wall` - Avisos padrão
- `-Wextra` - Avisos adicionais
- `-O2` - Otimização nível 2

### Execução

```bash
./src/output/DFA_form_mod
```

## 5. Estrutura do Código

### Variáveis
- `entrada[]` - Cadeia de entrada (número a validar)
- `estado` - Estado atual da máquina
- `c` - Caractere atual sendo processado

### Fluxo
1. Inicializa estado = 0
2. Itera sobre cada caractere da entrada
3. Valida se todos os caracteres são dígitos
4. Retorna sucesso se validar todos os dígitos
5. Retorna erro se encontrar caractere inválido
