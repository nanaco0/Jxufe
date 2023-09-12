package Test1;

/**Panel:�����,�̳�Rectangle��,��ʾ����Ǿ���
���.��Ҫ��װ- -������Switch,���ͨ�����ؿ��Ƶ��Ȼ��ƵĿ��͹�
*/
public class Panel extends Rectangle{
	private Switch aSwitch = null;//����ϵĿ���
	public Panel(){
		super("���");
	}
	public Panel (double width, double height) {
		super (width, height, " ���");
	}
	
	//��д����Rectangle���toString()����
	@Override
	public String toString() {
		String panelInfo = this. aSwitch==null ? " û�п����κ���ʩ":" ���Ƶ���ʩ��: \n"+ this. aSwitch;
		return super. toString() + panelInfo;
	}
	//�������ʹ��open������������ϵĿ��ؽ���open(�򿪵�ƻ���ȵ�)����
	public void open() {
		if(aSwitch != null){
			this. aSwitch. open();
		}
		else{
			System. out. println("�����û�����ӿ��Ƶ���ʩ");
		}
	}
	//�������ʹ��open������������ϵĿ��ؽ���close (�رյ�ƻ���ȵ�)����
	public void close() {
		if(aSwitch != null){
			this. aSwitch. close();
		}
		else{
			System. out. println("�����û�����ӿ��Ƶ���ʩ");
		}
	}
	public Switch getSwitch() {
		return this. aSwitch;
	}
	//�����.�ϰ�װ����(�����Ǹ��ӿ�,��ʵ.��Swi tch����aSwi tch�ǽӿ�Swi tch��ʵ����,��F an��Lights��)
	public void setSwitch(Switch aSwitch) {
		this. aSwitch = aSwitch;
	}
}
