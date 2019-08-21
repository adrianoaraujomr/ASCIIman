#include <iostream>
#include <cstdlib>

#define MAX_LINES 15
#define MAX_COLUMNS 21
#define MAX_BLOCKS 50

using namespace std;

char field[MAX_LINES][MAX_COLUMNS];
int player_pos[2] = {1,1};

void create_field(){

	for(int i{0};i < MAX_LINES;i++){
		for(int j{0};j < MAX_COLUMNS;j++){
			if(i == 0 || j == 0 || i == MAX_LINES - 1 || j == MAX_COLUMNS - 1|| (i%2 == 0 && j%2 == 0)) field[i][j] =  '*';
			else field[i][j] = ' ';
		}
	}

	int i = 0;

	while(i != MAX_BLOCKS){
		int x,y;

		x = (rand() % MAX_LINES/2)*2 + 1;
		y = (rand() % MAX_COLUMNS/2)*2 + 1;

		field[x][y] = '#';

		i += 1;
	}

}

void process_input(char pl_input){
	int x = player_pos[0];
	int y = player_pos[1];			

	cout << pl_input << endl;

	switch(pl_input){

		case 'w' : 
			y -= 1;
			if(y > 0 && field[x][y] == ' ') player_pos[1] = y;

			break;
		case 'a' :
			x -= 1;
			if(x > 0 && field[x][y] == ' ') player_pos[0] = x;

			break;
		case 's' :
			y += 1;
			if(y < MAX_LINES && field[x][y] == ' ') player_pos[1] = y;

			break;
		case 'd' :
			x += 1;
			if(x < MAX_COLUMNS && field[x][y] == ' ') player_pos[0] = x;

			break;
		case 'b' :
			field[y][x] = 'o';

			break;

	}
}

void display_field(){

	for(int i{0};i < MAX_LINES;i++){
		for(int j{0};j < MAX_COLUMNS;j++){
			if(i == player_pos[1] && j == player_pos[0]) cout << 'A' << ' ';
			else cout << field[i][j] << ' ';
		}
		cout << endl;
	}
}

int main(){

	create_field();

	while(1){
		display_field();
		char pl_input;

		cin >> pl_input;
		process_input(pl_input);
		system("clear");
	}
	
	return 0;
}
