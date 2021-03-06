// LC93 恢复IP地址.cpp: 定义控制台应用程序的入口点。
//
/*
给定仅包含数字的字符串，通过返回所有可能的有效IP地址组合来恢复它。
输入： “25525511135”
输出： ["255.255.11.135", "255.255.111.35"]
*/

//ip的特点就是每段数字不超过255，并且只能分成4段。
//现在的问题就是如何判定每串字符被分成了4段。

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<string>restoreIpAddress(string s)
{
	string cur;
	vector<string>ipArray;
	int numb;

	numb = std::stoi(s.substr(0, 3));

	if (s.length() <= 3)
	{
		cur = cur + '.' + s;
		ipArray.push_back(cur);
	}

	if (numb <= 255)
	{
		cur = cur + s.substr(0, 3) + '.';
		//s = s.substr(3, s.length());
		restoreIpAddress(s.substr(3, s.length()));
		restoreIpAddress(s.substr(2, s.length()));
		restoreIpAddress(s.substr(1, s.length()));
	}
	else
	{
		return;
	}


	return ipArray;
}


int main()
{
	return 0;
}

