# C

- 장점:
  1. `시스템 프로그래밍이 가능하다` :운영체제`OS`를 개발할 목적으로 만든 언어이므로 이를 사용해 하드웨어를 제어하는 시스템 프로그래밍이 가능하다. 
  2. `이식성을 갖춘 프로그램을 만들 수 있다.` : 이식성`portability` 이란 기종이 다른 컴퓨터에서도 올바르게 작동하는 성질을 의미한다.
  3. `함수를 사용해 개별 프로그래밍이 가능하다.` : 함수를 통해 기능별로 프로그래밍이 가능하므로 개발 과정에서 에러를 수정하기 쉽고 개발된 후에도 프로그램의 유지보수에 도움이 된다.



> __시작하기 전에__

프로그램을 만드려면 __소스파일__ 을 만들어야 한다. C언어 외에도 대부분의 프로그래밍 언어는 사람이 읽고 쓰는 데 중점을 두었기에 컴퓨터는 이를 그래돌 이해하지 못한다. 따라서 컴퓨터가 이해하는 언어, 기계어로 바꾸는 과정이 필요한데 이를 __컴파일__이라고 한다.



```c
// 문자열을 화면에 출력해줌
# include <stdio.h>  // prinf 함수가 선언되어 있으며 표준입출력과 관련된 기능을 제공해준다.

int main(void)
{
	printf("Be Happy");
    printf("My friend");
    return 0;
}
```



## 제어문자

__제어문자__ 란 문자는 아니지만, 출력 방식에 영향을 주는 문자를 의미한다. 제어 문자를 문자열 안에 포함 시키면 그 기능에 따라 출력 형태를 바꾼다.



- 제어문자 : ASCII [ 1 ~ 31 ]
  - 출력 가능한 문자: ASCII [ 9 ~ 13, 32 ] 

```c
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
```

- `\n (개행, new line)` : 다음 줄로 이동
- `\b (백스페이스, backspace)` : 한 칸 왼쪽으로 이동
- `\r (캐리지 리턴, carriage return)` : 맨 앞으로 이동
- `\a (알럿 경보, alert)` : 벨소리



## 정수와 실수 출력

printf 함수는 기본적으로 문자열을 출력한다. 따라서 숫자를 출력할 때는 변환 문자를 사용해서 문자열로 변환하는 과정이 필요하다. 변환 문자는 데이터의 형태에 따라 다르다. 정수는 `%d` , 실수는 `%lf(엘에프)`를 사용한다.



```c
# include <stdio.h>

int main(void)
{
    printf("%d\n", 10);
    printf("%lf\n", 3.4);
    printf("%.10lf\n", 3.45);
    printf("%.10lf\n", 3.4);

    printf("%d 과 %d 의 합은 %d 입니다. \n", 10, 20 ,10 + 20);
    printf("%.1lf-%.1lf = %.1lf\n", 3.4, 1.2, 3.4 - 1.2);

    return 0;

}
```

### 소수점 자릿수 지정과 반올림

%lf 로 실수를 출력하면 소수점 이하 여섯째 자리까지 출력된다. 이때 소수점의 자릿수를 바꾸려면 %와 lf 사이에 소수점을 찍고 자릿수를 지정해야 한다.

```c
printf("%.1lf\n", 3.45);
```

잘리는 값은 반올림해서 출력된다.  출력은 3.45이지만 소수점 첫째 자리까지 출력하겠다고 했으므로 둘째자리부터 반올림해서 3.5가 출력된다.



## 상수와 데이터 표현 방법

### 정수 상수 표현법

정수 상수는 기본적으로 아라비아 숫자 0~9, +, - 기호를 사용한다. 그리고 이를 3가지 진법 10진수, 8진수, 16진수로 표현할 수 있다.



### C언어에서 진법 표현하기

6, 11 과 같은 표기로는 10진수인지 8진수인지를 구분할 수 없다. 따라서 8진수는 숫자 앞에 0(영), 16진수는 0x(영엑스) 를 붙여 구분한다.

