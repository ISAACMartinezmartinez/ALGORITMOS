#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

  int main() {
       
        int gdriver = DETECT, gmode, err;
        float i, x1, y1, x2, y2, dx, dy, steps;
        float x, y, xincr, yincr;
        
        printf ("Punto de inicio:");
		scanf("%f%f",&x1,&y1);
	 	printf ("Punto final:");
		scanf("%f%f",&x2,&y2);

       
        initgraph(&gdriver, &gmode, "");

        err = graphresult();

        if (err != grOk) {
                printf("Graphic Error: %s\n",
                                grapherrormsg(err));
                getch();
                return 0;
        }

        
        
        dx = x2 - x1;
        dy = y2 - y1;

        x = x1, y = y1;

        steps = abs(dx) > abs(dy) ? dx : dy;

        xincr = (1.0 * dx) / steps;
        yincr = (1.0 * dy) / steps;

        putpixel((int) x, (int) y, WHITE);

        
        for (i = 0; i < steps; i++) {
                x = x + xincr;
                y = y + yincr;

                
                putpixel((int) x, (int) y, WHITE);

        }

                getchar();
		getchar();
        closegraph();
        return 0;
  }
