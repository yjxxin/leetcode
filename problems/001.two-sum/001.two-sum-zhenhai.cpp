#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// QUESTION
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> m;
        for(int i=0; i < int(nums.size()); i++){
            if(m.find(target - nums[i]) == m.end()){
                m[nums[i]] = i;
            }else{
                result.push_back(m[target - nums[i]]);
                result.push_back(i);
            }
        }
        return result;
    }
};

int main(){
    int arr[4] = {2, 7, 11, 15};
    vector<int> nums(arr, arr+4);
    int target = 9;
    vector<int> result;

    Solution solution;
    result = solution.twoSum(nums, target);
    cout << "result: " << result[0] << "," << result[1] << endl;
    return 0;
}