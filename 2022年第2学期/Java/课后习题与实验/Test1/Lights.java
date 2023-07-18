package Test1;

public class Lights extends Rectangle implements Switch{
	private int power;//灯泡功率
	private String type;//灯泡类型,如日光灯、白炽灯、节能灯
	public Lights() {
		super("电灯");
	}
	public Lights (double width, double height) {
		super (width, height, "电灯");
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
	//重写父类Rect angle类的t oString ()方法
	@Override
	public String toString() {
		return super. toString() +"功率:"+ this.power +";类型:"+ this. type +"\n";
	}
	//实现Swit ch接口的open方法
	public void open() {
		System. out. println("电灯了......");
	}
	//实现Switch接口的close方法
	public void close() {
		System. out. println("电灯灭了......");
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
