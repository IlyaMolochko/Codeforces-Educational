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
    vector<int> v(n);
    for (auto &i : v){
        cin >> i;
    }
    sort(v.begin(), v.end());
    int answ = 0;
    for (int i = 0; i < n; ++i){
        while (v[i] > 2 * k){
            ++answ;
            k *= 2;
        }
        k = max(k, v[i]);
    }
    cout << answ << '\n';
    return 0;
}

/*
*/


