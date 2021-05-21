#include<stdio.h>
#include<graphics.h>

void DDA(float x1,float y1,float x2,float y2){
	float x,y,pp,m,n;
	x=x2-x1;
	printf("dx: %f", x);
	y=y2-y1;
	printf("dy: %f", y);
	m=x1;
	n=y1;
	printf("\n");
	if(x>y){
		printf("steps: %f", x);	
		printf("\n");
		pp=1/x;
		printf("Xinc: %f", pp);
		printf("\n");	
	}
	else {
		printf("steps: %f", y);
		printf("\n");
		pp=1/y;
		printf("Yinc: %f", pp);
		printf("\n");
	}
	while(m<=x2&&n<=y2){
		m=m+pp*x;
		n=n+pp*y;
		printf("\n");
		printf("X: %f ", m);
		printf("\n");
		printf("Y: %f", n);
		putpixel((int)(m+100.0),(int)(n+100.0),RED);
		x1=m;
		y1=n;
	}
}

int main()
{
	int gd=DETECT,gmode;
	float x1,x2,y1,y2;
	 printf ("Punto de inicio:");
	scanf("%f%f",&x1,&y1);
	 printf ("Punto final:");
	scanf("%f%f",&x2,&y2);
	initgraph(&gd,&gmode,"");
	DDA(x1,y1,x2,y2);
	getchar();
	getchar();
	closegraph();
}

