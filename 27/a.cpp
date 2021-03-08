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
    int n;
    cin >> n;
    vector<int> v(2 * n);
    for (auto &i : v){
        cin >> i;
    }
    sort(v.begin(), v.end());
    if (lower_bound(v.begin(), v.end(), v[n]) - v.begin() < n){
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }
    return 0;
}

/*
*/
