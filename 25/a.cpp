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
    string s;
    cin >> n >> s;
    int cnt = 0;
    int answ = 0;
    for (int i = 0; i < n; ++i){
        cnt = 0;
        while (i < n and s[i] == '1'){
            ++i;
            ++cnt;
        }
        cout << cnt;
    }
    if (s.back() == '0'){
        cout << 0 << '\n';
    }
    return 0;
}
