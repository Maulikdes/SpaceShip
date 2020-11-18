#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
int x=320,y=430,flag=0,k,i=490;
int a=1,x3=10,y3=420,s1=0;
int x1=300,x2=210,y1=100,points,s2=1,y2=190,hit=0,c=210,b=121,q=2,count=0,count1=0; //health count
void start();
void draw();
void Start_animation();
void main()
{
	int gd=DETECT,gm;
	char g;

	clrscr();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	setbkcolor(10);
	Start_animation();
	while(1)
	{
		start();
	}
	getch();
}

	void start()
	{
		char g;
		if(kbhit())
		{
		g=getch();
		if(g==' ')
		{
			flag=1;
			i=430;          // y element of bullet
			k=x;
		}
		else if(g=='a'&&x>10)
			x=x-10;
		else if(g=='e')
		exit(0);
		else if(g=='d'&&x<630)
			x=x+10;
		else if(g=='p')
		{
		settextstyle(1,0,4);
		outtextxy(getmaxx()/2-30,getmaxy()/2,"PAUSE");
			while(!kbhit())
			{
			}
			}
		settextstyle(1,0,1);
		 }
		if(flag==1)
		i-=10;

		if(i==50||hit==1)
		{	flag=0;
			i=490;
			hit=0;
		}

			draw();
			return;

	}
	void draw()
	{
	//frame
	    setcolor(8);
	 rectangle(7,473,633,7);
	 rectangle(4,470,636,11);

	setcolor(15);
 //Starrs
		for(int l=0;l<6;l++)
	{
		for(int p=0;p<4;p++)
		outtextxy(x3+l*120,y3-p*120,"*");
	}



//Airship
	setfillstyle(1,1);
	setcolor(4);
	ellipse(x,y,0,360,20,4);
	setcolor(1);
	ellipse(x,y,0,360,6,15);
	floodfill(x,y,1);
	setfillstyle(1,5);
	circle(x-3,y+16,2);
	circle(x+3,y+16,2);
	floodfill(x-3,y+16,1);
	floodfill(x+3,y+16,1);
	setcolor(11);
	line(x-20,y-4,x-20,y+4);
	line(x-21,y-4,x-21,y+4);
	line(x+20,y-4,x+20,y+4);
	line(x+21,y-4,x+21,y+4);


//Bullets
	 if(flag==1)
	 {
		setfillstyle(1,3);
		circle(k-20,i,3);
		circle(k+20,i,3);
		floodfill(k-20,i,11);
		floodfill(k+20,i,11);
	  }
		setcolor(15);


//Last animation

	   int r=0;

       if(count==50)
       {

		    setbkcolor(11);
		    cleardevice();
			r=0;
			while(r<150)
			 {
				nosound();
				sound(r*200);
				cleardevice();
				for(int i=1;i<360;i+=5)
					{
					setcolor(i);
					outtextxy(getmaxx()/2+r*cos(i*3.14/180),getmaxy()/2+r*sin(i*3.14/180),"*");
					outtextxy(getmaxx()/2+(r+40)*cos(i*3.14/180),getmaxy()/2+(r+40)*sin(i*3.14/180),"*");
					outtextxy(getmaxx()/2+(r+80)*cos(i*3.14/180),getmaxy()/2+(r+80)*sin(i*3.14/180),"*");
					}
				settextstyle(1,0,1);
				delay(50);
				r+=5;

				nosound();
				     }

					settextstyle(1,0,5);
					outtextxy(getmaxx()/2-80,getmaxy()/2-20,"YOU WON");
					while(!kbhit())
					{}
					exit(5);


		}


//Monster
	    else
	      {
			setfillstyle(1,1);
			ellipse(x1,y1,0,360,100,20);
			floodfill(x1,y1,15);
			setcolor(1);
			ellipse(x1,y1,0,180,40,40);
			setfillstyle(1,q);



			floodfill(x1,65,1);
			setcolor(15);
			line(x2,110,x2-20,120);
			line(x2+3,110,x2-17,120);

			line(x2+180,110,x2+200,120);
			line(x2+183,110,x2+203,120);
			line(x2+60,120,x2+40,135);
			line(x2+63,120,x2+43,135);
			line(x2+120,120,x2+140,135);
			line(x2+123,120,x2+143,135);
			setcolor(6);
			circle(x2-19,121,3);
			circle(x2+199,121,3);
			circle(x2+41,136,3);
			circle(x2+141,136,3);
			floodfill(x2-19,121,6);
			floodfill(x2+199,121,6);
			floodfill(x2+41,136,6);
			floodfill(x2+141,136,6);


	 //enemy movements
			x1=x1+a*10;
			x2=x2+a*10;
			if(x1>580)
				a=-1;
			if(x1<100)
				a=1;



	   //hit enemy
			if(i<=121&&((k-20<=x2+141&&k-20>=x2-19)||(k+20<=x2+141&&k+20>=x2-19)))
			{
			   flag=0;
			   q++;
			   hit=1;
			   count+=10;
			   nosound();
			  for(s2=0;s2<5;s2++)
			  {
				nosound();
				sound(s2*240);
				delay(20);
			   }
			   nosound();			}



		   //enemy bullets

			circle(c-19,b,3);
			circle(c+199,b,3);
			circle(c+41,b+15,3);
			circle(c+141,b+15,3);
			floodfill(c-19,b,6);
			floodfill(c+199,b,6);
			floodfill(c+41,b+15,6);
			floodfill(c+141,b+15,6);

			b=b+10;
			if(b>=430)
			{
				c=x2;
				b=121;
			}

	    //airship hit
	     if(b>y-10)
		 {
		 if( ( (c-19)<(x+20) && (c-19)>(x-20) ) || ( (c+199)<(x+20) && (c+199)>(x-20) ) || ( (c+41)<(x+20) && (c+41)>(x-20) ) || ( (c+141)<(x+20) && (c+141)>(x-20) ) )
			{

			    setbkcolor(11);
				cleardevice();
				r=0;
			while(r<150)
				{
				nosound();
				sound(r*200);
					cleardevice();
				for(int i=1;i<360;i+=5)
					{
						setcolor(i);
					outtextxy(getmaxx()/2+r*cos(i*3.14/180),getmaxy()/2+r*sin(i*3.14/180),"*");
					outtextxy(getmaxx()/2+(r+40)*cos(i*3.14/180),getmaxy()/2+(r+40)*sin(i*3.14/180),"*");
					outtextxy(getmaxx()/2+(r+80)*cos(i*3.14/180),getmaxy()/2+(r+80)*sin(i*3.14/180),"*");
					}
				settextstyle(1,0,1);
				delay(50);
				r+=5;

				nosound();
				     }

					settextstyle(1,0,5);
					outtextxy(getmaxx()/2-80,getmaxy()/2-20,"Game over");
					while(!kbhit())
					{}
					exit(1);
			}
		}



		     delay(40);
		     cleardevice();

		     }



	}

	void Start_animation()
	{
	sound(s1*240);
	setcolor(6);
	s1++;
	for(int i=0;i<=5;i++)
	{
	nosound();
	sound(s1*240);
	setcolor(i);
	settextstyle(1,0,5);
	 outtextxy(100,i*45,"Welcome to the space");
	 delay(1000);
	 cleardevice();
	 s1++;
	}
//Loading
	int r=30,cx=320,cy=240;
	settextstyle(1,0,3);
	 setbkcolor(14);
	 s1=0;
	for(i=1;i<360;i+=20)
       {
       nosound();
       sound(s1*240);
	setcolor(2);
	outtextxy(cx+r*cos(i*3.14/180),cy+r*sin(i*3.14/180),"*");
	setcolor(i);
	outtextxy(40,i+30,"*");
	outtextxy(600,i+30,"*");
	outtextxy(i+140,40,"*");
	outtextxy(i+140,400,"*");
	outtextxy(290,290,"Loading");
	delay(300);
	s1++;
	}
	 floodfill(320,240,6);
	 delay(500);
	 cleardevice();
	 setcolor(4);
	 settextstyle(4,0,4);
	  outtextxy(90,220,"Enter any key to play the game");
	  nosound();
	 while(!kbhit())
	 {
	 }
	 settextstyle(1,0,1);
	 setcolor(15);
	 setbkcolor(0);
  }
