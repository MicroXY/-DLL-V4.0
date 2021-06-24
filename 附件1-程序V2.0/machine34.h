#include "snake.h"
using namespace std;

static int  flag34=0;
static int  flag_point_wall34=0;
static point point_wall34={0,0};

struct ex_point34
{
	int x;
	int y;
	int cost;
	int special;
	int next_dirction;
};

class Queue34
{
public:
	Queue34(int s=1800)
	{
		size=s;
		q=new point[size];
		front=tail=0;
	}
    int isfull(void)
	{
		if (tail==size)
		{
			return 1;
		}
		else
			return 0;
	}
	point pop(void)
	{
		if (!isempty())
		{
			return q[front++];
		}
		else
		{
		    printf("error\n");
		    point temp;
		    temp.x=-100;
		    temp.y=-100;
			return temp;
		}
	}

	void push(point item)
	{
		if (!isfull())
		{
			q[tail++]=item;
		}
		else
		{
			size=size*2;
			point* temp=new point[size];
			for (int i = 0; i < size/2; ++i)
			{
				temp[i]=q[i];
			}
			delete[] q;
			q=temp;
			q[tail++]=item;
		}
	}

	int isempty(void)
	{
		if (front==tail)
		{
			return 1;
		}
		else
			return 0;
	}

	~Queue34()
	{
		delete[] q;
	}
	void init()
	{
		front=0;
		tail=0;
	}
private:
	int size;
	int front;
	int tail;
	point* q;
};
Queue34 q34;

int checkoutofboard34(int x,int y,int n,int m)
{
	if (x==0 || y<2 || x==n+1 || y>m)
	{
		return 0;
	}
	return 1;
}

