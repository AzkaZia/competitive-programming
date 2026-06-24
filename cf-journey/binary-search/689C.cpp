#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll  = long long;

ll f(ll n) {
    ll total = 0;
    for (ll k=2; k*k*k<=n; k++) {
        total += n/(k*k*k);
    }
    return total;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m;
    cin >> m;

    ll lo = 1, hi = 8 * m + 10; 
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (f(mid) >= m) hi = mid;
        else lo = mid + 1;
    }

    if (f(lo) == m) cout << lo << "\n";
    else cout << -1 << "\n";
}