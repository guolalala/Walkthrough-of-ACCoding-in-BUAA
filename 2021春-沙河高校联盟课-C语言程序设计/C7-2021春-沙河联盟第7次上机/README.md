# C7-2021春-沙河联盟第7次上机

# 给线段排排序

时间限制: 1000 ms 内存限制: 65536 kb

总通过人数: 121 总提交人数: 133

## 题目描述

开花学长手上有一堆在一维数轴上的线段，现在他想把这些线段捋清楚，你能帮帮他吗？

具体来说，有 n 条线段，线段的左端坐标为 L, 右端坐标为 R （保证 L<R）。具体的排序要求如下：

- 在左端坐标不一样的时候，按照左端坐标从小到大排序
- 在左端坐标相同的时候，按照右端坐标从小到大排序

## 输入

每个测试点有只有一组数据。

第一个为一个整数 n(1≤n≤1000) 表示一共有 n 条需要排序的线段。

接下来 nn 行，每行 22 个整数 L,R(0≤L<R≤100)，表示每条线段的左端和右端坐标。

值得注意的是，可能出现一模一样的线段，请将他们全部分别输出。

## 输出

一共输出 n 行，为 n 条线段从小到大排序之后的结果，每一行两个整数，为每条线段的左端和右端坐标，两个整数之间用一个空格分隔。

## 输入样例

```
3
1 4
1 2
2 3
```

## 输出样例

```
1 2
1 4
2 3
```

## HINT

冒泡排序，选择排序，计数排序，`qsort`快速排序均可通过本题。

如果觉得开两个数组太麻烦，不如试试结构体呢？

结构体的定义可以写成以下形式:

```
struct section {
    int l, r;//左端点和右端点
};
struct section temp;//声明一个结构体变量
struct section a[1010];//声明一个结构体数组
```

交换的时候类似int的交换方式即可。

```
//假设需要交换section结构体变量a和b
struct section temp=a;
a=b;
b=temp;
```

*Author: 计组OO两开花*

## 思路

本题思路较多，冒泡排序，快速排序，计数排序均可通过。