#include <iostream>
#include <cmath>

using namespace std;

int guessBot();

int main(){
    guessBot();
}
int guessBot(){
    int userNumber;
    int lowerRange;
    int higherRange;
    //initial guess
    cout << "Choose your integer: ";
    cin >> userNumber;
    cout << "Choose two integers for your range: ";
    cout << "Lower Range: ";
    cin >> lowerRange;
    cout << "Higher Range: ";
    cin >> higherRange;

    //ensures the user number is within range
    while(lowerRange > userNumber || higherRange < userNumber){
        cout << "Please ensure your number is within your range." << endl;
        cout << "Choose your integer: ";
        cin >> userNumber;
        cout << "Choose two integers for your range: ";
        cout << "Lower Range: ";
        cin >> lowerRange;
        cout << "Higher Range: ";
        cin >> higherRange;
        if(lowerRange > higherRange){
            swap(lowerRange, higherRange);
        }
    }
    
    //bot guesses the middle of all possible numbers
    int botNumberGuessed = round((higherRange + lowerRange) / 2);
    
    while (botNumberGuessed != userNumber){
        if (botNumberGuessed > userNumber){
            higherRange = botNumberGuessed;
            cout << botNumberGuessed << " is too high." << endl;
        } 
        else if (botNumberGuessed < userNumber){
            lowerRange = botNumberGuessed;
            cout << botNumberGuessed << " is too low." << endl;
        }
        botNumberGuessed = (higherRange + lowerRange) / 2;
    }
    cout << "Your number was " << botNumberGuessed;
    return userNumber, lowerRange, higherRange;
}