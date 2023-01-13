//function y = funcaoTeste(x)
//    y = x^2 - 7.6*x + 11.55;
//endfunction

//function z = funcaoDerivadaTeste(x);
//    z = 2*x - 38/5;
//endfunction

function y = funcaoContinua(x);
    y = sin((%pi*(x + 1)) / 8) + 0.23 * x - 1.5;
endfunction

// Usei o aplicativo Photomath para encontrar a derivada da funcao continua
function z = funcaoDerivada(x);
    z = (%pi*cos((%pi*x+%pi)/8)) / 8 + (23/100);
endfunction

function [raiz, x, iter, ea]=newtonRaphson(x0,f,fp,tol,imax)
iter = 0; // inicializa numero de iteracoes
xr = x0; // inicializa raiz aproximada com a inicial
x(iter+1)=x0; // insere raiz inicial no vetor de raizes
while (1)
    xrold = xr; 
    xr = xrold - f(xrold)/fp(xrold); // aplica formula de Newton
    iter = iter+1; // incrementa numero de iteracoes
    x(iter+1) = xr; // insere raiz aproximada no respectivo vetor
    if(xr ~= 0) then // calcula erro relativo
        ea(iter)=abs((xr-xrold)/xr);
    end;
    if(ea(iter) <= tol) then // se erro relativo menor que tol, FIM
        raiz = xr;
        disp('Iteracoes necessarias: ', iter);
        return;
    end;
    if(iter >= imax) then // se excedeu num. maximo de iteracoes, FIM
        error('Número Máximo de Iterações Alcançado');
    end;
end
endfunction
