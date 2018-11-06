// 爆裂气球.cpp: 定义控制台应用程序的入口点。
//
/*
由于n气球，从索引0到n-1。每个气球都涂上一个由数字表示的数字nums。
你被要求爆破所有的气球。如果你爆裂的气球，i你会得到nums[left] * nums[i] * nums[right]硬币。这里left和right相邻的指数i。
脉冲串之后，left并right然后成为相邻。
通过明智地破坏气球找到可以收集的最大硬币。
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;


//这个题的规律就是戳破一个气球之后i前面对应的nums没有发生变化，i后面对应的nums对应的nums往后移动一格
int maxCoins(vector<int>& nums)
{
	int len = nums.size();
	vector<int>sum(len + 1, 1);
	if (len <= 3)
	{
		return (len == 3) ? nums[0] * nums[1] * nums[2] : nums[0] * nums[1];
	}

	for (int i = 0; i <= len; i++)
	{
		sum[i + 1] = sum[i] + nums[i - 1] * nums[i + 1] * nums[i + 2];
	}

}

int main()
{
	return 0;
}
