% U[10000,10000]
clear all
close all
 x = [1, 10, 50, 100, 200, 500, 1000, 2000, 5000, 10000];
 y = [199784, 199754, 199918, 200203, 200709, 202189, 204703, 209756, 224772, 249720];
 y = y-x*5;
loglog(x,y,'*-')
grid on
xlabel('N aution')
ylabel('mean paid of buyers')