bool check34(point snake[5][100], int len[5], int t, GamePanel gp, int direction )
{
	//将你的check函数体放在此处，并删去下面示例代码
	int snake_0_len=len[0];
	int snake_1_len=len[1];
	point head;
	head.x=snake[t][1].x;
	head.y=snake[t][1].y;
	switch(direction)
	{
		//下
		case 0:
		{
			if (checkoutofboard34(head.x+1,head.y,gp.n,gp.m)==0)
			{
				return false;
			}
			if (gp.panel[head.x+1][head.y]==2)
			{
				return false;
			}
			for (int i = 1; i < snake_0_len; ++i)
			{
				if (snake[0][i].x==head.x+1  &&  snake[0][i].y==head.y)
				{
					return false;
				}
			}
			for (int i = 1; i < snake_1_len; ++i)
			{
				if (snake[1][i].x==head.x+1  &&  snake[1][i].y==head.y)
				{
					return false;
				}
			}
			if (t==0 && snake[1][snake_1_len].x==head.x+1 && snake[1][snake_1_len].y==head.y)
			{
				return false;
			}
			if (t==1 && snake[0][snake_0_len].x==head.x+1 && snake[0][snake_0_len].y==head.y)
			{
				return false;
			}
			return true;
			break;
		}
		//右
		case 1:
		{
			if (checkoutofboard34(head.x,head.y+2,gp.n,gp.m)==0)
			{
				return false;
			}
			if (gp.panel[head.x][head.y+2]==2)
			{
				return false;
			}
			for (int i = 1; i < snake_0_len; ++i)
			{
				if (snake[0][i].x==head.x  &&  snake[0][i].y==head.y+2)
				{
					return false;
				}
			}
			for (int i = 1; i < snake_1_len; ++i)
			{
				if (snake[1][i].x==head.x  &&  snake[1][i].y==head.y+2)
				{
					return false;
				}
			}
			if (t==0 && snake[1][snake_1_len].x==head.x && snake[1][snake_1_len].y==head.y+2)
			{
				return false;
			}
			if (t==1 && snake[0][snake_0_len].x==head.x && snake[0][snake_0_len].y==head.y+2)
			{
				return false;
			}
			return true;
			break;
		}
		// 左
		case 2:
		{
			if (checkoutofboard34(head.x,head.y-2,gp.n,gp.m)==0)
			{
				return false;
			}
			if (gp.panel[head.x][head.y-2]==2)
			{
				return false;
			}
			for (int i = 1; i < snake_0_len; ++i)
			{
				if (snake[0][i].x==head.x  &&  snake[0][i].y==head.y-2)
				{
					return false;
				}
			}
			for (int i = 1; i < snake_1_len; ++i)
			{
				if (snake[1][i].x==head.x  &&  snake[1][i].y==head.y-2)
				{
					return false;
				}
			}
			if (t==0 && snake[1][snake_1_len].x==head.x && snake[1][snake_1_len].y==head.y-2)
			{
				return false;
			}
			if (t==1 && snake[0][snake_0_len].x==head.x && snake[0][snake_0_len].y==head.y-2)
			{
				return false;
			}
			return true;

			break;
		}
		// 上
		case 3:
		{
			//越界检查
			if (checkoutofboard34(head.x-1,head.y,gp.n,gp.m)==0)
			{
				return false;
			}
			if (gp.panel[head.x-1][head.y]==2)
			{
				return false;
			}

			for (int i = 1; i < snake_0_len; ++i)
			{
				if (snake[0][i].x==head.x-1  &&  snake[0][i].y==head.y)
				{
					return false;
				}
			}
			for (int i = 1; i < snake_1_len; ++i)
			{
				if (snake[1][i].x==head.x-1  &&  snake[1][i].y==head.y)
				{
					return false;
				}
			}
			if (t==0 && snake[1][snake_1_len].x==head.x-1 && snake[1][snake_1_len].y==head.y)
			{
				return false;
			}
			if (t==1 && snake[0][snake_0_len].x==head.x-1 && snake[0][snake_0_len].y==head.y)
			{
				return false;
			}
			return true;

			break;
		}
		// 下右
		case 4:
		{
			//越界检查
			if (checkoutofboard34(head.x+1,head.y+2,gp.n,gp.m)==0)
			{
				return false;
			}
			// 不是墙
			if (gp.panel[head.x+1][head.y+2]==2)
			{
				return false;
			}
			// 是不是蛇身子
			for (int i = 1; i < snake_0_len; ++i)
			{
				if (snake[0][i].x==head.x+1  &&  snake[0][i].y==head.y+2)
				{
					return false;
				}
			}
			for (int i = 1; i < snake_1_len; ++i)
			{
				if (snake[1][i].x==head.x+1  &&  snake[1][i].y==head.y+2)
				{
					return false;
				}
			}
			if (t==0 && snake[1][snake_1_len].x==head.x+1 && snake[1][snake_1_len].y==head.y+2)
			{
				return false;
			}
			if (t==1 && snake[0][snake_0_len].x==head.x+1 && snake[0][snake_0_len].y==head.y+2)
			{
				return false;
			}
			//斜着走跨越自己的身子或敌人的身子
			int flag1=0;
			int flag2=0;
			int temp=0;
			if (t==0)
			{
				temp=1;
			}
			//自己的蛇身子
			for (int i = 1; i <= len[t]; ++i)
			{
				if (snake[t][i].x==head.x+1 && snake[t][i].y==head.y )
				{
					flag1=1;
				}
				if (snake[t][i].x==head.x   && snake[t][i].y==head.y+2)
				{
					flag2=1;
				}
			}
			if(flag1==1 && flag2==1)
			{
				return false;
			}
			if (snake[t][len[t]].x==head.x+1 && snake[t][len[t]].y==head.y )
			{
				flag1=0;
			}
			if (snake[t][len[t]].x==head.x && snake[t][len[t]].y==head.y+2 )
			{
				flag2=0;
			}
			for (int i = 1; i <= len[temp]; ++i)
			{
				if (snake[temp][i].x==head.x+1 && snake[temp][i].y==head.y )
				{
					flag1=1;
				}
				if (snake[temp][i].x==head.x   && snake[temp][i].y==head.y+2 )
				{
					flag2=1;
				}
			}
			if (gp.panel[head.x+1][head.y]==2)
			{
				flag1=1;
			}
			if (gp.panel[head.x][head.y+2]==2)
			{
				flag2=1;
			}
			if (flag1==1 && flag2==1)
			{
				return false;
			}
			//只有一个一
			if (flag1==1)
			{
				if (gp.panel[head.x+1][head.y+2]==1 && (snake[t][len[t]].x==head.x && snake[t][len[t]].y==head.y+2 ))
				{
					return false;
				}
			}
			if (flag2==1)
			{
				if (gp.panel[head.x+1][head.y+2]==1 && (snake[t][len[t]].x==head.x+1 && snake[t][len[t]].y==head.y ))
				{
					return false;
				}
			}
			return true;
			break;
		}
		// 上右
		case 5:
		{
			//越界检查
			if (checkoutofboard34(head.x-1,head.y+2,gp.n,gp.m)==0)
			{
				return false;
			}
			// 不是墙
			if (gp.panel[head.x-1][head.y+2]==2)
			{
				return false;
			}
			// 是不是蛇身子
			for (int i = 1; i < snake_0_len; ++i)
			{
				if (snake[0][i].x==head.x-1  &&  snake[0][i].y==head.y+2)
				{
					return false;
				}
			}
			for (int i = 1; i < snake_1_len; ++i)
			{
				if (snake[1][i].x==head.x-1  &&  snake[1][i].y==head.y+2)
				{
					return false;
				}
			}
			if (t==0 && snake[1][snake_1_len].x==head.x-1 && snake[1][snake_1_len].y==head.y+2)
			{
				return false;
			}
			if (t==1 && snake[0][snake_0_len].x==head.x-1 && snake[0][snake_0_len].y==head.y+2)
			{
				return false;
			}
			//斜着走跨越自己的身子或敌人的身子
			int flag1=0;
			int flag2=0;
			int temp=0;
			if (t==0)
			{
				temp=1;
			}
			//自己的蛇身子
			for (int i = 1; i <= len[t]; ++i)
			{
				if (snake[t][i].x==head.x-1 && snake[t][i].y==head.y )
				{
					flag1=1;
				}
				if (snake[t][i].x==head.x   && snake[t][i].y==head.y+2)
				{
					flag2=1;
				}
			}
			if(flag1==1 && flag2==1)
			{
				return false;
			}
			if (snake[t][len[t]].x==head.x-1 && snake[t][len[t]].y==head.y )
			{
				flag1=0;
			}
			if (snake[t][len[t]].x==head.x && snake[t][len[t]].y==head.y+2 )
			{
				flag2=0;
			}
			for (int i = 1; i <= len[temp]; ++i)
			{
				if (snake[temp][i].x==head.x-1 && snake[temp][i].y==head.y )
				{
					flag1=1;
				}
				if (snake[temp][i].x==head.x   && snake[temp][i].y==head.y+2 )
				{
					flag2=1;
				}
			}
			if (gp.panel[head.x-1][head.y]==2)
			{
				flag1=1;
			}
			if (gp.panel[head.x][head.y+2]==2)
			{
				flag2=1;
			}
			if (flag1==1 && flag2==1)
			{
				return false;
			}
			//只有一个一
			if (flag1==1)
			{
				if (gp.panel[head.x-1][head.y+2]==1 && (snake[t][len[t]].x==head.x && snake[t][len[t]].y==head.y+2 ))
				{
					return false;
				}
			}
			if (flag2==1)
			{
				if (gp.panel[head.x-1][head.y+2]==1 && (snake[t][len[t]].x==head.x-1 && snake[t][len[t]].y==head.y ))
				{
					return false;
				}
			}
			return true;
			break;
		}
		// 上左
		case 6:
		{
			//越界检查
			if (checkoutofboard34(head.x-1,head.y-2,gp.n,gp.m)==0)
			{
				return false;
			}
			// 不是墙
			if (gp.panel[head.x-1][head.y-2]==2)
			{
				return false;
			}
			// 是不是蛇身子
			for (int i = 1; i < snake_0_len; ++i)
			{
				if (snake[0][i].x==head.x-1  &&  snake[0][i].y==head.y-2)
				{
					return false;
				}
			}
			for (int i = 1; i < snake_1_len; ++i)
			{
				if (snake[1][i].x==head.x-1  &&  snake[1][i].y==head.y-2)
				{
					return false;
				}
			}
			if (t==0 && snake[1][snake_1_len].x==head.x-1 && snake[1][snake_1_len].y==head.y-2)
			{
				return false;
			}
			if (t==1 && snake[0][snake_0_len].x==head.x-1 && snake[0][snake_0_len].y==head.y-2)
			{
				return false;
			}
			//斜着走跨越自己的身子或敌人的身子
			int flag1=0;
			int flag2=0;
			int temp=0;
			if (t==0)
			{
				temp=1;
			}
			//自己的蛇身子
			for (int i = 1; i <= len[t]; ++i)
			{
				if (snake[t][i].x==head.x-1 && snake[t][i].y==head.y )
				{
					flag1=1;
				}
				if (snake[t][i].x==head.x   && snake[t][i].y==head.y-2)
				{
					flag2=1;
				}
			}
			if(flag1==1 && flag2==1)
			{
				return false;
			}
			if (snake[t][len[t]].x==head.x-1 && snake[t][len[t]].y==head.y )
			{
				flag1=0;
			}
			if (snake[t][len[t]].x==head.x && snake[t][len[t]].y==head.y-2 )
			{
				flag2=0;
			}
			for (int i = 1; i <= len[temp]; ++i)
			{
				if (snake[temp][i].x==head.x-1 && snake[temp][i].y==head.y )
				{
					flag1=1;
				}
				if (snake[temp][i].x==head.x   && snake[temp][i].y==head.y-2 )
				{
					flag2=1;
				}
			}
			if (gp.panel[head.x-1][head.y]==2)
			{
				flag1=1;
			}
			if (gp.panel[head.x][head.y-2]==2)
			{
				flag2=1;
			}
			if (flag1==1 && flag2==1)
			{
				return false;
			}
			//只有一个一
			if (flag1==1)
			{
				if (gp.panel[head.x-1][head.y-2]==1 && (snake[t][len[t]].x==head.x && snake[t][len[t]].y==head.y-2 ))
				{
					return false;
				}
			}
			if (flag2==1)
			{
				if (gp.panel[head.x-1][head.y-2]==1 && (snake[t][len[t]].x==head.x-1 && snake[t][len[t]].y==head.y ))
				{
					return false;
				}
			}
			return true;
			break;
		}
		// 下左
		case 7 :
		{
			//越界检查
			if (checkoutofboard34(head.x+1,head.y-2,gp.n,gp.m)==0)
			{
				return false;
			}
			// 不是墙
			if (gp.panel[head.x+1][head.y-2]==2)
			{
				return false;
			}
			// 是不是蛇身子
			for (int i = 1; i < snake_0_len; ++i)
			{
				if (snake[0][i].x==head.x+1  &&  snake[0][i].y==head.y-2)
				{
					return false;
				}
			}
			for (int i = 1; i < snake_1_len; ++i)
			{
				if (snake[1][i].x==head.x+1  &&  snake[1][i].y==head.y-2)
				{
					return false;
				}
			}
			if (t==0 && snake[1][snake_1_len].x==head.x+1 && snake[1][snake_1_len].y==head.y-2)
			{
				return false;
			}
			if (t==1 && snake[0][snake_0_len].x==head.x+1 && snake[0][snake_0_len].y==head.y-2)
			{
				return false;
			}
			//斜着走跨越自己的身子或敌人的身子
			int flag1=0;
			int flag2=0;
			int temp=0;
			if (t==0)
			{
				temp=1;
			}
			//自己的蛇身子
			for (int i = 1; i <= len[t]; ++i)
			{
				if (snake[t][i].x==head.x+1 && snake[t][i].y==head.y )
				{
					flag1=1;
				}
				if (snake[t][i].x==head.x   && snake[t][i].y==head.y-2)
				{
					flag2=1;
				}
			}
			if(flag1==1 && flag2==1)
			{
				return false;
			}
			if (snake[t][len[t]].x==head.x+1 && snake[t][len[t]].y==head.y )
			{
				flag1=0;
			}
			if (snake[t][len[t]].x==head.x && snake[t][len[t]].y==head.y-2 )
			{
				flag2=0;
			}
			for (int i = 1; i <= len[temp]; ++i)
			{
				if (snake[temp][i].x==head.x+1 && snake[temp][i].y==head.y )
				{
					flag1=1;
				}
				if (snake[temp][i].x==head.x   && snake[temp][i].y==head.y-2 )
				{
					flag2=1;
				}
			}
			if (gp.panel[head.x+1][head.y]==2)
			{
				flag1=1;
			}
			if (gp.panel[head.x][head.y-2]==2)
			{
				flag2=1;
			}
			if (flag1==1 && flag2==1)
			{
				return false;
			}
			//只有一个一
			if (flag1==1)
			{
				if (gp.panel[head.x+1][head.y-2]==1 && (snake[t][len[t]].x==head.x && snake[t][len[t]].y==head.y-2 ))
				{
					return false;
				}
			}
			if (flag2==1)
			{
				if (gp.panel[head.x+1][head.y-2]==1 && (snake[t][len[t]].x==head.x+1 && snake[t][len[t]].y==head.y ))
				{
					return false;
				}
			}
			return true;
			break;
		}
	}
	return true;
}

