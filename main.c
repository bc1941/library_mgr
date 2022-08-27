#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "books_mgr.h"
#include "record_mgr.h"
#include "user_mgr.h"


char userid[60];


void show(void);
void glyms(void);
void dzms(void);
void glyxx(void);
void yhxx(void);
void sbxx(void);
void jhxx(void);
void ggmm(void);
void ckxx(void);
void ckjl(void);
void jhsj(void);

int main()
{
    user_list = create_u();
    books_list = create_b();
    history_list = create_r();
    record_list = create_r();

    load_books();
    load_history();
    load_record();
    load_user();

	show();
	return 0;
}

void show(void)
{   
    system("clear");
    printf("****************************************************************************");
	printf("\n                               欢迎使用本系统！！！\n");
    printf("****************************************************************************\n");
	int ms;
	while(1)
	{  
        
		printf("\n请选择登入模式【1->管理员模式；2->读者模式；0->退出】：");
		if(scanf("%d",&ms) && (1 == ms || 2 == ms || 0 == ms)) break;
		printf("输入错误！！！请重新输入！！\n");
		while(getchar() != '\n');
	}

	switch (ms)
	{
		case 1:
			glyms();
			break;

		case 2:
			dzms();
			break;
		default:
			return;
	}
}


void glyms(void)
{
    system("clear");

	printf("\n****************************************************************************\n");
    printf("                                管理员模式\n");
    printf("****************************************************************************\n");

	//登陆

    int cz;

	while(1)
	{  
		printf("\n请选择操作模式【1->管理员信息；2->用户信息；3->书本信息；4->借还记录；0->退出】：");
		if(scanf("%d",&cz) && (1 == cz || 2 == cz || 3 == cz || 4 == cz || 0 == cz)) break;
		printf("输入错误！！！请重新输入！！\n");
		while(getchar() != '\n');
	}

	switch (cz)
	{
		case 1:
			glyxx();
			break;

		case 2:
			yhxx() ;
			break;

		case 3:
			sbxx();
			break;

		case 4:
			jhxx();
			break;

		default:
			show();
	}
	return;
}


void glyxx(void)
{
    system("clear");

    printf("****************************************************************************\n");
    printf("                         管理员模式->管理员信息\n");
    printf("****************************************************************************\n");
    
	
	int cz;
	while(1)
	{  
		printf("\n请选择操作模式【1->管理员用户名修改；2->管理员密码修改；0->返回上一级目录】：");
		if(scanf("%d",&cz) && (1 == cz || 2 == cz || 0 == cz)) break;
		printf("输入错误！！！请重新输入！！\n");
		while(getchar() != '\n');

	}
	switch (cz)
	{
		case 1:
			printf("管理员用户名修改\n");
			break;

		case 2:
			printf("管理员密码修改\n");
			break;
		default:
			glyms();

	}
}


void yhxx(void)
{
    system("clear");

	printf("****************************************************************************\n");
    printf("                          管理员模式->用户信息\n");
    printf("****************************************************************************\n");
	int cz;
	while(1)
	{  
		printf("\n请选择操作模式【1->增加用户；2->修改用户信息；3->删除用户；4->查找用户；0->返回上一级目录】：");
		if(scanf("%d",&cz) && (1 == cz || 2 == cz || 3 == cz || 4 == cz || 0 == cz)) break;
		printf("输入错误！！！请重新输入！！\n");
		while(getchar() != '\n');
	}

	switch (cz)
	{
		case 1:
            system("clear");

            printf("****************************************************************************\n");
            printf("                          管理员模式->用户信息->增加用户\n");
            printf("****************************************************************************\n");

            input_user();
            
            save_user();
			break;

		case 2:
            system("clear");
            
            printf("****************************************************************************\n");
            printf("                          管理员模式->用户信息->修改用户信息\n");
            printf("****************************************************************************\n");

            if(update_user(user_list))
            printf("修改成功\n");
            else
            printf("修改失败，查无此人！\n");
            
            save_user();

			break;

		case 3:
            system("clear");
            printf("****************************************************************************\n");
            printf("                          管理员模式->用户信息->删除用户\n");
            printf("****************************************************************************\n");


            if(remove_user(user_list))
            printf("删除成功\n");
            else
            printf("删除失败，查无此人！\n");

            save_user();

			break;

		case 4:
            system("clear");
            printf("****************************************************************************\n");
            printf("                          管理员模式->用户信息->查找用户\n");
            printf("****************************************************************************\n");

            int o;

            while(1)
	        {  
		        printf("请选择查找模式【1->id 2->姓名 3->手机号】:");
		        if(scanf("%d",&o) && (1 == o || 2 == o || 3 == o)) break;
		        printf("输入错误！！！请重新输入！！\n");
		        while(getchar() != '\n');
	        }


            if(find_user(user_list,o) == 0)
                printf("查无此人！\n");
			break;
            

		default:
			glyms();
	}
    printf("是否继续？【1->是；2->返回上级】");

    int i;
    while(scanf("%d", &i) != 1)
            {
                printf("输入错误，请重新输入！");
                while(getchar() != '\n');
            }

    if(i == 1)
        yhxx();
        else
        glyms();
    
	return;
}


