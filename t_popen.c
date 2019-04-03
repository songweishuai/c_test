/*************************************************************************
    > File Name: t_popen.c
    > Author: 宋伟帅
    > Mail: songweishuai@thunder.com.cn 
    > Created Time: 2019年04月03日 星期三 10时40分30秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main()
{
	FILE *pp = popen("date","r");
	if(!pp)
	{
		return 0;	
	}

	char tmp[1024]="";
	while(fgets(tmp,sizeof(tmp),pp)!=NULL)
	{
		//if(tmp[strlen(tmp)-1] == '\n')
		//{
		//	tmp[strlen(tmp)-1]='\0';
		//}
	}

	pclose(pp);
	printf("%s",tmp);
}
