#include <iostream>
#include <vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int center = 0,len=nums.size();
        int preSum = 0, backSum = 0;
        while(center<=len){
            if(center==0){
                backSum = accumulate(nums.begin()+1, nums.end(), 0);
            }else{
                preSum += nums[center - 1];
                backSum -= nums[center];
            }
            if(backSum==preSum){
                return center;
            }else{
                center++;
            }
        }
        return -1;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {2,5};
    cout << solution.pivotIndex(nums);
    return 0;
}