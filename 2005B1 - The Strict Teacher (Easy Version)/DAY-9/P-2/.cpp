#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <string>
#include <cmath>
#include <bitset>
#include <stack>
#include <math.h>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cstdint>
#include <iomanip>

//#define int				long long 
#define ull             unsigned long long 
#define ll              long long 
#define pii             pair<ll,ll>
#define cy              cout<<"YES"<<'\n'
#define cn              cout<<"NO"<<'\n'
#define forn(i,begin,end,add)	for(ll (i)=(begin);(i)<=(end);(i)+=(add))	//begin是i的起始，end是i的终止，add是每次加的大小
#define rforn(i,begin,end,sub)  for(ll (i)=(end);(i)>=(begin);(i)-=(sub))	//r是倒序遍历
#define vv              vector
#define inf32           INT32_MAX/2
#define inf64           INT64_MAX/2
#define ld              long double
#define debug(a,b)		cout<<a<<b
#define eps				1e-12 
#define endl            '\n'
const long double PI = atan2(0.0, -1.0);

const int N = 4e5 + 100;
ll T;
ll mpow(int x, int y, int mod);
ll gcd(ll a, ll b);		ll lcm(ll a, ll b);

struct _Q {
	void query(vv<int> all);
	void answer(vv<int>& all);
};
struct Heavy_chain_splitting {
	vv<int> fa, son, dep, sz, top;	vv<vv<int>> e;
	void init(int n, int s, vv<vv<int>>& e);	void dfs1(int u, int father, vv<vv<int>>& e);	void dfs2(int u, int t, vv<vv<int>>& e);	int lca(int u, int v);
};
struct Cn {
	vv<ll> fac, inv, finv;	int mod;
	void init(int n, int mod);	ll A(int a, int b);	ll C(int a, int b);
};
struct UnionSet {
	void init(int n);	int find(int x);	void union_set(int x, int y);	int find_val(int x);	void union_set(int x, int y, int s);
	vv<int> fa, val, sz;
};
struct Bellman_Ford {
	queue<int> q;
	bool Bellman_ford(int s, const vv<vv<pii>>& e, vv<ll>& d);
};
struct Prime_sieve {
	/*质数数组下表从1开始*/
	vv<int>primes;		int cnt = 0;	vv<int>st;
	void init(int n);	void get_primes(int n);
};
struct Judge_two {
	/*是二分图返回1，不是二分图返回0*/
	int flag = 1;
	void dfs_judge_two_map(int u, int c, vv<vv<int>>& e, vv<int>& color);
};
struct Tarjan_SuoDian {
	int tot = 0, cnt = 0;	vv<int> dfn, low, instk, siz, scc;	stack<int>st;
	void init(int n);	void tarjan(int x, vv<vv<int>>& e);
};
struct Hash {
	vv<ull>p, h;	int P = 131;
	void init(string s);	ull get(int l, int r);
};
struct eDCC_SuoDian {
	struct edge { int v, ne; };	void add(int a, int b);	void init(int n, int m, vv<pii>& all);	void tarjan(int x, int in_edge);
	vv<edge> e;	int idx = 1, tot = 0; vv<int> dfn, low, dcc, bri, sz, h;	stack<int> st; int cnt = 0;
};
struct Dijkstra {
	void Heap_dijkstra(int s, vv<vv<pii>>& e, vv<int>& d);	void dfs_path(int u, int s);
	priority_queue<pair<int, int>> q;
};
struct Huan_tree {
	/*vis[i]=1第一次到，vis[i]=2第二次到*/
	int flag = 0;	int r1 = 0, r2 = 0;
	int len;
	void find(int u, int fa, vv<vv<int>>& e, vv<int>& vis, vv<int>& d);
};
struct KMP {
	int f[1][1];
	void get_next(string s, vector<int>& ne);
	int kmp(string s, string ss);
};
struct Tuopu_order {
	queue<int> q;
	bool topsort(vv<vv<pii>>& e, vv<int>& du);
};
struct Kruskal {
	bool cmp(const pair<int, pii>& a, const pair<int, pii>& b); bool kruskal(int n, const vv<pair<int, pii>>& e);
	int ans = 0; vv<pii> tree;
};
struct Segment_tree {
	struct node { ll l, r, sum, add; };	vv<node>tr;	vv<ll>w;
#define lc p<<1
#define rc (p<<1)|1
#define LEN(x) (tr[(x)].r - tr[(x)].l + 1)	//区间长度包括端点
#define MID(x) (tr[(x)].l + tr[(x)].r) >> 1	//中间点
	void init(int n);
	void pushup(int p);
	void build(int p, int l, int r);
	ll query(int p, int l, int r);
	void pushdown(int p);
	void update(int p, int l, int r, int k);
	void printSeg();
};
struct Tree_Arr {
	int n;	vv<int>c1, c2;
	ll lowbit(ll x);	void add(vv<int>& t, ll x, ll w);	ll sum(vv<int>& t, ll x);
	void init(int n);	int query(int l, int r);	void update(int l, int r, int v);
};

