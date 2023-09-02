/*
 * @Author: dongpeng dongpeng@hypersilicon.com
 * @Date: 2023-08-28 15:35:02
 * @LastEditors: dongpeng dongpeng@hypersilicon.com
 * @LastEditTime: 2023-08-28 17:33:15
 * @FilePath: /test/struct_test.c
 * @Description: 
 * 
 * Copyright (c) 2023 by dongpeng dongpeng@hypersilicon.com, All Rights Reserved. 
 */
#include <stdio.h>

struct mystruct{
    char a;
    char b;
    int c;
};

int main(void)
{
    struct mystruct test = {1, 1, 32};
    char *p1 = &test.a;
    char *p2 = &test.c;
    char *p3 = &test.b;
    
    printf("a value = %d, a addr = %x\n", *p1, p1);
    printf("b value = %d, b addr = %x\n", *(p2-3), p2);
    printf("c value = %d, c addr = %x\n", *(p2), p2);
    printf("b value = %d, b addr = %x\n", *(p3), p3);

    return 0;
}