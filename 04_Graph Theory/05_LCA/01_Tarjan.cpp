// ---
// Tarjan离线算法\\
// 时间复杂度$O(n+q)$
// ---
const int maxn = "Edit";
int par[maxn];                      //并查集
int ans[maxn];                      //存储答案
vector<int> G[maxn];                //邻接表
vector<int> query[maxn], num[maxn]; //存储查询信息
bool vis[maxn];                     //是否被遍历
inline void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        G[i].clear();
        query[i].clear();
        num[i].clear();
        par[i] = i;
        vis[i] = 0;
    }
}
inline void add_edge(int u, int v) { G[u].pb(v); }
inline void add_query(int id, int u, int v)
{
    query[u].pb(v), query[v].pb(u);
    num[u].pb(id), num[v].pb(id);
}
void tarjan(int u)
{
    vis[u] = 1;
    for (auto& v : G[u])
    {
        if (vis[v]) continue;
        tarjan(v);
        unite(u, v);
    }
    for (auto& v : query[u])
    {
        if (!vis[v]) continue;
        ans[num[u][i]] = find(v);
    }
}
