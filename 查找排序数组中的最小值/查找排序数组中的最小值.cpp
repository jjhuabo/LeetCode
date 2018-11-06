// 查找排序数组中的最小值.cpp: 定义控制台应用程序的入口点。
//
/*
假设按升序排序的数组在事先未知的某个枢轴处旋转。

（也就是说，   [0,1,2,4,5,6,7] 可能会   [4,5,6,7,0,1,2]）。

找到最小元素。

您可以假设数组中不存在重复。
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	return nums[0];
}

int main()
{
    return 0;
}

