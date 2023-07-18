package Test1;

/**Fan:吊扇类
1、继承Circle,而Circle继承了Shape普通方法和两个抽象方法: getArea和getPeremter, 
这两个抽象方法getArea和getPeremter在父类Circle中已经实现了,这里直接继承即可
2、实现Switch接口,必须实现该接口的两个方法open和close,表示吊扇的开和关
*/
public class Fan extends Circle implements Switch {
	private int leafNum = 3;//扇叶的默认值是3
	public Fan() {
		super("吊扇");
	}
	public Fan(double radius) {
		super (radius,"吊扇");
	}
	public Fan (double radius,int leafNum) {
		this (radius);
		this. leafNum = leafNum; 
	}
	//重写父类Circle类的toString ()方法
	@Override
	public String toString() {
		return super. toString() +"扇叶数:"+ this. leafNum + "\n";
	}
	//实现Switch接口的open方法
	public void open() {
		System. out. println("吊扇开始转了......");
	}
	//实现Switch接口的close方法
	public void close() {
		System. out. println("吊扇慢慢停......");
	}
	public int getLeafNum() {
		return this. leafNum;
	}
	public void setLeafNum(int leafNum) {
		this. leafNum = leafNum;
	}
}
