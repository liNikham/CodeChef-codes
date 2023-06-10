#include<bits/stdc++.h>
using namespace std;
struct Item{
  int value;
  int weight;
};
bool cmp(Item a,Item b){
  double r1=(double) a.value/a.weight;
  double r2=(double) b.value/b.weight;
  return  r1>r2;
}
double fractionKnapsack(int W,vector<Item>&item){
  sort(item.begin(),item.end(),cmp);
  int current_weight=0;
  double result=0.0;
  for(int i=0;i<item.size();i++){
         if(current_weight+item[i].weight<=W){
          result+=item[i].value;
          current_weight+=item[i].weight;
         }
         else{
          int rem_weight=W-current_weight;
          result+=((double)item[i].value/item[i].weight)*rem_weight;
          break;
         }
  }
  return result;
}
int main(){
    
    int size,W;
    cout<<"Enter the capacity"<<endl;
    cin>>W;
   cout<<"Enter the size of the array of weight and values"<<endl;
   cin>>size;
   vector<Item>item(size);
  for(int i=0;i<size;i++){
    int w,v;
    cout<<"Enter the weight  of item "<<i+1<<endl;
    cin>>w;
    item[i].weight=w;
    cout<<"Enter the value of item "<<i+1<<endl;
    cin>>v;
    item[i].value=v;
  }
 double max_value= fractionKnapsack(W,item);
 cout<<"The max value which can be obtained is "<<max_value<<endl;
  

    return 0;
}