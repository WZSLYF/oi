#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

const int maxn = 5e3 + 10;
string str1, str2[maxn], str3;
string str4[] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};
map<int, vector<int> > mp;
vector<string> ans;

void judge();

void dfs(int i) {
    if(i >= str1.size()) {
        //cout << strlen(str3.c_str()) << endl;
        //for(int j = 0; j < i; ++ j) cout << str3[j];
        //cout << endl;
        judge();
        return;
    }
    for(int j = 0; j < 3; ++j) {
        str3[i] = str4[str1[i] - '2'][j], dfs(i + 1);       
    }
}

bool isEQ(int j) {
    //cout << strlen(str3.c_str()) << strlen(str2[j].c_str()) << endl;
    if(strlen(str3.c_str()) != strlen(str2[j].c_str())) return false;
    for(int i = 0; i < strlen(str3.c_str()); ++i) if(str3[i] != str2[j][i]) return false;
    return true;
}

void judge() {
    int s = 1;
    for(int i = 0; i < strlen(str3.c_str()); ++i) s *= str3[i] - 'A' + 1, s %= 4493;
    //cout << s << endl;
    for(int i = 0; i < mp[s].size(); ++i) if(isEQ(mp[s][i])) ans.push_back(str2[mp[s][i]]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> str1;
    int n = 0;
    while(cin >> str2[n]) ++n;

    for(int i = 0; i < n; ++i) {
        int len = str2[i].size();
        int s = 1;
        for(int j = 0; j < len; ++j) s *= str2[i][j] - 'A' + 1, s %= 4493;
        mp[s].push_back(i);
        //cout << mp[s][0] << endl;
    }
    
    dfs(0);
    if(0 == ans.size()) cout << "NONE" << endl;
    else {
	sort(ans.begin(), ans.end());
    	for(int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
    }
    return 0;
}
