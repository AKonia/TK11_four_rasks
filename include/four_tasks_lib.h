// Copyright 2016 AuthorName. All rights reserved.
#ifndef __FOUR_TASKS_H__
#define __FOUR_TASKS_H__
#include <queue>
#include <vector>
#include <algorithm>
#include <list>

#include <cmath>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int comp(const void * lhs, const void * rhs)
{
    int l = *((int*)lhs),
        r = *((int*)rhs);
    return l < r ? -1 : (l == r ? 0 : 1);
}

int revInt(int arg)
{
    int res = 0;
    int buf = abs(arg);
    while(buf != 0)
    {
        res *= 10;
        res += buf % 10;
        buf /= 10;
    }
    return res * (arg / abs(arg));
}

string prefixOfDict(vector<string> dict)
{
    string res = "";
    char buf = 0;
    for(int indx = 0;;indx++, res += buf)
        for(int i = 0; i < dict.size();i++)
        {
            if(dict[i].size() == indx)
                return res;
            if(buf == 0)
                buf = dict[i][indx];
            else if(dict[i][indx] != buf)
                return res;
        }
    return res;
}

list<int>& reversePairs(list<int>& arg)
{
    if(arg.size() % 2 != 0)
        throw "ERROR: list size is not even !!!";
    queue<int> first, sec;
    int buf = 0;
    list<int> argCopy = arg;
    while(!argCopy.empty())
    {
        if(buf % 2 == 0)
            first.push(argCopy.front());
        else
            sec.push(argCopy.front());
        buf++;
        argCopy.pop_front();
    }
    while(!first.empty())
    {
        argCopy.push_back(sec.front());
        argCopy.push_back(first.front());
        first.pop();
        sec.pop();
    }
    arg = argCopy;
    return arg;
}

int quantityOfSums(vector<int> arr, int sumValue)
{
    std::sort(arr.begin(), arr.end());
    int res = 0;
    for(int li = 0, ri = arr.size()-1; li < ri;)
    {
        if(arr[li] + arr[ri] == sumValue)
        {
            res++;
            li++;
            ri--;
        }
        if(arr[li] + arr[ri] < sumValue)
            li++;
        if(arr[li] + arr[ri] > sumValue)
            ri--;
    }
    return res;
}

#endif  // __FOUR_TASKS_H__
