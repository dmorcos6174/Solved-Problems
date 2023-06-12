#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6;
bool notprime[N + 5];
vector<int> primes;
void seive(){
    notprime[0] = notprime[1] = 1;
    for(int i=1; i<=N/i; i++){
        if(notprime[i])
            continue;
        for(int j=i*i; j<=N; j+=i)
            notprime[j] = 1;
    }
    for(int i=2; i<=N; i++)
        if(!notprime[i])
            primes.push_back(i);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    seive();
    ll t;
    cin >> t;
    ll test = 1;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> vec(n);
        for (ll i = 0; i < n; ++i) {
            cin >> vec[i];
        }
        set<ll> primefactors;
        for (int i = 0; i < n; ++i) {
            for(int j=0; j<primes.size(); ++j)
            {
                while(vec[i]%primes[j]==0)
                {
                    primefactors.insert(primes[j]);
                    vec[i]/=primes[j];
                }
                if(vec[i]<=1) break;
            }
            if(vec[i]!=1)primefactors.insert(vec[i]);
        }
        cout << "Case #" << test++ << ": " << primefactors.size() << "\n";
        for (auto it : primefactors) {
            cout << it << "\n";
        }
    }
}