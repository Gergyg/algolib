struct state {
	int len, link;
	map<char,int> next;
    int first_pos;

    bool is_clon;
    vector<int> inv_link;
};

const int MAXLEN = 100000;
state st[MAXLEN*2];
int sz, last;



void build_inv_links() { // after full build
    for (int v=1; v<sz; ++v)
        st[st[v].link].inv_link.push_back (v);
}

// ответ на запрос - вывод всех вхождений (возможно, с повторами)
void output_all_occurences (int v, int P_length) {
	if (! st[v].is_clon)
		cout << st[v].first_pos - P_length + 1 << endl;
	for (size_t i=0; i<st[v].inv_link.size(); ++i)
		output_all_occurences (st[v].inv_link[i], P_length);
}


// find the number of occurences
int occurences_cnt[MAXLEN*2];
void init_occurences_cnt(int v = 0) {
    occurences_cnt[v] = 0;
    if(!st[v].is_clon) ++occurences_cnt[v];
    for (size_t i=0; i<st[v].inv_link.size(); ++i) {
		init_occurences_cnt(st[v].inv_link[i]);
        occurences_cnt[v] += occurences_cnt[st[v].inv_link[i]];
    }
}

char used_sa[MAXLEN*2];
void dfs(int v = 0) {
    for (const auto& [ch, nxt] : st[v].next) {

    }
}

int PREVIOUS_N = 0;

void sa_init() {
	sz = last = 0;
	st[0].len = 0;
	st[0].link = -1;
	++sz;
	
	// этот код нужен, только если автомат строится много раз для разных строк:
	for (int i=0; i<PREVIOUS_N*2; ++i) {// CLEAR
		st[i].next.clear();
        st[i].inv_link.clear();
        occurences_cnt[i] = 0;
        used_sa[i] = 0;
    }
}

void sa_extend (char c) {
	int cur = sz++;
	st[cur].len = st[last].len + 1;
    st[cur].is_clon = false;
    st[cur].first_pos = st[last].len;
	int p;
	for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
		st[p].next[c] = cur;
	if (p == -1)
		st[cur].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len)
			st[cur].link = q;
		else {
			int clone = sz++;
            st[clone].is_clon = true;
			st[clone].len = st[p].len + 1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
            st[clone].first_pos = st[q].first_pos;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}


/*
string lcs (string s, string t) {
	sa_init();
	for (int i=0; i<(int)s.length(); ++i)
		sa_extend (s[i]);
 
	int v = 0,  l = 0,
		best = 0,  bestpos = 0;
	for (int i=0; i<(int)t.length(); ++i) {
		while (v && ! st[v].next.count(t[i])) {
			v = st[v].link;
			l = st[v].length;
		}
		if (st[v].next.count(t[i])) {
			v = st[v].next[t[i]];
			++l;
		}
		if (l > best)
			best = l,  bestpos = i;
	}
	return t.substr (bestpos-best+1, best);
}
*/