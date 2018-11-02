// 排序数组中的单个元素.cpp: 定义控制台应用程序的入口点。
//
/*
给定一个排序数组，只包含整数，其中每个元素出现两次，除了一个出现一次的元素。找到只出现一次的单个元素。
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums)
{
	int len = nums.size();
	int index = -1;
	int end = 0;
	while (end <= len-1)
	{
		if (nums[end] == nums[end+1])
		{
			end += 2;
			if (end == len - 1)
			{
				index = end;
			}
		}
		else
		{
			index = end;
			return;
		}
	}
	


// 	for (int i = 0;i < len-1;i++)
// 	{
// 		if (nums[i] == nums[i+1])
// 		{
// 			i++;
// 			if (i == len-1)
// 			{
// 				index = i;
// 			}
// 		}
// 		else
// 		{
// 			index = i;
// 		}
// 	}

	return nums[index];
}

int main()
{

	
    return 0;
}

