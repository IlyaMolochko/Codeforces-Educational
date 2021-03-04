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


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::default_random_engine generator;
    generator.seed(time(nullptr));
    std::uniform_int_distribution<int> dist1(-100000,100000);
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    vector<pair<int, int>> a;
    a.reserve(n);
    ll item;
    int cnt1, cnt2;
    vector<vector<int>> d(k + 1, vector<int>((k + 1) * 27, -1));
    d[0][0] = 0;
    for (int i = 0; i < n; ++i){
        cin >> item;
        cnt1 = 0;
        cnt2 = 0;
        while (item % 2 == 0){
            ++cnt1;
            item /= 2;
        }
        while (item % 5 == 0){
            ++cnt2;
            item /= 5;
        }
        a.emplace_back(cnt1, cnt2);
    }
    for (int i = 0; i < n; ++i){
        for (int j = k - 1; j >= 0; --j){
            for (int t = (k + 1) * 27 - a[i].second - 1; t >= 0; --t){
                if (d[j][t] >= 0){
                    d[j + 1][t + a[i].second] = max(d[j + 1][t + a[i].second], d[j][t] + a[i].first);
                }
            }
        }
    }
    int answ = 0;
    for (int i = 0; i < (k + 1) * 27; ++i){
        answ = max(answ, min(i, d[k][i]));
    }
    cout << answ << '\n';
    return 0;
}

/*
*/
