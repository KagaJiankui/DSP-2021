function [X, w, h] = LPFtrunc(N)
    % input is the length of the window
    n = 0:1:N - 1;
    wc = 2.0;
    h = wc / pi * sinc(wc / pi * (n - (N - 1) / 2));
    % default length of DTFT is 512
    [X, w] = DTFT(h, 512);
end
