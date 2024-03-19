function [output_signal] = FIRfilter(input_signal, theta)
    % this function is to do a simple filterring using a default
    % transfer function hf shown below
    % the input
    w = -pi:0.00001:pi;
    j = sqrt(-1);
    z = exp(j * w);

    hf = [1 -2 * cos(theta) 1];
    output_signal = conv(input_signal, hf);
    Hf = 1 - 2 * cos(theta) * z.^(- 1) + z.^(- 2);
    figure(100);
    plot(w, abs(Hf));
    xlabel('\omega (rad/sample)');
    title('frequency response of the designed filter');
end
