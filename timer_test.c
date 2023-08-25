#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

int get_time(char *buff,int len);
int main(int argc, const char **argv)
{
    char buff[40];
    get_time(buff, sizeof(buff));
    printf("time:%s\n", buff);
    return 0;
}

int get_time(char *buff,int len)
{
	struct timeval tv;
    struct tm *ptm;
    char time_string[40];
    
    gettimeofday(&tv, NULL);
    ptm = localtime (&(tv.tv_sec));
    strftime (time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", ptm);  //输出格式为: 2022-03-30 20:38:37
    snprintf (buff, len, "%s", time_string);            
    return 0;
}