int check_is_safe34(point snake[5][100],int len[5],int t,GamePanel gp,int direction)
{
	//如果下一步是蛇尾巴，安全
	for (int i = 1; i < len[t]; ++i)
	{
		gp.panel[snake[t][i].x][snake[t][i].y]=2;
	}
	for (int i = 1; i <= len[!t]; ++i)
	{
		gp.panel[snake[!t][i].x][snake[!t][i].y]=2;
	}
	point head=snake[t][1];

	switch(direction)
	{
		case 0:head.x+=1 ;          ;if(head.x==snake[t][len[t]].x && head.y==snake[t][len[t]].y ) return 1; gp.panel[head.x][head.y]=2; break;
		case 1:          ;head.y+=2 ;if(head.x==snake[t][len[t]].x && head.y==snake[t][len[t]].y ) return 1; gp.panel[head.x][head.y]=2; break;
		case 2:          ;head.y-=2 ;if(head.x==snake[t][len[t]].x && head.y==snake[t][len[t]].y ) return 1; gp.panel[head.x][head.y]=2; break;
		case 3:head.x-=1 ;          ;if(head.x==snake[t][len[t]].x && head.y==snake[t][len[t]].y ) return 1; gp.panel[head.x][head.y]=2; break;
		case 4:head.x+=1 ;head.y+=2 ;if(head.x==snake[t][len[t]].x && head.y==snake[t][len[t]].y ) return 1; gp.panel[head.x][head.y]=2; break;
		case 5:head.x-=1 ;head.y+=2 ;if(head.x==snake[t][len[t]].x && head.y==snake[t][len[t]].y ) return 1; gp.panel[head.x][head.y]=2; break;
		case 6:head.x-=1 ;head.y-=2 ;if(head.x==snake[t][len[t]].x && head.y==snake[t][len[t]].y ) return 1; gp.panel[head.x][head.y]=2; break;
		case 7:head.x+=1 ;head.y-=2 ;if(head.x==snake[t][len[t]].x && head.y==snake[t][len[t]].y ) return 1; gp.panel[head.x][head.y]=2; break;
	}
	//如果不是蛇尾巴，从下一步开始寻找蛇尾巴，找到就是安全，否则不安全
	point temp_pp;
	q34.init();
	//上
	if (checkoutofboard34(head.x-1,head.y,gp.n,gp.m)==1 && gp.panel[head.x-1][head.y]!=2 && gp.panel[head.x-1][head.y]!=-2)
	{
		temp_pp.x=head.x-1;
		temp_pp.y=head.y  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=-2;
	}
	//下
	if (checkoutofboard34(head.x+1,head.y,gp.n,gp.m)==1 && gp.panel[head.x+1][head.y]!=2 && gp.panel[head.x+1][head.y]!=-2)
	{
		temp_pp.x=head.x+1;
		temp_pp.y=head.y  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=-2;
	}
	//左
	if (checkoutofboard34(head.x,head.y-2,gp.n,gp.m)==1 && gp.panel[head.x][head.y-2]!=2 && gp.panel[head.x][head.y-2]!=-2)
	{
		temp_pp.x=head.x;
		temp_pp.y=head.y-2  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=-2;
	}
	//右
	if (checkoutofboard34(head.x,head.y+2,gp.n,gp.m)==1 && gp.panel[head.x][head.y+2]!=2 && gp.panel[head.x][head.y+2]!=-2)
	{
		temp_pp.x=head.x;
		temp_pp.y=head.y+2  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=-2;
	}
	point t_temp;
	while(!q34.isempty())
	{
		temp_pp=q34.pop();
		if (snake[t][len[t]].x==temp_pp.x && snake[t][len[t]].y==temp_pp.y )
		{
			return 1;
		}
		//上
		if (checkoutofboard34(temp_pp.x-1,temp_pp.y,gp.n,gp.m)==1 && gp.panel[temp_pp.x-1][temp_pp.y]!=2 && gp.panel[temp_pp.x-1][temp_pp.y]!=-2)
		{
			t_temp.x=temp_pp.x-1;
			t_temp.y=temp_pp.y  ;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=-2;
		}
		//下
		if (checkoutofboard34(temp_pp.x+1,temp_pp.y,gp.n,gp.m)==1 && gp.panel[temp_pp.x+1][temp_pp.y]!=2 && gp.panel[temp_pp.x+1][temp_pp.y]!=-2)
		{
			t_temp.x=temp_pp.x+1;
			t_temp.y=temp_pp.y  ;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=-2;
		}
		//左
		if (checkoutofboard34(temp_pp.x,temp_pp.y-2,gp.n,gp.m)==1 && gp.panel[temp_pp.x][temp_pp.y-2]!=2 && gp.panel[temp_pp.x][temp_pp.y-2]!=-2)
		{
			t_temp.x=temp_pp.x;
			t_temp.y=temp_pp.y-2;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=-2;
		}
		//右
		if (checkoutofboard34(temp_pp.x,temp_pp.y+2,gp.n,gp.m)==1 && gp.panel[temp_pp.x][temp_pp.y+2]!=2 && gp.panel[temp_pp.x][temp_pp.y+2]!=-2)
		{
			t_temp.x=temp_pp.x;
			t_temp.y=temp_pp.y+2  ;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=-2;
		}

	}
	return 0;
}

ex_point34* init_array34(GamePanel gp,int& len)
{
	int temp_num=gp.currentfoodnum;
	if (gp.speednum!=0 &&gp.panel[gp.speedprops.x][gp.speedprops.y]==3)
	{
		temp_num++;
	}
	if (gp.obliquenum!=0 &&gp.panel[gp.obliqueprops[0].x][gp.obliqueprops[0].y]==4)
	{
		temp_num++;
	}
	if (gp.obliquenum!=0 &&gp.panel[gp.obliqueprops[1].x][gp.obliqueprops[1].y]==4)
	{
		temp_num++;
	}
	int front=0;
	ex_point34* temp_array=new ex_point34[temp_num];
	for (int i = 0; i < gp.totalfoodnum; ++i)
	{
		if (gp.panel[gp.food[i].x][gp.food[i].y]==1)
		{
			temp_array[front].x=gp.food[i].x;
			temp_array[front].y=gp.food[i].y;
			temp_array[front].cost=10000;
			temp_array[front].special=0;
			temp_array[front].next_dirction=-1;
			front++;
		}
	}
	if (gp.speednum!=0 &&gp.panel[gp.speedprops.x][gp.speedprops.y]==3)
	{
		temp_array[front].x=gp.speedprops.x;
		temp_array[front].y=gp.speedprops.y;
		temp_array[front].cost=10000;
		temp_array[front].special=1;
		temp_array[front].next_dirction=-1;
		front++;
	}
	if (gp.obliquenum!=0 &&gp.panel[gp.obliqueprops[0].x][gp.obliqueprops[0].y]==4)
	{
		temp_array[front].x=gp.obliqueprops[0].x;
		temp_array[front].y=gp.obliqueprops[0].y;
		temp_array[front].cost=10000;
		temp_array[front].special=2;
		temp_array[front].next_dirction=-1;
		front++;
	}
	if (gp.obliquenum!=0 &&gp.panel[gp.obliqueprops[1].x][gp.obliqueprops[1].y]==4)
	{
		temp_array[front].x=gp.obliqueprops[1].x;
		temp_array[front].y=gp.obliqueprops[1].y;
		temp_array[front].cost=10000;
		temp_array[front].special=2;
		temp_array[front].next_dirction=-1;
		front++;
	}
	len=temp_num;
	return temp_array;
}

