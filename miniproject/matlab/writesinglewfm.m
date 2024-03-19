close;clc;clear;
key='C';
Fs=48000;
T=1;
Tv=linspace(0,T,T*Fs);
fc1=tone2freq(1,0,0,key,0);
% amp=amp1(1:6);
fc1_list=fc1*(1:19);
amp=[987.8,368.6,620.2,483.9,156.7,83.62,120.1,70.73,5.348,24.41,27.35,21.3,10.31,6.477,15.91,3.495,2.546,0.4751,0.8858]/1000;
% amp=GenOscAmpl(19,0.01,0.112)/norm(GenOscAmpl(19,0.01,0.112));
wfm1=cell2mat(arrayfun(@(a,x) a*sin(2*pi*x*Tv),amp,fc1_list,'UniformOutput',false).');
wfm1=sum(wfm1,1).*GenADSRenv(wfm1,[0.08,0.16,0.23,0.48],[1,0.68,0.56,0]);
% wfm1=sum(wfm1,1).*env1(wfm1);

[b_b1,a_b1]=butter(6,2*[1300,1900]/Fs);
[b_b2,a_b2]=butter(6,2*[3600,5000]/Fs);
[b_b3,a_b3]=butter(6,2*[8000,11000]/Fs);
wfm2=wfm1+1.2*filter(b_b1,a_b1,wfm1)+1.1*filter(b_b2,a_b2,wfm1)+0.9*filter(b_b3,a_b3,wfm1);
wfm2=wfm2/(max(wfm2));
sound(wfm2,48000);

function env=env1(x) % 论文(1)
    tv=linspace(0,1,length(x));
    env=25.17*tv.*(tv<=0.03)+(-50*(tv-0.1).^2+1).*((tv>0.03)&(tv<=0.15))+0.875*exp(-8*(tv-0.15)).*((tv>0.15)&(tv<0.7));
end

function env=env2(x,a,b,tmax) % 论文(2)
    tv=linspace(0,tmax,length(x));% exp(-b*k)*(a/c)^k
    c1=exp(-2)*2^0.8*a^2*b^(-0.8);
    env=c1*tv.^(1.2).*(tv<2/b)+(a*tv).^2./exp(b*tv).*(tv>=2/b);
end

function env=env3(x) % CW键控滤波器
    tv=linspace(0,1,length(x));
    t1=0.15;
    a1=0.06;
    y1=exp(tv/a1)-1;
    t2=0.22;
    [~,P2] = min(abs(tv-t1));
    y2=y1(P2)*(tv>=0);
    t3=0.37;
    a2=0.08;
    [~,P3] = min(abs(tv-t3));
    y3=y2(P3)/(1-exp((-t3+t2)/a2))*(1-exp((-t3+tv)/a2));
    env=y1.*(tv<=t1)+y2.*(tv>t1&tv<=t2)+y3.*(tv>=t2&tv<=t3);
end

function amp=amp1(x)
    amp=1.4218*exp(-2.4618*x)+0.0049+0.0001*x.^2;
end