#include <bits/stdc++.h>
using namespace std;

const long long N = 2e7;
bool notprime[N + 5];
vector<long long> primes;
void seive(){
    notprime[0] = notprime[1] = 1;
    for(long long i=1; i<=N/i; i++){
        if(notprime[i])
            continue;
        for(long long j=i*i; j<=N; j+=i)
            notprime[j] = 1;
    }
    for(long long i=2; i<=N; i++)
        if(!notprime[i])
            primes.push_back(i);
}

vector<pair<long long, long long>> twinprimes;

void gentwinprimes(){
    for (long long i = 0; i < primes.size() - 1; ++i) {
        if(primes[i+1] - primes[i] == 2)
            twinprimes.emplace_back(primes[i], primes[i+1]);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    seive();
    gentwinprimes();
//    cout << primes.size() << endl;
//    cout << twinprimes.size() << endl;
    long long s;
    while(cin >> s){
        s--;
        cout << "(" << twinprimes[s].first << ", " << twinprimes[s].second << ")\n";
    }
}