void cacl_dirction34(point snake[5][100], int len[5], ex_point34 array[] ,int array_len, int t, GamePanel gp)
{
	for (int i = 1; i <= len[t]-1; ++i)
	{
		gp.panel[snake[t][i].x][snake[t][i].y]=2;
	}
	for (int i = 1; i <= len[!t]; ++i)
	{
		gp.panel[snake[!t][i].x][snake[!t][i].y]=2;
	}
	point temp_pp;
	q34.init();
	//上
	if (checkoutofboard34(snake[t][1].x-1,snake[t][1].y,gp.n,gp.m)==1 && gp.panel[snake[t][1].x-1][snake[t][1].y]!=2 && gp.panel[snake[t][1].x-1][snake[t][1].y]<10)
	{
		temp_pp.x=snake[t][1].x-1;
		temp_pp.y=snake[t][1].y  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
	}
	//下
	if (checkoutofboard34(snake[t][1].x+1,snake[t][1].y,gp.n,gp.m)==1 && gp.panel[snake[t][1].x+1][snake[t][1].y]!=2 && gp.panel[snake[t][1].x+1][snake[t][1].y]<10)
	{
		temp_pp.x=snake[t][1].x+1;
		temp_pp.y=snake[t][1].y  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
	}
	//左
	if (checkoutofboard34(snake[t][1].x,snake[t][1].y-2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x][snake[t][1].y-2]!=2 && gp.panel[snake[t][1].x][snake[t][1].y-2]<10)
	{
		temp_pp.x=snake[t][1].x;
		temp_pp.y=snake[t][1].y-2  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
	}
	//右
	if (checkoutofboard34(snake[t][1].x,snake[t][1].y+2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x][snake[t][1].y+2]!=2 && gp.panel[snake[t][1].x][snake[t][1].y+2]<10)
	{
		temp_pp.x=snake[t][1].x;
		temp_pp.y=snake[t][1].y+2  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
	}
	if (gp.obliqueowner[t]==1 )
	{
		//左上
		if (checkoutofboard34(snake[t][1].x-1,snake[t][1].y-2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x-1][snake[t][1].y-2]!=2 && gp.panel[snake[t][1].x-1][snake[t][1].y-2]<10)
		{
			temp_pp.x=snake[t][1].x-1;
			temp_pp.y=snake[t][1].y-2 ;
			q34.push(temp_pp);
			gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
		}
		//左下
		if (checkoutofboard34(snake[t][1].x+1,snake[t][1].y-2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x+1][snake[t][1].y-2]!=2 && gp.panel[snake[t][1].x+1][snake[t][1].y-2]<10)
		{
			temp_pp.x=snake[t][1].x+1;
			temp_pp.y=snake[t][1].y-2  ;
			q34.push(temp_pp);
			gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
		}
		//右上
		if (checkoutofboard34(snake[t][1].x-1,snake[t][1].y+2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x-1][snake[t][1].y+2]!=2 && gp.panel[snake[t][1].x-1][snake[t][1].y+2]<10)
		{
			temp_pp.x=snake[t][1].x-1;
			temp_pp.y=snake[t][1].y+2 ;
			q34.push(temp_pp);
			gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
		}
		//右下
		if (checkoutofboard34(snake[t][1].x+1,snake[t][1].y+2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x+1][snake[t][1].y+2]!=2 && gp.panel[snake[t][1].x+1][snake[t][1].y+2]<10)
		{
			temp_pp.x=snake[t][1].x+1;
			temp_pp.y=snake[t][1].y+2;
			q34.push(temp_pp);
			gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
		}

	}
	point t_temp;
	while(!q34.isempty())
	{
		temp_pp=q34.pop();
		for (int i = 0; i < array_len; ++i)
		{
			if (array[i].x==temp_pp.x && array[i].y==temp_pp.y )
			{
				int dir=1;
				int m_x=temp_pp.x;
				int m_y=temp_pp.y;
				int f_x=gp.panel[m_x][m_y]/100;
				int f_y=gp.panel[m_x][m_y]%100;
				while(!(f_x==snake[t][1].x && f_y==snake[t][1].y) )
				{
					dir++;
					m_x=f_x;
					m_y=f_y;
					f_x=gp.panel[m_x][m_y]/100;
					f_y=gp.panel[m_x][m_y]%100;
				}
				//上
				if ( snake[t][1].x-1==m_x && snake[t][1].y==m_y )
				{
					array[i].next_dirction=3;
					array[i].cost=dir;
				}
				//下
				if ( snake[t][1].x+1==m_x && snake[t][1].y==m_y )
				{
					array[i].next_dirction=0;
					array[i].cost=dir;
				}
				//左
				if ( snake[t][1].x==m_x && snake[t][1].y-2==m_y )
				{
					array[i].next_dirction=2;
					array[i].cost=dir;
				}
				//右
				if ( snake[t][1].x==m_x && snake[t][1].y+2==m_y )
				{
					array[i].next_dirction=1;
					array[i].cost=dir;
				}

				//上左
				if ( snake[t][1].x-1==m_x && snake[t][1].y-2==m_y )
				{
					array[i].next_dirction=6;
					array[i].cost=dir;
				}
				//上右
				if ( snake[t][1].x-1==m_x && snake[t][1].y+2==m_y )
				{
					array[i].next_dirction=5;
					array[i].cost=dir;
				}
				//下左
				if ( snake[t][1].x+1==m_x && snake[t][1].y-2==m_y )
				{
					array[i].next_dirction=7;
					array[i].cost=dir;
				}
				//下右
				if ( snake[t][1].x+1==m_x && snake[t][1].y+2==m_y )
				{
					array[i].next_dirction=4;
					array[i].cost=dir;
				}
			}
		}

		//上
		if (checkoutofboard34(temp_pp.x-1,temp_pp.y,gp.n,gp.m)==1 && gp.panel[temp_pp.x-1][temp_pp.y]!=2 && gp.panel[temp_pp.x-1][temp_pp.y]<10 )
		{
			t_temp.x=temp_pp.x-1;
			t_temp.y=temp_pp.y  ;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
		}
		//下
		if (checkoutofboard34(temp_pp.x+1,temp_pp.y,gp.n,gp.m)==1 && gp.panel[temp_pp.x+1][temp_pp.y]!=2 && gp.panel[temp_pp.x+1][temp_pp.y]<10)
		{
			t_temp.x=temp_pp.x+1;
			t_temp.y=temp_pp.y  ;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
		}
		//左
		if (checkoutofboard34(temp_pp.x,temp_pp.y-2,gp.n,gp.m)==1 && gp.panel[temp_pp.x][temp_pp.y-2]!=2 && gp.panel[temp_pp.x][temp_pp.y-2]<10)
		{
			t_temp.x=temp_pp.x;
			t_temp.y=temp_pp.y-2;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
		}
		//右
		if (checkoutofboard34(temp_pp.x,temp_pp.y+2,gp.n,gp.m)==1 && gp.panel[temp_pp.x][temp_pp.y+2]!=2 && gp.panel[temp_pp.x][temp_pp.y+2]<10)
		{
			t_temp.x=temp_pp.x;
			t_temp.y=temp_pp.y+2  ;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
		}

		if (gp.obliqueowner[t]==1 )
		{
			//左上
			if (checkoutofboard34(temp_pp.x-1,temp_pp.y-2,gp.n,gp.m)==1 && gp.panel[temp_pp.x-1][temp_pp.y-2]!=2 && gp.panel[temp_pp.x-1][temp_pp.y-2]<10)
			{
				t_temp.x=temp_pp.x-1;
				t_temp.y=temp_pp.y-2 ;
				q34.push(t_temp);
				gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
			}
			//左下
			if (checkoutofboard34(temp_pp.x+1,temp_pp.y-2,gp.n,gp.m)==1 && gp.panel[temp_pp.x+1][temp_pp.y-2]!=2 && gp.panel[temp_pp.x+1][temp_pp.y-2]<10)
			{
				t_temp.x=temp_pp.x+1;
				t_temp.y=temp_pp.y-2  ;
				q34.push(t_temp);
				gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
			}
			//右上
			if (checkoutofboard34(temp_pp.x-1,temp_pp.y+2,gp.n,gp.m)==1 && gp.panel[temp_pp.x-1][temp_pp.y+2]!=2 && gp.panel[temp_pp.x-1][temp_pp.y+2]<10)
			{
				t_temp.x=temp_pp.x-1;
				t_temp.y=temp_pp.y+2 ;
				q34.push(t_temp);
				gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
			}
			//右下
			if (checkoutofboard34(temp_pp.x+1,temp_pp.y+2,gp.n,gp.m)==1 && gp.panel[temp_pp.x+1][temp_pp.y+2]!=2 && gp.panel[temp_pp.x+1][temp_pp.y+2]<10)
			{
				t_temp.x=temp_pp.x+1;
				t_temp.y=temp_pp.y+2;
				q34.push(t_temp);
				gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
			}
		}
	}
}

void heapsort34(ex_point34* heap,int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = i; j < len; ++j)
		{
			if (heap[j].cost<heap[i].cost)
			{
				ex_point34 temp=heap[j];
				heap[j]=heap[i];
				heap[i]=temp;
			}
		}
	}
}

