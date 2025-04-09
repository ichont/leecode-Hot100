#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n;
	vector<int> num;
	while(cin>>n) {
	num.push_back(n);
	if(cin.get() == '\n') break;
	}
	sort(num.begin(),num.end());
	//for i=0直接遍历输出num[i]
	printf("{");
	for(int i=0;i<num.size();i++){
		printf("%d",num[i]);
		if(i<num.size()-1) printf(" ");
	}
	printf("}");
	return 0;
}
 
