clear;close;clc;
s1 = [[1, -1]; [1, 0]];
s2 = [[1, 0]; [1, -0.5]];
t = 0:15;
x = impseq(t(1), 0, t(end));
y1 = filter(s1(1, :), s1(2, :), x);
y2 = filter(s2(1, :), s2(2, :), x);
y12 = filter(s1(1, :), s1(2, :), y2);
y21 = filter(s2(1, :), s2(2, :), y1);
s1p2 = s1 + s2;
y1p2 = filter(s1p2(1, :), s1p2(2, :), x);
%Global Variables
f = [];
plist = [y1; y2; y12; y21; y1p2];

for index = 1:5
    fig = figure(index);
    stem(t, plist(index, :));
    f = [f; fig];
end

%Plot area
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

function x = heaviseq(n0, n1, n2)
    % heaviseq：产生一个阶跃函数
    % 参数：在n0-n2之间，n>=n1处为1，其余为0
    % 返回： x是阶跃序列
    x = 1 * ([n0:n2] - n1 >= 0) * 1;
end
