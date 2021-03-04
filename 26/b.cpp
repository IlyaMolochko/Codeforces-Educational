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

int get_w(vector<string> &v, int i, int j){
    int w = 1;
    while (j + 1 < v[i].size() and v[i][j] == v[i][j + 1]){
        ++j;
        ++w;
    }
    return w;
}

int get_h(vector<string> &v, int i, int j){
    int h = 1;
    while (i + 1 < v.size() and v[i + 1][j] == v[i][j]){
        ++i;
        ++h;
    }
    return h;
}

bool check(vector<string> &v, int r, int c, int h, int w){
    char ch = v[r][c];
    for (int i = r; i < r + h; ++i){
        for (int j = c; j < c + w; ++j){
            if (v[i][j] != ch){
                return false;
            }
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
    int n, m;
    cin >> n >> m;
    if (n % 3 != 0 and m % 3 != 0){
        cout << "NO" << '\n';
        return 0;
    }
    vector<string> v;
    v.reserve(n);
    string s;
    for (int i = 0; i < n; ++i){
        cin >> s;
        v.push_back(move(s));
    }
    int h, w, hight, width;
    int sh = 0, sw = 0;
    h = get_h(v, 0, 0);
    w = get_w(v, 0, 0);
    if (h != n and w != m or (h == n and 3 * w != m) or (w == m and 3 * h != n)){
        cout << "NO" << '\n';
        return 0;
    }
    bool answ = true;
    if (h == n){
        answ &= check(v, 0, 0, h, w);
        answ &= check(v, 0, w, h, w);
        answ &= check(v, 0, 2 * w, h, w);
        answ &= (v[0][0] != v[0][w] and v[0][0] != v[0][2 * w] and v[0][w] != v[0][2 * w]);
    } else {
        answ &= check(v, 0, 0, h, w);
        answ &= check(v, h, 0, h, w);
        answ &= check(v, 2 * h, 0, h, w);
        answ &= (v[0][0] != v[h][0] and v[0][0] != v[2 * h][0] and v[h][0] != v[2 * h][0]);
    }
    if (answ){
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}

/*
*/
