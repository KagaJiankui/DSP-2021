function [out,wout]=FFT1(a)
N=2^(ceil(log2(length(a))));%最近二次幂
a=[a,zeros(1,N-length(a))];
wout=linspace(0,2*pi,length(a));
S=1;
a=Reverse_Rader(a,N);
while S<=N
    T=N/S; %每层S循环的DFT问题规模
    Ws=exp(-1i*2*pi/S);
    for k=1:T%（对每个子段进行循环）
        l=(k-1)*S+(1:S/2);
        c1=a(l);
        c2=a(l+S/2).*(Ws.^(l-1));
        a(l)=c1+c2;
        a(l+S/2)=c1-c2;
    end
    S=S*2; %向上递归
end
out=a/N;
end