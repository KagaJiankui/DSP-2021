function env=GenADSRenv(x,vx,vy)
    tv=linspace(0,1,length(x));
    vxi=[0,vx];
    vyi=[0,vy];
    ya=zeros(1,length(tv));
    for i=1:(length(vxi)-1)
        ya=ya+Line(tv,[vxi(i),vyi(i)],[vxi(i+1),vyi(i+1)]).*(tv>=vxi(i)&tv<vxi(i+1));
    end
    env=ya;
end

function y=Line(x,p1,p2)
    y=(x-p2(1)).*(p2(2)-p1(2))./(p2(1)-p1(1))+p2(2);
end