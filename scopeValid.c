/*************************************************************************
    > File Name: scopeValid.c
    > Author: 宋伟帅
    > Mail: songweishuai@thunder.com.cn 
    > Created Time: 2018年11月13日 星期二 15时42分55秒
 ************************************************************************/

#include<stdio.h>
void main()
{
	int *p=NULL;
	if(1)
	{
		int a=11;
		p=&a;
		printf("a == %ld\n",&a);
	}
	printf("p == %ld\n",*p);
	*p=10;
	printf("p == %ld\n",*p);
}
