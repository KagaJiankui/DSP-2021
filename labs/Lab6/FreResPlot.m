function fig=FreResPlot(m,p,w,nf)
    figure(nf);
    subplot(211);
    semilogy(w,m)
    grid on
    subplot(212);
    plot(w,p)
    grid on
    fig=figure(nf);
end