function [mag,phase,w]=FreRes(b,a,n)
    w=linspace(0,1,n);
    nb = length(b);
    na = length(a);
    a  = [a zeros(1,nb-na)];  % Make a and b of the same length
    b  = [b zeros(1,na-nb)];
    s = warning; % Cache warning state
    warning off  % Avoid "Divide by zero" warnings
    res_comp = (fft(b,2*n)./fft(a,2*n)).';
    warning(s);
    mag=abs(res_comp(1:n));
    phase=angle(res_comp(1:n));
end