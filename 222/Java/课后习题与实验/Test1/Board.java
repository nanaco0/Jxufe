package Test1;

//Board: �ڰ���,�����˳�Ա����color,��ʾ�ڰ����ɫ
public class Board extends Rectangle{
	private String color ="��ɫ";//�ڰ�Ĭ���Ǻ�ɫ
	
	public Board() {
		super("�ڰ�");
	}
	public Board(double width,double height) {
		super (width,height, " �ڰ�");
	}
	public Board(double width,double height, String color) {
		this (width,height) ;
		this. color = color; 
	}
	//��д����Rectangle���toString()����
	@Override
	public String toString() {
		return super. toString() +"��ɫ:"+ this. color +"\n";
	}
	public String getColor() {
		return this. color;
	}
	public void setColor (String color) {
		this. color = color;
	}
}