const int mod = 998244353;
struct vDCC_suodian {
	//vDCC，极大的不包含割点的连通块
	//对于割点要裂点
	//将所有vDCC缩成点，把缩点和对应的割点连成边，构成一颗树或森林
	vv<vv<int>>e, ne;
	vv<int>dfn, low, cut, id;
	int tot = 0, cnt, num = 0;
	stack<int>st;
	vv<vv<int>>dcc;
	int root;
	void init(int n, int root) {
		cut = dfn = low = vv<int>(n + 1);
		dcc = e = vv<vv<int>>(n + 1);
		this->root = root;
		tot = cnt = num = 0;
	}
	void tarjan(int x) {
		dfn[x] = low[x] = ++tot;
		st.push(x);
		if (!e[x].size()) {
			dcc[++cnt].push_back(x);
			return;
		}
		int child = 0;
		for (auto y : e[x]) {
			if (!dfn[y]) {
				tarjan(y);
				low[x] = min(low[x], low[y]);
				if (low[y] >= dfn[x]) {
					child++;
					if (x != root || child > 1)
						cut[x] = true;
					cnt++;
					while (1) {
						int z = st.top(); st.pop();
						dcc[cnt].push_back(z);
						if (z == y)break;
					}
					dcc[cnt].push_back(x);
				}
			}
			else {
				low[x] = min(low[x], dfn[y]);
			}
		}
	}
	void get_ne(int n) {
		num = cnt;
		for (int i = 1; i <= n; i++)
			if (cut[i])id[i] = ++num;

		//建新图，从每个vDCC向对应割点连边
		for (int i = 1; i <= cnt; i++)
			for (int j = 0; j < dcc[i].size(); j++) {
				int x = dcc[i][j];
				if (cut[x]) {
					ne[i].push_back(id[x]);
					ne[id[x]].push_back(i);
				}
			}
	}
};
//马拉车算法
struct Manacher {
	/*下标从1开始*/
	void init(string s, string& rs) {
		rs += '%';
		for (auto a : s) {
			rs += '#';
			rs += a;
		}
		rs += '#';
		rs += '%';
	}
	void get_d(string s, vv<int>& d) {
		d[1] = 1;
		int n = s.size() - 1;
		for (int i = 2, l, r = 1; i <= n; i++) {
			if (i <= r)//自动转移
				d[i] = min(d[r - i + l], r - i + 1);
			while (s[i - d[i]] == s[i + d[i]])//暴力扩展
				d[i]++;
			if (i + d[i] - 1 > r)
				l = i - d[i] + 1, r = i + d[i] - 1;
		}
	}

};




