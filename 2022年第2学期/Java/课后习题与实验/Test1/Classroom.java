package Test1;

import java. util. ArrayList;
//Ĭ�Ͻ���Ϊ����,��ǽ����ǽ������,ǰǽ�ͺ�ǽ������
//��ôֻ��Ҫ֪����ǽ��ǰǽ�Ŀ�Ⱥ͸߶Ⱦ���ȷ�����ҵĿռ��С
public class Classroom{ 
	private ArrayList<Wall> wallList = new ArrayList<>() ;//��ʦ�������ǽ��
	//������������豸��յ������ΰ��֮��ĺ���
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
