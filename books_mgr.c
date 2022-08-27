#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books_mgr.h"


books_node* create_b(void)
{
    books_node* n = (books_node*)malloc(sizeof(books_node));
    n->next = NULL;

    return n;
}


void destory_books(books_node* l)
{
    books_node* p = NULL;

    while(l != NULL)
    {
        p = l->next;
        free(l);
        l = p;
    }
}


void save_books(void)
{
    FILE* fp = NULL;

    fp = fopen("books_data", "wb");

    if(fp == NULL)
    {
        perror("fopen fail");
    }

    books_node* l = books_list->next;

    while (l != NULL)
    {
        fwrite(&(l->data), sizeof(books), 1, fp);
        l = l->next;
    }
    
    fclose(fp);
    
}


void load_books(void)
{
    FILE* fp = NULL;
    books b;
    
    fp = fopen("books_data","rb");

    if(fp == NULL) return;

    while (fread(&b, sizeof(books), 1, fp))
    {
        push_books(books_list, b);
    }

    fclose(fp);   
}


void push_books(books_node* l, books data)
{
    books_node* n = (books_node*)malloc(sizeof(books_node));
    n->next = NULL;
    n->data = data;

    while(l->next != NULL)
        l = l->next;

    l->next = n;
}


int remove_books(books_node* l, int order)
{
    if(order == 1)
    {
        unsigned long int ISBN;
        printf("请输入图书编号：");
        scanf("%lu", &ISBN);

        books_node* p = NULL;

        while (l->next != NULL && l->next->data.ISBN != ISBN)
        {
            l = l->next;
        }
        
        if(l->next == NULL) return 0;

        p = l->next;
        l->next = p->next;
        free(p);
        return 1;
    }

    else
    {
        char name[60];
        printf("请输入图书名字：");
        scanf("%s", name);

        books_node* p = NULL;

        while (l->next != NULL && strcmp(l->next->data.book_name, name) != 0)
        {
            l = l->next;
        }
        
        if(l->next == NULL) return 0;

        p = l->next;
        l->next = p->next;
        free(p);
        return 1;
    }
}


int update_books(books_node* l, int order)
{
    if(order == 1)
    {
        unsigned long int ISBN;
        printf("请输入图书编号：");
        scanf("%lu", &ISBN);

        l = l->next;

        while (l != NULL && l->data.ISBN != ISBN)
        {
            l = l->next;
        }
        
        if(l == NULL) return 0;

    books b;

    printf("请按如下提示输入图书信息：\n");

    printf("图书ISBN：");
    scanf("%lu", &b.ISBN);

    printf("图书名字：");
    scanf("%s", b.book_name);

    printf("图书出版社：");
    scanf("%s", b.book_press);

    printf("图书总量：");
    scanf("%d", &b.inventory);

    printf("图书余量：");
    scanf("%d", &b.margin);

        l->data = b;
        return 1;
    }

    else
    {
        char name[60];
        printf("请输入图书名字：");
        scanf("%s", name);

        l = l->next;

        while (l != NULL && strcmp(l->data.book_name, name) != 0)
        {
            l = l->next;
        }
        
        if(l == NULL) return 0;

    books b;

    printf("请按如下提示输入图书信息：\n");

    printf("图书ISBN：");
    scanf("%lu", &b.ISBN);

    printf("图书名字：");
    scanf("%s", b.book_name);

    printf("图书出版社：");
    scanf("%s", b.book_press);

    printf("图书总量：");
    scanf("%d", &b.inventory);

    printf("图书余量：");
    scanf("%d", &b.margin);
         
         l->data = b;
        return 1;
    }
}


void show_books(books_node* l)
{
    l = l->next;

    while (l != NULL)
    {
        printf("\n图书ISBN：%lu\n图书名字：%s\n图书出版社：%s\n图书总量：%d\n图书余量：%d\n", l->data.ISBN, l->data.book_name, l->data.book_press,l->data.inventory, l->data.margin);
    
        l = l->next;
    }

    printf("\n");
    
}


books* find_books(books_node* l, unsigned long int ISBN, char name[60],int order)
{
    if(order == 1)
    {
        l = l->next;

        while (l != NULL)
        {
            if(l->data.ISBN == ISBN) return &(l->data);
        
            l = l->next;
        }
        
        return NULL;
    }

    else
{
        l = l->next;
        
        while (l != NULL)
        {
            if(strcmp(l->data.book_name, name) == 0) return &(l->data);

            l = l->next;
        }
        
        return NULL;
    }
}


void input_books(void)
{
    books b;

    printf("请按如下提示输入图书信息：\n");

    printf("图书ISBN：");
    scanf("%lu", &b.ISBN);

    printf("图书名字：");
    scanf("%s", b.book_name);

    printf("图书出版社：");
    scanf("%s", b.book_press);

    printf("图书总量：");
    scanf("%d", &b.inventory);

    printf("图书余量：");
    scanf("%d", &b.margin);

    push_books(books_list, b);
    printf("成功录入图书信息。\n");

}


