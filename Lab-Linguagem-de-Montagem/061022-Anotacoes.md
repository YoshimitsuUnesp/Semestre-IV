# Estrutura CPU

- Processador -> memória RAM

## Instruções

Qualquer programa de computador é composto de um conjunto de instruções especĩficas.  
São códigos presentes na memória secundária, contendo informações que são processadas pela ULA.  
Cada instrução possui um endereço, e é acessada pelos ponteiros responsáveis pela sua execução.

- São escritas em Hexadecimal, para ecnonomia de espaço na palavra.
- Possui diveross padrões, de acordo com a necessidade do programa.

## Estruturas das instruções

### Exemplo 1

Uso do endereçamento direto para carregar o valor do endereço 00002000h no registrador r10.

**Passo 1:** Acesso á memória para ler a palavra apontada por IP (0204h) e gravação do valor lido no registrador IR. Registrador IP é incrementado.  
**Passo 2:** Busca de operando: Acesso à memória para ler a palavra apontada por IP. O valor lido (00002000h) é armazenado em IR. Outro acesso é feito no endereço armazenado onde o valor lido é amrazenado em r10. IP é incrementado, e passa para 0210h.  
**Passo 3:** Execução: nada a fazer no caso desta instrução.  
**Passo 4:** Armazenamento de resultado na memória: nada a fazer no caso dessa instrução  

### Exemplo 2

Escrever um trecho de programa que calcule a soma dos valores contidos nas palavras de endereço 2000h e 2004h e armazene o resultado no registrador r1.

---

# Introdução a LM

Essencialmente, percebe-se a dificuldade em programar o processador e, nível de instrução, sobretudo pelos possíveis erros.  
Foi necessário desenvolver uma forma mais confiável para montar as sequências de instrução de um programa. Assim surgiram as primeiras linguagens de montagens. (em inglês, *assembly languages*).

Uma linguagem de montagem é basicamente uma linguagem de programação simples, com o uso de palavras **mnemônicas**.   
Exemplos: ADD (soma), LD (load)

### Exemplo 1

> ld rl, 2004h

Quando encontrado pelo montador, é traduzido na sequência de palavras binárias

> 03000100h
>
> 00002004h

### Exemplo 2

> add r1, r2

Quando encontrado pelo montador, é traduzido na sequência de palavras binárias

> 11000102h

A linguagem de montagem permite também a associação de um rótulo definido pelo programador a um endereço de memória.    
Rótulos devem aparecer no início de uma linha e são usados para definir pontos importantes em um programa.  
- Para a documentação do programa, pode-se adicionar comentários, precididos pelo **";"**

### Exemplo

Um trecho de programa, que calcule a soma dos valores contidos nas palavras de endereço 2000h e 2004h e armazene o resultado no registrador r1.

> inicio:  
>  
> ld  r2, 2000h ; carrega o primeiro termo da soma  
> ld r1, 2004h ; carrega do segundo termo  
> add r1, r2 ; soma os dois termos  

## Diretivas do montador

Além das intruções, uma linguagem de montagem possui diretivas, que **não são traduzidas em código de máquina**. Servem para **transmitir informações adicionais ao montador**.  
Exemplo:  

-  Uma constante que será utilizada em vários pontos do programa  
- Reserva de espaço na memória para armazenar variáveis  
- Indicar o endereço inicial da montagem e o final do programa  

## Constantes

Usualmente são definidas no início da linguagem de montagem, para que facilite a leitura e documentação.  
É introduzida pela diretiva **EQU**, cuja sintaxe é:

> nomeVariavel equ valorVariavel

Toda ocorrência de nome é substituĩda pelo valor

### Exemplo

>; definicao de constantes  
> VERDADEIRO equ 0ffh  
> FALSO equ 0  
> MAXVAL equ 1000
> MINVAL equ MAXVAL/2  

## Reserva de Espaço

É possível reservar espaços na memória de duas maneiras: 

- Inicializando o espaço com um valor conhecido;  
- Deixando o espaço não inicializado;

As duas formas são similares às formas de definição de variáveis em C:

> // Exemplo de declaração de variáveis não inicializadas em C:  
> int a, b[1000];
>
> // Exemplo de declaração de variáveis inicializadas em C:  
> int c = -1, d[4] = {1, 2, 3, 4};

Para simplesmente reservar espaço em memória, usamos a diretiva **ds**, que tem o formato geral:

> [rotulo:] ds [expressaoInteira] [;comentario]

### Exemplo

> ; exemplo de reserva de espaço na memória para variáveis  
> ; vamos primeiro definir uma constante  
> TAMANHO equ 4
>
> ; agora reservamos espaço para algumas variáveis  
> contador: ds 1  
> x: ds TAMANHO  
> final: ds 4

## Inicialização

É possível atribuir valores iniciais a posição de memória.  
Os valores são carregados na memória juntamente com o código executável do programa.  
Ao iniciar a execução, as variáveis definidas já conteém os valores especificados.  

Para reservar e inicializar espaço em memória, é utilizada a diretiva:

- **db** (reserva a inicialização em bytes)

> [rotulo:] db [lista-de-valores] [;comentarios]

A lista-de-valores é uma lista, separada por vírgula, onde cada elemento pode ser um int, char ou string.

- **dw** (reserva e inicializa palavras)

O montador computa o valor de cada elemento da lista e monta os  valores resultantes no bytes de memória em sequência, a partir do endereço associado ao rótulo.  
Nenhuma operação ẽ realizada pelo processador, e o montador apenas organiza essas informações para o início da execução do programa.

