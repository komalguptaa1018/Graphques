class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int N=nums.size();
        int j=0;
        for(int i=0;i<N;i++){
            if(nums[i]!=val){
                 nums[j]=nums[i];
            j++;
            }
           


        }
        return j;
    }
};