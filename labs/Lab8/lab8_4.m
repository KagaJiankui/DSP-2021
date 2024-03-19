f = [1.8, 2.2];
m = [1, 0];
ripple = [0.05, 0.005];
[n, fo, mo, w] = firpmord(f, m, ripple, 2 * pi);
b = firpm(n + 3, fo, mo, w);
h = b;
[H, w] = DTFT(h, 512);
figure(10);
subplot(2, 1, 1);
plot(h);
subplot(2, 1, 2);
plot(w, 20 * log10(abs(H)));

x = (load('nspeech2.mat').nspeech2).';
y = conv(x, h);

[Y, Yw] = DTFT(y(20001:20400), 400);

figure(11);
subplot(2, 1, 1);
plot(x);
subplot(2, 1, 2);
plot(Yw, abs(Y));

% sound(y);
