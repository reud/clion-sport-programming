#include <bits/stdc++.h>
#include "../library/atcoder"
#include "../library/lib.hpp"

#define INF 1e9
#define INFLL 1ull<<60u
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pair<int,int>>;

class FShiftAndInversions {
public:
	static void solve(std::istream& in, std::ostream& out) {
	    int N; in >> N;
	    vector<int> a(N); REP(i,N) in >> a[i];
	    auto [tree,inversions] = calcInversions(a);
	    out << inversions << endl;
	    REP(i,N-1) {
	        // 先頭の要素を削除する事による転倒数の減少
	        inversions -= a[i];
	        // 末尾に追加する事による転倒数の増加
	        inversions += N - 1 - a[i];
	        out << inversions << endl;
	    }

	}
};