```c
#include <stdio.h>

int main(void)
{
    printf("%o\n", 12);
    printf("%x\n", 12);
    printf("%X\n", 12);

    return 0;
}
```



### 실수 상수 표현법

지수 형태를 지수 값의 크기에 따라 무수히 많은 방법으로 표현할 수 있다. 그중 소수점 앞에 0이 아닌 유효 숫자 한 자리를 사용해 지수 형태로 바꾼것을 __정규화 normalization 표기법__ 이라고 한다.

```c
#include <stdio.h>

int main(void)
{
    printf("%.1lf\n", 1e6); // 지수 형태의 실수를 소수점 형태로 출력
    printf("%.7lf\n", 3.14e-5); // 소수점 이하 일곱째 자리까지 출력
    printf("%le\n", 0.0000314); // 소수점 형태의 실수를 지수 형태로 출력
    printf("%.2le\n", 0.0000314); // 지수 형태로 소수점 이하 둘째 자리까지 출력
    
}
```



### 문자와 문자열 상수 표현법

문자는 ''로 묶고, 문자열은 ""로 묶는다.

```c
#include <stdio.h>

int main(void)
{
    printf("%c\n", 'A');
    printf("%s\n", "A");
    printf("%c은 %s입니다. \n", '1', "first");
    
    return 0;
}
```

'1'은 문자 상수이고 "first"는 문자열 상수이다. 또한 "A" 와 같이 하나의 문자라도 큰따옴표가 붙으면 문자열 상수가 된다.



### 상수가 컴파일된 후의 비트 형태

지금까지 정수, 실수, 문자, 문자열 상수에 대해 살펴봤다. 편집기에 코드를 입력하면 이 코드는 모두 컴퓨터가 이해하는 형태의 아스키 코드 값으로 저장된다.

예를 들어 10 + 20을 입력했다면 1, 0, +, 2, 0 이 모두 하나의 문자로 저장되는 것이다. 이것이 컴파일 과정이 없으면 코드가 컴퓨터에서 실행되지 않는 이유이다. 컴퓨터에서 + 는 덧셈을 하라는 명령이 아니라 그저 '+' 문자이며, 10과 20도 연산이 가능한 값이 아니라 문자이다.

#### 정수 상수와 실수 상수의 컴파일

10 : 00000000 00000000 00000000 00001010

10.0 : 01000000 00100100 00000000 00000000 00000000 00000000 00000000 00000000



정수 상수를 컴파일하면 4바이트, 실수는 8바이트로 표현된다. 컴퓨터는 이 둘을 다르게 인식하기 때문에 어떤 상수를 쓰냐에 따라 실행 속도나 정확도에서 차이가 날 수 있습니다. 정수는 가장 빠르고 정확하게 연산될 수 있는 형태이므로 프로그래밍 할때 가능하면 정수 상수를 사용하는 것이 좋다.



#### 정수 상수가 컴파일된 후의 비트 형태

- 양수의 변환

  ```
  1비트 | 0 ~ 1
  8비트 | 0 ~ 255
  32비트 | 0 ~ 4294967295
  ```

  이 계산에 따르면 4바이트로 표현할 수 있는 정수의 최댓값은 2^32-1로 4294967295 이다.

  따라서 4294967295 보다 큰 상수를 사용하면 컴파일러는 자동으로 데이터의 크기를 8바이트로 늘려 처리한다. 

  만약 값의 크기와 상관없이 데이터의 크기를 8바이트로 만들고 싶을 때는 정수에 접미사 LL 또는 소문자 ll을 붙여 사용한다. LL 은 Long Long을 의미한다.

  ```
  13
  13LL
  ```

  

  

