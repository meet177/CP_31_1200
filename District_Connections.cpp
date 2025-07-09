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
        bool poss = 0;
        ll f = arr[0];
        for(ll i=1; i<n; i++) {
            if(arr[i] != f) {
                poss = 1;
                break;
            }
        }
        if(!poss) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        ll s = -1;
        for(ll i=1; i<n; i++) {
            if(arr[i] != f) {
                cout << 1 << " " << (i+1) << "\n";
                s = (i+1);
            }
        }
        for(ll i=1; i<n; i++) {
            if(arr[i] == f) {
                cout << s << " " << (i+1) << "\n";
            }
        }
        
    }
    return 0;
}