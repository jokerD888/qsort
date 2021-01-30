#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

           //目标数组地址   数组元素个数               返回int                    空类型元素
//void qsort(void* base, size_t num, size_t width, int(__cdecl* compare)(const void* elem1, const void* elem2));
//                                     每个元素大小    元素大小比较函数

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void test1()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(arr + i));
	}
}
int cmp_float(const void* e1, const void* e2)
{
	/*if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 > *(float*)e2)
		return 1;
	else return -1;*/
	return (int)(*(float*)e1 - *(float*)e2);
}
void test2()
{
	float f[] = { 9.0,8.0,7.0,6.0,5.0,4.0,3.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_float);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", *(f + i));
	}

}

struct Stu
{
	char name[20];
	int age;
};
int cmp_stu_by_age(const void* e1,const void* e2)//按年龄排序
{
	
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void test3()
{
	struct Stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",25} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}
int main(void)
{
	//test1();
	//test2();
	test3();
	return 0;
}