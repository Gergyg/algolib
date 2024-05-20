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
