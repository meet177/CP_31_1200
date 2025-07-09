#include <bits/stdc++.h>
using namespace std;

#define ll long long int
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
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        vector<ll> ind(2*n+1,-1);
        for(ll i=0; i<n; i++) ind[arr[i]] = (i+1);
        ll ans = 0;
        for(ll ai=1; ai<=2*n; ai++) {
            if(ind[ai] == -1) continue;
            for(ll aj=1; ai*aj<=2*n; aj++) {
                if(ai == aj) continue;
                if(ind[aj] == -1) continue;
                if(ai*aj == (ind[ai] + ind[aj])) ans++;
            }
        }
        cout << (ans >> 1) << "\n";
    }
    return 0;
}