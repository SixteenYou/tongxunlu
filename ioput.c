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
//����ͨѶ¼
DATA* chongzhi(DATA**data)
{
	if ((*data)->peizhi.auto_baocun_thread != NULL)//�����ݽṹ���в���ʱ���ȴ��Զ�������߳̽���
		yanzheng_auto_save(*data);
	char chose;
	if (yanzheng((*data)->wenjian.view_data, (*data)->wenjian.view_size,"����", true)==0)
		return *data;
	printf("����ȷ��Ҫ�����𣿸ò����ǳ�Σ�գ��Ὣ����������������ȱ��ݺ�������\n");
	printf("�Ƿ����ã�����y/n��\n");
	while (1)
		if (scanf("%c", &chose) == 1)
		{
			while (getchar() != '\n');
			if (chose != 'y' && chose != 'Y')
			{
				printf("ȡ�����ã�����\n");
				Sleep(2000);
				return *data;
			}
			else
				break;
		}
		else
		{
			while (getchar() != '\n');
			printf("������������������\n");
		}
	node* tmp = (*data)->wenjian.head;
	free_head(*data);
	*data = chushihua_data();
	openfile_peizhi(*data);
	(*data)->peizhi.is_kuai_max=false;
	(*data)->peizhi.thread_num = 1;
	printf("���óɹ�����\n");
	Sleep(2000);
	return *data;
}
static void xiewenjian(DATA*data, FILE* fp)//д�ļ�
{
	for (unsigned int i = 0;i < data->wenjian.view_size;i++)
		fwrite(data->wenjian.view_data[i], sizeof(id), 1, fp);
}
typedef struct read_data
{
	unsigned int count;//��ǰ�߳���Ҫ���������
	DATA* data;//���ݽṹ
	id* tmp;//���ݵĿ�ͷ,ע��Ҫ���߳����ͷ��ڴ�
	node* head;//ͷ�ڵ�
}read_data;
DWORD WINAPI read_data_thread(LPVOID lpParam)//��ȡ�����߳�
{
	read_data* data = (read_data*)lpParam;
	for (unsigned int i = 0; i < data->count; i++)
		data->head->people->peo[data->head->people->size++]=data->tmp[i];
	free(data->tmp);
	free(data);
	return 0;
}
static node* duwenjian(DATA*data, FILE* fp)//���ļ�
{
	unsigned long long total_tmp = 0;
	fread(&total_tmp, sizeof(unsigned long long), 1, fp);
	//��̬����kuai_max������ֻ�ܸ�һ�Σ��������ﲻ�ģ����ڶ�ȡ�ļ�ʧ�ܺ����Ϊfalse���������ٵ���
	if (data->peizhi.is_kuai_max)
	{
		int count = 32;
		for (int i = 5;i > 0;i--)
		{
			if ((count << (5*i)) < total_tmp)
			{
				data->peizhi.kuai_max = (count << (5 * i));
				break;
			}
			if(data->peizhi.thread_num>1)
				data->peizhi.thread_num >>=1;
		}
		data->wenjian.tail->people = (xinxi*)realloc(data->wenjian.tail->people, sizeof(xinxi) + (data->peizhi.kuai_max) * sizeof(id));
		data->wenjian.tail->start = &(data->wenjian.tail->people->peo[0]);
		data->wenjian.tail->end = &(data->wenjian.tail->people->peo[data->peizhi.kuai_max - 1]);
		if (data->wenjian.tail->people == NULL)
			printf("%s\n", strerror(errno));
		data->peizhi.is_kuai_max = false;
	}
	unsigned long long index = 0;//��¼��ǰ������λ��
	HANDLE* thread_handles = (HANDLE*)malloc(data->peizhi.thread_num * sizeof(HANDLE));
	//������������
	node* start = data->wenjian.tail;//��ȡ�Ŀ�ʼ�ڵ�
	node* end = NULL;//�����ڵ�
	unsigned int start_index=data->wenjian.tail->people->size;//��ȡ�Ŀ�ʼ�ڵ������
	unsigned int end_index=0;//�����ڵ������
	while (index < total_tmp)
	{
		int i = 0;
		for(;i< data->peizhi.thread_num &&index<total_tmp;i++)
		{
			_fseeki64(fp, index * (long long)sizeof(id) + sizeof(unsigned long long), SEEK_SET);//����ָ��λ�ã������ò���������Ϊ�˱��ջ���д��
			unsigned int  tmp_size = 0;
			if (data->wenjian.tail->people->size != 0 || total_tmp - index < data->peizhi.kuai_max)//�����½ڵ㣬��Ҫ���㵱ǰ�ڵ㻹�ж��ٿ�λ,���ߵ�ǰ��ȡ�Ľڵ㲻��һ���ڵ�Ĵ�С
			{
				tmp_size = data->peizhi.kuai_max - data->wenjian.tail->people->size;//��ǰ��ʣ��ռ�
				if (tmp_size > (unsigned int)(total_tmp - index))//ʣ�����ݵ�������ȡ��Сֵ
					tmp_size = (unsigned int)(total_tmp - index);
			}
			else
				tmp_size = data->peizhi.kuai_max;//�ռ������ʣ�������㹻һ���ڵ�Ĵ�С
			if (data->wenjian.tail->xiayige == NULL)//�����һ���ڵ㲻���ڣ�������ǰ���һ���ڵ�	
				new_node(data);
			id* tmp = (id*)malloc(tmp_size * sizeof(id));//����ռ�
			if (tmp == NULL)
				printf("%s\n", strerror(errno));
			if (fread(tmp, sizeof(id), tmp_size, fp) != tmp_size)
			{
				printf("��ȡ�ļ�ʧ�ܣ������ļ��Ƿ���\n");
				exit(1);//ǿ���˳����ļ��������ˣ����ټ�������
			}
			read_data* rd = (read_data*)malloc(sizeof(read_data));
			if (rd == NULL)
			{
				printf("%s\n", strerror(errno));
				exit(1);
			}
			rd->count = tmp_size;
			rd->tmp = tmp;
			rd->head = data->wenjian.tail;
			unsigned int tmp_num = data->wenjian.tail->people->size;
			thread_handles[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)read_data_thread, rd, 0, NULL);
			index += tmp_size;
			if(tmp_num+tmp_size>=data->peizhi.kuai_max)//�ж��Ƿ���Ҫ�ƶ�����һ���ڵ�
				data->wenjian.tail=data->wenjian.tail->xiayige;//��һ���ڵ�
		}
		WaitForMultipleObjects(i, thread_handles, TRUE, INFINITE);//�ȴ������߳̽���
	}
	end = data->wenjian.tail;
	end_index = data->wenjian.tail->people->size-1;
	for (int j = 0; j < data->peizhi.thread_num; j++)
	{
		if(thread_handles[j]!=NULL)
			CloseHandle(thread_handles[j]);
		thread_handles[j] = NULL;
	}
	free(thread_handles);
	while ((&(start->people->peo[start_index])) - 1 != &(end->people->peo[end_index]))
	{
		id*value = &(start->people->peo[start_index]);
		datas_to_index(data, &value, continund,1);//��������
		start_index=(start_index+1)%data->peizhi.kuai_max;
		if(start_index==0)
			start=start->xiayige;
		if (start->people->size == 0)
			break;
	}
	data->peizhi.total+=total_tmp;
	data->peizhi.change_num += (total_tmp > data->peizhi.sheding_auto_baocun ? data->peizhi.sheding_auto_baocun : (unsigned int)(total_tmp % (unsigned long long)data->peizhi.sheding_auto_baocun));
	return data->wenjian.tail;
}
//���ļ���ȡ����
node* openfile(DATA*data)
{
	FILE* fp = fopen("data.tn", "rb");
	if (fp == NULL)
	{
		data->peizhi.is_kuai_max = false;//����û�����ݻ���û���ļ�������ʧ�ܣ��Ͳ��ڵ���kuai_max���������������
		data->peizhi.thread_num = 1;
		return data->wenjian.tail;
	}
	openfile_peizhi(data);
	data->wenjian.tail = duwenjian(data,fp);//��ȡ����
	data->peizhi.change_num=0;
	fclose(fp);
	printf("�򿪳ɹ�\n");
	Sleep(500);
	system("cls");
	return data->wenjian.tail;
}
void openfile_peizhi(DATA* data)
{
	FILE* peizhi_fp = fopen("peizhi.tn", "rb");
	if (peizhi_fp == NULL)
	{
		data->peizhi.is_kuai_max = false;//����û�����ݻ���û���ļ�������ʧ�ܣ��Ͳ��ڵ���kuai_max���������������
		return ;
	}
	fread(&(data->peizhi.change_num), sizeof(data->peizhi.change_num), 1, peizhi_fp);
	fread(&(data->peizhi.is_auto_baocun), sizeof(data->peizhi.is_auto_baocun), 1, peizhi_fp);
	fread(&(data->peizhi.sheding_auto_baocun), sizeof(data->peizhi.sheding_auto_baocun), 1, peizhi_fp);
	fclose(peizhi_fp);
}
//�������ݵ��ļ�
void savefile(DATA*data)
{
	FILE* fp = fopen("data.tn", "wb");
	FILE* peizhi_fp = fopen("peizhi.tn", "wb");
	if (fp == NULL || peizhi_fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�����ʹ���ֲ�\n");
		return;
	}
	fwrite(&(data->peizhi.change_num), sizeof(data->peizhi.change_num), 1, peizhi_fp);
	fwrite(&(data->peizhi.is_auto_baocun), sizeof(data->peizhi.is_auto_baocun), 1, peizhi_fp);
	fwrite(&(data->peizhi.sheding_auto_baocun), sizeof(data->peizhi.sheding_auto_baocun), 1, peizhi_fp);
	fclose(peizhi_fp);
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�����ʹ���ֲ�\n");
		return;
	}
	printf("���ڱ������ݣ����Ե�...\n");
	fwrite(&(data->peizhi.total), sizeof( unsigned long long), 1, fp);
	xiewenjian(data, fp);
	fclose(fp);
}
//�����ļ�
void daochuwenjian(DATA*data)
{
	node* tmp_node = data->wenjian.head;
	printf("������Ҫ������ʲô��ʽ���ļ���\n");
	while (1)
	{
		printf("1.txt��ֱ�ӿ����ü��±��򿪿��ԣ�\n2.csv�����Ե��뵽Excel�У�\n3.tn�������ר����ʽ������һ̨�������������Դ򿪲�ʹ�ã�\n");
		char tmp = input_num_char(data);
		FILE* fp;
		printf("���ڵ����ļ�...\n");
		char filename[20];//�ļ���
		char geshi[3][10] = { {".txt"},{".csv"},{".tn"}};
		char leixing[2][2][50] = { {"����\\t�绰\\t�Ա�\\tסַ\\t����\\n","%%s\\t%%s\\t%%s\\t%%s\\t%%hd\\n"},{ "����,�绰,�Ա�,סַ,����\\n","%s,%s,%s,%s,%hd\\n"} };
		char biaoto[50];//����ѡ��ĸ�ʽ�����ñ�ͷ
		char shuju[50];//����ѡ��ĸ�ʽ���������ݸ�ʽ
		char jieyu[100];//��ʾ��Ϣ
		switch (tmp)
		{
			case '1':
				sprintf(filename, "ͨѶ¼%s", geshi[tmp-'1']);
				sprintf(biaoto, leixing[tmp-'1'][0]);
				sprintf(shuju, leixing[tmp-'1'][1]);
				sprintf(jieyu, "�����ɹ����ļ���ΪͨѶ¼.txt���ļ�·���ڱ������\\n");
				break;
			case '2':
				sprintf(filename, "ͨѶ¼%s", geshi[tmp-'1']);
				sprintf(biaoto, leixing[tmp-'1'][0]);
				sprintf(shuju, leixing[tmp-'1'][1]);
				sprintf(jieyu, "�����ɹ����ļ���ΪͨѶ¼.csv���ļ�·���ڱ������\\n");
				break;
			case '3':
				sprintf(filename, "move%s", geshi[tmp-'1']);
				fp = fopen(filename, "w");
				if (fp == NULL)
				{
					printf("%s\n", strerror(errno));
					return;
				}
				fwrite(&(data->wenjian.view_size), sizeof(unsigned long long), 1, fp);
				xiewenjian(data, fp);
				fclose(fp);
				sprintf(jieyu, "�����ɹ����ļ���Ϊmove.tn���ļ�·���ڱ������,���ڱ�ļ������ʹ�ðɣ���\n");
				break;
			default:
				printf("������������������\n");
				printf("������ѡ����Ҫ�������ļ���\n");
				continue;
		}
		if (tmp != '3')
		{
			fp = fopen(filename, "w");
			if (fp == NULL)
			{
				printf("%s\n", strerror(errno));
				return;
			}
			fprintf(fp, biaoto);
			for (unsigned long long i = 0; i < data->wenjian.view_size; i++)
				fprintf(fp, shuju,data->wenjian.view_data[i]->name,
								  data->wenjian.view_data[i]->tel,
								  data->wenjian.view_data[i]->xingbei,
						          data->wenjian.view_data[i]->zhuzhi,
								  data->wenjian.view_data[i]->age);
			fclose(fp);
		}
		printf(jieyu);
		Sleep(2000);
		return;
	}
}
//��������
node* daoru(DATA*data)
{
	if (data->peizhi.auto_baocun_thread != NULL)//�����ݽṹ���в���ʱ���ȴ��Զ�������߳̽���
		yanzheng_auto_save(data);
	FILE* fp = fopen("move.tn", "rb");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�����ʹ���ֲ�\n");
		Sleep(2000);
		return data->wenjian.tail;
	}
	printf("���ڵ������ݣ����Ե�...\n");
	data-> wenjian.tail= duwenjian(data,fp);//��������
	fclose(fp);
	printf("����ɹ�\n");
	Sleep(2000);			
	return data->wenjian.tail;
}