#include <bits/stdc++.h>

using namespace std;

int a, b;
vector<int> ans;

bool isPrime(int x) {
    int tmp = sqrt(1.0 * x) + 0.5;
    for(int i = 2; i <= tmp; ++i) if(x%i == 0) return false;
    return true;
}

void getAns(int a, int b) {
    for(int d1 = 1; d1 <= 9; d1 += 2) {
        int tmp = d1;
        if(tmp >= a && tmp <= b && isPrime(tmp)) ans.push_back(tmp);
        tmp = d1 * 10 + d1;
        if(tmp >= a && tmp <= b && isPrime(tmp)) ans.push_back(tmp);
    }

    for(int d1 = 1; d1 <= 9; d1 += 2) {
        for(int d2 = 0; d2 <= 9; ++d2) {
            int tmp = d1 * 100 + d2 * 10 + d1;
            if(tmp >= a && tmp <= b && isPrime(tmp)) ans.push_back(tmp);
            tmp = d1 * 1000 + d2 * 100 + d2 * 10 + d1;
            if(tmp >= a && tmp <= b && isPrime(tmp)) ans.push_back(tmp);
        }
    }

    for(int d1 = 1; d1 <= 9; d1 += 2) {
        for(int d2 = 0; d2 <= 9; ++d2) {
            for(int d3 = 0; d3 <= 9; ++d3) {
                int tmp = d1 * 10000 + d2 * 1000 + d3 * 100 + d2 * 10 + d1;
                if(tmp >= a && tmp <= b && isPrime(tmp)) ans.push_back(tmp);
                tmp = d1 * 1e5 + d2 * 1e4 + d3 * 1e3 + d3 * 100 + d2 * 10 + d1;
                if(tmp >= a && tmp <= b && isPrime(tmp)) ans.push_back(tmp);
            }
        }
    }

    for(int d1 = 1; d1 <= 9; d1 += 2) {
        for(int d2 = 0; d2 <= 9; ++d2) {
            for(int d3 = 0; d3 <= 9; ++d3) {
                for(int d4 = 0; d4 <= 9; ++d4) {
                    int tmp = d1 * 1e6 + d2 * 1e5 + d3 * 1e4 + d4 * 1e3 + d3 * 100 + d2 * 10 + d1;
                    if(tmp >= a && tmp <= b && isPrime(tmp)) ans.push_back(tmp);
                    tmp = d1 * 1e7 + d2 * 1e6 + d3 * 1e5 + d4 * 1e4 + d4 * 1e3 + d3 * 100 + d2 * 10 + d1;
                    if(tmp >= a && tmp <= b && isPrime(tmp)) ans.push_back(tmp);
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &a, &b);

    getAns(a, b);
    
    sort(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); ++i) printf("%d\n", ans[i]);
    return 0;
}
