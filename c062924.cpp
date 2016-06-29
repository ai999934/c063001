// from Glibw32
#include "glibw32.h"

const double PI = 3.141593;

void deqs(double x, double *y, double *dy)
{
    dy[0] = y[1];
    dy[1] = 0.3 * (1. - y[0] * y[0]) * y[1] - y[0];
    //dy[1] = 10.0 * (1. - y[0] * y[0]) * y[1] - y[0]; // for d<<0.5
}

main()
{
    double y[2];
    const double x_start = 0.0, x_end = PI * 2 * 5;
    const double d = 0.5;
    int k = (int)((x_end - x_start) / d + 1);
    
    ginit(500, 500, WHITE);
    
    GRAPH g;
    g.window(-PI * 5, -PI * 5, PI * 5, PI * 5);
    g.view(0, 0, 500, 500);
    g.axis(0.5, 0.5);
    g.setcolor(BLACK);
    g.textout(3, 2.9, "d=0.5", BLACK, 1.5, 1.5);
    
    y[0] = 1.0;
    y[1] = 0.0;
    
    g.plot_deq(2, x_start, k, y, y[0], y[1], d, deqs);
    
    gend();
}

// g++ c062924.cpp libglibw32-3.a -IC:\mingw-jp-20040217\include\ -LC:\mingw-jp-20040217\lib\ -IC:\Glibw32\ -LC:\Glibw32\ -luser
// 32 -lgdi32
// rename a.exe c062924.*
// c062924.exe
