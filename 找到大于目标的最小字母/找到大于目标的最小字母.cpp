// 找到大于目标的最小字母.cpp: 定义控制台应用程序的入口点。
//
/*
给定letters仅包含小写字母的排序字符列表，并给定目标字母target，找到列表中大于给定目标的最小元素。
字母也包裹着。例如，如果目标是target = 'z'和letters = ['a', 'b']，答案是'a'。
*/

//分析：这种题目一看就是考察的搜索的内容

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target)
{
	int len = letters.size();
	int index;
	sort(letters.begin(), letters.end());

	if (letters.back() <= target)
	{
		return letters[0];
	}

	if (letters[0] > target)
	{
		return letters[0];
	}

	for (int i = 0;i<len-1;i++)
	{
		if (letters[i] <= target)
		{
			if (letters[i+1]>target)
			{
				index = i + 1;
			}
		}
	}

	return letters[index];
}

char search(vector<char>& letters, char target,int index) 
{
	index = index / 2 + 1;
	for (int i = 0;i<index;i++)
	{

	}
}

int main()
{
	vector<char>num;
	num.push_back('c');
	num.push_back('f');
	num.push_back('j');
	num.push_back('a');
	cout << nextGreatestLetter(num, 'c') << endl;
	system("pause");
	return 0;
}

