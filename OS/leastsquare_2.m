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
sum_x3=sum(x.*x.*x);
sum_x4=sum(x.*x.*x.*x);
sum_xy=sum(x.*y);
sum_x2y=sum(x.*x.*y);
A=[n sum_x sum_x2;sum_x sum_x2 sum_x3;sum_x2 sum_x3 sum_x4];
b=[sum_y;sum_xy;sum_x2y];
f=inv(A)*b;
t=f(1)+f(2)*x+f(3)*x.*x;
plot(x,t,'b');