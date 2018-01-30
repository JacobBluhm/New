
//variables
int boardSize = 9;
char gameBoard[9];
int playerTurn = 0;
int move = 0;
bool valid = 0;
int o = 0;
bool finish;
int check1, check2, check3, check4, check5, check6,check7,check8;
int valg; 

//functions


bool menu();
void printGameboard();
void init();
bool validate();
bool win();
