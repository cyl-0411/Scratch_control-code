//
// Created by CYL04 on 2022/7/27.
//

#include "headfile.h"

void key_scan(void)
{
    if(key1==0){
        key1_task();
        while(key1==0);
    }

    if(key2==0){
        key2_task();
        while(key2==0);
    }

    if(key3==0){
        key3_task();
        while(key3==0);
    }

    if(key4==0){
        key4_task();
        while(key4==0);
    }
}



void key1_task(void)
{
    MG995_OPEN();
}


void key2_task(void)
{
    MG995_CLOSE();
}


void key3_task(void)
{

}


void key4_task(void)
{

}