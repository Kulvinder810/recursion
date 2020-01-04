#include<iostream>
#include<vector>
using namespace std;

bool check(vector<vector<int>>& board,int value,int x,int y){
      for(int i=0;i<9;i++)
      if(board[x][i]==value||board[i][y]==value) return false;
      int r=(x/3)*3, c=(y/3)*3;
      for(int i=r;i<r+3;i++)
          for(int j=c;j<c+3;j++)
          if(board[i][j]==value) return false;
      return true;    
      
}
int sudokufill(vector<vector<int>>& board,int idx){
    if(idx==81){ 
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        } 
        cout<<endl;
        return 1;  }
    
    int r=idx/9;
    int c=idx%9;
    int count=0;
    if(board[r][c]==0){
        for(int i=1;i<10;i++){
            if(check(board,i,r,c)){
            board[r][c]=i;
            count+=sudokufill(board,idx+1);
            board[r][c]=0; }
        }
    }
    else count+=sudokufill(board,idx+1);
    return count;
}
bool sudokufill1(vector<vector<int>>& board,int idx){
    if(idx==81){
        for(vector<int>  &arr: board){
            for(int ele: arr)
            cout<<ele<<" ";
            cout<<endl;
        } 
        return true;}
    
    int r=idx/9;
    int c=idx%9;
    bool res=false;
    if(board[r][c]==0){
        for(int i=1;i<10;i++){
            if(check(board,i,r,c)){
            board[r][c]=i;
            res=res||sudokufill1(board,idx+1);
            if(res) return res;
            board[r][c]=0; }
        }
    }
    else res=res||sudokufill1(board,idx+1);
    return res;
}
int main(){
    vector<vector<int>> box={{0,0,6,0,0,8,0,0,0},
                             {5,2,0,0,0,0,0,0,0},
                             {0,8,7,0,0,0,0,3,1},
                             {0,0,3,0,1,0,0,8,0},
                             {9,0,0,8,6,3,0,0,5},
                             {0,5,0,0,9,0,6,0,0},   
                             {1,3,0,0,0,0,2,5,0},
                             {0,0,0,0,0,0,0,7,4},
                             {0,0,5,2,0,6,3,0,0},
    };
    cout<<sudokufill1(box,0);

}
