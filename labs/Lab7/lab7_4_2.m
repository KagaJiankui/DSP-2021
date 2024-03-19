% load the sound into workspace
pcm_struct = load('pcm.mat');
pcm = pcm_struct.pcm;

%sound(pcm)

% get window figure 7 and plot portion of the original audio signal
figure(7);
plot(pcm(100:200));
xlabel('n');
title('portion of audio signal in time domain, pcm(100:200)');

% do a 1024 length DTFT to the portion of original audio signal
M = 1024;
[pcm_X, pcm_w] = DTFT(pcm(100:1100), M);

% get window figure 8 and plot the DTFT of the audio signal
figure(8);
plot(pcm_w, abs(pcm_X));
xlabel('\omega (rad/sample)');
title('magnitude of the DTFT of the portion of the audio signal (100:1100), pcm_X, with M=1024');

% evaluation for the desired frequency by given specification
theta = 3146/8000 * 2 * pi;

%%%%%%%%%%%%%%%%%%%%%%%%%%
% Now do the filtering
% note that this function is leak of self paramters
% thus can only be run when the cutoff frequency theta
% is given
filtered_pcm = IIRfilter(pcm, theta, 0.995);
%%%%%%%%%%%%%%%%%%%%%%%%%%

% get window figure 9 and plot portion of the filtered signal
figure(9);
plot(filtered_pcm(100:200));
xlabel('n');
title('portion of filtered audio signal in time domain, filtered pcm(100:200)');

% do a 1024 length DTFT (with the same M) to the portion of filtered signal
[filtered_pcm_X, filtered_pcm_w] = DTFT(filtered_pcm(100:1100), M);

% get wimdow figure 10 and plot the DTFT of the portion of the filtered signal
figure(10);
plot(filtered_pcm_w, abs(filtered_pcm_X));
xlabel('\omega (rad/sample)');
title('magnitude of the DTFT of the portion of the filtered audio signal (100:1100), filtered pcm X, with M=1024');

% the plot below gets the portion of the DTFT
% and compare with the original one
figure(11);
range = (511 - ceil((theta + 0.02) / (pi) * 512)):(513 - floor(((theta - 0.02) / (pi) * 512)));
plot(pcm_w(range), abs(pcm_X(range)));
hold on;
plot(filtered_pcm_w(range), abs(filtered_pcm_X(range)));
legend('pcm X', 'filtered pcm X');
xlabel('\omega (rad/sample)');
title('magnitude of the DTFT of the portion of the filtered audio signal (\theta-0.02:\theta-0.02), (filtered) pcm X, with M=1024');

% sound(filtered_pcm)

%
% the code below gets the result when r =0.9999999
filtered_pcm_2 = IIRfilter(pcm, theta, 0.9999999);

% get wimdow figure 13 and plot the portion of the filtered signal
figure(13);
plot(filtered_pcm_2(100:200));
xlabel('n');
title('portion of filtered audio signal in time domain, filtered pcm 2(100:200)');

% do a 1024 length DTFT to portion of original audio signal
[filtered_pcm_2_X, filtered_pcm_2_w] = DTFT(filtered_pcm_2(100:1100), M);

% get wimdow figure 14 and plot the DTFT of the portion of the filtered signal
figure(14);
plot(filtered_pcm_2_w, abs(filtered_pcm_2_X));
xlabel('\omega (rad/sample)');
title('magnitude of the DTFT of the portion of the filtered audio signal (100:1100), filtered pcm 2 X, with M=1024');

% sound(filtered_pcm_2)

% because it gets all maginitude too small!
