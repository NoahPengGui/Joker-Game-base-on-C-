#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#define card_num 53		
#define player_num 2

//void test(int card[],int player_one_hand[],int player_two_hand[],char* cardcolors[]);

void playgame();
void setcard(int card[]);
void washcard(int card[]);
void sendcard(int card[],int player_one_hand[],int player_two_hand[]);
void setcolors(char* cardcolors[]);
void printcardyouhave(int card[],int player_one_hand[],int player_two_hand[],char* cardcolors[]);
void throwcard(int card[],int player_one_hand[],int player_two_hand[],char* cardcolors[]);
void drawcard(int card[],int player_one_hand[],int player_two_hand[],char* cardcolors[]);
void comthrowcard(int card[],int player_one_hand[],int player_two_hand[],char* cardcolors[]);
void comdrawcard(int card[],int player_one_hand[],int player_two_hand[],char* cardcolors[]);
void checkwin(int card[],int player_one_hand[],int player_two_hand[],char* cardcolors[]);

int winplayer=0;

int main()
{
	srand(time(NULL));
	int card[card_num+1];
	int player_one_hand[28];
	int player_two_hand[28];
	char* cardcolors[54];
	
	setcard(card);
	washcard(card);
	sendcard(card, player_one_hand, player_two_hand);
	setcolors(cardcolors);
	
//	test(card, player_one_hand, player_two_hand,cardcolors);
	
	printf("-----遊戲開始-----\n");
	
	playgame(card,player_one_hand,player_two_hand,cardcolors);
	return 0;
}

/*----------------------------------------------

void test(int card[],int player_one_hand[],int player_two_hand[],char* cardcolors[])
{
	printf("---卡片索引洗牌後---\n");	
	int a;//testing code
	for(a=1;a<=53;a++)
	{
		printf("%d\n",card[a]);
	}
	int b;//testing code
	printf("---玩家一手排索引---\n");
	printf("\n");
	for(b=1;b<=27;b++)
	{
		printf("%d\n",player_one_hand[b]);
	}
	int c;//testing code
	printf("---玩家二手排索引---\n");
	printf("\n");
	for(c=1;c<=27;c++)
	{
		printf("%d\n",player_two_hand[c]);
	}0
	printf("---所有牌花色---\n");
	int z=0;
	for(z=0; z<=53;z++) 
	{
        printf("%s\n", cardcolors[z]);
    }
    printf("---玩家二手排---\n");
    int f=1;
	for(f=1;f<=27;f++)
	{
		printf("%d: %s\n", f, cardcolors[player_two_hand[f]]);	
	}	
	printf("----------以上為測試程式之數據----------\n");
}

//----------------------------------------------*/

void playgame(int card[],int player_one_hand[],int player_two_hand[],char* cardcolors[])
{
	
	while(1)
	{
		throwcard(card,player_one_hand,player_two_hand,cardcolors);
		drawcard(card,player_one_hand,player_two_hand,cardcolors);
		throwcard(card,player_one_hand,player_two_hand,cardcolors);

		checkwin(card,player_one_hand,player_two_hand,cardcolors);	
		if(winplayer==1)
		{
			printf("----電腦手牌----\n");
			int f=1;
			for(f=1;f<=27;f++)
			{
				printf("%d: %s\n", f, cardcolors[player_two_hand[f]]);	
			}
			printf("----你的手牌----\n");
			printcardyouhave(card,player_one_hand,player_two_hand,cardcolors);
			printf("\n\n------你獲勝------\n");
			break;
		}
		else if(winplayer==2)
		{
			printf("----電腦手牌----\n");
			int f=1;
			for(f=1;f<=27;f++)
			{
				printf("%d: %s\n", f, cardcolors[player_two_hand[f]]);	
			}
			printf("----你的手牌----\n");
			printcardyouhave(card,player_one_hand,player_two_hand,cardcolors);
			printf("\n\n------電腦獲勝------\n");
			break;
		}
		else if(winplayer==0)
		{
			
		}
		
		comthrowcard(card,player_one_hand,player_two_hand,cardcolors);
		comdrawcard(card,player_one_hand,player_two_hand,cardcolors);
		comthrowcard(card,player_one_hand,player_two_hand,cardcolors);

		checkwin(card,player_one_hand,player_two_hand,cardcolors);	
		if(winplayer==1)
		{
			printf("----電腦手牌----\n");
			int f=1;
			for(f=1;f<=27;f++)
			{
				printf("%d: %s\n", f, cardcolors[player_two_hand[f]]);	
			}
			printf("----你的手牌----\n");
			printcardyouhave(card,player_one_hand,player_two_hand,cardcolors);
			printf("\n\n------你獲勝------\n");
			break;
		}
		else if(winplayer==2)
		{
			printf("----電腦手牌----\n");
			int f=1;
			for(f=1;f<=27;f++)
			{
				printf("%d: %s\n", f, cardcolors[player_two_hand[f]]);	
			}
			printf("----你的手牌----\n");
			printcardyouhave(card,player_one_hand,player_two_hand,cardcolors);
			printf("\n\n------電腦獲勝------\n");
			break;
		}
		else if(winplayer==0)
		{
			
		}
	}
	system("PAUSE");
}

