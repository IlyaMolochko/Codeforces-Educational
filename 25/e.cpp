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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>());
    vector<int> d(n);
    int u, v;
    for (int i = 0; i < m; ++i){
        cin >> u >> v;
        --u;
        --v;
        g[v].push_back(u);
        ++d[u];
    }
    set<int> st;
    for (int i = 0; i < n; ++i){
        if (d[i] == 0){
            st.insert(-i);
        }
    }
    vector<int> stack;
    while (!st.empty()){
        u = -*st.begin();
        st.erase(st.begin());
        stack.push_back(u);
        for (auto vert : g[u]){
            --d[vert];
            if (d[vert] == 0){
                st.insert(-vert);
            }
        }
    }
    vector<int> answ(n);
    int val = 1;
    while (!stack.empty()){
        u = stack.back();
        stack.pop_back();
        answ[u] = val++;
    }
    for (auto &i : answ){
        cout << i << ' ';
    }
    return 0;
}

/*
*/
