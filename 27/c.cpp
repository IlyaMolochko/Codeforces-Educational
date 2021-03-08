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

struct st{
    int l;
    int r;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::default_random_engine generator;
    generator.seed(time(nullptr));
    std::uniform_int_distribution<int> dist1(-100000,100000);
    int n;
    cin >> n;
    vector<st> v(n);
    for (auto &i : v){
        cin >> i.l >> i.r;
    }
    sort(v.begin(), v.end(), [](st s1, st s2){
        if (s1.l == s2.l){
            return s1.r < s2.r;
        }
        return s1.l < s2.l;
    });
    int t1 = -1, t2 = -1;
    bool answ = true;
    for (int i = 0; i < n and answ; ++i){
        if (v[i].l > t1){
            t1 = v[i].r;
        } else if (v[i].l > t2){
            t2 = v[i].r;
        } else {
            answ = false;
        }
    }
    if (answ){
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}
