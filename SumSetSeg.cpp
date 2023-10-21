const ll N = 2e5 + 5;
ll t[4 * N], d[4 * N], p[4 * N];

void push(ll v, ll tl, ll tr){
    if(v >= 4*N) return;
    if(p[v] != 0 && d[v] != 0) p[v] += d[v], d[v] = 0;
    if(p[v]!=0){
        t[v] = (tr - tl + 1) * p[v];
    } else if (d[v]!=0){
        t[v] += (tr - tl + 1) * d[v];
    }

    if(p[v]!=0 && v*2+1 < 4 * N){
        p[v*2] = p[v];
        p[v*2+1] = p[v];
        d[v*2] = 0;
        d[v*2 + 1] = 0;
        d[v] = 0;
        p[v] = 0;
    }
	if(d[v]!=0 && v*2+1 < 4*N){
		d[v*2] += d[v];
		d[v*2+1] += d[v];
		d[v] = 0;
	}
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll add){
	if(l > r) return;

	push(v, tl, tr);

	if(tl==l && tr==r){
		d[v] += add;
        push(v, tl, tr);
		return;
	}

	ll tm = (tl+tr)/2;
	update(v*2, tl, tm, l, min(tm, r), add);
	update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    push(v*2, tl, tm);
    push(v*2 + 1, tm+1, tr);
	t[v] = t[v*2] + t[v*2 + 1];
}

void uset(ll v, ll tl, ll tr, ll l, ll r, ll add){
	if(l > r) return;

	push(v, tl, tr);

	if(tl==l && tr==r){
		p[v] = add;
        d[v] = 0;
        push(v, tl, tr);
		return;
	}

	ll tm = (tl+tr)/2;
	uset(v*2, tl, tm, l, min(tm, r), add);
	uset(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    push(v*2, tl, tm);
    push(v*2 + 1, tm+1, tr);
	t[v] = t[v*2] + t[v*2 + 1];
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
	if(l > r) return 0;

	push(v, tl, tr);

	if(tl==l && tr==r){
		return t[v];
	}

	ll tm = (tl+tr)/2;
	return query(v*2, tl, tm, l, min(tm, r)) + 
				query(v*2+1, tm+1, tr, max(l, tm+1), r);
}