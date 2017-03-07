#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *input,*crdt,*out;
    struct gp
    {
        int roll;
        char name[20];
        float CSE_1101,CSE_1102;
        float EEE_1107,EEE_1108;
        float PHY_1107,PHY_1108;
        float MATH_1107;
        float HUM_1107;
    } ;
    struct gp st[60];

    input=fopen("input_gp.txt","r");
    if(input==NULL)
    {
        printf("Can not open file");
    }

    float credit[60][8],total_credit[60]={0},cgpa[60];
    char abs[60]="Absent";
    int j,i;
    for(j=0;j<60;j++)
    fscanf(input,"%d%s%f%f%f%f%f%f%f%f",&st[j].roll,st[j].name,&st[j].CSE_1101,&st[j].CSE_1102,&st[j].EEE_1107,&st[j].EEE_1108,&st[j].PHY_1107,&st[j].PHY_1108,&st[j].MATH_1107,&st[j].HUM_1107);
    crdt=fopen("input_credit.txt","r");
    if(crdt==NULL)
    {
        printf("Can not open file");
    }
    for(i=0;i<60;i++)
    {
        for(j=0;j<8;j++)
        {
             fscanf(crdt," %f",&credit[i][j]);
            total_credit[i]=total_credit[i]+credit[i][j];
        }

    }
    for(i=0;i<60;i++)
    {
        if(total_credit[i]!=0)
        cgpa[i]=(st[i].CSE_1101*credit[i][0]+st[i].CSE_1102*credit[i][1]+st[i].EEE_1107*credit[i][2]+st[i].EEE_1108*credit[i][3]+st[i].PHY_1107*credit[i][4]+st[i].PHY_1108*credit[i][5]+st[i].MATH_1107*credit[i][6]+st[i].HUM_1107*credit[i][7])/total_credit[i];

    }


    out=fopen("output_cgpa.txt","w");
    fprintf(out,"Roll        Name      CGPA\n\n");
    for(i=0;i<60;i++)
    {
        if(total_credit[i]!=0)
         fprintf(out,"%d  %8s  %7.2f\n",st[i].roll,st[i].name,cgpa[i]);
         else
            fprintf(out,"%d  %s     %s\n",st[i].roll,st[i].name,abs);
         fprintf(out,"_______________________________\n\n");
    }

   fclose(input);
   fclose(crdt);
}
