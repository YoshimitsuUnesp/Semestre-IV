function [I, h] = simpson(func, a, b, ns)
    if(modulo(ns, 2) ~= 0) then
        error("NS não é par");
    else
        h = (b - a) / ns;
        x = a;
        soma = func(a) + func(b);
        for (i = 1 : ns-1)
            x = x + h;
            if (modulo(i, 2) ~= 0) then
                soma = soma + 4 * func(x);
            else
                soma = soma + 2 * func(x);
            end
        end
        I = h * soma/3;
   end
endfunction
