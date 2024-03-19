function freq=tone2freqA(number)
    % 基于A1=440Hz计算八度音程频率.也可以从A1计算一个八度以内的音调频率.
    % 语法: freq=tone2freqA(number) number->[0,12] 可以接受矩阵输入
    % 公式: f=f_0*2^(number/12) (十二平均律)
    fA=440;
    freq=fA*2.^(number/12);
end