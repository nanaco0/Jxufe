package Test1;

/**Wall: 墙类,一-间教室4方墙,每方墙可能有黑板、多扇窗户、多个面板*/
import java. util. ArrayList;
public class Wall extends Rectangle{
	private Board board = null;//墙 上的黑板,默认没有
	private ArrayList<Window> windowList = new ArrayList<>(); //墙上的窗户
	private ArrayList<Panel> panelList = new ArrayList<>();//墙 上的面板(-一个面板上有一个开关Switch)
	public Wall() {
		super("墙");
	}
	public Wall (double width, double height) {
		super (width,height, "墙");
	}
	//重写父类Rectangle类的toString()方法.
	@Override
	public String toString() {
		StringBuffer sb = new StringBuffer() ;					//这里用到StringBuffer,是个可变字符串
		int iWindow = 0,iPanel = 0;								//定义窗户序号和面板的序号
		for (Window window : windowList) {						//用foreach循环遍历窗户列表,如果列表为空,不会执行append
			sb. append("第"+ ++iWindow +"扇窗户的信息: \n"+ window) ;	//通过append方法向StringBuffer追加字符串
		}
		for (Panel panel : panelList) {							//用foreach循环遍历面板列表,如果列表为空,不会执行append
			sb. append("第"+ ++iPanel +"个面板的信息: \n" + panel);
		}
		if(this. board != null) {//判断是否有黑板,有的话就append
			sb. append (board) ;
			//调用父类的toString方法将StringBuffer转换为String
		}
		return super. toString() + sb. toString();
	}
	public ArrayList<Window> getWindowList() {
		return this. windowList;
	}
	//安装窗户
	public void setWindowList (ArrayList<Window> windowList) {
	for (Window window : windowList) {
	this. windowList. add (window) ;
	}
	}
	public ArrayList<Panel> getPanelList() {
		return this. panelList;
	}
	//安装面板
	public void setPanelList (ArrayList<Panel> panelList) {
		for(Panel panel : panelList) {
			this. panelList. add (panel) ;
		}
	}
	public Board getBoard() {
		return this. board;
	}
	//安装黑板
	public void setBoard (Board board) {
		this. board = board;
	}
}
