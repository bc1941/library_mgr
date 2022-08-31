#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "books_mgr.h"
#include "record_mgr.h"
#include "md5.h"
#include "user_mgr.h"


struct manager
{
    char manager_name[31];
    char manager_pwd[33];
};

int manager_login(void);
int is_first_login();
void update_manager(struct manager m);
int manager_login_check(const char* manager_name, const char* manager_pass);
int user_login_check(const char* user_name, const char* user_pass, user u);
int user_login(char user_id[25], char pwd[33]);


char userid[25];


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
            {
                

                if(manager_login())
                glyms();
            }
            
			
			break;

		case 2:
        {
            char userpwd[33];
            printf("\n请登录！\n");
            printf("用户名：");
            scanf("%s", userid);
            strcpy(userpwd, getpass("密码："));

            if(user_login(userid, userpwd))
            {
                dzms();
            }
            
			break;
        }
			
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
        {
                FILE* fp = NULL;

            char mname[31];
            struct manager m;
			fp = fopen("manager_data", "rb");

                fread(&m, sizeof(m),1,fp);

                fclose(fp);

                printf("请输入新的管理员名字：");
                scanf("%s",mname);
                
                strcpy(m.manager_name, mname);

                fp = fopen("manager_data", "wb");

                if(fp == NULL)
                {
                        perror("open user_data fail");
                }

                fwrite(&m, sizeof(m), 1, fp);

                fclose(fp);

                printf("\n管理员名字修改成功！\n");
            
			break;
        }
		case 2:
			{
                FILE* fp = NULL;
                struct manager m;
                char mpwd[33];
                char pwd_check[33];
			while(1)
                {
                        strcpy(mpwd, getpass("管理员新的密码："));
                        strcpy(pwd_check, getpass("再次输入管理员密码："));

                        if(strcmp(mpwd, pwd_check) == 0) break;

                        printf("\n两次输入的密码不一致，请重新输入！\n");
                }
                
                fp = fopen("manager_data", "rb");

                fread(&m, sizeof(m),1,fp);

                fclose(fp);


                md5_encode(mpwd, strlen(mpwd), m.manager_pwd);

               fp = fopen("manager_data", "wb");

                if(fp == NULL)
                {
                        perror("open user_data fail");
                }

                fwrite(&m, sizeof(m), 1, fp);

                fclose(fp);

                printf("\n管理员密码修改成功！\n");
        
			
            }break;
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

    char pwd[33];
    char pwd_check[33];
    
    while(1)
                {
                        strcpy(pwd, getpass("新的密码："));
                        strcpy(pwd_check, getpass("再次输入密码："));

                        if(strcmp(pwd, pwd_check) == 0) break;

                        printf("\n两次输入的密码不一致，请重新输入！\n");
                }

                md5_encode(pwd, strlen(pwd), l->data.user_pwd);

                save_user();
    
    return;
}


