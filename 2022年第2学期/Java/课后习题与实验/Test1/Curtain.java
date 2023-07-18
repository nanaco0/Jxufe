package Test1;

/**Curtain:窗帘类,有一个成员变量style表示窗帘的样式*/
public class Curtain extends Rectangle {
	private String style ="未知";
	
	public Curtain() {
		super("窗帘");
	}
	public Curtain (double width,double height) {
		super (width,height, "窗帘");
	}
	public Curtain (double width, double height, String style) {
		this (width,height) ;
		this. style = style;
	}
	//重写父类Rectangle类的toString()方法
	@Override
	public String toString() {
		return super. toString() + "风格:"+ this. style + "\n";
	}
	
	public String getStyle() {
		return this. style;
	}
	public void setStyle (String style) {
		this. style = style; 
	}
}
