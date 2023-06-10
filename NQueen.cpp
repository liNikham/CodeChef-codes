#include<bits/stdc++.h>
using namespace std;
bool isSafe(int row,int col,vector<string>&board,int n){
    int drow=row,dcol=col;
    while(row>=0&&col>=0){
        if(board[row][col]=='Q')
        return false;
        row--;col--;
    }
    col=dcol;row=drow;
    while(col>=0){
        if(board[row][col]=='Q')
        return false;
        col--;
    }
    row=drow;col=dcol;
    while(row<n&&col>=0){
        if(board[row][col]=='Q')
        return false;
        row++;
        col--;
    }
    return true;
}
void solveNqueen(int col,int n,vector<string>&board,vector<vector<string>>&ans){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            (solveNqueen(col+1,n,board,ans));
            board[row][col]='0';
        }
    }
}
int main(){
    vector<vector<string>>ans;
    int n,size;
    cout<<"Enter the size of the board"<<endl;
    cin>>size;
    vector<string>board(size);
    string s(size,'0');
    for(int i=0;i<size;i++) board[i]=s;
    cout<<"Enter the number of queens"<<endl;
    cin>>n;
    solveNqueen(0,size,board,ans);
        for(int i=0;i<ans.size();i++){
            cout<<"Arrangements "<<i+1<<endl;
            for(int j=0;j<ans[0].size();j++){
                cout<<ans[i][j]<<endl;
            }
            cout<<endl;
        }
        
    
    
    return 0;
}