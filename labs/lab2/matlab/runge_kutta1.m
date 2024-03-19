function [x, y] = runge_kutta1(ufunc, y0, h, a, b)
    %参数表顺序依次是微分方程组的函数名称，初始值向量，步长，时间起点，时间终点（参数形式参考了ode45函数）
    %语法: [x,y]=runge_kutta1(@dy/dx,y0,dx,x_i,x_f)
    n = floor((b - a) / h); %求步数
    x = zeros(1, n + 1);
    y = zeros(length(y0), n + 1);
    x(1) = a; %时间起点
    y(:, 1) = y0; %赋初值，可以是向量，但是要注意维数

    for ii = 1:n
        x(ii + 1) = x(ii) + h;
        k1 = ufunc(x(ii), y(:, ii));
        k2 = ufunc(x(ii) + h / 2, y(:, ii) + h * k1 / 2);
        k3 = ufunc(x(ii) + h / 2, y(:, ii) + h * k2 / 2);
        k4 = ufunc(x(ii) + h, y(:, ii) + h * k3);
        y(:, ii + 1) = y(:, ii) + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        %按照龙格库塔方法进行数值求解
    end

end
