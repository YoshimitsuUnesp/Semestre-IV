// usando a função quadrados_minimos para encontrar
// uma parábola que aproximar os valores
// x = [0, 0.25, 0.5, 0.75, 1, 1.25, 1.5, 1.75, 2]
// f(x) = [-1.8, -1.2, -0.4, 0.4, 1.1, 2.1, 3, 3.9, 5] 
// e também plotar o gráfico dos pontos de da G(x)

function [z]=g1(X)
    z = X.^0
endfunction

function [z]=g2(X)
    z = X
endfunction

function [z]=g3(X)
    z = X.^2
endfunction

exec('quadrados_minimos.sci');
// definindo os pontos tabelados da função
X = [0, 0.25, 0.5, 0.75, 1, 1.25, 1.5, 1.75, 2]
F = [-1.8, -1.2, -0.4, 0.4, 1.1, 2.1, 3, 3.9, 5] 

HLista = list(g1,g2)
[b] = quadrados_minimos(X,F,HLista)
mprintf('Reta:')
disp(b)

// Cálculo do erro da reta
HX = b(1) + b(2)*X;
Y = F-HX;
E = Y*Y'
mprintf('Erro da reta:')
disp(E)

GLista=list(g1,g2,g3)      
[a] = quadrados_minimos(X,F,GLista)
mprintf('Parábola:')
disp(a)

// Cálculo do erro da parábola
GX = a(1) + a(2)*X + a(3)*X.^2;
Y = F-GX;
E = Y*Y'
mprintf('Erro da parábola:')
disp(E)

// gráficos 
x=linspace(-0.5,2.5,100);

// Reta encontrada
H = b(1) + b(2)*x;
plot(x, H, "blue");

// Parábola encontrada
G = a(1) + a(2)*x + a(3)*x.^2;    
plot(x,G, "green");

// Pontos encontrados
plot(X,F,'ro');
title("Reta e Parabola");
