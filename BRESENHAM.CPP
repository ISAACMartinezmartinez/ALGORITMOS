 #include <stdio.h>
  #include <conio.h>
  #include <graphics.h>
  #include <math.h>
  #include <dos.h>

  int main() {
        
        int gdriver = DETECT, gmode;
       	float x1 , y1 , x2, y2;
        int err, x, y, dx, dy, dp, xEnd;
        int twody, twodxdy;
        
        printf ("Punto de inicio:");
		scanf("%f%f",&x1,&y1);
	 	printf ("Punto final:");
		scanf("%f%f",&x2,&y2);

        
        initgraph(&gdriver, &gmode, "");
        err = graphresult();

        if (err != grOk) {
                printf("Graphics Error: %s\n",
                                grapherrormsg(err));
                return 0;
        }

        
        dx = x2 - x1;
        dy = y2 - y1;

        twody = 2 * dy;
        twodxdy = 2 * (dy - dx);

        dp = twody - dx;

        if (x1 > x2) {
                x = x2;
                y = y2;
                xEnd = x1;
        } else {
                x = x1;
                y = y1;
                xEnd = x2;
        }

        putpixel(x, y, WHITE);

        while (x < xEnd) {
                x = x + 1;
                if (dp < 0) {
                        dp = dp + twody;
                } else {
                        y = y + 1;
                        dp = dp + twodxdy;
                }

  
                putpixel(x, y, WHITE);

        }

        getch();

        /* deallocate memory allocated for graphic screen */
        getchar();
		getchar();
        closegraph();

        return 0;
  }
