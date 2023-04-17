
/* INFO 0104 Final Assignment
	Aditi Persad - 20220206
	Date - 24.03.2023
	Program description: The program will initially display a menu allowing users to choose a prompt and based on the prompt chosen, the results be displayed on the screen.
	The program is built to display certain results for a marathon. */


#include <stdio.h>

// Initializing the function prototypes
int listing();
int fastest();
int gender();
int avg_time();

int main() {
	int choice;
	
	//Printing the main menu with choices and prompting the user
	printf("|\t Main Menu\t|\n");
	printf("[1] Participant listing\n[2] Male and female winners\n[3] Number of male and female runners\n[4] Male and female average times\n[5] Quit\n");
	scanf("%d", &choice);

	// case switch to carry out the user's choice
	switch(choice) {	
	//Calling the program with the participant listing sorted by gender
	case 1:
		listing();
	break;
	// Calling the program which sorts the fastest runners of each gender and their times in hours and minutes
	case 2:
		fastest();
	break;
	// Calling the program that counts the number of male and female runners
	case 3:
		gender();
	break;
	// Calling the program that outputs the average times of each gender in hours and minutes
	case 4:
		avg_time();
	break;
	// Ending the program
	case 5:
		printf("Thank you for supporting The Children's Guardian Non-profit organization.\nGoodbye...");
		return 0;
	break;
	// Repeating the program until a valid choice is inputted
	default:
		printf("Please enter a valid number:\n");
		return main();
}
	return 0;
}

// Program to list the name, gender and runtime in minutes of each runner
int listing() {
	// Variables for this program
	int count;
	
	//Arrays holding runtimes, gender and names respectively
	int runTimeMins [10] = {341, 273, 278, 329, 445, 402, 388, 275, 343, 334};
	char gender [10] = {'F', 'M', 'M', 'F', 'M', 'M', 'M', 'F', 'F', 'M'};
	char name [][10] = {"Ellen", "Tom", "Greg", "Suzie", "Phil", "Matt", "Alex", "Emma", "Jane", "James"};
	
	// Printing the headers
	printf("|Name\tTime(minutes)\tGender|\n");
	
	// For loop to display the results
	for (count=0; count< 10; count++) {
		
		printf(" %s\t\t%d\t%c\n", name[count],runTimeMins[count], gender[count]);
	}
	return 0;
}

// Program to find the fastest time ran by each gender
int fastest (){
	// Variables for this program
	int male, female, hours, mins, x;
	
	// Finding the fastest male
	// Array of male names
	char malenames[][6]={"Tom", "Greg", "Phil", "Matt", "Alex", "James"};
	
	// Array of male runtimes
	int maleruntimes[6] = {273,278,445,402,388,334};
	male =0;
	
	// For loop containing if statement to find the fastest male
	for (x=0; x<6; x++) {
		if ( maleruntimes[x] < maleruntimes[male]) {
			male=x;
		}
	}
	// Calculating the fastest male time in hours and minutes
	hours =(maleruntimes[male] / 60);
	mins =(maleruntimes[male] % 60);
	
	// Printing the fastest male
	printf("The fastest male is %s finishing at %d hours and %d minutes.\n", malenames[male], hours, mins);
	
	// Finding the fastest female
	//array of female names
	char femalenames[][6]={"Ellen", "Suzie", "Emma", "Jane"};
	
	// Array of female runtimes
	int femaleruntimes[4] = {341, 329, 275, 343};
	female=0;
	
	// For loop containing if statement to find the fastest female
	for (x=0; x<4; x++) {
		if ( femaleruntimes[x] < femaleruntimes[female]) {
			female=x;
		}
	}
	// Calculating the fastest female time in hours and minutes
	hours =(femaleruntimes[female] / 60);
	mins =(femaleruntimes[female] % 60);
	
	// Printing the fastest female
	printf("The fastest female is %s finishing at %d hours and %d minutes.\n", femalenames[female], hours, mins);
	
	return 0;
}

// Program to find the number of male and female runners
int gender() {
	// Variables for this program
	int male, female;
	
	// initializing the variables
	female=0;
	male=0;
 
	// Array with the genders of the runners
	char gender [10] = {'F', 'M', 'M', 'F', 'M', 'M', 'M', 'F', 'F', 'M'};
	int counter;
	
	// for loop to count the genders
	for (counter=0;counter<10; counter++) {
		
		// if statements to count the genders
		if (gender[counter]== 'F') {
			female=(female + 1);	
		}
		else if (gender[counter]=='M') {
			male=(male + 1);
		}
	}
	// Printing the counts
	printf("Total number of male runners: %d\nTotal number of female runners: %d", male, female);
	
	return 0;
}

// Program to find the average time for each gender
int avg_time() {
	// variables in this program
	int male, female, male_avg, female_avg, f_total, m_total;
	
	// initializing the variables
	female = 0;
	male = 0;
	f_total=0;
	m_total=0;
	
	//Array of the runtimes and genders
	int runTimeMins [10] = {341, 273, 278, 329, 445, 402, 388, 275, 343, 334};
	char gender [10] = {'F', 'M', 'M', 'F', 'M', 'M', 'M', 'F', 'F', 'M'};
	int counter;
	
	// for loop to find the associated runtimes with the genders
	for (counter=0;counter<10; counter++) {
		
		// if statements to add the runtimes
		if (gender[counter]== 'F') {
			f_total= f_total +1;
			female=	(female + runTimeMins[counter]);	
		}
		else if (gender[counter]=='M') {
			m_total= m_total +1;
			male=(male + runTimeMins[counter]);
		}
	}
	
	// Finding the average for female runtimes
	female_avg= (female/f_total);
	// Finding the average for male runtimes
	male_avg= (male/m_total);
	
	// Calculating hours and minutes
	int f_hours= (female_avg / 60);
	int f_mins= (female_avg % 60);
	int m_hours= (male_avg / 60);
	int m_mins= (male_avg % 60);
	
	// Printing the results
	printf("Average male runtimes: %d hours and %d minutes\nAverage female runtimes: %d hours and %d minutes", m_hours, m_mins, f_hours, f_mins);
	
	return 0;
}

