// ---
// DFS+ST在线算法\\
// 时间复杂度$O(nlogn+q)$
// ---
const int maxn = "Edit";
vector<int> G[maxn];
int dfs_clock;
int pos[maxn], f[maxn << 1], dep[maxn << 1];
int dp[maxn << 1][30];
inline void init(int n)
{
    for (int i = 0; i < n; i++) G[i].clear();
    dfs_clock = 0;
}
inline void add_edge(int u, int v) { G[u].pb(v); }
void dfs(int u, int pre, int depth)
{
    f[++dfs_clock] = u;     //记录遍历顺序
    pos[u] = dfs_clock;     //记录某个节点在f中第一次出现的位置
    dep[dfs_clock] = depth; //记录路径
    for (auto& v : G[u])
    {
        if (v == pre) continue;
        dfs(v, u, depth + 1);
        f[++dfs_clock] = u;
        dep[dfs_clock] = depth;
    }
}
void initrmq(int n) // n = dfs_clock
{
    for (int i = 1; i <= n; i++) dp[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i + (1 << j) - 1 <= tot; i++)
        {
            if (dep[dp[i][j - 1]] < dep[dp[i + (1 << (j - 1))][j - 1]])
                dp[i][j] = dp[i][j - 1];
            else
                dp[i][j] = dp[i + (1 << (j - 1))][j - 1];
        }
}
int rmq(int l, int r)
{
    l = pos[l], r = pos[r];
    if (l > r) swap(l, r);
    int k = 31 - __builtin_clz(r - l + 1);
    return (dep[l][k] < dep[r - (1 << k) + 1][k]) ? dp[l][k] : dp[r - (1 << k) + 1][k];
}
