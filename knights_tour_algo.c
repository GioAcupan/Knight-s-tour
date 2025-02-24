#include <stdio.h>


//each coordinate as a struct
typedef struct {
	int x,y;
	int visited;
	int degree;
}Square;

//function declaration
void assignCoord();
int startSquare(int *startX, int *startY);
int possibleSquares(int index);


//global declaration
Square tile[64];
int path[64][2], moveCount;

/*MAIN FUNCTION*/

int main (){
	
	int x, y, currentIndex;

	
	assignCoord();
	currentIndex = startSquare(&x, &y);
	
	
}

//function definition

void assignCoord(){
	int X, Y;
	int i = 0;
	
	//give each tile a coordinate
		for (X = 1; X <= 8; X++){
			for (Y = 1; Y <= 8; Y++){
				tile[i].x = X;
				tile[i].y = Y;
				i++;
				tile.visited = 0;
				tile.degree = 0;
			}
		}
}

int startSquare(int *startX, int *startY){
	
	int valid = 0;
	
	while (!valid){

	//input part
	
	printf("Enter the coordinates of the knight's starting position (starting from 1 1, to 8 8): ");

	
	//input validation part
	if (scanf("%d %d", startX, startY) != 2){
		printf("Invalid input, please enter 2 integers.\n");
		while (getchar() != '\n');
		continue;
	}
	if (((*startX >= 1)&&(*startX <= 8))&&((*startY >= 1)&&(*startY <= 8))){
		
	}else{
		printf("Invalid input, please enter values from 1 to 8.");
		continue;
	}
	//identify which tile does the coordinates correspond to:
	int i;
	
	for (i = 0; i < 64; i++){
		
		if ((tile[i].x == startX)&&(tile[i].y == startY)){
			moveCount = 0;
			path[moveCount][0] = tile[i].x;
			path[moveCount][1] = tile[i].y;
			return (i);
		}
		
	}

	}
}

int possibleSquares(int index){
	int lowest, j, newIndex, bounded = 0, newX, newY;
	Square validMoves[8][2];
	
	// Possible knight moves relative to (x, y)
	int moveX[8] = {  2,  1, -1, -2, -2, -1,  1,  2 };
	int moveY[8] = {  1,  2,  2,  1, -1, -2, -2, -1 };
	
	for (j = 0; j < 8; j++){
		//calculate move range
		newX = tile[index].x + moveX[j];
		newY = tile[index].y + moveY[j];
		//check if move is bounded, and its correspondence to the coordinates
		for (j = 0; j < 64; j++){
			if ((tile[j].x == newX)&&(tile[j].y == newY)){
				newIndex = j;
				bounded = 1;
			}
		}
		
		if (!bounded){
			break;
		}
		
		//calculate possible moves from current tile
		for (j = 0; j < 8; j++){
			newX = tile[newIndex].x + moveX[j];
			newY = tile[newIndex].y + moveY[j];	
			
			if ((newX > 0)&&(newX <= 8)&&(newY <= 8))
		}
		
	}

	
	
}


