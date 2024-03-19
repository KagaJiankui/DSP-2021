function Y = Reverse( N )
%二进制反转函数
%传入参数：下标总数N（必为2的幂次）
%返回参数：下标矩阵Y 用于二进制意义下逆序输出
    P=log2(N);
    Y=arrayfun(@(x)bitget(x,1:P)*(2.^(P-1:-1:0)).',0:N-1);
end