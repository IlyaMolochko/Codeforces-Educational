#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <random>

using namespace std;
typedef long long ll;

bool check(unordered_map<char, int> &ms, unordered_map<char, int> &mt, int m){
    int cnt = ms['?'];
    for (auto t : mt){
        if (t.second * m > cnt + ms[t.first]){
            return false;
        } else {
            cnt -= max((t.second * m - ms[t.first]), 0);
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::default_random_engine generator;
    generator.seed(time(nullptr));
    std::uniform_int_distribution<int> dist1(-100000,100000);
    string s, t;
    cin >> s >> t;
    if (t.size() > s.size()){
        for (auto c : s){
            if (c == '?'){
                cout << 'a';
            } else {
                cout << c;
            }
        }
        return 0;
    }
    unordered_map<char, int> ms, mt;
    for (auto c : s){
        ++ms[c];
    }
    for (auto c : t){
        ++mt[c];
    }
    int answ = 0, l = 0, r = s.size() / t.size(), m;
    while (l <= r){
        m = (l + r) / 2;
        if (check(ms, mt, m)){
            answ = m;
            l = m + (l == m);
        } else {
            r = m - 1;
        }
    }
    if (answ > 0){
        int cnt = ms['?'];
        queue<pair<char, int>> q;
        for (auto p : mt){
            if (p.second * answ > ms[p.first]){
                q.push({p.first, p.second * answ - ms[p.first]});
                cnt -= (p.second * answ - ms[p.first]);
            }
        }
        for (auto c : s){
            if (c == '?' and !q.empty()){
                cout << q.front().first;
                --q.front().second;
                if (q.front().second == 0){
                    q.pop();
                }
            } else if (c == '?'){
                cout << 'a';
            } else {
                cout << c;
            }
        }
        return 0;
    }
    for (auto c : s){
        if (c == '?'){
            cout << 'a';
        } else {
            cout << c;
        }
    }
    return 0;
}

/*
*/
