#include<bits/stdc++.h>
using namespace  std;
//general template of segemnt tree just need to update merge single function to build any segment tree
// seg tree for calculating sum
typedef int item;

struct segtree{
    
    int size,N;
    vector<item> tree;
    
    item merge(item a,item b){
        return a+b;
    }
    
    item single(int v){
        return v;
    }
    
    item Nuetral = 0;//the element which does'nt affect in calculation
    void init(int n){
        size = 1;
        N = n;
        while(size<n) size*=2;
        tree.resize(2*size);
    }
    
    void build(vector<int> &a,int x, int lx,int rx){
        if(rx-lx == 1){
            if(lx<(int)a.size())
            tree[x] = single(a[lx]);
        return;
        }
        int mid = (lx+rx)/2;
        build(a,2*x+1,lx,mid);
        build(a,2*x+2,mid,rx);
        tree[x] = merge(tree[2*x+1],tree[2*x+2]);
    }
    
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    //set value v at ith index in the array update a[i] = v
    void set(int i,int v,int x,int lx, int rx){
        if(rx-lx == 1){
            tree[x] = single(v);
            return;
        }
        int mid = (lx+rx)/2;
        if(i<mid){
            set(i,v,2*x+1,lx,mid);
        }else{
            set(i,v,2*x+2,mid,rx);
        }
        tree[x] = merge(tree[2*x+1],tree[2*x+2]);
    }
    
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    
    item calc(int l,int r,int x,int lx,int rx){
        if(lx>=r || l>=rx) return Nuetral;
        if(lx>=l && rx<=r) return tree[x];
        int mid = (lx+rx)/2;
        item s1 = calc(l,r,2*x+1,lx,mid);
        item s2 = calc(l,r,2*x+2,mid,rx);
        return merge(s1,s2);
    }
    
    item calc(int l,int r){
        return calc(l,r,0,0,size);
    }
};

int main(){
    ios::sync_with_stdio(false);
    
    int n,m;
    cin>>n>>m;
    
    segtree st;
    st.init(n);
    vector<int> a(n);
    
    for(int i=0;i<n;i++) cin>>a[i];
    
    st.build(a);

    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int i;
            cin>>i;
            int v = 1 - a[i];
            a[i] = v;
            st.set(i,v);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<st.calc(l,r)<<"\n";
        }
    }
    return 0;
}


