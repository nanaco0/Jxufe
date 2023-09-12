#include<time.h> 
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<fstream>
#include "Tetris.h"
#include"Block.h"
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define RECORDER_FILE "recorder.txt"


//speed：方块下降的速度
const int MAX_LEVEL = 5;
const int SPEED_NORMAL[MAX_LEVEL] = { 900,800,700,600,500 };//ms
const int SPEED_QUICK = 30;

//const int center_horizontal = 412;
const int right_horizontal = 728;


Tetris::Tetris(int rows, int columns, int leftMargin, int topMargin, int blockSize)
{

	this->rows = rows;
	this->columns = columns;
	this->leftMargin = leftMargin;
	this->topMargin = topMargin;
	this->blockSize = blockSize;

	for (int i = 0; i < rows; i++)
	{
		std::vector<int> mapRow;
		for (int j = 0; j < columns; j++)
		{
			mapRow.push_back(0);
		}
		map.push_back(mapRow);
	}
}

void Tetris::init()
{
	mciSendString("play res/bg.mp3 repeat", 0, 0, 0);
	delay = SPEED_NORMAL[0];

	srand((unsigned)time(NULL));

	//创建游戏窗口
	initgraph(938, 896);

	//加载背景图片
	loadimage(&imgBg, "res/bg2.png");

	// 加载胜利背景
	loadimage(&imgWin, "res/win.png");
	// 加载失败背景
	loadimage(&imgOver, "res/over.png");

	//初始化游戏区中的数据
	char date[20][10];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++) {
			map[i][j] = 0;
		}
	}

	score = 0;
	lineCount = 0;
	level = 1;

	//初始化最高分
	std::ifstream file(RECORDER_FILE);
	if (!file.is_open())//打开失败
	{
		std::cout << RECORDER_FILE << "打开失败" << std::endl;
		highestScore = 0;
	}
	else
	{
		file >> highestScore;//从文本中获取数据，输入到highestScore；cin从键盘中获取数据，输入到highestScore
	}
	file.close();

	gameOver = false;
}

void Tetris::play()
{
	init();

	nextBlock = new Block;
	curBlock = nextBlock;
	nextBlock = new Block;

	int timer = 0;
	while (1) {
		//接受用户的输入
		keyEvent();

		timer += getDelay();
		if (timer > delay)
		{
			timer = 0;//画面渲染刷新定时器归零
			drop();
			update = true;
		}

		if (update)
		{
			updateWindow();//渲染游戏画面
			update = false;

			clearLine();
		}
		if (gameOver)
		{
			//保存分数
			saveScore();

			//绘制游戏结束界面
			diaplayOver();

			system("pause");

			//重新开局
			init();
		}
	}
}

void Tetris::keyEvent()
{
	unsigned char ch = ' ';//无符号char范围:[0,225];char范围:[-128,127]
	bool rotateFlag = false;
	int dx = 0;

	if (_kbhit())//如何用户有输入，才getch；如果直接getch，程序会一直等待输入造成阻塞
	{
		ch = _getch();

		//按方向键，会返回两个字符
		//如果按 上方向键，返回224 72
		//如果按 下方向键，返回224 80
		//如果按 左方向键，返回224 75
		//如果按 右方向键，返回224 77

		if (ch == 224)
		{
			ch = _getch();
			switch (ch)
			{
			case 72:
				rotateFlag = true;
				break;
			case 80://快速下降
				delay = SPEED_QUICK;
				break;
			case 75://向左移动
				dx = -1;
				break;
			case 77://向左移动
				dx = 1;
				break;
			default:
				break;
			}
		}
	}
	if (rotateFlag)
	{
		rotate();
		update = true;
	}
	if (dx)
	{
		moveLeftRight(dx);
		update = true;
	}
}

void Tetris::updateWindow()
{
	putimage(0, 0, &imgBg);//绘制背景图片

	IMAGE** imgs = Block::getImages();
	BeginBatchDraw();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (map[i][j] == 0)
			{
				continue;
			}
			int x = j * blockSize + leftMargin;
			int y = i * blockSize + topMargin;
			putimage(x, y, imgs[map[i][j] - 1]);
		}
	}

	curBlock->draw(leftMargin, topMargin);
	nextBlock->draw(right_horizontal, topMargin);

	drawScore();

	EndBatchDraw();
}

void Tetris::drop()
{
	bakBlock = *curBlock;
	curBlock->drop();

	if (!curBlock->blockInMap(map))
	{
		bakBlock.solidify(map);
		delete curBlock;
		curBlock = new Block;
		curBlock = nextBlock;
		nextBlock = new Block;

		//检查游戏是否结束
		checkOver();
	}
	delay = SPEED_NORMAL[level - 1];
}

