% basic parameters for matlab running set up
w = -pi:0.001:pi;
j = sqrt(-1);
z = exp(j * w);

% generate the transfer functions
H1 = (1 - 0.99) ./ (1 - 2 * 0.99 * cos(pi / 3) * z.^(- 1) + 0.99^2 * z.^(- 2));
H2 = (1 - 0.9) ./ (1 - 2 * 0.9 * cos(pi / 3) * z.^(- 1) + 0.9^2 * z.^(- 2));
H3 = (1 - 0.7) ./ (1 - 2 * 0.7 * cos(pi / 3) * z.^(- 1) + 0.7^2 * z.^(- 2));

% get window figure 6 and plot the magnitude
% of the three transfer function with different theta
figure(6);
subplot(3, 1, 1);
plot(w, abs(H1));
xlabel('\omega (rad/sample)');
title('magnitude of the frequency response with r=0.99');
subplot(3, 1, 2);
plot(w, abs(H2));
xlabel('\omega (rad/sample)');
title('magnitude of the frequency response with r=0.9');
subplot(3, 1, 3);
plot(w, abs(H3));
xlabel('\omega (rad/sample)');
title('magnitude of the frequency response with r=0.7');

% the closer the poles gets to the unit circle
% the narrower the pass-band will be.
