#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// Seems like a DSU problem.
class Solution {
private:
    vector<int> p;
    vector<int> sz;
    ll n;
    vector<ll> E;
    map<ll, vector<ll>> idx;

    int get_parent(int x) {
        return p[x] == x ? x : (p[x] = get_parent(p[x]));
    }

    inline void union_set(int x, int y) {
        int px = get_parent(x);
        int py = get_parent(y);
        if (px == py) return;
        if (sz[px] < sz[py]) swap(px, py);
        sz[px] += sz[py];
        p[py] = px;
    }

    inline ll encode(const string& s) {
        ll ret = 0;
        for (const auto x : s) {
            ll d = (x - 'a');
            ret |= (1LL << d);
        }
        return ret;
    }

    inline vector<ll> add_one(ll x) {
        vector<ll> ret;
        for (int i = 0; i < 26; ++i) {
            if ((x&(1LL << i)) == 0) {
                ret.push_back((x | (1LL << i)));
            }
        }
        return std::move(ret);
    }

    inline vector<ll> del_one(ll x) {
        vector<ll> ret;
        for (int i = 0; i < 26; ++i) {
            if ((x&(1LL << i)) != 0) {
                ret.push_back((x ^ (1LL << i)));
            }
        }
        return std::move(ret);
    }

    inline vector<ll> replace_one(ll x) {
        vector<ll> ret;
        vector<ll> pos, anti_pos;
        for (int i = 0; i < 26; ++i) {
            if ((x&(1LL << i)) != 0) {
                pos.push_back(i);
            } else {
                anti_pos.push_back(i);
            }
        }
        for (const auto pp : pos) {
            ll y = (x ^ (1LL << pp));
            for (const auto jj : anti_pos) {
                ret.push_back((y | (1LL << jj)));
            }
        }
        return std::move(ret);
    }

    inline void try_merge() {
        assert(E.size() == n);
        for (ll i = 0 ; i < E.size(); ++i) {
            vector<ll> A = add_one(E[i]);
            for (auto& a : A) {
                if(idx[a].empty() == false) {
                    union_set(i, idx[a][0]); // Just the first one is enough.
                }
            }
            vector<ll> B = del_one(E[i]);
            for (auto& b : B) {
                if(idx[b].empty() == false) {
                    union_set(i, idx[b][0]); // Just the first one is enough.
                }
            }
            vector<ll> R = replace_one(E[i]);
            for (auto& r : R) {
                if(idx[r].empty() == false) {
                    union_set(i, idx[r][0]); // Just the first one is enough.
                }
            }
        }
    }
public:
    vector<int> groupStrings(vector<string>& words) {
        n = words.size();
        p.resize(n + 1, 0);
        sz.resize(n + 1, 1);
        for (int i = 0;i < n; ++i) p[i] = i;
        E.clear();
        idx.clear();
        for (auto& s : words) {
            E.push_back(encode(s));
            idx[E.back()].push_back(E.size() - 1);
            if (idx[E.back()].size() > 1) {
                union_set(idx[E.back()][idx[E.back()].size() - 2]  ,  idx[E.back()].back());
            }
        }
        try_merge(); // Do all the merging.

        vector<bool> seen(n, false);
        int cnt = 0;
        int maxm = 0;
        for (int i = 0; i < n; ++i) {
            int prnt = get_parent(i);
            if (seen[prnt]) continue;
            seen[prnt] = true;
            maxm = max(maxm, sz[prnt]);
            cnt++;
        }
        return {cnt, maxm};
    }
};