#include <stdio.h>
int zh(int x1,int x2,int x3);
void a(int zh1,int zh2,int zh3);
int main(){
    int x1, x2, x3;
    int y1, y2, y3;
    int z1, z2, z3;

    printf("请输入小明的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &x1, &x2, &x3);
    printf("请输入小强的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &y1, &y2, &y3);
    printf("请输入小林的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &z1, &z2, &z3);
    
    
    int zh1 = zh(x1,x2,x3);
    int zh2 = zh(y1,y2,y3);
    int zh3 = zh(z1,z2,z3);

    printf("结果");
    a(zh1,zh2,zh3);

    return 0;


}
int zh(int x1,int x2,int x3){
    int p = (x1 + x2 + x3) / 3;
    int f = ((p - x1) * (p - x1) + (p - x2) * (p - x2) + (p - x3) * (p - x3)) / 3;
    int zh = 3 * p - f / 3;
    return zh;
}
void a(int zh1,int zh2,int zh3){
    if (zh1 >= zh2 && zh2 >= zh3) {
      printf("小明 > 小强 > 小林");
  } else if (zh1 >= zh3 && zh3 >= zh2) {
      printf("小明 > 小林 > 小强");
  } else if (zh2 >= zh1 && zh1 >= zh3) {
      printf("小强 > 小明 > 小林");
  } else if (zh2 >= zh3 && zh3 >= zh1) {
      printf("小强 > 小林 > 小明");
  } else if (zh3 >= zh1 && zh1 >= zh2) {
      printf("小林 > 小明 > 小强");
  } else { // zh3 >= zh2 && zh2 >= zh1
      printf("小林 > 小强 > 小明");
  }
}