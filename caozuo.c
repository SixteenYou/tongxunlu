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
//�����Ϣ
node*  tianjia(DATA*data)
{
	system("cls");
	if (data->wenjian.tail == NULL)//����洢��Ϊ��
	{
		printf("�ô洢���г��ִ������˳���������´�\n");
		return data->wenjian.tail;
	}
	if (data->wenjian.tail->xiayige == NULL)//�����һ���ڵ㲻���ڣ�������ǰ���һ���ڵ�
		new_node(data);
	if (data->wenjian.tail->people->size == data->peizhi.kuai_max)//��ǰ�ڵ�����
		data->wenjian.tail = data->wenjian.tail->xiayige;
	do {//��������,����֤�������Ƿ����
		input(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].name, "����", name_max);
	} while (yanzheng_xingming(data, data->wenjian.tail->people->peo[data->wenjian.tail->people->size].name));
	do {//�����Ա𣬲���֤���Ա��Ƿ����Ҫ��
		input(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].xingbei, "�Ա��У�Ů�����ܣ�", xingbei_max);
	} while (yanzheng_xingbei(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].xingbei));
	do {//�������䣬����֤�������Ƿ����Ҫ��
		printf("������%s�����䣨0-150��\n", data->wenjian.tail->people->peo[data->wenjian.tail->people->size].name);
		if (scanf("%hd", &(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].age)) == 1)
		{
			while (getchar() != '\n');
			if (data->wenjian.tail->people->peo[data->wenjian.tail->people->size].age < 0 || data->wenjian.tail->people->peo[data->wenjian.tail->people->size].age > 150)
				printf("���䲻����Ҫ������������\n");
			else
				break;
		}
		else
		{
			while (getchar() != '\n');
			printf("������������������\n");
		}
	} while (1);
	do {//����绰������֤�õ绰�Ƿ����Ҫ��
		input(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].tel, "�绰", tel_max);
	} while (yanzheng_dianhua(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].tel));
	do {//�����ַ������֤�õ�ַ�Ƿ���ڣ�����Ĵ��ڲ��ǵ�ͼ�ϵĴ��ڣ���Ҫ��Ϊ�˷�ֹ�û�ɶҲ�����룩
		input(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].zhuzhi, "��ַ", zhuzhi_max);
	} while (strlen(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].zhuzhi) == 0);
	data->wenjian.tail->people->peo[data->wenjian.tail->people->size].is_del_full=true;
	id* value = &data->wenjian.tail->people->peo[data->wenjian.tail->people->size++];
	datas_to_index(data, &value,continund,1);
	data->peizhi.total++;//��������1
	data->peizhi.change_num++;//�޸Ĵ�����1
	printf("��ӳɹ�\n");
	Sleep(1000);
	return data->wenjian.tail;
}
//��֤�Ա������Ƿ����Ҫ��
int yanzheng_xingbei(char* xingbei)
{
	if (strcmp(xingbei, "��") != 0 && strcmp(xingbei, "Ů") != 0 && strcmp(xingbei, "����"))
	{
		printf("��������Ա𲻷���Ҫ������������\n");
		return 1;
	}
	return 0;
}
//��֤�����Ƿ���ڣ�������ƽ�����������֤������̫�������ж���ƽ�����������֤
int yanzheng_xingming(DATA*data, char* name)
{
	avltree* xingming_tree=data->wenjian.xingming;
	unsigned long long index = 0;
	find_avltree(xingming_tree, ctow(name), &index, 1);
	if (index!=0)
	{
		printf("������������Ѵ��ڣ�����������\n");
		return 1;
	}
	return 0;
}
//��֤�绰�Ƿ����Ҫ��
int yanzheng_dianhua(char* tel)
{
	int len=(int)strlen(tel);
	if (len < 7)
	{
		printf("������ĵ绰���Ȳ�����Ҫ������������\n");
		return 1;
	}
	for (int i=0;i < len - 1;i++)
	{
		if (tel[i] < '0' || tel[i] > '9')
		{
			printf("������ĵ绰������Ҫ������������\n");
			Sleep(2000);
			return 1;
		}
	}
	return 0;
}

