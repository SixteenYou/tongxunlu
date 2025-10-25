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
//添加信息
node*  tianjia(DATA*data)
{
	system("cls");
	if (data->wenjian.tail == NULL)//如果存储块为空
	{
		printf("该存储块中出现错误，请退出软件后重新打开\n");
		return data->wenjian.tail;
	}
	if (data->wenjian.tail->xiayige == NULL)//如果下一个节点不存在，就先提前添加一个节点
		new_node(data);
	if (data->wenjian.tail->people->size == data->peizhi.kuai_max)//当前节点满了
		data->wenjian.tail = data->wenjian.tail->xiayige;
	do {//输入姓名,并验证该姓名是否存在
		input(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].name, "姓名", name_max);
	} while (yanzheng_xingming(data, data->wenjian.tail->people->peo[data->wenjian.tail->people->size].name));
	do {//输入性别，并验证该性别是否符合要求
		input(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].xingbei, "性别（男，女，保密）", xingbei_max);
	} while (yanzheng_xingbei(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].xingbei));
	do {//输入年龄，并验证该年龄是否符合要求
		printf("请输入%s的年龄（0-150）\n", data->wenjian.tail->people->peo[data->wenjian.tail->people->size].name);
		if (scanf("%hd", &(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].age)) == 1)
		{
			while (getchar() != '\n');
			if (data->wenjian.tail->people->peo[data->wenjian.tail->people->size].age < 0 || data->wenjian.tail->people->peo[data->wenjian.tail->people->size].age > 150)
				printf("年龄不符合要求，请重新输入\n");
			else
				break;
		}
		else
		{
			while (getchar() != '\n');
			printf("输入有误，请重新输入\n");
		}
	} while (1);
	do {//输入电话，并验证该电话是否符合要求
		input(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].tel, "电话", tel_max);
	} while (yanzheng_dianhua(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].tel));
	do {//输入地址，并验证该地址是否存在（这里的存在不是地图上的存在，主要是为了防止用户啥也不输入）
		input(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].zhuzhi, "地址", zhuzhi_max);
	} while (strlen(data->wenjian.tail->people->peo[data->wenjian.tail->people->size].zhuzhi) == 0);
	data->wenjian.tail->people->peo[data->wenjian.tail->people->size].is_del_full=true;
	id* value = &data->wenjian.tail->people->peo[data->wenjian.tail->people->size++];
	datas_to_index(data, &value,continund,1);
	data->peizhi.total++;//总人数加1
	data->peizhi.change_num++;//修改次数加1
	printf("添加成功\n");
	Sleep(1000);
	return data->wenjian.tail;
}
//验证性别数据是否符合要求
int yanzheng_xingbei(char* xingbei)
{
	if (strcmp(xingbei, "男") != 0 && strcmp(xingbei, "女") != 0 && strcmp(xingbei, "保密"))
	{
		printf("你输入的性别不符合要求，请重新输入\n");
		return 1;
	}
	return 0;
}
//验证姓名是否存在，最终用平衡二叉树来验证，线性太慢，所有都用平衡二叉树来验证
int yanzheng_xingming(DATA*data, char* name)
{
	avltree* xingming_tree=data->wenjian.xingming;
	unsigned long long index = 0;
	find_avltree(xingming_tree, ctow(name), &index, 1);
	if (index!=0)
	{
		printf("你输入的姓名已存在，请重新输入\n");
		return 1;
	}
	return 0;
}
//验证电话是否符合要求
int yanzheng_dianhua(char* tel)
{
	int len=(int)strlen(tel);
	if (len < 7)
	{
		printf("你输入的电话长度不符合要求，请重新输入\n");
		return 1;
	}
	for (int i=0;i < len - 1;i++)
	{
		if (tel[i] < '0' || tel[i] > '9')
		{
			printf("你输入的电话不符合要求，请重新输入\n");
			Sleep(2000);
			return 1;
		}
	}
	return 0;
}

