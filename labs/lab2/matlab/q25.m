clear;close;clc;

[y, Fs] = audioread("music.au");
el = floor(length(y) / 2) * 2;
f0 = Fs * (0:(el / 2)) / el;

fy = fftSingle(y);
fy(1) = 0;

s1 = [[1, -1]; [1, 0]];
s2 = [[1, 0]; [1, -0.5]];
y1 = filter(s1(1, :), s1(2, :), y);
y2 = filter(s2(1, :), s2(2, :), y);
fy1 = fftSingle(y1);
fy1(1) = 0;
fy2 = fftSingle(y2);
fy2(1) = 0;
% sound(y1);
% sound(y2);

f = [];
fig = figure(1);
subplot(211)
plot(f0, fy)
hold on;
plot(f0, fy1);
title('Single-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
ylabel('|P1(f)|')
legend('Original Signal', 'Signal after filter S_{1}', 'Location', 'northeast');
subplot(212);
plot(f0, fy1 - fy);
xlabel('f (Hz)')
ylabel('|P1(S_{1}(x)))-P1(x)|')
title('Difference between S_{1}(x) and x');
f = [f; fig];

fig = figure(2);
subplot(211);
plot(f0, fy2);
hold on;
plot(f0, fy);
title('Single-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
ylabel('|P1(f)|')
legend('Signal after filter S_{2}', 'Original Signal', 'Location', 'northeast');
subplot(212);
plot(f0, fy2 - fy);
xlabel('f (Hz)')
ylabel('|P1(S_{2}(x)))-P1(x)|')
title('Difference between S_{2}(x) and x');
f = [f; fig];

%Bode Plot
w = logspace(-1, log10(Fs), 200);
sys1 = tf(s1(1, :), s1(2, :), 1 / Fs);
[mag, phase, wout] = bode(sys1, w);
mag1 = mag(1, :);
phase1 = phase(1, :);
fig = figure(3);
subplot(211);
semilogx(wout, mag1);
title('Magnitude of S_{1}(f)')
xlabel('f (Hz)')
ylabel('|P1(f)|')
subplot(212);
semilogx(wout, phase1);
title('Phase of S_{1}(f)')
xlabel('f (Hz)')
ylabel('|P1(f)|')
f = [f; fig];

sys2 = tf(s2(1, :), s2(2, :), 1 / Fs);
[mag, phase, wout] = bode(sys2, w);
mag2 = mag(1, :);
phase2 = phase(1, :);
fig = figure(4);
subplot(211);
semilogx(wout, mag2);
title('Magnitude of S_{2}(f)')
xlabel('f (Hz)')
ylabel('|P1(f)|')
subplot(212);
semilogx(wout, phase2);
title('Phase of S_{2}(f)')
xlabel('f (Hz)')
ylabel('|P1(f)|')
f = [f; fig];

imgWrite(f);

function imgWrite(f)

    for s = 1:length(f)
        imwrite(frame2im(getframe(f(s))), append(mfilename(), "_", string(s), ".png"))
    end

end

function fout = fftSingle(y)
    el = floor(length(y) / 2) * 2;
    fy = abs(fft(y) / length(y));
    fy = fy(1:el);
    fy = fy(1:(el / 2 + 1));
    fy(2:(end - 1)) = 2 * fy(2:(end - 1));
    fout = fy;
end
