/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: d.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2022年08月13日 星期六 10时57分32秒
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

#if __cplusplus >= 201703L
    #define REGISTER 
    #define null  nullptr
#elif __cplusplus >= 201103L
    #define REGISTER register
    #define null  nullptr
#elif __cplusplus >= 199711L
    #define REGISTER register
    #define null  NULL
#endif

/* #pragma GCC target("avx2") */
/* #pragma GCC optimize("Ofast") */
/* #pragma GCC optimize("unroll-loops") */
#define likely(x) __builtin_expect(x, 1)
#define unlikely(x) __builtin_expect(x, 0)
#define All(x) x.begin(), x.end()
#define Rep(x, a, b) for(REGISTER int x = a; x <= b; ++x)
#define Resp(x, a, b) for(REGISTER int x = a; x >= b; --x)
#define rep(x, a, b) for(REGISTER int x = a; x < b; ++x)
#define resp(x, a, b) for(REGISTER int x = a; x > b; --x)
using LL = long long;
using pr = std::pair<int, int>;
template<typename T>
using vc = std::vector<T>;
template<typename T>
using vv = vc<vc<T>>;
constexpr int INF = INT_MAX;

template <typename T>
struct TPoint {
    T x, y;
    int id;

    TPoint() : x(0), y(0), id(-1) {}
    TPoint(const T& x_, const T& y_) : x(x_), y(y_), id(-1) {}
    TPoint(const T& x_, const T& y_, int id_) : x(x_), y(y_), id(id_) {}

    static constexpr T eps = static_cast<T>(1e-9);

    inline TPoint operator+(const TPoint& rhs) const { return TPoint(x + rhs.x, y + rhs.y); }
    inline TPoint operator-(const TPoint& rhs) const { return TPoint(x - rhs.x, y - rhs.y); }
    inline TPoint operator*(const T& rhs) const { return TPoint(x * rhs, y * rhs); }
    inline TPoint operator/(const T& rhs) const { return TPoint(x / rhs, y / rhs); }

    friend T smul(const TPoint& a, const TPoint& b) {
        return a.x * b.x + a.y * b.y;
    }

    friend T vmul(const TPoint& a, const TPoint& b) {
        return a.x * b.y - a.y * b.y;
    }

    inline T abs2() const {
        return x * x + y * y;
    }

    inline bool operator<(const TPoint& rhs) const {
        return (y < rhs.y || (y == rhs.y && x < rhs.x));
    }

    inline bool is_upper() const {
        return (y > eps || abs(y) <= eps && x > eps);
    }

    inline int cmp_polar(const TPoint& rhs) const {
        assert(abs(x) > eps || abs(y) > eps);
        assert(abs(rhs.x) > eps || abs(rhs.y) > eps);
        bool a = is_upper();
        bool b = rhs.is_upper();
        if (a != b) {
            return (a ? -1 : 1);
        }

        long long v = x * rhs.y - rhs.x * y;
        return (v > eps ? -1 : (v < -eps ? 1 : 0));
    }
};

class dsu {
public:
    vc<int> f;
    int n;

    dsu(int _n) : n(_n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
    }

    inline int get(int x) {
        return (x == f[x] ? x : (f[x] = get(f[x])));
    }

    inline bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x != y) {
            f[x] = y;
            return true;
        }
        return false;
    }
};

using Point = TPoint<long long>;

int main()
{
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
    std::cin.tie(null);
    /* std::cout.tie(null); */
#endif
    int n;
    Point s, t;
    std::cin >> n >> s.x >> s.y >> t.x >> t.y;
    vc<Point> p(n);
    vc<LL> r(n);
    rep(i, 0, n) std::cin >> p[i].x >> p[i].y >> r[i];
    dsu d(n);

    auto sqr = [](LL x) {
        return x * x;
    };

    rep(i, 0, n) rep(j, i + 1, n) {
        LL dist = (p[i] - p[j]).abs2();
        if (dist > (sqr(r[i] + r[j]))) continue;
        if (dist < (sqr(r[i] - r[j]))) continue;
        d.unite(i, j);
    }

    rep(i, 0, n) if ((p[i] - s).abs2() == sqr(r[i])) {
        rep(j, 0, n) if ((p[j] - t).abs2() == sqr(r[j])) {
            if (d.get(i) == d.get(j)) {
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "No" << std::endl;
    return 0;
}

