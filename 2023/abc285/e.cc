//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
//#include <unordered_map>
//#include <unordered_set>
#include <cassert>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>
#include <complex>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#include <atcoder/convolution>
//#include <atcoder/lazysegtree>
//#include <atcoder/maxflow>
//#include <atcoder/mincostflow>
//#include <atcoder/segtree>
//#include <atcoder/string>
using namespace std;
//using namespace atcoder;
#define int long long
//#define L __int128
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define a first
#define b second
#define fi first
#define sc second
#define rng(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,x) for(int i=0;i<x;i++)
#define gnr(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define per(i,b) gnr(i,0,b)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
#define si(x) (int)(x.size())
#define pcnt(x) __builtin_popcountll(x)
#define all(x) x.begin(),x.end()

#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif
 
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
 
template<class t> using vc=vector<t>;
 
template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.fi<<","<<p.sc<<"}";
}
 
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
 
 //https://codeforces.com/blog/entry/62393
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
	//don't make x negative!
	size_t operator()(pair<int,int> x)const{
		return operator()(uint64_t(x.first)<<32|x.second);
	}
};
//unordered_set -> dtype, null_type
//unordered_map -> dtype(key), dtype(value)
using namespace __gnu_pbds;
template<class t,class u>
using hash_table=gp_hash_table<t,u,custom_hash>;

template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 998244353;
//const ll mod = 1000000007;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

struct mint{
	ll v;
	mint(ll vv=0){s(vv%mod+mod);}
	mint& s(ll vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	mint operator-()const{return mint()-*this;}
	mint &operator+=(const mint&rhs){return s(v+rhs.v);}
	mint &operator-=(const mint&rhs){return s(v+mod-rhs.v);}
	mint &operator*=(const mint&rhs){v=ll(v)*rhs.v%mod;return *this;}
	mint &operator/=(const mint&rhs){return *this*=rhs.inv();}
	mint operator+(const mint&rhs)const{return mint(*this)+=rhs;}
	mint operator-(const mint&rhs)const{return mint(*this)-=rhs;}
	mint operator*(const mint&rhs)const{return mint(*this)*=rhs;}
	mint operator/(const mint&rhs)const{return mint(*this)/=rhs;}
	mint pow(ll n)const{
		if(n<0)return inv().pow(-n);
		mint res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	mint inv()const{return pow(mod-2);}
	friend mint operator+(ll x,const mint&y){
		return mint(x)+y;
	}
	friend mint operator-(ll x,const mint&y){
		return mint(x)-y;
	}
	friend mint operator*(ll x,const mint&y){
		return mint(x)*y;
	}
	friend mint operator/(ll x,const mint&y){
		return mint(x)/y;
	}
	friend ostream& operator<<(ostream&os,const mint&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,mint&m){
		ll x;is>>x;
		m=mint(x);
		return is;
	}
	bool operator<(const mint&r)const{return v<r.v;}
	bool operator==(const mint&r)const{return v==r.v;}
	bool operator!=(const mint&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};
ll modpow(ll x,ll n,ll _md=mod){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%_md;
		x=x*x%_md;
		n>>=1;
	}
	return res;
}
#define _sz 1
mint F[_sz],R[_sz];
void make(){
	F[0] = 1;
	for(int i=1;i<_sz;i++) F[i] = F[i-1] * i;
	R[_sz-1] = F[_sz-1].pow(mod-2);
	for(int i=_sz-2;i>=0;i--) R[i] = R[i+1] * (i+1);
}
mint C(int a,int b){
	if(b < 0 || a < b) return mint();
	return F[a]*R[b]*R[a-b];
}
using ld=long double;
using vi=vc<int>;
using ull=unsigned long long;
/*int dst(P p, P q){
	return (p.a-q.a)*(p.a-q.a)+(p.b-q.b)*(p.b-q.b);
}*/
/*template<class t>
void add_inplace(t &a, t b){
	if(a.size() < b.size()) swap(a, b);
	for(int i=0;i<b.size();i++){
		a[i] += b[i];
		if(a[i] < 0) a[i] += mod;
		if(a[i] >= mod) a[i] -= mod;
	}
	return ;
}*/
template<class t>
void ov(const vc<t>&a){
	if(a.empty()) return;
	rep(i, si(a)) cout << a[i] << (i+1==si(a)?'\n':' ');
}
//o(ans?"Yes":"No");
int n, a[5005];
int num[5005];
int dp[5005];
void solve(){
	cin>>n;
	repn(i,n)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			num[i] += a[min(j, i+1-j)];
		}
	}
	rep(a,5005)dp[a]=-2e18;
	dp[1]=0;
	repn(i,n-1){
		for(int j=i+1;j<=n;j++){
			chmax(dp[j], dp[i]+num[j-i-1]);
		}
	}
	int ans=-2e18;
	repn(i,n) chmax(ans, dp[i]+num[n-i]);
	o(ans);
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}
