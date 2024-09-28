#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Awwab_Lab5 {
public:
    bool carPooling(vector<vector<int>> trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
       multimap<int,int>map;
       for(int i=0;i<trips.size();i++){
         int cap=trips[i][0];
             map.insert(make_pair(trips[i][1],-cap));
             map.insert(make_pair(trips[i][2],cap));
       }
        for (auto i = map.begin(); i != map.end(); i++){
            capacity=capacity+i->second;
            if(capacity < 0) return false;
        }
       return true;
    }
};

int main() {
    Awwab_Lab5 lab;
    cout << "Input: [[2,1,5],[3,3,7]] capacity = 5" << endl;
    cout << "Output: " << boolalpha << lab.carPooling(vector<vector<int>>({{2, 1, 5}, {3, 1, 7}}), 5) << endl;

    cout << "Input: [[2,1,5],[3,3,7]] capacity = 4" << endl;
    cout << "Output: " << boolalpha << lab.carPooling(vector<vector<int>>({{2, 1, 5}, {3, 1, 7}}), 4) << endl;
    return 0;
}