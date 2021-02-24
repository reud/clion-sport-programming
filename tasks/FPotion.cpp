#include <bits/stdc++.h>
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

using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vpii = vector<pair<int,int>>;

class FPotion {
public:
    static void solve(std::istream& in, std::ostream& out) {
        int N; ll X; in >> N >> X;
        vector<ll> A(N); REP(i,N) in >> A[i];


        // iまで見て、j個選んで、mod cにおいて値がkになる様な値X = max(X)
        vector<ll> answers(N);
        FOR(c,1,N+1) {
            vvvi dp(N+1,vvi(c+2,vi(c,-INFLL)));
            dp[0][0][0] = 0;
            FOR(i,1,N+1) {
                FOR(j,1,c+1) {
                    // 選ばない
                    // 選ぶ
                    REP(k,c) {
                        chmax(dp[i][j][k],dp[i-1][j][k]);
                        chmax(dp[i][j][(k+A[i-1])%c],dp[i-1][j-1][k] + A[i-1]);
                    }
                }
            }

            answers[c-1] = dp[N][c][X%c];
        }

        ll ans  = INFLL;

        FOR(i,1,N+1) if(answers[i-1] >= 0) chmin(ans,(X - answers[i-1])/i);
        out << ans << endl;
	}
};
