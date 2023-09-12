//----------------Log

//----------------2023_7_23
//1. 创建项目
//2. 导入素材
//3. C++开发
//4. 设计类/模块
//	4.1 Block:方块类
//	4.2 Tetris:游戏类
//5. 设计接口
//6. 启动游戏

#include"Tetris.h"

int main()
{
	using namespace std;
	Tetris game(20, 10, 263, 133, 36);
	game.play();

	return 0;
}
