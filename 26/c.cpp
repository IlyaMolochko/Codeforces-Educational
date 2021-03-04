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



bool check(vector<vector<int>> &v, vector<int> &p, int i, int j){
    for (int k = 0; k < 2; ++k){
        for (int q = 0; q < 2; ++q){
            for (int t = 0; t < 2; ++t){
                if (max(v[i][k], v[j][q]) <= p[t] and v[i][1 - k] + v[j][1 - q] <= p[1 - t]){
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::default_random_engine generator;
    generator.seed(time(nullptr));
    std::uniform_int_distribution<int> dist1(-100000,100000);
    int n, a, b;
    cin >> n >> a >> b;
    int x, y;
    vector<vector<int>> v;
    vector<int> p = {a, b};
    for (int i = 0; i < n; ++i){
        cin >> x >> y;
        if (max(x, y) > max(a, b) or min(x, y) > min(a, b)){
            continue;
        }
        v.push_back({x, y});
    }
    int mx = 0;
    for (int i = 0; i < v.size(); ++i){
        for (int j = i + 1; j < v.size(); ++j){
            if (check(v, p, i, j)){
                mx = max(mx, v[i][0] * v[i][1] + v[j][0] * v[j][1]);
            }
        }
    }
    cout << mx << '\n';
    return 0;
}

/*
*/
