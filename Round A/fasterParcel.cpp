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
vector<pair <int,int>> centers;
vector<pair <int,int>> points;

int net [250][250] = {0};

int R, C;



void evalNet(){
    points = centers;
    
    int count = 0;
    while(count < points.size()){

        int r = points[count].x, c = points[count].y;

        if(r > 0 && net[r-1][c] > net[r][c] + 1){
            net[r-1][c] = net[r][c] + 1;
            points.push_back(make_pair(r-1,c));
        }

        if(r < R - 1 && net[r+1][c] > net[r][c] + 1){
            net[r+1][c] = net[r][c] + 1;
            points.push_back(make_pair(r+1,c));
        }

        if(c > 0 && net[r][c-1] > net[r][c] + 1){
            net[r][c-1] = net[r][c] + 1;
            points.push_back(make_pair(r,c-1));
        }

        if(c < C - 1 && net[r][c+1] > net[r][c] + 1){
            net[r][c+1] = net[r][c] + 1;
            points.push_back(make_pair(r,c+1));
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

    int tests = 0;
    cin >> tests;
    for(int test = 0; test < tests; test++){
        centers.clear();
        char input;
        
        cin >> R >> C;

        for(int r = 0; r < R; r++){         //read input
            for(int c = 0; c < C; c++){
                cin >> input;
                if(input == '0')
                    net[r][c] = 1000;
                else{
                    net[r][c] = 0;
                    centers.push_back(make_pair(r,c));
                }
            }
        } 


        evalNet();       //build the network

        printNet();


        vector<pair <int,int>> maxpoints;
        
        int pos = points.size()-1;
        int max = net[points[pos].x][points[pos].y];

        while(true){
            if (pos < 0 || max != net[points[pos].x][points[pos].y])
                break;
            else    
                maxpoints.push_back(points[pos]);
            pos--;
        }
        
        for(int ro = 0; ro < R; ro++)
            for(int co = 0; co < C; co++)
                if(net[ro][co] != 0)
                    net[ro][co] = 100;

        int score = max;
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                int sum = 0;
                bool match = true;
                for(int i = 0; i < maxpoints.size(); i++){
                    if(abs(r-maxpoints[i].x) + abs(c - maxpoints[i].y) > max - 1){
                        match = false;
                        break;
                    }
                }
                if(match){
                    net[r][c] = 0;
                    centers.push_back(make_pair(r,c));
                    evalNet();
                    printNet();
                    cout << "score of grid: " << net[points[points.size()-1].x][points[points.size()-1].y] << '\n';
                    score = minOf(score,net[points[points.size()-1].x][points[points.size()-1].y]);

                    centers.pop_back();
                    net[r][c] = 100;
                    for(int ro = 0; ro < R; ro++)
                        for(int co = 0; co < C; co++)
                            if(net[ro][co] != 0)
                                net[ro][co] = 100;
                    
                }
            }
        }



        //evalNet();

       // printNet();
        

        
        cout << "Case #" << test + 1 << ": "<< score << endl;
    }
}

/*
7
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


