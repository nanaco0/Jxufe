package Test1;

/**Fan:������
1���̳�Circle,��Circle�̳���Shape��ͨ�������������󷽷�: getArea��getPeremter, 
���������󷽷�getArea��getPeremter�ڸ���Circle���Ѿ�ʵ����,����ֱ�Ӽ̳м���
2��ʵ��Switch�ӿ�,����ʵ�ָýӿڵ���������open��close,��ʾ���ȵĿ��͹�
*/
public class Fan extends Circle implements Switch {
	private int leafNum = 3;//��Ҷ��Ĭ��ֵ��3
	public Fan() {
		super("����");
	}
	public Fan(double radius) {
		super (radius,"����");
	}
	public Fan (double radius,int leafNum) {
		this (radius);
		this. leafNum = leafNum; 
	}
	//��д����Circle���toString ()����
	@Override
	public String toString() {
		return super. toString() +"��Ҷ��:"+ this. leafNum + "\n";
	}
	//ʵ��Switch�ӿڵ�open����
	public void open() {
		System. out. println("���ȿ�ʼת��......");
	}
	//ʵ��Switch�ӿڵ�close����
	public void close() {
		System. out. println("��������ͣ......");
	}
	public int getLeafNum() {
		return this. leafNum;
	}
	public void setLeafNum(int leafNum) {
		this. leafNum = leafNum;
	}
}
