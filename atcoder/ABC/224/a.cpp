/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: a.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 三 10/27 00:59:44 2021
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;
    int len = str.size();
    if(str.substr(len - 2, 2) == "er") cout << "er" << endl;
    else if(str.substr(len - 3, 3) == "ist") cout << "ist" << endl;
    return 0;
}

