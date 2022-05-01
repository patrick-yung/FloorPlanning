#include <iostream>
#include <stack>
#include <vector>

 
using namespace std;
 
#define N 4
#define M 5
 
void lee(int maze[][M], int pinx,int piny, int tagx,int tagy){
  int visit[N][M];
  int target=maze[3][4];
  cout<<"TARGET: "<<target<<endl;
  for(int a=0;a<N;a++)
    for(int b=0;b<M;b++)
      visit[a][b]=0;

  vector<int> x,y,newx,newy;
  x.push_back(pinx);
  y.push_back(piny);
  int loop=0;
  
  while(loop==0){
      int size=x.size();
      for(int n=0;n<size;n++){
        //Check right//

        if(x[n]+1<N && maze[x[n]+1][y[n]]==target){
            loop++;
            break;
          }
        if(x[n]+1<N && 
          (visit[x[n]+1][y[n]]>visit[x[n]][y[n]]+1&& maze[x[n]+1][y[n]]==0)
          ||(visit[x[n]+1][y[n]]==0 && !(x[n]+1==pinx && y[n]==piny))
          ){
          
          visit[x[n]+1][y[n]]=visit[x[n]][y[n]]+1;
          newx.push_back(x[n]+1);
          newy.push_back(y[n]);
          }
          
        if(x[n]-1>=0 && maze[x[n]-1][y[n]]==target){
            loop++;
            break;
          }
        //Check Left//
  if(x[n]-1>=0 && 
          (visit[x[n]-1][y[n]]>visit[x[n]][y[n]]+1         && maze[x[n]-1][y[n]]==0)
    ||(visit[x[n]-1][y[n]]==0 && x[n]-1!=pinx && !(x[n]-1==pinx && y[n]==piny))
          ){
          visit[x[n]-1][y[n]]=visit[x[n]][y[n]]+1;
          newx.push_back(x[n]-1);
          newy.push_back(y[n]);
          }
        
        if(y[n]+1<M && maze[x[n]][y[n]+1]==target){
            loop++;
            break;
          }
        //Check Top//
        
        if(y[n]+1<M && 
          (visit[x[n]][y[n]+1]>visit[x[n]][y[n]] +1        && maze[x[n]][y[n]+1]==0)
          ||(visit[x[n]][y[n]+1]==0  && !(x[n]==pinx && y[n]+1==piny))
          ){
          
          visit[x[n]][y[n]+1]=visit[x[n]][y[n]]+1;
          newx.push_back(x[n]);
          newy.push_back(y[n]+1);
          }
        
        
        //Check down//
        if(y[n]-1>=0 && maze[x[n]][y[n]-1]==target){
            loop++;
            break;
          }
  if(y[n]-1>=0 && 
          (y[n]-1>=0 &&visit[x[n]][y[n]-1]>visit[x[n]][y[n]]+1         && maze[x[n]][y[n]-1]==0)
    ||(y[n]-1>=0 &&visit[x[n]][y[n]-1]==0 &&  !(x[n]==pinx && y[n]-1==piny))
          ){
          visit[x[n]][y[n]-1]=visit[x[n]][y[n]]+1;
          newx.push_back(x[n]);
          newy.push_back(y[n]-1);
          }
      }
    
   
    
    x.clear();
    y.clear();
    for(int n=0;n<newx.size();n++){
      x.push_back(newx[n]);
      y.push_back(newy[n]);
    }
    
    newx.clear();
    newy.clear();
    
    
  }
    
    
    


   
for(int a=0;a<N;a++){
    for(int b=0;b<M;b++){
      cout<<visit[a][b]<<" ";
      }
    cout<<endl;
    }
  
  

  
} 
int decoy(int )

int main()
{

    int maze[N][M] = {
        { 0, 0, 1, 1, 0 },
        { 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, -2 }
    };
 
  
  for(int a=0;a<N;a++){
    for(int b=0;b<M;b++){
      cout<<maze[a][b]<<" ";
      }
    cout<<endl;
    }
  cout<<endl<<endl;
      
    
         
    return 0;
}
