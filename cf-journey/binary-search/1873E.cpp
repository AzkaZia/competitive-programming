#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll x;
        cin >> n >> x;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        auto check = [&](ll c) -> ll {
            ll water = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] < c) water += c - a[i];
                else break;          
            }
            return water;
        };

        ll lo = 1, hi = a[n - 1] + x;  
        ll ans = 1;

        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (check(mid) <= x) {
                ans = mid;       
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}