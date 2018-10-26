clear all
close all
 x = [1, 50, 100, 200, 500, 1000, 2000, 5000, 10000];
 y = [0 , 4344.98, 4850.93, 5080.74, 5204.16, 5240.28, 5260.89, 5270.7, 5271.94];

loglog(x,y,'*-')
grid on
title('Log Plot')
xlabel(' ')
ylabel(' ')