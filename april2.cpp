//To do
//Code a O(n) solution

//Problem Link
https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/?envType=daily-question&envId=2025-04-02

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> maxArr(n+2,0);
        for(int i=n-1;i>=0;i--){
            maxArr[i] = max(maxArr[i+1],(long long)nums[i]);
        }
        long long ans = 0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n-1;j++){
                ans = max(ans,(nums[i]-nums[j])*maxArr[j+1]);
            }
        }

        return ans;
    }
};