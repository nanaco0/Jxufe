package Test1;

public class Lights extends Rectangle implements Switch{
	private int power;//���ݹ���
	private String type;//��������,���չ�ơ��׳�ơ����ܵ�
	public Lights() {
		super("���");
	}
	public Lights (double width, double height) {
		super (width, height, "���");
	}
	public Lights (double width, double height,int power) {
		this (width, height);
		this. power = power;
	}
	public Lights(double width, double height, String type) {
		this (width, height);
		this. type = type;
	}
	public Lights(double width, double height,int power, String type) {
		this (width, height, power);
		this. type = type;
	}
	//��д����Rect angle���t oString ()����
	@Override
	public String toString() {
		return super. toString() +"����:"+ this.power +";����:"+ this. type +"\n";
	}
	//ʵ��Swit ch�ӿڵ�open����
	public void open() {
		System. out. println("�����......");
	}
	//ʵ��Switch�ӿڵ�close����
	public void close() {
		System. out. println("�������......");
	}
	public int getPower() {
		return this. power;
	}
	public void setPower (int power) {
		this. power = power;
	}
	public String getType() {
		return this. type;
	}
	public void setType (String type) {
		this. type = type;
	}
}
