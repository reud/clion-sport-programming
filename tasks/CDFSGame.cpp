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

// 損得表
using vpii = vector<pair<int,int>>;

class CDFSGame {
public:
    static void solve(std::istream& in, std::ostream& out) {
        int n; in >> n;
        vvi tree(n,vi());

        REP(i,n-1) {
            int p; in >> p;
            p--;
            tree[p].push_back(i+1);
        }

        // 部分木のサイズ、先手 - 後手の差

        // 部分木のサイズと損得を取得する。
        auto solve = [&](auto &&f,int watch) -> pair<int,int> {
            auto ret = 1;
            vi kisu_hands;
            vi bad_hands;
            bool kote = true;
            int sz_sum = 1;
            for (const auto &c : tree[watch]) {
                auto [sz, adv] = f(f,c);
                sz_sum += sz;
                if (sz % 2 == 0) {
                    // 後手が得するので後手で部分木のゲームを開始する。
                    if (adv <= 0) ret+=adv;
                    // 先手が得するのでやりたくない
                    else bad_hands.push_back(adv);
                } else {
                    // ターンが相手に回るのでやばい。一番小さい値をとっていく。
                    kisu_hands.push_back(adv);
                }
            }

            sort(ALL(kisu_hands));
            for (const auto &h: kisu_hands) {
                if (kote) ret+=h;
                else ret-=h;
                kote = !kote;
            }

            if (kote) ret += accumulate(ALL(bad_hands),0);
            else ret -= accumulate(ALL(bad_hands),0);

            return make_pair(sz_sum,ret);
        };

        auto [ret,ans] = solve(solve,0);
        // 2x + ans = n
        // x = (n - ans)/2
        // x + ans = n/2 + ans/2
        out << (n+ans)/2<< endl;

	}
};
