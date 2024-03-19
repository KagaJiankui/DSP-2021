clear;close;clc;

s2 = [[1, 0]; [1, -0.5]];
s3 = [[1, -0.5]; [1, 0]];
t = 0:15;
x = impseq(t(1), 0, t(end));
y2 = filter(s2(1, :), s2(2, :), x);
y3 = filter(s3(1, :), s3(2, :), x);
yx = filter(s3(1, :), s3(2, :), y2);
%Global Variables
f = [];
%Plot area

fig = figure(1);
stem(t, y2);
f = [f; fig];

fig = figure(2);
stem(t, y3);
f = [f; fig];

fig = figure(3);
subplot(211);
stem(t, yx);
subplot(212);
stem(t, x);
f = [f; fig];

imgWrite(f)

function imgWrite(f)

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
