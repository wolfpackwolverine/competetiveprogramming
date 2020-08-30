int getp(int v) {
	if (v == p[v]) return v;
	return p[v] = getp(p[v]);
}

// getp is getting parent of node v
// a-> b -> c-> v so for b c v a is parent that means this whole nodes are part of one set a->a->a->a;

//bool returns wheather 2 nodes can be merged or not
bool merge(int v, int u) {
	u = getp(u);
	v = getp(v);
	
	if (u == v) return false;
	
	if (rk[u] < rk[v]) swap(u, v);
	
	rk[u] += rk[v];
	p[v] = u;
	
	return true;
}

//merge is merging 2 nodes or connect them if it donot form a cycle

// if getp(u)==getp(v) there is cycle we cannot connect them 
// else we can merge them;
//krushkal'salgorithm

typedef pair<long long,pair<int,int>> edge;
#define ll long long
#define y second
#define x first
#define maxn 200*1000 + 2

int p[maxn];

int getp(int x){
    return (x==p[x]?x:(p[x] = getp(p[x])));
}

bool merge(int a,int b){
    a = getp(a);
    b = getp(b);
    if(a==b) return false;
    p[a]=b;
    return true;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<edge> ed(m);
    ll a[n],mn=1e18,min_ed;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<mn){
            mn = a[i];
            min_ed = i;
        }
    }
    for(int i=0;i<m;i++){
        cin>>ed[i].y.x>>ed[i].y.y>>ed[i].x;
        ed[i].y.y--;
        ed[i].y.x--;
    }
    for(int i =0;i<n;i++){
        if(i!=min_ed){
            ed.push_back(make_pair(mn + a[i],make_pair(min_ed,i)));
        }
    }
    for(int i=0;i<n;i++)p[i]=i;
    sort(ed.begin(),ed.end());
    ll ans = 0;
    for(auto i:ed){
        if(merge(i.y.x,i.y.y))
           ans+=i.x;
    }
    cout<<ans<<endl;
    return 0;
}