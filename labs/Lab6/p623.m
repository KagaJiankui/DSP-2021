clear;close;clc;
h1=[[1,2,0,2,1];[1,0,0,0,0]];

h2=[[1,0,-1];[1,-1.2,0.95]];

[m,p,w]=FreRes(h1(1,:),h1(2,:),256);
f=FreResPlot(m,p,w,1);

[m,p,w]=FreRes(h2(1,:),h2(2,:),256);
f=FreResPlot(m,p,w,2);