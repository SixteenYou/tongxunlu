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
//�˵�
void menuone()//һ���˵�
{
	printf("--------------------\n");
	printf("|      1.Ԥ��      |\n");
	printf("|    2.��������    |\n");
	printf("|      3.����      |\n");
	printf("|   4.�����ɸѡ   |\n");
	printf("|    5.�ļ�����    |\n");
	printf("|      6.����      |\n");
	printf("|   9.�˳�������   |\n");
	printf("|   0.�˳�������   |\n");
	printf("--------------------\n");
}
void menutow_caizuoshuju()//�������ݵĶ����˵�
{
	printf("--------------------\n");
	printf("|      1.���      |\n");
	printf("|      2.�޸�      |\n");
	printf("|      3.ɾ��      |\n");
	printf("|     4.����վ     |\n");
	printf("|      0.����      |\n");
	printf("--------------------\n");
}
void menutow_tiaoxu()//�����ɸѡ�Ķ����˵�
{
	printf("--------------------\n");
	printf("|      1.����      |\n");
	printf("|      2.ɸѡ      |\n");
	printf("|      0.����      |\n");
	printf("--------------------\n");
}
void menu_wenjiancaizuo()//����͵����Ķ����˵�
{
	printf("--------------------\n");
	printf("|      1.����      |\n");
	printf("|      2.����      |\n");
	printf("|      3.����      |\n");
	printf("|    4.�Զ�����    |\n");
	printf("|  5.�趨��������  |\n");
	printf("|      0.����      |\n");
	printf("--------------------\n");
}

