package Test1;

public abstract class Shape {
	private String realType = "δ֪";//���ͼ��������ʵ�����ͣ�����塢���ȡ��յ��ȵȡ�
	public Shape() {
		super() ;
	}
	public Shape (String realType) {
		this() ;//�����޲ι�������
		this. realType = realType;
	}
	//��д����0bject���toString()������
	@Override //����һ��ע�⣬��ʾ�����toString�����Ǹ������еģ�������д��
	public String toString() {
		return "����: " + this. realType + "\n" ;
	}
	public String getRealType() {
		return this. realType;
	}
	//setter:���ø�ͼ�ε�ʵ������;������ʵ�������ڴ���ʵ��ʱ��ȷ���ˣ��ʲ����޸����͡�
	/*public String setRealType (String realType) {��
	this. realType = realType;��
	}*/
	public abstract double getArea(); //��ͼ�������
	//�������������󷽷������󷽷�
	public abstract double getPerimeter ();//��ͼ���ܳ����� ������ʵ��
}
