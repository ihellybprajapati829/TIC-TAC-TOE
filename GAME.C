#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<ctype.h>
#define PF 'X'
#define PS 'O'
int status(char);
int checkin(int);
int play(char*);
char s[10]={' ','.','.','.','.','.','.','.','.','.'};
int turn=0,n;
char a[30],b[30];
int status(char z)
{
if((s[1]==s[2]&&s[2]==s[3]&&s[3]==z)||(s[4]==s[5]&&s[5]==s[6]&&s[6]==z)||
(s[7]==s[8]&&s[8]==s[9]&&s[9]==z)||(s[1]==s[4]&&s[4]==s[7]&&s[7]==z)||
(s[2]==s[5]&&s[5]==s[8]&&s[8]==z)||(s[3]==s[6]&&s[6]==s[9]&&s[9]==z)||
(s[1]==s[5]&&s[5]==s[9]&&s[9]==z)||(s[7]==s[5]&&s[5]==s[3]&&s[3]==z))
{
return 1;
}
else
{
return 0;
}
}
void disb(void)
{
cleardevice();
textcolor(0);
printf("\n\n\n\n\n");
setlinestyle(0,1,2);
setcolor(10);
rectangle(150,60,500,240);
setlinestyle(3,1,2);
setcolor(6);
line(150,120,500,120);
line(150,180,500,180);
line(260,60,260,240);
line(390,60,390,240);
gotoxy(26,6);
printf("%c",s[1]);
gotoxy(41,6);
printf("%c",s[2]);
gotoxy(56,6);
printf("%c",s[3]);
gotoxy(26,10);
printf("%c",s[4]);
gotoxy(41,10);
printf("%c",s[5]);
gotoxy(56,10);
printf("%c",s[6]);
gotoxy(26,14);
printf("%c",s[7]);
gotoxy(41,14);
printf("%c",s[8]);
gotoxy(56,14);
printf("%c",s[9]);
}
int checkin(int i)
{
if(i<=9)
{
if(s[i]=='.')
{
return 1;
}
printf("\t\t\tInvalid \t");
return 0;
}
return 0;
}
int play(char *p)
{
int i;
char z,m[80];
disb();
printf("\n\n\n\n\n\n\t\t\tPlayer %s\t",p);
do
{
printf("Enter Position : ");
scanf("%d",&i);
}while(!isdigit(i)&& !checkin(i));
if(p==a)
z=PF;
else
z=PS;
s[i]=z;
turn+=1;
disb();
if(turn==9&&!status(z))
{
cleardevice();
setbkcolor(9);
setlinestyle(0,1,2);
setcolor(1);
rectangle(10,10,625,470);
rectangle(7,7,622,467);
settextstyle(10,0,6);
setcolor(14);
outtextxy(35,150,"!! GAME TIE !!");
outtextxy(36,150,"!! GAME TIE !!");
outtextxy(37,150,"!! GAME TIE !!");
getch();
exit(0);

}
if(status(z))
{
cleardevice();
setbkcolor(9);
setlinestyle(0,1,2);
setcolor(1);
rectangle(10,10,625,470);
rectangle(7,7,622,467);
settextstyle(10,0,7);
setcolor(14);
outtextxy(25,100,"!! WINNER !!");
outtextxy(26,100,"!! WINNER !!");
outtextxy(27,100,"!! WINNER !!");
setcolor(1);
if(p==a)
{
setcolor(4);
settextstyle(1,0,7);
sprintf(m,"%s",p);
outtextxy(235,250, m);
}
if(p==b)
{
setcolor(4);
settextstyle(1,0,7);
sprintf(m,"%s",p);
outtextxy(235,250, m);
}
getch();
exit(0);
}
return 0;
}
void main()
{
int gd=DETECT,gm,i;
initgraph(&gd,&gm,"c:\\tc\\bgi");
{
cleardevice();
setbkcolor(14);
settextstyle(10,0,6);
setcolor(1);
outtextxy(150,25,"T");
outtextxy(290,25,"I");
outtextxy(400,25,"C");
outtextxy(150,120,"T");
outtextxy(275,120,"A");
outtextxy(400,120,"C");
outtextxy(150,210,"T");
outtextxy(280,210,"O");
outtextxy(405,210,"E");
setcolor(4);
line(120,140,490,140);
line(120,230,490,230);
line(120,145,490,145);
line(120,235,490,235);
line(240,30,240,330);
line(245,30,245,330);
line(360,30,360,330);
line(365,30,365,330);
setcolor(2);
settextstyle(0,0,2);
outtextxy(150,385,"PRESS ENTER TO START");
setcolor(6);
rectangle(143,373,468,408);
rectangle(145,375,470,410);
rectangle(10,5,630,475);
rectangle(8,3,628,473);
}
getch();
clrscr();
cleardevice();
setbkcolor(0);
setlinestyle(0,1,2);
setcolor(7);
rectangle(180,120,450,250);
rectangle(182,122,452,252);
gotoxy(26,10);
printf("To Choose 'X'");
gotoxy(26,11);
printf("Enter 1st Player name: ");
gets(a);
fflush(stdin);
gotoxy(26,13);
printf("To Choose 'O'");
gotoxy(26,14);
printf("Enter 2nd Player name: ");
gets(b);
cleardevice();
setbkcolor(0);
disb();
while(1)
{
if(play(a))
{
break;
}
if(play(b))
{
break;
}
}
getch();
closegraph();
}
