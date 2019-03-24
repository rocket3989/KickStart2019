#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int net [250][250] = {0};

void evalNet(int R, int C){
    bool found = true;
    int nextVal = 0;
    while(found){

        found = false;

        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if(net[r][c] == nextVal){

                    if(r > 0 && net[r-1][c] > nextVal + 1){
                        found = true;
                        net[r-1][c] = nextVal + 1;
                    }

                    if(r < R - 1 && net[r+1][c] > nextVal + 1){
                        found = true;
                        net[r+1][c] = nextVal + 1;
                    }

                    if(c > 0 && net[r][c-1] > nextVal + 1){
                        found = true;
                        net[r][c-1] = nextVal + 1;
                    }

                    if(c < C - 1 && net[r][c+1] > nextVal + 1){
                        found = true;
                        net[r][c+1] = nextVal + 1;
                    }
                }
            }
        }

        nextVal++;
    }
}

void printNet(int R,int C){
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            cout << net[r][c];
        }
        cout <<'\n';
    }
}

int main(){
    int tests = 0;
    cin >> tests;
    for(int test = 0; test < tests; test++){
        int R, C, max = 0;
        char input;
        
        cin >> R >> C;

        for(int r = 0; r < R; r++){         //read input
            for(int c = 0; c < C; c++){
                cin >> input;
                if(input == '0')
                    net[r][c] = 1000;
                else
                    net[r][c] = 0;
            }
        } 


        evalNet(R,C);       //build the network

        printNet(R,C);

        vector <int> row;
        vector <int> col;



        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if(max < net[r][c]){        //find what the biggest is
                    max = net[r][c];
                    row.clear();
                    col.clear();
                }
                
                if (max == net[r][c]){
                    row.push_back(r);       //add each instance of biggest to ordered pair
                    col.push_back(c);
                }
            }
        }
        
        bool found = false;
        int best;
        for(int i = 0; i < row.size() && !found; i++){
            bool inRange = true;
            for(int j = 0; j < row.size() && inRange; j++){
                if(abs(row[i]-row[j]) + abs(col[i] - col[j]) > max - 1)
                    inRange = false;
            }
            if(inRange){
                best = i;
                found  = true;
            }
        }

        if(found){
            net[row[best]][col[best]] = 0;

            evalNet(R,C);

            printNet(R,C);
            
            max = 0;
            for(int r = 0; r < R; r++)
                for(int c = 0; c < C; c++)
                    if(max < net[r][c])
                        max = net[r][c];

        }

        cout << "Case #" << test + 1 << ": "<< max << endl;
        
    }
}

/*
6
3 3
101
000
101
1 2
11
5 5
10001
00000
00000
00000
10001
10 10
1000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000001
5 7
1110111
1100011
1000001
1100011
1111111
9 5
11101
11000
10000
00000
00000
00000
00001
00011
10111

*/
