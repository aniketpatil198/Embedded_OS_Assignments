/*Create a multi-ﬁle project (main.c, circle.c/.h, square.c/.h, rectangle.c/.h). Compile the program using "gcc" and execute it. No fork(), exec() expected
here.*/
#include "square.h"
#include "rectangle.h"
#include "circle.h"

int main()
{
    //rectangle
    printf("Perimeter of rectangle is %d\n",perimeter(4,5));
    printf("Area of rectangle is %d\n",area_r(4,5));
    
    //square
    printf("Perimeter of square is %d\n",peri(5));
    printf("Area of square is %d\n",area_s(5));

    //circle
    printf("Circumference of circle is %d\n",circumference(5));
    printf("Area of circle is %d\n",area_c(5));

    return 0;

}
