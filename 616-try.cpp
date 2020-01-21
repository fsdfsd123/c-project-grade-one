#include<iostream>
#include<stdlib.h>
#include<curses.h>
#include <windows.h>
#include<time.h>

using namespace std;
class Creature
{
		public:
			int time,py,px,g,i,j;
			bool notmove;
			int arry[25][80];
		public:
			creature()
			{
				py=0;
				px=0;
				time=0;
				for(i=0;i<=24;i++)
				{
					for(j=0;j<=79;j++)
					{
						arry[i][j]=0;
					}
				}	
			}
			creature(int y,int x)
			{
				py=y;
				px=x;
				time=0;
				for(i=0;i<=24;i++)
				{
					for(j=0;j<=79;j++)
					{
						arry[i][j]=0;
					}
				}				
			}
			virtual void clone()
			{
				
			}
			virtual void Move()
			{
				
			}
			virtual void Print()
			{
			
			}
			virtual void print()
			{
				
			}
			
};
class Producer :public Creature
{
	public:	
			Producer()
			{
				py=0;
				px=0;
				time=0;
				for(i=0;i<=24;i++)
				{
					for(j=0;j<=79;j++)
					{
						arry[i][j]=0;
					}
				}	
			}
			Producer(int y,int x)
			{
				py=y;
				px=x;
				time=0;
				for(i=0;i<=24;i++)
				{
					for(j=0;j<=79;j++)
					{
						arry[i][j]=0;
					}
				}				
			}
			void print()
			{
				mvaddch(py,px,'~');
				refresh();
			}
			void Move(int system[25][80])
			{
				int y=py;
				int x=px;
				int yy=py;
				int xx=px;
				int g;
				for(i=0;i<=24;i++)
					{
						for(j=0;j<=79;j++)
						{
							arry[i][j]=system[i][j];
						}
					}	
			
			while(1)
			{
			
					g=rand()*8;
					while(g==4)
					{
						g=rand()%8;
					}
					if(y==0&&x==0)
					{
						while(g==0||g==1||g==2||g==3||g==6)
						{
							g=rand()%8;	
						}
					}
					if(y==0&&x==79)
					{
						while(g==5||g==0||g==1||g==2||g==8)
						{
							g=rand()%8;	
						}
					}
					if(y==24&&x==79)
					{
						while(g==2||g==5||g==7||g==8||g==6)
						{
							g=rand()%8;	
						}
					}
					if(y==24&&x==0)
					{
						while(g==3||g==0||g==7||g==8||g==6)
						{
							g=rand()%8;	
						}
					}
					if(x==0)
					{
						while(g==0||g==3||g==6)
						{
							g=rand()%8;	
						}
					}
					if(x==0)
					{
						while(g==2||g==5||g==8)
						{
							g=rand()%8;	
						}
					}
					if(y==0)
					{
						while(g==0||g==1||g==2)
						{
							g=rand()%8;	
						}
					}
					if(y==24)
					{
						while(g==6||g==7||g==8)
						{
							g=rand()%8;	
						}
					}
				
					
				if(g==0&&arry[--yy][--xx]==0)
				{
					arry[y][x]==0;
					mvaddch(y,x,' ');
					y--;
					x--;
					move(y,x);
					addch('~');
					refresh();
					arry[--py][--px]==1;								
					break;
				}
				if(g==1&&arry[--yy][xx]==0)
				{
					arry[y][x]==0;
					move(y,x);
					addch(' ');
					y--;					
					move(y,x);
					addch('~');
					refresh();
					arry[--py][px]==1;	
					break;
				}
				if(g==2&&arry[--yy][++xx]==0)
				{
					
					arry[y][x]==0;
					move(y,x);
					addch(' ');
					y--;
					x++;
					move(y,x);
					addch('~');
					refresh();
					arry[--py][++px]==1;	
					break;
				}
				if(g==3&&arry[yy][--xx]==0)
				{
					arry[y][x]==0;
					move(y,x);
					addch(' ');
					x--;
					move(y,x);
					addch('~');
					refresh();
					arry[py][--px]==1;	
					break;
				}
				if(g==5&&arry[yy][++xx]==0)
				{
					arry[y][x]==0;
					move(y,x);
					addch(' ');
					x++;
					move(y,x);
					addch('~');
					refresh();
					arry[py][++px]==1;	
					break;
				}
				if(g==6&&arry[++yy][--xx]==0)
				{
					arry[y][x]==0;
					move(y,x);
					addch(' ');
					y++;
					x--;
					move(y,x);
					addch('~');
					refresh();
					arry[++py][--px]==1;	
					break;
				}
				
	 			if(g==7&&arry[++yy][xx]==0)
	 			{
	 				arry[y][x]==0;
	 				move(y,x);
	 				addch(' ');
	 				refresh();
					y++;
					move(y,x);
					addch('~');
					refresh();
					arry[++py][px]==1;	
					break;
	 			}
	 			if(g==8&&arry[++yy][++xx]==0)
	 			{
	 				arry[y][x]==0;
	 				move(y,x);
	 				addch(' ');
	 				refresh();
					x++;
					y++;
					move(y,x);
					addch('~');
					refresh();
					arry[++py][px]==1;	
					break;
				}
			if(arry[++yy][++xx]!=0||arry[++yy][xx]!=0||arry[yy][++xx]!=0||
					arry[yy][xx]!=0||
				arry[--yy][xx]!=0||arry[yy][--xx]!=0||arry[--yy][--xx]!=0
				)
				{
					notmove=1;
					break;
				}
					
			}
		}
	
};
class Consumer :public Creature
{
	public:
		int eat;
		Consumer()
			{
				eat=0;
				py=0;
				px=0;
				time=0;
				for(i=0;i<=24;i++)
				{
					for(j=0;j<=79;j++)
					{
						arry[i][j]=0;
					}
				}	
			}
			Consumer(int y,int x)
			{
				eat=0;
				py=y;
				px=x;
				time=0;
				for(i=0;i<=24;i++)
				{
					for(j=0;j<=79;j++)
					{
						arry[i][j]=0;
					}
				}				
			}
			void print()
			{
				mvaddch(py,px,'@');
				refresh();
			}
			void Move(int system[25][80])
			{
				int y=py;
				int x=px;
				int yy=py;
				int xx=px;
				int g;
				for(i=0;i<=24;i++)
				{
					for(j=0;j<=79;j++)
					{
						arry[i][j]=system[i][j];
					}
				}
			
			while(1){
		
			
					g=rand()*8;
					while(g==4)
					{
						g=rand()%8;
					}
					if(y==0&&x==0)
					{
						while(g==0||g==1||g==2||g==3||g==6)
						{
							g=rand()%8;	
						}
					}
					if(y==0&&x==79)
					{
						while(g==5||g==0||g==1||g==2||g==8)
						{
							g=rand()%8;	
						}
					}
					if(y==24&&x==79)
					{
						while(g==2||g==5||g==7||g==8||g==6)
						{
							g=rand()%8;	
						}
					}
					if(y==24&&x==0)
					{
						while(g==3||g==0||g==7||g==8||g==6)
						{
							g=rand()%8;	
						}
					}
					if(x==0)
					{
						while(g==0||g==3||g==6)
						{
							g=rand()%8;	
						}
					}
					if(x==0)
					{
						while(g==2||g==5||g==8)
						{
							g=rand()%8;	
						}
					}
					if(y==0)
					{
						while(g==0||g==1||g==2)
						{
							g=rand()%8;	
						}
					}
					if(y==24)
					{
						while(g==6||g==7||g==8)
						{
							g=rand()%8;	
						}
					}
				
					
				if(g==0&&arry[--yy][--xx]==0)
				{
					arry[y][x]==0;
					move(y,x);
					addch(' ');
					y--;
					x--;
					move(y,x);
					addch('@');
					refresh();
					arry[--py][--px]==9;								
					break;
				}
				if(g==1&&arry[--yy][xx]==0)
				{
					arry[y][x]==0;
					move(y,x);
					addch(' ');
					y--;					
					move(y,x);
					addch('@');
					refresh();
					arry[--py][px]==9;	
					break;
				}
				if(g==2&&arry[--yy][++xx]==0)
				{
					
					arry[y][x]==0;
					move(y,x);
					addch(' ');
					y--;
					x++;
					move(y,x);
					addch('@');
					refresh();
					arry[--py][++px]==9;	
					break;
				}
				if(g==3&&arry[yy][--xx]==0)
				{
					arry[y][x]==0;
					move(y,x);
					addch(' ');
					x--;
					move(y,x);
					addch('@');
					refresh();
					arry[py][--px]==9;	
					break;
				}
				if(g==5&&arry[yy][++xx]==0)
				{
					arry[y][x]==0;
					move(y,x);
					addch(' ');
					x++;
					move(y,x);
					addch('@');
					refresh();
					arry[py][++px]==9;	
					break;
				}
				if(g==6&&arry[++yy][--xx]==0)
				{
					arry[y][x]==0;
					move(y,x);
					addch(' ');
					y++;
					x--;
					move(y,x);
					addch('@');
					refresh();
					arry[++py][--px]==9;	
					break;
				}
				
	 			if(g==7&&arry[++yy][xx]==0)
	 			{
	 				arry[y][x]==0;
	 				move(y,x);
	 				addch(' ');
	 				refresh();
					y++;
					move(y,x);
					addch('@');
					refresh();
					arry[++py][px]==9;	
					break;
	 			}
	 			if(g==8&&arry[++yy][++xx]==0)
	 			{
	 				arry[y][x]==0;
	 				move(y,x);
	 				addch(' ');
	 				refresh();
					x++;
					y++;
					move(y,x);
					addch('@');
					refresh();
					arry[++py][px]==9;	
					break;
				}
				if(arry[++yy][++xx]!=0||arry[++yy][xx]!=0||arry[yy][++xx]!=0||arry[yy][xx]!=0||arry[--yy][xx]!=0||arry[yy][--xx]!=0||arry[--yy][--xx]!=0)
				{
					notmove=1;
					break;
				}
					
			}
		}
	
};
main()
{

	int a1,a2,i,j,k,g;
	int system[25][80];
	cout<<"cin intial producer and consumer number "<<endl;
	cin>>a1>>a2;
	initscr();
	int pnumber=a1,cnumber=a2;
	Producer*fsd=new Producer[25*80];
	Consumer*fyx=new Consumer[25*80];
	for(i=0;i<=a1-1;i++)
	{
		fsd[i];
	}
	for(i=0;i<=a2-1;i++)
	{
		fyx[i];
	}
	for(i=0;i<=24;i++)
	{
		for(j=0;j<=79;j++)
		{
			system[i][j]=0;
		}
	}
	fsd[0].px=rand()%80;
	fsd[0].py=rand()%25;
	fyx[0].px=rand()%80;
	fyx[0].py=rand()%25;
	bool qwe=1;
	for(i=1,j=1;i<=a1-1,j<=a2-1;i++,j++)
	{
		fsd[i].py=rand()%80;
		fsd[i].px=rand()%25;
		fyx[j].py=rand()%80;
		fyx[j].px=rand()%25;
		while(1)
		{
			for(int k=0;k<=i;k++)
			{
				if(fsd[i].py==fsd[k].py||fsd[i].px==fsd[k].px)
				qwe=0;
			}
			for(int k=0;k<=j;k++)
			{
				if(fyx[j].py==fyx[k].py||fyx[j].px==fyx[k].px)
				qwe=0;
			}
			if(qwe=0)
			{
				fsd[i].py=rand()%80;
				fsd[i].px=rand()%80;
				fyx[j].py=rand()%80;
				fyx[j].px=rand()%25;
			}
			if(qwe=1)
			break;
		}
	}
	for(i=0;i<=pnumber-1;i++)
	{
		system[fsd[i].py][fsd[i].px]=1;
	}
	for(i=0;i<=cnumber-1;i++)
	{
		system[fyx[i].py][fyx[i].px]=9;
	}
	for(i=0;i<=pnumber-1;i++)
	{
		fsd[i].print();
	}
	for(i=0;i<=cnumber-1;i++)
	{
		fyx[i].print();
	}
	Sleep(3000);
	while(1)
	{	
		for(i=0,j=0;i<=pnumber-1,j<=cnumber-1;i++,j++)
		{
			int lastx=fsd[i].px;
			int lasty=fsd[i].py;
			fsd[i].Move(system);
			fsd[i].time++;
			fsd[i].print();
			if(fsd[i].notmove==0)
			{				
				system[lasty][lastx]=0;
				system[fsd[i].py][fsd[i].px]=1;							
			}
			if(fsd[i].time%3==0)
			{
					pnumber++;
					fsd[pnumber-1]=Producer (lasty,lastx);
					system[lasty][lastx]=1;				
					fsd[pnumber-1].print();
			}
			lastx=fyx[j].px;
			lasty=fyx[j].py;
			fyx[j].Move(system);
			fyx[j].time++;
			fyx[j].print();
			if(fsd[j].notmove==0)
			{	
				if(system[fyx[j].py][fyx[j].px]==1)
				{
					system[fyx[j].py][fyx[j].px]=9;
					pnumber--;
					int eatten;
					for(k=0;k<=pnumber-1;k++)
					{
						if(fsd[k].py==fyx[j].py&&fsd[k].px==fyx[j].px);
						eatten=k;
					}
					for(k=eatten;k<=pnumber-1;k++)
					{
						fsd[k]=fsd[k+1];
					}
					cnumber++;
					fyx[cnumber-1]=Consumer (lasty,lastx);
					system[lasty][lastx]=9;
					fyx[cnumber-1].print();
					fyx[j].eat++;
				}
				if(fyx[j].time%3==0)
				{					
					if(fyx[j].eat==0)
					{
						system[lasty][lastx]=0;					
						for(k=j;k<=cnumber-1;k++)
						{
							fyx[j]=fyx[j+1];
						}
					}
				}
			}
			Sleep(100);
			refresh();
		}
		Sleep(100);
		refresh();
	}
	endwin();
}

