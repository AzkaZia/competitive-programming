#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll  = long long;

string recipe;
ll nb,ns,nc;
ll pb,ps,pc;
ll bCt=0, sCt=0, cCt=0;
ll r;
bool canMake(ll x) {
    ll buyB = max(ll(0), (bCt *x)-nb);
    ll buyS = max(ll(0), (sCt *x)-ns);
    ll buyC = max(ll(0), (cCt *x)-nc);
    ll cost = (buyB * pb) + (buyS * ps) + (buyC * pc);

    return cost <= r;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> recipe;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;
    for (int i=0; i<recipe.size(); i++) {
        if (recipe[i] == 'B') bCt++;
        if (recipe[i] == 'S') sCt++;
        if (recipe[i] == 'C') cCt++;
    }

    //main binary implementation
    ll lo = 0;
    ll hi = r+200;

    while (lo<hi)
    {
        ll mid = lo + (hi-lo+1)/2;
        if (canMake(mid)) lo = mid;
        else hi = mid-1;
    }
    cout << lo << "\n";
}