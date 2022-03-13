class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, ans=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                ans=nums[i];
            }
            if(nums[i]==ans){
                count = count+1;
            }
            else{
                count = count-1;
            }
        }
        return ans;
    }
};