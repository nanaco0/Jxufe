package Test1;

public abstract class Circle extends Shape {
	private double radius; //Բ�εİ뾶
	
	public Circle() {
		super () ;
	}
	public Circle (String realType) {
		super (realType);
	}
	public Circle (double radius, String realType) {
		this (realType);
		this. radius = radius;
	}
	//��д����Shape���toString()����
	@Override
	public String toString() {
		return super. toString() +"�뾶:"+ this. radius + "\n";
	}
	//ʵ��Shape�е�getArea����,��ø�Բ�ε����
	@Override
	public double getArea() {
		return Math. PI * radius * radius;
	}
	//ʵ��Shape�е�getPerimeter����,��ø�Բ�ε��ܳ�
	@Override
	public double getPerimeter() {
		return 2 * Math. PI * radius;
	}
	//����Ϊgetter��setter
	public double getRadius() {
		return this. radius;
	}
	public void setRadius (double radius) {
		this. radius = radius;
	}
}
