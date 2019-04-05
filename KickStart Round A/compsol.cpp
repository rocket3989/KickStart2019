#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>
#include <cstdlib>
#include <ctime>

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

int R = 20, C = 20;



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
    int counter = 0;
    srand(time(NULL));

    while(true){

        centers.clear();

        for(int r = 0; r < R; r++){         //build grid
            for(int c = 0; c < C; c++){
                if(rand() % 20 < 19)
                    net[r][c] = 1000;
                else{
                    net[r][c] = 0;
                    centers.push_back(make_pair(r,c));
                }
            }
        } 


        evalNet();       //build the network

        //printNet();








        //    alg1


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
                    //printNet();
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








        //alg 2;


        int score1 = net[points[points.size()-1].x][points[points.size()-1].y];
        
        for(int ro = 0; ro < R; ro++)
            for(int co = 0; co < C; co++)
                if(net[ro][co] != 0)
                    net[ro][co] = 100;

        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if(net[r][c] != 0){
                    net[r][c] = 0;

                    centers.push_back(make_pair(r,c));
                    evalNet();

                    //printNet();

                    score1 = minOf(score1,net[points[points.size()-1].x][points[points.size()-1].y]);


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
        char garbage;

        if(score1 != score){
            evalNet();
            printNet();
            cout << "fast score was " << score << "  correct ans was " << score1 << '\n';
            cin >> garbage;
        }
        else
            cout << "test " << counter++ << " passed\n";        
    }
}
