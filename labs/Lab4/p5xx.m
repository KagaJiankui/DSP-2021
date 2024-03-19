clear;close;clc;
load LN;

n=2.^n0;
l1=l(1,:);
l2=l(2,:);
l3=l(3,:);
l4=l(4,:);
l5=l(5,:);

f1=fit(n.',l1.','power1');
f2=fit(n.',l2.','power1');
f3=fit(n.',l3.','power1');
f4=fit(n.',l4.','power1');
f5=fit(n.',l5.','power1');

plot(n,l);

% plot(f1,n0,l1);