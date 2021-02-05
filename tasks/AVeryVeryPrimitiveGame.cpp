#include <bits/stdc++.h>
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

class AVeryVeryPrimitiveGame {
public:
	void solve(std::istream& in, std::ostream& out) {
        int A,B,C; in >> A >> B >> C;
        bool is_aoki_turn = C;
        while (true) {
            if (is_aoki_turn && B == 0) {
                out << "Takahashi" << endl;
                return;
            } else if (!is_aoki_turn && A == 0) {
                out << "Aoki" << endl;
                return;
            }
            if (is_aoki_turn) B--;
            if (!is_aoki_turn) A--;
            is_aoki_turn = !is_aoki_turn;
        }
	}
};
