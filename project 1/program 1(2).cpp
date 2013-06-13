/*	EECS 211 Program 1 

Author: Jeannie Tran / Computer Science / 2583406 / jtr121

Purpose: This program computes the average of a set of non-negative values. 

*/

#include <iostream>
using namespace std;

int main()
{
	double counter;  //Number of scores read
	double sum;  //Sum of scores read
	double grade;  //Scores as they are entered by the user

	float average;  //Holds computer average

	counter = 0;  //Initializing counter and sum before starting
	sum = 0;

	int ans; //Variable to check if user wants to compute an average
	int ans2; //Second variable to check if user wants to compute an average

	do {
		cout << "Would you like to compute an average? Enter 1 if yes or 0 if no: \n";  //Checking if user wants to compute average
		cin >> ans;

		if(ans==1) {
			do {
				cout << "Would you like to enter a grade? Enter 1 if yes or 0 if no.\n";  //Checking if user wants to enter a grade
				cin >> ans2;

				if (ans2==1) {  //If yes,
					cout << "Please enter a grade.\n";  //then prompting user to enter a grade
					cin >> grade;

					if (0<=grade&&grade<=100) {  //If grade is within valid range of grades,
						sum = sum + grade;  //then add the grade to the sum,
						counter = counter + 1;  //and count one more grade
					}
					else if (grade>100||grade<0) {  //For all grades outside of valid range,
						cout << "Invalid score entered.\n";  //print error message and don't add grade to sum or add one to count
					}
				 
			 }

			 else if (ans2==0) {  //If no,
				 if (counter>0) {  //if the user has already entered grades,
					 average = (float)sum/counter;  //then compute the average,
					 cout << "The average of the " << counter <<" grades entered is " << average << ".\n";	 //print it,
					 counter = 0;  //reset the grade counter,
					 sum = 0;  //and reset the sum
				 }
				 else if (counter==0) { //If user has not entered grades,
					 cout << "No valid scores entered.\n";  //then print error message
				 }
				
			 }

		 } while(ans2==1);

	 }

 } while(ans==1);

}