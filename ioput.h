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
//����ͨѶ¼
DATA* chongzhi(DATA**data);

//���ļ���ȡ����
node* openfile(DATA*data);

//�������ݵ��ļ�
void savefile(DATA*data);

//�����ļ�
void daochuwenjian(DATA*data);

//�����ļ�
node* daoru(DATA*data);

void openfile_peizhi(DATA* data);