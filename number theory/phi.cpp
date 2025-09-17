//counts how many integers in
//range [1…n] are coprime to n.
int phi[N];
void phi(){
    for (int i=1;i<N;i++) phi[i]=i;
    for (int i=2;i<N;i++){
        if (phi[i]==i){
            for (int j=i;j<N;j+=i)
                phi[j]-=(phi[j]/i);
        }
    }
}
