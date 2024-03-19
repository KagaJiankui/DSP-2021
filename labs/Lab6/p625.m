clear;close;clc;
xz_num=[3,-7.8];
xz_den=conv([1,-0.7],[1,1.6]);
[r1,p1,k1]=residuez(xz_num,xz_den);
f1=rocplot(xz_num,xz_den,1);

yz_num=[3,1.8,1.28];
yz_den=conv([1,-0.5],[1,0.4]);
[r2,p2,k2]=residuez(yz_num,yz_den);
f2=rocplot(yz_num,yz_den,2);

[hx,tx]=impz(xz_num,xz_den,30);
[hy,ty]=impz(yz_num,yz_den,30);

figure(3);
subplot(211);
stem(tx,hx);
subplot(212);
stem(ty,hy);