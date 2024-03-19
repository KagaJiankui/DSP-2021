function [y] = IIRfilter(x, theta, r)
    % y[n]=(1-r)x[n]+2*r*cos(theta)*y[n-1]-r^2*y[n-2];
    % r = 0.995;
    y = zeros(1, length(x));
    y(1) = (1 - r) * x(1);
    y(2) = (1 - r) * x(1) + 2 * r * cos(theta) * y(1);

    for i = 3:1:length(x)
        y(i) = (1 - r) * x(i) + 2 * r * cos(theta) * y(i - 1) - r^2 * y(i - 2);
    end

    % for this is down by convolution
    % in this function I do not draw the
    % frequency response.

end
