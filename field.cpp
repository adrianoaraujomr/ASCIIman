#include <iostream>
#include <cstdlib>

#define MAX_LINES 15
#define MAX_COLUMNS 21
#define MAX_BLOCKS 50

using namespace std;

char field[MAX_LINES][MAX_COLUMNS];
int player_pos[2] = {1,2};
int bomb_clock = -1;
int bomb_pos[2] = {1,1};

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
	int a = player_pos[0]; //line coordenate
	int b = player_pos[1]; //column coordenate

	cout << pl_input << endl;

	switch(pl_input){
		case 'w' : 
			a -= 1;
			if(a > 0 && field[a][b] == ' ') player_pos[0] = a;

			break;
		case 'a' :
			b -= 1;
			if(b > 0 && field[a][b] == ' ') player_pos[1] = b;

			break;
		case 's' :
			a += 1;
			if(a < MAX_LINES && field[a][b] == ' ') player_pos[0] = a;

			break;
		case 'd' :
			b += 1;
			if(b < MAX_COLUMNS && field[a][b] == ' ') player_pos[1] = b;

			break;
		case 'b' :
			if(bomb_clock == -1) {
				field[a][b] = 'o';
				bomb_pos[0] = a;
				bomb_pos[1] = b;
				bomb_clock = 4; //240
			}

			break;
	}

	a = bomb_pos[0];
	b = bomb_pos[1];

	if(bomb_clock == 0){
		bomb_clock = -1;
		for(int l = a - 1;l < a + 2;l++){
			for(int c = b - 1;c < b + 2;c++){
				if(l == player_pos[0] && c == player_pos[b]) exit(1);
				if(field[l][c] == '#' || field[l][c] == 'o') {
					field[l][c] = ' ';
				}
			}
		}
	}

	if(bomb_clock > 0) bomb_clock -= 1;
}

void display_field(){

	for(int i{0};i < MAX_LINES;i++){
		for(int j{0};j < MAX_COLUMNS;j++){
			if(i == player_pos[0] && j == player_pos[1]) cout << 'A' << ' ';
			else cout << field[i][j] << ' ';
		}
		cout << endl;
	}
}

int main(){
	char pl_input;

	create_field();

	while(1){
		display_field();
		cout << "bomb_clock = " << bomb_clock << endl;
		cout << "player_pos = (" << player_pos[0] << "," << player_pos[1] << ")" << endl;
		cout << "bomb_pos = (" << bomb_pos[0] << "," << bomb_pos[1] << ")" << endl;

		cin >> pl_input;
		process_input(pl_input);
		system("clear");
	}
	
	return 0;
}
