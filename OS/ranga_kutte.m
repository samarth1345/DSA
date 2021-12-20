format short
clc
clear all;
f=@(t,y) -y+2*cos(t);
a=input('Enter lower limit = ');
b=input('Enter upper limit = ');
h=0.2;
t(1)=input('Enter initial value of t = ');
y(1)=input('Enter initial value of y = ');
n=(b-a)/h;
for i=1:n
    t(i+1)=t(i)+h;
    k1=h*f(t(i),y(i));
    k2=h*f(t(i)+h/2,k1/2+y(i));
    k3=h*f(t(i)+h/2,k2/2+y(i));
    k4=h*f(t(i+1),k3+y(i));
    k=(k1+2*k2+2*k3+k4)/6;
    y(i+1)=y(i)+k;
end
disp(y);