#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+10;
const int lN = 17; // lN = floor(log2(N-1)) + 1
int in[N],pv,par[N][lN],dep[N],sz[N];
vector<int> g[N];
void dfs(int k=1,int p=0){
	in[k] = pv++; dep[k] = dep[p]+1; sz[k] = 1;
	for(int i=1,pp =par[k][0]=p;i<lN && par[pp][i-1];i++)
		pp = par[k][i] = par[pp][i-1];
	for(auto nxt:g[k])if(nxt!=p){
		dfs(nxt,k);
        sz[k] += sz[nxt];
	}
    //update smth
}
int LCA(int a,int b,int&dis){
    if(dep[a]<dep[b]) swap(a,b);
    int dif = dep[a] - dep[b];
    dis = dif;
    for(int i=0;dif;(dif>>=1),i++)
        if(dif&1)
            a = par[a][i];
    if(a==b) return a;
    for(int i=lN-1;i>=0;i--)
        if(par[a][i]!=par[b][i])
            a = par[a][i], b = par[b][i] , dis += (1<<i+1);
    dis += 2;
    return par[a][0];
}
int LCA(int a,int b){int t;return LCA(a,b,t);}

int main(){
    ios::sync_with_stdio(!cin.tie(0));
    int n; cin>>n;
    for(int i=1;i<n;i++){
        int a,b; cin>>a>>b;
        g[a].push_back(b); g[b].push_back(a);
    }
    dfs(1);
    int m; cin>>m;
    while(m--){
        int a,b,p,d; cin>>a>>b;
        p = LCA(a,b,d);
        cout<<d<<'\n';
    }
}
