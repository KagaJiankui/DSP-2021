function xn=IDFTsum(Xk,N)
    n=0:N-1;
    WN=exp(-1j*2*pi/N);
    nk=n'*n;
    WNnk=WN.^(-nk);
    xn=(Xk*WNnk)/N;
end