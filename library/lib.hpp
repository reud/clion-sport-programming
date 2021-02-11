#include <bits/stdc++.h>
#include "./fenwicktree"

// BITを用いて数列vの転倒数を求める。O(NlogN)返り値は(BIT,転倒数) 0~N-1の数列を入力する。
std::pair<atcoder::fenwick_tree<long long>,long long> calcInversions(const std::vector<int> &v) {
    atcoder::fenwick_tree<long long> BIT(v.size());
    long long inversions = 0;
    for(const auto &it: v) {
        BIT.add(it,1);
        inversions += (long long)it - BIT.sum(0,it);
    }
    return std::make_pair(BIT,inversions);
}

int getTheAnswer() {
    return 42;
}


