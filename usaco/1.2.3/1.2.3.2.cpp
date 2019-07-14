#include <iostream>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str1, str2, str3;
vector<string> vec1, vec2;
string str4[] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};

bool judge(int i, int j);

void dfs(int i) {
    if(i >= str1.size()) {
        //cout << str3 << endl;
        if(judge(0, vec1.size() - 1)) vec2.push_back(str3);
        return ;
    }
    for(int j = 0; j < 3; ++j) str3 += str4[str1[i] - '2'][j], dfs(i + 1), str3.resize(i);
}

bool judge(int i, int j) {
    if(i > j) return false;
    int mid = i + (j - i) / 2;
    if(vec1[mid] == str3) return true;
    if(vec1[mid] < str3) judge(mid + 1, j);
    else judge(i, mid - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> str1;
    while(cin >> str2) vec1.push_back(str2);
    
    sort(vec1.begin(), vec1.end());
    dfs(0);

    if(vec2.size()) {
        for(int i = 0; i < vec2.size(); ++i) cout << vec2[i] << endl;
    }
    else cout << "NONE" << endl;
    return 0;
}
