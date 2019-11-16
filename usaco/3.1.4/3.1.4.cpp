#include <bits/stdc++.h>

using namespace std;

#define Rep(i, n) for(int i = 0; i < n; ++i)

const int maxn = 2e4 + 10;
int A, B, N;
struct node {
    int num;
    string str;
    bool operator < (const node& b) const { 
        if(num == b.num) {
            if(str.size() == b.str.size()) return str < b.str;
            else return str.size() < b.str.size();
        }
        else return num > b.num;       
    }
};
vector<node> vec;
map<string, int> mp;

int main() {
    cin >> A >> B >> N;
    
    string str1;
    string str3;
    while(cin >> str3) str1 += str3;
    int len = str1.size();
    Rep(i, len) {
        for(int j = A; j <= B; ++j) {
            if(i + j > len) break;
            string str2;
            Rep(k, j) str2 += str1[i + k];
            mp[str2]++;
        }
    }

    for(auto iter = mp.begin(); iter != mp.end(); ++iter) vec.push_back((struct node){iter->second, iter->first});

    sort(vec.begin(), vec.end());
    
    int tmp = 0;
    int Num = 0;
    int printNum = 0;
    Rep(i, vec.size()) if(vec[i].num != tmp) {
        Num++;
        if(Num > N) break;
        if(i) printf("\n");
        printf("%d\n", vec[i].num);
        printNum = 1;
        cout << vec[i].str;
        tmp = vec[i].num;
    }
    else {
        if(0 != printNum && printNum % 6 == 0) printf("\n"); else printf(" ");
        cout << vec[i].str;
        printNum++;
    }
    
    printf("\n");
    return 0;
}
