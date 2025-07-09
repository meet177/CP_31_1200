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
        int n;
        cin >> n;
        int m = n*(n-1)/2;
        vector<int>b(m);
        for(int i=0; i<m; i++) cin >> b[i];
        vector<int>a(n);
        sort(whole(b));
        int curr = 0;
        int i = 0;
        while(i < m) {
            int count = 1;
            while((i+1 < m) && b[i] == b[i+1]) {
                count++;
                i++;
            }
            while(count) {
                count -= (n-curr-1); 
                a[curr++] = b[i];
            }
            i++;
        }
        a[n-1] = b[m-1];
        for(int i=0; i<n; i++) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}