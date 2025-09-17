vector<bool>prime(N,1);
vector<int>primes;
void sieve(){
    prime[0]=prime[1]=0;
    for (int i=4;i<N;i+=2) prime[j]=0;
    for (ll i=3;i*i<N;i+=2){
        if (prime[i]){
            for (ll j=i*i;j<N;j+=i){
                prime[j]=0;
            }
        }
    }
    primes.push_back(2);
    for (int i=3;i<N;i+=2)
        if (prime[i]) primes.push_back(i);
}
