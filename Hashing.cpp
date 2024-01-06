const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

const ll N = 2e5 + 5;

ll p[N], h[N];
ll p2[N], h2[N];
ll PR = 31;
ll PR2 = 37;

string s;
ll n;

void prec(){
    p[0] = 1;
    p2[0] = 1;

    for(ll i=1; i<=n; i++){
        p[i] = p[i-1] * PR % MOD;
        p2[i] = p2[i-1] * PR2 % MOD2;
    }

    h[0] = 0;
    h2[0] = 0;

    for(ll i=1; i<=n; i++){
        h[i] = h[i-1] * PR + (ll) s[i-1];
        h2[i] = h2[i-1] * PR2 + (ll) s[i-1];
        h[i] %= MOD;
        h2[i] %= MOD2;
    }
    
}

pll Hash(ll l, ll r){ //  [l, r)
    ll part = (h[r] - h[l] * p[r - l] % MOD + MOD) % MOD;
    ll part2 = (h2[r] - h2[l] * p2[r - l] % MOD2 + MOD2) % MOD2;
    return mp(part, part2);
}