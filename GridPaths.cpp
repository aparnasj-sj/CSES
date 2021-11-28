#include<bits/stdc++.h>
#include <algorithm>  
#include <string>

using namespace std;
#define repi(s,e) for(int i=s;i<e;i++)
#define repk(s,e) for(int k=s;k<e;k++)
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
#define vvi vector<vector<int>>
vvi v;
#define inbounds isValid
#define vis v
int isValid(int x,int y){
  if(x>=0 && x<7 && y>=0 && y<7){
  return 1;
  }else{
    return 0;
  }
}


int ans=0;
int isTrap(int x,int y,vvi& v){
  //
   if((!isValid(x+1, y) || v[x+1][y]) && (!isValid(x-1, y) || vis[x-1][y])){
        if(inbounds(x, y-1) && !vis[x][y-1] && inbounds(x, y+1) && !vis[x][y+1]){
            return 1;}}
    if((!inbounds(x, y+1) || vis[x][y+1]) && (!inbounds(x, y-1) || vis[x][y-1])){
        if(inbounds(x+1, y) && !vis[x+1][y] && inbounds(x-1, y) && !vis[x-1][y]){
            return 1;
        }}
  return 0;
}
void helper(int i,int x,int y,string &s,vvi &v){
  //cout<<s[i]<<x<<" "<<y<<endl;
   if(v[x][y]==1){return ;}
   
   if(x==6 && y==0 && i==48){
   //cout<<"found"<<endl;
     ans++;
     
     
     return ;
   }
    if(x==6 && y==0){return ;}
    if(i==48){return ;}
    
 //Trap  
if((!isValid(x+1, y) || v[x+1][y]) && (!isValid(x-1, y) || vis[x-1][y])){
        if(inbounds(x, y-1) && !vis[x][y-1] && inbounds(x, y+1) && !vis[x][y+1]){
            return ;}}
    if((!inbounds(x, y+1) || vis[x][y+1]) && (!inbounds(x, y-1) || vis[x][y-1])){
        if(inbounds(x+1, y) && !vis[x+1][y] && inbounds(x-1, y) && !vis[x-1][y]){
            return ;
        }}

    v[x][y]=1;

   
  if(s[i]=='?'){
    
    repk(0,4){
      int nx=x+dx[k];
      int ny=y+dy[k];
      //cout<<nx<<ny<<endl;
      if(isValid(nx,ny) &&v[nx][ny]==0 ){
        
        helper(i+1,nx,ny,s,v);


      }// if

    }// kloop
    

  }// if
  if(s[i]=='U'){
    if(isValid(x-1,y) && v[x-1][y]==0){
        helper(i+1,x-1,y,s,v);


    }
  }// up
  if(s[i]=='D'){
    if(isValid(x+1,y)&& v[x+1][y]==0){
        helper(i+1,x+1,y,s,v);


    }
  }//down 
  if(s[i]=='L'){
    if(isValid(x,y-1) &&  v[x][y-1]==0){
        helper(i+1,x,y-1,s,v);


    }
  }//left
  if(s[i]=='R'){
    if(isValid(x,y+1) &&  v[x][y+1]==0){
        helper(i+1,x,y+1,s,v);


    }
  }//left

v[x][y]=0;

}//UF ends 

int32_t   main() {
  
    ios_base::sync_with_stdio(false);  
cin.tie(NULL); // flushes cout  
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
string s;
cin>>s;
//cout<<s<<endl;
vvi board(7,vector<int>(7,0));
vvi* v=&board;

helper(0,0,0,s,*v);
cout<<ans<<endl;




} 
