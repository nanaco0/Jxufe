package Test1;

import java.util.ArrayList;
public class Test {
	public static void main(String[] args) {
		//前面的墙:安装了一块黑板
		Wall frontWall = new Wall(10,3.6);
		Board board = new Board(4, 2,"黑色");
		frontWall.setBoard (board);//前墙安装一块黑板
		//------前墙创建结束,完美分割线-------
		//后面的墙:暂时投安装任何东西
		Wall backWall = new Wall(10,3.6);//前墙和后墙宽高一样
		//------后墙创建结束,完美分割线-
		//左墙:安装了三块窗户,每块窗户上装有窗帘
		Wall leftWall = new Wall(12,3.6); //左墙高度和前墙相同.
		//窗户列表
		ArrayList <Window> leftWindowList = new ArrayList<> ();
		//第一块窗户
		Window window1 = new Window(1,3,"玻璃");
		//给第一块窗户安装窗帘
		window1. setCurtain (new Curtain(1.3,3.2, " 黄色花纹"));
		//第二块窗户
		Window window2 = new Window(1,3,"玻璃"); 
		//给第二块窗户安装窗帘
		window2. setCurtain (new Curtain(1.3,3.2, " 黄色花纹"));
		//第三块窗户
		Window window3 = new Window(1,3,"玻璃"); 
		//给第三块窗户安装窗帘
		window3. setCurtain (new Curtain(1.3,3.2, " 黄色花纹"));
		//将这三块窗户增加到窗户列表
		leftWindowList. add (window1);
		leftWindowList. add (window2);
		leftWindowList. add (window3);
		//将这个窗户列表安装到左墙上
		leftWall. setWindowList (leftWindowList) ;
		//------左墙创建结束,完美分割线-------
		//右墙:没有窗户,但有很多面板(上有开关)
		Wall rightWall = new Wall(12, 3.6);
		ArrayList<Panel> panelList = new ArrayList<>();
		ArrayList<Shape> shapeList = new ArrayList<> ();
		ArrayList<Fan> fanList = new ArrayList<>();
		ArrayList<Lights> lightsList = new ArrayList<>();
		Panel panel = null;//定义面板
		Switch aSwitch = null;//定义面板上的开关
		//创建6个面板,来控制6个吊扇
		Fan fan = null;
		for(int i=0;i<6;i++){
			panel = new Panel(0.4, 0.4);
			fan = new Fan(1.5, 5);
			aSwitch = fan;//这个开关控制的是一个吊扇
			panel. setSwitch (aSwitch);
			panelList. add (panel);
			fanList. add (fan);
			shapeList. add (fan);
		}
		//创建12个面板,来控制12盏灯
		Lights lights = null;
		for(int i=0;i<12;i++){
			panel = new Panel(0.3,0.3);
			lights = new Lights(0.8, 0.6, 15, "日光灯");
			aSwitch = lights;//这 个开关控制的是一盏灯
			panel.setSwitch (aSwitch);
			panelList. add (panel) ;
			lightsList. add(lights);
			shapeList. add (lights);
		}
		rightWall.setPanelList (panelList);
		//-------------右墙创建结束,完美分割线-
		//创建四面墙的ArrayList
		ArrayList<Wall> wallList = new ArrayList<>();
		wallList.add(frontWall);
		wallList.add(backWall);
		wallList.add(leftWall);
		wallList.add(rightWall);
		//创建一个教室
		Classroom classroom = new Classroom();
		classroom.setWallList(wallList);
		//把教室的信息输出
		ArrayList <Wall> classWallList = classroom. getWallList();
		int iWall = 0;
		for (Wall wall : classWallList) {
			//输出墙的信息
			System. out. println("---------第"+ ++iWall +"面墙的信息开始输出---------");
			System. out. print(wall);
			System. out. println("---------第"+ iWall + "面墙的信息打印结束---------\n");
		}
		double sumFanArea= 0; //所有 电扇的面积之和
		double sumLightsArea = 0; //所有 电灯的面积之和
		double sumShapeArea = 0; //所有设施的面积之和
		//计算所有的电扇面积之和
		for(Fan aFan : fanList) {
			sumFanArea += aFan. getArea();
		}
		System. out. println("电扇面积和: " + sumFanArea);
		//计算所有的电灯面积之和
		for(Lights aLights : lightsList) {
			sumLightsArea += aLights. getArea();
		}
		System. out. println("电灯面积和:" + sumLightsArea);
		//计算所有的电扇面积之和
		for (Shape shape : shapeList) {
			sumShapeArea += shape. getArea();
		}
		System. out. println("所有设备面积和:"+ sumShapeArea) ;
	}
}
