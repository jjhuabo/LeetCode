// 添加括号的不同方法.cpp: 定义控制台应用程序的入口点。
//
/*
给定一串数字和运算符，通过计算所有不同的组编号和运算符的方式返回所有可能的结果。有效的运算符是+，-和*。
输入： "2-1-1"
输出： [0, 2]
说明：
((2-1)-1) = 0
(2-(1-1)) = 2
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace jihua
{
	int add(int a, int b) { return a + b;}
	int minus(int a, int b) { return a - b; }
	int multiply(int a, int b) { return a * b; }
}

vector<int>diffWaysToCompute(string input)
{
	vector<int>result;
	
	
}

unordered_map<string, vector<int>> m_;

const vector<int>& ways(const string& input)
{
	vector<int>ans;

	for (int i = 0;i<input.length();i++)
	{
		char op = input[i];

		if (op == '+'||op=='-'||op=='*')
		{
			const string left = input.substr(0, i);
			const string right = input.substr(i + 1);

			const vector<int>& l = ways(left);
			const vector<int>& r = ways(right);

			std::function<int(int, int)>f;
			switch (op)
			{
			case '+':f = jihua::add; break;
			case '-':f = jihua::minus; break;
			case '*':f = jihua::multiply; break;
			}

			for (int a:l)
			{
				for (int b:r)
				{
					ans.push_back(f(a, b));
				}
			}
		}
	}
}

int main()
{
    return 0;
}

