# PROBABILIDADES
Pode ser aplicada a um acontecidmento que pode ter ocorrido, no passado-presente, ou que poderá ocorrer no futuro, mas o qual não temos conhecimentos completos.  
Estudar a incerteza proveniente dos fenômenos aleatórios.  
Quantificação de eventos, num intervalo de 0 e 1, de acordo com o **grau de convicção**.  
**Definição:** número real no intervalo de 0 a 1, que é utilizada para expimir a chance de ocorrência de determinado evento.

Uma função P() é  denominada probabilidade se satisfaz as 3 seguintes condições:  
**i)** P(omega) = 1  
**ii)** 0 <= P(A) <= 1, para todo A contido em omega  
<!-- iii) ????? -->

**Exercício:**   
**1.** Conjunto de 4 números, sendo 3 positivos e 1 negativo. Sorteamos 2 números desse conjunto, com reposição.  

**(a)** Determine a probabilidade de ter um quociente negativo.  
B: número positivo 3/4    
N: número negativo 1/4  
P(A) = 3/4 * 1/4 + 1/4 * 3/4  
P(A) = 3/16

**(b)** Determine a probabilidade dos dois terem o mesmo sinal.    
P(C) = 3/4 * 3/4 + 1/4 * 1/4 = 10/16  

**2.**  Urna com 9 talões, numerados de 1 a 9. Se 3 talões são retirados da urna, um de cada vez, determine a probabilidade de eles serem alternadamente: (ímpar, par, ímpar) ou (par, ímpar, par).  

A: sair a sequência IPI  
B: sair a sequência PIP  

P(A U B) = P(A) + P(B)  
P(A U B) = 5/9 * 4/8 * 4/7 + 4/9 + 5/8 + 3/7  
P(A U B) = 5/18  

**3.** Dois processadores tipos A e B são colocados em teste por 50 mil horas. A probabilidade de um erro de cãlculo aconteça em um processador do tipo A é de 1/30, no tipo B, 1/80 e em ambos, 1/1000. Qual a probabilidade de que:  

**a)** Pelo menos um dos processadores apresente erro?  
P(A U B) = P(A) + P(B) - P(A inter B)  
= 1/30 + 1/80 - 1/1000 = 0,0448  

**b)** Nenhum processador apresente erro?  
P(!A inter !B) = 1 - P(A U B) = 0,9552    

**c)** Somente o processador A apresente erro?  
P(A inter !B) = P(A) - P(A inter B) = 0,032  

___

## Propriedades  

**1.**  
Omega U Vazio = Omega  
P(Omega U Vazio) = P(Omega)  
P(Omega) + P(Vazio) = 1  
Portanto P(Vazio) = 0  

**2.**  
P(!A inter B) = ?  
(!A inter B) U (A inter B) = B  
P(!A inter B) + P(A inter B) = P(B)  
= P(B) - P(A inter B)  

**3.**  
P(A U B) = P(A) + P(B) - P(A inter B)  
(A inter !B) U (A inter B) U (!A inter B) = A U B  
P(A) + P(!A inter B) = P(A U B)  

___

**Exercício**  
Uma turma de estatística teve a seguinte distribuição das notas finais: 4 do sexo masculino e 6 do feminino foram reprovados, 8 do sexo masculino e 14 do feminino foram aprovados. Para um aluno sorteado dessa classe, denote por M se o aluno escolhido for do sexo masculino e por A se o aluno foi aprovado. Calcule:  

**a)** P(!A inter M)   
= 4/32

| | M | !M | Total |
| --- | --- | --- | --- |
| A | 8/32 | 14/32 | 22/32 |  
| !A | 4/32 | 6/32 | 10/32 |
| Total | 12/32 | 20/32 | 1 |  

**b)** P(!A inter !M)  
= 6/32
