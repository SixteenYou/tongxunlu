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
//һ������������洢������
#define name_max 15//�����ֶ�����ܴ洢�����ֽ�
#define tel_max 12//�绰�ֶ�����ܴ洢�����ֽ�
#define xingbei_max 5//�Ա��ֶ�����ܴ洢�����ֽ�
#define zhuzhi_max 50//סַ�ֶ�����ܴ洢�����ֽ�
#define nianling_min 0//������Сֵ
#define nianling_max 150//�������ֵ
#define xingbie_min 0//�Ա�������Сֵ
#define xingbie_max 2//�Ա��������ֵ
#define jizhunshuju 32//�������ݶ����Դ���Ϊ׼
#define revow 2//���²���
#define continund 1//��������
#define �� 0//�Ա���
#define Ů 1//�Ա�Ů
#define ���� 2//�Ա���
#define fenge "--------------------------------------------------------------------------------------------------\n"
//һ���˵�����
typedef  struct id
{
	bool is_del_full;//��Ǵ������ϣ������ڶ����Ǳ�ʾһ��λ��tureΪ���ڣ�falseΪ������
	char name[name_max];//����
	char tel[tel_max];//�绰
	char xingbei[xingbei_max];//�Ա�
	char zhuzhi[zhuzhi_max];//סַ
	short age;//����
}id;
//��ϣ��ṹ���Ա��������Ϊ����
typedef struct hash
{
	unsigned long long size;//��ǰ����Ĵ�С�������
	unsigned long long max;//�������Ĵ�С
	bool* is_del;//����Ƿ�ɾ��
	id** value;//�洢��id�ṹ����
}hash;
typedef struct avltree//AVL���ṹ
{
	int height;//�߶�
	unsigned long long max_len;//�����������
	unsigned long long size;//��ǰ�ڵ������
	wchar_t* key;//��
	struct avltree* left;//������  
	struct avltree* right;//������
	id**value;//�洢��id�ṹ����
	bool* is_del;//����Ƿ�ɾ��
}avltree;
typedef struct queue//���нṹ
{
	avltree* data;//�洢������
	struct queue* next;//��һ���ڵ�
}queue;
//���У����ڵ���ʽ����avl��
typedef struct que
{
	unsigned long long size;//���е�����
	queue* front;//����ͷָ��
	queue* rear;//����βָ��
}que;
//һ���������
typedef  struct xinxi
{
	unsigned int size;//��ǰ��Ĵ�С
	id peo[];//�洢��id�ṹ
}xinxi;
//������ṹ
typedef struct node//ԭʼ���ݵĽڵ�ṹ
{
	id*start;//ָ���һ��id�ṹ
	id*end;//ָ�����һ��id�ṹ
	struct node* xiayige;//ָ����һ���ڵ�
	xinxi* people;//ָ���
}node;
typedef struct peizhi//�������ò����Ľṹ
{
	bool is_auto_baocun;//�Ƿ��̨�Զ�����(Ĭ�Ͽ���)
	bool is_kuai_max;//�Ƿ��޸Ŀ���������(Ĭ��û�޸ģ���ֻ�ܸ�һ��)
	unsigned int sheding_auto_baocun;//��̨�Զ����棨��λ���޸�/�Σ�
	unsigned int change_num;//�����޸Ĵ���
	unsigned int kuai_max;//����������
	HANDLE auto_baocun_thread;//�߳̾��
	int thread_num;//������ȡ������߳���
	unsigned long long total;//��������
}peizhixinxi;
typedef struct wnjian//�ļ��ṹ
{
	unsigned long long view_size;//����ͼ���ж��ٸ�����
	unsigned long long view_max;//��ǰ��ͼ���������
	unsigned long long delete_size;//ɾ���Ķ��ٸ�����
	unsigned long long delete_max;//ɾ�����������
	unsigned int link_len;//����ĳ���
	hash* nianling;//�����ϣ��
	hash* xingbie;//�Ա��ϣ��
	avltree* xingming;//����AVL��
	avltree* dianhua;//�绰AVL��
	avltree*zhuzhi;//סַAVL��
	id** view_data;//��ͼָ��,true��ʾ����
	id** delete_data;//ɾ����ָ��,false��ʾɾ��
	node* head;//ͷָ��
	node* tail;//βָ��
}wenjianxinxi;
typedef struct data//���ݽṹ
{
	wenjianxinxi wenjian;//�ļ��ṹ���洢�������ݣ�
	peizhixinxi peizhi;//���ò���
}DATA;
//�˵�
void menuone();
void menutow_caizuoshuju();
void menutow_tiaoxu();
void menu_wenjiancaizuo();
void new_node(DATA* data);//��ӽڵ�
void erji_caozuoshuju(DATA* data);//�������ݵĶ����˵�
void erji_tiaoxu(DATA* data);//�����ɸѡ�Ķ����˵�
DATA* erji_wenjiucaizuo(DATA* data);//����͵����Ķ����˵�
void free_head(DATA* data);
void anxia_continue();//���ո����
void huishouzhan(DATA* data);//����վ
int xingbei_to_num(char* s);//�Ա��ַ���ת����
//������������
char input_num_char(DATA*data);
//��֤�Ƿ�������,����ֵΪ0��ʾû�����ݣ�����ֵΪ��0��ʾ�����ݣ�ͬʱ����ֵ�������(ע���м�һ���ǵü�һ)����һ�����������飬�ڶ��������Ǹ�����Ĵ�С�������������Ǳ�ʶ�����ĸ������ǲ��ҵ�����true��false
unsigned long long yanzheng(id** value, unsigned  long long max, char* s1, bool type);
//��������
void chazhao(DATA*data);
//Ԥ����ӡ������Ϣ
void yulan(DATA* data);
//�����ַ�������֤��С����һ�Ĳ���Ϊ����λ�ã��ڶ�������Ϊ��ʾ��Ϣ������������Ϊ��󳤶�
void input(char* s1, char* s2, int a);
//��֤�Ƿ������Զ�����
void yanzheng_auto_save(DATA* data);
//��ӡԤ������
void dayinshuju(DATA* data);
//��ʼ������
DATA* chushihua_data();
//��ͼ�����������ؽ�,��һ������Ϊ����ָ�������򣬵ڶ�������Ϊ����ָ��bool�򣬵���������Ϊ������������ĸ�����Ϊ��ǰ���������������Ϊ���������ؽ������ͣ�type=1��ʾ����,type=2��ʾ�ؽ�
void chongjian_kuorong_view(id*** view, bool** is_del, unsigned long long* max, unsigned long long* size, int type);
//���½�����ϣ,�ڶ�����������ѡ��type=1��ʾ���䣬type=2��ʾ�Ա𣬵����������Ƿ�ɾ��ԭ����,is_del=2ʱ��ʾɾ��ԭ���ݣ�is_del=1ʱ��ʾ��ɾ��ԭ����
void chongjian_hash(DATA* data, int type, int is_del);
//�Ƿ��ؽ����ּ���type=2��ɾ�����м������ؽ���type=1ֻ����ĳһ���ݵļ�
void datas_to_index(DATA* data, id** value, int type, int flag);//Ŀǰû���뵽��ô�Ż������ñ�������
wchar_t* ctow(const char* str);//ת��Ϊ���ַ����бȽ�
//��avl��(ģ������)����һ�������Ǹ��ڵ㣬�ڶ���������Ҫ���ҵ�ֵ�������������Ƿ��صĴ�С,���ĸ������ǲ��Ҳ��ҿ�ͷ2�����Ӵ�3ȫ��1
id** find_avltree(avltree* root, wchar_t* value, unsigned long long* return_size, int type);
void dayinxiangxixinxi(id* tmp, bool* found);//��ӡ��ϸ��Ϣ

void free_avl(avltree* root);//�ͷ�avl��
void nothing(long long found, char* s1);
void  del_to_index(DATA* data, id* value ,id tmp_id);//ɾ�����ݵ�����

//һ���˵�ö��
enum caidanyiji
{
	�˳�������,
	Ԥ��,
	��������,
	����,
	�����ɸѡ,
	�ļ�����,
	����,
	�˳������� = 9,
};
//�̶��Ķ����˵�ö��
enum one
{
	����
};
//�����˵��������ݵ�ö��
enum caidanerji_caizuoshuju
{
	��� = 1,
	�޸�,
	ɾ��,
	����վ,
};
//�����˵������ɸѡ��ö��
enum caidanerji_tiaoxu
{
	���� = 1,
	ɸѡ,
};
//�����˵�����͵�����ö��
enum caidanerji_wenjiucaizuo
{
	���� = 1,
	����,
	����,
	�Զ�����,
	�趨��������,

};
//ö�ٲ��ҵ�����
enum chazhaozhonglie
{
	����=1,
	�绰,
	����,
	�Ա�,
};