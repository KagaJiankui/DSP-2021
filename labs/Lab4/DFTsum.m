function Xk=DFTsum(xn,N)
n=0:N-1;   
nk=n'*n;     %’*的意思是先将n转置，再乘k；所得出的矩阵，行=x(n）级同n，列=同k或者说n值不同k相同
WNnk=exp(-1j*2*pi/N).^nk;
Xk=xn*WNnk; %行向量x(n)×W的第a列后会得出一个数值（非数组），此数值=同一个k（即X(k)中的那个）在∑x(n)×W（不同n），得出的
end