// 矩阵中的连通分量数目.cpp: 定义控制台应用程序的入口点。
//
/*
给定'1's（土地）和'0's（水）的2d网格图，计算岛屿的数量。
岛被水包围，通过水平或垂直连接相邻的土地而形成。您可以假设网格的所有四个边都被水包围。
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

//思路：这道题要处理好截止条件
//截至条件：如何判定这是一个岛屿grid[i+1][j] == 0 && grid[i][j+1] == 0的时候
//确定这是一个岛屿

int numIslands(vector<vector<char>>&grid)
{
	int conCount = 0;
	for (int i = 0;i<grid.size();i++)
	{
		for (int j = 0;j>grid[0].size();j++)
		{
			if (grid[i][j] == '1')
			{
				conCount = dfs(grid, i, j);
			}
		}
	}

	return conCount;
}

int dfs(vector<vector<char>>&grid,int i,int j)
{
	if (i < 0 || i >grid.size()||j<0||j>grid[0].size()||grid[i][j] == '0')
	{
		return 0;
	}

	int areaCount = 0;
	grid[i][j] = '0';
	
	if (grid[i+1][j] == '0' && grid[i][j+1] == '0' && grid[i+1][j+1] == '1')
	{
		areaCount++;
	}

	return dfs(grid, i, j - 1) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i + 1, j);
}

int main()
{
    return 0;
}

