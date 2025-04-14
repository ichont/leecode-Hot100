# C++算法随想录

#### vector容器用法

定义一个vector

```c++
#include<vector>
//定义一个存储整型数字的数组
vector<int> num;//定义一个空的vector
```

初始化vector大全

```c++
vector<int> num={1,2,3,4}//初始化num数组1234
```

vector的基本访问

```c++
int s = num[0];//访问num的第一个元素
int front = num.front();//访问第一个元素
int end = num.back();//访问最后一个元素
num.push_back(50);//添加元素50到队尾
num.pop_back()//删除最后一个元素
num.clearn();//清空num
```

vector应用

```c++
int number = num.size();//查看num中有多少个元素
num.empty();//判断是否为空，空返回1，通常搭配if使用
```

向vector输入

```c++
```



#### 快捷排序

```c++
#include<algorithm>//引用头文件
vector<int> num;
sort(num.begin(),num.end());//升序排序一个vector数组
sort(num.end(),num.begin());//降序
```

```c++
int arr[] = {1,2,3,4};
int n = sizeof(arr)/sizeof(arr[0]);//求普通数组数量
sort(arr,arr+n);
```
