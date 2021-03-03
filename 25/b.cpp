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

bool check_row(vector<string> &m, int i, int j){
    int cnt1 = 0;
    int cnt2 = 0;
    for (int k = 0; k < 5; ++k){
        if (m[i][j + k] == 'X'){
            ++cnt1;
        } else if (m[i][j + k] == '.'){
            ++cnt2;
        }
    }
    return cnt1 == 4 and cnt2 == 1;
}

bool check_column(vector<string> &m, int i, int j){
    int cnt1 = 0;
    int cnt2 = 0;
    for (int k = 0; k < 5; ++k){
        if (m[i + k][j] == 'X'){
            ++cnt1;
        } else if (m[i + k][j] == '.'){
            ++cnt2;
        }
    }
    return cnt1 == 4 and cnt2 == 1;
}

bool check(vector<string> &m, int i, int j, int x){
    int cnt1 = 0;
    int cnt2 = 0;
    for (int k = 0; k < 5; ++k){
        if (m[i + k][j + k * x] == 'X'){
            ++cnt1;
        } else if (m[i + k][j + k * x] == '.'){
            ++cnt2;
        }
    }
    return cnt1 == 4 and cnt2 == 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::default_random_engine generator;
    generator.seed(time(nullptr));
    std::uniform_int_distribution<int> dist1(-100000,100000);
    vector<string> m(10);
    for (auto &i : m){
        cin >> i;
    }
    bool answ = false;
    for (int i = 0; i < 10 and !answ; ++i){
        for (int j = 0; j < 10 and !answ; ++j){
            if (j <= 5){
                answ |= check_row(m, i, j);
            }
            if (i <= 5){
                answ |= check_column(m, i, j);
            }
            if (i <= 5 and j <= 5){
                answ |= check(m, i, j, 1);
            }
            if (i <= 5 and j >= 4){
                answ |= check(m, i, j, -1);
            }
        }
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
