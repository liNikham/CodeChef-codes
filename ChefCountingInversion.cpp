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
int mySol(vi v,int n, int k){
	int val1=(k*(k+1))/2, val2=(k*(k-1))/2,
	 sum1=0,sum2=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(v[i]>v[j]) sum1+=val1;
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=i-1;j>=0;j--){
			if(v[i]>v[j]) sum2+=val2;
		}
	}
	return sum1+sum2;

}
int correctSol(vi v,int n,int k){
	vi store;
	for(int i=1;i<=k;i++){
		for(int j=0;j<n;j++){
			store.push_back(v[j]);
		}
	}
	int noOfans=0;
	int size=store.size();
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
                  if(store[i]>store[j]) noOfans++;
		}
	}
    return noOfans;
}
void solve(){
	srand(time(NULL));
	int count=1;
	while(count<=10000){

		int n= rand()% 5 + 1;
int k=rand()%4 +1;
vi v(n);
for(int i=0;i<n;i++){
    v[i]= rand() % 10+1;
}

int myans=mySol(v,n,k);
int correctans=correctSol(v,n,k);
  if(myans!=correctans){
  	cout<<"count "<<count<<endl;
  	cout<<n<<" "<<k<<endl;
  	for(int i=0;i<n;i++) cout<<v[i]<<" ";
  		cout<<endl;
  	cout<<"correct Answer "<<correctans<<" my answer "<<myans<<endl;
  	break;
  }
  count++;
	}

cout<<"correct ans"<<endl;
  
}
int32_t main(){
	ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	clock_t z = clock();
	int t=1;
	// cin>>t
	while(t--) solve();
	cerr << "Run Time : " << ((double)(clock()-z) / CLOCKS_PER_SEC);
	return 0;
}