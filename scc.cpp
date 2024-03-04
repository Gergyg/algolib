vector < vector<int> > g_scc, gr_scc;
vector<char> used_scc;
vector<int> order_scc, component_scc;
 
void dfs1_scc (int v) {
	used_scc[v] = true;
	for (size_t i=0; i<g_scc[v].size(); ++i)
		if (!used_scc[ g_scc[v][i] ])
			dfs1_scc (g_scc[v][i]);
	order_scc.push_back (v);
}
 
void dfs2_scc (int v) {
	used_scc[v] = true;
	component_scc.push_back (v);
	for (size_t i=0; i<gr_scc[v].size(); ++i)
		if (!used_scc[ gr_scc[v][i] ])
			dfs2_scc (gr_scc[v][i]);
}
 
int main() {
	int n;
	//... чтение n ...
	for(ll i=0; i<m; i++){
        ll u, v;
        cin >> u >> v;
        u--;v--;
        g_scc[u].push_back (v);
        gr_scc[v].push_back (u);
    }

    order_scc.clear();
 
	used_scc.assign (n, false);
	for (int i=0; i<n; ++i)
		if (!used_scc[i])
			dfs1_scc (i);
	used_scc.assign (n, false);
	for (int i=0; i<n; ++i) {
		int v = order_scc[n-1-i];
		if (!used_scc[v]) {
			dfs2_scc (v);
			//... вывод очередной component_scc ...
			component_scc.clear();
		}
	}
}