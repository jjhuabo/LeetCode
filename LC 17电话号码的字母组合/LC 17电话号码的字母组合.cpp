// LC 17电话号码的字母组合.cpp: 定义控制台应用程序的入口点。
//
/*
给定包含来自包含数字的字符串2-9，返回该数字可能表示的所有可能的字母组合。

下面给出了数字到字母的映射（就像在电话按钮上一样）。请注意，1不会映射到任何字母。

*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void combinations(string digits, vector<string>nums, vector<string>&ans, string temp, int start)
{
	if (start >= digits.size())
	{
		ans.push_back(temp);
		return;
	}

	int index = digits[start] - '0';
	for (int i = 0; i < nums[index].size(); i++)
	{
		combinations(digits, nums, ans, temp + nums[index][i], start + 1);
	}

	return;
}

vector<string>letterCombinations(string digits)
{
	vector<string> nums = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string>ans;
	if (digits.size() == 0)
	{
		return ans;
	}

	combinations(digits, nums, ans, "", 0);
	return ans;
}

int main()
{
	return 0;
}

