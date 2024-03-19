clear;close;clc;

t = linspace(0, 8, 256);
dt = t(2) - t(1);
xt = sin(2 * pi * t);
dx1 = SecOrdDiff(xt, t);
f = [];
fig = figure(1);
plot(t, xt);
hold on;
plot(t, xt)
plot(t(2:end - 1), dx1)
legend('$$x[t]=sin(2\pi t)$$', '$$x[t]-x[t-1]$$', 'Location', 'northeast', 'interpreter', 'latex');
f = [f; fig];

ix1 = cumsum(xt)/length(t);
fig = figure(2);
hold on;
plot(t, xt);
plot(t, ix1);
legend('$$x[t]=sin(2\pi t)$$', '$$\sum x[t]$$', 'Location', 'northeast', 'interpreter', 'latex');
f = [f; fig];

dy = zeros(3, 1); %初始化列向量

%对该微分方程组用ode45和自编的龙格库塔函数进行比较，调用如下：
fig = figure(3);
[T, F] = ode45(@test_fun, [0 15], [1 1 3]);
subplot(121)
plot(T, F) %Matlab自带的ode45函数效果
title('ode45(builtin)')
[T1, F1] = runge_kutta1(@test_fun, [1 1 3], 0.25, 0, 15); %测试时改变test_fun的函数维数，别忘记改变初始值的维数
subplot(122)
plot(T1, F1) %自编的龙格库塔函数效果
title('runge_kutta1')
f = [f; fig];

for s = 1:length(f)
    imwrite(frame2im(getframe(f(s))), append(mfilename(), "_", string(s), ".png"))
end

function dy = test_fun(x, y)
    dy(1) = y(2) * y(3);
    dy(2) = -y(1) + y(3);
    dy(3) = -0.51 * y(1) * y(2);
    dy = dy.';
end
