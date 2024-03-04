const ll MOD = 998244353;
const ll MAXN = 1e6+6;
 
ll md(ll a, ll b){ //binMODpow
    if(!b)
        return 1;
 
    ll ans = md(a, b/2);
    ans = ans*ans%MOD;
 
    if(b%2)
        ans = ans*a%MOD;
 
    return ans;
}
 
ll fact[MAXN+1], invfact[MAXN+1];
void initCombinatorics(){
    ll n = MAXN;
    fact[0]=1;
 
    for(ll i=1; i<=n; i++){
        fact[i] = fact[i-1]*i%MOD;
    }
 
    invfact[n] = md(fact[n], MOD - 2);
 
    for(ll i=n; i; i--){
        invfact[i-1] = invfact[i] * i % MOD;
    }
}
 
ll C(ll n, ll k){
    if(n < k || k < 0) return 0;
    return ((fact[n]*invfact[k])%MOD*invfact[n-k])%MOD;
}