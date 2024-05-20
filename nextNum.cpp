for(ll i=1; i <= n; ){
    ll k = n / i;
    ll y = (n + k) / k;
    y = min(y, n + 1);

    ll cur = sum(y-1) - sum(i-1);
    
    i = y;
}

void add(ll A, ll f = -1) {
    if(A == 0) return;
    for(ll i=1; i<=MX;){
        ll k = (A + i - 1) / i;
 
        if(k == 1) {
            x[i] += f;
            break;
        }
 
        l = (A + k - 2) / (k - 1);
        x[i] += k * f;
        x[l] -= k * f;
        i = l;
    }
}