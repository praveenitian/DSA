class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();

        int total=0;
        for(auto& it:nums) total+=it;
        int target=total-x;

        if(target<0) return -1;
        if(target==0) return n;

        int l=0;
        int curr=0;
        int res=-1;

        for(int r=0;r<n;r++){
            curr=curr+nums[r];

            while(curr>target){
                curr=curr-nums[l];
                l++;
            }

            if(curr==target){
                res=max(res,r-l+1);
            }
        }

        if(res==-1) return -1;

        return n-res;
    }
};