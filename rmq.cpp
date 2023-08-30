ll a[N], mn[LOGN][N];

ll rmq(ll l, ll r) { // полуинтервал [l; r)
    ll t = __lg(r - l);
    return min(mn[t][l], mn[t][r - (1 << t)]);
}

// Это считается где-то в первых строчках main:

memcpy(mn[0], a, sizeof a);

for (ll l = 0; l < LOGN - 1; l++)
    for (ll i = 0; i + (2 << l) <= n; i++)
        mn[l+1][i] = min(mn[l][i], mn[l][i + (1 << l)]);