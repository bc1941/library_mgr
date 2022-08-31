#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_mgr.h"
#include "md5.h"


user_node* user_list;


user_node* create_u(void)
{
    user_node* n = (user_node*)malloc(sizeof(user_node));
    n->next = NULL;

    return n;
}


void destory_user(user_node* l)
{
    user_node* p = NULL;

    while(l != NULL)
    {
        p = l->next;
        free(l);
        l = p;
    }
}


void save_user(void)
{
    FILE* fp = NULL;

    fp = fopen("user_data", "wb");

    if(fp == NULL)
    {
        perror("fopen fail");
    }

    user_node* l = user_list->next;

    while (l != NULL)
    {
        fwrite(&(l->data), sizeof(user), 1, fp);
        l = l->next;
    }
    
    fclose(fp);
    
}


void load_user(void)
{
    FILE* fp = NULL;
    user b;
    
    fp = fopen("user_data","rb");

    if(fp == NULL) return;

    while (fread(&b, sizeof(user), 1, fp))
    {
        push_user(user_list, b);
    }

    fclose(fp);   
}


void push_user(user_node* l, user data)
{
    user_node* n = (user_node*)malloc(sizeof(user_node));
    n->next = NULL;
    n->data = data;

    while(l->next != NULL)
        l = l->next;

    l->next = n;
}


int remove_user(user_node* l)
{
    char id[25];
    printf("请输入用户id：");
    scanf("%s", id);

    user_node* p = NULL;

    while (l->next != NULL && strcmp(l->next->data.user_id, id) != 0)
    {
        l = l->next;
    }
        
    if(l->next == NULL) return 0;

    p = l->next;
    l->next = p->next;
    free(p);
    return 1;
}


int update_user(user_node* l)
{
    
    char id[25];
    printf("请输入用户id：");
    scanf("%s", id);

    l = l->next;

    while (l != NULL && strcmp(l->data.user_id, id) != 0)
    {
        l = l->next;
    }
        
    if(l == NULL) return 0;

    user u;

    printf("请按如下提示输入用户信息：\n");

    printf("用户id：");
    scanf("%s", u.user_id);
    

    int n = strlen(u.user_id);
    char b[25];

    md5_encode(&u.user_id[n - 6], strlen(&u.user_id[n - 6]),u.user_pwd);
    u.login = 0;

    printf("用户名字：");
    scanf("%s", u.user_name);

    printf("用户性别【1->男；0->女】：");
    scanf("%d", &u.user_sex);

    printf("用户电话号码：");
    scanf("%s", u.user_phone_num);

    printf("用户地址：");
    scanf("%s", u.user_address);
         
    l->data = u;
    return 1;
}



void show_user(user u)
{
    
    printf("用户id：%s\n", u.user_id);

    printf("用户名字：%s\n", u.user_name);

    printf("用户性别：%s\n", (u.user_sex ? "男": "女"));

    printf("用户电话号码：%s\n", u.user_phone_num);

    printf("用户地址：%s\n", u.user_address);
}


int find_user(user_node* l, int order)  //1->id 2->姓名 3->手机号
{
    int f = 0;
    if(order == 1)
    {
        char id[25];
        printf("请输入用户id：");
        scanf("%s", id);

        l = l->next;

        while (l != NULL)
        {
            if(strstr(l->data.user_id, id) != 0)
            {
                show_user(l->data);
                f++;
            }
        
            l = l->next;
        }
        
        return f;
    }

    else if(order == 2)
    {
        char name[31];
        printf("请输入用户姓名：");
        scanf("%s", name);

        l = l->next;

        while (l != NULL)
        {
            if(strstr(l->data.user_name, name) != 0)
            {
                show_user(l->data);
                f++;
            }
        
            l = l->next;
        }
        
        return f;
    }

    else
    {
        char phone_num[25];
        printf("请输入用户电话：");
        scanf("%s", phone_num);

        l = l->next;

        while (l != NULL)
        {
            if(strstr(l->data.user_pwd, phone_num) != 0)
            {
                show_user(l->data);
                f++;
            }
        
            l = l->next;
        }
        
        return f;
    }
}


void input_user(void)
{
    user u;
    printf("请按如下提示输入用户信息：\n");

    printf("用户id：");
    scanf("%s", u.user_id);

    int n = strlen(u.user_id);
    char b[25];

    //char md5_pwd[33];
    md5_encode(&u.user_id[n - 6], strlen(&u.user_id[n - 6]),u.user_pwd);
    u.login = 0;

    printf("用户名字：");
    scanf("%s", u.user_name);

    printf("用户性别【1->男；0->女】：");
    scanf("%d", &u.user_sex);

    printf("用户电话号码：");
    scanf("%s", u.user_phone_num);

    printf("用户地址：");
    scanf("%s", u.user_address);

    push_user(user_list, u);
    printf("用户创建成功\n");
}



/*int main()
{
    user_list = create_u();
    load_user();

    find_user(user_list,1);
    find_user(user_list,2);
    find_user(user_list,3);
    return 0;
}
*/

