#include <iostream>
using namespace std;
void randomnum(int *num1, int *num2,bool *display){
        srand(time(NULL));
     *num1 = rand() % 51 + 50; // This creates a random number between 50 and 100 inclusive
     *num2 = rand()% 51 +50; // Creates random number between 50 and 100
    while(*num1 > *num2){ // This ensures that the that the first randon number is not bigger than the second randon number
        *num1 = rand()% 51 +50;
        *num2 = rand()% 51 +50;
        
    }
    *display = false;// if the user has displayed before this resetes for a new set of numbers
}
void getname(string &name){
        bool letter = false;//This allows the while loop that checks if the name has invalid input
        while(!letter){ // while letter is false this loop while run
            cout << "Enter your name: ";
            getline(cin,name); // This gets the users name
            letter = true;// This will end the loop if the if there is no invalid inputs
            for (int i = 0; i < name.length(); i++) { //runs the loop for the length of the word
                if (!(isalpha(name[i]) || name[i] == ' ' || isdigit(name[i]))) { // if the word contains anything that is not a letter a number or a space it will continue the loop
                    letter = false; // this continues the loop
                    break;
                }
            }
            if (!letter) { //if the user inputted a wrong input the program will ask the user for a new input
                cout << "Your name must contain alpha numeric characters and spaces only. \n";
                cout << "Please re-enter. \n"; //This tells the user to input something diffrent
            }
    }
}
void guessSumGame(int randomNum1, int randomNum2, int &points,bool &display) {
    int add = randomNum1 + randomNum2; // Adds both numbers together
    int usrGuess; // User's guess
    char again; // Variable to check if the user wants to restart

    cout << "Enter your guess for the sum: "; // Prompt the user to guess the sum
    cin >> usrGuess; // User's guess

    if (usrGuess > (add - 5) && usrGuess < (add + 5)) { // Check if the guess is within range
        points += 5; // Give the user 5 points
        if (usrGuess == add) { // Check for exact match
            cout << "Your guess is correct. You win!" << endl;
        } else { // Close enough
            cout << "Your guess is close enough. You win!" << endl;
        }
        cout << "Your updated points are: " << points << endl; // Show updated points
        // Ask the user if they want to restart the game
        cout << "Do you want to restart the game? (Y/N): ";
        cin >> again; // Get user input
    
        while (true) {
            if (again == 'y' || again == 'Y') { // If the user wants to play again
                randomnum(&randomNum1, &randomNum2,&display); // Generate new numbers
                guessSubGame(randomNum1, randomNum2, points,display); // Restart the guessing game
                break; // Exit the loop
            } else if (again == 'n' || again == 'N') { // If the user does not want to restart
                cout << "Thank you for playing!" << endl; // End the game
                break; // Exit the loop
            } else { // Invalid input
                cout << "Error: wrong input, please try again.\n";
                cout << "Do you want to restart the game? (Y/N): ";
                cin >> again; // Ask for input again
            }
    }
    } else { // If the guess is wrong
        points--; // Deduct a point
        cout << "Wrong guess!" << endl;
        cout << "Your updated points are: " << points << endl; // Show updated points
    }
}
void guessSubGame(int randomNum1, int randomNum2, int &points,bool &display) {
    int sub = randomNum2 - randomNum1; // Adds both numbers together
    int usrGuess; // User's guess
    char again; // Variable to check if the user wants to restart

    cout << "Enter your guess for the diffrence: "; // Prompt the user to guess the sum
    cin >> usrGuess; // User's guess

    if (usrGuess > (sub - 5) && usrGuess < (sub + 5)) { // Check if the guess is within range
        points += 5; // Give the user 5 points
        if (usrGuess == sub) { // Check for exact match
            cout << "Your guess is correct. You win!" << endl;
        } else { // Close enough
            cout << "Your guess is close enough. You win!" << endl;
        }
        cout << "Your updated points are: " << points << endl; // Show updated points
        // Ask the user if they want to restart the game
        cout << "Do you want to restart the game? (Y/N): ";
        cin >> again; // Get user input
    
        while (true) {
            if (again == 'y' || again == 'Y') { // If the user wants to play again
                randomnum(&randomNum1, &randomNum2,&display); // Generate new numbers
                guessSubGame(randomNum1, randomNum2, points,display); // Restart the guessing game
                break; // Exit the loop
            } else if (again == 'n' || again == 'N') { // If the user does not want to restart
                cout << "Thank you for playing!" << endl; // End the game
                break; // Exit the loop
            } else { // Invalid input
                cout << "Error: wrong input, please try again.\n";
                cout << "Do you want to restart the game? (Y/N): ";
                cin >> again; // Ask for input again
            }
    }
    } else { // If the guess is wrong
        points--; // Deduct a point
        cout << "Wrong guess!" << endl;
        cout << "Your updated points are: " << points << endl; // Show updated points
    }
}
 
