#include <bits/stdc++.h>

using namespace std;

const int maxn = 300;
int n;

bool chage(int x) {
    string str;
    while(x) {
        if((x % n) >= 10) str += (x%n) - 10 + 'A';
        else str += (x%n) + '0';
        x /= n;
    }

    int len = str.size();
    for(int i = 0; i < len / 2; ++i) if(str[i] != str[len - 1 - i]) return false;
    return true;
}

void print(int x) {
    int tmp = x;
    string str;
    while(x) {
        if((x%n) >= 10) str += (x%n) - 10 + 'A';
        else str += (x%n) + '0';
        x /= n;
    }
    
    reverse(str.begin(), str.end());
    cout << str;
    printf(" ");
    str.clear();
    x = tmp * tmp;
    while(x) {
        if((x%n) >= 10) str += (x%n) - 10 + 'A';
        else str += (x%n) + '0';
        x /= n;
    }
    reverse(str.begin(), str.end());
    cout << str;
    printf("\n");
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= maxn; ++i) if(chage(i * i)) print(i);
    return 0;
}
