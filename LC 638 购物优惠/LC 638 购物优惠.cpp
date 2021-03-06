// LC 638 购物优惠.cpp: 定义控制台应用程序的入口点。
//
/*
在LeetCode商店中，有一些商品可供出售。每件商品都有价格。

但是，有一些特别优惠，特别优惠包括一种或多种不同类型的商品和销售价格。

您将获得每件商品的价格，一系列特别优惠以及我们需要为每件商品购买的商品数量。
工作是输出，你必须支付的最低价格恰好为给予一定的项目，在那里你可以使特殊优惠的最佳利用。

每个特别优惠以阵列形式表示，最后一个数字代表您需要为此特别优惠支付的价格，其他数字代表您购买此优惠时可获得的特定商品数量。

您可以根据需要多次使用任何特别优惠。

例1：
输入： [2,5]，[[3,0,5]，[1,2,10]]，[3,2]
输出： 14
说明：
有两种物品，A和B.它们的价格分别是2美元和5美元。
在特别优惠1中，您可以为3A和0B支付5美元
在特别优惠2中，您可以支付10美元的1A和2B。
您需要购买3A和2B，因此您可以为1A和2B（特价＃2）支付10美元，为2A支付4美元。
*/

//本题思路就是尽可能多的利用优惠条件达成购买价格最少，因为不限定购买优惠次数，因此这是一个完全背包的问题。
//这题本题是按组背包和安全背包的

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int shoppingOffers(vector<int>&price, vector<vector<int>>&special, vector<int>&needs)
{
	vector<vector<int>>dp(needs[0], vector<int>(needs[1], 0));
	int offerSelectLen = special.size();

	for (int i = 0; i < price[0]; i++)
	{
		for (int j = 0; j < price[1]; j++)
		{
			for (int k = 0; k < offerSelectLen; k++)
			{
				if (i <= special[k][0] && j <= special[k][1])
				{
					dp[i][j] = dp[i - special[k][0]][j - special[k][1]] + special[k][2];
				}
				else if (i >= 1 && j >= 1)
				{
					dp[i][j] = dp[i - 1][j - 1] + price[0] + price[1];
				}
				else if (i == 0 && j >= 1)
				{
					dp[i][j] = dp[i][j - 1] + price[1];
				}
				else if (i >= 0 && j == 0)
				{
					dp[i][j] = dp[i - 1][j] + price[0];
				}
			}
		}
	}
}


int main()
{
	return 0;
}