bool xiugai(char* s1, char* s2, char* s3)
{
	char chose;
	printf("������Ҫ�޸�%s��(y/n)\n", s3);
	while (1)
		if (scanf("%c", &chose) == 1)
		{
			while (getchar() != '\n');
			if (chose == 'y' || chose == 'Y')
			{
				input(s2, s3, zhuzhi_max);
				strcpy(s1, s2);
				printf("�޸ĺ���ͨѶ¼�е�%s:%s�����������Ĳ����ϣ����¼��ǰ���֣�֮�������޸ģ�лл����\n", s3, s1);
				printf("����޸��޹�������ϵ����Ա���߷���һ��\n");
				return true;
			}
			else if (chose == 'n' || chose == 'N')
			{
				printf("ȡ���޸�%s\n", s3);
				break;
			}
			else
				printf("������������������\n");
		}
		else
		{
			while (getchar() != '\n');
			printf("��������ȷ������\n");
		}
	return false;
}
bool xiugai_nianling(short *age,char*name)
{
	char chose;
	printf("������Ҫ�޸�%s��������(y/n)\n", name);
	while (1)
		if (scanf("%c", &chose) == 1)
		{
			while (getchar() != '\n');
			if (chose == 'y' || chose == 'Y')
			{
				printf("������%s�����䣨0-150��\n", name);
				if (scanf("%hd", age) == 1)
				{
					while (getchar() != '\n');
					if (*age < 0 || *age > 150)
					{
						printf("���䲻����Ҫ������������\n");
						Sleep(2000);
					}
					else
					{
						printf("�޸ĺ���ͨѶ¼�е�%s:%hd�����������Ĳ����ϣ����¼��ǰ���֣�֮�������޸ģ�лл����\n","����", *age);
						printf("����޸��޹�������ϵ����Ա���߷���һ��\n");
						return true;
					}
				}
				else
				{
					while (getchar() != '\n');
					printf("������������������\n");
				}
			}
			else if (chose == 'n' || chose == 'N')
			{
				printf("ȡ���޸�����\n");
				break;
			}
			else
				printf("������������������\n");
		}
		else
		{
			while (getchar() != '\n');
			printf("��������ȷ������\n");
		}
	return false;
}
//�޸�����
void xuigai(DATA*data)
{
	system("cls");
	if (yanzheng(data->wenjian.view_data,data ->wenjian.view_size,"�޸�",true) == (unsigned long long)0)//û�����ݣ���û���޸�
		return;
	char tmp_name[name_max];
	char tmp_tel[tel_max];
	char tmp_xingbei[xingbei_max];
	char tmp_zhuzhi[zhuzhi_max];
	id tmp_id;
	dayinshuju(data);//����ʾһ��������Ϣ���ڿ�����Ҫ�޸ĵ��ĸ�
	printf("��������Ҫ�ҵ�����\n");
	while (1)
	{
	if (scanf("%s", tmp_name) == 1)
		{
			node* tmp = data->wenjian.head;
			while (getchar() != '\n');
			while (tmp != NULL)//������������Ѱ��
			{
				for (unsigned long long i=0;i < data->wenjian.view_size;i++)
					if (strcmp(tmp_name, data->wenjian.view_data[i]->name) == 0)
					{
						char name[name_max];
						bool flag=false;
						tmp_id = *(data->wenjian.view_data[i]);
						while (1)
						{
							if(flag|=xiugai(name, tmp_name, "����"))
								if (!yanzheng_xingming(data, name))
								{
									strcpy(data->wenjian.view_data[i]->name, name);
									break;
								}
								else
								{
									printf("�޸�ʧ�ܣ��������޸�\n");
									Sleep(2000);
								}
							else
								break;
						}
						do {
							if (!(flag |= xiugai(data->wenjian.view_data[i]->tel, tmp_tel, "�绰")))
								break;
						}while(yanzheng_dianhua(data->wenjian.view_data[i]->tel));
						do {
							if(!(flag |= xiugai(data->wenjian.view_data[i]->xingbei, tmp_xingbei, "�Ա�")))
								break;
						} while (yanzheng_xingbei(data->wenjian.view_data[i]->xingbei));
						xiugai_nianling(&(data->wenjian.view_data[i]->age), data->wenjian.view_data[i]->name);
						do {
							if(!(flag |= xiugai(data->wenjian.view_data[i]->zhuzhi, tmp_zhuzhi, "��ַ")))
								break;
						} while (strlen(data->wenjian.view_data[i]->zhuzhi) == 0);
						if (flag)
						{
							del_to_index(data, data->wenjian.view_data[i],tmp_id);
							datas_to_index(data, &data->wenjian.view_data[i],1,0);
						}
						Sleep(1500);
						printf("�޸ĳɹ�\n");
						data->peizhi.change_num++;
						return;
					}
			}
			printf("������˼��û���ҵ�����Ѱ�ҵ�����\n");
			Sleep(2000);
			break;
		}
		else
		{
			while (getchar() != '\n');
			printf("��������ȷ������\n");
		}
	}
}
//ɾ������
void shanchu(DATA*data)
{
	system("cls");
	unsigned long long i;
	for(i=0;i<data->wenjian.view_size;i++)
		if(data->wenjian.view_data[i]->is_del_full==true)
			break;
	if (i == data->wenjian.view_size)
	{
		printf("û����Ҫɾ��������\n");
		Sleep(1000);
		return;
	}
	char tmp[name_max];
	dayinshuju(data);//����ʾһ��������Ϣ���ڿ�����Ҫɾ�����ĸ�
	while (1)
	{
		printf("��������Ҫɾ��������\n");
		if (scanf(" %s", tmp))
		{
			while (getchar() != '\n');
			for (i>0?i-1:0;i < data->wenjian.view_size;i++)
				if (data->wenjian.view_data[i]->is_del_full == true && strcmp(tmp, data->wenjian.view_data[i]->name) == 0)
				{
					printf("��Ҫɾ����������%s���绰��%s\n", data->wenjian.view_data[i]->name, data->wenjian.view_data[i]->tel);
					printf("��ȷ���Ƿ�ɾ����(y/n)\n");
					char chose;
					while (1)
						if (scanf("%c", &chose) == 1)
						{
							while (getchar() != '\n');
							if (chose == 'y' || chose == 'Y')
							{
								if (data->wenjian.delete_size == data->wenjian.delete_max)
									chongjian_kuorong_view(&(data->wenjian.delete_data), NULL, &(data->wenjian.delete_max), &(data->wenjian.delete_size), 1);
								data->wenjian.view_data[i]->is_del_full = false;//false��ʾ�Ѿ�ɾ��
								data->wenjian.delete_data[data->wenjian.delete_size] = data->wenjian.view_data[i];
								data->wenjian.delete_size++;
								data->peizhi.change_num++;
								printf("�ѳɹ��������վ����ע��鿴\n");
								Sleep(1000);
								return;
							}
							else if (chose == 'n' || chose == 'N')
							{
								printf("ȡ��ɾ��\n");
								Sleep(1000);
								return;
							}
						}
						else
						{
							while (getchar() != '\n');
							printf("������������������\n");
						}
				}
			printf("û���ҵ��������������������������\n");
			Sleep(1000);
		}
		else
		{
			while (getchar() != '\n');
			printf("��������ȷ������\n");
		}
	}
}