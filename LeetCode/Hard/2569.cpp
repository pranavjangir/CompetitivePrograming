#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
// Is this a lazy propagation problem?
// lol? On LeetCode?

template<typename T>
class SegTree {
private:
inline T left(T x) {
    return (x << 1);
}
inline T right(T x) {
    return (x << 1) + 1;
}

void build(ll id, ll l, ll r, const vector<T>& b) {
    if (l == r) {
        tree[id] = b[l - 1];
        return;
    }
    ll mid = (l + r) >> 1;
    build(left(id), l, mid, b);
    build(right(id), mid + 1, r, b);
    tree[id] = tree[left(id)] + tree[right(id)];
}

public:

SegTree(T N, const vector<T>& b) {
    n = N;
    tree.resize(4 * N);
    build(1, 1, n, b);
}

void update(T id, T l, T r, T x, T y) {
    if (x > r || y < l || r < l || y < x) {
        return;
    }
    if (l >= x && r <= y) { // completely inside.
        tree[id] = r - l + 1 - tree[id];
        return;
    }
    T mid = (l + r) >> 1;
    if (x > mid) {
        update(right(id), mid + 1, r, x, y);
    } else if (y < mid) {
        update(left(id), l, mid, x, y);
    } else {
        update(left(id), l , mid, x, mid);
        update(right(id), mid + 1, r, mid+1, y);
    }

    tree[id] = tree[left(id)] + tree[right(id)];
}

T getSum() const {
    return tree[1];
}
private:
T n;
vector<T> tree;
};


class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        ll n = nums1.size();
        assert(n == nums2.size());
        ll q = queries.size();
        SegTree<int> S(n, nums1);
        // cout << S.getSum() << endl;
        ll sum = 0;
        for (auto x : nums2) sum += x;
        vector<ll> ret;
        for (auto qq : queries) {
            // serve one query.
            ll type = qq[0];
            ll L = qq[1];
            ll R = qq[2];
            if (type == 3) {
                ret.push_back(sum);
            } else if (type == 2) {
                sum += L * S.getSum();
            } else {
                S.update(1, 1, n, L + 1, R + 1);
                // cout << S.getSum() << endl;
            }
        }
        return ret;
    }
};