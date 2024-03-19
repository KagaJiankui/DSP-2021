% load the sound into workspace
nspeech1_struct = load('nspeech1.mat');
nspeech1 = nspeech1_struct.nspeech1;

% sound(nspeech1);

% get window figure 2 and plot portion of the original audio signal
figure(2);
plot(nspeech1(100:200));
xlabel('n');
title('portion of audio signal in time domain, nspeech1(100:200)');

% do a 16384 length DTFT to the portion of original audio signal
M = 16384;
% M = 10240;
% M = 1024;
[nspeech1_X, nspeech1_w] = DTFT(nspeech1(100:1100), M);

% get window figure 3 and plot the DTFT of the audio signal
figure(3);
plot(nspeech1_w, abs(nspeech1_X));
xlabel('\omega (rad/sample)');
title('magnitude of the DTFT of the portion of the audio signal (100:1100), nspeech1 X, with M=16384');

% find the maximum value of the DTFT
% find the theta for the sinusoidal interference signal
nspeech1_mas_X = abs(nspeech1_X);
[nspeech1_Xmax, nspeech1_Imax] = max(abs(nspeech1_X));
nspeech1_theta = nspeech1_w(nspeech1_Imax);
% nspeech1_theta = -1.3254

%%%%%%%%%%%%%%%%%%%%%%%%%%
% Now do the filtering
% note that this function is leak of self paramters
% thus can only be run when the cutoff frequency theta
% is given
filtered_nspeech1 = FIRfilter(nspeech1, nspeech1_theta);
%%%%%%%%%%%%%%%%%%%%%%%%%%

% get window figure 4 and plot portion of the filtered signal
figure(4);
plot(filtered_nspeech1(100:200));
xlabel('n');
title('portion of filtered audio signal in time domain, filtered nspeech1(100:200)');

% do a 16384 length DTFT (with the same M) to the portion of filtered signal
[filtered_nspeech1_X, filtered_nspeech1_w] = DTFT(filtered_nspeech1(100:1100), M);

% get wimdow figure 5 and plot the DTFT of the portion of the filtered signal
figure(5);
plot(filtered_nspeech1_w, abs(filtered_nspeech1_X));
xlabel('\omega (rad/sample)');
title('magnitude of the DTFT of the portion of the filtered audio signal (100:1100), filtered nspeech1 X, with M=16384');

% sound(filtered_nspeech1);

% the audio is 'please get rid of this beep'

% the beep is much weaker and we can hear the voice
% the frequency of the beep decreases

% the filter we used is a bandstop filter
% because we get the frequency reponse zero when the
% frequency is +-1.3254 rad/sample, which is at the
% of the frequency response.

% from the other side, we can know this is a bandstop
% by the transfer function itself. zeros at middle point
% it is a type I filter and can be made to bandstop

% the filter get rid of the beep!
