package Test1;

public abstract class Circle extends Shape {
	private double radius; //圆形的半径
	
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
	//重写父类Shape类的toString()方法
	@Override
	public String toString() {
		return super. toString() +"半径:"+ this. radius + "\n";
	}
	//实现Shape中的getArea方法,获得该圆形的面积
	@Override
	public double getArea() {
		return Math. PI * radius * radius;
	}
	//实现Shape中的getPerimeter方法,获得该圆形的周长
	@Override
	public double getPerimeter() {
		return 2 * Math. PI * radius;
	}
	//以下为getter和setter
	public double getRadius() {
		return this. radius;
	}
	public void setRadius (double radius) {
		this. radius = radius;
	}
}