int check_direction34(int d_x,int d_y,point snake[5][100],int len[5],int t,GamePanel gp ,int ff)
{
	for (int i = 1; i < len[t]; ++i)
	{
		gp.panel[snake[t][i].x][snake[t][i].y]=2;
	}
	for (int i = 1; i <= len[!t]; ++i)
	{
		gp.panel[snake[!t][i].x][snake[!t][i].y]=2;
	}
	point temp_pp;
	if (ff==1)
	{
		gp.panel[snake[!t][1].x][snake[!t][1].y]=0;
	}
	q34.init();
	//上
	if (checkoutofboard34(snake[t][1].x-1,snake[t][1].y,gp.n,gp.m)==1 && gp.panel[snake[t][1].x-1][snake[t][1].y]!=2 && gp.panel[snake[t][1].x-1][snake[t][1].y]<10)
	{
		temp_pp.x=snake[t][1].x-1;
		temp_pp.y=snake[t][1].y  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
	}
	//下
	if (checkoutofboard34(snake[t][1].x+1,snake[t][1].y,gp.n,gp.m)==1 && gp.panel[snake[t][1].x+1][snake[t][1].y]!=2 && gp.panel[snake[t][1].x+1][snake[t][1].y]<10)
	{
		temp_pp.x=snake[t][1].x+1;
		temp_pp.y=snake[t][1].y  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
	}
	//左
	if (checkoutofboard34(snake[t][1].x,snake[t][1].y-2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x][snake[t][1].y-2]!=2 && gp.panel[snake[t][1].x][snake[t][1].y-2]<10)
	{
		temp_pp.x=snake[t][1].x;
		temp_pp.y=snake[t][1].y-2  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
	}
	//右
	if (checkoutofboard34(snake[t][1].x,snake[t][1].y+2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x][snake[t][1].y+2]!=2 && gp.panel[snake[t][1].x][snake[t][1].y+2]<10)
	{
		temp_pp.x=snake[t][1].x;
		temp_pp.y=snake[t][1].y+2  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
	}
	if (gp.obliqueowner[t]==1 )
	{
		//左上
		if (checkoutofboard34(snake[t][1].x-1,snake[t][1].y-2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x-1][snake[t][1].y-2]!=2 && gp.panel[snake[t][1].x-1][snake[t][1].y-2]<10)
		{
			temp_pp.x=snake[t][1].x-1;
			temp_pp.y=snake[t][1].y-2 ;
			q34.push(temp_pp);
			gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
		}
		//左下
		if (checkoutofboard34(snake[t][1].x+1,snake[t][1].y-2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x+1][snake[t][1].y-2]!=2 && gp.panel[snake[t][1].x+1][snake[t][1].y-2]<10)
		{
			temp_pp.x=snake[t][1].x+1;
			temp_pp.y=snake[t][1].y-2  ;
			q34.push(temp_pp);
			gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
		}
		//右上
		if (checkoutofboard34(snake[t][1].x-1,snake[t][1].y+2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x-1][snake[t][1].y+2]!=2 && gp.panel[snake[t][1].x-1][snake[t][1].y+2]<10)
		{
			temp_pp.x=snake[t][1].x-1;
			temp_pp.y=snake[t][1].y+2 ;
			q34.push(temp_pp);
			gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
		}
		//右下
		if (checkoutofboard34(snake[t][1].x+1,snake[t][1].y+2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x+1][snake[t][1].y+2]!=2 && gp.panel[snake[t][1].x+1][snake[t][1].y+2]<10)
		{
			temp_pp.x=snake[t][1].x+1;
			temp_pp.y=snake[t][1].y+2;
			q34.push(temp_pp);
			gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
		}

	}
	point t_temp;
	while(!q34.isempty())
	{
		temp_pp=q34.pop();
		if (d_x==temp_pp.x && d_y==temp_pp.y )
		{
			int dir=1;
			int m_x=temp_pp.x;
			int m_y=temp_pp.y;
			int f_x=gp.panel[m_x][m_y]/100;
			int f_y=gp.panel[m_x][m_y]%100;
			while(!(f_x==snake[t][1].x && f_y==snake[t][1].y) )
			{
				dir++;
				m_x=f_x;
				m_y=f_y;
				f_x=gp.panel[m_x][m_y]/100;
				f_y=gp.panel[m_x][m_y]%100;
			}
			return dir;
		}
		//上
		if (checkoutofboard34(temp_pp.x-1,temp_pp.y,gp.n,gp.m)==1 && gp.panel[temp_pp.x-1][temp_pp.y]!=2 && gp.panel[temp_pp.x-1][temp_pp.y]<10)
		{
			t_temp.x=temp_pp.x-1;
			t_temp.y=temp_pp.y  ;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
		}
		//下
		if (checkoutofboard34(temp_pp.x+1,temp_pp.y,gp.n,gp.m)==1 && gp.panel[temp_pp.x+1][temp_pp.y]!=2 && gp.panel[temp_pp.x+1][temp_pp.y]<10)
		{
			t_temp.x=temp_pp.x+1;
			t_temp.y=temp_pp.y  ;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
		}
		//左
		if (checkoutofboard34(temp_pp.x,temp_pp.y-2,gp.n,gp.m)==1 && gp.panel[temp_pp.x][temp_pp.y-2]!=2 && gp.panel[temp_pp.x][temp_pp.y-2]<10)
		{
			t_temp.x=temp_pp.x;
			t_temp.y=temp_pp.y-2;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
		}
		//右
		if (checkoutofboard34(temp_pp.x,temp_pp.y+2,gp.n,gp.m)==1 && gp.panel[temp_pp.x][temp_pp.y+2]!=2 && gp.panel[temp_pp.x][temp_pp.y+2]<10)
		{
			t_temp.x=temp_pp.x;
			t_temp.y=temp_pp.y+2  ;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
		}

		if (gp.obliqueowner[t]==1 )
		{
			//左上
			if (checkoutofboard34(temp_pp.x-1,temp_pp.y-2,gp.n,gp.m)==1 && gp.panel[temp_pp.x-1][temp_pp.y-2]!=2 && gp.panel[temp_pp.x-1][temp_pp.y-2]<10)
			{
				t_temp.x=temp_pp.x-1;
				t_temp.y=temp_pp.y-2 ;
				q34.push(t_temp);
				gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
			}
			//左下
			if (checkoutofboard34(temp_pp.x+1,temp_pp.y-2,gp.n,gp.m)==1 && gp.panel[temp_pp.x+1][temp_pp.y-2]!=2 && gp.panel[temp_pp.x+1][temp_pp.y-2]<10)
			{
				t_temp.x=temp_pp.x+1;
				t_temp.y=temp_pp.y-2  ;
				q34.push(t_temp);
				gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
			}
			//右上
			if (checkoutofboard34(temp_pp.x-1,temp_pp.y+2,gp.n,gp.m)==1 && gp.panel[temp_pp.x-1][temp_pp.y+2]!=2 && gp.panel[temp_pp.x-1][temp_pp.y+2]<10)
			{
				t_temp.x=temp_pp.x-1;
				t_temp.y=temp_pp.y+2 ;
				q34.push(t_temp);
				gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
			}
			//右下
			if (checkoutofboard34(temp_pp.x+1,temp_pp.y+2,gp.n,gp.m)==1 && gp.panel[temp_pp.x+1][temp_pp.y+2]!=2 && gp.panel[temp_pp.x+1][temp_pp.y+2]<10)
			{
				t_temp.x=temp_pp.x+1;
				t_temp.y=temp_pp.y+2;
				q34.push(t_temp);
				gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
			}
		}
	}
	return 10000;
}

