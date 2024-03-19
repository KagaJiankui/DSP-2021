function df = SecOrdDiff(xt, t)
    %2ordCentDiff - 2-Order Central Differetiation
    %
    % Syntax: df = 2ordCentDiff(xt,t)
    %
    % Calculate the 2-Order Central Diffentiation(2OCD) of a given array:
    % df(x)=(f(x+dx/2)-f(x-dx/2))/dx=2*(f[n+1]-f[n-1])/(x[n+1]-x[n])
    dt = t(2) - t(1);
    x1 = [xt(2:end), xt(1)] - [xt(end), xt(1:(end - 1))];
    df = x1(2:(end - 1)) / (2 * dt);
end
