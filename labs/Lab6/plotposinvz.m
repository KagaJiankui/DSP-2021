function fig=plotposinvz(num,den,n,nfig)
[r1,p1,k1]=residuez(num,den);
fig=figure(nfig);
subplot(311);
x_right=invz_right(r1,p1,n);
stem(0:n,x_right)
subplot(312);
x_left=invz_left(r1,p1,n);
stem(-n:0,x_left)
subplot(313);
x_double=invz_double(r1,p1,n);
stem(-n:n,x_double)
end

function yn=invz_right(r,p,n)
    t=0:n;
    yn=(r.')*(p.^t);
end

function yn=invz_left(r,p,n)
    t=-n:0;
    yn=(r.')*(p.^t);
end

function yn=invz_double(r,p,n)
    t=-n:n;
    yn=(r.')*(p.^t);
end