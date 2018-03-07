const int maxn = "Edit";
int n, fa[maxn], ra[maxn];
void init()
{
    for (int i = 0; i <= n; i++) fa[i] = i, ra[i] = 0;
}
int find(int x) { return fa[x] != x ? fa[x] = find(fa[x]) : x; }
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    if (ra[x] < ra[y])
        fa[x] = y;
    else
    {
        fa[y] = x;
        if (ra[x] == ra[y]) ra[x]++;
    }
}
bool same(int x, int y) { return find(x) == find(y); }
