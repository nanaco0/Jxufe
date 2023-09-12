package Test1;

import java. util. ArrayList;
//默认教室为矩形,左墙和右墙宽高相等,前墙和后墙宽高相等
//那么只需要知道左墙和前墙的宽度和高度就能确定教室的空间大小
public class Classroom{ 
	private ArrayList<Wall> wallList = new ArrayList<>() ;//教师里的四面墙、
	//教室里的其他设备如空调、桌椅板凳之类的忽略
	//......
	public ArrayList<Wall> getWallList() {
		return this. wallList;
	}
	public void setWallList (ArrayList<Wall> wallList) {
		for(Wall wall : wallList) {
			this. wallList. add (wall);
		}
	}
}
