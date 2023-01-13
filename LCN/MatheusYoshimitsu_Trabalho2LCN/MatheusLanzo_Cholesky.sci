function [n] = simetrica(A)
    // Verifica se a matriz é quadrada
    // Trecho parecido com lu_gauss
    // Se m e n forem diferentes, não é quadrada
    [m, n] = size(A);
    if m ~= n then
        error('ERRO: A matriz deve ser quadrada!'); 
    end
    
    // Verifica se a matriz é simétrica
    // Para ser simetrica, A e A' devem ser iguais
    matriz = (A == A'); // Retorna um valor booleano para cada valor da matriz
    
    for i = 1 : m
        for j = 1 : m
            if ~matriz(i, j) then // Se qualquer valor não for igual ao da transposta, não é simétrica
                error("ERRO: A matriz não é simétrica!");
            end
        end
    end
    
endfunction

function [G, x] = cholesky(A, b)
    // Parte 1: verificar simetria
    n = simetrica(A);
    
    // Parte 2: decomposição de Cholesky a partir do pseudocodigo
    // Inicializa G e Gt com zeros
    G = zeros(n);
    Gt = zeros(n);
    
    //Processa coluna 1 separadamente
    G(1, 1) = sqrt(A(1, 1));
    
    for i = 2 : n
        G(1, i) = A(1, i) / G(1, 1);
    end                 
                        
    // Processa coluna 2 a n
    for i = 2 : n
        somatorio = 0;
        // Calcula elemento diagonal da coluna k
        for k = 1 : i - 1
            somatorio = somatorio + G(k, i)^2;
        end
        
        G(i, i) = sqrt(A(i, i) - somatorio);
        
        // Calcula elementos não diagonais da coluna k
        for j = i + 1 : n
            somatorio = 0;
            for k = 1 : i - 1
                somatorio = somatorio + G(k, i) * G(k, j);
            end
            G(i, j) = (A(i, j) - somatorio) / G(i, i);
        end
    end
  
    Gt = G';
    
    // Resolve sistema (trecho parecido com lu_gauss)
    // Solução do Sistema Triangular Inferior
    d = zeros(n, 1);
    d(1) = b(1) / Gt(1, 1);
    for i = 2 : n
        d(i) = (b(i) - Gt(i, 1 : i - 1) * d(1 : i - 1)) / Gt(i, i);
    end

    // Solução do Sistema Triangular Superior
    x = zeros(n, 1);
    x(n) = d(n) / G(n, n);
    for (i = n - 1 : -1 : 1)
        x(i) = (d(i) - G(i, i + 1 : n) * x(i + 1 : n)) / G(i, i);
    end
endfunction
