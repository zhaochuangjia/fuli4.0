#include<stdio.h>

#include<math.h>

double principal=0,mount=0;

int year=0;

int n=1;

double rate;

 void meu()
 {
printf("|----------------------------------------|\n");

printf("|          1.复利计算                    |\n");

printf("|          2.单利计算                    |\n");

printf("|          3.计算本金                    |\n");

printf("|          4.年限计算                    |\n");

printf("|          5.利率估算                    |\n");

printf("|          6.等额定投                    |\n");

printf("|          7.等额还款                    |\n");

printf("|----------------------------------------|\n");
 } 

void danli(){

    printf("请输入的本金：");

    scanf("%lf",&principal);

    printf("请输入年限：");

    scanf("%d",&year);
    printf("请输入年利率：");

    scanf("%lf",&rate);

    mount=principal+principal*rate*year;

    printf("本息为：%.2lf\n",mount); 

}

 

void fuli(){

 

    printf("请输入本金：");

    scanf("%lf",&principal);

    printf("请输入年限：");

    scanf("%d",&year);

    printf("请输入年利率：");

    scanf("%lf",&rate);

    printf("请输入年复利次数:");

    scanf("%d",&n);

    rate=pow((1+rate/n),n)-1;

    mount=principal*pow((1+rate),year);

    printf("本息为：%.2lf\n",mount);

 

}

 

void principaljisuan(){

    printf("请输入期望的收益：");

    scanf("%lf",&mount);  

    printf("请输入年限：");

    scanf("%d",&year);

    printf("请输入年利率：");

    scanf("%lf",&rate);

    printf("请输入年复利次数:");

    scanf("%d",&n);

    rate=pow((1+rate/n),n)-1;

    principal=mount/pow((1+rate),year);

    printf("输出所需本金为：%.2lf\n",principal);

 

}

 
void time()
{
    int flat=0;
    
    printf("请输入本利和:"); 
    scanf("%lf",&mount); 
    printf("请输入年回报率:"); 
    scanf("%lf",&rate); 
    printf("请输入本金:"); 
    scanf("%lf",&principal); 
    for(n=1;n<100;n++)    //穷举法求100年满足的计息期数
    {
        if((principal*(pow((1+rate),n)))>=mount)
        {
            printf("计息期数:%d\n\n",n);
            flat=1;
            break;
        }
    }
    if(flat==0)
        printf("在100年内没有符合计息期数!\n\n");
    
}

void lilv()
{
    
    printf("请输入本利和:"); 
    scanf("%lf",&mount); 
    printf("请输入复利次数（年）:"); 
    scanf("%d",&year); 
    printf("请输入本金:"); 
    scanf("%lf",&principal); 
    rate=pow(mount/principal, 1.0/year)-1;
    printf("年利率为:%lf",rate);
}
void yearmount()//计算年金终值
 {
  int n;
     printf("存入本金:");
     scanf("%lf",&principal);
    printf("存入年限:");
    scanf("%d",&year);
     printf("年利率:");
     scanf("%lf",&rate);
     printf("\t\t1:按年投资\n\t\t2:按月投资\n");
 A:printf("请选择你要的功能<1|2>:");
   scanf("%d",&n);
   if(n==1)
   {
       mount=principal*(pow(1+rate,year)-1)/rate;
      
   }
   else if(n==2)
   {
       mount=principal*12*(1+rate)*(pow(1+rate,year)-1)/rate;
   }
   else
   {
       printf("输入有误!请重新输入\n");
       goto A;
   }
   printf("%d年后的总产值:%.4lf\n",year,mount);
  
 }
 void huankuan()
 {

     printf("贷款金额:");
     scanf("%lf",&mount);
     printf("贷款年限:");
     scanf("%d",&year);
    printf("年利率:");
     scanf("%lf",&rate);
     principal=mount*rate/(12*(1-rate)*(pow(1-rate,year)-1));
    printf("贷款%.4lf每月需要还款%.4lf\n",mount,principal);
 }


 main(){
	 while(1){
    int num=0;
meu();

printf("请输入选择：");

scanf("%d",&num);

switch(num){

case 1:

    fuli(); 

    break;

case 2:

   danli();

    break;

case 3:

    principaljisuan();

break;
 case 4:

     time();
            
 break;

 case 5:

   lilv();

    break;
case 6:

   yearmount();

    break;

	case 7:

   huankuan();

    break;




}

 }
 }