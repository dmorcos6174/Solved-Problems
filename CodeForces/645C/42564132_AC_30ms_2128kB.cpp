#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, k;
string hotel;
vector<int> cumm;

bool valid(int x){
    for (int i = n; i < n * 2; ++i) {
        if(hotel[i] == '1')
            continue;
        int count = cumm[i + x + 1] - cumm[i - x];
        if(count > k)
            return true;
    }
    return false;
}

int bs(int s, int e) {
    while (s < e) {
        int mid = (s + (e - s) / 2);
        if (valid(mid))
            e = mid;
        else
            s = mid + 1;
    }
    return s;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k >> hotel;
    string extension = hotel;
    replace(extension.begin(), extension.end(), '0', '1');
    hotel = extension + hotel + extension;

    cumm = vector<int>(n*3 +1);
    cumm[0] = 0;
    for (int i = 1; i < n*3 +1; ++i) {
        if(hotel[i-1] == '0')
            cumm[i] = cumm[i-1] + 1;
        else
            cumm[i] = cumm[i-1];
    }
    int ans = 0;
    ans = bs(0, n);
    cout << ans;
}