- 음수의 변환

  음수는 절댓값을 2의 보수로 바꾸어 처리한다. 2의 보수란 2진수의 0과 1을 바꾼 상태 ( 이 상태를 1의 보수라 함)에서 1을 더한 값을 말한다. 예를 들어 -10은 그 절댓값은 10을 2진수로 바꾸고 1의 보수를 구한 후에 다시 1을 더해 2의 보수로 만든다.

  음수를 2의 보수로 처리하는 이유는 특별한 변환 과정없이 바로 양수와 음수를 더할 수 있기 떄문이다. 10과 -10의 모든 비트를 더하면 가장 왼쪽의 비트에서 자리 올림이 발생하고 남은 32비트는 모두 0이 되어 결과적으로 값 자체가 0이 된다.

#### 실수 상수가 컴파일된 후의 비트 형태

2진수로 값을 표현하는 방식은 값의 크기에 비례해 데이터의 크기도 커지므로 아주 큰 값이나 소수점 이하를 표현하는 데 한계가 있다. 따라서 데이터를 표현하는 효과적인 방법을 만들고 그 규칙에 따라 실수를 표현하다.

실수의 경우 제한된 데이터 크기에 수를 표현하기 위해 IEEE 754 표준을 따른다. 이 표준에는 sinle, double, quad 의 3가지 형식이 있는데, 그 중 가장 많이 사용하는 doublle 형식만 간단히 살펴보자. double 형식은 실수를 8바이트, 즉 64비트로 표현하며 64비트는 다음과 같이 구성된다.

- 부호 비트 : 가장 왼쪽 비트는 부호 비트이며 양수는 0, 음수는 1로 표시한다.
- 지수부 : 부호 비트 다음부터 11비트는 지수값을 의미한다.
- 소수부 : 나머지 52비트는 소수값을 의미한다.



#### 실수 상수의 오차

실수 상수의 경우 표현할 수 있는 값의 범위가 상당히 넓다. 그러나 값의 크기와 달리 정확한 값을 표현하는 데에는 한계가 있다. 실제로 0.123456789처럼 유효숫자가 많은 값은 정확히 표현하지 못하고 오차가 발생한다. 오차가 발생하는 이유는 소수 부분을 나타내는 비트가 정확한 값을 표현할 수 없기 때문이다.

결론적으로 IEEE 754 표준계산식에 의하면 double 형의 경우 15자리까지 유효숫자를 사용할 수 있다. 값에 따라 더 많은 자릿수를 서로 다르게 표현할 수 있으나 자릿수가 같은 모든 값을 서로 다르게 표현하지 못하므로 15자리 범위에서 사용하는 것이 바람직하다.



## 변수

변수는 선언을 통해 메모리에 저장 공간을 확보한다. 정수는 `int` , 실수는 `double`, 문자는 `char` , 문자열은 `char 배열`을 사용한다.

```c
int a;
```

자료형과 변수명을 통해 선언을 하게 된다. 변수를 선언하면 저장 공간이 생기는데 처음 그 안에는 어떤 값이 들어 있을까? 

`알 수 없다`

컴퓨터의 메모리 공간은 재활용된다. 프로그램이 종료되면 사용하던 메모리 공간을 반납하고 새로 실행된 프로그램이 그 공간을 사용하는 것이다. 이 때 종료된 프로그램이 어떤 값을 메모리 공간에 남겨놓았는지는 알 수 없다. 새 프로그램에서 이 값은 의미가 없으므로 이를 `쓰레기 값 garbage value` 이라고 한다. 이 쓰레기 값때문에 프로그램에 오류가 생길 수 있으므로 반드시 원하는 값으로 바꾸는 초기화 과정이 필요하다.

```c
a = 10;
```

`=`를 우리는 `대입 연산자`라고 부른다. 이는 오른쪽 값을 왼쪽에 저장한다는 의미이다.

### 변수 선언과 대입규칙

1. 중괄호의 블록`{}`안에 변수를 선언하며 선언한 위치부터 블록 끝까지 사용할 수 있다.

   > 앞에서 선언한 변수와 같은 이름은 사용할 수 없다.

2. 변수의 자료형이 같으면 동시에 둘 이상의 변수를 선언할 수 있다.

   ```c
   int b, c;
   ```

   

