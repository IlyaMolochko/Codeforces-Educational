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
    string s;
    int len = 0;
    int mx = 0;
    int cnt;
    while (len < n){
        cin >> s;
        cnt = 0;
        for (auto c : s){
            if (c >= 'A' and c <= 'Z'){
                ++cnt;
            }
        }
        mx = max(mx, cnt);
        len += s.size();
        if (len < n){
            ++len;
        }
    }
    cout << mx << '\n';
    return 0;
}

/*
*/
