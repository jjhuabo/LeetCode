// 青蛙跳403.cpp: 定义控制台应用程序的入口点。
//
/*
一只青蛙正在过河。河流分为x个单位，每个单位可能存在或不存在石头。青蛙可以跳到石头上，但不能跳入水中。

给出按照升序排序的石块位置（单位），确定青蛙是否能够通过落在最后一块石头上过河。
最初，青蛙在第一块石头上并假设第一次跳跃必须是1个单位。

如果青蛙的最后一次跳跃是k个单位，那么它的下一个跳跃必须是k -1，k或k + 1个单位。请注意，青蛙只能向前跳。
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

//这题采用dp，问题是状态空间如何进行选择。
//dp[i][j]代表从第i个单位起跳，跳到了第j个石头上
//状态方程转化：就是对每个状态进行决策，这里有两种决策
//dp[i][j] = dp[k][j - (stones[i] - stones[k] + 1)] + dp[k][j - (stones[i] - stones[k] - 1)]

bool canCross(vector<int>& stones)
{
	int len = stones.size();
	vector<int>minus(len, stones[0]);
	for (int i = 1;i<len;i++)
	{
		minus[i] = stones[i] - stones[i - 1];
	}

	vector<vector<int>>dp(len, vector<int>(len, 0));

	//init
	dp[0][0] = 1;

	for (int j = 0;j<len;j++)
	{
		for (int i = 0;i<j;i++)
		{
			for (int k = 0;k < i;k++)
			{
				dp[i][j] = dp[k][j - (stones[i] - stones[k] + 1)] + dp[k][j - (stones[i] - stones[k] - 1)];
			}
		}
	}

	return dp[len - 1][len - 1] != 0;
}

int main()
{
    return 0;
}

