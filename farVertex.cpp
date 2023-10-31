vpll fdown(N, {-1, -1});
vi fup(N, -1);

pll solvedown(ll v){
    if(fdown[v].F != -1) return fdown[v];
    ll ans = -1e18;
    ll ans2 = -1e18;
    if(marked[v]) ans = 0;
    for(ll nxt : g[v]){
        if(nxt == p[v]) continue;
        ll cur = 1 + solvedown(nxt).F;
        if(cur > ans2){
            ans2 = cur;
            if(ans2 > ans) swap(ans2, ans);
        }
    }
    return fdown[v] = mp(ans, ans2);
}

ll solveup(ll v){
    if(p[v] == -1) return -1e18;
    if(fup[v] != -1) return fup[v];
    pll pr = solvedown(p[v]);
    pll cur = solvedown(v);
    ll ans = 1 + solveup(p[v]);
    if(pr.F - 1 == cur.F) ans = max(ans, 1 + pr.S);
    else ans = max(ans, 1 + pr.F);
    return fup[v] = ans;
}


// get for vertex i:
max(solvedown(i).F, solveup(i))