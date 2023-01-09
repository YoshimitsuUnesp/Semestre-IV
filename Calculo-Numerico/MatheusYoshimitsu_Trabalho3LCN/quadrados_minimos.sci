function [a] = quadrados_minimos(X,F,GLista)

n=size(GLista);
for i=1:n
    gi= GLista(i)(X);
    for j=i:n
        gj=GLista(j)(X);
        G(i,j)=gi*gj';
        G(j,i)=G(i,j);
    end
    b(i)=F*gi';
end
a=G\b
endfunction
