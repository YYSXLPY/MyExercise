#include <stdio.h>
#include <malloc.h>  //包含malloc函数
#include <stdlib.h>  //包含exit函数

struct Arr
{
	int * pBase; //数组储存的首元素的地址
	int len;// 数组长度
	int cnt;//有效元素个数
};

void init_arr(struct Arr * pArr, int length);//函数声明要有封号
bool append_arr(struct Arr* pArr, int val);
bool insert_arr(struct Arr* pArr, int pos, int val);
bool delete_arr(struct Arr* pArr, int pos, int* pval);
int get();
bool is_full(struct Arr * pArr);
bool is_empty(struct Arr* pArr);
void sort_arr(struct Arr* pArr);
void inverse_arr(struct Arr* pArr);
void show_arr(struct Arr* pArr);
void swap(int *a, int *b);



int main(void)
{
	struct Arr arr;
	int val;

	init_arr(&arr,6);
	show_arr(&arr);

	append_arr(&arr, 1);
	append_arr(&arr, 5);
	append_arr(&arr, -3);
	append_arr(&arr, 4);
	show_arr(&arr);

	insert_arr(&arr, 3, 77);
	show_arr(&arr);


	/*delete_arr(&arr, 2, &val);
	show_arr(&arr);*/

	inverse_arr(&arr);
	printf_s("\n\n\n倒置后的数组为：\n");
	show_arr(&arr);

	sort_arr(&arr);
	show_arr(&arr);

	return 0; 
}

void init_arr(struct Arr * pArr,int length)
{   
	pArr->pBase = (int*)malloc(sizeof(int) * length);
	if (NULL == pArr->pBase)
	{
		printf_s("动态内存分配失败！\n");
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
		
	}
	return;
 }

bool is_empty(struct Arr* pArr)
{
	if (pArr->cnt == 0)
		return true;
	else
		return false;
}

bool is_full(struct Arr* pArr)
{
	if (pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

void show_arr(struct Arr * pArr)
{
	if (is_empty(pArr))
		printf_s("数组为空！\n");
	else
	{
		int i;
		for ( i= 0; i < pArr->cnt; ++i)
			printf_s("%d  ", pArr->pBase[i]);
		printf_s("\n");
		    
	}
	
}


bool append_arr(struct Arr* pArr, int val)
{
	if (is_full(pArr))
		return false;
	else
	{
		pArr->pBase[pArr->cnt] = val;
		pArr->cnt ++;
		return true;
	}
}

bool insert_arr(struct Arr* pArr, int pos, int val)
{
	if (is_full(pArr))
		return false;
	if (pos<1 || pos>(pArr->cnt + 1))
		return false;
	for (int i = pArr->cnt; i > pos-1;i--)
	{
		pArr->pBase[i] = pArr->pBase[i - 1];
	}
	pArr->pBase[pos - 1] = val;
	pArr->cnt++;
	return true;

}

bool delete_arr(struct Arr* pArr, int pos, int* pval)
{
	if (is_empty(pArr))
		return false;
	if (pos<1 || pos>pArr->cnt)
		return false;
	*pval = pArr->pBase[pos - 1];
	printf_s("您删除的元素是:%d\n", * pval);
	for (int i = pos; i < pArr->cnt; i++)
		pArr->pBase[i - 1] = pArr->pBase[i];
	pArr->cnt--;
	return true;
}

void inverse_arr(struct Arr* pArr)
{
	int i =0;
	int j=pArr->cnt-1;
	int t;

	while (i<j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		i++;
		j--;

	}
	return;
}

void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
	return;
 
}
void sort_arr(struct Arr* pArr)
{
	for (int i = 0; i < pArr->cnt; i++)
	{
		for (int j = i+1; j <pArr->cnt ; j++)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
				swap(pArr->pBase + i, pArr->pBase + j);

		}
	}
	return;
}
