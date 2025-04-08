#include "Canvas.h"

int main()
{
    Canvas canvas(50, 20);
    
    canvas.DrawRect(5, 2, 20, 10, '#');
    canvas.FillRect(6, 3, 19, 9, '.');

    canvas.DrawCircle(35, 10, 5, '*');
    canvas.FillCircle(35, 10, 3, '+');

    canvas.DrawLine(0, 0, 49, 19, '/');
    canvas.SetPoint(25, 10, '@');

    canvas.Print();

    return 0;
}
