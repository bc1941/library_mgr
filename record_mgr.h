#ifndef _RECORD_MGR_H_
#define _RECORD_MGR_H_


typedef struct record
{
    char user_id[25];
    unsigned long int ISBN;
    unsigned long int borrow_time;
    unsigned long int repay_time;
    int borrow_num;
    int repay_num;
    char remake[301];
}record;

typedef struct node_r
{
    record data;
    struct node_r* next;
}record_node;


extern record_node* history_list;
extern record_node* record_list;


void push_record(record_node* l, record data);
void push_history(record_node* l, record data);
record_node* create_r(void);
void destory_record(record_node* l);
void save_record(void);
void load_record(void);
void save_history(void);
void load_history(void);
int remove_record(record_node* l1, char id[25], unsigned long int isbn);
void show_history(record_node* l);
void show_record(record_node* l);


#endif