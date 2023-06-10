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
class Node{
     public:
     	int data;
     	Node *prev;
     	Node * next;
     	Node(int data){
     		this->data=data;
     		this->next=NULL;
     		this->prev=NULL;
     	}
};
void insertAtHead(Node*&head,int data){
     Node *temp=new Node(data);
     temp->next=head;
     head->prev=temp;
     head=temp;
}
void insertAtTail(Node*&tail,int data){
      Node*temp=new Node(data);
      tail->next=temp;
      temp->prev=tail;
      tail=temp;

}
void insertAtPosition(Node*&head,Node*&tail,int position,int data){
	if(position==1){
		insertAtHead(head,data);
		return ;
	}
	Node *newNode=new Node(data);
	
	Node *temp=head;
	int count=1;
	while(count<position-1){
            temp=temp->next;
            count++;
	}
	if(temp->next==NULL){
		insertAtTail(tail,data);
		return ;
	}
	newNode->next=temp->next;
	temp->next->prev=newNode;
	temp->next=newNode;
	newNode->prev=temp;

}
void deleteNode(Node*&head,int data){
   Node*temp=head;
    while(temp!=NULL && temp->data!=data)
        temp=temp->next;
    if(temp==NULL) // data not found in the list
        return;
    if(temp==head){
        head=head->next;
        if(head!=NULL) // check if head is not NULL
            head->prev=NULL;
        delete temp;
    }
    else if(temp->next==NULL)
    {
        temp->prev->next=NULL;
        delete temp;
    }
    else {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}
void p(Node*&head){
	Node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void solve(){
  Node *node1=new Node(10);
  Node*head=node1;
  Node*tail=node1;
  insertAtHead(head,9);
  p(head);
  insertAtTail(tail,11);
  p(head);
  insertAtTail(tail,12);
  p(head);
  insertAtHead(head,8);
  p(head);
   insertAtTail(tail,73);
   p(head);
  insertAtPosition(head,tail,1,7);
  p(head);
  insertAtPosition(head,tail,2,13);
  p(head);
  insertAtPosition(head,tail,8,14);
  p(head);
  insertAtPosition(head,tail,6,15);
  p(head);
  insertAtPosition(head, tail,3,20);
  p(head);
  deleteNode(head,73);
  p(head);
  deleteNode(head,7);
  p(head);

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