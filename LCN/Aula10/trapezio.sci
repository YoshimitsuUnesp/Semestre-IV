function [I,h] = trapezio(func,a,b,ns)
x=a;
h=(b-a)/ns;
soma=func(a);
for i=1:ns-1
    x = x+h;
    soma = soma + 2*func(x);
end
soma = soma + func(b);
I = h*soma/2
endfunction

