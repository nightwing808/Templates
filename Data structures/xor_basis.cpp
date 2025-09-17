const int B=64;
int basis[B];
void insert(int mask){
	for (int i=B-1;i>=0;i--){
		if (!((mask>>i)&1)) continue;
		if (!basis[i]){
			basis[i]=mask;
			return;
		}
		mask^=basis[i];
	}
}