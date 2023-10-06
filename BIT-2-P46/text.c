#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//数据的储存（进阶）作业
//回调函数等，作业
//int main()
//{
//	int a[5] = { 5,4,3,2,1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));//4,1
//	return 0;
//}

//指针的进阶作业
//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);//数组的地址
//	int* ptr2 = (int*)(*(aa + 1));//首元素的地址
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//1,6
//	return 0;
//}

//题目内容：旋转字符串
//实现一个函数，可以左旋字符串中的K个字符
//abcd  左旋一个字符  bcda
//abcd  左旋两个字符  cdab
//
#include <string.h>
#include <assert.h>
//1.暴力求解法
//void left_move(char* arr, int k)
//{
//	assert(arr != NULL);
//	int i = 0;
//	int len = strlen(arr);
//	for (i = 0; i < k; i++)
//	{
//		//左旋一个字符
//		//1.
//		char tmp = *arr;
//		//2.
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//		//3.
//		*(arr + len - 1) = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	left_move(arr, 2);
//	printf("%s\n", arr);
//	return 0;
//}

//2.三步反转法
void reverse(char* left, char* right)//字符串逆序函数
{
	assert(left);
	assert(right);
	while (left<right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	assert(k <= len);
	reverse(arr,arr+k-1);//逆序左边
	reverse(arr+k,arr+len-1);//逆序右边
	reverse(arr,arr+len-1);//逆序整体
}
//int main()
//{
//	char arr[] = "abcdef";
//	left_move(arr, 2);
//	printf("%s\n", arr);
//	return 0;
//}

//写一个函数，判断一个字符串是否为一个字符串旋转之后的字符串
// abcdef
// bcdefa
// cdefab
// defabc
// efabcd
// fabcde
//方案一
//int is_left_move(char* s1, char* s2)
//{
//	assert(s1);
//	assert(s2);
//	int len = strlen(s1);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		left_move(s1, 1);
//		int ret = strcmp(s1, s2);
//		if (ret == 0)
//			return 1;
//	}
//	return 0;
//}

//优化方案
//abcdef abcdef//包含上方所以可能性

//int is_left_move(char* str1, char* str2)
//{
//	int len1 = strlen(str1);
//	int len2 = strlen(str2);
//	if (len1 != len2)//长度不一样直接return 0
//	{
//		return 0;
//	}
//	//1.在str1字符串中追加一个str1字符串
//	//strcat(str1, str1); //---err不能自己追加自己
//	strncat(str1, str1, len1);
//
//	//2.判断str2指向的字符串是否为str1指向字符串的子串
//	//strstr-找子串
//	char* ret = strstr(str1, str2);
//	if (ret == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[] = "defab";
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//	{
//		printf("YES\n");
//	}
//	else
//	{
//		printf("NO\n");
//	}
//	return 0;
//}

//杨氏矩阵
//有一个数字矩阵，矩阵的每一行从左到右是递增的，每列从上到下递增，编写程序在这样的矩阵中查找某个数字
//要求时间复杂度小于O(n)
int FindNum(int(*p)[3], int k, int* row, int* col)
{
	//1.找到右上角元素位置
	int x = 0;
	int y = *col - 1;
	//2.b比较右上角元素大小
	while (x <= *row - 1 && y >= 0)
	{
		if (p[x][y] > k)//如果大于比较的数
		{
			y--;//列减一列
		}
		else if (p[x][y] < k)
		{
			x++;//行加一行
		}
		else
		{
			//printf("下标是：%d %d\n", x, y);
			*row = x;
			*col = y;
			return 1;
		}
	}
	//找不到
	*row = -1;
	*col = -1;
	return 0;
}
int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 0;
	int x = 3;
	int y = 3;
	//返回型参数
	int ret = FindNum(arr, k, &x, &y);
	if (ret == 1)
	{
		printf("找到了\n");
		printf("下标是：%d %d", x, y);
	}
	else
	{
		printf("找不到\n");
		printf("下标是：%d %d", x, y);
	}
	return 0;
}






