clear;close;clc;
load 'stockrates.mat'
t = 0:(length(rate) - 1);
f24 = [[0.2, 0]; [1, -0.8]];
y1 = filter(f24(1, :), f24(2, :), rate);

f25 = [[1, 0, 0, -1] * 1/3; [1, -1, 0, 0]];
y2 = filter(f25(1, :), f25(2, :), rate);

%Given the initial condition at t=-1 using filtic(b,a,y)
zi1 = filtic(f24(1, :), f24(2, :), rate(1))
y1zi = filter(f24(1, :), f24(2, :), rate, zi1);

%Global Variables
f = [];
%Plot area
fig = figure(1);
plot(t, rate);
hold on;
plot(t, y1);
title('LPF with zero initial value');
legend('Input Rate', 'LPF Filtered Rate', 'Location', 'southeast');
f = [f; fig];
fig = figure(2);
plot(t, rate);
hold on;
plot(t, y2);
title('Moving-Average with zero initial value');
legend('Input Rate', 'Moving-Average Filtered Rate', 'Location', 'southeast');
f = [f; fig];
fig = figure(3);
subplot(211);
stem(t, y1 - rate);
hold on;
stem(diff(y1));
title('Residue and smoothness after LPF filtering');
legend('Residue', '1st-diff', 'Location', 'southeast');
subplot(212);
stem(t, y2 - rate);
hold on;
stem(diff(y2));
title('Residue and smoothness after MA filtering');
legend('Residue', '1st-diff', 'Location', 'southeast');
f = [f; fig];
fig = figure(4);
subplot(211);
plot(t, rate);
hold on;
plot(t, y1zi);
title('LPF with same initial value');
legend('Input Rate', 'LPF Filtered Rate', 'Location', 'southeast');
subplot(212);
stem(t, y1zi - rate);
hold on;
stem(diff(y1zi))
title('Residue and smoothness after MA filtering');
legend('Residue', '1st-diff', 'Location', 'northeast');
f = [f; fig];
imgWrite(f)

function imgWrite(f)

    for s = 1:length(f)
        imwrite(frame2im(getframe(f(s))), append(mfilename(), "_", string(s), ".png"))
    end

end
