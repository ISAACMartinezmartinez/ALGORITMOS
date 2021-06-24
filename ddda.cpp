#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

  int main() {
        /* request auto detection */
        int gdriver = DETECT, gmode, err;
        float i, x1, y1, x2, y2, dx, dy, steps;
        float x, y, xincr, yincr;
        
        printf ("Punto de inicio:");
		scanf("%f%f",&x1,&y1);
	 	printf ("Punto final:");
		scanf("%f%f",&x2,&y2);

        /* initialize graphic mode */
        initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");

        err = graphresult();

        if (err != grOk) {
                /* error occurred */
                printf("Graphic Error: %s\n",
                                grapherrormsg(err));
                getch();
                return 0;
        }

        /* draw line from (0, 0) to x-axis & y-axis maximum */
        
        dx = x2 - x1;
        dy = y2 - y1;

        x = x1, y = y1;

        steps = abs(dx) > abs(dy) ? dx : dy;

        xincr = (1.0 * dx) / steps;
        yincr = (1.0 * dy) / steps;

        putpixel((int) x, (int) y, WHITE);

        /* find the x and y successors and plot the pixels */
        for (i = 0; i < steps; i++) {
                x = x + xincr;
                y = y + yincr;

                /* put a pixel at the given postion(x, y) */
                putpixel((int) x, (int) y, WHITE);

        }

        /* deallocate memory allocated fro graphic screen */
        getchar();
		getchar();
        closegraph();
        return 0;
  }
