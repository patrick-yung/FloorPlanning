#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

int size=1;

void lee(vector<vector<int>> maze, int pinx,int piny, int tagx,int tagy){
  vector<vector<int>> visit;
  visit.resize(maze.size(), vector<int>(maze.size()));

  int target=maze[tagx][tagy];
  cout<<"TARGET: "<<target<<endl;
  for(int a=0;a<maze.size();a++)
    for(int b=0;b<maze.size();b++)
      visit[a][b]=0;

  vector<int> x,y,newx,newy;
  x.push_back(pinx);
  y.push_back(piny);
  int loop=0;
  
  while(loop==0){
      int size=x.size();
      for(int n=0;n<size;n++){
        //Check right//

        if(x[n]+1<maze.size()&& maze[x[n]+1][y[n]]==target){
            loop++;
            break;
          }
        if(x[n]+1<maze.size() && 
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
        
        if(y[n]+1<maze.size() && maze[x[n]][y[n]+1]==target){
            loop++;
            break;
          }
        //Check Top//
        
        if(y[n]+1<maze.size() && 
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
    
    
    
} 


vector<vector<int>> final;
void print(vector<vector<int>> map, int size){
    cout<<endl;

  for(int m=0;m<size*3-1;m++)
      cout<<"-";
  cout<<endl;
  for(int n=0;n<size;n++){
    for(int m=0;m<size;m++){
      if(map[n][m]>0){
        cout<<" "<<map[n][m];
      }else if(map[n][m]<0){
        cout<<map[n][m];
      }else{
        cout<<"  ";
      }
      cout<<"|";
    }
    cout<<endl;
    for(int m=0;m<size*3-1;m++)
      cout<<"-";
    cout<<endl;
  }
}
bool solve(
    vector<vector<int>> map, int x,
    int y, vector<vector<int>> sol, int size, int tap);


bool isSafe(vector<vector<int>> maze, int x, int y, int N, int tap, int start)
{
    if(x==N || y==N){
      return false;
    }

    if (
        x >= 0 && x < N && y >= 0
        && y < N && maze[x][y] == 0||maze[x][y] == start){
        return true;}

    return false;
}





bool solve(
    vector<vector<int>> maze, int x,
    int y, vector<vector<int>> sol, int size, int tap, int start){
        if(x==size||y==size)
           return false;
    if (
        x == 5 && y == 2
        && maze[x][y] == tap) {
        sol[x][y] = tap;
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          if(sol[i][j]==-2)
          final[i][j]=sol[i][j];
        }
    }
        return true;
    }

    if (isSafe(maze, x, y, size,tap, start) == true) {
      
          if (sol[x][y] == tap)
              return false;

        sol[x][y] = tap;
        if (solve(
                maze, x + 1, y, sol,size,tap, start)
            == true)
            return true;
        if (solve(
                maze, x, y + 1, sol,size,tap, start)
            == true)
            return true;
        sol[x][y] = 0;
        return false;
    }
 
    return false;
}

bool solveMaze(vector<vector<int>> map, int size,vector<int> pinx, vector<int> piny, vector<int> pin)
{
  vector<vector<int>> sol;
    sol.resize(size, vector<int>(size));

  for(int n=0;n<size;n++){
    for(int m=0;m<size;m++){
      sol[n][m]=0;
    }
  }
  for(int n=0;n<8;n++){
    cout<<piny[n]<<" "<<pinx[n]<<" "<<pin[n]<<endl;
      if(piny[n]<=2 && pinx[n]<=5){
        if (solve(
                map, pinx[n], piny[n], sol,size, -2, pin[n]+1)
            == false) {
    cout<<piny[n]<<" "<<pinx[n]<<" "<<pin[n];

            printf(": Solution doesn't exist\n");
        }
      }
    }

   print(final,size);

    return true;
}




int main(int argc, char** argv)
{


  //Open the files
   ifstream input; 
   input.open(argv[2]); 
    string v="";
    string b="";
  //Declare items//
    vector<int> pinx,piny,pin;
    vector<int> tapx,tapy,tap;

    string nothing;
    int time, load, size,c,x,y, ind, tmp;
  //Read files input//
    input>>nothing>>time;
    input>>nothing>>load;
    input>>nothing>>size;
    input>>nothing>>c;
    input>>nothing>>tmp;
  
    pin.resize(tmp);
    pinx.resize(tmp);
    piny.resize(tmp);

    for(int n=0;n<tmp;n++){
      input>>nothing>>ind>>x>>y;
      pin[n]=ind;
      pinx[n]=x;
      piny[n]=y;

    }
    input>>nothing>>tmp;

  tap.resize(tmp);
  tapx.resize(tmp);
  tapy.resize(tmp);
  
    for(int n=0;n<tmp;n++){
      input>>nothing>>ind>>x>>y;
      tap[n]=ind;
      tapx[n]=x;
      tapy[n]=y;
    }
    input.close();
    
   
  
ofstream outfile (argv[4]);
  outfile<<"TAP 0\n";
  outfile<<"PINS "<<pinx.size()<<endl;
  for(int n=0;n<pinx.size();n++){
    outfile<<"PIN "<<n<<endl;
  }
  outfile<<"ROUTING "<<pinx.size()+2<<endl;
  for(int n=0;n<pinx.size();n++){
    outfile<<"EDGE "<<pinx[n]<<" "<<piny[n]<<" "<<pinx[n]<< " "<<tapy[0]<<endl;
  }
  outfile<<"EDGE "<<tapx[0]<<" "<<tapy[0]<<" "<<tapx[0]<< " "<<tapy[0]<<endl;
  outfile<<"EDGE 0 "<<tapy[0]<<" "<<size-1<<" "<< tapy[0] <<endl;
  
  outfile.close();
  
  //Draw out the array//
  

  

  
    return 0;
}
