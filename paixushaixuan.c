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
//比较函数，用于qsort排序
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
//排序
void sort(DATA*data)
{
	if (data->peizhi.auto_baocun_thread != NULL)//对数据结构进行操作时，等待自动保存的线程结束
		yanzheng_auto_save(data);
	system("cls");
	if (data->peizhi.total == 0)//如果没有数据就不需要排序
	{
		printf("还没有数据需要排序，请先添加数据\n");
		Sleep(2000);
		return;
	}
	typedef int (*func)(const void* s1, const void* s2);//比较函数类型
	func cmp[3][2] = { {cmp_name_sheng,cmp_name_jiang}, {cmp_nianling_sheng,cmp_nianling_jiang}, {cmp_dianhua_sheng,cmp_dianhua_jiang} };//比较函数数组
	char a[3][20] = { "正在按照姓名排序","正在按照年龄排序","正在按照电话排序" };
	while(1)
	{
		printf("请问你要按照什么排序？（1姓名2年龄3电话）（注意：已经开始排序，请不要恶意停止软件，否则后果自负）\n");
		int chose = input_num_char(data);
		if (chose >= '0' && chose <= '3')
		{
			printf("%s\n", a[chose - '1']);
			printf("请问你要正序还是倒序？（1升序2倒序）\n");
			int shunxu = input_num_char(data);
			if (shunxu >= '0' && shunxu <= '2')
			{
				qsort(data->wenjian.view_data, data->wenjian.view_size, sizeof(id*), cmp[chose - '1'][shunxu - '1']);//排序
				break;
			}
			else
				printf("输入错误，请重新输入\n");
		}
		else
			printf("输入错误，请重新输入\n");
	}
	printf("排序成功\n");
	if(data->peizhi.is_auto_baocun)
		data->peizhi.change_num += ((unsigned long long)data->peizhi.sheding_auto_baocun > data->peizhi.total ? (unsigned int)data->peizhi.total : data->peizhi.sheding_auto_baocun);
	Sleep(2000);
}
extern void chazhao_nianling_xingbie(hash* hash_table, int type, int flag);
extern void menu_chaozhao_xingbie();//查找性别的类型
extern void menu_chaozhao_dianhua();//查找电话的类型
extern void chazhao_avl(DATA* data, int type, int is_full);
//筛选
void shaixuan(DATA *data)
{
	system("cls");
	if (yanzheng(data->wenjian.view_data,data->wenjian.view_size,"筛选",true) == 0)//如果没有数据就不需要筛选
		return;
	node* tmp = data->wenjian.head;
	printf("请问你要筛选什么？（1性别2电话3住址）\n");
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
			printf("输入错误，请重新输入\n");
	}
}