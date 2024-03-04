// https://cses.fi/problemset/hack/1735/entry/8228883/

struct node
{
    ll val, lazy1, lazy2;
} st[LIM * 4];
 
void down(int id, int l, int r)
{
    ll val1 = st[id].lazy1, val2 = st[id].lazy2;
    st[id].lazy1 = st[id].lazy2 = 0;
 
    int mid = (l + r) / 2;
 
    if (val2)
    {
        st[id * 2].val = val2 * (mid - l + 1);
        st[id * 2].lazy1 = 0;
        st[id * 2].lazy2 = val2;
 
        st[id * 2 + 1].val = val2 * (r - mid);
        st[id * 2 + 1].lazy1 = 0;
        st[id * 2 + 1].lazy2 = val2;
    }
 
    st[id * 2].val += val1 * (mid - l + 1);
    st[id * 2].lazy1 += val1;
 
    st[id * 2 + 1].val += val1 * (r - mid);
    st[id * 2 + 1].lazy1 += val1;
}
 
void update(int id, int l, int r, int i, int j, int type, ll v)
{
    if (j < l || r < i)
        return;
    if (i <= l && r <= j)
    {
        if (type == 1)
        {
            st[id].val += v * (r - l + 1);
            st[id].lazy1 += v;
        }
        else
        {
            st[id].val = v * (r - l + 1);
            st[id].lazy1 = 0;
            st[id].lazy2 = v;
        }
        return;
    }
 
    down(id, l, r);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, i, j, type, v);
    update(id * 2 + 1, mid + 1, r, i, j, type, v);
    st[id].val = st[id * 2].val + st[id * 2 + 1].val;
}
 
ll get(int id, int l, int r, int i, int j)
{
    if (j < l || r < i)
        return 0;
    if (i <= l && r <= j)
        return st[id].val;
 
    down(id, l, r);
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, i, j) + get(id * 2 + 1, mid + 1, r, i, j);
}


// const ll N = 2e5 + 5;
// ll t[4 * N], d[4 * N], p[4 * N];

// void push(ll v, ll tl, ll tr){
//     if(v >= 4*N) return;
//     if(p[v] != 0 && d[v] != 0) p[v] += d[v];
//     if(p[v]!=0){
//         t[v] = (tr - tl + 1) * p[v];
//     } else if (d[v]!=0){
//         t[v] += (tr - tl + 1) * d[v];
//     }

//     if(p[v]!=0 && v*2+1 < 4 * N){
//         p[v*2] = p[v];
//         p[v*2+1] = p[v];
//         d[v*2] = 0;
//         d[v*2 + 1] = 0;
//     }

// 	if(d[v]!=0 && v*2+1 < 4*N){
// 		d[v*2] += d[v];
// 		d[v*2+1] += d[v];
// 	}

//     d[v] = 0;
// 	p[v] = 0;
// }

// void update(ll v, ll tl, ll tr, ll l, ll r, ll add){
// 	if(l > r) return;

// 	push(v, tl, tr);

// 	if(tl==l && tr==r){
// 		d[v] += add;
//         push(v, tl, tr);
// 		return;
// 	}

// 	ll tm = (tl+tr)/2;
// 	update(v*2, tl, tm, l, min(tm, r), add);
// 	update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
//     push(v*2, tl, tm);
//     push(v*2 + 1, tm+1, tr);
// 	t[v] = t[v*2] + t[v*2 + 1];
// }

// void uset(ll v, ll tl, ll tr, ll l, ll r, ll add){
// 	if(l > r) return;

// 	push(v, tl, tr);

// 	if(tl==l && tr==r){
// 		p[v] = add;
//         d[v] = 0;
//         push(v, tl, tr);
// 		return;
// 	}

// 	ll tm = (tl+tr)/2;
// 	uset(v*2, tl, tm, l, min(tm, r), add);
// 	uset(v*2+1, tm+1, tr, max(l, tm+1), r, add);
//     push(v*2, tl, tm);
//     push(v*2 + 1, tm+1, tr);
// 	t[v] = t[v*2] + t[v*2 + 1];
// }

// ll query(ll v, ll tl, ll tr, ll l, ll r){
// 	if(l > r) return 0;

// 	push(v, tl, tr);

// 	if(tl==l && tr==r){
// 		return t[v];
// 	}

// 	ll tm = (tl+tr)/2;
// 	return query(v*2, tl, tm, l, min(tm, r)) + 
// 				query(v*2+1, tm+1, tr, max(l, tm+1), r);
// }