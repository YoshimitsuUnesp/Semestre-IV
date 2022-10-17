# Teoria dos Conjuntos

# Experimento ou fenômeno aleatório:

Occore quando resultados não podem preditos. Os resultados de um fenômeno aleatório estão sujeitos à fatores casuais.

# Espaço amostral (omega):

É o conjunto de todos os resultados possíveis de um experimento ou fenômeno aleatório. Os resultados do espaço amostram se chamam eventos ou pontos amostrais.

Ex: Lançamento de uma moeda duas vezes  
omega = {CaCa, CaCo, CoCa, CoCo}

# Eventos:

Subconjuntos do espaço amostral.  
Considerando A contido em omega  
Evento simples: pontos amostrais; cada resultado individual possível do experimento.  
Evento composto: conjunto de eventos simples, podendo ser decomposto em outros eventos simples/compostos
Uniâo: A união com B; representa a ocorrência de pelo menos um dos eventos A ou B.  
Intersecção: A intercecção com B; representa a ocorrência dos eventos de A e B simultaneamente.  
Evenetos mutuamente exclusivos: quando A e B não possuem elementos em comum.  
Eventos complementares: quando A e B tem sua união como espaço amostral e sua intersecção é vazia.  
A intersecção B = vazio  
A união com B = omega  

# Diagrama de Venn

A intersecção com B (ocorrencia simultânea de A e B)  
A intersecção com nâo-B (ocorre somente o evento de A)  
Não-A intersecção com B (ocorre apenas o evento de B)  
Não-A intersecção com não-B

# Exemplos:

1. Em uma universidade há indivídeuos de três segmentos: alunos, funcionários e docentes. Sabe-se que 1800 são alunos, 2150 não são docentes e 15% são docentes. Quantos indivídulos têm a mesma universidade? Quantos são docentes?

2. Uma fábrica de bebidas produz refrigerantes que podem ser classificados ao final da produção em: "conformes" e "não conformes". Escolhidas 3 unidades de refrigerante, qual o espaço amostral? Se forem escolhidos 5, quantos elementos terá o espaço amostral?

omega = {CCC, CC!C, C!CC, !CCC, C!C!C, !CC!C, !C!CC, !C!C!C} -> 2^3  
omega = {CCCCC, ..., !C!C!C!C!C} -> 2^5

| Nº de conformes | Nº de possibilidades em omega |
| --- | --- |
| 0 | 1 |
| 1 | 3 |
| 2 | 3 |
| 3 | 1 |
| Total | 8 |

3. Sendo A e B dois eventos em um mesmo espaço amostral "traduza" para a linguagem da Teoria dos Conjuntos, as seguintes situações: a) ao menos um dos eventos ocorre. b) exatamente um dos eventos ocorre; c) nenhum deles ocorre; d) o evento A ocorre mas o B não.

4. Três jogadores A, B e C disputam um torneio de tênis. Inicialmente, A joga com B e o vencedor joga com C, e assim por diante. O torneio termina quando um jogador ganha duas vezes em seguida ou quando são disputadas, ao todo, quatro partidas. Quais são os resultados possíveis do torneio?

omega = {AA, BB, ACC, BCC, ACBA, ACBB, BCAB, BCAA}