3. 대입 연산자는 연산자 왼쪽의 변수에 오른쪽의 값을 저장한다.
   ```c
   a = 10; // 변수에 상수대입
   b = a; // 변수에 변수 대입
   c = a + 20; // 변수에 수식 대입
   ```

   

4. 변수는 대입 연산자 왼쪽에서는 저장공간이 되고, 오른쪽에서는 값이 된다.

### 정수 자료형

같은 정수형이라도 메모리 저장 공간의 크기에 따라 `char`, `short`, `int`, `long`, `long long` 으로 구분된다.

크기가 큰 자료형이 더 많은 범윌의 값을 저장할 수 있으며 그 범위는 다음 공식에 따라 계산된다.

```
-2^(비트 수 - 1) ~ 2^(비트 수 - 1) - 1
```

- 특별한 경우가 아니면 정수형을 표현할 때는 int를 사용하자.
  - int 형은 연산은 기본 단위로 컴퓨터에서 가장 빠르게 연산된다. short 형은 int 형보다 크기가 작아 메모리를 적게 사용하지만, 연산과정에서는 int 형으로 변환되므로 실행 속도가 느려질 수 있다.
- long 형은 큰 값을 저장할 때 사용된다.

> 자료형의 크기를 알아내기 위해서는 sizeof 연산자를 쓰자.

### unsigned 정수 자료형

정수형은 보통 양수와 음수를 모두 저장하지만, 양수만 저장하면 두 배 더 넓은 범위의 값을 저장할 수 있다. 음수가 없는 데이터를 저장할 때는 unsigned 를 사용한다.

unsigned 자료형을 사용할 때는 출력시 변환 문자 사용에 주의해야 한다. unsigned 변수에 큰 양수를 저장하고 %d로 출력하면 음수가 출력될 가능성이 있으며, 음수를 저장하고 %u로 출력하면 양수가 출력된다.

```c
# include <stdio.h>

int main(void)
{
	unsigned int a;
    
    a = 4294967295; // 큰 양수 저장
    printf("%d\n", a); // %d 로 출력
    a = -1;
    pritnf("%u\n", a); 
}
```

```
-1
4294967295
```

### 실수 자료형

실수 자료형은 크기에 따라 `float`, `double`, `long double`로 구별되며, 값을 저장할 수 있는 범위가 다르다. 가장 작은 `float`도 4바이트이므로 저장범위가 큰 편이다. 실수 자료형의 경우 값의 범위보다 유효숫자의 개수에 주목해야 한다.

```
float 유효숫자 7
double 유효숫자 15
long double 유효숫자 15이상
```

```c
# include <stdio.h>

int main(void)
{
    float ft = 1.234567890123456789; // 유효숫자가 많은 값으로 초기화
    double db = 1.234567890123456789;
    
    printf("float 형 변수의 값 : %.20f\n", ft); // 소수점이하 20자리
    printf("double 형 변수의 값 : %.20lf\n", db);
}
```

```
float 형 변수의 값 : 1.23456788063049316406
double 형 변수의 값 : 1.23456789012345669043
```

출력 값과 초깃값이 다름을 볼 수 있다. float 형 변수는 아홉번쨰부터, double 형 변수는 열일곱 번째부터 달라졌다. 

왜 그럴까? 실수형은 저장하는 값에 따라 숫자가 정확하게 표현될 수도 있고 그렇지 않을 수도 있다. 이렇게 값이 달라지는 이유는 컴퓨터에서 실수를 표현하는 방식이 오차를 갖고 있기 때문이다. 따라서 float 형은 유효숫자 7자리, double 형은 15자리 범위내의 값을 사용하는 것이 좋다.

- 정수형을 기본으로 사용하고 꼭 필요한 경우에만 실수형을 사용한다.
- 실수형은 유효 숫자가 많은 double 형을 기본으로 사용한다.

### 문자열 저장

```c
char fruit[6] = "apple";
```

왜 문자열의 길이보다 배열의 크기를 하나 더 크게 잡아야 할까? 바로 `컴파일러`가 문자열의 끝에 `\0(널 문자 null character)`을 자동으로 추가하기 때문이다.

