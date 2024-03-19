clear;close;clc;
%cascase
ft=0.3*pi;
M=round(-1/(2*log2(cos(ft/2))));
num1=poly([-1,-1,-1])/8;
[m,p,w]=FreRes(num1,1,256);
f=FreResPlot(m,p,w,1);

[s,val]=fsolve(@(x) hjw(x,ft),1);
num2=(repmat([1],[1,round(s)]))/round(s);
[m,p,w]=FreRes(num2,1,256);
f=FreResPlot(m,p,w,2);

function h=hjw(M,f)
    a=sin(M*f/2)/sin(f/2);
    b=exp(-1j/2*(M-1)*f);
    h=abs(a*b/M)-0.707;
end