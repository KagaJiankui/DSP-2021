clear;clc;close;
h1=[[-1,2,-3,6,-3,2,-1];[1,0,0,0,0,0,0]];
[z1,p1,k1]=tf2zpk(h1(1,:),h1(2,:));

g1=[[3,-2.4,15.36,3.84,9];[5,-8.5,17.6,4.7,-6]];
[z2,p2,k2]=tf2zpk(g1(1,:),g1(2,:));


g2=[[2,0.2,6.4,4.6,2.4];[5,1,6.6,4.2,24]];
[z3,p3,k3]=tf2zpk(g2(1,:),g2(2,:));


figure(1);
myzplane(z1,p1);

figure(2);
myzplane(z2,p2);

figure(3);
myzplane(z3,p3);

function myzplane(z,p)
    zplane(z,p);
    grid on
    text(real(z)-0.1,imag(z)-0.1,'\bfZeros','color',[0 0.4 0])
    text(real(p)-0.1,imag(p)-0.1,'\bfPoles','color',[0.6 0 0])
end