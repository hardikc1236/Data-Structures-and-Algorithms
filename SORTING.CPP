#include<stdio.h>
#include<conio.h>
void sortTemp(float t[],int n){
int i,j;float x;
for(i=0;i<n-1;i++)
for(j=0;j<n-i-1;j++)
if(t[j]<t[j+1]){x=t[j];t[j]=t[j+1];t[j+1]=x;}
}
void main(){
float t[50];int n,i;
clrscr();
printf("Enter number of days: ");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("Enter temperature of day %d: ",i+1);
scanf("%f",&t[i]);
}
sortTemp(t,n);
printf("\nTemperatures in descending order:\n");
for(i=0;i<n;i++)
printf("%.1f\n",t[i]);
printf("\nHighest: %.1f\nLowest: %.1f",t[0],t[n-1]);
getch();
}