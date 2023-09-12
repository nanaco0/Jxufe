#include "Block.h"
#include<cstdlib>
#include<iostream>

IMAGE* Block::imgs[7] = { NULL, };
int Block::size = 36;

Block::Block()
{
	if (imgs[0] == NULL)//如果方块的纹理没有加载
	{
		IMAGE imgTemp;
		loadimage(&imgTemp, "res/tiles.png");

		SetWorkingImage(&imgTemp);
		for (int i = 0; i < 7; i++)
		{
			imgs[i] = new IMAGE;
			getimage(imgs[i], i * size, 0, size, size);
		}
		SetWorkingImage();//恢复工作区
	}

	//随机生成一种方块，1~7
	blockType = rand() % 7 + 1;;
	//为随机防控适配纹理
	img = imgs[blockType - 1];

	int blocks[7][4] = {
		1,3,5,7, // I
		2,4,5,7, // Z 1型
		3,5,4,6, // Z 2型
		3,5,4,7, // T
		2,3,5,7, // L
		3,5,7,6, // J
		2,3,4,5, // 田
	};


	//初始化smallBlock
	for (int i = 0; i < 4; i++)
	{
		int value = blocks[blockType - 1][i];
		smallBlocks[i].row = value / 2;
		smallBlocks[i].col = value % 2;
	}

}

Block& Block::operator=(const Block& other)
{
	if (this == &other)
	{
		return *this;
	}
	this->blockType = other.blockType;
	for (int i = 0; i < 4; i++)
	{
		this->smallBlocks[i] = other.smallBlocks[i];
	}
	return *this;
}

void Block::drop()
{
	for (int i = 0; i < 4; i++)
	{
		smallBlocks[i].row++;
	}
}

void Block::moveLeftRight(int offset)
{
	for (int i = 0; i < 4; i++)
	{
		smallBlocks[i].col += offset;
	}
}

void Block::rotate()
{
	Point p = smallBlocks[1];
	for (int i = 0; i < 4; i++)
	{
		Point tmp = smallBlocks[i];
		smallBlocks[i].col = p.col - tmp.row + p.row;
		smallBlocks[i].row = p.row + tmp.col - p.col;
	}
}

void Block::draw(int leftMargin, int topMargin)
{
	for (int i = 0; i < 4; i++) {
		int x = smallBlocks[i].col * size + leftMargin;
		int y = smallBlocks[i].row * size + topMargin;
		putimage(x, y, img);
	}
}

void Block::solidify(std::vector<std::vector<int>>& map)
{
	for (int i = 0; i < 4; i++)
	{
		map[smallBlocks[i].row][smallBlocks[i].col] = blockType;
	}
}

int Block::getBlockType()
{
	return blockType;
}

bool Block::blockInMap(const std::vector<std::vector<int>>& map)
{
	for (int i = 0; i < 4; i++)
	{
		int validRows = map.size();
		int validCols = map[0].size();
		if (smallBlocks[i].col < 0 || smallBlocks[i].col >= validCols ||
			smallBlocks[i].row < 0 || smallBlocks[i].row >= validRows ||
			map[smallBlocks[i].row][smallBlocks[i].col] != 0)
		{
			return false;
		}
	}
	return true;
}

IMAGE** Block::getImages()
{
	return imgs;
}
