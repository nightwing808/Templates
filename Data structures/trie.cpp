struct vertex{
	int pre,flag,child[26];
	vertex(){
		pre=flag=0;
		for (int i=0;i<26;i++) child[i]=-1;
	}
};
vector<vertex>Trie;
int avail;
void insert(string &s){
	int cur=0;
	Trie[cur].pre++;
	for (int i=0;i<s.size();i++){
		int x=s[i]-'a';
		if (Trie[cur].child[x]==-1){
			Trie[cur].child[x]=avail;
			if (Trie.size()<=avail) Trie.push_back(vertex());
			else Trie[avail]=vertex();
			avail++;
		}
		cur=Trie[cur].child[x];
		Trie[cur].pre++;
	}
	Trie[cur].flag=1;
}
int query(string &s){
	int cur=0;
	for (int i=0;i<s.size();i++){
		int x=s[i]-'a';
		if (Trie[cur].child[x]==-1) return 0;
		cur=Trie[cur].child[x];
	}
	return Trie[cur].pre;
}
bool remove(int cur,string &s,int i){
	if (i!=s.size()){
		int x=s[i]-'a';
		bool deleted=remove(Trie[cur].child[x],s,i+1);
		if (deleted) Trie[cur].child[x]=-1;
	}
	else Trie[cur].flag--;
	if (cur){
		Trie[cur].pre--;
		if (Trie[cur].pre==0){
			Trie[cur]=vertex();
			return 1;
		}
	}
	return 0;
}