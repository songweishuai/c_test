/*************************************************************************
    > File Name: parameter.c
    > Author: 宋伟帅
    > Mail: songweishuai@thunder.com.cn 
    > Created Time: 2019年02月20日 星期三 15时15分53秒
 ************************************************************************/

#include<stdio.h>

int main(int argc,char* argv[])
{
	int n=0;
	printf("argc == %d\n",argc);
	for(n=0;n<argc;n++)
	{
		printf("argv[%d]=%s\n",n,argv[n]);
	}

	//printf("argv[%d]=%s\n",10,argv[10]);
}
