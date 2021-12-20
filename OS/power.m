format short
clc
clear all;
A=[4 1 0;1 20 1;0 1 4];
n=size(A,1);
x=ones(n,1);
maxerr=1e-3;
err=Inf;
k=Inf;
while(err>maxerr)
    y=A*x;
    k0=max(y);
    x=(1/k0)*y;
    err=abs(k-k0);
    k=k0;
end
disp(x);
disp(k);