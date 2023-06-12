#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, a;
vector<int> vec;

bool inRange(int x) {
    int low = 0, high = n-1;
    return (low <= x && x <= high);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> a;
    a--;
    vec = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    int count = 0;
    if (vec[a] == 1)
        count++;
    for (int i = 1; i < n; ++i) {
        if (inRange(a - i) && inRange(a + i)){
            if (vec[a + i] + vec[a - i] > 1)
                count += 2;
        }
        else if (!inRange(a - i) && inRange(a + i)){
            if (vec[a + i] == 1)
                count++;
        }
        else if (inRange(a - i) && !inRange(a + i)){
            if (vec[a - i] == 1)
                count++;
        }
    }
    cout << count;
}
