clear;close;clc;
t=0:9;
x1=(t==1)*1;
x2=ones(size(t));
x3=exp(1j*2*pi*t/length(t));

figure(1)
[X,w]=DTFTsamples(x2);
X1=dc1DFT(x2);
plot(w,abs(X));
hold on;
stem(w,fftshift(abs(X1))/length(t));

function X=dc1DFT(x)
    xe=x(1:2:length(x)-1);
    fxe=DFTsum(xe,length(xe));
    xo=x(2:2:length(x));
    fxo=DFTsum(xo,length(xo));
    twi=exp(-1j*2*pi*(0:length(x)/2-1)/length(x));
    X=[(fxe+fxo.*twi),(fxe-fxo.*twi)];
end