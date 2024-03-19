function Y=Reverse_Rader(F,N)
LH=N/2; 
J=LH; 
N1=N-2;  
for I=1:1:N1    
    if I<J         
        T=F(I+1);         
        F(I+1)=F(J+1);        
        F(J+1)=T;     
    end
    K=LH; %K是比较位数的指示，一开始是二进制最高位，如果J的K位为1，则跳0，比较下一位     
    while J>=K   %是0则不跳，退出循环      
        J=J-K;         
        K=K/2;     
    end
    J=J+K; %K位跳1 还是不明白逻辑，太神棍了这段代码
end
Y=F;
end