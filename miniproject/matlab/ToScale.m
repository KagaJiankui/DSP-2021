function table=ToScale(Base,Minority)
    % 将调号转为音阶序,大调音阶起始音符为Base,小调音阶起始音符为Base降低四度
    % 语法: table=ToScale(Base,Minority)
    % Base: 起始音符
    % Minority: 大小调切换,0为大调,非0为小调
    scale1=cumsum([2,1,2,2,1,2,2]);
    scale2=cumsum([2,2,1,2,2,2,1]);
    if all(isa(Base,'char'))
        Base=Base-'A';
    end
    minor=[4,3,3,4,4,3,4];
    if Base==0
        table=[0,scale2]-(Minority~=0)*4;
    else
        table=scale1(Base)+[0,scale2]-(Minority~=0)*minor(Base);
    end
end