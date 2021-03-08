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
    int t;
    vector<int> sc = {300};
    vector<int> overtake = {1};
    int speed;
    int answ = 0;
    int s;
    while (n--){
        cin >> t;
        if (t == 1){
            cin >> speed;
            while (speed > sc.back()){
                sc.pop_back();
                ++answ;
            }
        } else if (t == 2){
            while (overtake.back() == 0){
                overtake.pop_back();
                ++answ;
            }
        } else if (t == 3){
            cin >> s;
            if (s < speed){
                ++answ;
            } else {
                sc.push_back(s);
            }
        } else if (t == 4){
            overtake.push_back(1);
        } else if (t == 5){
            sc.push_back(300);
        } else {
            overtake.push_back(0);
        }
    }
    cout << answ << '\n';
    return 0;
}
