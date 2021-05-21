#include<stdio.h>
#include<graphics.h>

void BRESENHAMS(float x1,float y1,float x2,float y2){
	float x,y,m,n,p,w;
	x=x2-x1;
	printf("dx: %f", x);
	printf("\n");
	y=y2-y1;
	printf("dy: %f", y);
	printf("\n");
	p=(2*y)-x;
	printf("P: %f", p);
	printf("\n");
	m=x1;
	n=y1;
	w=m*2;
	printf("\n");
	while(m<=w){
		putpixel((int)(m+100.0),(int)(n+100.0),RED);
		x++;
		if(p<0){
			p=p+2*y;
		}
		else{
			p=p+(2*y)-(2*x);
			y++;
		}
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
	BRESENHAMS(x1,y1,x2,y2);
	getchar();
	getchar();
	closegraph();
}

