#include <iostream>

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
        int R, C, max = 0, x = 0, y = 0;
        char input;
        
        cin >> R >> C;

        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                cin >> input;
                if(input == '0')
                    net[r][c] = 1000;
                else
                    net[r][c] = 0;
            }
        } //read input

        //printNet(R,C);

        evalNet(R,C);

        printNet(R,C);

        int maxadj = 0;

        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if(max < net[r][c]){        //find where biggest is
                    max = net[r][c];
                    maxadj = -1;
                }
                
                if (max == net[r][c]){
                    int adj = 0;
                    if(r > 0 && net[r-1][c] == max)
                        adj++;
                    
                    if(r < R - 1 && net[r+1][c] == max)
                        adj++;
                
                    if(c > 0 && net[r][c-1] == max)
                        adj++;
                    
                    if(c < C - 1 && net[r][c+1] == max)
                        adj++;
                    
                    if(adj > maxadj){
                        x = r;
                        y = c;
                        maxadj = adj;
                    }
                }
            }
        }
        cout << maxadj << '\n' << '\n';

        net[x][y] = 0;

        //cout << "X is: " << x << " Y is: " << y << '\n';
        
        evalNet(R,C);

        printNet(R,C);
        
        max = 0;
        for(int r = 0; r < R; r++)
            for(int c = 0; c < C; c++)
                if(max < net[r][c])
                    max = net[r][c];

        cout << "Case #" << test + 1 << ": "<< max << endl;
        
    }
}