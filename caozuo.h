#pragma once
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

//添加信息
node* tianjia(DATA*data);

//修改数据
void xuigai(DATA*data);

//删除数据
void shanchu(DATA*data);

//验证姓名是否存在
int yanzheng_xingming(DATA* data, char* name);

//验证电话是否符合要求
int yanzheng_dianhua(char* 
);

//验证性别数据是否符合要求
int yanzheng_xingbei(char* xingbei);

