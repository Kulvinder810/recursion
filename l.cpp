#include<bits/stdc++.h>
using namespace std;
vector<bool> r(8,false);
vector<bool> c(8,false);
vector<bool> dig(r.size()+c.size()-1,false);
vector<bool> antidig(r.size()+c.size()-1,false);
int row=0,column=0,diagonal=0,antidiagonal=0;
int bitqueens(vector<vector<bool>>& a,int lpql,int tnq,int qpsf,string s){
       if(qpsf==tnq){
           cout<<s<<endl;
           return 1;
       }
       int count=0;
       for(int i=0;i<a.size()*a[0].size();i++){
           int x=i/a[0].size();
           int y=i%a[0].size();
           int a=(1<<x),b=(1<<y),c=(1<<(x+y)),d=(1<<(x-y+a[0].size()-1));

           if(!a[x][y]){
               
               count+=queens(a,i+1,tnq,qpsf+1,s+to_string(i/a.size())+to_string(i%a.size())+" ");
               r[x]=false; c[y]=false; dig[x+y]=false; antidig[x-y+antidig.size()]=false;
           }
       }

   return count;
   
   
}

bool isQueenSafe(vector<vector<bool>> &a,int x,int y){
    if(r[x]==true||c[y]==true||dig[x+y]==true||antidig[x-y+antidig.size()])
    return false;
    return true;
    
}
int queens(vector<vector<bool>>& a,int lpql,int tnq,int qpsf,string s){
       if(qpsf==tnq){
           cout<<s<<endl;
           return 1;
       }
       int count=0;
       for(int i=0;i<a.size()*a[0].size();i++){
           int x=i/a[0].size();
           int y=i%a[0].size();
           if(!a[x][y]&&isQueenSafe(a,x,y)){
               r[x]=true; c[y]=true; dig[x+y]=true; antidig[x-y+antidig.size()]=true;
               count+=queens(a,i+1,tnq,qpsf+1,s+to_string(i/a.size())+to_string(i%a.size())+" ");
               r[x]=false; c[y]=false; dig[x+y]=false; antidig[x-y+antidig.size()]=false;
           }
       }

   return count;
   
   
}
int main(){
    vector<vector<bool>> ar(4,vector<bool>(4,false));
    cout<<queens(ar,0,4,0,"");
    return 0;
}