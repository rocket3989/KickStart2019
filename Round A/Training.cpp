#include <iostream>
#include <vector>
#include <algorithm> 

#define ll long long

using namespace std;




int main(){
    int cases = 0;
    cin >> cases;
    for(int C = 0; C < cases; C++){
        int min, N, P, F = 0, input;
        vector<int> S;

        cin >> N >> P;
        
        for(int i = 0; i < N; i++){
            cin >> input;
            S.push_back(input);
        }

        sort(S.begin(),S.end());

        for(int i = 0; i < P - 1; i++)
            F += (S[P-1] - S[i]);
        min = F;
        
        for(int i = P; i < N; i++){
            F += (S[i] - S[i-1]) * (P-1) - (S[i-1] - S[i - P]);
            if(F < min)
                min = F;
        }
        
        cout << "Case #" << C + 1 << ": "<< min << endl;
        
    }
}