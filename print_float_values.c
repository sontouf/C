# include <stdio.h>

int main(void)
{
    float ft = 1.234567890123456789; // 유효숫자가 많은 값으로 초기화
    double db = 1.234567890123456789;
    
    printf("float 형 변수의 값 : %.20f\n", ft); // 소수점이하 20자리
    printf("double 형 변수의 값 : %.20lf\n", db);
}