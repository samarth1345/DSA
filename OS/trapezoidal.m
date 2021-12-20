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
    sum=sum+2*f(a+i*h);
end
sum=sum+f(a)+f(b);
sum=sum*(h/2);
disp(sum);