bool xiugai(char* s1, char* s2, char* s3)
{
	char chose;
	printf("请问你要修改%s吗？(y/n)\n", s3);
	while (1)
		if (scanf("%c", &chose) == 1)
		{
			while (getchar() != '\n');
			if (chose == 'y' || chose == 'Y')
			{
				input(s2, s3, zhuzhi_max);
				strcpy(s1, s2);
				printf("修改后，在通讯录中的%s:%s，如果与输入的不符合，请记录当前名字，之后重新修改，谢谢！！\n", s3, s1);
				printf("多次修改无果，请联系管理员或者反馈一下\n");
				return true;
			}
			else if (chose == 'n' || chose == 'N')
			{
				printf("取消修改%s\n", s3);
				break;
			}
			else
				printf("输入有误，请重新输入\n");
		}
		else
		{
			while (getchar() != '\n');
			printf("请输入正确的数据\n");
		}
	return false;
}
bool xiugai_nianling(short *age,char*name)
{
	char chose;
	printf("请问你要修改%s的年龄吗？(y/n)\n", name);
	while (1)
		if (scanf("%c", &chose) == 1)
		{
			while (getchar() != '\n');
			if (chose == 'y' || chose == 'Y')
			{
				printf("请输入%s的年龄（0-150）\n", name);
				if (scanf("%hd", age) == 1)
				{
					while (getchar() != '\n');
					if (*age < 0 || *age > 150)
					{
						printf("年龄不符合要求，请重新输入\n");
						Sleep(2000);
					}
					else
					{
						printf("修改后，在通讯录中的%s:%hd，如果与输入的不符合，请记录当前名字，之后重新修改，谢谢！！\n","年龄", *age);
						printf("多次修改无果，请联系管理员或者反馈一下\n");
						return true;
					}
				}
				else
				{
					while (getchar() != '\n');
					printf("输入有误，请重新输入\n");
				}
			}
			else if (chose == 'n' || chose == 'N')
			{
				printf("取消修改年龄\n");
				break;
			}
			else
				printf("输入有误，请重新输入\n");
		}
		else
		{
			while (getchar() != '\n');
			printf("请输入正确的数据\n");
		}
	return false;
}
//修改数据
void xuigai(DATA*data)
{
	system("cls");
	if (yanzheng(data->wenjian.view_data,data ->wenjian.view_size,"修改",true) == (unsigned long long)0)//没有数据，就没法修改
		return;
	char tmp_name[name_max];
	char tmp_tel[tel_max];
	char tmp_xingbei[xingbei_max];
	char tmp_zhuzhi[zhuzhi_max];
	id tmp_id;
	dayinshuju(data);//先显示一下所有信息，在看看需要修改的哪个
	printf("请输入你要找的姓名\n");
	while (1)
	{
	if (scanf("%s", tmp_name) == 1)
		{
			node* tmp = data->wenjian.head;
			while (getchar() != '\n');
			while (tmp != NULL)//遍历所有数据寻找
			{
				for (unsigned long long i=0;i < data->wenjian.view_size;i++)
					if (strcmp(tmp_name, data->wenjian.view_data[i]->name) == 0)
					{
						char name[name_max];
						bool flag=false;
						tmp_id = *(data->wenjian.view_data[i]);
						while (1)
						{
							if(flag|=xiugai(name, tmp_name, "名字"))
								if (!yanzheng_xingming(data, name))
								{
									strcpy(data->wenjian.view_data[i]->name, name);
									break;
								}
								else
								{
									printf("修改失败，请重新修改\n");
									Sleep(2000);
								}
							else
								break;
						}
						do {
							if (!(flag |= xiugai(data->wenjian.view_data[i]->tel, tmp_tel, "电话")))
								break;
						}while(yanzheng_dianhua(data->wenjian.view_data[i]->tel));
						do {
							if(!(flag |= xiugai(data->wenjian.view_data[i]->xingbei, tmp_xingbei, "性别")))
								break;
						} while (yanzheng_xingbei(data->wenjian.view_data[i]->xingbei));
						xiugai_nianling(&(data->wenjian.view_data[i]->age), data->wenjian.view_data[i]->name);
						do {
							if(!(flag |= xiugai(data->wenjian.view_data[i]->zhuzhi, tmp_zhuzhi, "地址")))
								break;
						} while (strlen(data->wenjian.view_data[i]->zhuzhi) == 0);
						if (flag)
						{
							del_to_index(data, data->wenjian.view_data[i],tmp_id);
							datas_to_index(data, &data->wenjian.view_data[i],1,0);
						}
						Sleep(1500);
						printf("修改成功\n");
						data->peizhi.change_num++;
						return;
					}
			}
			printf("不好意思，没有找到你所寻找的姓名\n");
			Sleep(2000);
			break;
		}
		else
		{
			while (getchar() != '\n');
			printf("请输入正确的名字\n");
		}
	}
}
//删除数据
void shanchu(DATA*data)
{
	system("cls");
	unsigned long long i;
	for(i=0;i<data->wenjian.view_size;i++)
		if(data->wenjian.view_data[i]->is_del_full==true)
			break;
	if (i == data->wenjian.view_size)
	{
		printf("没有需要删除的数据\n");
		Sleep(1000);
		return;
	}
	char tmp[name_max];
	dayinshuju(data);//先显示一下所有信息，在看看需要删除的哪个
	while (1)
	{
		printf("请输入你要删除的姓名\n");
		if (scanf(" %s", tmp))
		{
			while (getchar() != '\n');
			for (i>0?i-1:0;i < data->wenjian.view_size;i++)
				if (data->wenjian.view_data[i]->is_del_full == true && strcmp(tmp, data->wenjian.view_data[i]->name) == 0)
				{
					printf("你要删除的姓名是%s，电话是%s\n", data->wenjian.view_data[i]->name, data->wenjian.view_data[i]->tel);
					printf("请确认是否删除？(y/n)\n");
					char chose;
					while (1)
						if (scanf("%c", &chose) == 1)
						{
							while (getchar() != '\n');
							if (chose == 'y' || chose == 'Y')
							{
								if (data->wenjian.delete_size == data->wenjian.delete_max)
									chongjian_kuorong_view(&(data->wenjian.delete_data), NULL, &(data->wenjian.delete_max), &(data->wenjian.delete_size), 1);
								data->wenjian.view_data[i]->is_del_full = false;//false表示已经删除
								data->wenjian.delete_data[data->wenjian.delete_size] = data->wenjian.view_data[i];
								data->wenjian.delete_size++;
								data->peizhi.change_num++;
								printf("已成功移入回收站，请注意查看\n");
								Sleep(1000);
								return;
							}
							else if (chose == 'n' || chose == 'N')
							{
								printf("取消删除\n");
								Sleep(1000);
								return;
							}
						}
						else
						{
							while (getchar() != '\n');
							printf("输入有误，请重新输入\n");
						}
				}
			printf("没有找到你所输入的姓名，请重新输入\n");
			Sleep(1000);
		}
		else
		{
			while (getchar() != '\n');
			printf("请输入正确的名字\n");
		}
	}
}