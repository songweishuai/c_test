/*************************************************************************
    > File Name: tsterm.c
    > Author: 宋伟帅
    > Mail: songweishuai@thunder.com.cn 
    > Created Time: 2019年01月10日 星期四 10时33分31秒
 ************************************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
        char *tty=ttyname(1);
        if(tty!=NULL)
        {
                printf("%s\n",tty);
        }
}