void sbxx(void)
{
	printf("****************************************************************************\n");
	printf("                            管理员模式->书本信息\n");
	printf("****************************************************************************\n");

	int cz;
	while(1)
	{  
		printf("\n请选择操作模式【1->增加书本；2->修改书本信息；3->删除书本；4->查找书本；0->返回上一级目录】：");
		if(scanf("%d",&cz) && (1 == cz || 2 == cz || 3 == cz || 4 == cz || 0 == cz)) break;
		printf("输入错误！！！请重新输入！！\n");
		while(getchar() != '\n');
	}

	switch (cz)
	{
		case 1:
	        printf("****************************************************************************\n");
            printf("                      管理员模式->书本信息->增加书本\n");
	        printf("****************************************************************************\n");

            input_books();
            save_books();
			break;

		case 2:
            printf("****************************************************************************\n");
            printf("                     管理员模式->书本信息->修改书本信息\n");
	        printf("****************************************************************************\n");

            int o;

            while(1)
	        {  
		        printf("请选择模式【1->书本编号 2->书本名字】:");
		        if(scanf("%d",&o) && (1 == o || 2 == o)) break;
		        printf("输入错误！！！请重新输入！！\n");
		        while(getchar() != '\n');
	        }

            update_books(books_list,o);
            save_books();
			break;

		case 3:
            printf("****************************************************************************\n");
            printf("                     管理员模式->书本信息->删除书本\n");
	        printf("****************************************************************************\n");
			
            while(1)
	        {  
		        printf("请选择模式【1->书本编号 2->书本名字】:");
		        if(scanf("%d",&o) && (1 == o || 2 == o)) break;
		        printf("输入错误！！！请重新输入！！\n");
		        while(getchar() != '\n');
	        }
            remove_books(books_list, o);
            save_books();

			break;

		case 4:
            printf("****************************************************************************\n");
            printf("                     管理员模式->书本信息->查找书本\n");
	        printf("****************************************************************************\n");
			
            while(1)
	        {  
		        printf("请选择模式【1->书本编号 2->书本名字】:");
		        if(scanf("%d",&o) && (1 == o || 2 == o)) break;
		        printf("输入错误！！！请重新输入！！\n");
		        while(getchar() != '\n');
	        }

            books b;
            unsigned long int ISBN = 1;
            char name[60];

            if(o == 1)
            {
                printf("请输入书本编号：");
                scanf("%lu", &ISBN);
                if(find_books(books_list,ISBN,name,o) != NULL)
                {
                b = *find_books(books_list,ISBN,name,o);

                printf("\n图书ISBN：%lu\n图书名字：%s\n图书出版社：%s\n图书总量：%d\n图书余量：%d\n", b.ISBN, b.book_name, b.book_press,b.inventory, b.margin);
                }
                else{
                    printf("查无此书！\n");
                }
            }
            else
            {
                printf("请输入图书名字：");
                scanf("%s", name);

                if(find_books(books_list,ISBN,name,o) != NULL)
                {
                    b = *find_books(books_list,ISBN,name,o);

                    printf("\n图书ISBN：%lu\n图书名字：%s\n图书出版社：%s\n图书总量：%d\n图书余量：%d\n", b.ISBN, b.book_name, b.book_press,b.inventory, b.margin);
                }
                else{
                    printf("查无此书！\n");
                }
            }
            

			break;

		default:
			glyms();
	}
	 printf("是否继续？【1->是；2->返回上级】");

    int i;
    while(scanf("%d", &i) != 1)
            {
                printf("输入错误，请重新输入！");
                while(getchar() != '\n');
            }

    if(i == 1)
        sbxx();
        else
        glyms();
    
	return;
}


