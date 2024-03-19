% this test .m file is use for test the unexpected remaining sinusoidal 
% signal after filter in lab7_3_2
% result is clear, this file ends its mission.
w = -pi:0.001:pi;
j = sqrt(-1);
z = exp(j * w);

M=1024;

% 100Hz
x=cos(100*2*pi*w)+1;
[X,X_w]=DTFT(x,M);

filtered_x=FIRfilter(x,200*pi*0.001);
[filtered_X,filtered_X_w]=DTFT(filtered_x,M);

figure(200);
plot(X_w,abs(X));

figure(201);
plot(filtered_X_w,abs(filtered_X));