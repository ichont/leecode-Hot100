#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std; 

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int result = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                left_max = max(left_max, height[left]);
                result += left_max - height[left];
                left++;
            } 
            else {
                right_max = max(right_max, height[right]);
                result += right_max - height[right];
                right--;
            }
        }
        return result;
    }
};

//法一：先输入n，再输入数组元素；法二：直接输入数组元素 
int main(){
	int num,result;
	vector<int> height;
	while(cin>>num){
		height.push_back(num);
		if (cin.get() == '\n') break;
	}
	Solution sol;
	result = sol.trap(height);
	printf("%d",result);
	return 0;
}
