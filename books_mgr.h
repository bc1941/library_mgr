#ifndef _BOOKS_MGR_H_
#define _BOOKS_MGR_H_


typedef struct books
{
    unsigned long int ISBN;
    char book_name[61];
    char book_press[100];
    int inventory;
    int margin;
}books;


typedef struct node_b
{
    books data;
    struct node_b* next;
}books_node;


extern books_node* books_list;


void push_books(books_node* l, books data);
books_node* create_b(void);
void destory_books(books_node* l);
void save_books(void);
void load_books(void);
int remove_books(books_node* l, int order);
int update_books(books_node* l, int order);
void show_books(books_node* l);
books* find_books(books_node* l, unsigned long int ISBN, char name[60],int order);
void input_books(void);


#endif