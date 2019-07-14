#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn = 15;
char str1[maxn], str2[maxn];
char str3[] = {"2223334445556667777888999"};
vector<string> ans;

bool judge(char *a, char *b) {
    if(strlen(a) != strlen(b)) return false;
    for(int i = 0; i < strlen(a); ++i) {
        if(a[i] != str3[b[i] - 'A']) return false;
    }
    return true;
}

int main() {
    scanf("%s", str1);
    
    int n = 0;
    while((scanf("%s", str2)) != EOF) {
        string tmp;
        if(judge(str1, str2)) ans.push_back(tmp = str2);
    }
    
    if(0 == ans.size()) printf("NONE\n");
    else {
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++ i) cout << ans[i] << endl;   
    }
    return 0;
}
