#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool kthBit(ll n,ll k){
	return ((n&(1<<k))!=0);
}
void clearKthBit(ll &n,ll k){
	n=(n&(~(1<<k)));
}
void setKthBit(ll &n,ll k){
	n=(n|(1<<k));
}
void toggleKthBit(ll &n,ll k){
	n=(n^(1<<k));
}
void removeLastSetBit(ll &n){
	n=(n&(n-1));
}
ll countSetBits(ll n){
	ll c=0;
    while(n!=0){
        n=(n&(n-1));
        c++;
    }
    return c;
}
bool powerOfTwo(ll n){
	return n>0 && !(n&(n-1));
}
ll factorial(ll n){
    if(n==0){
    	return 1;
	}
    ll r=1;
    for(ll i=2;i<=n;i++){
        r*=i;
	}
    return r;
}
ll gcd(ll a,ll b){
	if(b){
		return gcd(b,a%b);
	}
	return a;
}
ll lcm(ll a,ll b){
	return(a/gcd(a,b))*b;
}
ll numberOfDivisors(ll n){
	ll t=1;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			ll e=0;
			do{
				e++;
				n/=i;
			}while(n%i==0);
			t*=e+1;
		}
	}
	if(n>1){
		t*=2;
	}
	return t;
}
ll sumOfDivisors(ll n){
	ll t=1;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			ll e=0;
			do{
				e++;
				n/=i;
			}while(n%i==0);
			ll s=0,p=1;
			do{
				s+=p;
				p*=i;
			}while(e-->0);
			t*=s;
		}
	}
	if(n>1){
		t*=(1+n);
	}
	return t;
}
bool perfectCube(long double n){
	ll c=cbrt(n);
	return(c*c*c==n);
}
bool perfectSquare(long double n){
	ll s=sqrt(n);
	return(s*s==n);
}
bool prime(ll n){
	if(n<2){
		return false;
	}
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
ll power(ll a,ll b){
	if(b<0){
		return 0;
	}
	ll r=1;
	while(b>0){
		if(b&1){
			r*=a;
		}
		a*=a;
		b>>=1;
	}
	return r;
}
ll powerModulo(ll a,ll b,ll m){
	if(b<0){
		return 0;
	}
	ll r=1;
	a%=m;
	while(b>0){
		if(b&1){
			r=(r*a)%m;
		}
		a=(a*a)%m;
		b>>=1;
	}
	return r;
}
ll binarySearch(vector<ll>&v,ll n){
	ll l=0,h=v.size();
	while(l<=h){
		ll m=l+((h-l)/2);
		if(n==v[m]){
			return m;
		}
		if(n>v[m]){
			l=m+1;
		}
		else{
			h=m-1;
		}
	}
	return -1;
}
ll stepFunction(ll x,ll t){
    if(x<=10){
		return 1;
	}
	return 0;
}
ll binaryLift(){
	ll t=0;
	for(ll i=1<<30;i>=1;i>>=1){
		t+=(i*stepFunction(i+t,10));
	}
	return t;
}
class disjointSet{
public:
	ll n,m;
	vector<ll> parent,rank;
	void disjointSetInput(){
		cin>>n>>m;
		parent.resize(n+1);
		rank.resize(n+1);
		for(ll i=0;i<=n;i++){
			parent[i]=i;
		}
		for(ll i=0;i<m;i++){
			ll u,v;
			cin>>u>>v;
			Union(u,v);
		}
	}
	void Union(ll u,ll v){
		u=findParent(u);
		v=findParent(v);
		if(rank[u]<rank[v]){
			parent[u]=v;
		}
		else if(rank[v]<rank[u]){
			parent[v]=u;
		}
		else{
			parent[v]=u;
			rank[u]++;
		}
	}
	ll findParent(ll node){
		if(node==parent[node]){
			return node;
		}
		return parent[node]=findParent(parent[node]);
	}
};
class Graph{
public:
	ll n,m,u,v,ew;
	vector<vector<ll>> adj,edgeWeight;
	vector<int> visited;
	void directedGraphInput(){
		cin>>n>>m;
		adj.resize(n+1);
		visited.resize(n+1);
		for(ll i=0;i<m;i++){
			cin>>u>>v;
			adj[u].push_back(v);
		}
	}
	void directedGraphInputEdgeWeight(){
		cin>>n>>m;
		adj.resize(n+1);
		visited.resize(n+1);
		edgeWeight.resize(n+1,vector<ll>(n+1,LLONG_MAX));
		for(ll i=0;i<m;i++){
			cin>>u>>v>>ew;
			edgeWeight[u][v]=ew;
		}
	}
	void undirectedGraphInput(){
		cin>>n>>m;
		adj.resize(n+1);
		visited.resize(n+1);
		for(ll i=0;i<m;i++){
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	void undirectedGraphInputEdgeWeight(){
		cin>>n>>m;
		adj.resize(n+1);
		visited.resize(n+1);
		edgeWeight.resize(n+1,vector<ll>(n+1,LLONG_MAX));
		for(ll i=0;i<m;i++){
			cin>>u>>v>>ew;
			edgeWeight[u][v]=ew;
			edgeWeight[v][u]=ew;
		}
	}
	void bfs(ll startingNode){
		visited[startingNode]=1;
		queue<ll> q;
		q.push(startingNode);
		while(!q.empty()){
			ll node=q.front();
			q.pop();
			for(size_t i=0;i<adj[node].size();i++){
				if(!visited[adj[node][i]]){
					visited[adj[node][i]]=1;
					q.push(adj[node][i]);
				}
			}
		}
	}
	void dfs(ll node){
		visited[node]=1;
		for(size_t i=0;i<adj[node].size();i++){
			if(!visited[adj[node][i]]){
				dfs(adj[node][i]);
			}
		}
	}
	vector<ll> dijkstra(ll startingNode){
		vector<ll> dist(n+1,LLONG_MAX);
		dist[startingNode]=0;
		priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
		pq.push({0,startingNode});
		while(!pq.empty()){
			ll node=pq.top().second,dis=pq.top().first;
			pq.pop();
			if(!visited[node]){
				visited[node]=1;
				for(ll i=0;i<=n;i++){
					if(edgeWeight[node][i]!=LLONG_MAX && dis+edgeWeight[node][i]<dist[i]){
						dist[i]=dis+edgeWeight[node][i];
						pq.push({dist[i],i});
					}
				}
			}
		}
		for(size_t i=0;i<dist.size();i++){
			if(dist[i]==LLONG_MAX){
				dist[i]=-1;
			}
		}
		return dist;
	}
	void floydWarshall(){
		for(ll i=0;i<=n;i++){
			edgeWeight[i][i]=0;
		}
		for(ll k=0;k<=n;k++){
			for(ll i=0;i<=n;i++){
				for(ll j=0;j<=n;j++){
					if(edgeWeight[i][k]!=LLONG_MAX && edgeWeight[k][j]!=LLONG_MAX){
						edgeWeight[i][j]=min(edgeWeight[i][j],edgeWeight[i][k]+edgeWeight[k][j]);
					}
				}
			}
		}
	}
	ll shortestPath(ll startingNode,ll endingNode){
		vector<ll> dist(n+1,LLONG_MAX);
		queue<ll> q;
		dist[startingNode]=0;
		q.push(startingNode);
		while(!q.empty()){
			ll node=q.front();
			q.pop();
			for(size_t i=0;i<adj[node].size();i++){
				if(dist[node]+1<dist[adj[node][i]]){
					dist[adj[node][i]]=dist[node]+1;
					q.push(adj[node][i]);
				}
			}
		}
		if(dist[endingNode]==LLONG_MAX){
			dist[endingNode]=-1;
		}
		return dist[endingNode];
	}
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