void menu_chazhao()//���ҵ�����
{
	printf("--------------------\n");
	printf("|      1.����      |\n");
	printf("|      2.�绰      |\n");
	printf("|      3.����      |\n");
	printf("|      4.�Ա�      |\n");
	printf("|      0.����      |\n");
	printf("--------------------\n");
}
void menu_chaozhao_mingzi()//��������������
{
	printf("-------------------\n");
	printf("|    1.����ȫ��   |\n");
	printf("|      2.��ͷ     |\n");
	printf("|    3.��������   |\n");
	printf("|      0.����     |\n");
	printf("-------------------\n");
}
void menu_chaozhao_dianhua()//���ҵ绰������
{
	printf("--------------------\n");
	printf("|    1.�绰ȫ��    |\n");
	printf("|      2.��ͷ      |\n");
	printf("|  3.�����ĵ绰��  |\n");
	printf("|      0.����      |\n");
	printf("--------------------\n");
}
void menu_chaozhao_nianling()//�������������
{
	printf("----------------------\n");
	printf("|     1.���䷶Χ     |\n");
	printf("| 2.���ڵ���ĳ������ |\n");
	printf("| 3.С�ڵ���ĳ������ |\n");
	printf("|   4.����ĳ������   |\n");
	printf("|       0.����       |\n");
	printf("----------------------\n");
}
void menu_chaozhao_xingbie()//�����Ա������
{
	printf("------------------\n");
	printf("|      1.��      |\n");
	printf("|      2.Ů      |\n");
	printf("|     3.����     |\n");
	printf("|     0.����     |\n");
	printf("------------------\n");
}
void erji_caozuoshuju(DATA* data)//�������ݵĶ����˵�
{
	if (data->peizhi.auto_baocun_thread != NULL)//�����ݽṹ���в���ʱ���ȴ��Զ�������߳̽���
		yanzheng_auto_save(data);
	int tmp = 0;//tmp�����ж��Ƿ�������
	while (1)
	{
		system("cls");
		menutow_caizuoshuju();
		char chose = input_num_char(data);
		switch (chose - '0')
		{
		case ���:
			do{
				data->wenjian.tail=tianjia(data);
				tmp = 0;
				printf("�����Ƿ������ӣ�(y/n)\n");
				char tmp_char = input_num_char(data);
				if (tmp_char == 'y' || tmp == 'Y')
					tmp = 1;
			} while (tmp);
			return;
		case �޸�:
			do {
				xuigai(data);
				tmp = 0;
				printf("�����Ƿ�����޸ģ�(y/n)\n");
				char tmp_char = input_num_char(data);
				if (tmp_char == 'y' || tmp == 'Y')
					tmp = 1;
			} while (tmp);
			return;
		case ɾ��:
			do {
				shanchu(data);
				tmp = 0;
				printf("�����Ƿ����ɾ����(y/n)\n");
				char tmp_char = input_num_char(data);
				if (tmp_char == 'y' || tmp == 'Y')
					tmp = 1;
			} while (tmp);
			return;
		case ����վ:
			huishouzhan(data);
			return;
		case ����:
			return;
		default:
			printf("�����������������\n");
			Sleep(2000);
			break;
		}
	}
}
void erji_tiaoxu(DATA* data)//�����ɸѡ�Ķ����˵�
{
	while (1)
	{
		system("cls");
		menutow_tiaoxu();
		char chose = input_num_char(data);
		switch (chose - '0')
		{
		case ����:
			sort(data);
			return;
		case ɸѡ:
			shaixuan(data);
			return;
		case ����:
			return;
		default:
			printf("�����������������\n");
			Sleep(2000);
			break;
		}
	}
}
void save_change(DATA*data)//�Զ����湦��
{
	system("cls");
	if (data->peizhi.is_auto_baocun)
	{
		printf("�Զ����湦���ѿ���,������Ҫ�ر��Զ����湦����(y/n)(�����Զ��������������й����У�������Զ��������ݣ������ֶ�����)\n");
		char tmp_char;
		if(scanf("%c", &tmp_char))
		{
			while (getchar() != '\n');
			if (tmp_char == 'y' || tmp_char == 'Y')
			{
				data->peizhi.is_auto_baocun = false;
				printf("�Զ����湦���ѹرգ���ע�����ݰ�ȫ\n");
				Sleep(1000);
			}
		}
		else
		{
			while (getchar() != '\n');
			printf("����������Ժ���������\n");
			Sleep(2000);
		}
	}
	else
	{
		printf("�Զ����湦���ѹر�,������Ҫ�����Զ����湦����(y/n)(�����Զ��������������й����У�������Զ��������ݣ������ֶ�����)\n");
		char tmp_char;
		if (scanf("%c", &tmp_char))
		{
			while (getchar() != '\n');
			if (tmp_char == 'y' || tmp_char == 'Y')
			{
				data->peizhi.is_auto_baocun = true;
				printf("�Զ����湦���ѿ���\n");
				Sleep(1000);
			}
		}
		else
		{
			while (getchar() != '\n');
			printf("����������Ժ���������\n");
			Sleep(2000);
		}
	}
}
void set_save_num(DATA*data)//�趨��������
{
	system("cls");
	if (data->peizhi.is_auto_baocun)
	{
		printf("��ǰÿ����%d�����ݣ�����Զ�����һ��\n", data->peizhi.sheding_auto_baocun);
		printf("�Զ����湦���ѿ���,������Ҫ�޸��Զ������������(��������10-100)(������̫�����̫С��̫�����û����ʱ���棬̫С���ܱ�����ļ�Ƶ��)\n");
		printf("�������µ��Զ�����������");
		int tmp_num;
		if (scanf("%d", &tmp_num))
		{
			while (getchar() != '\n');
			if(tmp_num >= 10 && tmp_num <= 100)
			{
				data->peizhi.sheding_auto_baocun = (unsigned int)tmp_num;
				printf("�Զ����������������Ϊ%u\n",data->peizhi.sheding_auto_baocun);
				Sleep(1000);
			}
			else
			{
				printf("��������������Ҫ�����Ժ���������\n");
				Sleep(2000);
			}
		}
		else
		{
			while (getchar() != '\n');
			printf("����������Ժ���������\n");
			Sleep(2000);	
		}
	}
	else
	{
		printf("�Զ����湦���ѹر�,Ҫ�ȿ����Զ����湦�ܲ������ñ�������\n");
		Sleep(2000);
	}
}
DATA* erji_wenjiucaizuo(DATA* data)//����͵����Ķ����˵�
{
	while (1)
	{
		system("cls");
		menu_wenjiancaizuo();
		char chose = input_num_char(data);
		switch (chose - '0')
		{
		case ����:
			data->wenjian.tail=daoru(data);
			return data;
		case ����:
			daochuwenjian(data);
			return data;
		case ����:
			data=chongzhi(&data);
			return data;
		case �Զ�����:
			save_change(data);
			return data;
		case �趨��������:
			set_save_num(data);
			return data;
		case ����:
			return data;
		default:
			printf("�����������������\n");
			Sleep(2000);
			break;
		}
	}
}
void new_node(DATA*data)//��ӽڵ�
{
	node* tmp = (node*)calloc(1,sizeof(node));//����һ���µĽڵ�
	if (tmp == NULL)
	{
		printf("%s\n", strerror(errno));
		printf("�ڴ����ʧ�ܣ�����ʹ���ֲ�\n");
		return;
	}
	tmp->people = (xinxi*)calloc(1,sizeof(xinxi) + (data->peizhi.kuai_max) * sizeof(id));//����һ���µĿ�
	if (tmp->people == NULL)
	{
		printf("%s\n", strerror(errno));
		printf("�ڴ����ʧ�ܣ�����ʹ���ֲ�\n");
		return;
	}
	tmp->people->size = 0;
	tmp->xiayige = NULL;
	tmp->start = &(tmp->people->peo[0]);
	tmp->end = &(tmp->people->peo[data->peizhi.kuai_max - 1]);
	data->wenjian.link_len++;
	data->wenjian.tail->xiayige = tmp;//����ǰ�ڵ����һ���ڵ�ָ���½ڵ�
}
//�ͷ��ڴ�	
void free_head(DATA* data)
{
	node* txl = data->wenjian.head;
	while (txl != NULL)
	{
		node* tmp = txl;
		txl = txl->xiayige;
		if(tmp->people!= NULL)
		{
			free(tmp->people);
			tmp->people = NULL;
		}
		free(tmp);
		tmp = NULL;
	}
	free(data->wenjian.view_data);
	data->wenjian.view_data = NULL;
	data->wenjian.view_size = 0;
	data->wenjian.link_len = 0;
	free(data->wenjian.delete_data);
	data->wenjian.delete_data = NULL;
	data->wenjian.delete_size = 0;
	free_avl(data->wenjian.dianhua);
	data->wenjian.dianhua = NULL;
	free_avl(data->wenjian.xingming);
	data->wenjian.xingming = NULL;
	free_avl(data->wenjian.zhuzhi);
	data->wenjian.zhuzhi = NULL;
	data->wenjian.head = NULL;
	data->wenjian.tail = NULL;
	for (int i = xingbie_min; i <= xingbie_max; i++)
	{
		if(data->wenjian.xingbie[i].value!= NULL)
			free(data->wenjian.xingbie[i].value);
		data->wenjian.xingbie[i].value = NULL;
		if(data->wenjian.xingbie[i].is_del!= NULL)
			free(data->wenjian.xingbie[i].is_del);
		data->wenjian.xingbie[i].is_del = NULL;
	}
	free(data->wenjian.xingbie);
	data->wenjian.xingbie = NULL;
	for (int i = nianling_min; i <= nianling_max; i++)
	{
		if (data->wenjian.nianling[i].value!= NULL)
			free(data->wenjian.nianling[i].value);
		data->wenjian.nianling[i].value = NULL;
		if (data->wenjian.nianling[i].is_del!= NULL)
			free(data->wenjian.nianling[i].is_del);
		data->wenjian.nianling[i].is_del = NULL;
	}
	free(data->wenjian.nianling);
	data->wenjian.nianling = NULL;
	free(data);
}
HANDLE WINAPI save_file(LPVOID tmp)
{
	savefile((DATA*)tmp);
	return 0;
}
//������������
char input_num_char(DATA*data)
{
	char tmp;
	printf("��ESC���˳����(������)\n");
	while (1)
	{
		if (_kbhit())
		{
			tmp = _getch();
			if (tmp == 27)
			{
				printf("�˳����\n");
				Sleep(1000);
				exit(0);
			}
			break;
		}
		if (data->peizhi.is_auto_baocun && data->peizhi.change_num >=data->peizhi.sheding_auto_baocun)
		{
			data->peizhi.auto_baocun_thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)save_file, data, 0, NULL);
			data->peizhi.change_num = 0;
		}
		Sleep(200);
	}
	return tmp;
}
void yanzheng_auto_save(DATA* data)//��֤�Ƿ������Զ�����
{
	printf("�����Զ������У����Ժ�\n");
	WaitForSingleObject(data->peizhi.auto_baocun_thread, INFINITE);
	CloseHandle(data->peizhi.auto_baocun_thread);
	data->peizhi.auto_baocun_thread = NULL;
	printf("�Զ��������\n");
}
//��֤�Ƿ�������
unsigned long long yanzheng(id**value,unsigned  long long max,char* s1,bool type)
{
	for(unsigned long long i=0; i< max;i++)
		if((*value)[i].is_del_full==type)
			return i+1;
	printf("��û��������Ҫ%s�������������\n",s1);
	Sleep(1000);
	return 0;
}
void dayinshuju(DATA* data)
{
	long long count = 0;
	unsigned long long i = 0;
	printf("-----------------------------\n");
	printf("| %10s | %12s |\n", "����", "�绰");
	printf("-----------------------------\n");
	for(;i<data->wenjian.view_size;i++)
		if(data->wenjian.view_data[i]->is_del_full)
		{
			printf("| %10s | %12s |\n", data->wenjian.view_data[i]->name, data->wenjian.view_data[i]->tel);
			count++;
		}
	printf("-----------------------------\n");
	printf("|���Ϲ���%11lldλ��ϵ��|\n", count);
	printf("-----------------------------\n");
}
//Ԥ����ӡ������Ϣ

