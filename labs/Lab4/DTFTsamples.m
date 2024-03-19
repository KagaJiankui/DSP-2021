function [X,w]=DTFTsamples(x)
    N=length(x);
    w=linspace(-pi,pi,N);
    X=fftshift(DFTsum(x,N))/N;
end