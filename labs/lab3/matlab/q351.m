clear;close;clc;

t=0:20;
x1=(t==0)*1;
d=200;
[X,w]=DTFT(x1,-5,d);

magX = abs(X);
angX = angle(X);
realX = real(X);
imagX = imag(X);
figure(1)
plot(t,x1)
hold on;
stem(t,x1)
figure(2)
subplot(2,2,1);
plot(w/pi,magX);
title('Magnitude Part');
xlabel('w/pi');ylabel('Magnitude');
subplot(2,2,2);
plot(w/pi,angX);
title('Angle Part');
xlabel('w/pi');ylabel('Radians');
subplot(2,2,3);
plot(w/pi,realX);
title('Real part');
xlabel('w/pi');ylabel('Real');
subplot(2,2,4);
plot(w/pi,imagX);
title('Imaginary Part');
xlabel('w/pi');ylabel('Imaginary');

function [X,w]=DTFT(x1,n0,d)
    t=[0:length(x1)-1]+n0;
    k=0:d;
    w = (pi/d)*k;
    X = x1 * (exp(-1i * pi/d)).^(t.' * k);
end
