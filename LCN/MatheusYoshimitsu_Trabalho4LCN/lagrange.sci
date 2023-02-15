function [y_interp] = lagrange(x, y, x_interp)
    n = length(x);
    soma = 0;
    for k = 1:n
        produto = y(k);
        for j = 1:n
            if j ~= k then
                produto = produto * (x_interp - x(j)) / (x(k) - x(j));
            end
        end
        soma = soma + produto;
    end
    y_interp = soma;
endfunction
