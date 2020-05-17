#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
/*********************************************************************************************************************
* Developer : Cezain Majeed
* Purpose   : Snake game.
*********************************************************************************************************************/
int height=40,width=20,gameover;
int x,y,foodx,foody,score=0,flag;
int tailx[100],taily[100];
int cntail=0;
void setup()
{
    gameover=0;
    x=width/2;
    y=height/2;

    label1:
    foodx=rand()%20;
    if(foodx==0)
        goto label1;

    label2:
    foody=rand()%40;
    if(foody==0)
        goto label2;

    score=0;
}
void draw()
{
    int i,j,k;
    system("cls");
    for(i=0;i<width;i++)
    {
        for(j=0;j<height;j++)
        {
            if(i==0 || i==width-1 ||j==0 ||j==height-1)
            printf("#");
            else
            {
                if(i==x && j==y)
                printf("0");
                else if(i==foodx && j==foody)
                printf("*");
                else
                {
                    int ch=0;
                    for(k=0;k<cntail;k++)
                    {
                        if(i==tailx[k] && j==taily[k])
                        {
                            printf("o");
                            ch=1;
                        }
                    }
                    if(ch==0)
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("SCORE = %d",score);
}
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'a':
                flag=1;
                break;
            case 'd':
                flag=2;
                break;
            case 'w':
                flag=3;
                break;
            case 's':
                flag=4;
                break;
            case 'x':
                gameover=1;
                break;

        }
    }
}
void logic()
{
    int i;
    int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x,prev2y;
    tailx[0]=x;
    taily[0]=y;

    for(i=1;i<cntail;i++)
    {
        prev2x=tailx[i];
        prev2y=taily[i];

        tailx[i]=prevx;
        taily[i]=prevy;

        prevx=prev2x;
        prevy=prev2y;
    }


    switch(flag)
    {
    case 1:
        y--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x--;
        break;
    case 4:
        x++;
        break;
    default:
        break;
    }
    if(x<0 ||x>width ||y<0||y>height)
        gameover=1;
    for(i=0;i<cntail;i++)
    {
        if(x==tailx[i] && y==taily[i])
            gameover=1;
    }

    if(x==foodx && y==foody)
    {
        label3:
    foodx=rand()%20;
    if(foodx==0)
        goto label3;

    label4:
    foody=rand()%40;
    if(foody==0)
        goto label4;

    score+=10;
    cntail++;
    }
}
int main()
{
    char c;
    label5 :
    setup();
    while(!gameover)
    {
        draw();
        input();
        logic();

        for(int n=0;n<1000;n++)
        {
            for(int m=0;m<10000;m++)
            {

            }
        }

        for(int n=0;n<1000;n++)
        {
            for(int m=0;m<10000;m++)
            {

            }
        }
    }
    printf("\nPress Y to play again.");
    scanf("%c",&c);
    if(c=='y'||c=='Y')
        goto label5;
    return 0;

}