void solve() {

	int n, m, q; cin >> n >> m >> q;


	int p1, p2; cin >> p1 >> p2;
	if (p1 > p2)
		swap(p1, p2);
	while (q--) {
		int a; cin >> a;

		int ans;

		if (a > p1 && a < p2)
		{
			int mid = (p1 + p2) / 2;
			ans = min(mid - p1, p2 - mid);
		}
		else if (a <= p1)
			ans = p1 - 1;
		else
			ans = n - p2;
		if (p1 == a || p2 == a)
			ans = 1;
		cout << ans << endl;
	}


}
signed main() {

	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	T = 1;
	cin >> T;
	while (T--)
		solve();
	return 0;
}


//线段树
void Segment_tree::init(int n) {
	tr = vv<node>(4 * n + 3);
	w = vv<ll>(n + 1);
	for (int i = 1; i <= n; i++)
		w[i] = 1;
	build(1, 1, n);
}
void Segment_tree::pushup(int p) {
	tr[p].sum = tr[lc].sum + tr[rc].sum;
}
void Segment_tree::build(int p, int l, int r) {
	tr[p] = { l,r,w[l],0 };
	if (l == r)		return;
	int m = MID(p);
	build(lc, l, m);
	build(rc, m + 1, r);
	pushup(p);
}
ll Segment_tree::query(int p, int l, int r) {
	ll sum = 0;
	if (l <= tr[p].l && tr[p].r <= r)return tr[p].sum;
	int m = MID(p);
	pushdown(p);
	if (l <= m)	sum += query(lc, l, r);
	if (r > m)	sum += query(rc, l, r);
	return sum;
}
void Segment_tree::pushdown(int p) {
	if (tr[p].add) {
		tr[lc].sum += tr[p].add * LEN(lc);
		tr[rc].sum += tr[p].add * LEN(rc);
		tr[lc].add += tr[p].add;
		tr[rc].add += tr[p].add;
		tr[p].add = 0;
	}
}
void Segment_tree::update(int p, int l, int r, int k) {

	if (l <= tr[p].l && tr[p].r <= r) {//找到了这个节点，就重新算一下这个点的值
		tr[p].add += k;
		tr[p].sum += LEN(p) * k;
		return;
	}
	int m = MID(p);
	pushdown(p);
	if (l <= m)	update(lc, l, r, k);
	if (r > m)	update(rc, l, r, k);

	pushup(p);
}
void Segment_tree::printSeg() {

	queue<int>q;
	q.push(1);

	while (q.size()) {

		int sz = q.size();
		while (sz--) {
			int nd = q.front();
			q.pop();
			cout << tr[nd].l << ' '
				<< tr[nd].r << ' '
				<< tr[nd].sum << "    ";
			int p = nd;
			if (tr[nd].l == tr[nd].r)
				continue;
			q.push(lc);
			q.push(rc);
		}
		cout << endl;
	}


}
//树状数组
ll Tree_Arr::lowbit(ll x) { return x & (-x); }
void Tree_Arr::add(vv<int>& t, ll x, ll w) {
	while (x <= n) {
		t[x] += w;
		x += lowbit(x);
	}
	return;
}
ll Tree_Arr::sum(vv<int>& t, ll x) {
	ll s = 0;
	while (x > 0) {
		s += t[x];
		x -= lowbit(x);
	}
	return s;
}
void Tree_Arr::init(int n) {
	this->n = n;
	c1 = c2 = vv<int>(n + 1);
}
int Tree_Arr::query(int l, int r) {
	int sum1 = 0;
	int sum2 = 0;
	sum1 = (l - 1) * sum(c1, l - 1) - sum(c2, l - 1);
	sum2 = r * sum(c1, r) - sum(c2, r);
	return sum2 - sum1;
}
void Tree_Arr::update(int l, int r, int v) {
	add(c1, l, v); add(c1, r + 1, -v);
	add(c2, l, v * (l - 1)); add(c2, r + 1, -v * r);
}

