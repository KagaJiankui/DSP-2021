kaiser_w1 = kaiser(21, 0);
kaiser_w2 = kaiser(21, 1);
kaiser_w3 = kaiser(21, 5);

[kaiser_W1, kaiser_omega1] = DTFT(kaiser_w1, 512);
[kaiser_W2, kaiser_omega2] = DTFT(kaiser_w2, 512);
[kaiser_W3, kaiser_omega3] = DTFT(kaiser_w3, 512);

figure(5);
subplot(3, 1, 1);
plot(kaiser_w1);
subplot(3, 1, 2);
plot(kaiser_w2);
subplot(3, 1, 3);
plot(kaiser_w3);

figure(6);
subplot(3, 1, 1);
plot(kaiser_omega1, abs(kaiser_W1));
subplot(3, 1, 2);
plot(kaiser_omega1, abs(kaiser_W2));
subplot(3, 1, 3);
plot(kaiser_omega1, abs(kaiser_W3));

sigma = 0.005;
A = -20 * log10(sigma);
% A=42.0206
beta = 0.5842 * (A - 21)^0.4 + 0.07886 * (A - 21);
% beta=4.0909
N = ceil(1 + (A - 8) / (2.285 * 0.045));
% N=371

[H, wH, h] = LPFtrunc(N);

kaiser_w = kaiser(N, beta);
[kaiser_W, kaiser_omega] = DTFT(kaiser_w, 512);
figure(7);
subplot(2, 1, 1);
plot(kaiser_w);
subplot(2, 1, 2);
plot(kaiser_omega, abs(kaiser_W));

hf = h .* (kaiser_w.');
[Hf, Hfw] = DTFT(hf, 512);
figure(8);
subplot(2, 1, 1);
plot(hf);
subplot(2, 1, 2);
plot(Hfw, abs(Hf));

nspeech2 = (load('nspeech2.mat').nspeech2).';

filtered_nspeech2 = conv(hf, nspeech2);
[fil_nsp2_H, fil_nsp2_w] = DTFT(filtered_nspeech2(20001:20400), 400);
figure(9);
subplot(2, 1, 1);
plot(filtered_nspeech2);
subplot(2, 1, 2);
plot(fil_nsp2_w, abs(fil_nsp2_H));

% sound(filtered_nspeech2);
