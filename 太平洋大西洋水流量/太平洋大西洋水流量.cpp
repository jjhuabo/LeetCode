// 太平洋大西洋水流量.cpp: 定义控制台应用程序的入口点。
//
/*
给定m x n表示大陆中每个单元格高度的非负整数矩阵，“太平洋”触及矩阵的左边缘和上边缘，“大西洋”触及右边缘和底边缘。

水只能从四个方向（向上，向下，向左或向右）从一个单元流向高度相等或更低的另一个方向。

找到水可以流入太平洋和大西洋的网格坐标列表。

给出以下5x5矩阵：

太平洋~~~~~
~  1   2   2   3  (5) *
~  3   2   3  (4) (4) *
~  2   4  (5)  3   1  *
~ (6) (7)  1   4   5  *
~ (5)  1   1   2   4  *
* * * * *大西洋

返回：

[[0,4]，[1,3]，[1,4]，[2,2]，[3,0]，[3,1]，[4,0]]（上述矩阵中带括号的位置）。
*/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<pair<int, int>> DFS(vector<vector<int>>& matrix, int i, int j, int direction[4][2], vector<pair<int, int>>path)
{
	if (matrix[i][j] == -1 || i < 0 || j < 0 || i > matrix.size() || j > matrix[0].size())
	{
		pair<int, int>qu(0, 0);
		path.push_back(qu);
		return path;
	}

	int next_x, next_y;
	int cur = matrix[i][j];
	matrix[i][j] = 1;

	for (int d = 0; d < 4; d++)
	{
		next_x = i + direction[d][0];
		next_y = j + direction[d][1];

		if (matrix[next_x][next_y] >= matrix[i][j])
		{
			pair<int, int>dir(i, j);
			path.push_back(dir);
			DFS(matrix, next_x, next_y, direction, path);
		}
	}

	return path;
}


vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix)
{
	int dirction[4][2] = { { 1,0 }, { -1,0 }, { 0,1 }, { 0,-1 } };
	vector<pair<int, int>>pathSum;

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			if (matrix[i][j] != -1)
			{
				DFS(matrix, i, j, dirction,pathSum);
			}
		}
	}

	return pathSum;
}




int main()
{
	int i = 0;
	for (int j = 0;j<100;j++)
	{
		i = i++;
	}

	cout << i << endl;

	system("pause");
	return 0;
}

