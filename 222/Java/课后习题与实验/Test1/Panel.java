package Test1;

/**Panel:面板类,继承Rectangle类,表示面板是矩形
面板.上要安装- -个开关Switch,面板通过开关控制电扇或电灯的开和关
*/
public class Panel extends Rectangle{
	private Switch aSwitch = null;//面板上的开关
	public Panel(){
		super("面板");
	}
	public Panel (double width, double height) {
		super (width, height, " 面板");
	}
	
	//重写父类Rectangle类的toString()方法
	@Override
	public String toString() {
		String panelInfo = this. aSwitch==null ? " 没有控制任何设施":" 控制的设施是: \n"+ this. aSwitch;
		return super. toString() + panelInfo;
	}
	//在面板上使用open方法调用面板上的开关进行open(打开电灯或吊扇等)操作
	public void open() {
		if(aSwitch != null){
			this. aSwitch. open();
		}
		else{
			System. out. println("该面板没有连接控制的设施");
		}
	}
	//在面板上使用open方法调用面板上的开关进行close (关闭电灯或吊扇等)操作
	public void close() {
		if(aSwitch != null){
			this. aSwitch. close();
		}
		else{
			System. out. println("该面板没有连接控制的设施");
		}
	}
	public Switch getSwitch() {
		return this. aSwitch;
	}
	//在面板.上安装开关(开关是个接口,事实.上Swi tch变量aSwi tch是接口Swi tch的实现类,如F an或Lights等)
	public void setSwitch(Switch aSwitch) {
		this. aSwitch = aSwitch;
	}
}
