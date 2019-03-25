#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

#define ll long long

using namespace std;

long minBook;

class Booking{
public:
    long start;
    long end;
    long len;
    Booking(long _start, long _end){
        start = _start;
        end = _end;
        len = end - start;
    }
    void eval(){

    }

    bool operator < (const Booking& str) const
    {
        return (len < str.len);
    }
};


int main(){
    int cases = 0;
    cin >> cases;
    for(int C = 0; C < cases; C++){
        long N, Q;
        cin >> N >> Q;

        vector<Booking> B;
        vector<int> S;

        for(int i = 0; i < N; i ++)
            S.push_back(1);
        
        for(int i = 0; i < Q; i++){
            int S,E;
            cin >> S >> E;
            B.push_back(Booking(S,E));
        }

        sort(B.begin(),B.end());
        minBook = B[0].len;
        long curr = 0;

        while(B.begin() < B.end()){
            if(B[0].len == len){
                
                
            }
            else{
                for(int i = 0; i < B.size(); i++){
                    B[i].eval();
                }
                sort(B.begin(),B.end());
            }

        
        }

    
    
    }




}