close; clear; clc;
f = [];
%Eq2.3
b1 = [1, 1, 1] * 1/3;
a1 = 1;
t = 0:10;
d1 = impseq(t(1), 0, t(end));
y1 = filter(b1, a1, d1);
fig = figure(1);
stem(t, y1);
legend('Method 2.3');
f = [f; fig];

%Eq2.4
b2 = 1 * 0.2;
a2 = [1, -0.8];
t = 0:15;
d2 = impseq(t(1), 0, t(end));
y2 = filter(b2, a2, d2);
fig = figure(2);
stem(t, y2);
legend('Method 2.4');
f = [f; fig];

%Eq2.5
b3 = [1, 0, 0, -1] * 1/3;
a3 = [1, -1];
t = 0:10;
d3 = impseq(t(1), 0, t(end));
y3 = filter(b3, a3, d3);
fig = figure(3);
stem(t, y3);
legend('Method 2.3');
f = [f; fig];

imgWrite(f);

function imgWrite(f)
    %imgWrite - Write plots to the same directory of the M-file
    %
    % Syntax: imgWrite(f)
    %
    % Use For loop to write plots to the same directory of the M-file, renaming the plots sequently at the same time.
    for s = 1:length(f)
        imwrite(frame2im(getframe(f(s))), append(mfilename(), "_", string(s), ".png"))
    end

end

function x = impseq(n0, n1, n2)
    % impseq：产生一个冲激函数
    % 参数：在n0-n2之间，n1处为1，其余为0
    % 返回： x是冲激序列
    n = n0:n2;
    x = [(n - n1) == 0];
end
