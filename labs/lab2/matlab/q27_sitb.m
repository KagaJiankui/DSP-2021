clear;close;clc;

N=1200;
t=[0:N-1];
% x1 = [0, 0, 1, 2, 2, 1,0,0];
% x1 = repmat(x1, 1, 120 / length(x1));
% x2 = [0, 1, 2, 0, -2, -1,0,0];
% x2 = repmat(x2, 1, 120 / length(x2));
% t = [0:length(x1) - 1];
% x1=randi([-1,1],[1,N]);
% x2=randi([0,2],[1,N])-1;
wfun=[1,1,0,0,0,0,0,0];
% x1=sin(2*pi*20*t/N).*repmat([0,0,0,1,1,0,0,0],[1,N/length(wfun)]);
x1=[zeros(1,N/3),ones(1,N/3),zeros(1,N/6),ones(1,N/6)];
% x2=sin(2*pi*12*t/N).*repmat([0,0,1,1,1,1,0,0],[1,N/length(wfun)]);
% x2=linspace(0,1,20);
% x2=repmat(x2,[1,N/length(x2)]);
x2=x1.*sin(2*pi*20*t/N);

%Global Variables
f = [];
%Plot area
% figure(1);
% stem(t, x1);
% hold on;
% stem(t, bbox1(x1));
% figure(2);
% stem(t, x2);
% hold on;
% stem(t, bbox1(x2));

% Use System Identification Toolbox
Ts = 1;
Ze = iddata(bbox1(x1).', x1.', Ts);
Zv = iddata(bbox1(x2).', x2.', Ts);
figure(3);
plot(Ze);
figure(4);
plot(Zv);

Ge = spa(Ze);
Gv=spa(Zv);
figure(5);
bode(Ge);
figure(6);
bode(Gv);

Mimp1 = impulseest(Ze);
Mimp2 = impulseest(Zv);
figure(7);
subplot(121);
step(Mimp1);
subplot(122);
step(Mimp2);

delayest(Ze)
delayest(Zv)

% imgWrite(f)

function imgWrite(f)

    for s = 1:length(f)
        imwrite(frame2im(getframe(f(s))), append(mfilename(), "_", string(s), ".png"))
    end

end

function x = impseq(n0, n1, n2)
    % impseq：产生一个冲激函数
    % 参数：在n0-n2之间，n1处为1，其余为0
    % 返回： x是冲激序列w
    n = n0:n2;
    x = [(n - n1) == 0];
end

function x = heaviseq(n0, n1, n2)
    % heaviseq：产生一个阶跃函数
    % 参数：在n0-n2之间，n>=n1处为1，其余为0
    % 返回： x是阶跃序列
    x = 1 * ([n0:n2] - n1 >= 0) * 1;
end
