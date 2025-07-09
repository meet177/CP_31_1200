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
        vector<string> mtx(n);
        for(ll i=0; i<n; i++) cin >> mtx[i];
        ll ans = 0;
        for(ll i=0; i<n; i++) {
            for(ll j=0; j<n; j++) {
                //simple
                ll a1 = mtx[i][j];
                //90 clockwise
                ll a2 = mtx[n-j-1][i];
                //180
                ll a3 = mtx[n-i-1][n-j-1];
                //90 anticlockwise
                ll a4 = mtx[j][n-i-1];
                //all same no need to flip anything
                if(a1 == a2 && a2 == a3 && a3 == a4) continue;
                //any three same so change only the remaining one
                if((a1 == a2 && a2 == a3) || (a2 == a3 && a3 == a4) || (a1 == a2 && a2 == a4) || (a1 == a3 && a3 == a4)) ans++;
                //any two same change the other two
                else ans += 2;
            }
        }
        //we will get all things counted four times in whole process so divide by 4
        cout << ans/4 << "\n";
    }
    return 0;
}