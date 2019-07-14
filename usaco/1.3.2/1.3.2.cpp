#include <bits/stdc++.h>

using namespace std;

int M, S, C;
vector<int> vc1, vc2;

int main() {
    scanf("%d %d %d", &M, &S, &C);

    int a;
    for(int i = 0; i < C; ++i) scanf("%d", &a), vc1.push_back(a);

    if(M >= C) printf("%d\n", C);
    else {
        int sum = 0;
        sort(vc1.begin(), vc1.end());
        for(int i = 1; i < vc1.size(); ++i) vc2.push_back(vc1[i] - vc1[i-1]);
        sum = vc1[vc1.size()-1] - vc1[0] + 1;
        sort(vc2.begin(), vc2.end());
        for(int i = vc2.size() - 1; i >= 0 && M > 1; --i) sum -= vc2[i] - 1, --M;
        printf("%d\n", sum);
    }
    return 0;
}
