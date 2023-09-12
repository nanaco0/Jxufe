function forecast

%读取excel'china_provincedata'中工作表2的A14-D42之间的内容，即湖北省2020年2月的数据
hubei = xlsread ('china_provincedata' , 2 , 'A14:D42' );    %2月共29天 sheet2保存了湖北省的数据
ConfirmedIncrease = hubei(:,1); %新增确诊
ConfirmedCount = hubei(:,2);    %累计确诊
CuredCount = hubei(:,3);            %累计治愈
DeadCount = hubei(:,4);             %累计死亡

figure('name' , '湖北省2020年2月疫情数据统计折线图')
hold on;
plot (ConfirmedIncrease , 'b*-' );
plot (ConfirmedCount , 'r*-' );
plot (CuredCount , 'g*-' );
plot (DeadCount , 'c*-' );
title('湖北省2020年2月疫情数据统计折线图','FontSize',16,'FontWeight','bold');    %加标题
hold off;

days = [1:29]'; %本例统计湖北省2020年2月的数据，2月共29天
beta = nlinfit(days , ConfirmedCount , 'Logistic' , [0.3 , 60000]) ;

%预测70天的累计确诊人数走向：
hold on ;
days2 = [1:70]';
population= Logistic (beta , days2);
plot(days2 , population , 'm*-');
legend('新增确诊' , '累计确诊' , '累计治愈' , '累计死亡' , '预测确诊');    %加图例
yticks([0 10000 20000 30000 40000 50000 60000 70000]);
yticklabels({'0','10000','20000','30000','40000','50000','60000','70000'});
title('预测70天的累计确诊人数走向','FontSize',16,'FontWeight','bold');    %加标题
hold off;