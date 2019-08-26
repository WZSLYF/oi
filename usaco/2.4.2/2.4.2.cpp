#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
const int maxm = 250;
char str[maxm][maxn];
int W, H;
struct fence {
    int x, y, val;
};
queue<fence> que;
const int X[] = {-1, 0, 1, 0};
const int Y[] = {0, 1, 0, -1};
bool isVis[maxn][maxm];

void init() {
    for(int i = 1; i < 2*W + 1; i += 2) {
        if(str[0][i] == ' ') {
            fence a;
            a.x = 0;
            a.y = (i - 1) / 2;
            a.val = 1;
            isVis[a.x][a.y] = 1;
            que.push(a);
        }

        if(str[2*H][i] == ' ') {
            fence a;
            a.x = H - 1;
            a.y = (i - 1) / 2;
            a.val = 1;
            isVis[a.x][a.y] = 1;
            que.push(a);
        }
    } 

    for(int i = 1; i < 2*H + 1; i += 2) {
        if(str[i][0] == ' ') {
            fence a;
            a.x = (i - 1) / 2;
            a.y = 0;
            a.val = 1;
            isVis[a.x][a.y] = 1;
            que.push(a);
        }

        if(str[i][2*W] == ' ') {
            fence a;
            a.x = (i - 1) / 2;
            a.y = W - 1;
            a.val = 1;
            isVis[a.x][a.y] = 1;
            que.push(a);
        }
    }
}

bool judge(int x, int y) {
    if(x >= 0 && x < H && y >= 0 && y < W) return true;
    return false;
}

int main() {
    scanf("%d %d\n", &W, &H);
    //printf("%d\n", 2*H + 1);
    
    for(int i = 0; i < 2*H + 1; ++i) fgets(str[i], maxn, stdin);

    init();
    int ans = 0;
    while(!que.empty())
    {
        fence tmp = que.front();
        que.pop();

        ans = max(ans, tmp.val);

        if(str[2 * tmp.x][2 * tmp.y + 1] == ' ' && 
           judge(tmp.x + X[0], tmp.y + Y[0]) &&
           !isVis[tmp.x + X[0]][tmp.y + Y[0]]) {
            fence a;
            a.x = tmp.x + X[0];
            a.y = tmp.y + Y[0];
            a.val = tmp.val + 1;
            isVis[a.x][a.y] = 1;
            que.push(a);
        }

        if(str[2 * tmp.x + 1][2 * tmp.y + 2] == ' ' && 
           judge(tmp.x + X[1], tmp.y + Y[1]) &&
           !isVis[tmp.x + X[1]][tmp.y + Y[1]]) {
            fence a;
            a.x = tmp.x + X[1];
            a.y = tmp.y + Y[1];
            a.val = tmp.val + 1;
            isVis[a.x][a.y] = 1;
            que.push(a);
        }
	
    	if(str[2 * tmp.x + 2][2 * tmp.y + 1] == ' ' && 
           judge(tmp.x + X[2], tmp.y + Y[2]) &&
           !isVis[tmp.x + X[2]][tmp.y + Y[2]]) {
            fence a;
            a.x = tmp.x + X[2];
            a.y = tmp.y + Y[2];
            a.val = tmp.val + 1;
            isVis[a.x][a.y] = 1;
            que.push(a);
        }

        if(str[2 * tmp.x + 1][2 * tmp.y] == ' ' && 
           judge(tmp.x + X[3], tmp.y + Y[3]) &&
           !isVis[tmp.x + X[3]][tmp.y + Y[3]]) {
            fence a;
            a.x = tmp.x + X[3];
            a.y = tmp.y + Y[3];
            a.val = tmp.val + 1;
            isVis[a.x][a.y] = 1;
            que.push(a);
        }
    }

    printf("%d\n", ans);
    return 0;
}
