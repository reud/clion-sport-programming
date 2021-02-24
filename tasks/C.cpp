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

class C {
public:
    static void solve(std::istream& in, std::ostream& out) {
        string S; in >> S;
        string w1 = "dream";
        string w2 = "dreamer";
        string w3 = "erase";
        string w4 = "eraser";
        reverse(ALL(w1));
        reverse(ALL(w2));
        reverse(ALL(w3));
        reverse(ALL(w4));
        reverse(ALL(S));

        string now;
        for(const auto &c: S) {
            now.push_back(c);
            if (now.size() == 5) {
                if (now == w1 || now == w3) {
                    now = string();
                }
            } else if (now.size() == 6) {
                if (now == w4) {
                    now = string();
                }
            } else if (now.size() == 7) {
                if (now == w2) {
                    now = string();
                } else {
                    out << "NO" << endl;
                    return;
                }
            }
        }
        if (now.empty()) {
            out << "YES" << endl;
        } else {
            out << "NO" << endl;
        }


    }
};
