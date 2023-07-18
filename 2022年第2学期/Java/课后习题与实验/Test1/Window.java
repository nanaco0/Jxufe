package Test1;

//Window:窗户类,包括材质字段material和窗帘curtain
public class Window extends Rectangle {
	private String material = "玻璃";
	private Curtain curtain = null;
	public Window() {
		super("窗户");
	}
	public Window(double width, double height) {
		super (width,height, " 窗户");
	}
	public Window(double width, double height,String material) {
		this (width,height) ;
		this. material = material;
	}
	//重写父类Rectangle类的toString()方法
	@Override
	public String toString() {
		String curtainInfo =
		this. curtain == null ?"没有安装窗帘":"安装的窗帘如下: \n"+ this. curtain;
		return super. toString() +"材质:"+ this. material + "\n"+ curtainInfo;
	}
	public Curtain getCurtain() {
		return this. curtain;
	}
	//给窗户安装窗帘
	public void setCurtain (Curtain curtain) {
		this. curtain = curtain; 
	}
	public String getMaterial() {
		return this. material;
	}
	public void setMaterial (String material) {
		this. material = material;
	}
}
