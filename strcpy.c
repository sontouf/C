# include <stdio.h>
# include <string.h>

int main(void)
{
    char fruit[20] = "strawberry";
    printf("%s\n", fruit);
    strcpy(fruit, "banana");
    printf("%s\n", fruit);
    printf("%c\n %c\n", fruit[5], fruit[7]);
    return 0;
}