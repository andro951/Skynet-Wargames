//Name: Skynet Wargames.
//Author: Isaac Richards.
//Date: 15OCT18.

//Header.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using std::cout;
using std::cin;
using std::time;
using std::string;


int main()
{
	bool repeatProgram = false;
	/*
	=================================================================================================================================================
	|																																				|
	|	Program loop																																|
	|																																				|
	=================================================================================================================================================
	*/
	//Repeats the entire program if desired by the user.
	do //(repeatProgram)
	{
		int gridSizeX; //Represents the width of the grid.
		cout << "Enter the grid size X value: ";
		cin >> gridSizeX;

		int gridSizeY; //Represents the length of the grid.
		cout << "Enter the grid size y value: ";
		cin >> gridSizeY;

		cout << "\n";

		int searchGridLowNumber = 1; //Initially the lowest numbered cell.  Used to calculate targetLocation and targetLocationPrediction.
		int searchGridHighNumber = gridSizeX * gridSizeY; //Initially the highest numbered cell.  Used to calculate targetLocation and targetLocationPrediction.
		srand(static_cast<unsigned int>(time(0))); //Uses the current date and time as a seed for rand().
		int randomNumber = rand(); //Create a random number with rand().
		int targetLocation = searchGridLowNumber + randomNumber % searchGridHighNumber; //Generates a random enemy location within the grid.

		cout << "Generating random enemy location on " << gridSizeX << "x" << gridSizeY << " grid....\n"
			<< "The enemy is located at location #" << targetLocation << " on " << gridSizeX << "x" << gridSizeY << " grid with " << searchGridLowNumber << "-" << searchGridHighNumber << " sectors.\n"
			<< "===============================================================\n";


		bool searchingForTarget = true; //Causes the searchingForTarget loop to repeat until the enemy is found.
		int ping = 0; //The number of radar pings or guesses.
		cout << "Initializing user search pattern software.....\n"
			<< "===============================================================\n";
		/*
		=================================================================================================================================================
		|	user searchingForTarget loop																												|
		=================================================================================================================================================
		*/
		while (searchingForTarget) //Repeats until the enemy is found.
		{
			int targetLocationPrediction;
			++ping; //Increment ping each time searchingForTarget loop runs.
			cout << "Search #" << ping << ".\n"
				<< "Please enter a target location between " << searchGridLowNumber << "-" << searchGridHighNumber << ":";
			cin >> targetLocationPrediction; //Get prediction from the user.

			if (targetLocationPrediction > targetLocation) //Prediction is too high.
			{
				cout << "Your location prediction of " << targetLocationPrediction << " was higher than the actual enemy location.\n"
					<< "---------------------------------------------------------------\n";
			}
			else if (targetLocationPrediction < targetLocation) //Prediction is too low.
			{
				cout << "The target location prediction of " << targetLocationPrediction << " was lower than the actual enemy location.\n"
					<< "---------------------------------------------------------------\n";
			}
			else //Enemy found.
			{
				cout << "Enemy was hiding at location #" << targetLocation << ".\n"
					<< "You found the target at location #" << targetLocationPrediction << ".\n"
					<< "You took " << ping << " predictions to find the enemy location on a grid size of " << gridSizeX << "x" << gridSizeY << "(" << gridSizeX * gridSizeY << ").\n";
				searchingForTarget = false;
			}
		}
		/*
		=================================================================================================================================================
		|	End of user searchingForTarget loop																											|
		=================================================================================================================================================
		*/
		cout << "===============================================================\n";


		searchingForTarget = true;
		ping = 0;
		cout << "Initializing linear search pattern software.....\n"
			<< "===============================================================\n"
			<< "Target location: ";
		/*
		=================================================================================================================================================
		|	linear searchingForTarget loop																												|
		=================================================================================================================================================
		*/
		while (searchingForTarget) //Repeats until the enemy is found.
		{
			++ping; //Increment ping each time searchingForTarget loop runs.
			int targetLocationPrediction = ping;
			cout << ping;

			if (targetLocationPrediction > targetLocation) //prediction is too high.
			{
				cout << ", ";
			}
			else if (targetLocationPrediction < targetLocation) //prediction is too low.
			{
				cout << ", ";
			}
			else //Enemy found.
			{
				cout << "\nEnemy was hiding at location #" << targetLocation << ".\n"
					<< "Target was found at location #" << targetLocationPrediction << ".\n"
					<< "Linear search pattern Software took " << ping << " predictions to find the enemy location on a grid size of " << gridSizeX << "x" << gridSizeY << "(" << gridSizeX * gridSizeY << ").\n";
				searchingForTarget = false;
			}
		}
		/*
		=================================================================================================================================================
		|	End of linear searchingForTarget loop																										|
		=================================================================================================================================================
		*/
		cout << "===============================================================\n";


		searchingForTarget = true;
		ping = 0;
		cout << "Initializing random search pattern software.....\n"
			<< "===============================================================\n"
			<< "Target location: ";
		/*
		=================================================================================================================================================
		|	random searchingForTarget loop																												|
		=================================================================================================================================================
		*/
		while (searchingForTarget) //Repeats until the enemy is found.
		{
			int targetLocationPrediction = rand() % (gridSizeX * gridSizeY) + 1;
			++ping; //Increment ping each time searchingForTarget loop runs.
			cout << targetLocationPrediction;

			if (targetLocationPrediction > targetLocation) //prediction is too high.
			{
				cout << ", ";
			}
			else if (targetLocationPrediction < targetLocation) //prediction is too low.
			{
				cout << ", ";
			}
			else //Enemy found.
			{
				cout << "\nEnemy was hiding at location #" << targetLocation << ".\n"
					<< "Target was found at location #" << targetLocationPrediction << ".\n"
					<< "Skynet HK-Aerial Software took " << ping << " predictions to find the enemy location on a grid size of " << gridSizeX << "x" << gridSizeY << "(" << gridSizeX * gridSizeY << ").\n";
				searchingForTarget = false;
			}
		}
		/*
		=================================================================================================================================================
		|	End of random searchingForTarget loop																										|
		=================================================================================================================================================
		*/
		cout << "===============================================================\n";


		searchingForTarget = true;
		ping = 0;
		cout << "Skynet HK-Aerial initializing software.....\n"
			<< "===============================================================\n";
		/*
		=================================================================================================================================================
		|	half-split searchingForTarget loop																											|
		=================================================================================================================================================
		*/
		while (searchingForTarget) //Repeats until the enemy is found.
		{
			int targetLocationPrediction = ((searchGridHighNumber + searchGridLowNumber) / 2); //Initial target location prediction.
			++ping; //Increment ping each time searchingForTarget loop runs.
			cout << "Skynet HK-Aerial sending out ping #" << ping << ".\n";

			if (targetLocationPrediction > targetLocation) //prediction is too high.
			{
				cout << "The target location prediction of " << targetLocationPrediction << " was higher than the actual enemy location of " << targetLocation << ".\n";
				searchGridHighNumber = targetLocationPrediction - 1; //lower the searchGridHighNumber.
				cout << "The new searchGridHighNumber =" << searchGridHighNumber << ".\n"
					<< "---------------------------------------------------------------\n";
			}
			else if (targetLocationPrediction < targetLocation) //prediction is too low.
			{
				searchGridLowNumber = targetLocationPrediction + 1; //raise the searchGridLowNumber.
				cout << "The target location prediction of " << targetLocationPrediction << " was lower than the actual enemy location of " << targetLocation << ".\n"
					<< "The new searchGridLowNumber =" << searchGridLowNumber << ".\n"
					<< "---------------------------------------------------------------\n";
			}
			else //Enemy found.
			{
				cout << "Enemy was hiding at location #" << targetLocation << ".\n"
					<< "Target was found at location #" << targetLocationPrediction << ".\n"
					<< "Skynet HK-Aerial Software took " << ping << " predictions to find the enemy location on a grid size of " << gridSizeX << "x" << gridSizeY << "(" << gridSizeX * gridSizeY << ").\n";
				searchingForTarget = false;
			}
		}
		/*
		=================================================================================================================================================
		|	End of half-split searchingForTarget loop																									|
		=================================================================================================================================================
		*/
		cout << "===============================================================\n";

		bool waitingForValidInput = true; //Used to determine if the waitingForValidInput loop needs to repeat.

		/*
		=================================================================================================================================================
		|	waitingForValidInput loop																													|
		=================================================================================================================================================
		*/
		while (waitingForValidInput) //Repeat until a valid input is entered.
		{
			cout << "Would you like to run another simulation? (type yes or no)\n";
			string userAnswer; //Stores the user's answer to the above question.
			cin >> userAnswer; //Obtain input from the user.
			if (userAnswer == "yes" || userAnswer == "Yes" || userAnswer == "YES") //If yes is entered, repeat the Program loop.
			{
				repeatProgram = true;
				waitingForValidInput = false;
				cout << "===============================================================\n";
			}
			else if (userAnswer == "no" || userAnswer == "No" || userAnswer == "NO") //If no is entered, end the Program loop and exit the program.
			{
				repeatProgram = false;
				waitingForValidInput = false;
			}
			else //If anything other than yes or no is entered, repeat the waitingForValidInput loop.
			{
				cout << "\nInvalid input.\n\n";
			}
		}
		/*
		=================================================================================================================================================
		|	End of waitingForValidInput loop																											|
		=================================================================================================================================================
		*/

	} while (repeatProgram);
	/*
	=================================================================================================================================================
	|																																				|
	|	End of Program loop																															|
	|																																				|
	=================================================================================================================================================
	*/
}