```c
char fruit[20] = "strawberry";
printf("%s\n", fruit);
```

문자열의 끝에는 항상 `널 문자`가 있으므로 printf 함수는 널 문자 이전까지 저장된 문자열만 출력한다.

- 배열에는 대입 연산자를 사용할 수 없다.

  > 대입 연산은 대상 자료형의 크기가 일정해야 수행할 수 있다. 선언에 따라 크기가 달라지는 char 배열을 사용하면 대입 연산을 할 수 없다. 또한 배열명은 주소 상수이므로 대입 연산자 왼쪽에 쓸 수 없다.

char 배열에 새로운 문자열을 저장하려면 어떻게 할까? char 배열에 초기화 이외에 문자열을 저장할 때는 strcpy 함수를 사용한다.

```c
# include <stdio.h>
# include <string.h>

int main(void)
{
    char fruit[20] = "strawberry";
    printf("%s\n", fruit);
    strcpy(fruit, "banana");
    printf("%s\n", fruit);
    return 0;
}
```

### const 를 사용한 변수

변수는 저장 공간이므로 언제든지 그 값을 바꿀 수 있다고 했다. 그러나 `const` 를 사용한 변수는 예외이다. 변수를 선언할 때 그 앞에 const를 붙이면 초기화된 값을 바꿀 수 없다.

```c
# include <stdio.h>

int main(void)
{
    int income = 0;
    double tax;
    const double tax_rate = 0.12;
    
    income = 456;
    tax = income + tax_rate;
    printf("세금은 : %.1lf입니다.\n", tax);
    
    return 0;
}
```

const 를 왜 쓰는 걸까? 변수에 const 를 사용하면 복잡한 값에 의미있는 이름을 붙여 쓸 수 있고 값이 바뀌지 않음을 보장받을 수 있다. const를 사용하면 변수가 상수처럼 쓰이지만, C 문법이 제공하는 변수의 특성을 모두 가지는 엄연한 변수이다. 따라서 앞으로 배우겠지만, 주소 연산자로 메모리의 위치를 알 수 있고 사용범위의 제한 규칙도 그대로 적용된다.

### 예약어와 식별자

`예약어 reserverd word(key word)` 는 컴파일러와 사용방법이 약속된 단어이며, `식별자 identifier` 는 필요에 따라 만들어 사용하는 단어이다. 예를 들어 변수 선언문에서 자료형 이름은 예약어이고, 변수명은 식별자이다.

식별자는 만들어 사용하는 단어이므로 중복되지 않는다면 어떤 것이든 사용할 수 있다.

- 알파벳 대문자 A~Z, 소문자 a~z, 숫자 0~9, _(밑줄, underline)로 만든다.
- 숫자로 시작할 수 없다.
- 대문자와 소문자는 서로 다른 식별자로 인산하다.
- 예약어는 식별자로 사용할 수 없다.

대소문자를 구분하므로 student와 Student는 다른 식별자이다. 따라서 이 두 식별자를 동시에 사용할 수 있다 Int, INT도 예약어 int와 구분되므로 식별자로 사용할 수 있다. 



## 데이터 입력

키보드에서 타이핑하는 모든 내용은 문자로 인식된다. 따라서 입력한 데이터를 연산이 가능한 정수나 실수로 사용하려면 변환 과정이 필요하다. 이때 사용하는 것이 바로 `scanf` 함수이다. `scan formatted` 라는 뜻이다. 

이 함수는 입력 문자들을 스캔해 원하는 형태의 데이터로 바꿔준다. 어떤 데이터로 변환할 것인지는 변환 문자를 통해 결정된다. scanf 함수에서 자료형에 따라 사용하는 변환 문자는 printf 함수로 출력할 때 사용하는 변환 문자와 거의 같다.



### scanf 함수의 사용법

```c
scanf("%d", &a);
```

```c
#include <stdio.h>

int main(void)
{
    int a;
    
    scanf("%d", &a);
    printf("입력한 값 : %d\n", a);
    
    return 0;
}
```



