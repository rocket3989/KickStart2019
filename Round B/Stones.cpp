#include <iostream>
#include <unordered_map> 
#include <vector>
#include <cstdlib>
#include <utility>
#include <string>
#include <math.h>
#include <set>
#include <map>

using namespace std;

class Stone {

public:

    int S,E,L;

    Stone (int _S, int _E, int _L) {
        S = _S;
        E = _E;
        L = _L;    
    }

};



int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for(int test = 1; test < T + 1; test++){

        vector<Stone> stones;
        int N, S, E, L;
        cin >> N;

        for(int i = 0; i < N; i++){
            cin >> S >> E >> L;
            stones.push_back(Stone(S,E,L));
        }

        int points = 0;

        while(stones.size() > 0){
            int minScore = -1;
            int best = 0;
            int timefor;

            for(int i = 0; i < stones.size(); i++){
                timefor = stones[i].S;
                int sum = 0;

                for(int j = 0; j < stones.size(); j++){
                    if(i == j)
                        continue;
                    
                    int lost = stones[j].L * timefor;

                    int remaining = stones[j].E;

                    if(lost > remaining)
                        sum += remaining;
                    else
                        sum += lost;

                }
                if(sum < minScore || minScore == -1){
                    best = i;
                    minScore = sum;
                }
            
            }
            


            points += stones[best].E;
            timefor = stones[best].S;
            stones.erase(stones.begin() + best);


            for(int i = stones.size() - 1; i > -1; i--){
                stones[i].E -= stones[i].L * timefor;

                if(stones[i].E <= 0)
                    stones.erase(stones.begin() + i);
            }


        }

    cout << "Case #" << test << ": " << points << endl;

        


    }
}


/*
1 3 
10 4 1000
10 3 1000
10 8 1000


1 4
20 10 1
5 30 5
100 30 1
5 80 60

1 2
12 300 50
5 200 0



*/
