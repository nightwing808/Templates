int spf[N];
void SPF(){
    for (int i=1;i<N;i++) spf[i]=i;
    for (ll i=2;i<N;i++){
        if (spf[i]==i){
            for (ll j=i*i;j<N;j+=i)
                if (spf[j]==j) spf[j]=i;
        }
    }
}
