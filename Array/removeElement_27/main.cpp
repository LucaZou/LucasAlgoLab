#include<vector>
#include<iostream>
using namespace std;
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int slow = 0;
            for (int fast = 0; fast < nums.size(); fast++) {
                if (nums[fast] != val) {
                    nums[slow++] = nums[fast];
                }
            }
            return slow;
        }
    };

int main(){
    Solution s;
    vector<int> nums = {3,2,2,3};
    int val = 3;
    cout << s.removeElement(nums, val) << endl;
    return 0;
}