//交互类
void _Q::query(vv<int> all) {
	cout << "? ";
	for (auto a : all) {
		cout << a << ' ';
	}
	cout << '\n'; cout.flush();
}
void _Q::answer(vv<int>& all) {
	cout << "! ";
	for (auto a : all) {
		cout << a << ' ';
	}
	cout << '\n'; cout.flush();
}

//最小生成树
bool Kruskal::cmp(const pair<int, pii>& a, const pair<int, pii>& b) {
	return a.first < b.first;
}
bool Kruskal::kruskal(int n, const vv<pair<int, pii>>& e) {
	ans = 0;
	int cnt = 0;
	UnionSet ust;
	ust.init(n + 1);
	int m = e.size() - 1;
	vector<pair<int, pii>> edges = e;
	sort(edges.begin(), edges.end());

	for (int i = 0; i < m; i++) {
		int x = ust.find(edges[i].second.first);
		int y = ust.find(edges[i].second.second);
		if (x != y) {
			tree.push_back({ edges[i].second.first, edges[i].second.second });
			ust.union_set(x, y);
			ans += edges[i].first;
			cnt++;
		}
	}
	return cnt == n - 1;
}

//卢卡斯定理组合数
void Cn::init(int n, int mod) {
	fac.assign(n + 1, 1ll);
	finv = inv = fac;
	this->mod = mod;
	for (int i = 1; i < n; i++)
		fac[i] = fac[i - 1] * i % mod;
	for (int i = 2; i < n; i++)
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 2; i < n; i++)
		finv[i] = finv[i - 1] * inv[i] % mod;
}
ll Cn::A(int a, int b) {
	return fac[a] * finv[a - b] % mod;
}
ll Cn::C(int a, int b) {
	if (a < 0 || b > a || b < 0)
		return 0;
	else
		return fac[a] * finv[a - b] % mod * finv[b] % mod;
}

//求负权值的最短路
bool Bellman_Ford::Bellman_ford(int s, const vv<vv<pii>>& e, vv<ll>& d) {
	d[s] = 0;
	int n = d.size() - 1;
	bool flag = 0;
	for (int i = 1; i <= n; i++) {
		flag = false;
		for (int u = 1; u <= n; u++) {
			if (d[u] == inf64)
				continue;
			for (const auto& ed : e[u]) {
				int v = ed.first;
				int w = ed.second;
				if (d[v] > d[u] + w) {
					d[v] = d[u] + w;
					flag = true;
				}
			}
		}
		if (!flag)
			break;
	}
	return flag;
}

//重链刨分求lca
void Heavy_chain_splitting::init(int n, int s, vv<vv<int>>& e) {
	fa = vv<int>(n + 1);
	dep = vv<int>(n + 1);
	son = vv<int>(n + 1);
	sz = vv<int>(n + 1);
	top = vv<int>(n + 1);
	dfs1(s, 0, e);
	dfs2(s, 0, e);
}
void Heavy_chain_splitting::dfs1(int u, int father, vv<vv<int>>& e) {
	fa[u] = father;
	dep[u] = dep[father] + 1;
	sz[u] = 1;
	for (int v : e[u]) {
		if (v == father)
			continue;

		dfs1(v, u, e);
		sz[u] += sz[v];

		if (sz[son[u]] < sz[v])
			son[u] = v;
	}
}
void Heavy_chain_splitting::dfs2(int u, int t, vv<vv<int>>& e) {
	top[u] = t;
	if (!son[u])
		return;
	dfs2(son[u], t, e);
	for (int v : e[u]) {
		if (v == fa[u] || v == son[u])
			continue;
		dfs2(v, v, e);
	}
}
int Heavy_chain_splitting::lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]])
			swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}

//拓扑序列
bool Tuopu_order::topsort(vv<vv<pii>>& e, vv<int>& du) {
	int n = e.size() - 1;
	for (int i = 1; i <= n; i++) {
		if (!du[i])
			q.push(i);
	}
	int tot = 0;
	while (!q.empty()) {
		int nd = q.front();
		q.pop();
		tot++;
		for (auto& a : e[nd]) {
			du[a.first]--;
			if (!du[a.first])
				q.push(a.first);

		}
	}

	return tot == n;
}

