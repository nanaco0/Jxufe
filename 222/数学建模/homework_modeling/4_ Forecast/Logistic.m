function y=Logistic(b,t)
%prompt = 'Please input date about population :  \n';
%n = input(prompt);
%prompt = 'Please input date about time :  \n';
%t = input(prompt);

global y0;
%b(1):人口固有增长率
%b(2):人口最大载量
%9074:人口初始值
y=b(2)./(1+(b(2)/9074-1)*exp(-b(1)*t));
