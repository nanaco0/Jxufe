package Test1;

/**Curtain:������,��һ����Ա����style��ʾ��������ʽ*/
public class Curtain extends Rectangle {
	private String style ="δ֪";
	
	public Curtain() {
		super("����");
	}
	public Curtain (double width,double height) {
		super (width,height, "����");
	}
	public Curtain (double width, double height, String style) {
		this (width,height) ;
		this. style = style;
	}
	//��д����Rectangle���toString()����
	@Override
	public String toString() {
		return super. toString() + "���:"+ this. style + "\n";
	}
	
	public String getStyle() {
		return this. style;
	}
	public void setStyle (String style) {
		this. style = style; 
	}
}
