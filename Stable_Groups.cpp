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
    ll n,k,x;
    cin >> n >> k >> x;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    sort(whole(arr));
    vector<ll> needed;
    for(ll i=1; i<n; i++) {
        if((arr[i] - arr[i-1]) > x) {
            needed.push_back((arr[i] - arr[i-1] - 1)/x);
        }
    }
    sort(whole(needed));
    ll m = needed.size();
    ll j = 0;
    ll sum = 0;
    while(j < m && (sum + needed[j]) <= k) {
        sum += needed[j];
        j++;
    }
    cout << (1 + (m - j)) << "\n";
    return 0;
}