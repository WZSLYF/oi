#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 700 + 10;
char str[maxn];
int lb[maxn], lr[maxn], rb[maxn], rr[maxn], n;

int main() {
	scanf("%d", &n);
	scanf("%s", str + 1);
	for(int i = n + 1; i <= 2 * n; ++i) str[i] = str[i - n];

	lb[0] = 0, lr[0] = 0;
	for(int i = 1; i <= 2 * n; ++i) {
		if(str[i] == 'r') lb[i] = 0, lr[i] = lr[i - 1] + 1;
		if(str[i] == 'b') lb[i] = lb[i - 1] + 1, lr[i] = 0;
		if(str[i] == 'w') lb[i] = lb[i - 1] + 1, lr[i] = lr[i - 1] + 1;
		//printf(" %d %d", lb[i], lr[i]);
	}
	//printf("\n");

	rb[2 * n + 1] = 0, rr[2 * n + 1] = 0;
	for(int i = 2 * n; i > 0; --i) {
		if(str[i] == 'r') rb[i] = 0, rr[i] = rr[i + 1] + 1;
		if(str[i] == 'b') rb[i] = rb[i + 1] + 1, rr[i] = 0;
		if(str[i] == 'w') rb[i] = rb[i + 1] + 1, rr[i] = rr[i + 1] + 1;
		//printf(" %d %d", rb[i], rr[i]);
	}
	//printf("\n");

	int res = 0;
	for(int i = 1; i < 2 * n; ++i) res = max(res, max(lb[i], lr[i]) + max(rb[i + 1], rr[i + 1]));
	res = min(res, n);
	printf("%d\n", res);
	return 0;
}
