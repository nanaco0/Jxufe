function map
x=0:400:5600;
y=0:400:4800;
z=[370 470 550 600 670 690 670 620 580 450 400 300 100 150 250;
   510 620 730 800 850 870 850 780 720 650 500 200 300 350 320;
   650 760 880 970 1020 1050 1020 830 800 700 300 500 550 480 350;
   740 880 1080 1130 1250 1280 1230 1040 900 500 700 780 750 650 550;
   830 980 1180 1320 1450 1420 1400 1300 700 900 850 840 380 780 750;
   880 1060 1230 1390 1500 1500 1400 900 1100 1060 950 870 900 930 950;
   910 1090 1270 1500 1200 1100 1350 1450 1200 1150 1010 880 1000 1050 1100;
   950 1190 1370 1500 1200 1100 1550 1600 1550 1380 1070 900 1050 1150 1200;
   1430 1450 1460 1500 1550 1600 1550 1600 1600 1600 1550 1500 1500 1550 1550; 
   1420 1430 1450 1480 1500 1550 1510 1430 1300 1200 980 850 750 550 500;
   1380 1410 1430 1450 1470 1320 1280 1200 1080 940 780 620 460 370 350;
   1370 1390 1410 1430 1440 1140 1110 1050 950 820 690 540 380 300 210;
   1350 1370 1390 1400 1410  960  940  880 800 690 570 430 290 210 150];
[X,Y]=meshgrid(x,y);

subplot(2,3,1)
%实色边、实色面的三维曲面
surf(X,Y,z)
hold on
plot3(0,800,z(3,1),'rp','markersize',16,'markerfacecolor','r')
plot3(4000,2000,z(6,11),'yp','markersize',16,'markerfacecolor','y')
plot3(2000,4000,z(11,6),'bp','markersize',16,'markerfacecolor','b')
text(0,800,z(3,1)+9,'公路起点','FontWeight','bold')%为防止文字被三维图遮盖，将z轴+9
text(4000,2000,z(6,11)+9,'村庄','FontWeight','bold')
text(2000,4000,z(11,6)+9,'矿山','FontWeight','bold')
title('山区概貌图','FontSize',16,'FontWeight','bold')
hold off

subplot(2,3,4)
%有实色边、无实色面的三维曲面
mesh(X,Y,z)
hold on
plot3(0,800,z(3,1),'rp','markersize',16,'markerfacecolor','r')
plot3(4000,2000,z(6,11),'yp','markersize',16,'markerfacecolor','y')
plot3(2000,4000,z(11,6),'bp','markersize',16,'markerfacecolor','b')
text(0,800,z(3,1)+9,'公路起点','FontWeight','bold')
text(4000,2000,z(6,11)+9,'村庄','FontWeight','bold')
text(2000,4000,z(11,6)+9,'矿山','FontWeight','bold')
title('山区概貌图','FontSize',16,'FontWeight','bold')
hold off

subplot(2,3,2)
%无填充的二维等高线图
contour(X,Y,z,30)
hold on
plot(0,800,'rp','markersize',16,'markerfacecolor','r')
plot(4000,2000,'yp','markersize',16,'markerfacecolor','y')
plot(2000,4000,'bp','markersize',16,'markerfacecolor','b')
text(0,800,'公路起点','FontWeight','bold')
text(4000,2000,'村庄','FontWeight','bold')
text(2000,4000,'矿山','FontWeight','bold')
title('山区等高线图','FontSize',16,'FontWeight','bold')
hold off

subplot(2,3,5)
%填充的二维等高线图
contourf(X,Y,z,30)
hold on
plot(0,800,'rp','markersize',16,'markerfacecolor','r')
plot(4000,2000,'yp','markersize',16,'markerfacecolor','y')
plot(2000,4000,'bp','markersize',16,'markerfacecolor','b')
text(0,800,'公路起点','FontWeight','bold')
text(4000,2000,'村庄','FontWeight','bold')
text(2000,4000,'矿山','FontWeight','bold')
title('山区等高线图','FontSize',16,'FontWeight','bold')
hold off

subplot(2,3,3)
%无填充的三维等高线图
contour3(X,Y,z,60)
hold on
plot3(0,800,z(3,1),'rp','markersize',16,'markerfacecolor','r')
plot3(4000,2000,z(6,11),'yp','markersize',16,'markerfacecolor','y')
plot3(2000,4000,z(11,6),'bp','markersize',16,'markerfacecolor','b')
text(0,800,z(3,1)+9,'公路起点','FontWeight','bold')%为防止文字被三维图遮盖，将z轴+9
text(4000,2000,z(6,11)+9,'村庄','FontWeight','bold')
text(2000,4000,z(11,6)+9,'矿山','FontWeight','bold')
title('山区等高线图','FontSize',16,'FontWeight','bold')
hold off