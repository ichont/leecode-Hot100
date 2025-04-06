class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        //�ؼ�����֮����ȷ����Ψһ������˫ָ���߼�
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int l = i+1, r = n-1;
            int target = -nums[i];
            while(l < r){
                if(nums[l]+nums[r] == target){
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++,r--;
                    while(l < r && nums[l] == nums[l-1]){
                        l++;
                    }
                    while(l < r && nums[r] == nums[r+1]){
                        r--;
                    }
                }
                else if(nums[l]+nums[r] < target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return res;
    }
};
