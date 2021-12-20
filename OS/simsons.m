format short
clc
clear all;
n=input('Enter no of intervals = ');
f=@(x) (cos(x))^2;
a=input('Enter lower limit = ');
b=input('Enter upper limit = ');
h=(b-a)/n;
sum=0;
for i=1:n-1
    if rem(i,2)==0
        sum=sum+2*f(a+i*h);
    else
        sum=sum+4*f(a+i*h);
    end
end
sum=sum+f(a)+f(b);
sum=sum*(h/3);
disp(sum);