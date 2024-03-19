function [sig1up,tup]=FFTSynth(x,Fs,Ts,usf)
    %% Determine Fourier Coefficients with FFT result
    l1=length(x);
    Xs=fftshift(fft(x))/l1;
    f1=linspace(-pi,pi,l1)*Fs;
    Xs=2*Xs(ceil(l1/2):end); % Single-Side Spectrum
    Xs1=abs(Xs);
    Cs=angle(Xs);
    %x(t)=\tilde{A} exp(j*k*w_0*t)=abs(A)cos(arg(A))cos(k*w_0*t)+j*abs(A)sin(arg(A))sin(k*w_0*t)
    [As1,q]=findpeaks(Xs1);
    % coefficients of FS(x(t))=1/T(x(t))*DFT(x(t))
    Fs1=f1(q+floor(l1/2))
    Cs1=Cs(q)
    t1=linspace(0,Ts,l1);
    %x(t)=abs(A)cos(k*w_0*t+arctan(arg(A)))
    %% Synthing Fourier Series
    x1=arrayfun(@(w,th) cos(w*t1+th),Fs1,Cs1,'UniformOutput',false);
    x2=diag(As1)*cell2mat(x1.');
    sig1syn=sum(x2,1)+Xs1(1)/2;
    %% Upsampling
    sig1up=interp(sig1syn,usf);
    tup=interp(t1,usf);
end
