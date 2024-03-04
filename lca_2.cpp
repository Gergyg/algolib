int tin[N], tout[N];
int T = 0;
int fup[N][K];

void dfs(int v, int u)
{
    tin[v] = T++;      
    fup[v][0] = u;
    for(int i = 1; i < K; i++)
        fup[v][i] = fup[fup[v][i - 1]][i - 1];
    for(auto y : g[v])
        if(y != u)
            dfs(y, v);
    tout[v] = T++;   
}
 
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
int LCA(int x, int y)
{
    if(is_ancestor(x, y)) return x;
    for(int i = K - 1; i >= 0; i--)
        if(!is_ancestor(fup[x][i], y))
            x = fup[x][i];
    return fup[x][0];
}