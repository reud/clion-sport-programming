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

class CDigitalGraffiti {
public:
    static void solve(std::istream& in, std::ostream& out) {
        int H,W; in >> H >> W;
        vector<string> field(H);
        REP(i,H) in >> field[i];

        int vx[4] = {0,0,-1,-1};
        int vy[4] = {0,-1,0,-1};

        int ans = 0;
        FOR(h,1,H) FOR(w,1,W) {
            int cnt = 0;
            REP(i,4) if(field[h+vy[i]][w+vx[i]] == '#') cnt++;
            if(cnt == 1 || cnt == 3) ans++;
        }

        out << ans << endl;

	}
};