void setcard(int card[])
{
	int i;
	for(i=1;i<=card_num;i++)
	{
		card[i]= i;
	}
}

void washcard(int card[])
{
	int i,temp,ran;
	for(i=1;i<=card_num;i++)
	{
		ran=rand()%card_num+1;
		temp=card[i];
		card[i]=card[ran];
		card[ran]=temp;
	}
}

void sendcard(int card[],int player_one_hand[],int player_two_hand[])
{
	int a;
	a=rand()%(27-26+1)+26;;
	int i;
//	printf("%d\n\n\n",a);//testing code
	for(i=1;i<=a;i++)
	{
		player_one_hand[i]=card[i];
	} 
	int o;
	for(o=1;o<=53-a;o++)
	{
		player_two_hand[o]=card[a+o];
	}
}

void setcolors(char* cardcolors[])
{
	int y;
	cardcolors[0] = malloc(20 * sizeof(char));
	strcpy(cardcolors[0],"| 無卡");
	for(y=1;y<=13;y++)
	{
		cardcolors[y] = malloc(20 * sizeof(char));
		sprintf(cardcolors[y],"| %d of 黑桃",y);
	}
	int h=1;
	for(y=14;y<=26;y++)
	{
		cardcolors[y] = malloc(20 * sizeof(char));
		sprintf(cardcolors[y],"| %d of 紅心",h);
		h++;
	}
	h=1;
	for(y=27;y<=39;y++)
	{
		cardcolors[y] = malloc(20 * sizeof(char));
		sprintf(cardcolors[y],"| %d of 方塊",h);
		h++;
	}
	h=1;
	for(y=40;y<=52;y++)
	{
		cardcolors[y] = malloc(20 * sizeof(char));
		sprintf(cardcolors[y],"| %d of 梅花",h);
		h++;
	}
	cardcolors[53] = malloc(20 * sizeof(char));
	strcpy(cardcolors[53],"| 鬼牌");
	//我很抱歉 setcolors 裡面 cardcolors[y] = malloc(20 * sizeof(char)); 這串程式碼是我跟chatgpt拿的 因為真的找不出邏輯上的漏洞 之後只能這樣求助 
}

void printcardyouhave(int card[],int player_one_hand[],int player_two_hand[],char* cardcolors[])
{
	int a;
	for(a=1;a<=27;a++)
	{
		printf("%d: %s\n", a, cardcolors[player_one_hand[a]]);
		
	}
}

void throwcard(int card[],int player_one_hand[],int player_two_hand[],char* cardcolors[])
{ 
	printf("-----丟出可配對的卡-----\n");
	while(1)
	{
		int a=0,b=0,aa=0,bb=0,c=0;
		printcardyouhave(card,player_one_hand,player_two_hand,cardcolors);
		printf("請選擇你想丟出的卡\n");
		printf("第一張:");
		scanf("%d",&a);
		printf("第二張:");
		scanf("%d",&b);
		aa=player_one_hand[a];
		bb=player_one_hand[b];
		if((aa % 13 == bb % 13)&&(aa!=bb)&&(aa!=53&&bb!=53)&&(aa!=0&&bb!=0)&&(a<=27&&a>=1)&&(b>=1&&b<=27))
		{ 
			player_one_hand[a]=0;
			player_one_hand[b]=0;
			system("cls");
			break;
		}
		else if(a==28||b==28)
		{
			printf("確定跳過?");
			printf("\n 1=確定 2=取消");
			scanf("%d",&c);
			if(c==1)
			{
				system("cls");
				break;
			}
			else
			{
				system("cls");
				printf("----請重選----\n");
			}
		}
		else
		{
			system("cls");
			printf("----請重選----\n");
		} 
	}
}

