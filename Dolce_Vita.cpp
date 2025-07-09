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
        ll n,x;
        cin >> n >> x;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        sort(whole(arr));
        for(ll i=1; i<n; i++) arr[i] += arr[i-1];
        ll packets = 0;
        ll days = 0;
        for(ll i=n-1; i>=0; i--) {
            ll currCost = arr[i] + (i+1)*days;
            if(currCost > x) continue;
            ll currDays = (x - currCost)/(i+1);
            packets += (i+1)*(currDays + 1);
            days += (currDays + 1);
        }
        cout << packets << "\n";
    }
    return 0;
}