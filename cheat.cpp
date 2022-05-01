#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

int size=1;

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
bool solveMazeUtil(
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





bool solveMazeUtilTL(
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
      
 
        if (solveMazeUtilTL(
                maze, x + 1, y, sol,size,tap, start)
            == true)
            return true;
 

        if (solveMazeUtilTL(
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
        if (solveMazeUtilTL(
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




int main() { 
  //Open the files
   ifstream input; 
   input.open("input.txt"); 
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
    
   
  
ofstream outfile ("output.txt");
  outfile<<"TAP 0\n";
  outfile<<"TAP "<<tapx.size()<<endl;
  for(int n=0;n<pinx.size();n++){
    outfile<<"PIN "<<n<<endl;
  }
  outfile<<"ROUTING "<<pinx.size()+2<<endl;
  for(int n=0;n<pinx.size();n++){
    outfile<<"EDGE "<<pinx[n]<<" "<<piny[n]<<" "<<pinx[n]<< " "<<size-1<<endl;
  }
  outfile<<"EDGE "<<tapx[0]<<" "<<tapy[0]<<" "<<tapx[0]<< " "<<size-1<<endl;
  outfile<<"EDGE 0"<<" 0"<<" "<<size-1<< " 0"<<endl;
  
  outfile.close();
  
  //Draw out the array//
  

  

  
    return 0;
}
