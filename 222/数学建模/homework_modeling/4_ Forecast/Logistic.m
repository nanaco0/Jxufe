function y=Logistic(b,t)
%prompt = 'Please input date about population :  \n';
%n = input(prompt);
%prompt = 'Please input date about time :  \n';
%t = input(prompt);

global y0;
%b(1):�˿ڹ���������
%b(2):�˿��������
%9074:�˿ڳ�ʼֵ
y=b(2)./(1+(b(2)/9074-1)*exp(-b(1)*t));
