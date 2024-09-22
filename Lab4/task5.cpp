#include <iostream>
#include <vector>

using namespace std;

class Awwab_Lab4 {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};

        for (int num : nums) {
            count[num]++;
        }

        int index = 0;
        for (int i = 0; i < 3; i++) {
            while (count[i] > 0) {
                nums[index++] = i;
                count[i]--;
            }
        }
    }

    void print(const vector<int>& nums) {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    Awwab_Lab4 lab;
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Original array: ";
    lab.print(nums);

    lab.sortColors(nums);

    cout << "Sorted array: ";
    lab.print(nums);

    return 0;
}
