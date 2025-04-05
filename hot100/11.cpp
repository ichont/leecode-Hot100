#include <iostream>
#include <vector>
#include <algorithm>  // 需要包含algorithm头文件使用max函数

using namespace std;

class Solution {
public:
	//自己写的暴力遍历超时了 
    int maxArea(vector<int>& height) {
        int n = height.size();
        int lans=0,ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a = j-i;
                if(height[i]<height[j]) ans=a*height[i];
                else ans = a*height[j];
                lans=max(ans,lans);
            }
        }
        return lans;
    }
    //双指针 
    int maxAreaX(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        
        while (left < right) {
            // 计算当前容器的面积：宽度 × 较小高度
            int current_height = min(height[left], height[right]);
            int width = right - left;
            max_area = max(max_area, width * current_height);
            
            // 移动较短的边（可能找到更高的边）
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
    
};

int main() {
    vector<int> height;
    int num;
    // 输入示例（例如：1 8 6 2 5 4 8 3 7）
    while (cin >> num) {
        height.push_back(num);
        if (cin.get() == '\n') break; // 回车结束输入
    }
    
    Solution sol;
    cout << sol.maxAreaX(height) << endl;
    printf("你好"); 
    return 0;
}