void Tetris::clearLine()
{
	int lines = 0;
	int k = rows - 1;
	for (int i = rows - 1; i >= 0; i--)
	{
		int count = 0;
		for (int j = 0; j < columns; j++)
		{
			if (map[i][j])
			{
				count++;
			}
			map[k][j] = map[i][j];
		}
		if (count < columns)//不是满行
		{
			k--;
		}
		else//统计一次消除多少行
		{
			lines++;
		}
	}
	if (lines > 0)
	{
		mciSendString("play res/xiaochu1.mp3", 0, 0, 0);

		//计算score
		int addScore[4] = { 10,30,60,80 };
		score += addScore[lines - 1];

		//计算level
		//0~100第一关，101~200第二关
		level = (score + 99) / 100;

		if (level > MAX_LEVEL)
		{
			gameOver = true;
		}

		//计算lineCount
		lineCount += lines;

		//计算highestScore
		if (score > highestScore)
		{
			highestScore = score;
			//更新最高分
			std::ofstream file(RECORDER_FILE);
			if (!file.is_open())//打开失败
			{
				std::cout << RECORDER_FILE << "打开失败" << std::endl;
				highestScore = 0;
			}
			else
			{
				file << highestScore;
			}
			file.close();
		}

		update = true;
	}
}

void Tetris::moveLeftRight(int offset)
{
	bakBlock = *curBlock;
	curBlock->moveLeftRight(offset);

	if (!curBlock->blockInMap(map))
	{
		*curBlock = bakBlock;
	}
}

void Tetris::rotate()
{
	if (curBlock->getBlockType() == 7)//7是田字形方块，旋转没有意义，该分支处理田字形方块的旋转，直接返回即可
	{
		return;
	}
	bakBlock = *curBlock;
	curBlock->rotate();

	if (!curBlock->blockInMap(map))
	{
		*curBlock = bakBlock;
	}
}

void Tetris::drawScore()
{
	//绘制分数
	char scoreText[32];
	sprintf_s(scoreText, sizeof(scoreText), "%d", score);
	//设置字体
	settextcolor(RGB(180, 180, 180));//设置颜色
	LOGFONT f;
	gettextstyle(&f);//获取现在的字体
	f.lfHeight = 50;
	f.lfWeight = 20;
	f.lfQuality = ANTIALIASED_QUALITY;//字体抗锯齿
	strcpy_s(f.lfFaceName, sizeof(f.lfFaceName), _T("Segoe UI Black"));
	settextstyle(&f);//设置字体
	setbkmode(TRANSPARENT);

	outtextxy(670, 727, scoreText);

	//绘制level
	sprintf_s(scoreText, sizeof(scoreText), "%d", lineCount);
	gettextstyle(&f);//获取现在的字体
	int xPos = 224 - f.lfWeight * strlen(scoreText);
	outtextxy(xPos, 817, scoreText);

	//绘制lineCount
	sprintf_s(scoreText, sizeof(scoreText), "%d", level);
	outtextxy(224 - 20, 727, scoreText);

	//绘制highestScore
	sprintf_s(scoreText, sizeof(scoreText), "%d", highestScore);
	outtextxy(670, 817, scoreText);

}

void Tetris::checkOver()
{
	gameOver = (curBlock->blockInMap(map) == false);
}

void Tetris::saveScore()
{
	//计算highestScore
	if (score > highestScore)
	{
		highestScore = score;
		//更新最高分
		std::ofstream file(RECORDER_FILE);
		if (!file.is_open())//打开失败
		{
			std::cout << RECORDER_FILE << "打开失败" << std::endl;
			highestScore = 0;
		}
		else
		{
			file << highestScore;
		}
		file.close();
	}
}


void Tetris::diaplayOver()
{
	mciSendString("stop res/bg.mp3", 0, 0, 0);

	//判别胜利
	if (level <= MAX_LEVEL)//失败
	{
		putimage(262, 361, &imgOver);
		mciSendString("play res/over.mp3", 0, 0, 0);
	}
	else
	{
		putimage(262, 361, &imgWin);
		mciSendString("play res/win.mp3", 0, 0, 0);
	}
}

//第一次调用返回0
//其他调用，返回距离上一次使用过去了多少毫秒
int Tetris::getDelay()
{
	static unsigned long long lastTime = 0;
	unsigned long long currentTime = GetTickCount();

	if (lastTime == 0)
	{
		lastTime = currentTime;
		return 0;
	}
	else
	{
		int ret = currentTime - lastTime;
		lastTime = currentTime;
		return ret;
	}
}
