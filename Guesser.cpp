#include <iostream>
using namespace std;
int main() {
    srand(time(NULL));
    int randomNum1 = rand()% 51 +50; // This creates a random number between 50 and 100 inclusive
    int randomNum2 = rand()% 51 +50; // Creates random number between 50 and 100
    while(randomNum1 > randomNum2){ // This ensures that the that the first randon number is not bigger than the second randon number
        randomNum1 = rand()% 51 +50;
        randomNum2 = rand()% 51 +50;
    }
    
    string name;
    int add = 0; // This is going to be the sum of the two random numbers
    int sub = 0; //This is going to be the difference of the two random numbers
    int points = 50; // The ammount of points the player starts with
    int usrGuess; // This stores the users guess for addition and diffrence
    int usrChoice; // This stores the input of the user for the menu choice 
    char again; // This stores the input for when the user decides of they want to play again
    bool letter = false; //This allows the while loop that checks if the name has invalid input
    bool menu = false; // This allows the while loop for the menu to function
    bool display = false; // This allows the display to function properly
    
    enum options{ADD = 1,SUBTRACT = 2,DISPLAY = 3,GIVEUP = 4,EXIT = 5};// This is the enum which stores the menu options
    
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
            add = randomNum1 + randomNum2; // adds both numbers together
            cout << "Enter your guess sum?"; // tells the user to guess the sum of both  numbers
            cin >> usrGuess; //users guess
            if(usrGuess > (add - 5) && usrGuess < (add + 5)){ //if the user is 4 away from the correct answer the user gets points
                points += 5; // gives the user 5 points
                if(usrGuess == add){ //if the user is directly correct they will be told that they are correct
                    cout << "Your guess is correct. You win.";
                }
                else{// if they are close they get told close enough
                    cout << "Your guess is close enough. You win.";
                }
                cout << "Your updated points are: " << points << endl; // tells the user their new point value
                cout << "Do you want to restart the game?Y/N:"; // ask the user if they want to restart the game
                cin >> again; // Gets the input of the user
                while(true){
                    if(again == 'y' || again == 'Y'){ // if the user decides they wanna play again new numbers are generated
                        randomNum1 = rand()% 51 +50;
                        randomNum2 = rand()% 51 +50;
                        while(randomNum1 > randomNum2){ // Makes sure the first random number is smaller than the second number
                            randomNum1 = rand()% 51 +50;
                            randomNum2 = rand()% 51 +50;
                        }
                        break;
                        display = false; // if the user has displayed before this resetes for a new set of numbers
                    }
                    else if(again == 'n' || again == 'N'){ // if the user inputs no the loop  will end
                        menu = true;
                        break;
                    }
                    else{ //if the user doesnt input a y or n it will give them a error
                        cout << "Error wrong input please try again \n";
                        cout << "Do you want to restart the game?Y/N:";
                        cin >> again; // ask for them to input it again
                        
                    }
                }
            }
            else{ //if you guess wrong you lose points
                points --;
                cout << "Wrong guess \n";
                cout << "Your updated points are:" << points << endl; //tells them their new points
            }
            break;
            case SUBTRACT : //the diffrence between both random numbers
            sub = randomNum2 - randomNum1; // the difrence between both numbers
            cout << "Enter your guess difference?";
            cin >> usrGuess; // gets the users guess
            if(usrGuess > (sub - 5) && usrGuess < (sub + 5)){ //if the users guess is within 5 of the correct number they get 5 points
                points += 5; // gives the user 5 points
                if(usrGuess == sub){ // if they on the money they get told they are correct
                    cout << "Your guess is correct. You win.";
                }
                else{ // if not on the money they are told that they were close enough
                    cout << "Your guess is close enough. You win.";
                }
                cout << "Your updated points are: " << points << endl; // tells them their updated points 
                cout << "Do you want to restart the game?Y/N:";
                cin >> again; // gets their input if they want to restart the game
                while(true){
                    if(again == 'y' || again == 'Y'){ // if they type yes they get a new set of numbers
                        randomNum1 = rand()% 51 +50;
                        randomNum2 = rand()% 51 +50;
                        while(randomNum1 > randomNum2){ // this makes sure that num1 < num2
                            randomNum1 = rand()% 51 +50;
                            randomNum2 = rand()% 51 +50;
                        }
                        display = false; // resets the display so you can do display again
                        break;
                    }
                    else if(again == 'n' || again == 'N'){ // if they input no the loop ends
                        menu = true;
                        break;
                    }
                    else{// if they put a invalid input they get a error
                        cout << "Error wrong input please try again \n";
                        cout << "Do you want to restart the game?Y/N:";
                        cin >> again;
                        
                    }
                }
            }
            else{ // if they guess wrong they lose 1 point
                points --;
                cout << "Wrong guess \n";
                cout << "Your updated points are:" << points << endl; // new updated points
            }
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
                        display = false;
                        randomNum1 = rand()% 51 +50;
                        randomNum2 = rand()% 51 +50;
                        while(randomNum1 >= randomNum2){ // makes sure num1 < num2
                            randomNum1 = rand()% 51 +50;
                            randomNum2 = rand()% 51 +50;
                        }
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
