#include <bits/stdc++.h>

using namespace std;

int n, S;

bool judge1(string str) {
    int len = str.size();
    for(int i = 0; i < len / 2; ++i) if(str[i] != str[len - 1 - i]) return false;
    return true;
}

bool judge(int x) {
    int num = 0;
    for(int i = 2; i <= 10; ++i) {
        string str;
        int tmp = x;
        while(tmp) {
            str += (tmp%i) + '0';
            tmp /= i;
        }

        if(judge1(str)) num++;
        if(num >= 2) break;
    }
    
    return num >= 2;
}

int main() {
    scanf("%d %d", &n, &S);
    int num = 0;
    for(int i = S + 1; ; ++i) {
        if(judge(i)) printf("%d\n", i), num++;
        if(num >= n) break;
    }
    return 0;
}
