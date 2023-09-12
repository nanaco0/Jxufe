#pragma once
#include<vector>
#include<graphics.h>//需要安装easyx图形库

struct Point
{
	int row;
	int col;
};

class Block
{
private:
	int blockType;
	Point smallBlocks[4];
	IMAGE* img;
	static IMAGE* imgs[7];
	static  int size;

public:
	Block();
	Block& operator = (const Block& other);
	void drop();
	void moveLeftRight(int offset);
	void rotate();
	void draw(int leftMargin, int topMargin);
	void solidify(std::vector< std::vector<int>>& map);

	int getBlockType();
	bool blockInMap(const std::vector< std::vector<int>>& map);
	static IMAGE** getImages();

};

