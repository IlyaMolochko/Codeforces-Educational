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
    int s1 = 0, s2 = 0;
    char c;
    vector<int> a(3), b(3);
    for (auto &i : a){
        cin >> c;
        i = c - '0';
        s1 += i;
    }
    for (auto &i : b){
        cin >> c;
        i = c - '0';
        s2 += i;
    }
    int cnt = 0;
    if (s1 == s2){
        cout << 0 << '\n';
        return 0;
    }
    if (s1 < s2){
        swap(s1, s2);
        swap(a, b);
    }
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    int dif = s1 - s2;
    int d1, d2;
    cnt = 0;
    while (cnt < 3 and dif != 0){
        d1 = min(dif, a[i]);
        d2 = min(dif, 9 - b[j]);
        if (d2 > d1){
            dif -= d2;
            ++j;
        } else {
            dif -= d1;
            ++i;
        }
        ++cnt;
    }
    cout << cnt << '\n';
    return 0;
}
