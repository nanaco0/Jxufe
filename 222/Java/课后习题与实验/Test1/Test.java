package Test1;

import java.util.ArrayList;
public class Test {
	public static void main(String[] args) {
		//ǰ���ǽ:��װ��һ��ڰ�
		Wall frontWall = new Wall(10,3.6);
		Board board = new Board(4, 2,"��ɫ");
		frontWall.setBoard (board);//ǰǽ��װһ��ڰ�
		//------ǰǽ��������,�����ָ���-------
		//�����ǽ:��ʱͶ��װ�κζ���
		Wall backWall = new Wall(10,3.6);//ǰǽ�ͺ�ǽ���һ��
		//------��ǽ��������,�����ָ���-
		//��ǽ:��װ�����鴰��,ÿ�鴰����װ�д���
		Wall leftWall = new Wall(12,3.6); //��ǽ�߶Ⱥ�ǰǽ��ͬ.
		//�����б�
		ArrayList <Window> leftWindowList = new ArrayList<> ();
		//��һ�鴰��
		Window window1 = new Window(1,3,"����");
		//����һ�鴰����װ����
		window1. setCurtain (new Curtain(1.3,3.2, " ��ɫ����"));
		//�ڶ��鴰��
		Window window2 = new Window(1,3,"����"); 
		//���ڶ��鴰����װ����
		window2. setCurtain (new Curtain(1.3,3.2, " ��ɫ����"));
		//�����鴰��
		Window window3 = new Window(1,3,"����"); 
		//�������鴰����װ����
		window3. setCurtain (new Curtain(1.3,3.2, " ��ɫ����"));
		//�������鴰�����ӵ������б�
		leftWindowList. add (window1);
		leftWindowList. add (window2);
		leftWindowList. add (window3);
		//����������б�װ����ǽ��
		leftWall. setWindowList (leftWindowList) ;
		//------��ǽ��������,�����ָ���-------
		//��ǽ:û�д���,���кܶ����(���п���)
		Wall rightWall = new Wall(12, 3.6);
		ArrayList<Panel> panelList = new ArrayList<>();
		ArrayList<Shape> shapeList = new ArrayList<> ();
		ArrayList<Fan> fanList = new ArrayList<>();
		ArrayList<Lights> lightsList = new ArrayList<>();
		Panel panel = null;//�������
		Switch aSwitch = null;//��������ϵĿ���
		//����6�����,������6������
		Fan fan = null;
		for(int i=0;i<6;i++){
			panel = new Panel(0.4, 0.4);
			fan = new Fan(1.5, 5);
			aSwitch = fan;//������ؿ��Ƶ���һ������
			panel. setSwitch (aSwitch);
			panelList. add (panel);
			fanList. add (fan);
			shapeList. add (fan);
		}
		//����12�����,������12յ��
		Lights lights = null;
		for(int i=0;i<12;i++){
			panel = new Panel(0.3,0.3);
			lights = new Lights(0.8, 0.6, 15, "�չ��");
			aSwitch = lights;//�� �����ؿ��Ƶ���һյ��
			panel.setSwitch (aSwitch);
			panelList. add (panel) ;
			lightsList. add(lights);
			shapeList. add (lights);
		}
		rightWall.setPanelList (panelList);
		//-------------��ǽ��������,�����ָ���-
		//��������ǽ��ArrayList
		ArrayList<Wall> wallList = new ArrayList<>();
		wallList.add(frontWall);
		wallList.add(backWall);
		wallList.add(leftWall);
		wallList.add(rightWall);
		//����һ������
		Classroom classroom = new Classroom();
		classroom.setWallList(wallList);
		//�ѽ��ҵ���Ϣ���
		ArrayList <Wall> classWallList = classroom. getWallList();
		int iWall = 0;
		for (Wall wall : classWallList) {
			//���ǽ����Ϣ
			System. out. println("---------��"+ ++iWall +"��ǽ����Ϣ��ʼ���---------");
			System. out. print(wall);
			System. out. println("---------��"+ iWall + "��ǽ����Ϣ��ӡ����---------\n");
		}
		double sumFanArea= 0; //���� ���ȵ����֮��
		double sumLightsArea = 0; //���� ��Ƶ����֮��
		double sumShapeArea = 0; //������ʩ�����֮��
		//�������еĵ������֮��
		for(Fan aFan : fanList) {
			sumFanArea += aFan. getArea();
		}
		System. out. println("���������: " + sumFanArea);
		//�������еĵ�����֮��
		for(Lights aLights : lightsList) {
			sumLightsArea += aLights. getArea();
		}
		System. out. println("��������:" + sumLightsArea);
		//�������еĵ������֮��
		for (Shape shape : shapeList) {
			sumShapeArea += shape. getArea();
		}
		System. out. println("�����豸�����:"+ sumShapeArea) ;
	}
}