void ckxx(void)
{
    user_node* l = NULL;
    l = user_list->next;
    

        while (l != NULL)
        {
            if(strcmp(l->data.user_id, userid) == 0)
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
void jhsj(void)
{   
    unsigned long int ISBN;
    printf("请输入书籍编号：");
    return;
}


int is_first_login()
{
        FILE* fp = fopen("manager_data", "rb");

        if(fp == NULL) return 1;

        fclose(fp);

        return 0;
}


int manager_login(void)
{
        char manager_name[31], manager_pwd[33], manager_pwd_check[33];

        struct manager m;

        printf("\n请登录！\n");
        printf("管理员用户名：");
        scanf("%s", manager_name);
        // 输入密码时没有回显
        strcpy(manager_pwd, getpass("密码："));

        if(is_first_login())
        {
                if(strcmp(manager_name, "manager") != 0 || strcmp(manager_pwd, "888888") != 0)
                {
                        printf("用户名或密码错误，登录失败！\n");
                        exit(1);
                }

                // 首次登录成功
                printf("\n为了系统安全，请重新设置管理员用户名和密码。\n");
                printf("管理员用户名：");
                scanf("%s", manager_name);
                // 输入密码时没有回显

                while(1)
                {
                        strcpy(manager_pwd, getpass("管理员密码："));
                        strcpy(manager_pwd_check, getpass("再次输入管理员密码："));

                        if(strcmp(manager_pwd, manager_pwd_check) == 0) break;

                        printf("\n两次输入的密码不一致，请重新输入！\n");
                }

                strcpy(m.manager_name, manager_name);
                
                md5_encode(manager_pwd, strlen(manager_pwd), m.manager_pwd);

                FILE* fp = fopen("manager_data", "wb");

                if(fp == NULL)
                {
                        perror("open user_data fail");
                }

                fwrite(&m, sizeof(m), 1, fp);

                fclose(fp);

                printf("\n设置管理员用户名和密码成功！\n");
        }
        else
        {
                // 非首次登录
                if(!manager_login_check(manager_name, manager_pwd))
                {
                        printf("用户名或密码错误，登录失败！\n");
                        exit(1);
                }

                update_manager(m);
        }

        printf("\n%s，您好，欢迎使用本系统！\n", m.manager_name); 
}


void update_manager(struct manager m)
{
        FILE* fp = NULL;
        
        fp = fopen("manager_data", "wb");

        if(fp == NULL)
        {
                perror("open user_data fail");
        }
        
        fwrite(&m, sizeof(m), 1, fp);

        fclose(fp);
}



int manager_login_check(const char* manager_name, const char* manager_pass)
{
        FILE* fp = NULL;
        struct manager m;
    
        char manager_pass_md5[33];
        int check_success = 0;

        fp = fopen("manager_data", "rb");

        if(fp == NULL) return 0;

        md5_encode(manager_pass, strlen(manager_pass), manager_pass_md5);

        while(fread(&m, sizeof(m), 1, fp) == 1)
        {
                if(strcmp(manager_name, m.manager_name) == 0 && strcmp(manager_pass_md5, m.manager_pwd) == 0)
                {
                        // 登录验证成功
                        check_success = 1;
                        break;
                }
        }

        fclose(fp);

        return check_success;
}


int user_login_check(const char* user_name, const char* user_pass, user u)
{
        FILE* fp = NULL;
    
        char user_pass_md5[33];
        int check_success = 0;


        md5_encode(user_pass, strlen(user_pass), user_pass_md5);

                if(strcmp(user_name, u.user_id) == 0 && strcmp(user_pass_md5, u.user_pwd) == 0)
                {
                        // 登录验证成功
                        check_success = 1;
                        save_user();
                }

        return check_success;
}


int user_login(char user_id[25], char pwd[33])
{
    char pwd_check[33];
    user_node* l = NULL;
    l = user_list;
    l = l ->next;

    while(l != NULL && strcmp(l->data.user_id, user_id) != 0)
    l = l->next;

    if(l == NULL) return 0;

    if(l->data.login == 0)
        {   
             if(!user_login_check(user_id, pwd, l->data))
                {
                        printf("用户名或密码错误，登录失败！\n");
                        exit(1);
                }
                // 首次登录成功
                printf("\n为了系统安全，请重新设置密码。\n");

                while(1)
                {
                        strcpy(pwd, getpass("新的密码："));
                        strcpy(pwd_check, getpass("再次输入密码："));

                        if(strcmp(pwd, pwd_check) == 0) break;

                        printf("\n两次输入的密码不一致，请重新输入！\n");
                }

                md5_encode(pwd, strlen(pwd), l->data.user_pwd);
                l->data.login++;

                save_user();
        }
    else
        {
                // 非首次登录
                if(!user_login_check(user_id, pwd, l->data))
                {
                        printf("用户名或密码错误，登录失败！\n");
                        exit(1);
                }
        }

        printf("\n%s，您好，欢迎使用本系统！\n", l->data.user_name); 
}