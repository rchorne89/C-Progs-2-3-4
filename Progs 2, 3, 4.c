// Programmer:		Robert Christain Horne
// Date:			July 9 2024
// Program Name:	Prog 2, 3, 4
// Chapter:			Chapter 6 - Functions
// Description:		A menu-driven program to allow the user to select and run a program from one of the first 3 chapters of CPT 234.
//					Uses a function to display a menu of choices, and have the function return the choice made by the user.

#define _CRT_SECURE_NO_WARNINGS // Disable warnings (and errors) when using non-secure versions of printf, scanf, strcpy, etc.
#include <stdio.h> // Needed for working with printf and scanf

// This Program will show a menu for the user to choose which program they want to view.
// Each individual program is set as its own function below the main.
// All the programs were previous assignments from the the class. Thus all the program functions were copy-paste from the original source
//		with some minor changes based on feedback from the grading rubric (if it was graded).

int main(void)
{
	// Constant and Variable Declarations

	// Variable used for the menu choice.
	int userChoice;


	// *** Your program goes here ***
	// This statement will call upon the UserMenu function. After the function ends, it
	//   will set the "userChoice" variable to what ever the user choices.
	userChoice = UserMenu();

	// 
	// This loop will continue to occur as long as the "userChoice" number is anything except -1.
	while (userChoice != -1) {
		switch (userChoice) {
		// This Case statement will run the SplitDouble program.
		// The program is listed as a function below.
		case 2:
			SplitDouble();
			break;
		// This Case statement will run the Minutes, Hours, Days program.
		// The program is listed as a function below.
		case 3:
			MinutesHoursDays();
			break;
		// This Case statement will run the Calories Burned program.
		// The program is listed as a function below.
		case 4:
			CaloriesBurned();
			break;
		}
		// If 2, 3, or 4 was not entered. The program will return to the menu.
		// This also goes for when the programs above are complete it will go back to the menu.
		// The user will then be asked for another number.
		userChoice = UserMenu();
	}

	// This will only print if the user inputs -1.
	// Thus showing the loop is broken and the program has ended.
	printf("Goodbye!\n");

	printf("\n"); //Blank Line

	return 0;
} // end main()

int UserMenu() {
	// Variable used for the function.
	int userNum;

	// This is the displayed menu the used will see.
	printf("Progs 2, 3, 4 Menu\n");
	printf("------------------------\n");
	printf("2 - Split Double\n");
	printf("3 - Minutes, Hours, Days\n");
	printf("4 - Calories Burned\n");
	printf("\n");
	printf("Enter a choice (-1 to quit): ");
	// User will input their number of choice.
	scanf("%d", &userNum);
	printf("\n\n");

	// This will return the user's input to the above main function.
	return userNum;
}

int SplitDouble()
{
	// Constant and Variable Declarations
	// Variables used for the program.
	double userNumber;
	int integerNumber;
	double decNumber;


	// *** Your program goes here ***
	// This will ask the user to input a number with a decimal.
	printf("Enter a number that includes a decimal point: ");
	scanf("%lf", &userNumber);

	// This statement will change the user's number to an interger then save it to the "intergerNumber" Variable.
	integerNumber = (int)userNumber;
	// This statement will subtract the userNumber from the interger to get only the decimals from the user's number.
	decNumber = userNumber - integerNumber;

	// This will print out the user's number as an interger.
	printf("The integer part of %lf is %d.\n", userNumber, integerNumber);
	// This will print out the user's number with only the decimal part.
	printf("The decimal part of %lf is %lf.\n", userNumber, decNumber);

	printf("\n\n"); // Blank Lines

	return 0; //End Function
}


