// pair<权值, 点>
// 记得初始化
const int maxn = "Edit";
typedef pair<int, int> PII;
typedef vector<PII> VII;
VII G[maxn];
int vis[maxn], dis[maxn];
void init(int n)
{
    for (int i = 0; i < n; i++) G[i].clear();
}
void add_edge(int u, int v, int w) { G[u].pb(mp(w, v)); }
void Dijkstra(int s, int n)
{
    clr(vis, 0), clr(dis, 0x3f);
    dis[s] = 0;
    priority_queue<PII, VII, greater<PII> > q;
    q.push(mp(dis[s], s));
    while (!q.empty())
    {
        PII t = q.top();
        int x = t.Y;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = 0; i < G[x].size(); i++)
        {
            int y = G[x][i].Y, w = G[x][i].X;
            if (!vis[y] && dis[y] > dis[x] + w)
            {
                dis[y] = dis[x] + w;
                q.push(mp(dis[y], y));
            }
        }
    }
}
