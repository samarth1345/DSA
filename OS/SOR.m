format short
clc
clear all;
A=[10 8 -3 1;2 10 1 -4;3 -4 10 1;2 2 -3 10];
n=size(A,2);
x=zeros(1,n);
b=[16 9 10 11];
maxerr=1e-3;
w=input('Enter value of w = ');
err=Inf;
while err > maxerr
    x_old=x;
    for i=1:n
        sum=0;
        for j=1:i-1
            sum=sum+A(i,j)*x(j);
        end
        for j=i+1:n
            sum=sum+A(i,j)*x_old(j);
        end
        x(i)=(1-w)*x_old(i)+(b(i)-sum)*(w/A(i,i));
    end
    err=abs(x_old-x);
end
fprintf('required values are \n');
disp(x);