int check_direction_pre_next34(int d_x,int d_y,point snake[5][100],int len[5],int t,GamePanel gp,int& next)
{
	for (int i = 1; i < len[t]; ++i)
	{
		gp.panel[snake[t][i].x][snake[t][i].y]=2;
	}
	for (int i = 1; i <= len[!t]; ++i)
	{
		gp.panel[snake[!t][i].x][snake[!t][i].y]=2;
	}
	point temp_pp;
	q34.init();
	//上
	if (checkoutofboard34(snake[t][1].x-1,snake[t][1].y,gp.n,gp.m)==1 && gp.panel[snake[t][1].x-1][snake[t][1].y]!=2 && gp.panel[snake[t][1].x-1][snake[t][1].y]<10)
	{
		temp_pp.x=snake[t][1].x-1;
		temp_pp.y=snake[t][1].y  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
	}
	//下
	if (checkoutofboard34(snake[t][1].x+1,snake[t][1].y,gp.n,gp.m)==1 && gp.panel[snake[t][1].x+1][snake[t][1].y]!=2 && gp.panel[snake[t][1].x+1][snake[t][1].y]<10)
	{
		temp_pp.x=snake[t][1].x+1;
		temp_pp.y=snake[t][1].y  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
	}
	//左
	if (checkoutofboard34(snake[t][1].x,snake[t][1].y-2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x][snake[t][1].y-2]!=2 && gp.panel[snake[t][1].x][snake[t][1].y-2]<10)
	{
		temp_pp.x=snake[t][1].x;
		temp_pp.y=snake[t][1].y-2  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
	}
	//右
	if (checkoutofboard34(snake[t][1].x,snake[t][1].y+2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x][snake[t][1].y+2]!=2 && gp.panel[snake[t][1].x][snake[t][1].y+2]<10)
	{
		temp_pp.x=snake[t][1].x;
		temp_pp.y=snake[t][1].y+2  ;
		q34.push(temp_pp);
		gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
	}
	if (gp.obliqueowner[t]==1 )
	{
		//左上
		if (checkoutofboard34(snake[t][1].x-1,snake[t][1].y-2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x-1][snake[t][1].y-2]!=2 && gp.panel[snake[t][1].x-1][snake[t][1].y-2]<10)
		{
			temp_pp.x=snake[t][1].x-1;
			temp_pp.y=snake[t][1].y-2 ;
			q34.push(temp_pp);
			gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
		}
		//左下
		if (checkoutofboard34(snake[t][1].x+1,snake[t][1].y-2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x+1][snake[t][1].y-2]!=2 && gp.panel[snake[t][1].x+1][snake[t][1].y-2]<10)
		{
			temp_pp.x=snake[t][1].x+1;
			temp_pp.y=snake[t][1].y-2  ;
			q34.push(temp_pp);
			gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
		}
		//右上
		if (checkoutofboard34(snake[t][1].x-1,snake[t][1].y+2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x-1][snake[t][1].y+2]!=2 && gp.panel[snake[t][1].x-1][snake[t][1].y+2]<10)
		{
			temp_pp.x=snake[t][1].x-1;
			temp_pp.y=snake[t][1].y+2 ;
			q34.push(temp_pp);
			gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
		}
		//右下
		if (checkoutofboard34(snake[t][1].x+1,snake[t][1].y+2,gp.n,gp.m)==1 && gp.panel[snake[t][1].x+1][snake[t][1].y+2]!=2 && gp.panel[snake[t][1].x+1][snake[t][1].y+2]<10)
		{
			temp_pp.x=snake[t][1].x+1;
			temp_pp.y=snake[t][1].y+2;
			q34.push(temp_pp);
			gp.panel[temp_pp.x][temp_pp.y]=snake[t][1].x*100+snake[t][1].y;
		}

	}
	point t_temp;
	while(!q34.isempty())
	{
		temp_pp=q34.pop();
		if (d_x==temp_pp.x && d_y==temp_pp.y )
		{
			int dir=1;
			int m_x=temp_pp.x;
			int m_y=temp_pp.y;
			int f_x=gp.panel[m_x][m_y]/100;
			int f_y=gp.panel[m_x][m_y]%100;
			while(!(f_x==snake[t][1].x && f_y==snake[t][1].y) )
			{
				dir++;
				m_x=f_x;
				m_y=f_y;
				f_x=gp.panel[m_x][m_y]/100;
				f_y=gp.panel[m_x][m_y]%100;
			}
			//上
			if ( snake[t][1].x-1==m_x && snake[t][1].y==m_y )
			{
				next=3;
			}
			//下
			if ( snake[t][1].x+1==m_x && snake[t][1].y==m_y )
			{
				next=0;
			}
			//左
			if ( snake[t][1].x==m_x && snake[t][1].y-2==m_y )
			{
				next=2;
			}
			//右
			if ( snake[t][1].x==m_x && snake[t][1].y+2==m_y )
			{
				next=1;
			}

			//上左
			if ( snake[t][1].x-1==m_x && snake[t][1].y-2==m_y )
			{
				next=6;
			}
			//上右
			if ( snake[t][1].x-1==m_x && snake[t][1].y+2==m_y )
			{
				next=5;
			}
			//下左
			if ( snake[t][1].x+1==m_x && snake[t][1].y-2==m_y )
			{
				next=7;
			}
			//下右
			if ( snake[t][1].x+1==m_x && snake[t][1].y+2==m_y )
			{
				next=4;
			}
			return dir;
		}
		//上
		if (checkoutofboard34(temp_pp.x-1,temp_pp.y,gp.n,gp.m)==1 && gp.panel[temp_pp.x-1][temp_pp.y]!=2 && gp.panel[temp_pp.x-1][temp_pp.y]<10)
		{
			t_temp.x=temp_pp.x-1;
			t_temp.y=temp_pp.y  ;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
		}
		//下
		if (checkoutofboard34(temp_pp.x+1,temp_pp.y,gp.n,gp.m)==1 && gp.panel[temp_pp.x+1][temp_pp.y]!=2 && gp.panel[temp_pp.x+1][temp_pp.y]<10)
		{
			t_temp.x=temp_pp.x+1;
			t_temp.y=temp_pp.y  ;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
		}
		//左
		if (checkoutofboard34(temp_pp.x,temp_pp.y-2,gp.n,gp.m)==1 && gp.panel[temp_pp.x][temp_pp.y-2]!=2 && gp.panel[temp_pp.x][temp_pp.y-2]<10)
		{
			t_temp.x=temp_pp.x;
			t_temp.y=temp_pp.y-2;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
		}
		//右
		if (checkoutofboard34(temp_pp.x,temp_pp.y+2,gp.n,gp.m)==1 && gp.panel[temp_pp.x][temp_pp.y+2]!=2 && gp.panel[temp_pp.x][temp_pp.y+2]<10)
		{
			t_temp.x=temp_pp.x;
			t_temp.y=temp_pp.y+2  ;
			q34.push(t_temp);
			gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
		}

		if (gp.obliqueowner[t]==1 )
		{
			//左上
			if (checkoutofboard34(temp_pp.x-1,temp_pp.y-2,gp.n,gp.m)==1 && gp.panel[temp_pp.x-1][temp_pp.y-2]!=2 && gp.panel[temp_pp.x-1][temp_pp.y-2]<10)
			{
				t_temp.x=temp_pp.x-1;
				t_temp.y=temp_pp.y-2 ;
				q34.push(t_temp);
				gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
			}
			//左下
			if (checkoutofboard34(temp_pp.x+1,temp_pp.y-2,gp.n,gp.m)==1 && gp.panel[temp_pp.x+1][temp_pp.y-2]!=2 && gp.panel[temp_pp.x+1][temp_pp.y-2]<10)
			{
				t_temp.x=temp_pp.x+1;
				t_temp.y=temp_pp.y-2  ;
				q34.push(t_temp);
				gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
			}
			//右上
			if (checkoutofboard34(temp_pp.x-1,temp_pp.y+2,gp.n,gp.m)==1 && gp.panel[temp_pp.x-1][temp_pp.y+2]!=2 && gp.panel[temp_pp.x-1][temp_pp.y+2]<10)
			{
				t_temp.x=temp_pp.x-1;
				t_temp.y=temp_pp.y+2 ;
				q34.push(t_temp);
				gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
			}
			//右下
			if (checkoutofboard34(temp_pp.x+1,temp_pp.y+2,gp.n,gp.m)==1 && gp.panel[temp_pp.x+1][temp_pp.y+2]!=2 && gp.panel[temp_pp.x+1][temp_pp.y+2]<10)
			{
				t_temp.x=temp_pp.x+1;
				t_temp.y=temp_pp.y+2;
				q34.push(t_temp);
				gp.panel[t_temp.x][t_temp.y]=temp_pp.x*100+temp_pp.y;
			}
		}
	}
	return 10000;
}

int snake_around_food34(point snake[5][100],int food_x,int food_y,int t, GamePanel gp)
{
	//上
	if (food_x-1==snake[t][1].x && food_y==snake[t][1].y)
	{
		return 1;
	}
	//左
	if (food_x==snake[t][1].x && food_y-2==snake[t][1].y)
	{
		return 1;
	}
	//右
	if (food_x==snake[t][1].x && food_y+2==snake[t][1].y)
	{
		return 1;
	}
	//下
	if (food_x+1==snake[t][1].x && food_y==snake[t][1].y)
	{
		return 1;
	}
	//左上
	if (food_x-1==snake[t][1].x && food_y-2==snake[t][1].y)
	{
		return 1;
	}
	//左下
	if (food_x+1==snake[t][1].x && food_y-2==snake[t][1].y)
	{
		return 1;
	}
	//右上
	if (food_x-1==snake[t][1].x && food_y+2==snake[t][1].y)
	{
		return 1;
	}
	//右下
	if (food_x+1==snake[t][1].x && food_y+2==snake[t][1].y)
	{
		return 1;
	}
	return 0;
}

