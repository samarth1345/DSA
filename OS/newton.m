format short
clc
clear all;
x=[1 1.5 2.0 2.5];
f=[2.7183 4.4817 7.3891 12.1825];
a=input('Enter interpolating value = ');
n=length(x);
DD=zeros(n,n);
DD(:,1)=f';
for j=2:n
    for i=1:n-j+1
        DD(i,j)=(DD(i+1,j-1)-DD(i,j-1))/(x(i+j-1)-x(i));
    end
end
for i=1:n-1
    P(i)=prod(a-x(1,1:i))*DD(1,i+1);
end
A=f(1)+sum(P);
disp(A);
    
