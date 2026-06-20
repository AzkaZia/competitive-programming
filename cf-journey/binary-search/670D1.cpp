#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll  = long long;

ll n,k;
vector<ll> a , b;

bool canMake(ll x) {
    __int128 totalDeficit = 0;
    for (int i=0; i<n; i++) {
        __int128 need = (__int128)a[i] * (__int128)x;
        __int128 deficit = need - (__int128)b[i];
        if (deficit > 0) totalDeficit += deficit;
        if (totalDeficit > (__int128)k) return false; 
    }
    return totalDeficit <= (__int128)k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    a.resize(n);
    b.resize(n);

    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    ll lo = 0;
    ll hi = 2000000000LL + 10; 

    while (lo < hi)
    {
        ll mid = lo + (hi - lo + 1) / 2;
        if (canMake(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}