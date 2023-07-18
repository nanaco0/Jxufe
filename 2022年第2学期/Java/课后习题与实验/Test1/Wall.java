package Test1;

/**Wall: ǽ��,һ-�����4��ǽ,ÿ��ǽ�����кڰ塢���ȴ�����������*/
import java. util. ArrayList;
public class Wall extends Rectangle{
	private Board board = null;//ǽ �ϵĺڰ�,Ĭ��û��
	private ArrayList<Window> windowList = new ArrayList<>(); //ǽ�ϵĴ���
	private ArrayList<Panel> panelList = new ArrayList<>();//ǽ �ϵ����(-һ���������һ������Switch)
	public Wall() {
		super("ǽ");
	}
	public Wall (double width, double height) {
		super (width,height, "ǽ");
	}
	//��д����Rectangle���toString()����.
	@Override
	public String toString() {
		StringBuffer sb = new StringBuffer() ;					//�����õ�StringBuffer,�Ǹ��ɱ��ַ���
		int iWindow = 0,iPanel = 0;								//���崰����ź��������
		for (Window window : windowList) {						//��foreachѭ�����������б�,����б�Ϊ��,����ִ��append
			sb. append("��"+ ++iWindow +"�ȴ�������Ϣ: \n"+ window) ;	//ͨ��append������StringBuffer׷���ַ���
		}
		for (Panel panel : panelList) {							//��foreachѭ����������б�,����б�Ϊ��,����ִ��append
			sb. append("��"+ ++iPanel +"��������Ϣ: \n" + panel);
		}
		if(this. board != null) {//�ж��Ƿ��кڰ�,�еĻ���append
			sb. append (board) ;
			//���ø����toString������StringBufferת��ΪString
		}
		return super. toString() + sb. toString();
	}
	public ArrayList<Window> getWindowList() {
		return this. windowList;
	}
	//��װ����
	public void setWindowList (ArrayList<Window> windowList) {
	for (Window window : windowList) {
	this. windowList. add (window) ;
	}
	}
	public ArrayList<Panel> getPanelList() {
		return this. panelList;
	}
	//��װ���
	public void setPanelList (ArrayList<Panel> panelList) {
		for(Panel panel : panelList) {
			this. panelList. add (panel) ;
		}
	}
	public Board getBoard() {
		return this. board;
	}
	//��װ�ڰ�
	public void setBoard (Board board) {
		this. board = board;
	}
}
