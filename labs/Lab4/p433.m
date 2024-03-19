clear;close;clc;

n0=1:13;
l=zeros(5,length(n0));
for j=n0
    t=0:2^j-1;
xt=cos(2*pi*t/10);
f1=@() DFTsum(xt,length(xt));
time1=timeit(f1);

n=t;
nk=n'*n;
DFTN=exp(-1j*2*pi/length(n)).^(nk);
f2=@() xt*DFTN;
time2=timeit(f2);
n=[];nk=[];DFTN=[];

f3=@() DFTloop(xt,length(xt));
time3=timeit(f3);

f4=@() FFT1(xt);
time4=timeit(f4);

f5=@() FFT1_mex(xt);
time5=timeit(f5);

l(:,j)=[time1,time2,time3,time4,time5].';

end

save('LN.mat',"l","n0");

xt=cos(2*pi*(0:511)/10);
subplot(211)
plot(abs(DFTloop(xt,length(xt))))
subplot(212)
plot(abs(DFTsum(xt,length(xt))))

clear;

function c=DFTloop(x,N)
    W=linspace(-pi,pi,N);
    c=zeros(1,N);
    for i=1:length(x)
        c=c+x(i)*exp(-1j*W*i);
    end
    fftshift(c);
end

function c=IDFTloop(x,N)
    W=linspace(-pi,pi,N);
    c=zeros(1,N);
    for i=1:length(x)
        c=c+x(i)*exp(1j*W*i);
    end
    fftshift(c);
end