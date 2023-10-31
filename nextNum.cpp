for(ll i=1; i <= n; ){
    ll k = n / i;
    ll y = (n + k) / k;
    y = min(y, n + 1);

    ll cur = sum(y-1) - sum(i-1);
    
    i = y;
}
