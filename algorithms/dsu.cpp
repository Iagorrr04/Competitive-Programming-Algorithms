// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

class DSU{
    private:
        vector<int> ps;
        vector<int> size;
    public:
        DSU(int N) : ps(N+1), size(N+1, 1){
            iota(ps.begin(), ps.end(), 0);
        }
        
        // to find wich set x belongs.
        int find_set(int x){
            return ps[x] == x ? x : ps[x] = find_set(x);
        }
        bool same_set(int x, int y){
            return find_set(x) == find_set(y);
        }
        
        
        // join two distinct sets.
        void union_set(int x, int y){
            if(same_set(x, y))
                return;

            int px = find_set(x);
            int py = find_set(y);

            // let the bigger one be px.
            if(size[px] < size[py]) swap(px, py);

            ps[py] = px;
            size[px] += size[py];
        }
};   

int main(){
    return 0;
}