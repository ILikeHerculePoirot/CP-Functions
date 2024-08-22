#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define directedGraphInput \
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
#define undirectedGraphInput \
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
#define vectorInput \
	ll n;\
	cin>>n;\
	vector<ll> v(n,0);\
	for(ll i=0;i<n;i++){\
		cin>>v[i];\
	}
void bfs(ll startingNode,vector<ll> adj[],vector<int> &visited,ll &components){
	visited[startingNode]=1;
	queue<ll> q;
	q.push(startingNode);
	while(!q.empty()){
		ll node=q.front();
		q.pop();
		for(auto it:adj[node]){
			if(!visited[it]){
				visited[it]=1;
				q.push(it);
				components++;
			}
		}
	}
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
void dfs(ll node,vector<ll> adj[],vector<int> &visited,ll &components){
	visited[node]=1;
	for(size_t i=0;i<adj[node].size();i++){
		if(!visited[adj[node][i]]){
			components++;
			dfs(adj[node][i],adj,visited,components);
		}
	}
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
			}while (e-->0);
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
ll shortestPath(ll startingNode,ll endingNode,vector<ll> adj[],ll n){
	vector<ll> dist(n+1,LLONG_MAX);
	queue<ll> q;
	dist[startingNode]=0;
	q.push(startingNode);
	while(!q.empty()){
		ll node=q.front();
		q.pop();
		for(auto it:adj[node]){
			if(dist[node]+1<dist[it]){
				dist[it]=dist[node]+1;
				q.push(it);
			}
		}
	}
	if(dist[endingNode]==LLONG_MAX){
		dist[endingNode]=-1;
	}
	return dist[endingNode];
}
bool shuffledPalindrome(string s){
	bool odd=false;
	map<char,ll> m;
	for(char& c:s){
		m[c]++;
	}
	for(auto it=m.begin();it!=m.end();it++){
		if(it->second%2){
			if(odd){
				return false;
			}
			odd=true;
		}
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
}
