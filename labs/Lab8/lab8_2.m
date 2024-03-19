w1 = ones(21, 1);
w2 = hamming(21);
w3 = hanning(21);
w4 = blackman(21);

[W1, omega1] = DTFT(w1, 512);
[W2, omega2] = DTFT(w2, 512);
[W3, omega3] = DTFT(w3, 512);
[W4, omega4] = DTFT(w4, 512);

figure(1);
subplot(4, 1, 1);
plot((w1));
subplot(4, 1, 2);
plot((w2));
subplot(4, 1, 3);
plot((w3));
subplot(4, 1, 4);
plot((w4));

figure(2);
subplot(4, 1, 1);
plot(omega1, 20 * log10(abs(W1)));
subplot(4, 1, 2);
plot(omega2, 20 * log10(abs(W2)));
subplot(4, 1, 3);
plot(omega3, 20 * log10(abs(W3)));
subplot(4, 1, 4);
plot(omega4, 20 * log10(abs(W4)));

% note there should be a table to measure
% some important parameters

[H, wH, h] = LPFtrunc(21);
figure(3);
subplot(2, 1, 1);
plot(h);
subplot(2, 1, 2);
plot(wH, abs(H));
hf = h .* w2';
[Hf, wHf] = DTFT(hf, 512);
figure(4);
subplot(2, 1, 1);
plot(hf);
subplot(2, 1, 2);
plot(wHf, abs(Hf));
