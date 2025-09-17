#define pii pair<int,int>
vector<pair<int,int>>a[N];
int dist[N];
void dijkstra(int source){
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,source});
    dist[source]=0;
    while (!pq.empty()){
        pii node=pq.top();
        int v=node.second;
        int d=node.first;
        pq.pop();
        if (dist[v]<d) continue;
        for (auto ch:a[v])
        {
            int c=ch.first;
            int w=ch.second;
            if (dist[v]+w<dist[c])
            {
                dist[c]=dist[v]+w;
                pq.push({dist[c],c});
            }
        }
    }
}