void drawcard(int card[],int player_one_hand[],int player_two_hand[],char* cardcolors[])
{
	int a=0,b=0,c=0;
	while(1)
	{
		printf("可以抽的卡有:\n");
		int y;
		for(y=1;y<=27;y++)
		{
			if(player_two_hand[y]!=0)
			{
				printf("%d\n",y);
			}
		} 
		printf("請選擇你要抽的卡:");
		scanf("%d",&a);
		if(player_two_hand[a]!=0)
		{
			system("cls");
			printf("-----選擇抽卡放置位置-----\n");
			printcardyouhave(card,player_one_hand,player_two_hand,cardcolors);
			printf("請選擇要放入的位置:");
			while(1)
			{
				scanf("%d",&b);
				if(player_one_hand[b]==0)
				{
					player_one_hand[b]=player_two_hand[a];
					player_two_hand[a]=0;
					system("cls");
					break;
				}
				else
				{
					system("cls");
					printf("----請重選----\n");
					printcardyouhave(card,player_one_hand,player_two_hand,cardcolors);
					printf("此位有卡 請重選:");
				}
			}
			system("cls");
			printf("你抽到了 %s\n",cardcolors[player_one_hand[b]]);
			break;
		}
		else
		{
			system("cls");
			printf("此卡位空白 請重選，");
		}
	}
}
	
void comthrowcard(int card[],int player_one_hand[],int player_two_hand[],char* cardcolors[])
{
	int t=0;
	while(t!=150)
	{
		int a=0,b=0,aa=0,bb=0;
		a=rand()%27+1;;
		b=rand()%27+1;;
		aa=player_two_hand[a];
		bb=player_two_hand[b];
		int c=0,d=0;
		for(c=1;c<=27;c++)
		{
			if(player_two_hand[c]!=0)
			{
				d++;
			}
			else
			{
			
			}
		}
		if((aa % 13 == bb % 13)&&(aa!=bb)&&(aa!=53&&bb!=53)&&(aa!=0&&bb!=0))
		{ 
			player_two_hand[a]=0;
			player_two_hand[b]=0;
			break;
		}
		else if(d==1)
		{
			break;
		}
		printf("loading...");
		system("cls");
		t++;
	}
}

void comdrawcard(int card[],int player_one_hand[],int player_two_hand[],char* cardcolors[])
{
	srand(time(NULL));
	int a=0,b=0;
	while(1)
	{
		a=rand()%(27-1+1)+1;;
		if(player_one_hand[a]!=0)
		{
			while(1)
			{
				b=rand()%(27-1+1)+1;;
				if(player_two_hand[b]==0)
				{
					player_two_hand[b]=player_one_hand[a];
					player_one_hand[a]=0;
					break;
				}
			else
				{
					
				}
			}
			break;
		}
		else
		{
			
		}
	}
}

void checkwin(int card[],int player_one_hand[],int player_two_hand[],char* cardcolors[])
{
	int a=0,b=0;
	for(a=1;a<=27;a++)
	{
		if(player_one_hand[a]!=0)
		{
			b++;
		}
	}
	int c=0,d=0;
	for(c=1;c<=27;c++)
	{
		if(player_two_hand[c]!=0)
		{
			d++;
		}
	}
	int aa,bb;
	if(b==1)
	{
		for(aa=1;aa<=27;aa++)
		{
			if(player_one_hand[aa]!=0)
			{
				bb=player_one_hand[aa];
			}
		}
	}
	else if(b==0)
	{
		winplayer=1;
	}
	int cc,dd;
	if(d==1)
	{		
		for(cc=1;cc<=27;cc++)
		{
			if(player_two_hand[cc]!=0)
			{
				dd=player_two_hand[cc];
			}
		}
	}
	else if(d==0)
	{
		winplayer=2;
	}
	else if(bb==53)
	{
		winplayer=2;
	}
	else if(dd==53)
	{
		winplayer=1;
	}
	else
	{
		winplayer=0;
	}
}


