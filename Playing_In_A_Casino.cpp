#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define whole(x) (x).begin(), (x).end()

const int M = 1e9 + 7;

void setupIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    setupIO();
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(m, vector<int>(n));
        //here we just have to take care about columns becuase it is independent row wise
        //so what we are doing here is we can't sort any column directly so we are taking input like all columns will become rows after coming into array
        //then we just sort the array now observe one thing
        //(1 3 5) so on the right side of any element the element will become negative and on the left side of any element the element will become positive so we are just doing it from this we can put O(nC2) to O(nlogn) and that iss needed
        //TC is (m * (nlogn))
        for(int j=0; j<n; j++) {
            for(int i=0; i<m; i++) {
                cin >> a[i][j];
            }
        }
        for(int i=0; i<m; i++) {
            sort(whole(a[i]));
        }
        ll ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans -= (1LL*a[i][j]*(n-j-1));
                ans += (1LL*a[i][j]*(j));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}