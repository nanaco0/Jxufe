package Test1;

//Board: 黑板类,定义了成员变量color,表示黑板的颜色
public class Board extends Rectangle{
	private String color ="黑色";//黑板默认是黑色
	
	public Board() {
		super("黑板");
	}
	public Board(double width,double height) {
		super (width,height, " 黑板");
	}
	public Board(double width,double height, String color) {
		this (width,height) ;
		this. color = color; 
	}
	//重写父类Rectangle类的toString()方法
	@Override
	public String toString() {
		return super. toString() +"颜色:"+ this. color +"\n";
	}
	public String getColor() {
		return this. color;
	}
	public void setColor (String color) {
		this. color = color;
	}
}
