exec("simpson.sci");

function y = f1(x)
    y = 0.2 + 25*x - 200*x^2 + 675*x^3 - 900*x^4 + 400*x^5;
endfunction

format(20)
ex =exp(1)-1;
mprintf("\n valor exato:")
disp(ex)
a=0
b=0.8

n=4
[IT,h] = simpson(f1,a,b,n)
mprintf("\n valor do passo h:")
disp(h)
mprintf(" valor da aproximação IT:")
disp(IT)
mprintf(" valor do erro:")
disp(abs(ex-IT))

