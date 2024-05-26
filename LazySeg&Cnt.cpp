const ll N = 2e5 + 5;
pll t[4 * N];
ll p[4 * N];
 
pll combine(pll a, pll b)
{
    if (a.first < b.first) return a;
    if (b.first < a.first) return b;
    return mp(a.first,a.S+b.S);
}
 
vi st;
 
void build(ll v, ll tl, ll tr){
	if(tl==tr){
		t[v] = {st[tl],1};
		p[v] = 0;
		return;
	}
 
	ll tm = (tl+tr)/2;
	build(v*2, tl, tm);
	build(v*2+1, tm+1, tr);
	t[v] = combine(t[v*2], t[v*2+1]);
	p[v] = 0;
}
 
void push(ll v){
	if(p[v]!=0 && v*2+1 < 4*N){
		p[v*2] += p[v];
		t[v*2].F += p[v];
		p[v*2+1] += p[v];
		t[v*2+1].F += p[v];
		p[v] = 0;
	}
}
 
void update(ll v, ll tl, ll tr, ll l, ll r, ll add){
	if(l > r) return;
 
	push(v);
 
	if(tl==l && tr==r){
		t[v].F += add;
		p[v] += add;
		return;
	}
 
	ll tm = (tl+tr)/2;
	update(v*2, tl, tm, l, min(tm, r), add);
	update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
	t[v] = combine(t[v*2], t[v*2+1]);
}
 
pll query(ll v, ll tl, ll tr, ll l, ll r){
	if(l > r) return {1e17,-1};
 
	push(v);
 
	if(tl==l && tr==r){
		return t[v];
	}
 
	ll tm = (tl+tr)/2;
	return combine(query(v*2, tl, tm, l, min(tm, r)),
				query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
 
// ll get(ll ind){
// 	return query(1, 0, n-1, ind, ind);
// }