void jhxx(void)
{
	printf("已归还的记录如下：\n");

    show_history(history_list);

    printf("未归还的记录如下：\n");
    show_record(record_list);


    return;
}



void dzms(void)
{
    system("clear");

	printf("\n****************************************************************************\n");
    printf("                                读者模式\n");
    printf("****************************************************************************\n");

	//登陆

    int cz;

	while(1)
	{  
		printf("\n请选择操作模式【1->修改密码；2->查看个人信息；3->查看个人借还记录；4->借、还书本；0->退出】：");
		if(scanf("%d",&cz) && (1 == cz || 2 == cz || 3 == cz || 4 == cz || 0 == cz)) break;
		printf("输入错误！！！请重新输入！！\n");
		while(getchar() != '\n');
	}

	switch (cz)
	{
		case 1:
			ggmm();
			break;

		case 2:
			ckxx() ;
			break;

		case 3:
			ckjl();
			break;

		case 4:
			jhsj();
			break;

		default:
			exit;
	}
	return;
}
    

void ggmm(void)
{
    user_node* l = NULL;
    l = user_list->next;

    char pwd[31];
    printf("请输入秘密：");
    

    while(strcmp(l->data.user_id, userid) == 0)
    {
        strcpy(l->data.user_pwd, pwd);
    }

    return;
}


void ckxx(void)
{
     user_node* l = NULL;
    l = user_list->next;
    

        while (l != NULL)
        {
            if(strstr(l->data.user_id, userid) != 0)
            {
                show_user(l->data);
            }
        
            l = l->next;
        }
        return;
}


void ckjl(void)
{
    record_node* l;
    printf("未归还的记录如下：");
    l = record_list->next;
    int cnt = 0;
    const char* weekday[] = {"日", "一", "二", "三", "四", "五", "六"};
	struct tm* now_time;


    while(l != NULL && (strcmp(l->data.user_id, userid) == 0))
    {   cnt++;
        printf("第%d条记录：",cnt);
        //printf("用户id：%s\n",l->data.user_id);
        printf("书本编号：%lu\n",l->data.ISBN);
        now_time = localtime(&l->data.borrow_time);
        printf("借阅时间：%d年%d月%d日 %d:%02d:%02d 星期%s\n", now_time->tm_year + 1900, now_time->tm_mon + 1, now_time->tm_mday, now_time->tm_hour, now_time->tm_min, now_time->tm_sec, weekday[now_time->tm_wday]);
        printf("归还时间：暂未归还。\n");
        printf("借阅数量：%d\n", l->data.borrow_num);
        printf("备注：%s\n",l->data.remake);
    }

    printf("一共%d条记录。",cnt);

    l = record_list->next;
    printf("已归还的记录如下：");
    cnt = 0;
    while(l != NULL && (strcmp(l->data.user_id, userid) == 0))
    {   
        cnt++;
        printf("第%d条记录：",cnt);
        printf("用户id：%s\n",l->data.user_id);
        printf("书本编号：%lu\n",l->data.ISBN);
        now_time = localtime(&l->data.borrow_time);
        printf("借阅时间：%d年%d月%d日 %d:%02d:%02d 星期%s\n", now_time->tm_year + 1900, now_time->tm_mon + 1, now_time->tm_mday, now_time->tm_hour, now_time->tm_min, now_time->tm_sec, weekday[now_time->tm_wday]);
        printf("归还时间：暂未归还。\n");
        printf("借阅数量：%d\n", l->data.borrow_num);
        printf("备注：%s\n",l->data.remake);
    }

    printf("一共%d条记录。",cnt);
    return;

}
void jhsj(void);