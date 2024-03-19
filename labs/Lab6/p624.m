clear;close;clc;
% z变换就是其实复变函数里的洛朗级数，z变换的收敛域就是洛朗级数的收敛域
% 洛朗级数的收敛域一定是一个圆或圆环或圆外部，而原来的信号实际上就是洛朗级数的系数
% 你可以对照着信号书留数法求z逆变换和复变书洛朗级数展开式的-1次方项的公式看看，他们是一样的

xz_num=[3,-7.8];
xz_den=conv([1,-0.7],[1,1.6]);
[r1,p1,k1]=residuez(xz_num,xz_den);
f1=rocplot(xz_num,xz_den,1);

yz_num=[3,1.8,1.28];
yz_den=conv([1,-0.5],[1,0.4]);
[r2,p2,k2]=residuez(yz_num,yz_den);
f2=rocplot(yz_num,yz_den,2);

f3=plotposinvz(xz_num,xz_den,8,3);

f4=plotposinvz(yz_num,yz_den,8,4);