//27382935	105	The Skyline Problem	Accepted	C++11	0.000	2022-04-05 14:08:49
#include <bits/stdc++.h>
using namespace std;

int main() {
    int l,h,r;
    vector<pair<int,int>> buildings;
    while(scanf("%d %d %d", &l, &h, &r) != EOF){
        buildings.push_back({l,h});
        buildings.push_back({r,-h}); 
    }
    sort(buildings.begin(),buildings.end(),[](pair<int,int>& a, pair<int,int>& b){

            if(a.first != b.first) return a.first < b.first;

            else if(a.second > 0 && b.second > 0)
                return a.second > b.second;

            else if(a.second < 0 && b.second < 0)
                return a.second > b.second;
            return a.second > 0; 
         }
    );

    multiset<int> height;
    height.insert(0);
    int maxHeight = 0;
    bool notfirst = false;
    for(auto& p : buildings){
        if(p.second < 0){
            height.erase(height.find(abs(p.second)));
        } else {
            height.insert(p.second);
        }
        int curMax = *prev(height.end());
        if(curMax != maxHeight){

            if(notfirst) cout << " ";
            notfirst = true;
            cout << p.first << " " << curMax;
            maxHeight = curMax;
        }
    }
    cout << endl;
}