//KMP
void KMP::get_next(string s, vector<int>& ne) {
	int n = s.size();
	ne[0] = -1;
	for (int i = 1, j = -1; i < n; i++) {
		while (j != -1 && s[i] != s[j + 1])
			j = ne[j];

		if (s[i] == s[j + 1])
			j++;

		ne[i] = j;
	}
}
int KMP::kmp(string s, string ss) {
	int n = s.size(), m = ss.size();
	vector<int> next(m);
	get_next(ss, next);
	for (int i = 0, j = -1; i < n; i++) {
		while (j != -1 && s[i] != ss[j + 1]) {
			if (j < n - 1) {
				j = f[j][s[i] - 'a' + 1];
				break;
			}
			j = next[j];
		}

		if (s[i] == ss[j + 1])
			j++;

		if (j == m - 1) {
			return i - j;
		}
	}
	/*KMP自动机*/
	//for (int i = 0; i < n - 1; i++) {
	//	for (int j = 1; j <= 26; j++) {
	//		if (ne[i] == -1)
	//			f[i][j] = -1;
	//		else
	//			f[i][j] = f[ne[i]][j];
	//	}

	//	f[i][s[i + 1] - 'a' + 1] = i;
	//}
	return -1;
}

//找基环树的环
void Huan_tree::find(int u, int fa, vv<vv<int>>& e, vv<int>& vis, vv<int>& d) {
	vis[u] = 1;
	//有向图的重边处理方式
	//int flag = 1;
	for (auto v : e[u]) {
		//if (v == fa && flag) {
		//	flag = 0;
		//	continue;
		//}
		if (vis[v] == 1) {
			r1 = v;
			r2 = u;
			this->flag = 1;
			this->len = abs(d[u] - d[v]) + 1;
			continue;
		}
		else if (vis[v] == 2) {
			continue;
		}
		//if (v == fa)
		//	continue;
		d[v] = d[u] + 1;
		find(v, u, e, vis, d);
	}
	vis[u] = 2;//如果提前return就会出现没办法标记已经出栈的情况
}

//最短路
void Dijkstra::Heap_dijkstra(int s, vv<vv<pii>>& e, vv<int>& d) {
	priority_queue<pii> q;

	vv<int> vis(d.size());
	d[s] = 0; q.push({ 0, s });

	while (q.size()) {
		auto t = q.top();
		q.pop();
		int u = t.second;
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto& ed : e[u]) {
			int v = ed.first, w = ed.second;
			if (d[v] < d[u] + w) {
				d[v] = d[u] + w;
				q.push({ d[v], v });
			}
		}
	}
}
void Dijkstra::dfs_path(int u, int s) {
	if (u == s) {
		cout << u << " ";
		return;
	}
	cout << u << " ";
}

//edcc缩点
void eDCC_SuoDian::add(int a, int b) {
	e[++idx].v = b;
	e[idx].ne = h[a];
	h[a] = idx;
}
void eDCC_SuoDian::init(int n, int m, vv<pii>& all) {
	e = vv<edge>(2 * m + 10);
	sz = bri = dcc = dfn = low = h = vv<int>(2 * m + 100);
	idx = 1;
	cnt = tot = 0;

	for (auto a : all) {
		add(a.first, a.second);
		add(a.second, a.first);
	}
	for (int i = 1; i <= n; ++i) {
		if (!dfn[i]) tarjan(i, 1);
	}
}
void eDCC_SuoDian::tarjan(int x, int in_edge) {
	dfn[x] = low[x] = ++tot;
	st.push(x);
	for (int i = h[x]; i; i = e[i].ne) {
		int y = e[i].v;
		if (!dfn[y]) {
			tarjan(y, i);
			low[x] = min(low[x], low[y]);
			if (low[y] > dfn[x]) bri[i] = bri[i ^ 1] = true;
		}
		else if (i != (in_edge ^ 1)) {
			low[x] = min(low[x], dfn[y]);
		}
	}
	if (dfn[x] == low[x]) {
		++cnt;
		while (true) {
			int y = st.top(); st.pop();
			dcc[y] = cnt;
			if (y == x) break;
		}
	}
}

