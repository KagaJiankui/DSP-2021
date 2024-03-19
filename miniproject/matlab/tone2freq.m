function freq=tone2freq(tone,noctave,rising,base,minority)
    % 计算任意八度音程的频率,基音f0.
    % 语法: freq=tone2freq(tone,noctave,rising,base,minority)
    % tone: 输入数字音符,数值范围1到7
    % noctave: 高或低八度的数量,数值范围整数. 0表示中音,正数表示高 noctave个八度,负数为低 noctave个八度
    % rising: 升或降调. 1为升,-1为降,0无升降调
    % base: 基音音调,默认为C大调音阶
    % minority: 大小调切换,0为大调,非0为小调
    % freq为输出的频率
    if tone<1||tone>7
        error("输入的音符 %d 不在表示范围 [1,7] 内",tone);
    end
    tbl1=ToScale(base,minority);
    freq=440*2.^((tbl1(tone)+rising)/12+noctave);
end

