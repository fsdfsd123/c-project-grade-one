#include <cstdlib> 
#include <curses.h>
#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

class final             
{
	public:
		final(int a, int b);
		void output();
		void moveP();
		void moveC();
		void testP(int a, int b);
		void testC(int a, int b);
		bool test();
	private:
		int x[24][80];
		int* t[8];
		int n;
};

int main()
{
	srand(time(0));
	final cpp(0,0);
	int a, b;
	char ch;
	
while(1){
	cout << "PRODUCTOR: ";
	cin >> a;
	cout << "CONSUMER: ";
	cin >> b;
	
	while(a<0 || b<0 || a+b>1920){
		cout << "ERROR" << endl;
		cout << "PRODUCTOR: ";
		cin >> a;
		cout << "CONSUMER: ";
		cin >> b;
	}
	cpp = final(a, b);
	initscr();
	start_color();
	while(cpp.test()){
		cpp.output();
		cpp.moveP();
		cpp.moveC();
		Sleep(500);
	}
	erase();
	move(12,32);
	addstr("GAME OVER !");
	move(14,29);
	addstr("enter \"1\" to quit");
	move(24,0);
	refresh();
	ch = getch();
	if(ch == '1'){
		break;
	}
	endwin();
	initscr();
	endwin();
}
    return 0;
}

void final::output(){
	int i, j;
	
    init_pair(1, COLOR_GREEN, COLOR_BLACK);	
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
	
	erase();
	for(i=0; i<24; i++){
		for(j=0; j<80; j++){
			if(x[i][j] > 0){
				move(i, j);			
				if(x[i][j]==1){
					attrset(COLOR_PAIR(1));
					addch('*');	
					attroff(COLOR_PAIR(1));				
				}
				else{
					addch('*');	
				}
			}
			if(x[i][j] < 0){
				move(i, j);
				if(x[i][j]%3==0){
					attrset(COLOR_PAIR(3));
					addch('@');	
					attroff(COLOR_PAIR(3));
				}
				else{
					attrset(COLOR_PAIR(2));
					addch('@');	
					attroff(COLOR_PAIR(2));
				}
			}
		} 
	}
	refresh();
} 
void final::moveP(){
	int i, j, k;
	for(i=0; i<24; i++){
		for(j=0; j<80; j++){ 
			if(x[i][j] > 0 && x[i][j] < 100){
				testP(i,j);
				if(n > 0){
					k = rand() % n;
					if(x[i][j] % 3 == 0){
						*t[k] = 101;
						x[i][j] ++;
					}
					else{
						*t[k] = x[i][j] + 101;
						x[i][j] = 0;
					}
				}
				else{
					x[i][j] ++;
				}
			}
		}
	}
	for(i=0; i<24; i++){
		for(j=0; j<80; j++){
			if(x[i][j] > 100)
				x[i][j] -= 100;
			if(x[i][j] == 99)
				x[i][j] = 3;
		}
	}
}
void final::moveC(){
	int i, j, k;
	for(i=0; i<24; i++){
		for(j=0; j<80; j++){
			if(x[i][j] < 0 && x[i][j] > -100){
				testC(i,j);
				if(n > 0){
					k = rand() % n;
					if(*t[k] == 0 && x[i][j] % 3 != 0){
						*t[k] = x[i][j] - 101;
						x[i][j] = 0;
					}
					else if(*t[k] == 0){
						x[i][j] = 0;
					}
					if(*t[k] > 0){
						*t[k] = (x[i][j]/3-1)*3 - 101 ;
						x[i][j] = -1;
					}
				}
				else{
					if(x[i][j] % 3 == 0){
						x[i][j] = 0;
					}
					else{
						x[i][j] --;
					}
				}
			}
		}
	}
	for(i=0; i<24; i++){
		for(j=0; j<80; j++){
			if(x[i][j] < -100)
				x[i][j] += 100;
			if(x[i][j] == -100)
				x[i][j] = -3;
		}
	}
}
void final::testP(int a, int b){
	int i, j;
	n = 0;
		for( i=a-1; i<=a+1 && i<24; i++ ){
			if(i < 0){
				i = 0;
			}
			for( j=b-1; j<=b+1 && j<80; j++ ){
				if(j < 0){
					j = 0;
				}
				if( x[i][j] == 0 ){
					t[n] = &x[i][j];
					n++;
				}
			}
		}
}
void final::testC(int a, int b){
	int i, j;
	n = 0;
	for( i=a-1; i<=a+1 && i<24; i++ ){
		if(i < 0){
				i = 0;
			}
		for( j=b-1; j<=b+1 && j<80; j++ ){
			if(j < 0){
					j = 0;
				}
			if( x[i][j] > 0 ){
				t[n] = &x[i][j];
				n++;	
			}
		}
	}
	if(n == 0){
		for( i=a-1; i<=a+1 && i<24; i++ ){
			if(i < 0){
				i = 0;
			}
			for( j=b-1; j<=b+1 && j<80; j++ ){
				if(j < 0){
					j = 0;
				}
				if( x[i][j] == 0 ){
					t[n] = &x[i][j];
					n++;	
				} 
			}
		}
	}
}
final::final(int a, int b){
	int* c = new int [a+b];
	int i, j, temp;
	for(i=0; i<24; i++){
		for(j=0; j<80; j++){
			x[i][j] = 0;
		}
	}
	for(i=0; i<a+b; i++){
		temp = rand() % 1920;
		c[i] = temp;
		for(j=0; j<i; j++){
			if(c[j] == temp)
				break;
		}
		if(j != i)
			i--;
	}
	for(i=0; i<a; i++){
		x[c[i]/80][c[i]%80] = 1; 
	}
	for(i=a; i<a+b; i++){
		x[c[i]/80][c[i]%80] = -1;
	}
	delete[] c;
}
bool final::test(){
	int i, j, n=0, m=0;
	for(i=0; i<24; i++){
		for(j=0; j<80; j++){
			if(x[i][j] == 0)
				n++;
			else if(x[i][j] > 0)
				m++;
		}
	}
	if(n == 24*80 || m == 24*80)
		return false;
	return true;
}

