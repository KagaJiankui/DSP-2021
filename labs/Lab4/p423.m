clear;close;clc;
t=linspace(0,1,1024);
xn=cos(pi/4*t);

figure(1);
[r1,ph1]=WindowFFT(64);
xw=linspace(-pi,pi,64);
plot(xw,r1);
hold on;
plot(xw,ph1);

figure(2);
for i=1:6
    plottrunc(xn,2^i);
    hold on;
    legend;
end


function [rho,phi]=WindowFFT(N)
    W=linspace(-pi,pi,N);
    Wjw=(1-exp(-1j*W*N))./(1-exp(-1j*W));
    phi=unwrap(angle(Wjw));
    rho=abs(Wjw);
end

function plottrunc(signal,ltrunc)
    xtr=signal.*[ones(1,ltrunc),zeros(1,length(signal)-ltrunc)];
    [f,w]=DTFT(xtr,length(xtr));
    plot(w,abs(f)/length(f));
end