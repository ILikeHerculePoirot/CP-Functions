#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll binarySearch(vector<ll>& v,ll n){ll l=0,h=v.size();while(l<=h){ll m=l+((h-l)/2);if(n==v[m]){return m;}if(n>v[m]){l=m+1;}else{h=m-1;}};return -1;}
ll gcd(ll a,ll b){if(b){return gcd(b,a%b);}return a;}
ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}
ll numberOfFactors(ll n){if(n<=0){return 0;};if(n==1){return 1;};ll c=2;for(ll i=2;i*i<=n;i++){if(n%i==0){if(i*i!=n){c++;}c++;}}return c;}
bool perfectCube(long double n){ll c=cbrt(n);return(c*c*c==n);}
bool perfectSquare(long double n){ll s=sqrt(n);return(s*s==n);}
ll power(ll a,ll b){if(b<0){return 0;};ll r=1;while(b>0){if(b&1){r*=a;}a*=a;b>>=1;};return r;}
ll powerModulo(ll a,ll b,ll m){if(b<0){return 0;};ll r=1;a%=m;while(b>0){if(b&1){r=(r*a)%m;};a=(a*a)%m;;b>>=1;};return r;}
bool powerOfTwo(ll n){return n>0 && !(n&(n-1));}
bool prime(ll n){if(n<2){return false;};for(ll i=2;i*i<=n;i++){if(n%i==0){return false;}};return true;}
bool shuffledPalindrome(string s){bool odd=false;map<char,ll> m;for(char& c:s){m[c]++;};for(auto it=m.begin();it!=m.end();it++){if(it->second%2){if(odd){return false;};odd=true;}};return true;}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
}
