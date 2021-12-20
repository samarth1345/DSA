format short
clc
clear all;
t=[0 8 16 24 32 40];
O=[14.621 11.843 9.870 8.418 7.305 6.413];
a=input('Enter interpolate value = ');
n=length(t);
for i=1:n
    t_new=t;
    t_new(i)=[];
    k1=prod(a-t_new);
    k2=prod(t(i)-t_new);
    l(i)=k1/k2;
end
p=sum(l.*O);
disp(p);