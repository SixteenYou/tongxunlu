//��ϵ�˹���ϵͳ  
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
int main()  
{  
   setlocale(LC_ALL, "");
   DATA* data = chushihua_data();
   data->wenjian.tail=openfile(data); 
   while (1)  
   {  
       system("cls");  
       menuone();  
       int chose = input_num_char(data);  
       switch (chose - '0')  
       {  
       case Ԥ��://Ԥ����ӡ������Ϣ  
           yulan(data);  
           break;  
       case ��������://�������ݵĶ����˵�(��ɾ��)  
           erji_caozuoshuju(data);  
           break;  
       case ����://��������  
           chazhao(data);  
           break;  
       case �����ɸѡ://�����ɸѡ�Ķ����˵�  
           erji_tiaoxu(data);  
           break;  
       case �ļ�����://����͵����Ķ����˵�  
           data=erji_wenjiucaizuo(data);  
           break;  
       case ����://����  
           if (data->peizhi.auto_baocun_thread != NULL)
           {
               printf("��̨�Զ������������У���\n");
               break;
           }
           savefile(data);  
           Sleep(1000);
           printf("����ɹ�����\n");
           break;
       case 7://��ʾ������(����©�ӿڣ�������)
           printf("%lld\n", data->peizhi.total);
           Sleep(2000);
           break;
       case �˳�������://�˳�������   
           if (data->peizhi.auto_baocun_thread != NULL)
           {
               printf("��̨�����������У���\n");
               free_head(data);
               break;
           }
           savefile(data);
           Sleep(1000);
           printf("�˳�������ɹ�����\n");
           return 1;  
       case �˳�������://�˳�������  
           free_head(data);  
		   printf("�˳��ɹ������������棩\n");
           return 0;  
       default:  
           printf("�����������������\n");  
		   Sleep(500);
           break;  
       }  
   }  
   return 0;  
}