### scanf 함수 사용의 유의점

- scanf 함수에서 변수명을 지정할 때는 &를 붙여야 한다.
  scanf 함수를 사용할 때 가장 많이 하는 실수다. `&`는 변수의 주소를 구하는 연산자로 함수의 파라미터로 전달된 a의 값으로 적용되기 위해서 포인터로써 사용되야 한다.
- scanf 함수에서 사용한 변환 문자와 맞는 형태의 데이터를 입력해야 한다.
  scanf 함수는 변환문자와 입력형태가 다르면 데이터를 입력하지 못할 수 있다. 키보드로 입력하는 데이터는 모두 문자로 처리된다. scanf 함수는 변환문자를 보고 정수로 변환할지 실수로 변환할지 아니면 그냥 문자열로 입력할지를 판단한다. 그런데 만약 변환 문자와 다른, 예상치 못한 데이터가 입력되면 scanf 함수는 변환을 포기하고 실행을 중단한다.



### 문자와 문자열의 입력

char 형 변수에 문자를 입력할 때는 키보드로 입력하는 모든 문자가 대상이 된다.

즉, `SpaceBar`(공백문자) 나 `Enter`(개행문자) 도 하나의 문자로 전달된다. 문자열은 char 배열에 %s 변환문자를 사용해 입력하는데, 문자열을 입력할 때는 배열명에 &를 붙이지 않는다. 또한 스페이스나 엔터, 탭 등을 만나면 바로 전까지만 저장되므로 공백없이 연속으로 입력해야 한다.

```c
# include <stdio.h>

int main(void)
{
    char grade;
    char name[20];
    
    printf("학점 입력: ");
   	scanf("%c", &grade);
    printf("이름 입력 : ");
    scanf("%s", name);
    printf("%s의 학점은 %c이다.\n", name, grade);
    
    return 0;
}
```

6행에서 배열의 크기가 20바이트이므로 최대 19자의 문자열을 입력할 수 있다. 문자열에서는 문자열의 끝을 표시하기 위해 널 문자를 사용해야 한다. 따라서 문자열 끝에 널문자를 저장할 1바이트의 여유는 있어야 한다. 널 문자는 scanf 함수가 자동으로 붙여준다.



### 비정상 종료되는 경우

지정한 배열보다 큰 문자열을 입력하면 프로그램이 비정상적으로 종료될 수 있다. 큰 문자열을 입력되면 다른 변수의 저장 공간을 침범할 수 있기 때문이다.



## 연산자

### 산술연산자, 관계연산자, 논리연산자

연산자는 보통 기능에 따라 분류하지만, 피연산자의 개수에 따라 나눌 수 있다. 피연산자가 하나면 단항 연산자, 2개면 이항연산자, 3개면 삼항연산자가 된다

#### 산술연산자

- `+`, `-`, `*`, `/`, `%`

  - 나머지 연산자, 나머지 연산자
    ```c
    # include <stdio.h>
    
    int main(void)
    {
        double apple;
        int banana;
        int orange;
        
        apple = 5.0 / 2.0;
        banana = 5 / 2;
        orange = 5 % 2;
        
        printf("apple : %.1lf\n", apple);
        printf("banana : %d\n", banana);
        printf("orange : %d\n", orange);
        
        return 0;
    }
    ```

    자료형에 맞게 연산을 수행하는 것이 좋은데 실수를 정수형 변수에 저장하는 얘기가 복잡하게 될 수 있다. 몫을 뺀 나머지만 구할 때는 나머지 연산자 `%` 를 사용한다.

#### 대입연산자

- `=`

#### 증감 연산자

a 라는 int 형 변수에 1을 더하려면 a = a + 1; 이라고 쓰면 된다. 그런데 이렇게 쓰지 않고 ++a; 로 간단히 표현할 수도 있다. 빼기도 마찬가지다.

이런 표현은 앞으로 배울 for 문, while문, do while 문 같은 반복문에서 루프마다 하나씩 더하거나 뺄때 자주 사용된다.