int main() {
    int randomNum1;
    int randomNum2;
    string name;
    int add = 0; // This is going to be the sum of the two random numbers
    int sub = 0; //This is going to be the difference of the two random numbers
    int points = 50; // The ammount of points the player starts with
    int usrGuess; // This stores the users guess for addition and diffrence
    int usrChoice; // This stores the input of the user for the menu choice 
    char again; // This stores the input for when the user decides of they want to play again
    bool menu = false; // This allows the while loop for the menu to function
    bool display = false; // This allows the display to function properly
    
    enum options{ADD = 1,SUBTRACT = 2,DISPLAY = 3,GIVEUP = 4,EXIT = 5};// This is the enum which stores the menu options
    randomnum(&randomNum1, &randomNum2,&display);
    
    getname(name);
    
    cout << "Welcome " << name << ".\n"; // This greets the user using their input 
    cout << "Your two random numbers have been generated. \n"; // informs the user that 2 random numbers were randomly generated 
    cout << "What would you like to do? \n"; //Ask the user what they would like to do
   while(!menu){
       if(points < 0){ //if the user reaches less than zero points it will end the loop
           menu = true; //ends the loop
           break;
       }
        cout << "1. ADD \n"; 
        cout << "2. SUBTRACT \n";
        cout << "3. DISPLAY \n";
        cout << "4. GIVEUP \n";
        cout << "5. EXIT \n";
        cout << "Enter choice: ";
        cin >> usrChoice; //gets the users input for the menu
        switch(usrChoice){ // decides which case to use
            case ADD: // if the user inputs 1 this will run
            guessSumGame(randomNum1, randomNum2, points, display);
            break;
            case SUBTRACT : //the diffrence between both random numbers
            guessSubGame(randomNum1, randomNum2, points, display);
            break;
            case DISPLAY:
            if(display == false){ //if display is false display the first number and the user loses 3 points
                points -= 3;
                cout << "Your updated points are:" << points << endl; 
                cout << "The first random number is " << randomNum1 << endl;
                display = true; // makes so when the user inputs display they dont lose points 
            }
            else{ // tells them that they already displayed the first number and tell the first number again
                cout << "You have already displayed the first number.\n";
                cout << "The first random number is " << randomNum1 << endl;
            }
            break;
            case GIVEUP: // if they give up
            cout << "Your random numbers are " << randomNum1 << " and " << randomNum2 << endl; //tells them both random numbers
            cout << "Do you want to restart the game?Y/N:"; //ask them if they want to play again
                cin >> again;
                while(true){ // if they type yes they get a new set of numbers
                    if(again == 'y' || again == 'Y'){
                        randomnum(&randomNum1, &randomNum2,&display);
                        break;
                    }
                    else if(again == 'n' || again == 'N'){ //ends the loop if they type no
                        menu = true;
                        break;
                    }
                    else{ //if the user doesnt input a y or n it will give them a error
                        cout << "Error wrong input please try again \n";
                        cout << "Do you want to restart the game?Y/N:";
                        cin >> again;
                        
                    }
                }
            break;
            case EXIT: // they input exit the loop will end
            menu = true;
            break;
            default: // if they dont type one of the options the program will them to input a valid input
            cout << "You have entered a incorrect number please try again\n";
            break;
        }
   }
   cout << "Your final points are:" << points << endl; // tells them their final ammount of points
   cout << "Goodbye, " << name; // tells them goodbye
    return 0;
    
}
