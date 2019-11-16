#include <bits/stdc++.h>

using namespace std;

#define Rep(i, n) for(int i = 0; i < n; ++i)

const int maxn = 110;
int dat[maxn], K, N;
struct humNum {
    long long val, ind, num;
    //bool operator < (const humNum& b) const { return val * dat[ind] < b.val * dat[b.ind]; }
};

struct cmp {
    bool operator()(const humNum& a, const humNum& b) const {
        return a.val * a.num > b.val * b.num;
    }
};
//vector<humNum> ans;
priority_queue<humNum, vector<humNum>, cmp> que;

int main() {
    scanf("%d %d", &K, &N);

    Rep(i, K) scanf("%d", &dat[i]);
    
    que.push((struct humNum){1, 0, dat[0]});
    //ans.push_back((struct humNum){1, 0});
    long long tmp = 1;
    int j = 0;
	while(1) {
        humNum p = que.top();
        que.pop();
        if(p.val * dat[p.ind] > tmp) {
            humNum q;
            q.val = p.val * dat[p.ind];
            q.ind = 0;
            q.num = dat[0];
            que.push(q);
            tmp = q.val;
            j++;
        }
        p.ind++;
        //while(p.ind < K && p.val * dat[p.val] <= q.val) p.ind++;
        if(p.ind < K) p.num = dat[p.ind], que.push(p);
	    if(j == N) { 
            printf("%lld\n", tmp); break; 
        }
    }
    return 0;
}

