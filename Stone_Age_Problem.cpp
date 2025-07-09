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
    ll n,q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    ll sum = 0;
    for(ll i=0; i<n; i++) sum += arr[i];
    unordered_map<ll,ll> mpp;
    ll prev_v = -1;
    while(q--) {
        ll t; cin >> t;
        if(t == 1) {
            ll i,x; cin >> i >> x;
            //means we don't have any type 2 ope
            //so our original values will infect only
            if(prev_v == -1){
                sum = (sum - arr[i-1] + x);
                arr[i-1] = x;
            }
            //now when we have any type 2 ope then again when we have a type 1 ope
            else {
                if(mpp.find(i-1) != mpp.end()) {
                    sum = (sum - mpp[i-1] + x);
                    mpp[i-1] = x;
                }else {
                    sum = (sum - prev_v + x);
                    mpp[i-1] = x;
                }
            }
        }else {
            ll x; cin >> x;
            sum = x*n;
            prev_v = x;
            mpp.clear();
        }
        cout << sum << "\n";
    }
    return 0;
}