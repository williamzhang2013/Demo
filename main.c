//
//  main.c
//  Demo01
//
//  Created by williamzhang on 15/3/6.
//  Copyright (c) 2015年 williamzhang. All rights reserved.
//

#include <stdio.h>


#define FSM_INIT_STATE          0
#define FSM_TUNE_STATE          1
#define FSM_BUFF_STATE          2
#define FSM_PLAY_STATE          3
#define FSM_PAUSE_STATE         4

typedef struct fsm_data_tag {
    int state;
    int (*handler)(int data1, int data2);
}FSM_STATE_DATA;

int handler_init_state(int data1, int data2);
int handler_tune_state(int data1, int data2);
int handler_buffer_state(int data1, int data2);
int handler_play_state(int data1, int data2);
int handler_pause_state(int data1, int data2);

static int sg_fsm_state = FSM_INIT_STATE;
FSM_STATE_DATA fsm[] = {
    {FSM_INIT_STATE,  handler_init_state},
    {FSM_TUNE_STATE,  handler_tune_state},
    {FSM_BUFF_STATE,  handler_buffer_state},
    {FSM_PLAY_STATE,  handler_play_state},
    {FSM_PAUSE_STATE, handler_pause_state},
};

int handler_init_state(int data1, int data2)
{
    printf("%s Entry!\n", __FUNCTION__);
    sg_fsm_state = FSM_TUNE_STATE;
    return 1;
}

int handler_tune_state(int data1, int data2)
{
    printf("%s Entry!\n", __FUNCTION__);
    return 1;
}

int handler_buffer_state(int data1, int data2)
{
    printf("%s Entry!\n", __FUNCTION__);
    return 1;
}

int handler_play_state(int data1, int data2)
{
    printf("%s Entry!\n", __FUNCTION__);
    return 1;
}

int handler_pause_state(int data1, int data2)
{
    printf("%s Entry!\n", __FUNCTION__);
    return 1;
}

int handle_fsm()
{
//    int  i = FSM_INIT_STATE;
////    for (i=FSM_INIT_STATE; i; <#increment#>) {
////        <#statements#>
////    }
    int ret = (*fsm[sg_fsm_state].handler)(0, 0);
    return ret;
}

int main(int argc, const char * argv[])
{
    //printf("Hello, World!\n");
    //scanf("%d\n", &sg_fsm_state);
    printf("sg_fsm_state=%d\n", sg_fsm_state);
    handle_fsm();
    return 0;
}

