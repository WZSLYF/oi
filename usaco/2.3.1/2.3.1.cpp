#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;
vector<string> dat;
string str;
int dp[maxn], n;

bool judge(int cur, string str1) {
    if(cur + str1.size() > str.size()) return false;
    for(int i = 0; i < str1.size(); ++i) if(str[cur + i] != str1[i]) return false;
    return true;
}

int main() {
    while(cin >> str && str[0] != '.') dat.push_back(str);
    
    string tmp;
    str.clear();
    while(cin >> tmp) str += tmp;
    
    dp[0] = 1;
    for(int j = 0; j < str.size(); ++j)
    for(int i = 0; i < dat.size(); ++i) {
    if(judge(j, dat[i])) if(dp[j]) dp[j + dat[i].size()] = 1;
    }

    int ans = 0;
    for(int i = 0; i <= str.size(); ++i) if(dp[i]) ans = max(ans, i);
    printf("%d\n", ans);
    return 0;
}
