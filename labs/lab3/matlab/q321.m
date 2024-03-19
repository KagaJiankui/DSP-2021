% 功能：
%   无
% 核心变量：
%   Fs: Generate Original Signal
%   T0:
%   rep:
%   imp:
%   sig1:
%   l1:
%   t1:
%   sig2:
%   l2:
%   t2:
%   Xs1: FFT Spectrum Plot
%   f1:
%   Xs2:
%   f2:
%   sig1up:
%   t1up:
%   sig2up:
%   t2up:
% 备注：
%   无

%   rep: Time to repeat the imp(t)
%   imp: Signal within MPP
%   sig1: Signal 1
%   l1: Length of signal 1
%   t1: Time vector of signal 1
%   sig2: Signal 2
%   l2: Length of signal 2
%   t2: Time vector of signal 2
%   Xs1: FFT Spectrum Plot
%   f1:
%   Xs2:
%   f2:
%   sig1up:
%   t1up:
%   sig2up:
%   t2up:
clear;close;clc;
%% Generate Original Signal
Fs = 64;
T0 = 2; %Minimun positive period(MPP) of the original signal
rep = 4;
imp = linspace(0, T0, Fs * T0);
imp = (imp >= 0) .* (imp <= 1); % x(t)=u(t)*\sum_{k}\delta(t-kT_0)
sig1 = repmat(imp, [1, rep]);
sig1 = [sig1, 0];
l1 = length(sig1);
t1 = linspace(0, T0 * rep, l1);

T0 = 2;
rep = 4;
imp = linspace(0, T0, Fs * T0);
imp = (imp >= 0) .* (imp <= 1/4) + (imp >= 7/4) .* (imp <= 2) - 1/2; % x(t)=u(t)*\sum_{k}\delta(t-kT_0)
sig2 = repmat(imp, [1, rep]);
sig2 = [sig2, 0];
l2 = length(sig1);
t2 = linspace(0, T0 * rep, l1);
%% FFT Spectrum Plot
Xs1 = fftshift(fft(sig1)) / l1;
f1 = linspace(-pi, pi, l1) * Fs;
[sig1up, t1up] = FFTSynth(sig1, Fs, t1(end), 1);
figure(1)
subplot(211)
plot(f1, abs(Xs1))
%% Synthesized Waveform Plot
subplot(212)
plot(t1, sig1)
hold on;
plot(t1up, sig1up)

Xs2 = fftshift(fft(sig2)) / l2;
f2 = linspace(-pi, pi, l2) * Fs;
[sig2up, t2up] = FFTSynth(sig2, Fs, t2(end), 1);
figure(2)
subplot(211)
plot(f2, abs(Xs2))
subplot(212)
plot(t2, sig2)
hold on;
plot(t2up, sig2up)
