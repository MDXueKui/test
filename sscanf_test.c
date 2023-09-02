/*
 * @Author: dongpeng dongpeng@hypersilicon.com
 * @Date: 2023-08-28 17:43:16
 * @LastEditors: dongpeng dongpeng@hypersilicon.com
 * @LastEditTime: 2023-08-28 18:13:07
 * @FilePath: /test/sscanf_test.c
 * @Description: 
 * 
 * Copyright (c) 2023 by dongpeng dongpeng@hypersilicon.com, All Rights Reserved. 
 */
#include <stdio.h>

int main(void)
{
    char *tmpBuffer;
    char *a = "batch,--source";

    sscanf(a, "%[^,]", &tmpBuffer);
    printf("tmpBuffer = %s\n", tmpBuffer);
    // printf("BatchPatch = %s\n", BatchPatch);

    return 0;
}