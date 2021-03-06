// 字梯.cpp: 定义控制台应用程序的入口点。
//
/*
给定两个单词（beginWord和endWord）和一个字典的单词列表，找到从beginWord到endWord的最短变换序列的长度，这样：
一次只能更改一个字母。
每个转换后的单词必须存在于单词列表中。需要注意的是beginWord是不是变换词。
注意：

如果没有这样的转换序列，则返回0。
所有单词都有相同的长度。
所有单词仅包含小写字母字符。
您可以假设单词列表中没有重复项。
您可以假设beginWord和endWord是非空的并且不相同。
例1：

输入：
beginWord =“hit”，
endWord =“cog”，
wordList = [“hot”，“dot”，“dog”，“lot”，“log”，“cog”]

*/

#include "stdafx.h"
#include <queue>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> dict(wordList.begin(), wordList.end());
	if (!dict.count(endWord)) { return 0; }
	queue<string>q;
	q.push(beginWord);

	int l = beginWord.length();

	//record the depth
	int step = 0;

	while (!q.empty())
	{
		++step;
		for (int size = q.size();size>0;size--)
		{
			string w = q.front();
			q.pop();

			for (int i = 0;i < l;i++)
			{
				//record pos which was exchanged
				char ch = w[i];
				for (int j = 'a';j<='z';j++)
				{
					w[j] = j;
					if (w == endWord) { return step++; }
					if (!dict.count(w)) { continue; }
					dict.erase(w);
					q.push(w);
				}
				w[i] = ch;
			}
		}
	}
	return 0;
}

int main()
{
    return 0;
}

