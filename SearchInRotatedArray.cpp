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

    int peak(vector<int>&nums){
    	auto it= max_element(all(nums));
  int max_index = distance(nums.begin(), it);
  for(int i=max_index+1;i<nums.size();i++){
  	if(nums[i]==*it){
  		max_index=i;
  	}
  	else{
  		break;
  	}
  }
  return max_index;
    }
bool search(vector<int>& nums, int target) {
	if(target==nums[0])
		return 0;
        int peakIndex=peak(nums);
        cout<<"peakIndex"<<peakIndex<<endl;
        if(target<nums[0]){
          int s=peakIndex+1,e=nums.size()-1;
          int mid=s+(e-s)/2;
          while(s<=e){
              if(nums[mid]==target)
              	return 1;
              else if(nums[mid]<target)
              	s=mid+1;
              else
              	e=mid-1;
              mid=s+(e-s)/2;
          }
        }
        else{
           int s=0,e=peakIndex;
          int mid=s+(e-s)/2;
          int ans;
          while(s<=e){
              if(nums[mid]==target)
              	return 1;
              else if(nums[mid]<target)
              	s=mid+1;
              else
              	e=mid-1;
              mid=s+(e-s)/2;
          }
        }
        return 0;
    }
void solve(){
   int n;
        cin >> n;

        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;
        cout<<search(a,key)<<endl;

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