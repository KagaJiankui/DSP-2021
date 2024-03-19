% get the two truncation function with different length
[X1, w1, h1] = LPFtrunc(21);
[X2, w2, h2] = LPFtrunc(101);

% get window 15 and plot the magnitude of DTFT of
% the first truncation function
figure(15);
subplot(2, 1, 1);
plot(w1, abs(X1));
xlabel('\omega (rad/sample)');
title('magnitude of the DTFT of the truncation function with window length 21, with M=512');
subplot(2, 1, 2);
plot(w1, 20 * log10(abs(X1)));
xlabel('\omega (rad/sample)');
title('magnitude (in decibels) of the DTFT of the truncation function with window length 21, with M=512');

% get window 16 and plot the magnitude of DTFT of
% the second truncation function
figure(16);
subplot(2, 1, 1);
plot(w2, abs(X2));
xlabel('\omega (rad/sample)');
title('magnitude of the DTFT of the truncation function with window length 101, with M=512');
subplot(2, 1, 2);
plot(w2, 20 * log10(abs(X2)));
xlabel('\omega (rad/sample)');
title('magnitude (in decibels) of the DTFT of the truncation function with window length 101, with M=512');

% load the audio into the workspace
nspeech2_struct = load('nspeech2.mat');
nspeech2 = nspeech2_struct.nspeech2;

%
figure(17);
plot(nspeech2);
xlabel('n');
title('original audio signal');

[nspeech2_X, nspeech2_w] = DTFT(nspeech2, 16384);

figure(18);
subplot(2, 1, 1);
plot(nspeech2_w, abs(nspeech2_X));
xlabel('\omega (rad/sample)');
title('magnitude of the DTFT of the original signal, with M=512');
subplot(2, 1, 2);
plot(nspeech2_w, 20 * log10(abs(nspeech2_X)));
xlabel('\omega (rad/sample)');
title('magnitude (in decibels) of the DTFT of the orignal signal, with M=512');

% sound(nspeech2);

% do the filtering
% because this is a FIR filter
% we can simply do the convolution
filtered_1 = conv(nspeech2, h1);
filtered_2 = conv(nspeech2, h2);

[filtered_1_X, filtered_1_w] = DTFT(filtered_1, 16384);
[filtered_2_X, filtered_2_w] = DTFT(filtered_2, 16384);

% get window 19 and plot the
figure(19);
plot(filtered_1);
xlabel('n');
title('filtered signal by length 21 filter, with M=512');

figure(20);
subplot(2, 1, 1);
plot(filtered_1_w, abs(filtered_1_X));
xlabel('\omega (rad/sample)');
title('magnitude of the DTFT of the filtered signal by length 21 filter, with M=512');
subplot(2, 1, 2);
plot(filtered_1_w, 20 * log10(abs(filtered_1_X)));
xlabel('\omega (rad/sample)');
title('magnitude (in decibels) of the DTFT of the filtered signal by length 21 filter, with M=512');

figure(21);
plot(filtered_2);
xlabel('n');
title('filtered signal by length 101 filter, with M=512');

figure(22);
subplot(2, 1, 1);
plot(filtered_2_w, abs(filtered_2_X));
xlabel('\omega (rad/sample)');
title('magnitude of the DTFT of the filtered signal by length 101 filter, with M=512');
subplot(2, 1, 2);
plot(filtered_2_w, 20 * log10(abs(filtered_2_X)));
xlabel('\omega (rad/sample)');
title('magnitude (in decibels) of the DTFT of the filtered signal by length 101 filter, with M=512');

% sound(filtered_1)
sound(filtered_2)

% filtered_2 seems to be more clear

% if you can hear this clearly
% you filter the signal correctly