void yulan(DATA*data)
{
	system("cls");
	unsigned long long i= yanzheng(data->wenjian.view_data,data->wenjian.view_size, "Ԥ��", true);
	if(i--==(unsigned long long)0)
		return;
	for (; i < data->wenjian.view_size; i++)
	{
		if (data->wenjian.view_data[i]->is_del_full == true)
			break;
	}
	dayinshuju(data);
	if (data->peizhi.total > 10000)
	{
		printf("ע��:��ʱ������Ϊ%lld�������е��������ÿ���̨������ܻ�����⣬��ʱ����ʹ�÷�΢�����̨\n", data->peizhi.total);
		Sleep(3000);
		return;
	}
	anxia_continue();
}
static void print_flag(bool* flag_found)//��ӡ����
{
	if (*flag_found)
	{
		system("cls");
		printf(fenge);
		printf("| %10s | %5s | %5s | %12s | %50s |\n", "����", "���� ", "�Ա�", "�绰", "סַ");
		printf(fenge);
		*flag_found = false;
	}
}
void dayinxiangxixinxi(id* tmp,bool*found)//��ӡ��ϸ��Ϣ
{
	print_flag(found);
	printf("| %10s | %5hd | %5s | %12s | %50s |\n", tmp->name,tmp->age, tmp->xingbei, tmp->tel, tmp->zhuzhi);
}
void nothing(long long found, char* s1)
{
	if (found > 0)
		printf(fenge"���Ϲ�%lld����ϵ��\n", found);
	else
		printf("%s\n", s1);
}
wchar_t* ctow(const char* str)//ת��Ϊ���ַ����бȽ�
{
	size_t len = strlen(str) + 1;
	size_t i = 0;
	wchar_t* wstr = (wchar_t*)malloc(len * sizeof(wchar_t));
	mbstowcs_s(&i, wstr, len, str, _TRUNCATE );
	return wstr;
}
//�������ݣ���һ���������������ݽṹ���ڶ����ǲ�������1Ϊ������2Ϊ�绰��3Ϊסַ���������ǲ����ȫ��1����ͷ2�������Ӵ�3��
void chazhao_avl(DATA*data,int type,int is_full)
{
	char biaotou[100];
	char jiewei[100];
	char shuju1[3][20] = {{"����"},{"�绰"},{"סַ"}};
	char shuju2[3][20] = { {"ȫ��"},{"��ͷ"},{"������"}};
	char tmp[100];
	sprintf(biaotou, "��Ҫ����%s��%s", shuju1[type-1], shuju2[is_full-1]);
	sprintf(jiewei, "������˼��û���ҵ�����Ҫ%s��%s", shuju1[type - 1], shuju2[is_full-1]);
	input(tmp, biaotou, 100);
	wchar_t* wtmp = ctow(tmp);
	id** return_data = NULL;
	unsigned long long index = 0;
	bool flag_found = true;
	switch (type)
	{
	case 1:
		return_data = find_avltree(data->wenjian.xingming,wtmp,&index,is_full);
		break;
	case 2:
		return_data = find_avltree(data->wenjian.dianhua, wtmp, &index, is_full);
		break;
	case 3:
		return_data = find_avltree(data->wenjian.zhuzhi, wtmp, &index, is_full);
		break;
	}
	for (unsigned long long i = 0; i < index; i++)
	{
		print_flag(&flag_found);
		dayinxiangxixinxi(return_data[i], &flag_found);
	}
	nothing(index, jiewei);
	anxia_continue();
	free(return_data);
}
int input_nianling(short* left)
{
	if (scanf(" %hd", left) == 1)
	{
		while (getchar() != '\n');
		if (*left >= nianling_min && *left <= nianling_max)
			return 1;
		return 0;
	}
	else
		while (getchar() != '\n');//������뻺����
	return 0;
}
//���ҹ�ϣ��falgΪ1ʱ��ʾ�����䣬Ϊ0ʱ��ʾ���Ա�
void chazhao_nianling_xingbie(hash* hash_table,int type,int flag)
{
	long long found = 0;
	bool flag_found = true;
	char biaotou[100];
	char jiewei[100];
	char* a[3] = { "��","Ů","����" };
	short left = nianling_min, right = nianling_max;
	if(flag == 1)
	{
		short t_left, t_right;
		sprintf(jiewei, "��������ȷ�����֣�ע�⣺���䷶Χ��%d - %d\n", nianling_min, nianling_max);
		sprintf(biaotou, "��������Ҫ%%s�����䣨�涨������ķ�Χ��%d-%d��\n", nianling_min, nianling_max);
		switch (type)
		{
		case 1:
			while (1)
			{
				printf("����������ķ�Χ(�涨������ķ�Χ��%d-%d)(����֮���ÿո����)(����С�ģ�������)\n", nianling_min, nianling_max);
				if (scanf("%hd %hd", &t_left, &t_right) == 2)
				{
					while (getchar() != '\n');
					left = t_left < t_right ? t_left : t_right;
					right = t_left < t_right ? t_right : t_left;
					break;
				}
				else
				{
					while (getchar() != '\n');
					printf(jiewei);
				}
			}
			sprintf(jiewei, "������˼,û���ҵ�������%hd-%hd����", left, right);
			break;
		case 2:
			while (1)
			{
				printf(biaotou, "���ڶ���");
				if (input_nianling(&t_left) == 1)
				{
					left = t_left;
					break;
				}
				else
					printf(jiewei);
			}
			sprintf(jiewei, "������˼,û���ҵ��������%hd����", left);
			break;
		case 3:
			while (1)
			{
				printf(biaotou, "С�ڶ���");
				if (input_nianling(&t_right) == 1)
				{
					right = t_right;
					break;
				}
				else
					printf(jiewei);
			}
			sprintf(jiewei, "������˼,û���ҵ�����С��%hd����", right);
			break;
		case 4:
			while (1)
			{
				printf(biaotou, "��");
				if (input_nianling(&t_left) == 1)
				{
					left = t_left;
					right = t_left;
					break;
				}
				else
					printf(jiewei);
			}
			sprintf(jiewei, "������˼,û���ҵ�����Ϊ%hd����", left);
			break;
		}
	}
	else
	{
		sprintf(jiewei, "������˼,û���ҵ��Ա�Ϊ%s����", a[type-1]);
		left = type-1;
		right = type-1;
	}
	for (short i = left; i <= right; i++)
	{
		for (unsigned long long j = 0; j < hash_table[i].size; j++)
			if (hash_table[i].is_del[j]==true)
			{
				print_flag(&flag_found);
				dayinxiangxixinxi(hash_table[i].value[j], &flag_found);
				found++;
			}
	}
	nothing(found, jiewei);
	anxia_continue();
}
//��������
void chazhao(DATA*data)
{
	system("cls");
	if (yanzheng(data->wenjian.view_data, data->wenjian.view_size, "����", true) == (unsigned long long)0)
		return;
	menu_chazhao();
	int type = input_num_char(data);//�����жϲ��ҵ�����
	typedef void(*func)(node*head);
	system("cls");
	switch (type - '0')
	{
	case ����:
		menu_chaozhao_mingzi();
		type = input_num_char(data);//�����жϲ�������������
		if (type == ���� + '0')
			return;
		chazhao_avl(data, 1, type - '0');
		return;
	case �绰:
		menu_chaozhao_dianhua();
		type = input_num_char(data);//�����жϲ��ҵ绰������
		if (type == ���� + '0')
			return;
		chazhao_avl(data, 2, type - '0');
		return;
	case ����:
		menu_chaozhao_nianling();
		type = input_num_char(data);//�����жϲ������������
		if (type == ���� + '0')
			return;
		chazhao_nianling_xingbie(data->wenjian.nianling, type - '0',1);
		return;
	case �Ա�:
		menu_chaozhao_xingbie();
		type = input_num_char(data);//�����жϲ����Ա������
		if (type == ���� + '0')
			return;
		chazhao_nianling_xingbie(data->wenjian.xingbie,type - '0',0);
		return;
	case ����:
		return;
	default:
		printf("�����������������\n");
		Sleep(2000);
		break;
	}
}
//�����ַ�������֤��С
void input(char* s1, char* s2, int a)
{
	char wight[10];
	sprintf(wight, " %%%ds", zhuzhi_max);
	while (1)
	{
		char tmp[zhuzhi_max + 5];
		printf("������%s\n", s2);
		if (scanf(wight, tmp) == 1)
		{
			while (getchar() != '\n');
			if (strlen(tmp) <= a - 1)
			{
				strcpy(s1, tmp);
				break;
			}
			else
			{
				printf("�����%s����������������\n", s2);
				continue;
			}
		}
		while (getchar() != '\n');
		printf("��������ȷ��%s\n", s2);
	}
}
void anxia_continue()//���ո����
{
	printf("���ո����......\n");
	while (1)
	{
		if (_kbhit())
		{
			char tmp = _getch();
			if (tmp == ' ')
				break;
		}
		Sleep(200);
	}
}
DATA* chushihua_data()
{
	DATA* data = (DATA*)calloc(1, sizeof(DATA));//�洢��������
	if (data == NULL)
		printf("%s\n", strerror(errno));
	data->peizhi.is_auto_baocun = true;//Ĭ�Ͽ�����̨�Զ�����
	data->peizhi.sheding_auto_baocun = jizhunshuju;//��̨�Զ�����ʱ��Ϊ32���޸�
	data->peizhi.kuai_max = jizhunshuju;//��ʼĬ���£�һ�������������Ϊ�����ײ����ֵ���ڵ�һ�ζ�ȡ�ļ�ʱ������ݵ�ǰ��ȡ���������Ĵ�С��������Ĵ�С��ֻ�ܵ���һ�Σ����������ٵ���
	data->peizhi.is_kuai_max = true;//Ĭ�Ͽ����޸�������������޸ĺ���ֱ��ֹͣ�޸ģ�ֱ���´���������
	data->peizhi.total = 0;//��������
	data->peizhi.change_num = 0;//�޸Ĵ���
	data->peizhi.thread_num = 8;//�߳���
	data->wenjian.head = (node*)calloc(1, sizeof(node));//ͷ�ڵ�
	if (data->wenjian.head == NULL)
		printf("%s\n", strerror(errno));
	data->wenjian.head->xiayige = NULL;//ͷ�ڵ����һ���ڵ�
	data->wenjian.head->people = (xinxi*)calloc(1, sizeof(xinxi) + data->peizhi.kuai_max * sizeof(id));//ͷ�ڵ�ĵ�һ����
	if (data->wenjian.head->people == NULL)
		printf("%s\n", strerror(errno));
	data->wenjian.head->people->size = 0;//��ǰ��Ĵ�С�������
	data->wenjian.head->start = &(data->wenjian.head->people->peo[0]);
	data->wenjian.head->end = &(data->wenjian.head->people->peo[data->peizhi.kuai_max-1]);
	data->wenjian.tail = data->wenjian.head;//β�ڵ�
	data->peizhi.auto_baocun_thread = NULL;
	data->wenjian.xingming=NULL;
	data->wenjian.zhuzhi=NULL;
	data->wenjian.dianhua=NULL;
	data->wenjian.link_len = 1;
	data->wenjian.xingbie = (hash*)calloc(xingbie_max + 1, sizeof(hash));
	data->wenjian.nianling = (hash*)calloc(nianling_max + 1, sizeof(hash));
	chongjian_kuorong_view(&data->wenjian.delete_data, NULL, &data->wenjian.delete_max, &data->wenjian.delete_size, 2);//��ʼ��ɾ����
	chongjian_kuorong_view(&data->wenjian.view_data, NULL, &data->wenjian.view_max, &data->wenjian.view_size, 2);//��ʼ����ͼ��
	chongjian_hash(data, 1, revow);//��ʼ�������ϣ��
	chongjian_hash(data, 2, revow);//��ʼ���Ա��ϣ��
	return data;
}
int xingbei_to_num(char* s)//�Ա��ַ���ת����
{
	if (strcmp(s, "��") == 0)
		return ��;
	else if (strcmp(s, "Ů") == 0)
		return Ů;
	else if (strcmp(s, "����") == 0)
		return ����;
	else
		return -1;
}
static int cmp(const void* a, const void* b)
{
	id* p2 = *((id**)a);
	id* p1 = *((id**)b);
	return (p1 < p2) ? -1 : (p1 > p2) ? 1 : 0;
}
void huishouzhan(DATA* data)//����վ
{
	system("cls");
	unsigned long long i = yanzheng(data->wenjian.delete_data, data->wenjian.delete_size, "����վ", false);
	if ( i-- == (unsigned long long)0)
		return;
	bool flag_delete=true;
	unsigned long long count = 0;
	for (; i < data->wenjian.delete_size; i++)
		if (data->wenjian.delete_data[i]->is_del_full == false)
		{
			dayinxiangxixinxi(data->wenjian.delete_data[i], &flag_delete);
			count++;
		}
	nothing(count, "����վΪ��");
	while (1)
	{
		printf("��������Ҫѡ��Ĳ�����\n1.�ָ�\n2.��ջ���վ������ɾ����\n0.����\n");
		int type = input_num_char(data);
		switch (type - '0')
		{
		case 1:
			printf("��������Ҫ�ָ��ĵڼ�����ϵ�ˣ�0��ָ����У���\n");
			while (1)
				if (scanf(" %llu", &count) == 1)
				{
					while (getchar() != '\n');//������뻺����
					if (count == 0)
					{
						for (int i = 0; i < data->wenjian.delete_size; i++)
							data->wenjian.delete_data[i]->is_del_full = true;
						chongjian_kuorong_view(&data->wenjian.delete_data, NULL, &data->wenjian.delete_max, &data->wenjian.delete_size, 2);
						printf("�ָ��ɹ�\n");
						Sleep(2000);
						return;
					}
					else
					{
						if (count-- > data->wenjian.delete_size)
						{
							printf("û���������ݣ����Ժ�����\n");
							return;
						}
						for (int i = 0; i < data->wenjian.delete_size; i++)
						{
							if (data->wenjian.delete_data[i]->is_del_full == false && count != 0)
								count--;
							else if (data->wenjian.delete_data[i]->is_del_full == false && count == 0)
							{
								printf("�ָ��ɹ�\n");
								data->wenjian.delete_data[i]->is_del_full = true;
								Sleep(2000);
								return;
							}
						}
						if (count != 0)
						{
							printf("û���������ݣ����Ժ�����\n");
							Sleep(2000);
							return;
						}
					}
				}
				else
				{
					while (getchar() != '\n');
					printf("��������ȷ������\n");
				}
			break;
		case 2:
			while (1)
			{
				printf("��ȷ��Ҫ��ջ���վ��,��պ��޷��ָ����Ƿ������(Y/N)\n");
				char tmp = input_num_char(data);
				if (tmp == 'Y' || tmp == 'y')
				{
					printf("������ջ���վ�����Ժ�\n");
					qsort(data->wenjian.delete_data, data->wenjian.delete_size, sizeof(id*), cmp);
					for (unsigned long long i = 0; i < data->wenjian.delete_size; i++)//��������վ
					{
						node* tmp = data->wenjian.head;
						while (tmp != NULL)//��������
						{
							if (data->wenjian.delete_data[i] >= tmp->start && data->wenjian.delete_data[i] <= tmp->end)
							{
								for (unsigned int j = (unsigned int)((data->wenjian.delete_data[i] - tmp->start)); j < tmp->people->size; j++)//��ʼ�������
									tmp->people->peo[j] = tmp->people->peo[j + 1];//ǰ������
								tmp->people->size--;//�޸Ĵ�С
								data->peizhi.total--;//�޸���������
								break;
							}
							tmp = tmp->xiayige;
						}
					}
					//���ּ����ؽ�����
					datas_to_index(data, NULL, revow,1);
					printf("��ջ���վ�ɹ�\n");
					Sleep(2000);
					return;
				}
				else
				{
					printf("ȡ����ջ���վ\n");
					Sleep(2000);
					return;
				}
			}
		case ����:
			return;
		default:
			printf("�����������������\n");
			break;
		}
	}
}
void chongjian_hash(DATA* data,int type,int is_del)
{
	if (is_del==revow)
		if(type==1)
			for (int i = nianling_min; i <= nianling_max; i++)
			{
				if(data->wenjian.nianling[i].value!=NULL)
					free(data->wenjian.nianling[i].value);
				if(data->wenjian.nianling[i].is_del!=NULL)
					free(data->wenjian.nianling[i].is_del);
				data->wenjian.nianling[i].value = NULL;
				data->wenjian.nianling[i].is_del = NULL;
				data->wenjian.nianling[i].size = 0;
				data->wenjian.nianling[i].max = jizhunshuju;
			}
		else
			for (int i = xingbie_min; i <= xingbie_max; i++)
			{
				if(data->wenjian.xingbie[i].value!=NULL)
					free(data->wenjian.xingbie[i].value);
				if(data->wenjian.xingbie[i].is_del!=NULL)
					free(data->wenjian.xingbie[i].is_del);
				data->wenjian.xingbie[i].value = NULL;
				data->wenjian.xingbie[i].is_del = NULL;
				data->wenjian.xingbie[i].size = 0;
				data->wenjian.xingbie[i].max = jizhunshuju;
			}
	if (type == 1)
	{
		for (int i = nianling_min; i <= nianling_max; i++)
		{
			data->wenjian.nianling[i].value = (id**)calloc(jizhunshuju, sizeof(id*));
			data->wenjian.nianling[i].is_del = (bool*)calloc(jizhunshuju, sizeof(bool));
		}
	}
	else
	{
		for (int i = xingbie_min; i <= xingbie_max; i++)
		{
			data->wenjian.xingbie[i].value = (id**)calloc(jizhunshuju, sizeof(id*));
			data->wenjian.xingbie[i].is_del = (bool*)calloc(jizhunshuju, sizeof(bool));
		}
	}
}
void chongjian_kuorong_view(id*** view,bool**is_del, unsigned long long* max, unsigned long long* size,int type)
{
	id** new_view = NULL;
	bool* new_is_del = NULL;
	if (type == revow)
	{
		if(view!=NULL&&*view!=NULL)
			free(*view);
		if (is_del!=NULL&&*is_del!= NULL)
			free(*is_del);
		if(view!=NULL)
			*view=NULL;
		if (is_del!=NULL)
			*is_del=NULL;
		*size = 0;
		*max = jizhunshuju;
	}
	else
		(*max) <<= 1;
	new_view = (id**)realloc(*view, sizeof(id*)* *max);
	if (new_view == NULL)
		printf("%s\n", strerror(errno));
	*view = new_view;
	if(is_del!=NULL)//���û��ɾ���򣬾Ͳ������·���ռ���
	{
		new_is_del = (bool*)realloc(*is_del, sizeof(bool) * *max);
		if (new_is_del == NULL)
			printf("%s\n", strerror(errno));
		*is_del = new_is_del;
	}
}
que* createQue()//��������
{
	que* q = (que*)malloc(sizeof(que));
	if (q == NULL)
		printf("%s\n", strerror(errno));
	q->front = q->rear = NULL;
	q->size = 0;
	return q;
}
void insert_que(que* q, avltree* node)
{
	queue* new = (queue*)malloc(sizeof(queue));
	if (new == NULL)
		printf("%s\n", strerror(errno));
	new->data = node;
	new->next = NULL;
	if (q->size == 0)
		q->front = q->rear = new;
	else
	{
		q->rear->next = new;
		q->rear = new;
	}
	q->size++;
}
queue* out_que(que* q)
{
	queue* tmp = NULL;
	if (q->size == 0)
		return NULL;
	if (q->size == 1)
	{
		tmp= q->front;
		q->front = q->rear = NULL;
	}
	else
	{
		tmp = q->front;
		q->front = q->front->next;
	}
	q->size--;
	return tmp;
}
void free_que(que* q)
{
	while (q->size != 0)
	{
		queue* tmp = out_que(q);
		free(tmp);
	}
	free(q);
}
int get_hight(avltree* root)
{
	if (root == NULL)
		return 0;
	return root->height;
}
int blance_factor(avltree* root)
{
	if (root == NULL)
		return 0;
	return get_hight(root->left) - get_hight(root->right);
}
int updata_height(avltree* root)
{
	if (root == NULL)
		return 0;
	int left_height = get_hight(root->left);
	int right_height = get_hight(root->right);
	return  (left_height > right_height) ? (left_height + 1) : (right_height + 1);
}
avltree* left_rotate(avltree* root)//����ת
{
	avltree* new_root = root->right;
	root->right = new_root->left;
	new_root->left = root;
	root->height = updata_height(root);
	new_root->height = updata_height(new_root);
	return new_root;
}
avltree* right_rotate(avltree* root)//����ת
{
	avltree* new_root = root->left;
	root->left = new_root->right;
	new_root->right = root;
	root->height = updata_height(root);
	new_root->height = updata_height(new_root);
	return new_root;
}
avltree* insert_avl(avltree* root, wchar_t* key, id** value)
{
	if (root == NULL)
	{
		root = (avltree*)calloc(1, sizeof(avltree));
		root->key = key;
		root->left = NULL;
		root->right = NULL;
		root->size = 1;
		root->height = 1;
		root->max_len = jizhunshuju;
		root->value = (id**)calloc(1, sizeof(id*) * root->max_len);
		root->is_del = (bool*)calloc(1, sizeof(bool) * root->max_len);
		root->value[0] = *value;
		root->is_del[0] = true;
		return root;
	}
	if (wcscmp(key, root->key) < 0)
		root->left = insert_avl(root->left, key, value);
	else if (wcscmp(key, root->key) > 0)
		root->right = insert_avl(root->right, key, value);
	else
	{
		if (root->size == root->max_len)
			chongjian_kuorong_view(&root->value, &root->is_del, &root->max_len, &root->size, 2);
		root->value[root->size] = *value;
		root->is_del[root->size] = true;
		root->size++;
	}
	root->height = updata_height(root);
	int blance = blance_factor(root);
	if (blance > 1)
	{
		blance = blance_factor(root->left);
		if (blance > 0)
			root->left = left_rotate(root->left);
		return right_rotate(root);
	}
	else if (blance < -1)
	{
		blance = blance_factor(root->right);
		if (blance > 0)
			root->right = right_rotate(root->right);
		return left_rotate(root);
	}
	return root;
}
id** find_avltree(avltree* root, wchar_t* value,unsigned long long* return_size,int type)//��avl��(ģ������)����һ�������Ǹ��ڵ㣬�ڶ���������Ҫ���ҵ�ֵ�������������Ƿ��صĴ�С,���ĸ������ǲ��ҿ�ͷ1�����Ӵ�2
{
	que *duilie=createQue();
	if(root==NULL)
		return NULL;
	insert_que(duilie,root);
	unsigned long long len=2;
	id**ans=(id**)malloc(sizeof(id*)*len);
	unsigned long long index=0;
	int len_value = (int)wcslen(value);
	while (duilie->size != 0)
	{
		queue* tmp = out_que(duilie);
		switch (type)
		{
		case 1:
			while (root != NULL)
			{
				if (wcscmp(root->key, value) == 0)
				{
					free(ans);
					ans = root->value;
					free(tmp);
					free_que(duilie);
					*return_size = root->size;
					return ans;
				}
				else if (wcscmp(value, root->key) < 0)
					root = root->left;
				else
					root = root->right;
			}
			break;
		case 2:
			if (wcsncmp(tmp->data->key, value, len_value) == 0)
			{
				if (len >= index + tmp->data->size)
				{
					ans = (id**)realloc(ans, sizeof(id*) * (unsigned long long)(len + tmp->data->size * 1.5));
					len = (unsigned long long)(len + tmp->data->size * 1.5);
				}
				for (unsigned long long i = 0; i < tmp->data->size; i++)
					if (tmp->data->is_del[i] == true && tmp->data->value[i]->is_del_full == true)
						ans[index++] = tmp->data->value[i];
			}
			break;
		case 3:
			if (wcsstr(tmp->data->key, value) != NULL)
			{
				if (len >= index + tmp->data->size)
				{
					ans = (id**)realloc(ans, sizeof(id*) * (unsigned long long)(len + tmp->data->size * 1.5));
					len = (unsigned long long)(len + tmp->data->size * 1.5);
				}
				for (unsigned long long i = 0; i < tmp->data->size; i++)
					if (tmp->data->is_del[i] == true && tmp->data->value[i]->is_del_full == true)
						ans[index++] = tmp->data->value[i];
			}
			break;
		}
		if(tmp->data->left!=NULL)
			insert_que(duilie, tmp->data->left);
		if(tmp->data->right!=NULL)
			insert_que(duilie, tmp->data->right);
		free(tmp);
	}
	free(value);
	*return_size=index;
	return ans;
}
void free_avl(avltree* root)//�ͷ�avl��
{
	if (root == NULL)
		return;
	free_avl(root->left);
	free_avl(root->right);
	free(root->key);
	free(root->value);
	free(root->is_del);
	free(root);
	root = NULL;
}
void datas_to_index(DATA*data,id**value,int type,int flag)//Ŀǰû���뵽��ô�Ż������ñ�������
{
	if (type == revow)
	{
		free_avl(data->wenjian.xingming);
		data->wenjian.xingming = NULL;
		free_avl(data->wenjian.dianhua);
		data->wenjian.dianhua = NULL;
		free_avl(data->wenjian.zhuzhi);
		data->wenjian.zhuzhi = NULL;
		chongjian_hash(data, 1, 0);
		chongjian_hash(data, 2, 0);
		chongjian_kuorong_view(&data->wenjian.delete_data, NULL, &data->wenjian.delete_max, &data->wenjian.delete_size, 2);//��ʼ��ɾ����
		chongjian_kuorong_view(&data->wenjian.view_data, NULL, &data->wenjian.view_max, &data->wenjian.view_size, 2);//��ʼ����ͼ��
	}
	if (value == NULL)
	{
		node* tmp = data->wenjian.head;
		while (tmp != NULL)
		{
			for(unsigned long long i=0;i<tmp->people->size;i++)
			{
				id* temp = &(tmp->people->peo[i]);
				if(tmp->people->peo[i].is_del_full == false)
				{
					if (data->wenjian.delete_size == data->wenjian.delete_max)
						chongjian_kuorong_view(&(data->wenjian.delete_data), NULL, &(data->wenjian.delete_max), &(data->wenjian.delete_size), 1);
					data->wenjian.delete_data[data->wenjian.delete_size++]=temp;
				}
				if(flag==1)
				{
					if (data->wenjian.view_size == data->wenjian.view_max)
						chongjian_kuorong_view(&(data->wenjian.view_data), NULL, &(data->wenjian.view_max), &(data->wenjian.view_size), 1);
					data->wenjian.view_data[data->wenjian.view_size++]=temp;
				}
				int xingbie_index = xingbei_to_num(tmp->people->peo[i].xingbei);
				int nianling_index = tmp->people->peo[i].age;
				if(data->wenjian.nianling[nianling_index].size == data->wenjian.nianling[nianling_index].max)
					chongjian_kuorong_view(&(data->wenjian.nianling[nianling_index].value), &(data->wenjian.nianling[nianling_index].is_del), &(data->wenjian.nianling[nianling_index].max), &(data->wenjian.nianling[nianling_index].size), 1);
				if(data->wenjian.xingbie[xingbie_index].size == data->wenjian.xingbie[xingbie_index].max)
					chongjian_kuorong_view(&(data->wenjian.xingbie[xingbie_index].value), &(data->wenjian.xingbie[xingbie_index].is_del), &(data->wenjian.xingbie[xingbie_index].max), &(data->wenjian.xingbie[xingbie_index].size), 1);
				data->wenjian.nianling[nianling_index].is_del[data->wenjian.nianling[nianling_index].size]=true;
				data->wenjian.xingbie[xingbie_index].is_del[data->wenjian.xingbie[xingbie_index].size]=true;
				data->wenjian.nianling[nianling_index].value[data->wenjian.nianling[nianling_index].size++]=temp;
				data->wenjian.xingbie[xingbie_index].value[data->wenjian.xingbie[xingbie_index].size++]=temp;
				wchar_t* mingzi = ctow(tmp->people->peo[i].name);
				wchar_t*tel = ctow(tmp->people->peo[i].tel);
				wchar_t*zhuzhi = ctow(tmp->people->peo[i].zhuzhi);
				data->wenjian.xingming= insert_avl(data->wenjian.xingming, mingzi, &temp);
				data->wenjian.dianhua = insert_avl(data->wenjian.dianhua, tel, &temp);
				data->wenjian.zhuzhi = insert_avl(data->wenjian.zhuzhi, zhuzhi, &temp);
			}
			tmp = tmp->xiayige;
		}
	}
	else
	{
		int xingbie_index = xingbei_to_num((*value)->xingbei);
		int nianling_index = (*value)->age;
		if (data->wenjian.nianling[nianling_index].size == data->wenjian.nianling[nianling_index].max)
			chongjian_kuorong_view(&(data->wenjian.nianling[nianling_index].value), &(data->wenjian.nianling[nianling_index].is_del), &(data->wenjian.nianling[nianling_index].max), &(data->wenjian.nianling[nianling_index].size), 1);
		if (data->wenjian.xingbie[xingbie_index].size == data->wenjian.xingbie[xingbie_index].max)
			chongjian_kuorong_view(&(data->wenjian.xingbie[xingbie_index].value), &(data->wenjian.xingbie[xingbie_index].is_del), &(data->wenjian.xingbie[xingbie_index].max), &(data->wenjian.xingbie[xingbie_index].size), 1);
		if ((*value)->is_del_full == false)
		{
			if (data->wenjian.delete_size == data->wenjian.delete_max)
				chongjian_kuorong_view(&(data->wenjian.delete_data), NULL, &(data->wenjian.delete_max), &(data->wenjian.delete_size), 1);
			data->wenjian.delete_data[data->wenjian.delete_size++] = *value;
		}
		if(flag==1)
		{
			if (data->wenjian.view_size == data->wenjian.view_max)
				chongjian_kuorong_view(&(data->wenjian.view_data), NULL, &(data->wenjian.view_max), &(data->wenjian.view_size), 1);
			data->wenjian.view_data[data->wenjian.view_size++] = *value;
		}
		data->wenjian.nianling[nianling_index].is_del[data->wenjian.nianling[nianling_index].size] = true;
		data->wenjian.xingbie[xingbie_index].is_del[data->wenjian.xingbie[xingbie_index].size] = true;
		data->wenjian.nianling[nianling_index].value[data->wenjian.nianling[nianling_index].size++] = *value;
		data->wenjian.xingbie[xingbie_index].value[data->wenjian.xingbie[xingbie_index].size++] = *value;
		wchar_t* mingzi = ctow((*value)->name);
		wchar_t* tel = ctow((*value)->tel);
		wchar_t* zhuzhi = ctow((*value)->zhuzhi);
		data->wenjian.xingming=insert_avl(data->wenjian.xingming, mingzi, value);
		data->wenjian.dianhua = insert_avl(data->wenjian.dianhua, tel, value);
		data->wenjian.zhuzhi = insert_avl(data->wenjian.zhuzhi, zhuzhi, value);
	}
}
void  del_to_index(DATA* data, id* value,id tmp_id)//ɾ�����ݵ�����
{
	int xingbie_index = xingbei_to_num(tmp_id.xingbei);
	int nianling_index = tmp_id.age;
	wchar_t* mingzi = ctow(tmp_id.name);
	wchar_t* tel = ctow(tmp_id.tel);
	wchar_t* zhuzhi = ctow(tmp_id.zhuzhi);
	for(unsigned long long i=0;i<data->wenjian.xingbie[xingbie_index].size;i++)
		if(data->wenjian.xingbie[xingbie_index].value[i]==value)
		{
			data->wenjian.xingbie[xingbie_index].is_del[i] = false;
			break;
		}
	for (unsigned long long i = 0; i < data->wenjian.nianling[nianling_index].size; i++)
		if (data->wenjian.nianling[nianling_index].value[i] == value)
		{
			data->wenjian.nianling[nianling_index].is_del[i] = false;
			break;
		}
	avltree* tmp = data->wenjian.xingming;
	while (tmp != NULL)
	{
		if (wcscmp(tmp->key, mingzi) == 0)
		{
			for (unsigned long long i = 0; i < tmp->size; i++)
				if (tmp->value[i] == value)
				{
					tmp->is_del[i] = false;
					break;
				}
			break;
		}
		else if (wcscmp(tmp->key, mingzi) > 0)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	tmp = data->wenjian.dianhua;
	while (tmp != NULL)
	{
		if (wcscmp(tmp->key, tel) == 0)
		{
			for (unsigned long long i = 0; i < tmp->size; i++)
				if (tmp->value[i] == value)
				{
					tmp->is_del[i] = false;
					break;
				}
			break;
		}
		else if (wcscmp(tmp->key, tel) > 0)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	tmp = data->wenjian.zhuzhi;
	while (tmp != NULL)
	{
		if (wcscmp(tmp->key, zhuzhi) == 0)
		{
			for (unsigned long long i = 0; i < tmp->size; i++)
				if (tmp->value[i] == value)
				{
					tmp->is_del[i] = false;
					break;
				}
			break;
		}
		else if (wcscmp(tmp->key, zhuzhi) > 0)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
}