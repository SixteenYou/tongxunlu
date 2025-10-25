//联系人管理系统  
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
       case 预览://预览打印所有信息  
           yulan(data);  
           break;  
       case 操作数据://操作数据的二级菜单(添删改)  
           erji_caozuoshuju(data);  
           break;  
       case 查找://查找数据  
           chazhao(data);  
           break;  
       case 排序和筛选://排序和筛选的二级菜单  
           erji_tiaoxu(data);  
           break;  
       case 文件操作://导入和导出的二级菜单  
           data=erji_wenjiucaizuo(data);  
           break;  
       case 保存://保存  
           if (data->peizhi.auto_baocun_thread != NULL)
           {
               printf("后台自动保存正在运行！！\n");
               break;
           }
           savefile(data);  
           Sleep(1000);
           printf("保存成功！！\n");
           break;
       case 7://显示数据量(不暴漏接口，测试用)
           printf("%lld\n", data->peizhi.total);
           Sleep(2000);
           break;
       case 退出并保存://退出并保存   
           if (data->peizhi.auto_baocun_thread != NULL)
           {
               printf("后台保存正在运行！！\n");
               free_head(data);
               break;
           }
           savefile(data);
           Sleep(1000);
           printf("退出并保存成功！！\n");
           return 1;  
       case 退出不保存://退出不保存  
           free_head(data);  
		   printf("退出成功！！（不保存）\n");
           return 0;  
       default:  
           printf("输入错误，请重新输入\n");  
		   Sleep(500);
           break;  
       }  
   }  
   return 0;  
}