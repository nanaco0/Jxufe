package Test1;

//Window:������,���������ֶ�material�ʹ���curtain
public class Window extends Rectangle {
	private String material = "����";
	private Curtain curtain = null;
	public Window() {
		super("����");
	}
	public Window(double width, double height) {
		super (width,height, " ����");
	}
	public Window(double width, double height,String material) {
		this (width,height) ;
		this. material = material;
	}
	//��д����Rectangle���toString()����
	@Override
	public String toString() {
		String curtainInfo =
		this. curtain == null ?"û�а�װ����":"��װ�Ĵ�������: \n"+ this. curtain;
		return super. toString() +"����:"+ this. material + "\n"+ curtainInfo;
	}
	public Curtain getCurtain() {
		return this. curtain;
	}
	//��������װ����
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
