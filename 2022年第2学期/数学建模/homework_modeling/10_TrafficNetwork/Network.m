[sum,txt]=xlsread('D:\Term\MathematicalModeling\homework_modeling\10_TrafficNetwork\2011B_交巡警服务平台的设置与调度\cumcm2011B附件2_全市六区交通网路和平台设置的数据表.xls',1,'B2:D583');
[r,c]=size(sum)
for i=1:r
    if char(txt(i,1))=='A'
        scatter(sum(i,1),sum(i,2),'g.')
        hold on;
    elseif char(txt(i,1))=='B'
        scatter(sum(i,1),sum(i,2),'g.')
        hold on;
    elseif char(txt(i,1))=='C'
        scatter(sum(i,1),sum(i,2),'b.')
        hold on;
    elseif char(txt(i,1))=='D'
        scatter(sum(i,1),sum(i,2),'k.')
        hold on;
    elseif char(txt(i,1))=='E'
        scatter(sum(i,1),sum(i,2),'b.')
        hold on;
    elseif char(txt(i,1))=='F'
        scatter(sum(i,1),sum(i,2),'k.')
        hold on;
    end 
end       
%scatter(sum(:,1),sum(:,2),'b.')
hold on;
[roads]=xlsread('D:\Term\MathematicalModeling\homework_modeling\10_TrafficNetwork\2011B_交巡警服务平台的设置与调度\cumcm2011B附件2_全市六区交通网路和平台设置的数据表.xls',2,'A2:B929');
[r,c]=size(roads);
for i=1:r
    start=roads(i,1)
    last=roads(i,2)
    if char(txt(start,1)) == char(txt(last,1)) && char(txt(start,1))=='A'
        line([sum(start,1),sum(last,1)],[sum(start,2),sum(last,2)],'Color','g');
        hold on;
    elseif char(txt(start,1)) == char(txt(last,1)) && char(txt(start,1))=='B'
        line([sum(start,1),sum(last,1)],[sum(start,2),sum(last,2)],'Color','g');
        hold on;
    elseif char(txt(start,1)) == char(txt(last,1)) && char(txt(start,1))=='C'
        line([sum(start,1),sum(last,1)],[sum(start,2),sum(last,2)],'Color','b');
        hold on;
    elseif char(txt(start,1)) == char(txt(last,1)) && char(txt(start,1))=='D'
        line([sum(start,1),sum(last,1)],[sum(start,2),sum(last,2)],'Color','k');
        hold on;
    elseif char(txt(start,1)) == char(txt(last,1)) && char(txt(start,1))=='E'
        line([sum(start,1),sum(last,1)],[sum(start,2),sum(last,2)],'Color','b');
        hold on;
    elseif char(txt(start,1)) == char(txt(last,1)) && char(txt(start,1))=='F'
        line([sum(start,1),sum(last,1)],[sum(start,2),sum(last,2)],'Color','k');
        hold on;
    else
        line([sum(start,1),sum(last,1)],[sum(start,2),sum(last,2)],'Color','r');
        hold on;
    end
end

[platform]=xlsread('D:\Term\MathematicalModeling\homework_modeling\10_TrafficNetwork\2011B_交巡警服务平台的设置与调度\cumcm2011B附件2_全市六区交通网路和平台设置的数据表.xls',3,'B2:B81');
[n]=size(platform)
for i=1:n
    index = platform(i,1)
    plot(sum(index,1),sum(index,2),'ro');
    
end


[crossing]=xlsread('D:\Term\MathematicalModeling\homework_modeling\10_TrafficNetwork\2011B_交巡警服务平台的设置与调度\cumcm2011B附件2_全市六区交通网路和平台设置的数据表.xls',4,'B2:C18');
[r,c]=size(crossing);
for i=1:r
    for j=1:c
       if isnan(crossing(i,j))
           continue;
       end
       index = crossing(i,j); 
       plot(sum(index,1),sum(index,2),'r*'); 
       hold on;
    end
end

text(350,350,'A','FontSize',15,'FontName','Times New Roman')
text(140,90,'B','FontSize',15,'FontName','Times New Roman')
text(240,400,'C','FontSize',15,'FontName','Times New Roman')
text(50,340,'D','FontSize',15,'FontName','Times New Roman')
text(150,220,'E','FontSize',15,'FontName','Times New Roman')
text(370,180,'F','FontSize',15,'FontName','Times New Roman')
hold on;

plot(sum(32,1),sum(32,2),'k^')
text(330,350,'P','FontSize',10,'FontName','Times New Roman')
hold on;

title('全市六区交通网络图与平台设置示意图')

