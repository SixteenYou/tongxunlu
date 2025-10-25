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
//菜单
void menuone()//一级菜单
{
	printf("--------------------\n");
	printf("|      1.预览      |\n");
	printf("|    2.操作数据    |\n");
	printf("|      3.查找      |\n");
	printf("|   4.排序和筛选   |\n");
	printf("|    5.文件操作    |\n");
	printf("|      6.保存      |\n");
	printf("|   9.退出不保存   |\n");
	printf("|   0.退出并保存   |\n");
	printf("--------------------\n");
}
void menutow_caizuoshuju()//操作数据的二级菜单
{
	printf("--------------------\n");
	printf("|      1.添加      |\n");
	printf("|      2.修改      |\n");
	printf("|      3.删除      |\n");
	printf("|     4.回收站     |\n");
	printf("|      0.返回      |\n");
	printf("--------------------\n");
}
void menutow_tiaoxu()//排序和筛选的二级菜单
{
	printf("--------------------\n");
	printf("|      1.排序      |\n");
	printf("|      2.筛选      |\n");
	printf("|      0.返回      |\n");
	printf("--------------------\n");
}
void menu_wenjiancaizuo()//导入和导出的二级菜单
{
	printf("--------------------\n");
	printf("|      1.导入      |\n");
	printf("|      2.导出      |\n");
	printf("|      3.重置      |\n");
	printf("|    4.自动保存    |\n");
	printf("|  5.设定保存数量  |\n");
	printf("|      0.返回      |\n");
	printf("--------------------\n");
}

