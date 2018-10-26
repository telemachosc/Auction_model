%everyone need 100 energy
clear all
close all
 x = [1, 10, 50, 100, 200, 500, 1000, 2000, 5000, 10000];
 y = [2000, 2000, 2000, 2080.85, 2180.62, 2481.04, 2972.28, 3980.52, 6973.56, 11965.7];
 %y = y-x*5;
loglog(x,y,'*-')
grid on
xlabel('N aution')
ylabel('mean paid of buyers')
