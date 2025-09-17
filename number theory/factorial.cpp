// COPY BIN_EXPO
ll fact[N],ifact[N];
void factorial()
{
    fact[0]=ifact[0]=1;
    for (ll i=1;i<N;i++)
    {
        fact[i]=(fact[i-1]*i)%M;
        ifact[i]=(ifact[i-1]*bin_expo(i,M-2,M))%M;
    }
}
