clc
clear all
a=[];
disp("enter moments of inertia")
for i=1:3
    b=[];
    for j=1:3
        x=input("enter matrix element");
        b=[b x];
    end
    a=[a;b];
end
disp(a)
eig(a)