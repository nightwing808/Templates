struct Matrix{
	int n,m;
	vector<vector<ll>>a;
	Matrix() {}
	Matrix(int x,int y){
		n=x,m=y;
		a.assign(n,vector<ll>(m,0));
	}
	Matrix(vector<vector<ll>>v){
		n=v.size();
		m=(n>0)?v[0].size():0;
		a=v;
	}
	inline void make_unit(){
		assert(n==m);
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				a[i][j]=(i==j);
			}
		}
	}
	inline Matrix operator +(const Matrix &b){
		assert(n==b.n && m==b.m);
		Matrix ans=Matrix(n,m);
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				ans.a[i][j]=(a[i][j]+b.a[i][j])%M;
			}
		}
		return ans;
	}
	inline Matrix operator -(const Matrix &b){
		assert(n==b.n && m==b.m);
		Matrix ans=Matrix(n,m);
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				ans.a[i][j]=(a[i][j]-b.a[i][j]+M)%M;
			}
		}
		return ans;
	}
	inline Matrix operator *(const Matrix &b) {
		assert(m==b.n);
		Matrix ans=Matrix(n,b.m);
		for (int i=0;i<n;i++){
			for (int j=0;j<b.m;j++){
				for (int k=0;k<m;k++){
					ans.a[i][j]=(ans.a[i][j]+(a[i][k]*b.a[k][j])%M)%M;
				}
			}
		}
		return ans;
	}
	inline Matrix pow(ll k) {
		assert(n==m);
		Matrix ans=Matrix(n,n);
		Matrix tmp=a;
		ans.make_unit();
		while (k){
			if (k & 1LL) ans=ans*tmp;
			tmp=tmp*tmp;
			k>>=1LL;
		}
		return ans;
	}
	inline Matrix &operator +=(const Matrix &b) {return *this=(*this)+b;}
	inline Matrix &operator -=(const Matrix &b) {return *this=(*this)-b;}
	inline Matrix &operator *=(const Matrix &b) {return *this=(*this)*b;}
	inline bool operator == (const Matrix &b) {return a==b.a;}
	inline bool operator != (const Matrix &b) {return a!=b.a;}
};