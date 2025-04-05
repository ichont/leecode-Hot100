#include <iostream>
#include <vector>
#include <algorithm>  // ��Ҫ����algorithmͷ�ļ�ʹ��max����

using namespace std;

class Solution {
public:
	//�Լ�д�ı���������ʱ�� 
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
    //˫ָ�� 
    int maxAreaX(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        
        while (left < right) {
            // ���㵱ǰ�������������� �� ��С�߶�
            int current_height = min(height[left], height[right]);
            int width = right - left;
            max_area = max(max_area, width * current_height);
            
            // �ƶ��϶̵ıߣ������ҵ����ߵıߣ�
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
    // ����ʾ�������磺1 8 6 2 5 4 8 3 7��
    while (cin >> num) {
        height.push_back(num);
        if (cin.get() == '\n') break; // �س���������
    }
    
    Solution sol;
    cout << sol.maxAreaX(height) << endl;
    printf("���"); 
    return 0;
}
