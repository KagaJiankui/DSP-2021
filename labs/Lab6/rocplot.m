function fig=rocplot(num,den,nfig)
fig=figure(nfig);
[z1x,p1x]=tf2zpk(num,den)
zp=zplaneplot(z1x,p1x);
xl1=xlim;
yl1=ylim;
hold on;
xr1=[xl1(1),max(abs(p1x))*cos(linspace(pi,0,30)),xl1(2),xl1(2),xl1(1)];
yr1=[0,max(abs(p1x))*sin(linspace(pi,0,30)),0,yl1(2),yl1(2)];
yr2=[0,max(abs(p1x))*sin(linspace(pi,2*pi,30)),0,yl1(1),yl1(1)];
patch('XData',xr1,'YData',yr1,'FaceColor','#CC6133','FaceAlpha',0.2);
patch('XData',xr1,'YData',yr2,'FaceColor','#CC6133','FaceAlpha',0.2);
xr3=min(abs(p1x))*cos(linspace(0,2*pi,60));
yr3=min(abs(p1x))*sin(linspace(0,2*pi,60));
patch('XData',xr3,'YData',yr3,'FaceColor','#4433CC','FaceAlpha',0.3);
uistack(zp,'top')
end