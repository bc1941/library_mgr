#ifndef _USER_MGR_H_
#define _UH_SER_MGR_


typedef struct user
{
    char user_id[25];
    char user_pwd[33];
    char user_name[31];
    int user_sex;
    char user_phone_num[21];
    char user_address[101];
    int login;
}user;


typedef struct node_u
{
    user data;
    struct node_u* next;
}user_node;


extern user_node* user_list;


void push_user(user_node* l, user data);
user_node* create_u(void);
void destory_user(user_node* l);
void save_user(void);
void load_user(void);
int remove_user(user_node* l);
int update_user(user_node* l);
void show_user(user u);
int find_user(user_node* l, int order);
void input_user(void);


#endif