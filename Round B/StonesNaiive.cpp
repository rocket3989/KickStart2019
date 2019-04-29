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

    int S,E,L,lost;

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
            int maxScore = -1;
            int best = 0;
            int total = 0;

            for(int i = 0; i < stones.size(); i++){

                int val = stones[i].L * stones[i].S;

                if(val > stones[i].E)
                    val = stones[i].E;

                if(val > maxScore || maxScore == -1){
                    best = i;
                    maxScore = val;
                }
            
            } 

            points += stones[best].E;
            int timefor = stones[best].S;
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