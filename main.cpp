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

void SolveMaze(vector<vector<int>> gridArray, int width, int height)
{
    bool foundEnd = false;
    int it = 0;
    while (!foundEnd) 
    {
        bool foundEmpty = false;
        for (int x = 0; x < width && !foundEnd; ++x){
            for (int y = 0; y < height; ++y){
                if (gridArray[x][y] == it){
                    // check east cell
                    if (x < width - 1){
                        int &east = gridArray[x + 1][y];
                        if (east == -3){
                            foundEnd = true;
                            break;
                        }else if (east == -1){
                            east = it + 1;
                            foundEmpty = true;
                        }
                    }
                    // check west cell
                    if (x > 0){
                        int &west = gridArray[x - 1][y];
                        if (west == -3){
                            foundEnd = true;
                            break;
                        }else if (west == -1){
                            west = it + 1;
                            foundEmpty = true;
                        }
                    }

                    // check south cell
                    if (y < height - 1){
                        int &south = gridArray[x][y + 1];
                        if (south == -3){
                            foundEnd = true;
                            break;
                        }else if (south == -1){
                            south = it + 1;
                            foundEmpty = true;
                        }
                    }

                    // check north cell
                    if (y > 0){
                        int &north = gridArray[x][y - 1];
                        if (north == -3){
                            foundEnd = true;
                            break;
                        }else if (north == -1){
                            north = it + 1;
                            foundEmpty = true;
                        }
                    }   
                }
            }
        }

        if (!foundEnd && !foundEmpty)
        {
            std::cout << "This maze has no solution!" << std::endl << std::endl;
            break;
        }

        it++;
    }
}
//The end on the path is specified by assigning a cell to -3. Cells that are blocked are -2. Cells that are empty are -1. The starting cell is 0//


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

int main() { 
  //Open the files
   ifstream input; 
   input.open("input.txt"); 
    string v="";
    string b="";
  //Declare items//
  stack<int> pinx,piny, pin;
    stack<int> tapx,tapy, tap;
    string nothing;
    int time, load, size,c,x,y, ind, tmp;
  //Read files input//
    input>>nothing>>time;
    input>>nothing>>load;
    input>>nothing>>size;
    input>>nothing>>c;
    input>>nothing>>tmp;
    for(int n=0;n<tmp;n++){
      input>>nothing>>ind>>x>>y;
      pin.push(ind);
      pinx.push(x);
      piny.push(y);
    }
    input>>nothing>>tmp;
    for(int n=0;n<tmp;n++){
      input>>nothing>>ind>>x>>y;
      tap.push(ind);
      tapx.push(x);
      tapy.push(y);
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
    while(!pinx.empty()){
        x=pinx.top();
        y=piny.top();
        ind=pin.top();
        map[x][y]=ind+1;
        pinx.pop();
        piny.pop();
        pin.pop();
    }
        //Put tap//
    while(!tap.empty()){
      cout<<"HELLO";
        x=tapx.top();
        y=tapy.top();
        ind=tap.top();
        map[x][y]=-ind-1;
        tapx.pop();
        tapy.pop();
        tap.pop();
    }

  
  //Draw out the array//
  print(map,size);
  

  

  
    return 0;
}
