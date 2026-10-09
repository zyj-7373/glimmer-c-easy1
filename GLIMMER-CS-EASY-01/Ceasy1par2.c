#include <stdio.h>
int main(){
    char name[50];
    int age;
    int count=0;
    int change;
    do{
        printf("请输入您的姓名: ");
        scanf("%s",name);
        printf("请输入您的年龄: ");
        scanf("%d", &age);
        printf("%s %d岁\n", name, age);
        count++;
        printf("操作已进行%d 次。请问是否继续输入？(输入1继续,输入2结束): ", count);
        scanf("%d",&change);
    }while(change==1);
    printf("总共进行了%d次\n", count);
    return 0;
}