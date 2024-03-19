clear;close;clc;

t = -10:20;
x1 = impseq(t(1), 0, t(end)) - impseq(t(1), 5, t(end));
N = 10;
x2 = heaviseq(t(1), 0, t(end)) - heaviseq(t(1), N + 1, t(end));
f = [];

%signal x1
dx1 = [x1(1), diff(x1)];
%differentiator
ix1 = cumsum(x1);
%integrator
fig = figure(1);
subplot(311);
stem(t, x1);
title('Signal $$x_{1}[t]=\delta[t]-\delta[t-5]$$', 'interpreter', 'latex');
subplot(312);
stem(t, dx1);
title('Signal $$dx_{1}[t]=\mathcal{D}(x_{1})=x_{1}[t]-x_{1}[t-1]$$', 'interpreter', 'latex');
subplot(313);
stem(t, ix1);
title('Signal $$ix_{1}[t]=\sum x_{1}[t]$$', 'interpreter', 'latex');
f = [f; fig];

%signal x2
dx2 = [x2(1), diff(x2)];
%differentiator
ix2 = cumsum(x2);
%integrator
fig = figure(2);
subplot(311);
stem(t, x2);
title('Signal $$x_{2}[t]=u[t]-u[t-11]$$', 'interpreter', 'latex');
subplot(312);
stem(t, dx2);
title('Signal $$dx_{2}[t]=\mathcal{D}(x_{2})=x_{2}[t]-x_{2}[t-1]$$', 'interpreter', 'latex');
subplot(313);
stem(t, ix2);
title('Signal $$ix_{2}[t]=\sum x_{2}[t]$$', 'interpreter', 'latex');
f = [f; fig];

imgWrite(f)

function imgWrite(f)
    %imgWrite - Write plots to the same directory of the M-file
    %
    % Syntax: imgWrite(f)
    %
    % Use For loop to write plots to the same directory of the M-file, renaming the plots sequently at the same time.
    for s = 1:length(f)
        imwrite(frame2im(getframe(f(s))), append(mfilename(), "_", string(s), ".png"))
    end

end

function x = impseq(n0, n1, n2)
    % impseq：产生一个冲激函数
    % 参数：在n0-n2之间，n1处为1，其余为0
    % 返回： x是冲激序列
    n = n0:n2;
    x = [(n - n1) == 0];
end

function x = heaviseq(n0, n1, n2)
    % heaviseq：产生一个阶跃函数
    % 参数：在n0-n2之间，n>=n1处为1，其余为0
    % 返回： x是阶跃序列
    x = 1 * ([n0:n2] - n1 >= 0) * 1;
end
