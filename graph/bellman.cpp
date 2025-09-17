struct triplet{
    int first,second,third;
};
int n,m;
const int ninf=1e17;
vector<triplet>edges;
vector<int>dist;
void bellman()
{
    for (int i=1;i<n;i++)
    {
        for (auto e:edges)
        {
            int u=e.first;
            int v=e.second;
            int d=e.third;
            if (dist[u]==ninf) continue;
            dist[v]=min(dist[v],d+dist[u]);
            dist[v]=max(ninf,dist[v]);
        }
    }
}
