const ll MOD = 1e9+7;
 
ll CC = 49;
 
void mul(vvi& a, vvi& b){
    vvi res(CC, vi(CC));
 
    for(ll i=0; i<CC; i++){
        for(ll j=0; j<CC; j++){
            for(ll p=0; p<CC; p++){
                res[i][j] = (res[i][j] + a[i][p] * b[p][j]) % MOD;
            }
        }
    }
    swap(a, res);
}
 
vvi binpow(vvi& a, ll m){
    if(m==1)
        return a;
    
    vvi res = binpow(a, m/2);
    mul(res, res);
    if(m & 1) mul(res, a);
    return res;
}