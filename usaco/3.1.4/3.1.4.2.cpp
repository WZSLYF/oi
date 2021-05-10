#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int A, B, N;

string tarStr, temStr;

struct stat {
    int num;
    string str;
    stat(int _num, string _str) {
        num = _num;
        str = _str;
    }

    bool operator < (const stat& b) const {
        if(num == b.num) {
            if(str.size() == b.str.size()) return str < b.str;
            else return str.size() < b.str.size();
        }
        else return num > b.num;
    }
};

vector<stat> ans;

struct Trie {
    int nxt[maxn][2], cnt;
    int Num[maxn];
    bool exist[maxn];

    void insert(string str) {
        int len = strlen(str.c_str());
        int p = 0;
        for(int i = 0; i < len; ++i) {
            int c = str[i] - '0';
            if(!nxt[p][c]) nxt[p][c] = ++cnt;
            p = nxt[p][c];
            if(i + 1 >= A) Num[p]++;
        }
        exist[p] = 1;
    }

    void calc(int p, int depth, string str) {
        if(depth >= A && depth <= B) {
            stat s(Num[p], str);
            ans.push_back(s);
        }
        //if(exist[p]) return;
        if (nxt[p][0]) calc(nxt[p][0], depth + 1, str + '0');
        if (nxt[p][1]) calc(nxt[p][1], depth + 1, str + '1');
    }
};

int main() {
    cin >> A >> B >> N;
    while(cin >> temStr) tarStr += temStr;
    int len = strlen(tarStr.c_str());
    //cout << tarStr << endl;
    Trie trie;
    for(int i = 0; i + A - 1 < len; ++i) {
        string tmpStr;
        for(int j = 0; j < B && i + j - 1 < len; ++j) tmpStr += tarStr[i + j];
        trie.insert(tmpStr);
    }

    trie.calc(0, 0, "");

    sort(ans.begin(), ans.end());

    int tmp = 0;
    int Num = 0;
    int printNum = 0;
    for(int i = 0; i < ans.size(); ++i) if(ans[i].num != tmp) {
        Num++;
        if(Num > N) break;
        if(i) printf("\n");
        printf("%d\n", ans[i].num);
        printNum = 1;
        cout << ans[i].str;
        tmp = ans[i].num;
    }
    else {
        if(0 != printNum && printNum % 6 == 0) printf("\n"); else printf(" ");
        cout << ans[i].str;
        printNum++;
    }
    printf("\n");

    return 0;
}