//并查集
void UnionSet::init(int n) {
	fa = sz = vv<int>(n + 1);
	val = vv<int>(n + 1);
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
		sz[i] = 1;
	}
}
int UnionSet::find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void UnionSet::union_set(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (sz[y] < sz[x]) swap(x, y);
	fa[x] = y;
	sz[y] += sz[x];
}
int UnionSet::find_val(int x) {
	if (x != fa[x]) {
		int t = fa[x];
		fa[x] = find_val(fa[x]);
		val[x] += val[t];
	}
	return fa[x];
}
void UnionSet::union_set(int x, int y, int s) {
	if (find_val(x) == find_val(y)) return;
	int px = find_val(x);
	int py = find_val(y);
	if (px != py) {
		fa[px] = py;
		val[px] = -val[x] + val[y] + s;
	}
}

//质数筛
void Prime_sieve::init(int n) {
	primes = vv<int>(n);
	st = vv<int>(n + 10);
	cnt = 0;
}
void Prime_sieve::get_primes(int n) {
	init(n);
	for (int i = 2; i <= n; i++) {
		if (!st[i])
			primes[++cnt] = i;

		for (int j = 1; primes[j] <= n / i; j++) {
			st[primes[j] * i] = primes[j];//记录最小nums[i]的质因子
			if (i % primes[j] == 0)
				break;
		}
	}
}

//字符串Hash
void Hash::init(string s) {
	int n = s.size();
	s = ')' + s;
	p = h = vv<ull>(n + 2);
	p[0] = 1, h[0] = 0;
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] * P;
		h[i] = (h[i - 1] * P) % mod + s[i];
		p[i] %= mod;
		h[i] %= mod;
	}
}

ull Hash::get(int l, int r) {
	return (h[r] - (h[l - 1] * p[r - l + 1]) % mod + mod) % mod;
}

//二分图
void Judge_two::dfs_judge_two_map(int u, int c, vv<vv<int>>& e, vv<int>& color) {
	color[u] = c;
	for (auto v : e[u])
		if (!color[v])
			dfs_judge_two_map(v, 3 - c, e, color);
		else if (color[v] == c)
			flag = 0;
}

//Tarjan缩点
void Tarjan_SuoDian::init(int n) {
	cnt = 0, tot = 0;
	dfn = low = siz = scc = vv<int>(n + 1);
	instk = vv<int>(n + 1);
}
void Tarjan_SuoDian::tarjan(int x, vv<vv<int>>& e) {
	dfn[x] = low[x] = ++tot;
	st.push(x), instk[x] = true;
	for (int y : e[x]) {
		//if(y==x) 出现自环
		if (!dfn[y]) {
			tarjan(y, e);
			low[x] = min(low[x], low[y]);
		}
		else if (instk[y]) {//y还没往下走，所以用dfn更新
			low[x] = min(low[x], dfn[y]);
		}
		//如果一个点既不在栈中，又已经走过了，不需要再走了，因为横跨边无法更新任何东西
	}
	//离开x时，记录scc
	if (dfn[x] == low[x]) {
		int y; ++cnt;
		do {
			y = st.top(); st.pop();
			instk[y] = false;
			scc[y] = cnt;
			++siz[cnt];//强连通分量的大小

		} while (y != x);
	}
}

//数学公式
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : abs(a); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll mpow(ll x, ll y, ll mod) {
	x %= mod;
	int s = 1;
	while (y) {
		if (y & 1) {
			s *= x;
			s %= mod;
		}
		x *= x;
		x %= mod;
		y >>= 1;
	}
	return s % mod;
}
