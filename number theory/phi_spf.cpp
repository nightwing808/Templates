//phi counts how many integers in
//range [1…n] are coprime to n.
int phi[N],spf[N];
void pre(){
    for (int i=1;i<N;i++) phi[i]=spf[i]=i;
    for (int i=2;i<N;i++){
        if (phi[i]==i){
            for (int j=i;j<N;j+=i)
                phi[j]-=(phi[j]/i);
        }
        if (spf[i]==i){
            for (ll j=i*i;j<N;j+=i)
                if (spf[j]==j) spf[j]=i;
        }
    }
}
