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
        if(arr[n-2] > arr[n-1]) {
            cout << -1 << '\n';
        }else {
            if(arr[n-2] < 0 && arr[n-1] < 0) {
                if(is_sorted(whole(arr))) cout << 0 << "\n";
                else cout << -1 << "\n";
            }else {
                ll diff = arr[n-2] - arr[n-1];
                cout << (n-2) << "\n";
                for(ll i=0; i<n-2; i++) {
                    cout << (i+1) << " " << (n-1) << " " << (n) << '\n';
                }
            }
        }
    }
    return 0;
}