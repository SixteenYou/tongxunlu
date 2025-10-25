#ifndef TONGYONG
#define TONGYONG
#include"tongyong.h"
#endif // !TONGYONG
#ifndef IOPUT
#define IOPUT
#include"ioput.h"
#endif 
#ifndef PAIXUSHAIXUAN
#define PAIXUSHAIXUAN
#include"paixushaixuan.h"
#endif
#ifndef CAOZUO
#define CAOZUO
#include"caozuo.h"
#endif
//�ȽϺ���������qsort����
int cmp_name_sheng(const void* s1, const void* s2)
{
	wchar_t* str1 = ctow((*(id*)s1).name);
	wchar_t* str2 = ctow((*(id*)s2).name);
	return wcscmp(str1, str2);
}
int cmp_name_jiang(const void* s1, const void* s2)
{
	wchar_t* str1 = ctow((*(id*)s1).name);
	wchar_t* str2 = ctow((*(id*)s2).name);
	return wcscmp(str2, str1);
}
int cmp_nianling_jiang(const void* s1, const void* s2)
{
	return (*(id*)s2).age - (*(id*)s1).age;
}
int cmp_nianling_sheng(const void* s1, const void* s2)
{
	return (*(id*)s1).age - (*(id*)s2).age;
}
int cmp_dianhua_jiang(const void* s1, const void* s2)
{
	return strcmp(((id*)s1)->tel, ((id*)s2)->tel);
}
int cmp_dianhua_sheng(const void* s1, const void* s2)
{
	return strcmp(((id*)s2)->tel, ((id*)s1)->tel);
}
//����
void sort(DATA*data)
{
	if (data->peizhi.auto_baocun_thread != NULL)//�����ݽṹ���в���ʱ���ȴ��Զ�������߳̽���
		yanzheng_auto_save(data);
	system("cls");
	if (data->peizhi.total == 0)//���û�����ݾͲ���Ҫ����
	{
		printf("��û��������Ҫ���������������\n");
		Sleep(2000);
		return;
	}
	typedef int (*func)(const void* s1, const void* s2);//�ȽϺ�������
	func cmp[3][2] = { {cmp_name_sheng,cmp_name_jiang}, {cmp_nianling_sheng,cmp_nianling_jiang}, {cmp_dianhua_sheng,cmp_dianhua_jiang} };//�ȽϺ�������
	char a[3][20] = { "���ڰ�����������","���ڰ�����������","���ڰ��յ绰����" };
	while(1)
	{
		printf("������Ҫ����ʲô���򣿣�1����2����3�绰����ע�⣺�Ѿ���ʼ�����벻Ҫ����ֹͣ������������Ը���\n");
		int chose = input_num_char(data);
		if (chose >= '0' && chose <= '3')
		{
			printf("%s\n", a[chose - '1']);
			printf("������Ҫ�����ǵ��򣿣�1����2����\n");
			int shunxu = input_num_char(data);
			if (shunxu >= '0' && shunxu <= '2')
			{
				qsort(data->wenjian.view_data, data->wenjian.view_size, sizeof(id*), cmp[chose - '1'][shunxu - '1']);//����
				break;
			}
			else
				printf("�����������������\n");
		}
		else
			printf("�����������������\n");
	}
	printf("����ɹ�\n");
	if(data->peizhi.is_auto_baocun)
		data->peizhi.change_num += ((unsigned long long)data->peizhi.sheding_auto_baocun > data->peizhi.total ? (unsigned int)data->peizhi.total : data->peizhi.sheding_auto_baocun);
	Sleep(2000);
}
extern void chazhao_nianling_xingbie(hash* hash_table, int type, int flag);
extern void menu_chaozhao_xingbie();//�����Ա������
extern void menu_chaozhao_dianhua();//���ҵ绰������
extern void chazhao_avl(DATA* data, int type, int is_full);
//ɸѡ
void shaixuan(DATA *data)
{
	system("cls");
	if (yanzheng(data->wenjian.view_data,data->wenjian.view_size,"ɸѡ",true) == 0)//���û�����ݾͲ���Ҫɸѡ
		return;
	node* tmp = data->wenjian.head;
	printf("������Ҫɸѡʲô����1�Ա�2�绰3סַ��\n");
	char chose = input_num_char(data);
	while (1)
	{
		if (chose >= '0' && chose <= '3')
		{
			switch (chose - '0')
			{
			case 1:
				menu_chaozhao_xingbie();
				chose = input_num_char(data);
				if (chose == '0')
					return;
				chazhao_nianling_xingbie(data->wenjian.xingbie,chose - '0', 0);
				return;
			case 2:
			case 3:
				chazhao_avl(data, chose-'0', 3);
				return;
			}
		}
		else
			printf("�����������������\n");
	}
}