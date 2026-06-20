#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll  = long long;

 int n;
vector<ll> a;
ll attackSum(ll k) {
    ll attackSec = 0;
    for (int i=0; i<n; i++) {
        if (i== n-1) {
            attackSec += k;
        } else if (a[i]+k-1 >= a[i+1]) {
            attackSec+= a[i+1] - a[i];
        } else {
            attackSec += k;}
    }
    return attackSec;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
       
        ll h;
        cin >> n >> h;

        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll lo=0;
        ll hi = h;

        while (lo < hi) {
           ll mid = lo + (hi-lo)/2;
           if (attackSum(mid) >= h) {
            hi = mid;
           } else {lo = mid + 1;}
        }

        cout << lo << "\n";
    }
}