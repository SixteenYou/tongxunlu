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
//重置通讯录
DATA* chongzhi(DATA**data)
{
	if ((*data)->peizhi.auto_baocun_thread != NULL)//对数据结构进行操作时，等待自动保存的线程结束
		yanzheng_auto_save(*data);
	char chose;
	if (yanzheng((*data)->wenjian.view_data, (*data)->wenjian.view_size,"重置", true)==0)
		return *data;
	printf("请问确定要重置吗？该操作非常危险，会将所有数据清除，请先备份后再重置\n");
	printf("是否重置？？（y/n）\n");
	while (1)
		if (scanf("%c", &chose) == 1)
		{
			while (getchar() != '\n');
			if (chose != 'y' && chose != 'Y')
			{
				printf("取消重置！！！\n");
				Sleep(2000);
				return *data;
			}
			else
				break;
		}
		else
		{
			while (getchar() != '\n');
			printf("输入有误，请重新输入\n");
		}
	node* tmp = (*data)->wenjian.head;
	free_head(*data);
	*data = chushihua_data();
	openfile_peizhi(*data);
	(*data)->peizhi.is_kuai_max=false;
	(*data)->peizhi.thread_num = 1;
	printf("重置成功！！\n");
	Sleep(2000);
	return *data;
}
static void xiewenjian(DATA*data, FILE* fp)//写文件
{
	for (unsigned int i = 0;i < data->wenjian.view_size;i++)
		fwrite(data->wenjian.view_data[i], sizeof(id), 1, fp);
}
typedef struct read_data
{
	unsigned int count;//当前线程需要处理的数量
	DATA* data;//数据结构
	id* tmp;//数据的开头,注意要在线程内释放内存
	node* head;//头节点
}read_data;
DWORD WINAPI read_data_thread(LPVOID lpParam)//读取数据线程
{
	read_data* data = (read_data*)lpParam;
	for (unsigned int i = 0; i < data->count; i++)
		data->head->people->peo[data->head->people->size++]=data->tmp[i];
	free(data->tmp);
	free(data);
	return 0;
}
static node* duwenjian(DATA*data, FILE* fp)//读文件
{
	unsigned long long total_tmp = 0;
	fread(&total_tmp, sizeof(unsigned long long), 1, fp);
	//动态调整kuai_max，并且只能改一次，假设这里不改，会在读取文件失败后会置为false，即不会再调整
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
	unsigned long long index = 0;//记录当前读到的位置
	HANDLE* thread_handles = (HANDLE*)malloc(data->peizhi.thread_num * sizeof(HANDLE));
	//用来建立索引
	node* start = data->wenjian.tail;//读取的开始节点
	node* end = NULL;//结束节点
	unsigned int start_index=data->wenjian.tail->people->size;//读取的开始节点的索引
	unsigned int end_index=0;//结束节点的索引
	while (index < total_tmp)
	{
		int i = 0;
		for(;i< data->peizhi.thread_num &&index<total_tmp;i++)
		{
			_fseeki64(fp, index * (long long)sizeof(id) + sizeof(unsigned long long), SEEK_SET);//调节指针位置，可能用不到，但是为了保险还是写上
			unsigned int  tmp_size = 0;
			if (data->wenjian.tail->people->size != 0 || total_tmp - index < data->peizhi.kuai_max)//不是新节点，需要计算当前节点还有多少空位,或者当前读取的节点不够一个节点的大小
			{
				tmp_size = data->peizhi.kuai_max - data->wenjian.tail->people->size;//当前块剩余空间
				if (tmp_size > (unsigned int)(total_tmp - index))//剩余数据的数量，取最小值
					tmp_size = (unsigned int)(total_tmp - index);
			}
			else
				tmp_size = data->peizhi.kuai_max;//空间充足且剩余数据足够一个节点的大小
			if (data->wenjian.tail->xiayige == NULL)//如果下一个节点不存在，就先提前添加一个节点	
				new_node(data);
			id* tmp = (id*)malloc(tmp_size * sizeof(id));//分配空间
			if (tmp == NULL)
				printf("%s\n", strerror(errno));
			if (fread(tmp, sizeof(id), tmp_size, fp) != tmp_size)
			{
				printf("读取文件失败，请检查文件是否损坏\n");
				exit(1);//强制退出，文件出问题了，不再继续运行
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
			if(tmp_num+tmp_size>=data->peizhi.kuai_max)//判断是否需要移动到下一个节点
				data->wenjian.tail=data->wenjian.tail->xiayige;//下一个节点
		}
		WaitForMultipleObjects(i, thread_handles, TRUE, INFINITE);//等待所有线程结束
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
		datas_to_index(data, &value, continund,1);//更新索引
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
//打开文件读取数据
node* openfile(DATA*data)
{
	FILE* fp = fopen("data.tn", "rb");
	if (fp == NULL)
	{
		data->peizhi.is_kuai_max = false;//假设没有数据或者没有文件，即打开失败，就不在调整kuai_max，重启软件后会调整
		data->peizhi.thread_num = 1;
		return data->wenjian.tail;
	}
	openfile_peizhi(data);
	data->wenjian.tail = duwenjian(data,fp);//读取数据
	data->peizhi.change_num=0;
	fclose(fp);
	printf("打开成功\n");
	Sleep(500);
	system("cls");
	return data->wenjian.tail;
}
void openfile_peizhi(DATA* data)
{
	FILE* peizhi_fp = fopen("peizhi.tn", "rb");
	if (peizhi_fp == NULL)
	{
		data->peizhi.is_kuai_max = false;//假设没有数据或者没有文件，即打开失败，就不在调整kuai_max，重启软件后会调整
		return ;
	}
	fread(&(data->peizhi.change_num), sizeof(data->peizhi.change_num), 1, peizhi_fp);
	fread(&(data->peizhi.is_auto_baocun), sizeof(data->peizhi.is_auto_baocun), 1, peizhi_fp);
	fread(&(data->peizhi.sheding_auto_baocun), sizeof(data->peizhi.sheding_auto_baocun), 1, peizhi_fp);
	fclose(peizhi_fp);
}
//保存数据到文件
void savefile(DATA*data)
{
	FILE* fp = fopen("data.tn", "wb");
	FILE* peizhi_fp = fopen("peizhi.tn", "wb");
	if (fp == NULL || peizhi_fp == NULL)
	{
		printf("打开文件失败，请检查使用手册\n");
		return;
	}
	fwrite(&(data->peizhi.change_num), sizeof(data->peizhi.change_num), 1, peizhi_fp);
	fwrite(&(data->peizhi.is_auto_baocun), sizeof(data->peizhi.is_auto_baocun), 1, peizhi_fp);
	fwrite(&(data->peizhi.sheding_auto_baocun), sizeof(data->peizhi.sheding_auto_baocun), 1, peizhi_fp);
	fclose(peizhi_fp);
	if (fp == NULL)
	{
		printf("打开文件失败，请检查使用手册\n");
		return;
	}
	printf("正在保存数据，请稍等...\n");
	fwrite(&(data->peizhi.total), sizeof( unsigned long long), 1, fp);
	xiewenjian(data, fp);
	fclose(fp);
}
//导出文件
void daochuwenjian(DATA*data)
{
	node* tmp_node = data->wenjian.head;
	printf("请问你要导出成什么格式的文件？\n");
	while (1)
	{
		printf("1.txt（直接可以用记事本打开可以）\n2.csv（可以导入到Excel中）\n3.tn（本软件专属格式，让另一台计算机本软件可以打开并使用）\n");
		char tmp = input_num_char(data);
		FILE* fp;
		printf("正在导出文件...\n");
		char filename[20];//文件名
		char geshi[3][10] = { {".txt"},{".csv"},{".tn"}};
		char leixing[2][2][50] = { {"姓名\\t电话\\t性别\\t住址\\t年龄\\n","%%s\\t%%s\\t%%s\\t%%s\\t%%hd\\n"},{ "姓名,电话,性别,住址,年龄\\n","%s,%s,%s,%s,%hd\\n"} };
		char biaoto[50];//根据选择的格式，设置表头
		char shuju[50];//根据选择的格式，设置数据格式
		char jieyu[100];//提示信息
		switch (tmp)
		{
			case '1':
				sprintf(filename, "通讯录%s", geshi[tmp-'1']);
				sprintf(biaoto, leixing[tmp-'1'][0]);
				sprintf(shuju, leixing[tmp-'1'][1]);
				sprintf(jieyu, "导出成功，文件名为通讯录.txt，文件路径在本软件下\\n");
				break;
			case '2':
				sprintf(filename, "通讯录%s", geshi[tmp-'1']);
				sprintf(biaoto, leixing[tmp-'1'][0]);
				sprintf(shuju, leixing[tmp-'1'][1]);
				sprintf(jieyu, "导出成功，文件名为通讯录.csv，文件路径在本软件下\\n");
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
				sprintf(jieyu, "导出成功，文件名为move.tn，文件路径在本软件下,请在别的计算机上使用吧！！\n");
				break;
			default:
				printf("输入有误，请重新输入\n");
				printf("请重新选择你要导出的文件？\n");
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
//导入数据
node* daoru(DATA*data)
{
	if (data->peizhi.auto_baocun_thread != NULL)//对数据结构进行操作时，等待自动保存的线程结束
		yanzheng_auto_save(data);
	FILE* fp = fopen("move.tn", "rb");
	if (fp == NULL)
	{
		printf("打开文件失败，请检查使用手册\n");
		Sleep(2000);
		return data->wenjian.tail;
	}
	printf("正在导入数据，请稍等...\n");
	data-> wenjian.tail= duwenjian(data,fp);//导入数据
	fclose(fp);
	printf("导入成功\n");
	Sleep(2000);			
	return data->wenjian.tail;
}