% U[1,10000]
clear all
close all
 x = [1, 10, 50, 100, 200, 500, 1000, 2000, 5000, 10000];
 y = [100148, 100046, 100116, 100578, 100724, 102538, 105129, 109884, 124702, 149930];
 y = y-x*5
plot(x,y,'*-')
grid on
xlabel('N aution')
ylabel('mean paid of buyers')
