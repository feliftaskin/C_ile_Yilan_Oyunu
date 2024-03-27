#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
//goto fonkdiyonu ogrenildi yapýldý
//ANSII tuslar ogrenildi
int yilan_alani[80][23]={0};

struct icerik {int a,b;
int yilan_kuyruk_sutun[300];
int yilan_kuyruk_satir[300];};

int j;
int oyun_devam=1;

struct icerik t;

// ineternetten gecirdigimiz kisim
void gotoxy(short x ,short y){
HANDLE hConsoleOutput;
COORD Cursor_Pos={x-1,y-1};

hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}


void baslangic(FILE *pf){
	char s1[50];
	 char s2[50];
	  char s3[50];
 pf=fopen("mainprojegç.c","r");
 if(pf==NULL){	
 printf("gecersiz dosya!\n");
 exit(1);
 }
 fscanf(pf,"%s%s%s",s1,s2,s3);
 fclose(pf);
 printf("%s %s %s",s1,s2,s3);
 getch();
}

// yilanin dolasacagi alanin sinirlari
void oyun_sinirlari(int x1, int y1, int x2, int y2, int tur){
    int i;
    //sutun sinirlari
    for(i=x1;i<=x2;i++){
        yilan_alani[i][y1]=tur;
        yilan_alani[i][y2]=tur;
    }
    //satir sinirlari
    for(i=y1;i<=y2;i++){
        yilan_alani[x1][i]=tur;
        yilan_alani[x2][i]=tur;
    }
}


//yilanin ekranda dolasacagi kisimlar
void ekran_dolas(){
  int x,y;
    for(x=0;x<80;x++){
        for(y=0;y<23;y++){
            gotoxy(x+1,y+1);
            if(yilan_alani[x][y]==2){
                printf("%c",176);
            }
        }
    }
}

//yemin rastgele atanmasi
int random_yem(){

      srand(time(NULL));
      t.a=4+rand()%65;
      t.b=4+rand()%15;
}

void main(){
FILE *fp;
baslangic(fp);
random_yem();
oyun_sinirlari(0,0,79,22,2);
ekran_dolas();
unsigned char tus;
int ax=40,ay=12;
int by=0;
int bx=0;
int k=0;//kuyruk uzunlugunu artmasi

do{
        // sag sol tuslari ANSII dan bakildi
	if(kbhit()){
        tus=getch();
        if(tus==224){
            tus=getch();
            switch(tus)
            {
                case 72: by=-1; bx=0;
                break;
                case 80: by=1; bx=0;
                break;
                case 77: bx=1; by=0;
                break;
                case 75:  bx=-1; by=0;
            }
        }
	}
//yilanin oyun alanindan Ã§Ä±kmamasi iÃ§in yapilmiÅŸtir
	ax=ax+bx;
	ay=ay+by;
    if(ax>78){
      printf("YANDINIZ\n");
      oyun_devam=0;}
    if(ax<2){
      printf("YANDINIZ\n");
      getch();
      oyun_devam=0;}
    if(ay>22){
        printf("YANDINIZ\n");
        getch();
        oyun_devam=0;}
    if(ay<2){
        printf("YANDINIZ\n");
        getch();
          oyun_devam=0;}

t.yilan_kuyruk_sutun[0]=ax;
t.yilan_kuyruk_satir[0]=ay;

for(j=1;j<=k;j++){
    if(ax==t.yilan_kuyruk_sutun[j]&& ay==t.yilan_kuyruk_satir[j]){
        gotoxy(ax,ay);printf("YANDINIZ");
        getch();
        oyun_devam=0;
    }
}


gotoxy(ax,ay);printf("*");

for(j=0;j<=k;j++){
    gotoxy(t.yilan_kuyruk_sutun[j],t.yilan_kuyruk_satir[j]);printf("*");
}
//yemle karsilastiginda almasi ve puan yazilmasi
  if(ax==t.a && ay==t.b){
    random_yem();
    k++;
    gotoxy(2,2);printf("Puan=%d",k);
  }

gotoxy(t.a,t.b); printf("+");

//aninda yem alinmamasi ara verilmesi iÃ§in bu fonksiyon ogrenildi
Sleep(60);
gotoxy(ax,ay); printf(" ");

for(j=0;j<=k;j++){
    gotoxy(t.yilan_kuyruk_sutun[j],t.yilan_kuyruk_satir[j]);printf(" ");
}


for(j=k;j>0;j--){
    t.yilan_kuyruk_sutun[j]=t.yilan_kuyruk_sutun[j-1];
    t.yilan_kuyruk_satir[j]=t.yilan_kuyruk_satir[j-1];
}

} while(oyun_devam==1);



}






