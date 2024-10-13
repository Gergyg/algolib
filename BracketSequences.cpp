ll br_V(ll n, ll k) {
    return (k + 1) * C(2*n-k,n-k) % MOD * fact[n] % MOD * invfact[n+1] % MOD;
}

ll brackets_c(ll n, ll a, ll b) { // the number of sequences with a '(' & b ')' for n pairs()
    if(a < b) return 0;
    return br_V(n-b,a-b);
}

/*
if dp[n] - the number of sequences for n pairs ()
dp[n] : for(i=0; i<=n-1; i++) dp[n] += dp[i] * dp[n-i-1]; // splitted [(good)good]

if t - the number of sequences where '(' is on Ith index:
ll psum[n+1];
psum[0] = 0;
for(ll i=0; i<n; i++){
    psum[i+1] = (psum[i] + dp[i] * dp[n-1-i] % MOD) % MOD;
}
ll t = psum[(2 * n - I + 1)/2];
*/