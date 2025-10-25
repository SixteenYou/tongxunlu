#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#include<errno.h>
#include<locale.h>
//一个块的内容最多存储的内容
#define name_max 15//年龄字段最多能存储多少字节
#define tel_max 12//电话字段最多能存储多少字节
#define xingbei_max 5//性别字段最多能存储多少字节
#define zhuzhi_max 50//住址字段最多能存储多少字节
#define nianling_min 0//年龄最小值
#define nianling_max 150//年龄最大值
#define xingbie_min 0//性别种类最小值
#define xingbie_max 2//性别种类最大值
#define jizhunshuju 32//所有数据都是以此数为准
#define revow 2//重新操作
#define continund 1//持续操作
#define 男 0//性别男
#define 女 1//性别女
#define 保密 2//性别保密
#define fenge "--------------------------------------------------------------------------------------------------\n"
//一个人的内容
typedef  struct id
{
	bool is_del_full;//标记打到人身上，不至于多个标记表示一个位置ture为存在，false为不存在
	char name[name_max];//姓名
	char tel[tel_max];//电话
	char xingbei[xingbei_max];//性别
	char zhuzhi[zhuzhi_max];//住址
	short age;//年龄
}id;
//哈希表结构，性别和年龄作为索引
typedef struct hash
{
	unsigned long long size;//当前数组的大小兼顾坐标
	unsigned long long max;//最大数组的大小
	bool* is_del;//标记是否被删除
	id** value;//存储的id结构数组
}hash;
typedef struct avltree//AVL树结构
{
	int height;//高度
	unsigned long long max_len;//最多数据数量
	unsigned long long size;//当前节点的数量
	wchar_t* key;//键
	struct avltree* left;//左子树  
	struct avltree* right;//右子树
	id**value;//存储的id结构数组
	bool* is_del;//标记是否被删除
}avltree;
typedef struct queue//队列结构
{
	avltree* data;//存储的数据
	struct queue* next;//下一个节点
}queue;
//队列，用于迭代式访问avl树
typedef struct que
{
	unsigned long long size;//队列的数量
	queue* front;//队列头指针
	queue* rear;//队列尾指针
}que;
//一个块的内容
typedef  struct xinxi
{
	unsigned int size;//当前块的大小
	id peo[];//存储的id结构
}xinxi;
//单链表结构
typedef struct node//原始数据的节点结构
{
	id*start;//指向第一个id结构
	id*end;//指向最后一个id结构
	struct node* xiayige;//指向下一个节点
	xinxi* people;//指向块
}node;
typedef struct peizhi//设置配置参数的结构
{
	bool is_auto_baocun;//是否后台自动保存(默认开启)
	bool is_kuai_max;//是否修改块的最大数量(默认没修改，且只能改一次)
	unsigned int sheding_auto_baocun;//后台自动保存（单位：修改/次）
	unsigned int change_num;//计算修改次数
	unsigned int kuai_max;//块的最大数量
	HANDLE auto_baocun_thread;//线程句柄
	int thread_num;//批量读取的最大线程数
	unsigned long long total;//总数据量
}peizhixinxi;
typedef struct wnjian//文件结构
{
	unsigned long long view_size;//当视图中有多少个数据
	unsigned long long view_max;//当前视图的最大容量
	unsigned long long delete_size;//删除的多少个数据
	unsigned long long delete_max;//删除的最大容量
	unsigned int link_len;//链表的长度
	hash* nianling;//年龄哈希表
	hash* xingbie;//性别哈希表
	avltree* xingming;//姓名AVL树
	avltree* dianhua;//电话AVL树
	avltree*zhuzhi;//住址AVL树
	id** view_data;//视图指针,true表示存在
	id** delete_data;//删除的指针,false表示删除
	node* head;//头指针
	node* tail;//尾指针
}wenjianxinxi;
typedef struct data//数据结构
{
	wenjianxinxi wenjian;//文件结构（存储所有数据）
	peizhixinxi peizhi;//配置参数
}DATA;
//菜单
void menuone();
void menutow_caizuoshuju();
void menutow_tiaoxu();
void menu_wenjiancaizuo();
void new_node(DATA* data);//添加节点
void erji_caozuoshuju(DATA* data);//操作数据的二级菜单
void erji_tiaoxu(DATA* data);//排序和筛选的二级菜单
DATA* erji_wenjiucaizuo(DATA* data);//导入和导出的二级菜单
void free_head(DATA* data);
void anxia_continue();//按空格继续
void huishouzhan(DATA* data);//回收站
int xingbei_to_num(char* s);//性别字符串转数字
//非阻塞型输入
char input_num_char(DATA*data);
//验证是否有数据,返回值为0表示没有数据，返回值为非0表示有数据，同时返回值兼顾坐标(注意有加一，记得减一)，第一个参数是数组，第二个参数是该数组的大小，第三个参数是标识，第四个参数是查找的类型true和false
unsigned long long yanzheng(id** value, unsigned  long long max, char* s1, bool type);
//查找数据
void chazhao(DATA*data);
//预览打印所有信息
void yulan(DATA* data);
//输入字符串并验证大小，第一的参数为数据位置，第二个参数为提示信息，第三个参数为最大长度
void input(char* s1, char* s2, int a);
//验证是否正在自动保存
void yanzheng_auto_save(DATA* data);
//打印预览数据
void dayinshuju(DATA* data);
//初始化数据
DATA* chushihua_data();
//视图的扩建或者重建,第一个数据为三级指针数据域，第二个数据为二级指针bool域，第三个数据为最大容量，第四个数据为当前容量，第五个数据为扩建或者重建的类型，type=1表示扩建,type=2表示重建
void chongjian_kuorong_view(id*** view, bool** is_del, unsigned long long* max, unsigned long long* size, int type);
//重新建立哈希,第二个参数类型选择，type=1表示年龄，type=2表示性别，第三个参数是否删除原数据,is_del=2时表示删除原数据，is_del=1时表示不删除原数据
void chongjian_hash(DATA* data, int type, int is_del);
//是否重建各种键，type=2先删除所有键，在重建，type=1只建立某一数据的键
void datas_to_index(DATA* data, id** value, int type, int flag);//目前没有想到怎么优化，先用暴力法吧
wchar_t* ctow(const char* str);//转换为宽字符进行比较
//查avl树(模糊查找)，第一个参数是根节点，第二个参数是要查找的值，第三个参数是返回的大小,第四个参数是查找查找开头2还是子串3全部1
id** find_avltree(avltree* root, wchar_t* value, unsigned long long* return_size, int type);
void dayinxiangxixinxi(id* tmp, bool* found);//打印详细信息

void free_avl(avltree* root);//释放avl树
void nothing(long long found, char* s1);
void  del_to_index(DATA* data, id* value ,id tmp_id);//删除数据的索引

//一级菜单枚举
enum caidanyiji
{
	退出并保存,
	预览,
	操作数据,
	查找,
	排序和筛选,
	文件操作,
	保存,
	退出不保存 = 9,
};
//固定的二级菜单枚举
enum one
{
	返回
};
//二级菜单操作数据的枚举
enum caidanerji_caizuoshuju
{
	添加 = 1,
	修改,
	删除,
	回收站,
};
//二级菜单排序的筛选的枚举
enum caidanerji_tiaoxu
{
	排序 = 1,
	筛选,
};
//二级菜单导入和导出的枚举
enum caidanerji_wenjiucaizuo
{
	导入 = 1,
	导出,
	重置,
	自动保存,
	设定保存数量,

};
//枚举查找的类型
enum chazhaozhonglie
{
	姓名=1,
	电话,
	年龄,
	性别,
};