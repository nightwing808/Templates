vector<int>g[N];
int cnt[N],sz[N],col[N];
bool big[N];
void szdfs(int v,int p=-1){
    sz[v]=1;
    for (int c:g[v]){
        if (c==p) continue;
        szdfs(c,v);
        sz[v]+=sz[c];
    }
}
void add(int v,int p,int x){
    cnt[col[v]]+=x;
    for (int c:g[v]){
        if (c==p || big[c]) continue;
        add(c,v,x);
    }
}
void sack(int v,int p,bool keep){
    int mxsz=-1,bigC=-1;
    for (int c:g[v]){
        if (c==p) continue;
        if (sz[c]>mxsz){
            mxsz=sz[c];
            bigC=c;
        }
    }
    for (int c:g[v]){
        if (c==p || bigC==c) continue;
        sack(c,v,0);
    }
    if (bigC!=-1){
        sack(bigC,v,1);
        big[bigC]=1;
    }
    add(v,p,1);
    // ans here
    if (bigC!=-1){
        big[bigC]=0;
    }
    if (!keep){
        add(v,p,-1);
    }
}