int sround_food34(point snake[5][100],int len[5],int food_x,int food_y,int t, GamePanel gp)
{
	gp.obliqueowner[t]=0;
	for (int i = 1; i <= len[t]; ++i)
	{
		gp.panel[snake[t][i].x][snake[t][i].y]=2;
	}
	for (int i = 1; i <= len[!t]; ++i)
	{
		gp.panel[snake[!t][i].x][snake[!t][i].y]=2;
	}
	gp.panel[food_x][food_y]=2;
	int llen=0;
	//上
	if ( gp.panel[food_x-1][food_y]!=2 )
	{
		llen++;
	}
	//左
	if (gp.panel[food_x][food_y-2]!=2 )
	{
		llen++;
	}
	//右
	if ( gp.panel[food_x][food_y+2]!=2 )
	{
		llen++;
	}
	//下
	if ( gp.panel[food_x+1][food_y]!=2 )
	{
		llen++;
	}
	//左上
	if (  gp.panel[food_x-1][food_y-2]!=2 )
	{
		llen++;
	}
	//左下
	if ( gp.panel[food_x+1][food_y-2]!=2 )
	{
		llen++;
	}
	//右上
	if (  gp.panel[food_x-1][food_y+2]!=2 )
	{
		llen++;
	}
	//右下
	if (  gp.panel[food_x+1][food_y+2]!=2  )
	{
		llen++;
	}
	ex_point34* ex_point_t=new ex_point34[llen];
	for (int i = 0; i < llen; ++i)
	{
		//上
		if ( gp.panel[food_x-1][food_y]!=2 )
		{
			ex_point_t[i].x=food_x-1;
			ex_point_t[i].y=food_y;
		}
		//左
		if (gp.panel[food_x][food_y-2]!=2 )
		{
			ex_point_t[i].x=food_x;
			ex_point_t[i].y=food_y-2;
		}
		//右
		if ( gp.panel[food_x][food_y+2]!=2 )
		{
			ex_point_t[i].x=food_x;
			ex_point_t[i].y=food_y+2;
		}
		//下
		if ( gp.panel[food_x+1][food_y]!=2 )
		{
			ex_point_t[i].x=food_x+1;
			ex_point_t[i].y=food_y;
		}
		//左上
		if (  gp.panel[food_x-1][food_y-2]!=2 )
		{
			ex_point_t[i].x=food_x-1;
			ex_point_t[i].y=food_y-2;
		}
		//左下
		if ( gp.panel[food_x+1][food_y-2]!=2 )
		{
			ex_point_t[i].x=food_x+1;
			ex_point_t[i].y=food_y-2;
		}
		//右上
		if (  gp.panel[food_x-1][food_y+2]!=2 )
		{
			ex_point_t[i].x=food_x-1;
			ex_point_t[i].y=food_y+2;
		}
		//右下
		if (  gp.panel[food_x+1][food_y+2]!=2  )
		{
			ex_point_t[i].x=food_x+1;
			ex_point_t[i].y=food_y+2;
		}
	}
	for (int i = 1; i <= len[t]; ++i)
	{
		gp.panel[snake[t][i].x][snake[t][i].y]=0;
	}
	for (int i = 1; i <= len[!t]; ++i)
	{
		gp.panel[snake[!t][i].x][snake[!t][i].y]=0;
	}
	//计算数组里面各个点的距离
	cacl_dirction34(snake,len,ex_point_t,llen,t,gp);
	heapsort34(ex_point_t,llen);
	for (int i = 0; i < llen; ++i)
	{
		if (ex_point_t[i].next_dirction!=-1 && check34(snake,len,t,gp,ex_point_t[i].next_dirction)==true && check_is_safe34(snake,len,t,gp,ex_point_t[i].next_dirction)==1)
		{
			int temp=ex_point_t[i].next_dirction;
			delete[] ex_point_t;
			return temp;
		}
	}
	// //找最近的身体
	//找尾巴
	int next=-1;
	check_direction_pre_next34(snake[t][len[t]].x,snake[t][len[t]].y,snake,len,t,gp,next);
	if (next!=-1 && check34(snake,len,t,gp,next)==true && check_is_safe34(snake,len,t,gp,next)==1 )
	{
		delete[] ex_point_t;
		return next;
	}
	delete[] ex_point_t;
	return -1;//失败
}

int vi_cal_dir34(int m_x,int m_y,int d_x,int d_y ,int flag_t)
{
	int temp=0;
	if (flag_t==0)
	{
		temp=abs(m_x-d_x)+abs(m_y-d_y);
	}
	else
	{
		temp=abs(m_x-d_x)+abs(m_y-d_y);
		temp/=2;
	}
	return temp;
}

int fight_with_other_snake34(point snake[5][100], int len[5], int t, GamePanel gp)
{
	for (int i = 1; i < len[t]; ++i)
	{
		gp.panel[snake[t][i].x][snake[t][i].y]=2;
	}
	for (int i = 1; i <= len[!t]; ++i)
	{
		gp.panel[snake[!t][i].x][snake[!t][i].y]=2;
	}
	//寻找公共区域

	//第二节周围
	//上
	if (checkoutofboard34(snake[!t][2].x-1,snake[!t][2].y  ,gp.n,gp.m)==1 && gp.panel[snake[!t][2].x-1][snake[!t][2].y  ]!=2)
	{
		gp.panel[snake[!t][2].x-1][snake[!t][2].y  ]=-1;
	}
	//下
	if (checkoutofboard34(snake[!t][2].x+1,snake[!t][2].y  ,gp.n,gp.m)==1 && gp.panel[snake[!t][2].x+1][snake[!t][2].y  ]!=2)
	{
		gp.panel[snake[!t][2].x+1][snake[!t][2].y  ]=-1;
	}
	//左
	if (checkoutofboard34(snake[!t][2].x  ,snake[!t][2].y-2,gp.n,gp.m)==1 && gp.panel[snake[!t][2].x  ][snake[!t][2].y-2]!=2)
	{
		gp.panel[snake[!t][2].x  ][snake[!t][2].y-2]=-1;
	}
	//右
	if (checkoutofboard34(snake[!t][2].x  ,snake[!t][2].y+2,gp.n,gp.m)==1 && gp.panel[snake[!t][2].x  ][snake[!t][2].y+2]!=2)
	{
		gp.panel[snake[!t][2].x  ][snake[!t][2].y+2]=-1;
	}
	//左上
	if (checkoutofboard34(snake[!t][2].x-1,snake[!t][2].y-2,gp.n,gp.m)==1 && gp.panel[snake[!t][2].x-1][snake[!t][2].y-2]!=2)
	{
		gp.panel[snake[!t][2].x-1][snake[!t][2].y-2]=-1;
	}
	//左下
	if (checkoutofboard34(snake[!t][2].x+1,snake[!t][2].y-2  ,gp.n,gp.m)==1 && gp.panel[snake[!t][2].x+1][snake[!t][2].y-2  ]!=2)
	{
		gp.panel[snake[!t][2].x+1][snake[!t][2].y-2  ]=-1;
	}
	//右上
	if (checkoutofboard34(snake[!t][2].x-1  ,snake[!t][2].y+2,gp.n,gp.m)==1 && gp.panel[snake[!t][2].x-1  ][snake[!t][2].y+2]!=2)
	{
		gp.panel[snake[!t][2].x-1  ][snake[!t][2].y+2]=-1;
	}
	//右下
	if (checkoutofboard34(snake[!t][2].x+1  ,snake[!t][2].y+2,gp.n,gp.m)==1 && gp.panel[snake[!t][2].x+1  ][snake[!t][2].y+2]!=2)
	{
		gp.panel[snake[!t][2].x+1  ][snake[!t][2].y+2]=-1;
	}
	//开始寻找节点
	//上
	if (checkoutofboard34(snake[!t][1].x-1,snake[!t][1].y  ,gp.n,gp.m)==1 && gp.panel[snake[!t][1].x-1][snake[!t][1].y  ]==-1)
	{
		return 1;
	}
	//下
	if (checkoutofboard34(snake[!t][1].x+1,snake[!t][1].y  ,gp.n,gp.m)==1 && gp.panel[snake[!t][1].x+1][snake[!t][1].y  ]==-1)
	{
		return 2;
	}
	//左
	if (checkoutofboard34(snake[!t][1].x  ,snake[!t][1].y-2,gp.n,gp.m)==1 && gp.panel[snake[!t][1].x  ][snake[!t][1].y-2]==-1)
	{
		return 3;
	}
	//右
	if (checkoutofboard34(snake[!t][1].x  ,snake[!t][1].y+2,gp.n,gp.m)==1 && gp.panel[snake[!t][1].x  ][snake[!t][1].y+2]==-1)
	{
		return 4;
	}
	//失败
	return -1;
}

