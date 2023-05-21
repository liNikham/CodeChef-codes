#include<bits/stdc++.h>
using namespace std;
bool binarySearch(int s,int e,int element,vector<int>&arr,int &index){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==element){
            index=mid;
            return true;
        }
        if(element<arr[mid]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return false;
}
int main(){
    vector<int>arr;int size,element,index;
    cout<<"Enter the size of the vector"<<endl;
    cin>>size;
    cout<<"Enter the elements in the array"<<endl;
    for(int i=0;i<size;i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }
    cout<<"Enter the element to search for"<<endl;
    cin>>element;
    sort(arr.begin(),arr.end());
    if(binarySearch(0,size,element,arr,index)){
       cout<<"element found at index "<<index;
    }
    else{
        cout<<"element not found";
    }
    return 0;
}