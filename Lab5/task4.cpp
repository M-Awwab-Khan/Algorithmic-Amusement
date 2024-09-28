#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Awwab_Lab5 {
public:
    int findLHS(vector<int> nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, n = nums.size(), result = 0;

        while (j < n) {
            while (nums[j] - nums[i] > 1) {
                i += 1;
            }
            if (nums[j] - nums[i] == 1) {
                result = max(result, j - i + 1);
            }
            j++;
        }

        return result;
    }
};

int main() {
    Awwab_Lab5 lab;

    cout << "Input: (1,3,2,2,5,2,3,7)" << endl;
    cout << "Output: " << lab.findLHS(vector<int>({1,3,2,2,5,2,3,7})) << endl;

    return 0;
}
