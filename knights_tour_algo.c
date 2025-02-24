

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
void displayPath();


//global declaration
Square tile[64];
int path[64][2], moveCount;

/*MAIN FUNCTION*/

int main (){
	
	int x, y, currentIndex;

	
	assignCoord();
	currentIndex = startSquare(&x, &y);
	possibleSquares(currentIndex);
	displayPath();
	
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
				tile[i].visited = 0;
				tile[i].degree = 0;
				i++;
			}
		}
}

int startSquare(int *startX, int *startY){
	
	int valid = 0;
	
	while (!valid){

	//input part
	
	printf("Enter the coordinates of the knight's starting position (starting from 1 1, to 8 8): ");

	
	//input validation part
	if (scanf("%d %d", &(*startX), &(*startY)) != 2){
		printf("Invalid input, please enter 2 integers.\n");
		while (getchar() != '\n');
		continue;
	}
	if (((*startX >= 1)&&(*startX <= 8))&&((*startY >= 1)&&(*startY <= 8))){
		valid = 1;
	}else{
		printf("Invalid input, please enter values from 1 to 8.\n");
		continue;
	}
	//identify which tile does the coordinates correspond to:
	int i;
	
	for (i = 0; i < 64; i++){
		
		if ((tile[i].x == *startX)&&(tile[i].y == *startY)){
			moveCount = 0;
			path[moveCount][0] = tile[i].x;
			path[moveCount][1] = tile[i].y;
			tile[i].visited = 1;
			valid = 1;
			return (i);
		}
	}
	
	return -1;
	}
}

int possibleSquares(int index){
	int lowestDeg, lowestIndex, i, j, k, l, mov, newIndex, bounded, newX, newY, visitedflag;
	Square validMoves[8][2];
	
	for (mov = 0; mov < 63; mov++){
	
		// Possible knight moves relative to (x, y)
		int moveX[8] = {  2,  1, -1, -2, -2, -1,  1,  2 };
		int moveY[8] = {  1,  2,  2,  1, -1, -2, -2, -1 };
		
		lowestDeg = 9;
		lowestIndex = -1;
		
		
		for (i = 0; i < 8; i++){
			bounded = 0;
			//calculate move range
			newX = tile[index].x + moveX[i];
			newY = tile[index].y + moveY[i];
			//check if move is bounded, and its correspondence to the coordinates
			for (l = 0; l < 64; l++){
				if ((tile[l].x == newX)&&(tile[l].y == newY)){
					newIndex = l;
					bounded = 1;
					break;
				}
			}
			
			if (!bounded){
				continue;
			}
			
			//check if visited
			if (tile[newIndex].visited == 1){
				continue;
			}
			
			//calculate no. of possible moves from current tile
			tile[newIndex].degree = 0; //restart degree for calculation
			for (k = 0; k < 8; k++){
				int checkX = tile[newIndex].x + moveX[k];
				int checkY = tile[newIndex].y + moveY[k];
					
				//check if move is already visited
				visitedflag = 0;
				for (j = 0; j < 64; j++){
					if ((path[j][0] == checkX)&&(path[j][1] == checkY)){
						visitedflag = 1;
						break;
					}
				}
				//validate if not visited and bound
				if ((checkX > 0)&&(checkX <= 8)&&(checkY > 0)&&(checkY <= 8)&&(visitedflag == 0)){
					tile[newIndex].degree++;
				}
			}
			// lowest comparison
			if (tile[newIndex].degree < lowestDeg) {
                lowestDeg = tile[newIndex].degree;
                lowestIndex = newIndex;
            }
		}
			 // Ensure a valid move was found
	        if (lowestIndex == -1) {
	            printf("No valid moves found! The tour is incomplete.\n");
	            return 0;
	        }
			//set the move to visited
			tile[lowestIndex].visited = 1;
			
			//write to path
			moveCount++;
			path[moveCount][0] = tile[lowestIndex].x;
			path[moveCount][1] = tile[lowestIndex].y;
			
			//set next index to the index of the last move
			index = lowestIndex;
	}
	
	return 1;
}

void displayPath (){
	int i;
	
	printf("\n<@@ KNIGHT'S TOUR PATH @@>\n");
	
	for (i = 0; i < 64; i++){
		
		printf("(%d, %d), ", path[i][0], path[i][1]);
		if (i % 8 == 7) {
		printf("\n");
		}
	}
	
	printf("\n\n%d", moveCount + 1);
	
}

