// 查找最大连通面积.cpp: 定义控制台应用程序的入口点。
//
/*
给定一个grid0和1的非空二维数组，一个岛是一组1（代表陆地）4方向连接（水平或垂直）。您可以假设网格的所有四个边都被水包围。

找到给定2D阵列中岛的最大面积。（如果没有岛，则最大面积为0.）

例1：

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,1,1,0,1,0,0,0,0,0,0,0,0],
[0,1,0,0,1,1,0,0,1,0,1,0,0],
[0,1,0,0,1,1,0,0,1,1,1,0,0],
[0,0,0,0,0,0,0,0,0,0,1,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,0,0,0,0,0,0,1,1,0,0,0,0]]
鉴于以上网格，返回6。注意答案不是11，因为岛必须是4向连接。
*/

//思路这种题目就是经典的dfs了：最大连通问题

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
	int area = 0;
	int temp = 0;

	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j] == 1)
			{
				temp = dfs(grid, i, j);
				area = max(area, temp);
			}
		}
	}

	return area;
}

int dfs(vector<vector<int>>&grid, int i, int j)
{
	if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
	{
		return 0;
	}

	int tempMaxArea = 1;
	//if the point has been visited,set the mark
	grid[i][j] = 0;

	tempMaxArea += dfs(grid, i, j - 1) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i + 1, j);
	return tempMaxArea;
}

int main()
{
	return 0;
}

