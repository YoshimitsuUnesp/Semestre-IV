function x = gauss_simplorio(A,b)
// Método da Eliminação de Gauss Sem Pivotamento
[m,n] = size(A);
if m~=n, error('Matriz A deve ser quadrada'); end
// Construindo a Matriz Aumentada [A b]
nb = n+1;
Aug = [A b];
disp(Aug)
// Fase 1: Eliminação
for k = 1:n-1
//   if Aug(k,k)==0 then
//       disp('Elemento da diagonal igual a 0')
//       abort
//   end   
    for i = k+1:n
        m = Aug(i,k)/Aug(k,k);
        //disp(m)
        Aug(i,k)=0;
        Aug(i,k+1:nb) = Aug(i,k+1:nb)-m*Aug(k,k+1:nb);
    end
end
disp(Aug)
// Fase 2: Solução do Sistema Triangular - Retrosubstituição
x = zeros(n,1);
x(n) = Aug(n,nb)/Aug(n,n);
for i = n-1:-1:1
    x(i) = (Aug(i,nb)-Aug(i,i+1:n)*x(i+1:n))/Aug(i,i);
end
endfunction
