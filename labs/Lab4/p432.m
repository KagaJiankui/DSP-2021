clear;close;clc;
N=5;
n=0:N-1;
WN=exp(-1j*2*pi/N);
nk=n'*n;
DFTN=WN.^(nk);
IDFTN=WN.^(-nk);