#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//���ݵĴ��棨���ף���ҵ
//�ص������ȣ���ҵ
//int main()
//{
//	int a[5] = { 5,4,3,2,1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));//4,1
//	return 0;
//}

//ָ��Ľ�����ҵ
//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);//����ĵ�ַ
//	int* ptr2 = (int*)(*(aa + 1));//��Ԫ�صĵ�ַ
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//1,6
//	return 0;
//}

//��Ŀ���ݣ���ת�ַ���
//ʵ��һ�����������������ַ����е�K���ַ�
//abcd  ����һ���ַ�  bcda
//abcd  ���������ַ�  cdab
//
#include <string.h>
#include <assert.h>
//1.������ⷨ
//void left_move(char* arr, int k)
//{
//	assert(arr != NULL);
//	int i = 0;
//	int len = strlen(arr);
//	for (i = 0; i < k; i++)
//	{
//		//����һ���ַ�
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

//2.������ת��
void reverse(char* left, char* right)//�ַ���������
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
	reverse(arr,arr+k-1);//�������
	reverse(arr+k,arr+len-1);//�����ұ�
	reverse(arr,arr+len-1);//��������
}
//int main()
//{
//	char arr[] = "abcdef";
//	left_move(arr, 2);
//	printf("%s\n", arr);
//	return 0;
//}

//дһ���������ж�һ���ַ����Ƿ�Ϊһ���ַ�����ת֮����ַ���
// abcdef
// bcdefa
// cdefab
// defabc
// efabcd
// fabcde
//����һ
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

//�Ż�����
//abcdef abcdef//�����Ϸ����Կ�����

//int is_left_move(char* str1, char* str2)
//{
//	int len1 = strlen(str1);
//	int len2 = strlen(str2);
//	if (len1 != len2)//���Ȳ�һ��ֱ��return 0
//	{
//		return 0;
//	}
//	//1.��str1�ַ�����׷��һ��str1�ַ���
//	//strcat(str1, str1); //---err�����Լ�׷���Լ�
//	strncat(str1, str1, len1);
//
//	//2.�ж�str2ָ����ַ����Ƿ�Ϊstr1ָ���ַ������Ӵ�
//	//strstr-���Ӵ�
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

//���Ͼ���
//��һ�����־��󣬾����ÿһ�д������ǵ����ģ�ÿ�д��ϵ��µ�������д�����������ľ����в���ĳ������
//Ҫ��ʱ�临�Ӷ�С��O(n)
int FindNum(int(*p)[3], int k, int* row, int* col)
{
	//1.�ҵ����Ͻ�Ԫ��λ��
	int x = 0;
	int y = *col - 1;
	//2.b�Ƚ����Ͻ�Ԫ�ش�С
	while (x <= *row - 1 && y >= 0)
	{
		if (p[x][y] > k)//������ڱȽϵ���
		{
			y--;//�м�һ��
		}
		else if (p[x][y] < k)
		{
			x++;//�м�һ��
		}
		else
		{
			//printf("�±��ǣ�%d %d\n", x, y);
			*row = x;
			*col = y;
			return 1;
		}
	}
	//�Ҳ���
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
	//�����Ͳ���
	int ret = FindNum(arr, k, &x, &y);
	if (ret == 1)
	{
		printf("�ҵ���\n");
		printf("�±��ǣ�%d %d", x, y);
	}
	else
	{
		printf("�Ҳ���\n");
		printf("�±��ǣ�%d %d", x, y);
	}
	return 0;
}






