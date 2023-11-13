int n;
vector < vector<int> > g_2sat, g_2satt;
vector<bool> used_2sat;
vector<int> order, comp;

void dfs1 (int v) {
	used_2sat[v] = true;
	for (size_t i=0; i<g_2sat[v].size(); ++i) {
		int to = g_2sat[v][i];
		if (!used_2sat[to])
			dfs1 (to);
	}
	order.push_back (v);
}

void dfs2 (int v, int cl) {
	comp[v] = cl;
	for (size_t i=0; i<g_2satt[v].size(); ++i) {
		int to = g_2satt[v][i];
		if (comp[to] == -1)
			dfs2 (to, cl);
	}
}

int main() {
	... чтение n, графа g, построение графа gt (обратный) ...

    order.clear();

	used_2sat.assign (n, false);
	for (int i=0; i<n; ++i)
		if (!used_2sat[i])
			dfs1 (i);

	comp.assign (n, -1);
	for (int i=0, j=0; i<n; ++i) {
		int v = order[n-i-1];
		if (comp[v] == -1)
			dfs2 (v, j++);
	}

	for (int i=0; i<n; ++i)
		if (comp[i] == comp[i^1]) {
			puts ("NO SOLUTION");
			return 0;
		}
	for (int i=0; i<n; i+=2) {
		if(comp[i] > comp[i^1]); // i - x, i ^ 1 - !x
		    printf ("%d ", i); // Если нужно брать i, выводим
	}

}