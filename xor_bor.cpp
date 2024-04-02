struct node{
    ll cnt[2];
    ll nxt[2];
};

const ll N = 7e6 + 5;

ll cur = 1;

node bor[N];

void add(ll x){
    ll v = 0;

    for(ll i=30; i>=0; i--){
        if(x & (1LL << i)){
            if(bor[v].nxt[1] == 0){
                bor[v].nxt[1] = cur++;
            }
            bor[v].cnt[1]++;
            v = bor[v].nxt[1];
        } else {
            if(bor[v].nxt[0] == 0){
                bor[v].nxt[0] = cur++;
            }
            bor[v].cnt[0]++;
            v = bor[v].nxt[0];
        }
    }
}

ll get(ll x){
    ll v = 0;
    ll res = 0;

    for(ll i=30; i>=0; i--){
        ll f;
        if(x & (1LL << i)){
            f = 0;
        } else {
            f = 1;
        }

        if(bor[v].nxt[1] == 0){
            bor[v].nxt[1] = cur++;
        }
        if(bor[v].nxt[0] == 0){
            bor[v].nxt[0] = cur++;
        }

       
        if(bor[v].cnt[f] != 0){
            res |= (1LL << i);
            v = bor[v].nxt[f];
        } else {
            v = bor[v].nxt[1 - f];
        }
    }

    return res;
}