int MinutesHoursDays()
{
	// Constant and Variable Declarations
	int numSec = 0;
	const double SECONDS_IN_A_MINUTE = 60.00; //Constant for seconds in a minute.
	const double SECONDS_IN_A_HOUR = 3600.00; //Constant for seconds in an hour.
	const double SECONDS_IN_A_DAY = 86400.00; //Constant for seconds in a day.
	
	// Variables used to save the Minutes, Hours, Days based on the user's input seconds.
	double numMin = 0.00;
	double numHour = 0.00;
	double numDay = 0.00;


	// *** Your program goes here ***
	
	//User inputs number of seconds.
	printf("Enter the number of seconds: ");
	scanf("%d", &numSec); 
	printf("\n");


	if (numSec < 1) // Validation If statement. If number is less than 1, then it will stop and end the function.
	{
		printf("The number of seconds entered is invald.\n"); //Statement will print only if user inputed seconds is less than 1.
	}
	else if (numSec >= 86400) //Checks if number is greater than or equal to 86400 sec (Number of seconds in a day).
	{
		numMin = numSec / SECONDS_IN_A_MINUTE; //Calculates number of seconds per minute.
		numHour = numSec / SECONDS_IN_A_HOUR; //Calculates number of seconds per hour.
		numDay = numSec / SECONDS_IN_A_DAY; //Calculates number of seconds per day.
		printf("The number of seconds you entered, %d, is %.2lf days.\n", numSec, numDay);
		printf("The number of seconds you entered, %d, is %.2lf hours.\n", numSec, numHour);
		printf("The number of seconds you entered, %d, is %.2lf minutes.\n", numSec, numMin);
	}
	else if (numSec >= 3600) //Checks if number is greater than or equal to 3600 sec (Number of seconds in an hour).
	{
		numMin = numSec / SECONDS_IN_A_MINUTE;
		numHour = numSec / SECONDS_IN_A_HOUR;
		printf("The number of seconds you entered, %d, is %.2lf hours.\n", numSec, numHour);
		printf("The number of seconds you entered, %d, is %.2lf minutes.\n", numSec, numMin);
	}
	else if (numSec >= 60) //Checks if number is greater than or equal to 60 sec (Number of seconds in a minute).
	{
		numMin = numSec / SECONDS_IN_A_MINUTE;
		printf("The number of seconds you entered, %d, is %.2lf minutes.\n", numSec, numMin);
	}
	else
	{
		printf("The number of seconds you entered, %d.\n", numSec); //This statement will only appear if number of seconds is 1 thru 59.
	}
	printf("\n\n"); //Blank Lines

	return 0; //End Function
}

int CaloriesBurned()
{
	// Constant and Variable Declarations

	//Constants for Calories burned per minute, the increment amount of minutes, the starting minutes, and the ending minutes. Can be changed by the user.
	const double CALORIES_BURNED_PER_MINUTE = 3.9;
	const int MIN_MINUTES = 5;
	const int MAX_MINUTES = 20;
	const int MINUTES_INCREMENT = 3;
	//Additional Variables 
	double caloriesBurned;
	//This set the time to the starting minutes the user has set.
	int timeMinutes = MIN_MINUTES;

	// *** Your program goes here ***
	printf("You burn %.1lf calories every minute you run.\n", CALORIES_BURNED_PER_MINUTE);
	printf("This shows how many calories you burn if you ran for %d to %d minutes.\n\n", MIN_MINUTES, MAX_MINUTES);
	printf("	Minutes	Calories\n");
	printf("Using a while loop\n");
	while (timeMinutes <= MAX_MINUTES) { //Displays the table using a "while" loop to run the program. The loop will break when Minutes is greater than the Ending Minutes.
		caloriesBurned = timeMinutes * CALORIES_BURNED_PER_MINUTE; //Calculates the total amount of calories burned from the time in minutes by the amount burned.
		printf("	   %d	   %.2lf\n", timeMinutes, caloriesBurned); //Displays to the user how many total calories burned in set minutes
		timeMinutes += MINUTES_INCREMENT; //Increments the time by set minutes
	}
	printf("\n");//Blank Line

	timeMinutes = MIN_MINUTES; //Used to reset the time to the starting minutes
	printf("Using a do-while loop\n");
	do { //Displays the table using a "do-while" loop to run the program.
		caloriesBurned = timeMinutes * CALORIES_BURNED_PER_MINUTE; //Calculates the total amount of calories burned from the time in minutes by the amount burned.
		printf("	   %d	   %.2lf\n", timeMinutes, caloriesBurned); //Displays to the user how many total calories burned in set minutes.
		timeMinutes += MINUTES_INCREMENT; //Increments the time by set minutes
	} while ((timeMinutes <= MAX_MINUTES)); //The loop will break when Minutes  is greater than the Ending Minutes.

	printf("\n"); //Blank Line

	printf("Using a for loop\n");
	for (timeMinutes = MIN_MINUTES; timeMinutes <= MAX_MINUTES; timeMinutes += MINUTES_INCREMENT) { //Displays the table using a "for" loop to run the program.
		//The "for" loop will reset the minutes to the starting minutes. Then loop around until the time is greater than the ending minutes.
		caloriesBurned = timeMinutes * CALORIES_BURNED_PER_MINUTE; //Calculates the total amount of calories burned from the time in minutes by the amount burned.
		printf("	   %d	   %.2lf\n", timeMinutes, caloriesBurned); //Displays to the user how many total calories burned in set minutes
	}

	printf("\n\n"); //Blank Lines

	return 0; //End Function
}