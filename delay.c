#include <REGX51.H>
sbit v1=P2^0;
sbit v2=P2^1;
sbit v3=P2^2;
sbit v4=P2^3;
sbit v5=P2^4;
sbit v6=P2^5;
sbit v7=P2^6;

void delay(int);
void one();
void txo();
void three();
void four();


int main(){
	
	v5=0x00;
	v6=0x00;
	v7=0x00;
	v1=0x00;
	v2=0x00;
	v3=0x00;
	v4=0x00;
	//delay(1000);
	
	while(1){
	one();
	//delay(100);
	txo();
		three();
		four();
		}
	
}
void one(){v1=1;
v2=0;
v3=0;
v4=0;
delay(1000);}
void txo(){v1=0;
v2=1;
v3=0;
v4=0;
delay(1000);}
void three(){v1=0;
v2=0;
v3=1;
v4=0;
delay(1000);}
void four(){v1=0;
v2=0;
v3=0;
v4=1;
delay(1000);}
void delay(int i){
	char j;
	for(i;i>0;i--)
		for(j=121;j>0;j--);
}
