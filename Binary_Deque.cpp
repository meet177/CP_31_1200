#include <bits/stdc++.h>
using namespace std;

#define ll int
const ll INF = 1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "Yes\n"
#define no cout << "No\n"

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n,s;
        cin >> n >> s;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        vector<ll> one_ind;
        for(ll i=0; i<n; i++) {
            if(arr[i] == 1) one_ind.push_back(i);
        }
        ll m = one_ind.size();

        ll longest = -1;
        ll i = 0;
        while(i <= (m-s)) {
            ll curr = one_ind[i+s-1] - one_ind[i] + 1;
            if(i > 0) curr += (one_ind[i] - one_ind[i-1] - 1);
            else curr += (one_ind[i]);
            if((i+s-1) < m-1) curr += (one_ind[i+s] - one_ind[i+s-1] - 1);
            else curr += (n-1 - one_ind[m-1]);
            longest = max(longest,curr);
            ++i;
        }
        if(longest == -1) cout << -1 << "\n";
        else cout << (n - longest) << "\n";
    } 
    return 0;
}