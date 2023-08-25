/*
 * @Author: dongpeng dongpeng@hypersilicon.com
 * @Date: 2023-08-23 17:00:56
 * @LastEditors: dongpeng dongpeng@hypersilicon.com
 * @LastEditTime: 2023-08-25 11:00:02
 * @FilePath: /test/test.c
 * @Description: 
 * 
 * Copyright (c) 2023 by dongpeng dongpeng@hypersilicon.com, All Rights Reserved. 
 */
#include <stdio.h>
#include "queue.h" 

typedef struct {
    int index;
    QUEUE q;
}work;

void printwork(work *work)
{
    printf("work-> = %d\n", work->index);
}

int main(void)
{
    int i;
    int a;
    QUEUE start;
    QUEUE_INIT(&start);

    int num = 10;
    work works[num];
    
    for (int i = 0; i < num; i++){
        works[i].index = i;
        QUEUE_INSERT_TAIL(&start, &works[i].q);
    }
    
    QUEUE *tmpq;
    work *tmpwork;

    QUEUE_FOREACH(tmpq, &start){
        tmpwork = QUEUE_DATA(tmpq, work, q);
        printwork(tmpwork);
    }
    
    return 0;
}