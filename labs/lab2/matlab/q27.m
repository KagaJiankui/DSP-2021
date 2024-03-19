clear;close;clc;

func_unkn={@bbox1,@bbox2,@bbox3};
isnl=[];
istv=[];
%Global Variables
for f=func_unkn
    a=detNL(f{1},randi(12),randi(12),120);
    b=detTV(f{1},randi(20),40,120);
    isnl=[isnl,a];
    istv=[istv,b];
end
isnl
istv
% f = [];
%Plot area

% imgWrite(f)

function imgWrite(f)

    for s = 1:length(f)
        imwrite(frame2im(getframe(f(s))), append(mfilename(), "_", string(s), ".png"))
    end

end

function ret=detNL(ufunc,tl1,tl2,tsL)
    ts1=rand([1,tsL]);
    ts2=rand([1,tsL]);
    test=ufunc(ts1*tl1+ts2*tl2)-ufunc(ts1)*tl1-ufunc(ts2)*tl2;
    ret=(max(abs(test))<=1e-5)*1;
end

function ret=detTV(ufunc,dt,paddle,tsL)
    ts1=[zeros(1,paddle),rand([1,tsL]),zeros(1,paddle)];
    ts2=circshift(ts1,dt);
    out1=ufunc(ts1);
    out2=ufunc(ts2);
    test=out2-circshift(out1,dt);
    ret=(max(abs(test))<=1e-5)*1;
end