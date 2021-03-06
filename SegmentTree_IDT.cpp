#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T=ll>
struct Seg{
    int n;
    vector<T> t;
    Seg(int k=0):n(k),t(2*k){}
    inline T op(T a,T b){return a+b;}
    void build(int n,vector<T>&a){
        this->n=n; t.resize(2*n,0);
        for(int i=0;i<n;i++) t[n+i]=a[i];
        for(int i=n-1;i>=1;i--) t[i]=op(t[i<<1],t[i<<1|1]);
    }
    void update(int pos,T v){
        for(t[pos+=n]=v;pos>1;pos>>=1) t[pos>>1]=op(t[pos],t[pos^1]);
    }
    T query(int l,int r){
        T res=0;
        for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
            if(l&1) res=op(res,t[l++]);
            if(!(r&1)) res=op(res,t[r--]); 
        }
        return res;
    }
};
int main(){
    ios::sync_with_stdio(!cin.tie(0));
    int n,m,k; cin>>n>>m>>k;
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll k; cin>>k;
        v.push_back(k);
    }
    Seg ST;
    ST.build(n,v);
}