##### 전위 표기와 후위 표기

증감연산자가 피연산자 앞에 놓이면 `전위표기 prefix` , 뒤에 놓이면 `후위 표기 postfix` 라고 한다.

```c
# include <stdio.h>

int main(void)
{
    int a = 5, b = 5;
    int pre, post;
    
    pre = (++a) * 3;
    post = (b++) * 3;
    
    printf("a = %d, b= %d\n", a, b);
    printf("++a * 3 = %d, b++ * 3 = %d\n", pre, post);
    
    return 0;
}
```

증감연산자를 단독으로 쓰면 전위표기와 후위표기의 결과는 같다. 즉 a++ 와 ++a 는 모두 a의 값을 1씩 증가시킨다. 그러나 다른 연산자와 함께 쓰이면 연산의 결과에 영향을 미친다. 즉 증감연산자의 후위 표기는 다른 연산자와 함께 사용될 때 가장 나중에 연산된다고 생각해도 좋다.

- (++a) + a + (++a) 의 결과는?
  하나의 수식에서 같은 변수를 두 번 이상 사용할 때는 그 변수에 증감 연산자를 사용하면 안된다. C 언어 표준에는 이와 관련된 내용이 정의되어 있지 않으므로 컴파일러에 따라 실행결과가 다를 수 있다. 따라서 이런 코드는 절대 사용해서는 안된다.

#### 관계연산자

관계 연산자에는 대소 관계연산자와 동등 관계 연산자가 있다. `<`, `>`, `=`, `!=` 

#### 논리 연산자

`&&`, `||`, `!`

### 그 외의 연산자

#### 형 변환 연산자

형 변환 연산자는 피연산자를 하나 가지며 피 연산자의 값을 원하는 형태로 바꾼다.

#### 자동 형 변환

컴퓨터는 데이터의 형태에 따라 다른 연산 방법을 사용하므로 피연산자가 2개 이상이라면 피연산자의 형태는 같아야 한다. 따라서 컴파일러는 컴파일 과정에서 피연산자의 형태가 다르면 형태를 일치시키는 작업을 수행한다. 이를 `자동형변환(묵시적 형변환)` 이라고 한다.

이런 형 변환의 기본 규칙은 데이터크기가 작은 값이 크기가 큰 값으로 바뀌는 것이다. 예를 들어 정수와 실수를 연산하면 정수가 실수로 자동 변환되어 연산된다. 다만 대입 연산은 메모리에 값을 저장하므로 무조건 좌항의 변수형에 맞게 저장된다.



#### sizeof 연산자

피연산자의 크기를 바이트 단위로 계산해서 알려준다. 보통 () 로 피연산자를 묶어서 사용한다.

#### 복합연산자

- `-=`,`+=`,`/=`,`%=`,`*=`,`<<=`,`>>=`

복합대입 연산자는 대입 연산자의 특징을 그대로 가진다.

- 왼쪽 피연산자는 반드시 변수가 와야한다.
- 오른쪽 항의 계산이 모두 끝난 후, 즉 가장 마지막에 복합대입연산자를 계산한다.

#### 콤마 연산자

콤마 연산자는 대입 연산자보다 우선순위가 낮은 유일한 연산자이다. 따라서 대입 연산자와 함께 사용할 때는 반드시 괄호가 필요하다.

```c
res = (++a, ++b);
```

res에는 ++b의 값이 저장된다.

#### 조건 연산자

유일한 삼항 연산자이다. `a ? b : c` 으로 쓴다. a 가 참이면 b, 아니면 c가 결과값이 된다.

#### 비트 연산자

- 논리 연산자 : `&`, `|`, `^`,`~`
- 비트 이동 연산자 : `>>`, `<<`

비트 연산자는 데이트를 비트로 정확히 표현할 수 있는 정수에만 사용할 수 있다.



### 연산자 우선순위와 연산방향

- 단항 연산자 > 이항 연산자 > 삼항 연산자
- 산술 연산자 > 비트이동연산자 > 관계 연산자 > 논리연산자



## 선택문

