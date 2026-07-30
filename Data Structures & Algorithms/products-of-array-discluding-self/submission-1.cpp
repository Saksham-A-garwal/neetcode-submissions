class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int pro = 1;
        bool isOneZero = false , isMoreZeros = false;
        for(int num : nums){
            if(num == 0){
                if(!isOneZero) isOneZero = true;
                else isMoreZeros = true;
                continue;
            }
            pro *= num;
        }

        vector<int> res(n,0);

        if(isMoreZeros) return res;

        for(int i=0;i<n;i++){
            if(isOneZero){
                if(nums[i] == 0) res[i] = pro;
            }else{
                res[i] = (pro / nums[i]);
            }
        }

        return res;

    }
};
