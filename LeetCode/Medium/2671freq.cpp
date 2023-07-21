#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef set<ll> sll;

class FrequencyTracker {
public:
    FrequencyTracker() {
        cnt.clear();
        rev_cnt.clear();
    }
    
    void add(int number) {
        if (cnt[number] > 0) {
            rev_cnt[cnt[number]].erase(number);
        }
        cnt[number]++;
        rev_cnt[cnt[number]].insert(number);
    }
    
    void deleteOne(int number) {
        if (cnt[number] == 0) return;
        rev_cnt[cnt[number]].erase(number);
        cnt[number]--;
        if (cnt[number] > 0) {
            rev_cnt[cnt[number]].insert(number);
        }
    }
    
    bool hasFrequency(int frequency) {
        return (!rev_cnt[frequency].empty());
    }
private:
map<ll, ll> cnt;
map<ll, sll> rev_cnt;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */