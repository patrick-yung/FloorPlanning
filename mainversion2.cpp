#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

int size=1;
//https://www.techiedelight.com/lee-algorithm-shortest-path-in-a-maze///
//https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2///


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


bool isSafe(vector<vector<int>> maze, int x, int y, int N, int tap)
{
    // if (x, y outside maze) return false
      cout<<"SASDS: "<<x<<" "<<y<<" "<<maze[x][y]<<" "<<N<<endl;

    if(x==N || y==N){
      return false;
    }
          cout<<"SASDS: "<<x<<y<<maze[x][y]<<endl;


    if (
        x >= 0 && x < N && y >= 0
        && y < N && maze[x][y] == 0||maze[x][y]==5){
      cout<<"HELLSD"<<endl;
        return true;}

    return false;
}


/* A recursive utility function
to solve Maze problem */
bool solveMazeUtil(
    vector<vector<int>> maze, int x,
    int y, vector<vector<int>> sol, int size, int tap){
    // if (x, y is goal) return true
        if(x==size||y==size)
            return false;

    if (
        x == 5 && y == 2
        && maze[x][y] == tap) {
        sol[x][y] = tap;
        print(sol, size);
        return true;
    }
      cout<<"TEST: "<<x<<y<<endl;

    if (isSafe(maze, x, y, size,tap) == true) {
          // Check if the current block is already part of solution path.   
        cout<<"HELLO: "<<x<<y<<endl;
          if (sol[x][y] == tap)
              return false;

        // mark x, y as part of solution path
        sol[x][y] = tap;
 
        /* Move forward in x direction */
        if (solveMazeUtil(
                maze, x + 1, y, sol,size,tap)
            == true)
            return true;
 
        /* If moving in x direction
        doesn't give solution then
        Move down in y direction */
        if (solveMazeUtil(
                maze, x, y + 1, sol,size,tap)
            == true)
            return true;
       
        /* If none of the above movements
        work then BACKTRACK: unmark
        x, y as part of solution path */
        sol[x][y] = 0;
        return false;
    }
 
    return false;
}

bool solveMaze(vector<vector<int>> map, int size)
{
  vector<vector<int>> sol;
    sol.resize(size, vector<int>(size));

  for(int n=0;n<size;n++){
    for(int m=0;m<size;m++){
      sol[n][m]=0;
    }
  }
  cout<<map[2][1]<<" FUCK"<<endl;
 
    if (solveMazeUtil(
            map, 2, 1, sol,size, -2)
        == false) {
        printf("Solution doesn't exist");
        return false;
    }

 
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
    
    //Create an array to empty information//
    vector<vector<int>> map;
    map.resize(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          map[i][j]=0;
        }
    }
  //Put Pins//
  for(int n=0;n<pinx.size();n++){
    map[pinx[n]][piny[n]]=pin[n]+1;
  }
  //Put Tap//

  for(int n=0;n<tapx.size();n++){
    map[tapx[n]][tapy[n]]=-tap[n]-1;
  }

  solveMaze(map, size);

  
  //Draw out the array//
  print(map,size);
  

  

  
    return 0;
}