int machine_move34(point snake[5][100], int len[5], int direct[5], int t, GamePanel gp)
{
	//将你的machine_move函数体放在此处，并删去下面示例代码
	//检测全局变量
	if (gp.panel[point_wall34.x][point_wall34.y]!=1)
	{
		flag34=0;
		flag_point_wall34=0;
		point_wall34.x=0;
		point_wall34.y=0;
	}
	int is_second_level=0;
	if (len[0]+len[1]>=16)
	{
		is_second_level=1;
	}
	//倍速道具是否被敌人占有并且有效
	//注意到最后需要改
	//注意到最后需要改
	////注意到最后需要改

	// if ( gp.speedowner==!t && gp.step_speed<100)//注意到最后需要改
	// {
	// 	int next=-1;
	// 	int direction_to_arm =vi_cal_dir34(snake[!t][1].x,snake[!t][1].y,snake[t][1].x,snake[t][1].y,gp.obliqueowner[!t]);
	// 	int direction_to_back=check_direction_pre_next34(snake[t][len[t]].x,snake[t][len[t]].y,snake,len,t,gp,next);
	// 	//是
	// 		//判断敌人离自己的距离，观察自己是否安全
	// 			//不安全
	// 				//向自己的蛇尾前进，进行绕圈，保护自己
	// 	if (direction_to_arm/2<=direction_to_back && len[t]%2==0 && next!=-1 && check34(snake,len,t,gp,next)==true && check_is_safe34(snake,len,t,gp,next)==1 )
	// 	{

	// 		return next;
	// 	}
	// 	//安全
	// 		//执行下面的代码
	// }


	//否，执行下面的代码
	//将所有食物道具点放入数组里面
	int array_len=0;
	ex_point34* point_array=init_array34(gp,array_len);
	//判断远近的函数，计算蛇头到每个点的距离，并计算如果要去那个点下一步应该怎么走，
	cacl_dirction34(snake,len,point_array,array_len,t,gp);
	//对所有点排序
	heapsort34(point_array,array_len);
	//取最小的两个目标,最近的目标,次远的目标
	//判断现在是否还有道具
	int speedprops_flag  =-1;
	int obliqueprops_flag[2]={-1,-1};
	for (int i = 0; i < array_len; ++i)
	{
		if (point_array[i].special==1)
		{
			speedprops_flag=i;
		}
		if (point_array[i].special==2)
		{
			(obliqueprops_flag[0]==-1)?obliqueprops_flag[0]=i:obliqueprops_flag[1]=i;
		}
	}
	//是
	if (speedprops_flag!=-1 ||obliqueprops_flag[0]!=-1 ||obliqueprops_flag[1]!=-1 )
	{
		//判断是否还有倍速道具
		//是
		if (speedprops_flag!=-1)
		{
			//判断倍速道具离自己的距离是否比敌人近
			//是
			if (point_array[speedprops_flag].next_dirction!=-1&& check34(snake,len,t,gp,point_array[speedprops_flag].next_dirction)==true && check_is_safe34(snake,len,t,gp,point_array[speedprops_flag].next_dirction)==1 && point_array[speedprops_flag].cost<=check_direction34(point_array[speedprops_flag].x,point_array[speedprops_flag].y,snake,len,!t,gp,0))
			{
				return point_array[speedprops_flag].next_dirction;
			}
			//否
				//执行下面代码
		}
		//否
		//去抢最近的斜走道具
		if (obliqueprops_flag[0]!=-1)
		{
			if (point_array[obliqueprops_flag[0]].next_dirction!=-1&& check34(snake,len,t,gp,point_array[obliqueprops_flag[0]].next_dirction)==true && check_is_safe34(snake,len,t,gp,point_array[obliqueprops_flag[0]].next_dirction)==1 && point_array[obliqueprops_flag[0]].cost<=check_direction34(point_array[obliqueprops_flag[0]].x,point_array[obliqueprops_flag[0]].y,snake,len,!t,gp,0))
			{
				return point_array[obliqueprops_flag[0]].next_dirction;
			}
		}
		if (obliqueprops_flag[1]!=-1)
		{
			if (point_array[obliqueprops_flag[1]].next_dirction!=-1 && check34(snake,len,t,gp,point_array[obliqueprops_flag[1]].next_dirction)==true && check_is_safe34(snake,len,t,gp,point_array[obliqueprops_flag[1]].next_dirction)==1 &&point_array[obliqueprops_flag[1]].cost<=check_direction34(point_array[obliqueprops_flag[1]].x,point_array[obliqueprops_flag[1]].y,snake,len,!t,gp,0))
			{
				return point_array[obliqueprops_flag[1]].next_dirction;
			}
		}

	}
	//否
	//判断倍速道具是否被自己占有并且有效
	if (gp.speedowner==t && gp.obliqueowner[t]==1 && gp.obliqueowner[!t]!=1 && gp.step_speed<50)//注意要改偶
	{
		//是
		//攻击对方
		int dir_temp_pp=fight_with_other_snake34(snake,len,t,gp);
		if (dir_temp_pp!=-1)
		{
			switch(dir_temp_pp)
			{
				case 1: check_direction_pre_next34(snake[!t][1].x-1,snake[!t][1].y  ,snake,len,t,gp,dir_temp_pp);break;
				case 2: check_direction_pre_next34(snake[!t][1].x+1,snake[!t][1].y  ,snake,len,t,gp,dir_temp_pp);break;
				case 3: check_direction_pre_next34(snake[!t][1].x  ,snake[!t][1].y-2,snake,len,t,gp,dir_temp_pp);break;
				case 4: check_direction_pre_next34(snake[!t][1].x  ,snake[!t][1].y+2,snake,len,t,gp,dir_temp_pp);break;
			}
			if (dir_temp_pp!=-1 && check34(snake,len,t,gp,dir_temp_pp)==true && check_is_safe34(snake,len,t,gp,dir_temp_pp)==1)
			{
				return dir_temp_pp;
			}
		}
	}
	//否
		//执行下面代码
	//执行下面的代码

	//判断最小的是不是离自己比离敌人近
		//是，去吃食物
			//判断所走路不能把自己围死
				//是，随机向其他安全方向行走
				//否，去吃食物
		//否，选择次近的食物
			//判断所走路不能把自己围死
				//是，随机向其他安全方向行走
				//否，去吃食物

	for (int i = 0; i < array_len; ++i)
	{
		//如果自己到一个食物的距离+6-1<=敌人到此食物的距离 && 没有在墙角，墙边
		if (flag34==1 || point_array[i].cost+6-1<=check_direction34(point_array[i].x,point_array[i].y,snake,len,!t,gp,0))
		{
			//是
			//如果除了该食物外,敌人的长度+其他食物的长度<=自己的长度
			if (flag34==1 ||(len[t]%2==0 && point_array[i].next_dirction!=-1 && len[!t]+array_len-1<=len[t]))
			{
				//是
					//围住食物
					//是否到达食物附近
						//是
						if (flag_point_wall34==1)
						{
							int ttt_dir=sround_food34(snake,len,point_wall34.x,point_wall34.y,t,gp);
							if (ttt_dir!=-1)
							{
								return ttt_dir;
							}
							flag34=0;
							flag_point_wall34=0;
							point_wall34.x=0;
							point_wall34.y=0;
						}
						else if (snake_around_food34(snake,point_array[i].x,point_array[i].y,t,gp)==1)
						{
							flag34=1;
							flag_point_wall34=1;
							point_wall34.x=point_array[i].x;
							point_wall34.y=point_array[i].y;
							int ttt_dir=sround_food34(snake,len,point_array[i].x,point_array[i].y,t,gp);
							if (ttt_dir!=-1)
							{
								return ttt_dir;
							}
							flag34=0;
							flag_point_wall34=0;
							point_wall34.x=0;
							point_wall34.y=0;
						}
						//否
						else if (check34(snake,len,t,gp,point_array[i].next_dirction)==true && check_is_safe34(snake,len,t,gp,point_array[i].next_dirction)==1)
						{
							return point_array[i].next_dirction;
						}
			}
			//否
				//执行下面代码
		}
		//是否第一面最后一个食物
		if (is_second_level==0 && gp.currentfoodnum==1 )
		{
			//判断该食物是否抢先敌人到达
			if (point_array[0].next_dirction!=-1 && check34(snake,len,t,gp,point_array[0].next_dirction)==true && check_is_safe34(snake,len,t,gp,point_array[0].next_dirction)==1  && point_array[0].cost<=check_direction34(point_array[0].x,point_array[0].y,snake,len,!t,gp,0))
			{
				return point_array[i].next_dirction;
			}
			else
			{
				int next=-1;
				check_direction_pre_next34(gp.n/2,gp.m/2,snake,len,t,gp,next);
				if (next!=-1 && check34(snake,len,t,gp,next)==true && check_is_safe34(snake,len,t,gp,next)==1)
				{
					return next;
				}
			}
		}
		//否
			//执行下面代码
		if (point_array[i].next_dirction!=-1 && check34(snake,len,t,gp,point_array[i].next_dirction)==true && check_is_safe34(snake,len,t,gp,point_array[i].next_dirction)==1  && point_array[i].cost<=check_direction34(point_array[i].x,point_array[i].y,snake,len,!t,gp,0))
		{
			return point_array[i].next_dirction;
		}
	}
	for (int i = 0; i < array_len; ++i)
	{
		if (point_array[i].next_dirction!=-1 && check34(snake,len,t,gp,point_array[i].next_dirction)==true && check_is_safe34(snake,len,t,gp,point_array[i].next_dirction)==1  )
		{
			return point_array[i].next_dirction;
		}
	}
	//随机吃食物
	int i=100;
	int k=0;
	while(i>0)
	{

		if (gp.obliqueowner[t]==1)
		{
			k=k%8;
		}
		else
		{
			k=k%4;
		}
		if (check34(snake,len,t,gp,k)==true && check_is_safe34(snake,len,t,gp,k)==1 )
		{
			return k;
		}
		--i;
		k++;
	}
	i=100;
	k=0;
	while(i>0)
	{

		if (gp.obliqueowner[t]==1)
		{
			k=k%8;
		}
		else
		{
			k=k%4;
		}
		if (check34(snake,len,t,gp,k)==true )
		{
			return k;
		}
		--i;
		k++;
	}

	k=0;
	if (gp.obliqueowner[t]==1)
	{
		k=rand()%8;
	}
	else
	{
		k=rand()%4;
	}
	return k;
}
