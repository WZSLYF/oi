/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 3.4.1.cpp
*   Author: Yufei Li
*   Mail: 990704776@qq.com
*   CreatedTime: Fri 18 Jun 2021 11:29:22 PM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

void recursex(string sin, string spre) {
    int i;
    if(sin.length() < 2) {
        cout << sin;
        return;
    }
    for(i = 0; sin[i] != spre[0]; ++i);
    recursex(sin.substr(0, i), spre.substr(1, i));
    recursex(sin.substr(i + 1), spre.substr(i + 1));
    cout << spre[0];
}

int main()
{
    string sin, spre;
    cin >> sin >> spre;
    recursex(sin, spre);
    cout << endl;
    return 0;
}

