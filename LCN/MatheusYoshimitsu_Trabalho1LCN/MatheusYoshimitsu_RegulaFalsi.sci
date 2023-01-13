//function y = funcaoTeste(x)
//    y = x^2 - 7.6*x + 11.55;
//endfunction

function y = funcaoContinua(x);
    y = sin((%pi*(x + 1)) / 8) + (0.23 * x) - 1.5;
endfunction

function [raiz, x, iter, ea] = regulaFalsi(xl, xu, f, tol, imax)
    iter = 0;
    xr = xu-(f(xu)*(xl-xu))/(f(xl)-f(xu));
    a = f(xl)*f(xr);
    if((f(xl)*f(xr))<0) then 
        xu=xr;
    elseif((f(xl)*f(xr))>0) then
        x1=xr;
    else
        ea(iter+1)=0;
    end
    xrold = xr;
    while(1) then
        xr = xu - (f(xu) * (xl-xu)) / (f(xl) - f(xu));
        iter = iter + 1;
        ea(iter) = abs((xr - xrold)/xr);
        if ((f(xl) * f(xr)) < 0) then
            xu = xr;
        elseif ((f(xl)*f(xr)) > 0) then
            xl = xr;
        else
            ea(iter) = 0;
        end
        xrold=xr;
        if(ea(iter)>tol && iter<imax) then
            raiz = xr;
            disp(xl, xu);
            return;
        end
    end
endfunction
