/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: c.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 三  9/22 00:41:18 2021
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define re register

int input(char *str, int n) {
    int res = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            str[i * n + j] = getchar(), res += (str[i * n +j] == '#');
        }
        getchar();
    }
    return res;
}

void init(char* str1, char* str2, int n) {
    int x = input(str1, n), y = input(str2, n);
    if(x != y) cout << "No" << endl, exit(0);
}

bool check(char *str1, char *str2, int n) {
    int x1, y1, x2, y2;
    auto findPos = [](char* str, int n, int &x, int &y) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(str[i * n + j] == '#') {
                    x = i, y = j;
                    return;
                }
            }
        }
    };

    findPos(str1, n, x1, y1), findPos(str2, n, x2, y2);

    /*for(re int i = 0; i < n; ++i) {
        for(re int j = 0; j < n; ++j) {
            int tmpx1 = (i + x1) * n + y1 + j;
            int tmpx2 = (i + x2) * n + y2 + j;
            tmpx1 %= n * n;
            tmpx2 %= n * n;
            cout << str1[tmpx1] << str2[tmpx2] << endl;
            if(str1[tmpx1] != str2[tmpx2]) return false;
        }
    }*/
    
    //cout << x1 << y1 << x2 << y2 << endl;
    int offset_i = x2 - x1;
    int offset_j = y2 - y1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int tmpx = i + offset_i;
            int tmpy = j + offset_j;
            if(tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < n) {
                if(str1[i * n + j] != str2[tmpx * n + tmpy]) return false;
            }
            else {
                if(str1[i * n + j] == '#') return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    getchar();
    char dat1[n][n], dat2[n][n];
    char dat3[4][n][n];

    init((char*)dat1, (char*)dat2, n);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            dat3[0][i][j] = dat1[i][j];
            dat3[1][i][j] = dat1[n - 1 - j][i];
            dat3[2][i][j] = dat1[n - 1 - i][n - 1 - j];
            dat3[3][i][j] = dat1[j][n - 1 - i];
        }
    }

    for(int i = 0; i < 4; ++i) {
        if(check((char*)dat3[i], (char*)dat2, n)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

