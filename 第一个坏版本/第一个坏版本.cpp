// 第一个坏版本.cpp: 定义控制台应用程序的入口点。
//
/*
您是产品经理，目前领导团队开发新产品。不幸的是，您产品的最新版本未通过质量检查。
由于每个版本都是基于以前的版本开发的，因此糟糕版本之后的所有版本也都很糟糕。
假设你有n版本[1, 2, ..., n]而你想要找出第一个坏版本，这会导致以下所有版本都不好。
您将获得一个API bool isBadVersion(version)，它将返回是否version为坏。
实现一个函数来查找第一个坏版本。您应该最小化对API的调用次数。
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

bool isBadVersion(int version);

int firstBadVersion(int n)
{
	int l = 1,h = n;

	while (l < h)
	{
		int mid = (h - l) / 2 + 1;
		if (isBadVersion(mid))
		{
			h = mid;
		}
		else
		{
			l = mid + 1; 
		}
	}

	return l;
}

int search(int begin, int end)
{
	for (int i = begin;i<=end;i++)
	{
		if (isBadVersion(i))
		{
			return i;
		}
		else
		{
			
		}
	}
}

int main()
{
    return 0;
}

