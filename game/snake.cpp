#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

void mgotoxy(int x,int y){
	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

int main(void){

	int x,direcao=2,cx[300]={1,2},cy[300]={7,7},tamanho=1,macax,macay;
	char tecla='a';
	
	for(x=0;x<18;x++){
		mgotoxy(0,x);
		printf("%c",219);
	}

	for(x=0;x<26;x++){
		mgotoxy(x,0);
		printf("%c",219);
	}

	for(x=0;x<18;x++){
		mgotoxy(26,x);
		printf("%c",219);
	}

	for(x=0;x<27;x++){
		mgotoxy(x,18);
		printf("%c",219);
	}

	srand(time(NULL));
	macax=(rand()%25)+1;
	macay=(rand()%17)+1;

	while(tecla!='s'){
		while(tecla!='s'&&!(tecla=kbhit())){
			for(x=tamanho;x>0;x--){
				cx[x]=cx[x-1];
				cy[x]=cy[x-1];
			}

			if(direcao==0)cx[0]--;
			if(direcao==1)cy[0]--;
			if(direcao==2)cx[0]++;
			if(direcao==3)cy[0]++;

			mgotoxy(cx[tamanho],cy[tamanho]);
			printf(" ");

			if(macax==cx[0]&macay==cy[0]){
				tamanho++;
				macax=(rand()%25)+1;
				macay=(rand()%17)+1;
			}

			mgotoxy(cx[0],cy[0]);
			printf("%c",219);
			mgotoxy(macax,macay);
			printf("%c",1);
			Sleep(200);

			for(x=1;x<tamanho;x++){
				if(cx[0]==cx[x]&cy[0]==cy[x])tecla='s';
			}
			if(cy[0]==0||cy[0]==18||cx[0]==0||cx[0]==26)tecla='s';
		}

		if(tecla!='s')tecla=getch();
		if(tecla=='K')direcao=0;
		if(tecla=='H')direcao=1;
		if(tecla=='M')direcao=2;
		if(tecla=='P')direcao=3;
		if(cy[0]==0||cy[0]==18||cx[0]==0||cx[0]==26)tecla='s';
	}
    
	getch();
	return 0;
}