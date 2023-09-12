#pragma once

#include<vector>
#include<graphics.h>
#include"Block.h"


class Tetris
{
private:
	int score;
	int level;//当前关卡，score=[0,100]为level 1，score=[101,200]为level 2
	int lineCount;//当前消除了多少行
	int highestScore;

	int delay;//画面更新时延
	bool update;//画面是否更新

	bool gameOver;

	//int map[20][10];
	//0:空白，没有任何方块
	//5:第5种俄罗斯方块
	std::vector<std::vector<int>> map;
	int rows;
	int columns;
	int leftMargin;
	int topMargin;
	int blockSize;

	IMAGE imgBg;
	IMAGE imgWin;
	IMAGE imgOver;

	Block* curBlock;
	Block* nextBlock;//预告方块
	Block bakBlock;//当前方块降落过程中，用来备份上一个合法位置的

public:
	Tetris(int rows, int columns, int leftMargin, int topMargin, int blockSize);
	void init();//初始化
	void play();//开始游戏

private://是类内部的方法调用的，不是别人调用的，所以用private
	void keyEvent();//键盘事件
	void updateWindow();
	void drop();
	void clearLine();
	void moveLeftRight(int offset);
	void rotate();
	void drawScore();//绘制游戏信息，score，level，lineCount，highestScore;
	void checkOver();//检查游戏是否结束
	void saveScore();//保存最高分
	void diaplayOver();//绘制游戏结束画面


	int getDelay();
	//返回距离上一次调用该函数，间隔了多少毫秒
	//第一次调用该函数，返回0
};