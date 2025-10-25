#pragma once
#ifndef TONGYONG
#define TONGYONG
#include"tongyong.h"
#endif // !TONGYONG 
#ifndef PAIXUSHAIXUAN
#define PAIXUSHAIXUAN
#include"paixushaixuan.h"
#endif
#ifndef CAOZUO
#define CAOZUO
#include"caozuo.h"
#endif
//重置通讯录
DATA* chongzhi(DATA**data);

//打开文件读取数据
node* openfile(DATA*data);

//保存数据到文件
void savefile(DATA*data);

//导出文件
void daochuwenjian(DATA*data);

//导入文件
node* daoru(DATA*data);

void openfile_peizhi(DATA* data);