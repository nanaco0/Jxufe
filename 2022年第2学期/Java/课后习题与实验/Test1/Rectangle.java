package Test1;

/**
Rectangle抽象类,继承抽象类Shape
该类的构造器和普通方法供子类调用
该类的暂时未定义抽象方法
*/
public abstract class Rectangle extends Shape{
	private double width;//矩形的宽度
	private double height;//矩形的高度
	public Rectangle() {
		super() ;
	}
	public Rectangle (String realType) {
		super (realType) ;
	}
	public Rectangle (double width, double height, String realType) {
		this (realType);//调用带- -个String类型参数的构造器,即这个Rectangle (String realType)
		this. width = width;
		this. height = height;
	}
	//重写父类Shape类的toString()方法
	@Override
	public String toString() {
		return super. toString() +"宽度:"+ this. width +";高度:"+ this. height + "\n";
	}
	//实现Shape中的抽象方法getArea,获得该矩形的面积
	@Override
	public double getArea() {
		return this.width * this. height;
	}
	//实现Shape中的抽象方法getPer imeter,获得该矩形的周长
	@Override
	public double getPerimeter() {
		return (this. width + this. height) * 2;
	}
	//以下为getter和setter
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
