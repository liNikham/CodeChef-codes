#include<bits/stdc++.h>
using namespace std;
#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int,int>
#define vpi            vector <pii>
#define vpp            vector <pair<int,pii>>
#define mii            map <int,int>
#define mpi            map <pii,int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(),p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int,vi,greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x:a) cout << x << " "; cout << endl;
#define print1(a)      for(auto x:a) cout << x.F << " " << x.S <<endl;
#define print2(a,x,y)  for(int i=x;i<y;i++) cout<<a[i]<<" ";cout<<endl;
inline int power(int a, int b){
	int x=1;
	while(b){
		if(b&1) x*=a;
		a*=a;
		b>>=1;
	}
	return x;
}
template <typename Arg1>
void __f (const char*name,Arg1&& arg1) {cout << name <<" : "<<arg1<<endl;}
template <typename Arg1, typename... Args>
void __f ( const char*names,Arg1&& arg1,Args&&... args)
{
	const char*comma=strchr (names + 1,',');
	cout.write(names,comma - names) << ": "<<arg1 << " | "; __f(comma +1,args...);	
}
const int N=200005;
void solve(){
  string a,b;
  cin>>a>>b;
  int n,ans=0;
  cin>>n;
    vi v(26,0);
    a=a+b;
    for(auto ch: a) v[ch-'a']++;
    	vi m(26,0);
    string child;
  for(int i=0;i<n;i++){
  	string c;
  	cin>>c;
  	child+=c;
  }
  for(auto ch: child) m[ch-'a']++;
  	for(int i=0;i<26;i++){
  		if(v[i]<m[i]) {
  			cout<<"NO"<<endl;
  			ans=1;
  			break;
  		}
  	}
  if(ans==0)
    cout<<"YES"<<endl;
}
int32_t main(){
	ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	clock_t z = clock();
	int t=1;
	cin>>t;
	while(t--) solve();
	cerr << "Run Time : " << ((double)(clock()-z) / CLOCKS_PER_SEC);
	return 0;
}