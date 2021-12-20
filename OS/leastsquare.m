format short
clc
clear all;
x=[2 3 4 5];
y=[27.8 62.1 110 161];
plot(x,y,'r*');
hold on
n=length(x);
sum_x=sum(x);
sum_y=sum(y);
sum_x2=sum(x.*x);
sum_xy=sum(x.*y);
A=[n sum_x;sum_x sum_x2];
b=[sum_y;sum_xy];
f=inv(A)*b;
t=f(1)+f(2)*x;
plot(x,t,'b');