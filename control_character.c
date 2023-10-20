#include <stdio.h>

int main()
{
    // Be happy 를 출력하고 줄을 바꿈
    printf("Be happy\n"); 
    
    // 화면에 번호를 출력하고 줄을 바꿈
    printf("12345678901234567890\n");

    // My를 출력하고 탭 위치로 이동 후에 friend 를 출력하고 줄을 바꿈
    printf("My\tfriend\n");

    // Goot를 출력하고 한 칸 왼쪽으로 이동해 t를 d로 바꾸고 탭 위치로 이동후오
    // chance 를 출력하고 줄을 바꿈
    printf("Goot\bd\tchance\n");

    // 맨 앞으로 이동해 C를 W로 바꾸고 벨소리를 내고 줄을 바꿈
    printf("Cow\rW\a\n");
    return 0;
}