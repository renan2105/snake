#include<windows.h>
#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include <windows.h>

enum DOS_COLORS {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };
void textcolor (DOS_COLORS iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}
void mgotoxy(int x,int y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

int main()
{   
	int x, d=2, cx[300]={6,2}, cy[300]={7,7}, t=1, mx, my;
	int vel =100, vel2 =5, pontos =0, nivel =1;
	char niv;
    char tecla='a';
    
    
    for(x=5;x<23;x++) 
    {   mgotoxy(5,x);
        printf("%c",219);
        textcolor(CYAN);
    }
    for(x=5;x<55;x++)  
    {   mgotoxy(x,5);
        printf("%c",219);
    }
    for(x=5;x<23;x++) 
    {   mgotoxy(55,x);
        printf("%c",219);
    }
    for(x=5;x<56;x++)   
    {   mgotoxy(x,23);
        printf("%c",219);
    }
    srand(time(NULL));
    mx=(rand()%25)+6; 
    my=(rand()%17)+6;
    
    vel = 200;
    while(tecla!='s')
    {   while(tecla!='s'&&!(tecla=kbhit()))
    
        {   for(x=t;x>0;x--)
            {   cx[x]=cx[x-1];
                cy[x]=cy[x-1];
            }
            if(d==0)cx[0]--;
            if(d==1)cy[0]--;
            if(d==2)cx[0]++;
            if(d==3)cy[0]++;
            mgotoxy(cx[t],cy[t]);
            printf(" "); 
            textcolor(LIGHT_RED);
            if(mx==cx[0]&&my==cy[0])
            {   t++;
                pontos++;
                mx=(rand()%25)+6;
                my=(rand()%17)+6;
                vel -=5;
                vel2+=5;
            }         
          
            mgotoxy(cx[0],cy[0]);
            
            printf("%c",219);
            mgotoxy(mx,my);
			printf("%c",4);
			mgotoxy(60,15);
			
			textcolor(LIGHT_GREEN);
			printf("Pontos: %d ",pontos);
			mgotoxy(60,10);
			printf("Nivel: %d",nivel);
			mgotoxy(60,8);
			printf("Velocidade: %d",vel2);
			mgotoxy(8,27);
			if(pontos>nivel*2)
			{nivel++;
			}
			
			Sleep(vel);			           

            for(x=1;x<t;x++)
            {   if(cx[0]==cx[x]&&cy[0]==cy[x])tecla='s';
            }
            if(cy[0]==5||cy[0]==23||cx[0]==5||cx[0]==55)tecla='s';
        }
        if(tecla!='s')tecla=getch();
        if(tecla=='K')d=0;
        if(tecla=='H')d=1;
        if(tecla=='M')d=2;
        if(tecla=='P')d=3;
        if(cy[0]==5||cy[0]==23||cx[0]==5||cx[0]==55)tecla='s';
    }
    
    system("cls");
    system("pause");
    
    printf("\n\n\tPERDEU LIXO\n\n");
    printf("\n\n\tCOMEU %d MACÇS",pontos);
    getch();
}
