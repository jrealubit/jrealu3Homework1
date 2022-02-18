# jrealu3Homework1

(i) Functions:

int inputToInt(char v); //parses character in text file to be used by other functions
bool isPresentRow(int r, int num); //checks if number is already in row
bool isPresentCol(int c, int num); //checks if number is already in column
bool isPresentSubBoard(int subBeginR, int subBeginC, int num); //checks if number is already within a 3x3 section of the board
bool findEmpty(int &r, int &c); //finds an empty space on the board
bool isValid(int r, int c, int num); //checks to see if a number can be placed within a certain spot
bool solve(); //provides a solution to the board
void printBoard(); //outputs solves board

(ii) Functions for consistency check:

bool isPresentRow(int r, int num); 
bool isPresentCol(int c, int num); 
bool isPresentSubBoard(int subBeginR, int subBeginC, int num);

(iii) Functions for backtrack search:

bool findEmpty(int &r, int &c);
bool isValid(int r, int c, int num); 
bool solve();

Notes:
I could not get the program to work, the most trouble I had was from reading and storing values from the text file.





