package Test1;

/**
Rectangle������,�̳г�����Shape
����Ĺ���������ͨ�������������
�������ʱδ������󷽷�
*/
public abstract class Rectangle extends Shape{
	private double width;//���εĿ��
	private double height;//���εĸ߶�
	public Rectangle() {
		super() ;
	}
	public Rectangle (String realType) {
		super (realType) ;
	}
	public Rectangle (double width, double height, String realType) {
		this (realType);//���ô�- -��String���Ͳ����Ĺ�����,�����Rectangle (String realType)
		this. width = width;
		this. height = height;
	}
	//��д����Shape���toString()����
	@Override
	public String toString() {
		return super. toString() +"���:"+ this. width +";�߶�:"+ this. height + "\n";
	}
	//ʵ��Shape�еĳ��󷽷�getArea,��øþ��ε����
	@Override
	public double getArea() {
		return this.width * this. height;
	}
	//ʵ��Shape�еĳ��󷽷�getPer imeter,��øþ��ε��ܳ�
	@Override
	public double getPerimeter() {
		return (this. width + this. height) * 2;
	}
	//����Ϊgetter��setter
	public double getWidth() {
		return this. width;
	}
	public void setWidth(double w) {
		this. width= w;
	}
	public double getHeight() {
		return this. height;
	}
	public void setHeight (double h) {
		this. height = h;
	}

}
