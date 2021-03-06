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

class DBinomialCoefficients {
public:
    static void solve(std::istream& in, std::ostream& out) {
        int n; in >> n;
        vector<int> a(n); REP(i,n) in >> a[i];
        sort(ALL(a));
        auto target = (a[a.size()-1]+1)/2;
        auto itr = lower_bound(ALL(a),target);
        // not found.
        if (*itr == a[a.size()-1]) {
            itr--;
            out << a[a.size()-1] << " " << *itr << endl;
            return;
        }

        auto latter = abs(*itr - target);
        if (itr == a.begin()) {
            out << a[a.size()-1] << " " << *itr << endl;
            return;
        }
        itr--;
        auto former = abs(target - *itr);
        if (former < latter) {
            out << a[a.size()-1] << " " << *itr << endl;
        } else {
            itr++;
            out << a[a.size()-1] << " " << *itr << endl;
        }
	}
};
