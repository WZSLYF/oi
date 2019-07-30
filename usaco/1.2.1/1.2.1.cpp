#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 5000 + 10;

#define gt() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, maxn, stdin), p1 == p2) ? EOF : *p1++)

struct farmer {
	int S, E;
	inline bool operator<(const farmer& b) const { return S < b.S;}
}dat[maxn];
static char buf[maxn], *p1 = buf, *p2 = buf;
int n;

int read() {
	int ret = 0;
	char ch = gt();
	while(ch < '0' || ch > '9') ch = gt();
	while(ch >= '0' && ch <= '9') ret = (ret << 3) + (ret << 1) + ch - '0', ch = gt();
	return ret;
}

int main() {
	n = read();
	for(int i = 0; i < n; ++i) dat[i] = (farmer){read(), read()};
	
	sort(dat, dat + n);

	int res1 = 0, res2 = 0;
	//res2 = max(res2, dat[0].S);
	int S = dat[0].S, E = dat[0].E;
	for(int i = 1; i < n; ++i) {
		if(dat[i].S <= E) E = max(E, dat[i].E);
		else res1 = max(res1, E - S), res2 = max(res2, dat[i].S - E), S = dat[i].S, E = dat[i].E;
	}
	
	res1 = max(res1, E - S);
	printf("%d %d\n", res1, res2);
	return 0;
}

