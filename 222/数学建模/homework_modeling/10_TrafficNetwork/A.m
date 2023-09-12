[sum,txt]=xlsread('D:\Term\MathematicalModeling\homework_modeling\10_TrafficNetwork\2011B_交巡警服务平台的设置与调度\cumcm2011B附件2_全市六区交通网路和平台设置的数据表.xls',1,'B2:D583');
[r,c]=size(sum)
for i=1:r
    if char(txt(i,1))=='A'
        scatter(sum(i,1),sum(i,2),'b.')
        hold on;
    end 
end       

hold on;
[roads]=xlsread('D:\Term\MathematicalModeling\homework_modeling\10_TrafficNetwork\2011B_交巡警服务平台的设置与调度\cumcm2011B附件2_全市六区交通网路和平台设置的数据表.xls',2,'A2:B929');
[r,c]=size(roads);
for i=1:r
    start=roads(i,1) 
    last=roads(i,2)
    if char(txt(start,1)) == char(txt(last,1)) && char(txt(start,1))=='A'
        line([sum(start,1),sum(last,1)],[sum(start,2),sum(last,2)],'Color','b');
        hold on;
    end
end

[platform]=xlsread('D:\Term\MathematicalModeling\homework_modeling\10_TrafficNetwork\2011B_交巡警服务平台的设置与调度\cumcm2011B附件2_全市六区交通网路和平台设置的数据表.xls',3,'B2:B81');

for i=1:20
    index = platform(i,1)
    plot(sum(index,1),sum(index,2),'ro');
    
end


[crossing]=xlsread('D:\Term\MathematicalModeling\homework_modeling\10_TrafficNetwork\2011B_交巡警服务平台的设置与调度\cumcm2011B附件2_全市六区交通网路和平台设置的数据表.xls',4,'B2:C18');
[r,c]=size(crossing);
for i=1:r
    for j=1:c
       index = crossing(i,j); 
       if isnan(index) || char(txt(index,1))~='A'
           continue;
       end
       plot(sum(index,1),sum(index,2),'r*'); 
       hold on;
    end
end

text(350,350,'A','FontSize',15,'FontName','Times New Roman')
hold on;

plot(sum(32,1),sum(32,2),'k^')
text(330,350,'P','FontSize',12,'FontName','Times New Roman')
hold on;

title('A区交通网络图与平台设置示意图')

