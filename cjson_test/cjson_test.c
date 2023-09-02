/*
 * @Author: dongpeng dongpeng@hypersilicon.com
 * @Date: 2023-09-02 09:57:20
 * @LastEditors: dongpeng dongpeng@hypersilicon.com
 * @LastEditTime: 2023-09-02 17:54:20
 * @FilePath: /test/cjson_test/cjson_test.c
 * @Description: 
 * 
 * Copyright (c) 2023 by dongpeng dongpeng@hypersilicon.com, All Rights Reserved. 
 */
#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

int main(void)
{
    // 打开文件
    FILE *file = NULL;
    file = fopen("./test.json", "r");
    if (file == NULL) {
        printf("Open file fail！\n");
        return;
    }

    // 获得文件大小
    struct stat statbuf;
    stat("./test.json", &statbuf);
    int fileSize = statbuf.st_size;
    printf("文件大小：%d\n", fileSize);


    // 分配符合文件大小的内存
    char *jsonStr = (char *)malloc(sizeof(char) * fileSize + 1);
    memset(jsonStr, 0, fileSize + 1);


    // 读取文件中的json字符串
    int size = fread(jsonStr, sizeof(char), fileSize, file);
    if (size == 0) {
        printf("读取文件失败！\n");
        fclose(file);
        return;
    }
    printf("%s\n", jsonStr);
    fclose(file);


    cJSON *json, *item, *item2, *object, *object_child, *object_child_child;
    int i = 0, j = 0;
    json=cJSON_Parse(jsonStr);
    printf("********\n");
    if (!json)
    {
        printf("Error before: [%s]\n",cJSON_GetErrorPtr());
    }
    else
    {

        cJSON_ArrayForEach(object, json);
        printf("The parent key name is:%s\n",object->string);

        int size=cJSON_GetArraySize(object);  //获取数组大小

        for (i = 0; i < size; i++)
        {
            item = cJSON_GetArrayItem(object, i);
            cJSON_ArrayForEach(object_child, item);

            printf("The childs key name is:%s\n",object_child->string);

            if (object_child->child != NULL)
            {
                    object_child_child = object_child->child;
                    while (object_child_child != NULL)
                    {
                            printf("The child child key name is:%s\n", object_child_child->string);
                            object_child_child = object_child_child->next;
                    }
            }
        }

        cJSON_Delete(json);
    }
    return 0;
}

