clear;close;clc;
ft=0.2*pi;
al=1/cos(ft)+sqrt(1/(cos(ft)^2)-1);
num=(1+al)/2.*[1,-1];
den=[1,-al]
[m,p,w]=FreRes(num,den,256);
f=FreResPlot(m,p,w,1);