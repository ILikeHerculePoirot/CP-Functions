#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vectorInput\
	ll n;\
	cin>>n;\
	vector<ll> v(n,0);\
	for(ll i=0;i<n;i++){\
		cin>>v[i];\
	}
#define directedGraphInput\
	ll n,m;\
	cin>>n>>m;\
	vector<ll> adj[n+1];\
	vector<int> visited(n+1,0);\
	ll components=0;\
	components++;\
	for(ll i=0;i<m;i++){\
		ll u,v;\
		cin>>u>>v;\
		adj[u].push_back(v);\
	}
#define directedGraphInputEdgeWeight\
	ll n,m;\
	cin>>n>>m;\
	vector<vector<ll>> edgeWeight(n+1,vector<ll>(n+1,LLONG_MAX));\
	vector<int> visited(n+1,0);\
	ll components=0;\
	components++;\
	for(ll i=0;i<m;i++){\
		ll u,v,ew;\
		cin>>u>>v>>ew;\
		edgeWeight[u][v]=ew;\
	}
#define undirectedGraphInput\
	ll n,m;\
	cin>>n>>m;\
	vector<ll> adj[n+1];\
	vector<int> visited(n+1,0);\
	ll components=0;\
	components++;\
	for(ll i=0;i<m;i++){\
		ll u,v;\
		cin>>u>>v;\
		adj[u].push_back(v);\
		adj[v].push_back(u);\
	}
#define undirectedGraphInputEdgeWeight\
	ll n,m;\
	cin>>n>>m;\
	vector<vector<ll>> edgeWeight(n+1,vector<ll>(n+1,LLONG_MAX));\
	vector<int> visited(n+1,0);\
	ll components=0;\
	components++;\
	for(ll i=0;i<m;i++){\
		ll u,v,ew;\
		cin>>u>>v>>ew;\
		edgeWeight[u][v]=ew;\
		edgeWeight[v][u]=ew;\
	}
void bfs(ll startingNode,vector<ll> adj[],vector<int> &visited,ll &components){
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
				components++;
			}
		}
	}
}
void dfs(ll node,vector<ll> adj[],vector<int> &visited,ll &components){
	visited[node]=1;
	for(size_t i=0;i<adj[node].size();i++){
		if(!visited[adj[node][i]]){
			components++;
			dfs(adj[node][i],adj,visited,components);
		}
	}
}
vector<ll> dijkstra(ll startingNode,vector<int> &visited,vector<vector<ll>> &edgeWeight,ll n){
	vector<ll> dist(n+1,LLONG_MAX);
    dist[startingNode]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,startingNode});
    while(!pq.empty()){
        ll node=pq.top().second,dis=pq.top().first;
        pq.pop();
        if(visited[node]){
            continue;
        }
        visited[node]=1;
        for(ll i=0;i<=n;i++){
            if(edgeWeight[node][i]!=LLONG_MAX && dis+edgeWeight[node][i]<dist[i]){
                dist[i]=dis+edgeWeight[node][i];
                pq.push({dist[i],i});
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
void floydWarshall(vector<vector<ll>> &edgeWeight,ll n){
	for(int i=0;i<=n;i++){
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
ll shortestPath(ll startingNode,ll endingNode,vector<ll> adj[],ll n){
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
bool powerOfTwo(ll n){
	return n>0 && !(n&(n-1));
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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
}
