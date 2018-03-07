// G[u] = mp(v, w)
// BellmanFord()返回0表示存在负环
const int maxn = "Edit";
vector<PII> G[maxn];
bool vis[maxn];
int dis[maxn];
int inqueue[maxn];
void init(int n)
{
    for (int i = 0; i < n; i++) G[i].clear();
}
void add_edge(int u, int v, int w) { G[u].pb(mp(v, w)); }
bool BellmanFord(int s, int n)
{
    clr(vis, 0), clr(dis, 0x3f), clr(inqueue, 0);
    dis[s] = 0;
    queue<int> q; // 待优化的节点入队
    q.push(s);
    vis[s] = true, ++inqueue[s];
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = false;
        for (int i = 0; i < G[x].size(); i++)
        {
            int y = G[x][i].X, w = G[x][i].Y;
            if (dis[y] > dis[x] + w)
            {
                dis[y] = dis[x] + w;
                if (!vis[y])
                {
                    q.push(y);
                    vis[y] = true;
                    if (++inqueue[y] >= n) return 0;
                }
            }
        }
    }
    return 1;
}
