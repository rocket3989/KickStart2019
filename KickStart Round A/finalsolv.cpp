#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>

using namespace std;

#define x first
#define y second

typedef unsigned long long lli;


int maxOf(int a, int b){
    return (a > b ? a : b);
}

int minOf(int a, int b){
    return (a < b ? a : b);
}
vector<pair <int,int>> points;
vector<int> score;

int net [250][250] = {0};

int R, C;



void evalNet(){
    
    int count = 0;
    while(count < points.size()){

        int r = points[count].x, c = points[count].y;

        if(r > 0 && net[r-1][c] > net[r][c] + 1){
            net[r-1][c] = net[r][c] + 1;
            points.push_back(make_pair(r-1,c));
            score.push_back(net[r][c] + 1);
        }

        if(r < R - 1 && net[r+1][c] > net[r][c] + 1){
            net[r+1][c] = net[r][c] + 1;
            points.push_back(make_pair(r+1,c));
            score.push_back(net[r][c] + 1);
        }

        if(c > 0 && net[r][c-1] > net[r][c] + 1){
            net[r][c-1] = net[r][c] + 1;
            points.push_back(make_pair(r,c-1));
            score.push_back(net[r][c] + 1);
        }

        if(c < C - 1 && net[r][c+1] > net[r][c] + 1){
            net[r][c+1] = net[r][c] + 1;
            points.push_back(make_pair(r,c+1));
            score.push_back(net[r][c] + 1);
        }
        count++;
    }
}

void printNet(){
    cout <<'\n';    
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            cout << net[r][c] << ' ';
        }
        cout <<'\n';
    }
    cout <<'\n';

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tests = 0;
    cin >> tests;
    for(int test = 0; test < tests; test++){
        points.clear();
        score.clear();
        char input;
        
        cin >> R >> C;

        for(int r = 0; r < R; r++){         //read input
            for(int c = 0; c < C; c++){
                cin >> input;
                if(input == '0')
                    net[r][c] = 1000;
                else{
                    net[r][c] = 0;
                    points.push_back(make_pair(r,c));
                    score.push_back(0);
                }
            }
        } 


        evalNet();       //build the network

        //printNet();
        


        int pos_max = points.size()-1;
        int bin_max = score[pos_max];
        int bin_min = 0;
        int curr, pos;

        while(bin_max != bin_min){    

            curr  = (bin_max + bin_min) / 2;

            //cout << "b min is: " << bin_min << " b max is: " << bin_max << '\n';
            //cout << "checking " << curr << '\n';

            bool passed = false;

            for(int r = 0; r < R && !passed; r++){
                for(int c = 0; c < C && !passed; c++){
                    pos = pos_max;
                    bool failed = false;
                    while(!failed && pos >= 0 && curr < score[pos]){
                        if(abs(r-points[pos].x) + abs(c - points[pos].y) > curr){
                            //cout << "pos is: " << pos << '\n';
                            failed = true;
                            break;
                        }
                        pos--;
                    }
                    passed = !failed;
                }
            }

            //cout << "passed is: " << passed << '\n';
            if(!passed)
                bin_min = curr + 1;
            else 
                bin_max = curr;
            
        }



        //evalNet();

       // printNet();
        

        
        cout << "Case #" << test + 1 << ": "<< bin_max << endl;
    }
}

/*
8
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
3 5
10101
00000
10101
5 6
100010
000000
000000
000000
100010

*/


