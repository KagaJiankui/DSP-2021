clear;close;clc;

hz=[-0.0035,-0.0039,0.0072,0.0201,0,0.0517,-0.0506,0.0855,0.2965];
hz=[hz,0.4008,fliplr(hz)];
[m,p,w]=FreRes(hz,1,256);
f=FreResPlot(m,p,w,1);

hx=[-0.0035,-0.0039,0.0072,0.0201,0,0.0517,-0.0506,0.0855,0.2965];
hx=[hx,0.4008,-1*fliplr(hx)];
[m1,p1,w1]=FreRes(hx,1,256);
f=FreResPlot(m1,p1,w1,2);

hz1=upsample(-1*hz(1:2:end),2);
hz2=upsample(hz(2:2:end),2,1);
h1=hz1(1:19)+[hz2 0];
[m2,p2,w2]=FreRes(h1,1,256);
f=FreResPlot(m2,p2,w2,3);

h2=upsample(hz,5);
[m3,p3,w3]=FreRes(h2,1,256);
f=FreResPlot(m3,p3,w3,4);