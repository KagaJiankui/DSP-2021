clear;close;clc;

t1=0:9;
f1=linspace(-pi,pi,length(t1));
% x1=(t1==0)*1;
% fx1=DFTsum(x1,length(x1));
% x2=ones(size(t1));
% fx2=DFTsum(x2,length(x2));
X=[(t1==0)*1;ones(size(t1));exp(1j*2*pi*t1/10);cos(2*pi*t1/10)];
figure(1);
hold on;
for i=1:4
   fx=DFTsum(X(i,:),length(X(i,:)));
   stem(f1,abs(fftshift(fx))); 
end

figure(2);
for i=1:4
    subplot(2,2,i);
    hold on;
    xt=IDFTsum(DFTsum(X(i,:),length(X(i,:))),length(X(i,:)));
    stem(t1,X(i,:));
    stem(t1,real(xt));
end
    