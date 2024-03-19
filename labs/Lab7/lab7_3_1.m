% basic parameters for matlab running set up
w = -pi:0.001:pi;
j = sqrt(-1);
z = exp(j * w);

% generate the transfer functions
H1 = 1 - 2 * cos(pi / 6) * z.^(- 1) + z.^(- 2);
H2 = 1 - 2 * cos(pi / 3) * z.^(- 1) + z.^(- 2);
H3 = 1 - 2 * cos(pi / 2) * z.^(- 1) + z.^(- 2);

% get window figure 1 and plot the magnitude
% of the three transfer function with different theta
figure(1);
plot(w, abs(H1));
hold on;
plot(w, abs(H2));
hold on;
plot(w, abs(H3));
legend('H1 with \theta = \pi/6', 'H2 with \theta = \pi/3', 'H3 with \theta = \pi/2');
xlabel('\omega (rad/sample)');
title('maginitude response of the filter when \theta is different')
