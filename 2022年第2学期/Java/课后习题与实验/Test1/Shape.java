package Test1;

public abstract class Shape {
	private String realType = "未知";//这个图形真正的实物类型，如面板、电扇、空调等等↓
	public Shape() {
		super() ;
	}
	public Shape (String realType) {
		this() ;//调用无参构造器↓
		this. realType = realType;
	}
	//重写父类0bject类的toString()方法↓
	@Override //这是一个注解，表示下面的toString方法是父类已有的，这里重写↓
	public String toString() {
		return "类型: " + this. realType + "\n" ;
	}
	public String getRealType() {
		return this. realType;
	}
	//setter:设置该图形的实物类型;但由于实物类型在创建实物时就确定了，故不能修改类型↓
	/*public String setRealType (String realType) {↓
	this. realType = realType;↓
	}*/
	public abstract double getArea(); //求图形面积↓
	//定义了两个抽象方法，抽象方法
	public abstract double getPerimeter ();//求图形周长↓在 子类中实现
}