void menu_chazhao()//查找的类型
{
	printf("--------------------\n");
	printf("|      1.姓名      |\n");
	printf("|      2.电话      |\n");
	printf("|      3.年龄      |\n");
	printf("|      4.性别      |\n");
	printf("|      0.返回      |\n");
	printf("--------------------\n");
}
void menu_chaozhao_mingzi()//查找姓名的类型
{
	printf("-------------------\n");
	printf("|    1.名字全部   |\n");
	printf("|      2.开头     |\n");
	printf("|    3.包含的字   |\n");
	printf("|      0.返回     |\n");
	printf("-------------------\n");
}
void menu_chaozhao_dianhua()//查找电话的类型
{
	printf("--------------------\n");
	printf("|    1.电话全部    |\n");
	printf("|      2.开头      |\n");
	printf("|  3.包含的电话段  |\n");
	printf("|      0.返回      |\n");
	printf("--------------------\n");
}
void menu_chaozhao_nianling()//查找年龄的类型
{
	printf("----------------------\n");
	printf("|     1.年龄范围     |\n");
	printf("| 2.大于等于某个年龄 |\n");
	printf("| 3.小于等于某个年龄 |\n");
	printf("|   4.等于某个年龄   |\n");
	printf("|       0.返回       |\n");
	printf("----------------------\n");
}
void menu_chaozhao_xingbie()//查找性别的类型
{
	printf("------------------\n");
	printf("|      1.男      |\n");
	printf("|      2.女      |\n");
	printf("|     3.保密     |\n");
	printf("|     0.返回     |\n");
	printf("------------------\n");
}
void erji_caozuoshuju(DATA* data)//操作数据的二级菜单
{
	if (data->peizhi.auto_baocun_thread != NULL)//对数据结构进行操作时，等待自动保存的线程结束
		yanzheng_auto_save(data);
	int tmp = 0;//tmp用于判断是否继续添加
	while (1)
	{
		system("cls");
		menutow_caizuoshuju();
		char chose = input_num_char(data);
		switch (chose - '0')
		{
		case 添加:
			do{
				data->wenjian.tail=tianjia(data);
				tmp = 0;
				printf("请问是否继续添加？(y/n)\n");
				char tmp_char = input_num_char(data);
				if (tmp_char == 'y' || tmp == 'Y')
					tmp = 1;
			} while (tmp);
			return;
		case 修改:
			do {
				xuigai(data);
				tmp = 0;
				printf("请问是否继续修改？(y/n)\n");
				char tmp_char = input_num_char(data);
				if (tmp_char == 'y' || tmp == 'Y')
					tmp = 1;
			} while (tmp);
			return;
		case 删除:
			do {
				shanchu(data);
				tmp = 0;
				printf("请问是否继续删除？(y/n)\n");
				char tmp_char = input_num_char(data);
				if (tmp_char == 'y' || tmp == 'Y')
					tmp = 1;
			} while (tmp);
			return;
		case 回收站:
			huishouzhan(data);
			return;
		case 返回:
			return;
		default:
			printf("输入错误，请重新输入\n");
			Sleep(2000);
			break;
		}
	}
}
void erji_tiaoxu(DATA* data)//排序和筛选的二级菜单
{
	while (1)
	{
		system("cls");
		menutow_tiaoxu();
		char chose = input_num_char(data);
		switch (chose - '0')
		{
		case 排序:
			sort(data);
			return;
		case 筛选:
			shaixuan(data);
			return;
		case 返回:
			return;
		default:
			printf("输入错误，请重新输入\n");
			Sleep(2000);
			break;
		}
	}
}
void save_change(DATA*data)//自动保存功能
{
	system("cls");
	if (data->peizhi.is_auto_baocun)
	{
		printf("自动保存功能已开启,请问你要关闭自动保存功能吗？(y/n)(开启自动保存后，在软件运行过程中，软件会自动保存数据，无需手动保存)\n");
		char tmp_char;
		if(scanf("%c", &tmp_char))
		{
			while (getchar() != '\n');
			if (tmp_char == 'y' || tmp_char == 'Y')
			{
				data->peizhi.is_auto_baocun = false;
				printf("自动保存功能已关闭，请注意数据安全\n");
				Sleep(1000);
			}
		}
		else
		{
			while (getchar() != '\n');
			printf("输入错误，请稍后重新设置\n");
			Sleep(2000);
		}
	}
	else
	{
		printf("自动保存功能已关闭,请问你要开启自动保存功能吗？(y/n)(开启自动保存后，在软件运行过程中，软件会自动保存数据，无需手动保存)\n");
		char tmp_char;
		if (scanf("%c", &tmp_char))
		{
			while (getchar() != '\n');
			if (tmp_char == 'y' || tmp_char == 'Y')
			{
				data->peizhi.is_auto_baocun = true;
				printf("自动保存功能已开启\n");
				Sleep(1000);
			}
		}
		else
		{
			while (getchar() != '\n');
			printf("输入错误，请稍后重新设置\n");
			Sleep(2000);
		}
	}
}
void set_save_num(DATA*data)//设定保存数量
{
	system("cls");
	if (data->peizhi.is_auto_baocun)
	{
		printf("当前每操作%d条数据，软件自动保存一次\n", data->peizhi.sheding_auto_baocun);
		printf("自动保存功能已开启,请问你要修改自动保存的数量吗？(输入数字10-100)(不建议太大或者太小，太大可能没法及时保存，太小可能保存的文件频繁)\n");
		printf("请输入新的自动保存数量：");
		int tmp_num;
		if (scanf("%d", &tmp_num))
		{
			while (getchar() != '\n');
			if(tmp_num >= 10 && tmp_num <= 100)
			{
				data->peizhi.sheding_auto_baocun = (unsigned int)tmp_num;
				printf("自动保存的数量已设置为%u\n",data->peizhi.sheding_auto_baocun);
				Sleep(1000);
			}
			else
			{
				printf("输入数量不符合要求，请稍后重新设置\n");
				Sleep(2000);
			}
		}
		else
		{
			while (getchar() != '\n');
			printf("输入错误，请稍后重新设置\n");
			Sleep(2000);	
		}
	}
	else
	{
		printf("自动保存功能已关闭,要先开启自动保存功能才能设置保存数量\n");
		Sleep(2000);
	}
}
DATA* erji_wenjiucaizuo(DATA* data)//导入和导出的二级菜单
{
	while (1)
	{
		system("cls");
		menu_wenjiancaizuo();
		char chose = input_num_char(data);
		switch (chose - '0')
		{
		case 导入:
			data->wenjian.tail=daoru(data);
			return data;
		case 导出:
			daochuwenjian(data);
			return data;
		case 重置:
			data=chongzhi(&data);
			return data;
		case 自动保存:
			save_change(data);
			return data;
		case 设定保存数量:
			set_save_num(data);
			return data;
		case 返回:
			return data;
		default:
			printf("输入错误，请重新输入\n");
			Sleep(2000);
			break;
		}
	}
}
void new_node(DATA*data)//添加节点
{
	node* tmp = (node*)calloc(1,sizeof(node));//分配一个新的节点
	if (tmp == NULL)
	{
		printf("%s\n", strerror(errno));
		printf("内存分配失败，请检查使用手册\n");
		return;
	}
	tmp->people = (xinxi*)calloc(1,sizeof(xinxi) + (data->peizhi.kuai_max) * sizeof(id));//分配一个新的块
	if (tmp->people == NULL)
	{
		printf("%s\n", strerror(errno));
		printf("内存分配失败，请检查使用手册\n");
		return;
	}
	tmp->people->size = 0;
	tmp->xiayige = NULL;
	tmp->start = &(tmp->people->peo[0]);
	tmp->end = &(tmp->people->peo[data->peizhi.kuai_max - 1]);
	data->wenjian.link_len++;
	data->wenjian.tail->xiayige = tmp;//将当前节点的下一个节点指向新节点
}
//释放内存	
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
//非阻塞型输入
char input_num_char(DATA*data)
{
	char tmp;
	printf("按ESC键退出软件(不保存)\n");
	while (1)
	{
		if (_kbhit())
		{
			tmp = _getch();
			if (tmp == 27)
			{
				printf("退出软件\n");
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
void yanzheng_auto_save(DATA* data)//验证是否正在自动保存
{
	printf("正在自动保存中，请稍后\n");
	WaitForSingleObject(data->peizhi.auto_baocun_thread, INFINITE);
	CloseHandle(data->peizhi.auto_baocun_thread);
	data->peizhi.auto_baocun_thread = NULL;
	printf("自动保存完成\n");
}
//验证是否有数据
unsigned long long yanzheng(id**value,unsigned  long long max,char* s1,bool type)
{
	for(unsigned long long i=0; i< max;i++)
		if((*value)[i].is_del_full==type)
			return i+1;
	printf("还没有数据需要%s，请先添加数据\n",s1);
	Sleep(1000);
	return 0;
}
void dayinshuju(DATA* data)
{
	long long count = 0;
	unsigned long long i = 0;
	printf("-----------------------------\n");
	printf("| %10s | %12s |\n", "姓名", "电话");
	printf("-----------------------------\n");
	for(;i<data->wenjian.view_size;i++)
		if(data->wenjian.view_data[i]->is_del_full)
		{
			printf("| %10s | %12s |\n", data->wenjian.view_data[i]->name, data->wenjian.view_data[i]->tel);
			count++;
		}
	printf("-----------------------------\n");
	printf("|以上共有%11lld位联系人|\n", count);
	printf("-----------------------------\n");
}
//预览打印所有信息

void yulan(DATA*data)
{
	system("cls");
	unsigned long long i= yanzheng(data->wenjian.view_data,data->wenjian.view_size, "预览", true);
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
		printf("注意:此时数据量为%lld，数量有点大，如果光用控制台输入可能会出问题，此时建议使用非微软控制台\n", data->peizhi.total);
		Sleep(3000);
		return;
	}
	anxia_continue();
}
static void print_flag(bool* flag_found)//打印标题
{
	if (*flag_found)
	{
		system("cls");
		printf(fenge);
		printf("| %10s | %5s | %5s | %12s | %50s |\n", "姓名", "年龄 ", "性别", "电话", "住址");
		printf(fenge);
		*flag_found = false;
	}
}
void dayinxiangxixinxi(id* tmp,bool*found)//打印详细信息
{
	print_flag(found);
	printf("| %10s | %5hd | %5s | %12s | %50s |\n", tmp->name,tmp->age, tmp->xingbei, tmp->tel, tmp->zhuzhi);
}
void nothing(long long found, char* s1)
{
	if (found > 0)
		printf(fenge"以上共%lld个联系人\n", found);
	else
		printf("%s\n", s1);
}
wchar_t* ctow(const char* str)//转换为宽字符进行比较
{
	size_t len = strlen(str) + 1;
	size_t i = 0;
	wchar_t* wstr = (wchar_t*)malloc(len * sizeof(wchar_t));
	mbstowcs_s(&i, wstr, len, str, _TRUNCATE );
	return wstr;
}
//查找数据，第一个参数是整个数据结构，第二个是查找类型1为姓名，2为电话，3为住址，第三个是查的是全部1，开头2，还是子串3。
void chazhao_avl(DATA*data,int type,int is_full)
{
	char biaotou[100];
	char jiewei[100];
	char shuju1[3][20] = {{"姓名"},{"电话"},{"住址"}};
	char shuju2[3][20] = { {"全部"},{"开头"},{"包含段"}};
	char tmp[100];
	sprintf(biaotou, "你要查找%s的%s", shuju1[type-1], shuju2[is_full-1]);
	sprintf(jiewei, "不好意思，没有找到你想要%s的%s", shuju1[type - 1], shuju2[is_full-1]);
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
		while (getchar() != '\n');//清空输入缓冲区
	return 0;
}
//查找哈希表，falg为1时表示找年龄，为0时表示找性别
void chazhao_nianling_xingbie(hash* hash_table,int type,int flag)
{
	long long found = 0;
	bool flag_found = true;
	char biaotou[100];
	char jiewei[100];
	char* a[3] = { "男","女","保密" };
	short left = nianling_min, right = nianling_max;
	if(flag == 1)
	{
		short t_left, t_right;
		sprintf(jiewei, "请输入正确的数字，注意：年龄范围是%d - %d\n", nianling_min, nianling_max);
		sprintf(biaotou, "请输入你要%%s的年龄（规定的年龄的范围是%d-%d）\n", nianling_min, nianling_max);
		switch (type)
		{
		case 1:
			while (1)
			{
				printf("请输入年龄的范围(规定的年龄的范围是%d-%d)(数字之间用空格隔开)(先输小的，再输大的)\n", nianling_min, nianling_max);
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
			sprintf(jiewei, "不好意思,没有找到年龄在%hd-%hd的人", left, right);
			break;
		case 2:
			while (1)
			{
				printf(biaotou, "大于多少");
				if (input_nianling(&t_left) == 1)
				{
					left = t_left;
					break;
				}
				else
					printf(jiewei);
			}
			sprintf(jiewei, "不好意思,没有找到年龄大于%hd的人", left);
			break;
		case 3:
			while (1)
			{
				printf(biaotou, "小于多少");
				if (input_nianling(&t_right) == 1)
				{
					right = t_right;
					break;
				}
				else
					printf(jiewei);
			}
			sprintf(jiewei, "不好意思,没有找到年龄小于%hd的人", right);
			break;
		case 4:
			while (1)
			{
				printf(biaotou, "找");
				if (input_nianling(&t_left) == 1)
				{
					left = t_left;
					right = t_left;
					break;
				}
				else
					printf(jiewei);
			}
			sprintf(jiewei, "不好意思,没有找到年龄为%hd的人", left);
			break;
		}
	}
	else
	{
		sprintf(jiewei, "不好意思,没有找到性别为%s的人", a[type-1]);
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
//查找数据
void chazhao(DATA*data)
{
	system("cls");
	if (yanzheng(data->wenjian.view_data, data->wenjian.view_size, "查找", true) == (unsigned long long)0)
		return;
	menu_chazhao();
	int type = input_num_char(data);//用于判断查找的类型
	typedef void(*func)(node*head);
	system("cls");
	switch (type - '0')
	{
	case 姓名:
		menu_chaozhao_mingzi();
		type = input_num_char(data);//用于判断查找姓名的类型
		if (type == 返回 + '0')
			return;
		chazhao_avl(data, 1, type - '0');
		return;
	case 电话:
		menu_chaozhao_dianhua();
		type = input_num_char(data);//用于判断查找电话的类型
		if (type == 返回 + '0')
			return;
		chazhao_avl(data, 2, type - '0');
		return;
	case 年龄:
		menu_chaozhao_nianling();
		type = input_num_char(data);//用于判断查找年龄的类型
		if (type == 返回 + '0')
			return;
		chazhao_nianling_xingbie(data->wenjian.nianling, type - '0',1);
		return;
	case 性别:
		menu_chaozhao_xingbie();
		type = input_num_char(data);//用于判断查找性别的类型
		if (type == 返回 + '0')
			return;
		chazhao_nianling_xingbie(data->wenjian.xingbie,type - '0',0);
		return;
	case 返回:
		return;
	default:
		printf("输入错误，请重新输入\n");
		Sleep(2000);
		break;
	}
}
//输入字符串并验证大小
void input(char* s1, char* s2, int a)
{
	char wight[10];
	sprintf(wight, " %%%ds", zhuzhi_max);
	while (1)
	{
		char tmp[zhuzhi_max + 5];
		printf("请输入%s\n", s2);
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
				printf("输入的%s过长，请重新输入\n", s2);
				continue;
			}
		}
		while (getchar() != '\n');
		printf("请输入正确的%s\n", s2);
	}
}
void anxia_continue()//按空格继续
{
	printf("按空格继续......\n");
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
	DATA* data = (DATA*)calloc(1, sizeof(DATA));//存储所有数据
	if (data == NULL)
		printf("%s\n", strerror(errno));
	data->peizhi.is_auto_baocun = true;//默认开启后台自动保存
	data->peizhi.sheding_auto_baocun = jizhunshuju;//后台自动保存时间为32次修改
	data->peizhi.kuai_max = jizhunshuju;//初始默认下，一个块最大数据量为基本底层的数值，在第一次读取文件时，会根据当前读取的数据量的大小来调整块的大小，只能调整一次，后续不会再调整
	data->peizhi.is_kuai_max = true;//默认可以修改最大数据量，修改后，则直接停止修改，直到下次启动程序
	data->peizhi.total = 0;//总数据量
	data->peizhi.change_num = 0;//修改次数
	data->peizhi.thread_num = 8;//线程数
	data->wenjian.head = (node*)calloc(1, sizeof(node));//头节点
	if (data->wenjian.head == NULL)
		printf("%s\n", strerror(errno));
	data->wenjian.head->xiayige = NULL;//头节点的下一个节点
	data->wenjian.head->people = (xinxi*)calloc(1, sizeof(xinxi) + data->peizhi.kuai_max * sizeof(id));//头节点的第一个块
	if (data->wenjian.head->people == NULL)
		printf("%s\n", strerror(errno));
	data->wenjian.head->people->size = 0;//当前块的大小兼顾坐标
	data->wenjian.head->start = &(data->wenjian.head->people->peo[0]);
	data->wenjian.head->end = &(data->wenjian.head->people->peo[data->peizhi.kuai_max-1]);
	data->wenjian.tail = data->wenjian.head;//尾节点
	data->peizhi.auto_baocun_thread = NULL;
	data->wenjian.xingming=NULL;
	data->wenjian.zhuzhi=NULL;
	data->wenjian.dianhua=NULL;
	data->wenjian.link_len = 1;
	data->wenjian.xingbie = (hash*)calloc(xingbie_max + 1, sizeof(hash));
	data->wenjian.nianling = (hash*)calloc(nianling_max + 1, sizeof(hash));
	chongjian_kuorong_view(&data->wenjian.delete_data, NULL, &data->wenjian.delete_max, &data->wenjian.delete_size, 2);//初始化删除域
	chongjian_kuorong_view(&data->wenjian.view_data, NULL, &data->wenjian.view_max, &data->wenjian.view_size, 2);//初始化视图域
	chongjian_hash(data, 1, revow);//初始化年龄哈希表
	chongjian_hash(data, 2, revow);//初始化性别哈希表
	return data;
}
int xingbei_to_num(char* s)//性别字符串转数字
{
	if (strcmp(s, "男") == 0)
		return 男;
	else if (strcmp(s, "女") == 0)
		return 女;
	else if (strcmp(s, "保密") == 0)
		return 保密;
	else
		return -1;
}
static int cmp(const void* a, const void* b)
{
	id* p2 = *((id**)a);
	id* p1 = *((id**)b);
	return (p1 < p2) ? -1 : (p1 > p2) ? 1 : 0;
}
void huishouzhan(DATA* data)//回收站
{
	system("cls");
	unsigned long long i = yanzheng(data->wenjian.delete_data, data->wenjian.delete_size, "回收站", false);
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
	nothing(count, "回收站为空");
	while (1)
	{
		printf("请输入你要选择的操作：\n1.恢复\n2.清空回收站（彻底删除）\n0.返回\n");
		int type = input_num_char(data);
		switch (type - '0')
		{
		case 1:
			printf("请输入你要恢复的第几个联系人（0则恢复所有）：\n");
			while (1)
				if (scanf(" %llu", &count) == 1)
				{
					while (getchar() != '\n');//清空输入缓冲区
					if (count == 0)
					{
						for (int i = 0; i < data->wenjian.delete_size; i++)
							data->wenjian.delete_data[i]->is_del_full = true;
						chongjian_kuorong_view(&data->wenjian.delete_data, NULL, &data->wenjian.delete_max, &data->wenjian.delete_size, 2);
						printf("恢复成功\n");
						Sleep(2000);
						return;
					}
					else
					{
						if (count-- > data->wenjian.delete_size)
						{
							printf("没有这条数据，请稍后重试\n");
							return;
						}
						for (int i = 0; i < data->wenjian.delete_size; i++)
						{
							if (data->wenjian.delete_data[i]->is_del_full == false && count != 0)
								count--;
							else if (data->wenjian.delete_data[i]->is_del_full == false && count == 0)
							{
								printf("恢复成功\n");
								data->wenjian.delete_data[i]->is_del_full = true;
								Sleep(2000);
								return;
							}
						}
						if (count != 0)
						{
							printf("没有这条数据，请稍后重试\n");
							Sleep(2000);
							return;
						}
					}
				}
				else
				{
					while (getchar() != '\n');
					printf("请输入正确的数字\n");
				}
			break;
		case 2:
			while (1)
			{
				printf("你确定要清空回收站吗,清空后将无法恢复，是否继续？(Y/N)\n");
				char tmp = input_num_char(data);
				if (tmp == 'Y' || tmp == 'y')
				{
					printf("正在清空回收站，请稍后\n");
					qsort(data->wenjian.delete_data, data->wenjian.delete_size, sizeof(id*), cmp);
					for (unsigned long long i = 0; i < data->wenjian.delete_size; i++)//遍历回收站
					{
						node* tmp = data->wenjian.head;
						while (tmp != NULL)//遍历链表
						{
							if (data->wenjian.delete_data[i] >= tmp->start && data->wenjian.delete_data[i] <= tmp->end)
							{
								for (unsigned int j = (unsigned int)((data->wenjian.delete_data[i] - tmp->start)); j < tmp->people->size; j++)//开始清除数据
									tmp->people->peo[j] = tmp->people->peo[j + 1];//前移数据
								tmp->people->size--;//修改大小
								data->peizhi.total--;//修改总数据量
								break;
							}
							tmp = tmp->xiayige;
						}
					}
					//各种键的重建操做
					datas_to_index(data, NULL, revow,1);
					printf("清空回收站成功\n");
					Sleep(2000);
					return;
				}
				else
				{
					printf("取消清空回收站\n");
					Sleep(2000);
					return;
				}
			}
		case 返回:
			return;
		default:
			printf("输入错误，请重新输入\n");
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
	if(is_del!=NULL)//如果没有删除域，就不用重新分配空间了
	{
		new_is_del = (bool*)realloc(*is_del, sizeof(bool) * *max);
		if (new_is_del == NULL)
			printf("%s\n", strerror(errno));
		*is_del = new_is_del;
	}
}
que* createQue()//创建队列
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
avltree* left_rotate(avltree* root)//左旋转
{
	avltree* new_root = root->right;
	root->right = new_root->left;
	new_root->left = root;
	root->height = updata_height(root);
	new_root->height = updata_height(new_root);
	return new_root;
}
avltree* right_rotate(avltree* root)//右旋转
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
id** find_avltree(avltree* root, wchar_t* value,unsigned long long* return_size,int type)//查avl树(模糊查找)，第一个参数是根节点，第二个参数是要查找的值，第三个参数是返回的大小,第四个参数是查找开头1还是子串2
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
void free_avl(avltree* root)//释放avl树
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
void datas_to_index(DATA*data,id**value,int type,int flag)//目前没有想到怎么优化，先用暴力法吧
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
		chongjian_kuorong_view(&data->wenjian.delete_data, NULL, &data->wenjian.delete_max, &data->wenjian.delete_size, 2);//初始化删除域
		chongjian_kuorong_view(&data->wenjian.view_data, NULL, &data->wenjian.view_max, &data->wenjian.view_size, 2);//初始化视图域
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
void  del_to_index(DATA* data, id* value,id tmp_id)//删除数据的索引
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