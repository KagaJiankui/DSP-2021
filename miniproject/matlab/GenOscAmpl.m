function a=GenOscAmpl(n,x0,l0)
    % 对于基模频率f_0,每个谐波次数k的振动频率/傅里叶系数A_k*4*v_0/(pi^2*f_0)
    % l0=d/l->(0,1),x0=x/l<<1
    N=1:n;
    a=l0*N.^(-1).*(1-4*(x0^2)*N.^2).^(-1).*sin(N*pi*l0).*cos(N*pi*x0);
end