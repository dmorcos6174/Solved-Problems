#include<bits/stdc++.h>
using namespace std;

vector<int> cities, towers;

bool valid(long long r){
    vector<bool> covered(cities.size(),false);
    int i = 0, j = 0;
    int n = cities.size(), m = towers.size();
    while(i < n && j < m){
        long long pos = towers[j] + r;
        long long neg = towers[j] - r;
        if(cities[i] <= pos && cities[i] >= neg){
            covered[i] = true;
            i++;
        }
        else
            j++;
    }
    if(find(begin(covered), end(covered), false) == end(covered))
        return true;
    else
        return false;
}

long long bs(long long s, long long e){
    while(s < e){
        long long mid = s + (e-s)/2;
        if (valid(mid))
            e = mid;
        else
            s = mid + 1;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int city;
        cin >> city;
        cities.push_back(city);
    }
    for (int i = 0; i < m; ++i) {
        int tower;
        cin >> tower;
        towers.push_back(tower);
    }
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distr(0, 2e9+5);
    int r = distr(generator);
    cout << bs(0 , 2e9+5);
}