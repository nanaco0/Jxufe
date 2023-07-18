function forecast

%��ȡexcel'china_provincedata'�й�����2��A14-D42֮������ݣ�������ʡ2020��2�µ�����
hubei = xlsread ('china_provincedata' , 2 , 'A14:D42' );    %2�¹�29�� sheet2�����˺���ʡ������
ConfirmedIncrease = hubei(:,1); %����ȷ��
ConfirmedCount = hubei(:,2);    %�ۼ�ȷ��
CuredCount = hubei(:,3);            %�ۼ�����
DeadCount = hubei(:,4);             %�ۼ�����

figure('name' , '����ʡ2020��2����������ͳ������ͼ')
hold on;
plot (ConfirmedIncrease , 'b*-' );
plot (ConfirmedCount , 'r*-' );
plot (CuredCount , 'g*-' );
plot (DeadCount , 'c*-' );
title('����ʡ2020��2����������ͳ������ͼ','FontSize',16,'FontWeight','bold');    %�ӱ���
hold off;

days = [1:29]'; %����ͳ�ƺ���ʡ2020��2�µ����ݣ�2�¹�29��
beta = nlinfit(days , ConfirmedCount , 'Logistic' , [0.3 , 60000]) ;

%Ԥ��70����ۼ�ȷ����������
hold on ;
days2 = [1:70]';
population= Logistic (beta , days2);
plot(days2 , population , 'm*-');
legend('����ȷ��' , '�ۼ�ȷ��' , '�ۼ�����' , '�ۼ�����' , 'Ԥ��ȷ��');    %��ͼ��
yticks([0 10000 20000 30000 40000 50000 60000 70000]);
yticklabels({'0','10000','20000','30000','40000','50000','60000','70000'});
title('Ԥ��70����ۼ�ȷ����������','FontSize',16,'FontWeight','bold');    %�ӱ���
hold off;