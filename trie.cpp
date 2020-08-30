#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

typedef struct data{
	data* child[26];
	int cnt = 0 ;
}trie;

trie* root;
int n,k;
string a[N];

void insert(string &s){
	trie* cur = root;
	for(int i = 0; i < s.size(); i++){
		char ch = s[i];
		int reqd = ch - 'A';
		if(!cur -> child[reqd])
			cur -> child[reqd] = new trie();
		cur = cur -> child[reqd];
	}
	cur -> cnt++; //atleaf will increase cnt to know how many same words we have;
}

int ans = 0;

void dfs(trie* cur,int lvl)
{
	for(int i=0;i<26;i++)
	{
		if(cur -> child[i])//if child exist
		{
			dfs(cur -> child[i], lvl + 1);
			cur -> cnt += cur -> child[i] -> cnt;
		}
	}
	while(cur -> cnt >= k){
		cur -> cnt -= k;
		ans += lvl;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){ 
		ans = 0;
		root = new trie();
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			insert(a[i]);
		}
		dfs(root, 0);
		cout<<ans<<endl;
	}
	return 0;
}