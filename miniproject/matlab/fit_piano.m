clear;close;clc;
fn=[440.1,880.8,1320.6,1760.9,2201.1,2640.7];
an=[0.1262,0.0152,0.0062,0.0044,0.0059,0.0043];
fn2=(1:19);
an2=[987.8,368.6,620.2,483.9,156.7,83.62,120.1,70.73,5.348,24.41,27.35,21.3,10.31,6.477,15.91,3.495,2.546,0.4751,0.8858]/1000;

fn_norm=fn.'/fn(1);
an_norm=an.';
s1=fitoptions('Method','NonlinearLeastSquares', ...
    'Lower',[-10,-10,-10], ...
    'Upper',[1,1,1], ...
    'StartPoint',[1.4,1.2,0].');
ftype1=fittype('a*exp(-b*x)+c1', ...
    'independent','x', ...
    'coefficients',{'a','b','c1'});

f1=fit(fn_norm,an_norm,ftype1);
disp(coeffvalues(f1));
figure(1)
plot(f1,fn_norm,an_norm);

an_fit=feval(f1,fn/fn(1)).';
figure(2)
subplot(211)
scatter(fn,an)
hold on
plot(fn,an_fit)
subplot(212)
plot(fn,an-an_fit)