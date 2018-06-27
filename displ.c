#include <REGX51.H>
#include <math.h>
#define data_pin P2

sbit RS=P3^0;
sbit E=P3^2;
char a[8];



void delay(unsigned int count);
void lcd_cmd(char cmd);
void lcd_data(char dat);
void lcd_string(char *ptr);
void lcd_start();
char getchar(int i);
void getval(char a[]);
void getar(void);

void main(void)
{
	
	
	
	lcd_start();
	while(1)
	{
		int i;
		getar();		
		lcd_cmd(0x80);
		lcd_string("volt");
				
		for(i=0;i<8;i++){
			lcd_data(getchar(a[i]));
		}
		
	}
}

void getar(void){
	a[0]=P1^0;
	a[1]=P1^1;
	a[2]=P1^2;
	a[3]=P1^3;
	a[4]=P1^4;
	a[5]=P1^5;
	a[6]=P1^6;
	a[7]=P1^7;
}

char getchar(int i){
	if(i==1)
		return '1';
	else
		return '0';
}
void getval(char *a){
	int i,j=0,s=0;
	for(i=0;i<8;i++,j++){
		s=s+pow(j,i);
	}
	
}
void delay(unsigned int count){
	int i,j;
	for(i=0;i<count;i++)
		for(j=0;j<1000;j++);
}

void lcd_cmd(char cmd){
	data_pin =cmd;
	RS=0;
	E=1;
	delay(1);
	E=0;
}

void lcd_data(char dat){
	data_pin =dat;
	RS=1;
	E=1;
	delay(1);
	E=0;
}

void lcd_string(char *ptr){
	while(*ptr !='\0'){
		lcd_data(*ptr);
		ptr++;
	}
}

void lcd_start(){
	lcd_cmd(0x38);
	lcd_cmd(0x0E);
	lcd_cmd(0x06);
	lcd_cmd(0x0C);
}