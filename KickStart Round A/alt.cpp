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
    cout <<'\n';

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


        int min = 100;

        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if(net[r][c] != 0){
                    net[r][c] = 0;
    
                    evalNet(R,C);
                    max = 0;
                    for(int ro = 0; ro < R; ro++)
                        for(int co = 0; co < C; co++)
                            if(max < net[ro][co])
                                max = net[ro][co];
                                
                    if(max < min)
                        min = max;
                    
                    net[r][c] = 100;
                    for(int ro = 0; ro < R; ro++)
                        for(int co = 0; co < C; co++)
                            if(net[ro][co] != 0)
                                net[ro][co] = 100;
                }
            }
        }
        

        
        cout << "Case #" << test + 1 << ": "<< min << endl;
    }
}