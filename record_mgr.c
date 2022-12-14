#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "record_mgr.h"
#include "books_mgr.h"


record_node* record_list;
record_node* history_list;
books_node* books_list;


record_node* create_r(void)
{
    record_node* n = (record_node*)malloc(sizeof(record_node));
    n->next = NULL;

    return n;
}


void destory_record(record_node* l)
{
    record_node* p = NULL;

    while(l != NULL)
    {
        p = l->next;
        free(l);
        l = p;
    }
}


void save_record(void)
{
    FILE* fp = NULL;

    fp = fopen("record_data", "wb");

    if(fp == NULL)
    {
        perror("fopen fail");
    }

    record_node* l = record_list->next;

    while (l != NULL)
    {
        fwrite(&(l->data), sizeof(record), 1, fp);
        l = l->next;
    }
    
    fclose(fp);
    
}


void load_record(void)
{
    FILE* fp = NULL;
    record b;
    
    fp = fopen("record_data","rb");

    if(fp == NULL) return;

    while (fread(&b, sizeof(record), 1, fp))
    {
        push_record(record_list, b);
    }

    fclose(fp);   
}


void save_history(void)
{
    FILE* fp = NULL;

    fp = fopen("history_data", "wb");

    if(fp == NULL)
    {
        perror("fopen fail");
    }

    record_node* l = history_list->next;

    while (l != NULL)
    {
        fwrite(&(l->data), sizeof(record), 1, fp);
        l = l->next;
    }
    
    fclose(fp);
    
}


void load_history(void)
{
    FILE* fp = NULL;
    record b;
    
    fp = fopen("history_data","rb");

    if(fp == NULL) return;

    while (fread(&b, sizeof(record), 1, fp))
    {
        push_record(history_list, b);
    }

    fclose(fp);   
}



void push_record(record_node* l, record data)
{
    record_node* n = (record_node*)malloc(sizeof(record_node));
    n->next = NULL;
    n->data = data;

    while(l->next != NULL)
        l = l->next;

    l->next = n;
}


void push_history(record_node* l, record data)
{
    record_node* n = (record_node*)malloc(sizeof(record_node));
    n->next = NULL;
    n->data = data;

    while(l->next != NULL)
        l = l->next;

    l->next = n;
}


int remove_record(record_node* l1, char id[25], unsigned long int isbn)
{
    record_node* p = NULL;

    while (l1->next != NULL && (strcmp(l1->next->data.user_id, id) != 0 || l1->data.ISBN == isbn))
    {
        l1 = l1->next;
    }
        
    if(l1->next == NULL) return 0;

    p = l1->next;
    l1->next = p->next;
    free(p);
    return 1;
}


/*
char user_id[25];
    unsigned long int ISBN;
    unsigned long int borrow_time;
    unsigned long int repay_time;
    int borrow_num;
    char remake[301];


    time_t t;
	time(&t);
	struct tm* now_time = localtime(&t);
	const char* weekday[] = {"???", "???", "???", "???", "???", "???", "???"};
	printf("\n???????????????%d???%d???%d??? %d:%02d:%02d ??????%s\n", now_time->tm_year + 1900, now_time->tm_mon + 1, now_time->tm_mday, now_time->tm_hour, now_time->tm_min, now_time->tm_sec, weekday[now_time->tm_wday]);

*/

void show_history(record_node* l)
{
    l = l->next;
    int cnt = 0;
	const char* weekday[] = {"???", "???", "???", "???", "???", "???", "???"};
	struct tm* now_time;

    while(l != NULL)
    {   cnt++;
        printf("\n???%d????????????",cnt);
        printf("??????id???%s\n",l->data.user_id);
        printf("???????????????%lu\n",l->data.ISBN);
        now_time = localtime(&l->data.borrow_time);
        printf("???????????????%d???%d???%d??? %d:%02d:%02d ??????%s\n", now_time->tm_year + 1900, now_time->tm_mon + 1, now_time->tm_mday, now_time->tm_hour, now_time->tm_min, now_time->tm_sec, weekday[now_time->tm_wday]);
        now_time = localtime(&l->data.borrow_time);
        printf("???????????????%d???%d???%d??? %d:%02d:%02d ??????%s\n", now_time->tm_year + 1900, now_time->tm_mon + 1, now_time->tm_mday, now_time->tm_hour, now_time->tm_min, now_time->tm_sec, weekday[now_time->tm_wday]);
        printf("???????????????%d\n", l->data.borrow_num);
        printf("?????????%s\n",l->data.remake);
        l = l->next;
    }

    printf("??????%d????????????\n",cnt);
    
    return;
}


void show_record(record_node* l)
{
    l = l->next;
    int cnt = 0;
    const char* weekday[] = {"???", "???", "???", "???", "???", "???", "???"};
	struct tm* now_time;


    while(l != NULL)
    {   cnt++;
        printf("\n???%d????????????",cnt);
        printf("??????id???%s\n",l->data.user_id);
        printf("???????????????%lu\n",l->data.ISBN);
        now_time = localtime(&l->data.borrow_time);
        printf("???????????????%d???%d???%d??? %d:%02d:%02d ??????%s\n", now_time->tm_year + 1900, now_time->tm_mon + 1, now_time->tm_mday, now_time->tm_hour, now_time->tm_min, now_time->tm_sec, weekday[now_time->tm_wday]);
        printf("??????????????????????????????\n");
        printf("???????????????%d\n", l->data.borrow_num);
        printf("?????????%s\n",l->data.remake);
        l = l->next;
    }

    printf("??????%d????????????\n",cnt);
    
    return;
}










