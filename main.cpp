
/*
 PROJECT
 Name: Binod Katwal
 Date: April 8, 2016
  The purpose of the program to implement autocomplete for a given set of N terms, where a term is a
query string and an associated nonnegative weight. That is, given a prefix, find all queries
that start with the given prefix, in descending order of weight.
 */
#include <iostream>// C++ basic
#include <fstream>// fstream reads and write
#include <ctime>
#include "Term.h" // First Part of the program
#include "Autocomplete.h"// Second part of the program
// Main function
int main(int argc, char *argv[])// Argument count, argument vector
{
// if user didn't include text file  while compiling the program, Do below
    if( argc != 3 )
	{
		cout << "Enter command line arguments properly!" << endl;
		return 1;
	}
    
//FIle won't open if text file doesn't exists or doesn't match the text file that i have
	std::ifstream infile(argv[1]);// fstreamming
	int k = atoi( argv[2] );// declaration of k = atoi of argument vector 2.

    // Do below if file doesn't match or doesn't exists
	if( !infile )
	{
		cout << "Cannot open input file!" << endl;  //display
		return 2;
	}

	long weight;// declare weight
	string query;// declare query

	Autocomplete autocomplete;//class autocomplete variable
	std::string line;// if weight and query in the file do below

	char number[15]; // number array of 15
	char str[100]; // str array of 100
	while (std::getline(infile, line)) //Condition
	{
	   	//cout << line << endl;
		int i = 0;
		while( !( line[i] >= '0' && line[i] <= '9' )) // if no match
			i++;

		int j = 0;
		while( line[i] >= '0' && line[i] <= '9' ) // if matched
		{
			number[j] = line[i];
			j++;
			i++;
		}

		number[j] = '\0';
		
		//cout << number << endl;
		weight = atol( number );
        // If array of line of the condition below doesn't match, increment i

		while( !( (line[i] >= 'a' && line[i] <= 'z' ) || (line[i] >= 'A' && line[i] <= 'Z' )))
			i++;

		j = 0;
		while( i < line.length() ) // while i  is smallar than length, do below
		{
			str[j] = line[i];
			j++;
			i++;
		}

		str[j] = '\0';
		//cout << str << endl;
		query = string( str );
		
		Term term( query, weight ); // Calling Term from term
		autocomplete.insert( term ); // Calling 
//cout << "Time for sorting all terms:" <<endl;
	}


	string input = "";

//Time Code: Help us to calculated the Sorting time for all term
//The time for sorting all terms is <= 1 minute
		 clock_t begin, end;
                begin = clock();
                vector<Term> terms = autocomplete.allMatches( input );// called, If matched
               end = clock();
        double elaspsed_secs = double(end -begin)/CLOCKS_PER_SEC;
       cout << "Time for sorting all terms: " <<elaspsed_secs<< " seconds"<<endl; //end.

// While loop is used here to the main displaying part of the program,does below if above is true
// The program will not  stop asking to search query until you entered "exit"
	while( true )
	{
     // Ask users to input to search query(what do you want to search)
		cout << "Please input the search query(type \"exit\" to quit): " << endl;
		cin >> input;// take in input to the program

//If  user input is exit then The program will automatically quit
		if( input.compare("exit") == 0 )
			break;

// TIme code: Helps to calculate  time taken to  search User Input
// The time for searching any user-input prefix is <= 10 seconds
               clock_t begin, end;
		begin = clock();
		vector<Term> terms = autocomplete.allMatches( input );;// called, If matched
               end = clock();
		double elaspsed_secs = double(end -begin)/CLOCKS_PER_SEC;
       cout << "Time for searching all matched terms: " <<elaspsed_secs<< " seconds"<<endl; //end.


        //  display the outcome of the user input if matched and found, it'll display, if not found, displays empty
		for( int i=0; i<terms.size(); i++)
		{
			if( i == k )
				break;			
			cout << terms[i].getWeight() << " " << terms[i].getQuery() << endl;//display if matched
		}
	}
    return 0;   // retun 0 if you break the code by entering "exit" as query
}
 //End Of The Main Function
