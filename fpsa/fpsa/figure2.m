% they need U[100,1000]
clear all
close all
 x = [1, 10, 50, 100, 200, 500, 1000, 2000, 5000, 10000];
 y = [11012.4, 11007.1, 11057.3, 11328.7, 11803.1, 13327.3, 15813.5, 20718.7, 35524.9, 60227.5];
 y = y-x*5;
loglog(x,y,'*-')
grid on
xlabel('N aution')
ylabel('mean paid of buyers')
