
/*
 File name: Autocomplete.cpp
 Author: Binod Katwal
 Date: April 11 2016
 */

#include "Autocomplete.h" // Header file of the Autocomplete.cpp coded file


	/* Inserts the newterm to the sequence */
	void Autocomplete::insert(Term newterm)
	{
		terms.push_back( newterm );
	}

//**********************************************************************//
	/* returns all terms that start with the given prefix, 
	  in descending order of weight<T>*/
	vector<Term> Autocomplete::allMatches(string prefix)
	{
		vector<Term> t;
		for( int i =0 ; i<terms.size(); i++)
		{
			if( prefix.compare( terms[i].query.substr(0, prefix.length()) ) == 0)
			{
				t.push_back( terms[i] );
			}
		}
	
		/*Return in descending order*/	

		std::sort(t.begin(), t.end());
		return t;
	}

//**********************************************************************//
	/* First: the index of the first query that equals
	 the search key, or -1 if no such key
	 last: the index of the last query that equals 
	 the search key, or -1 if no such key */
	void Autocomplete::Search(string key, int& first, int& last)
	{
		for( int i=0; i<terms.size(); i++) //Nested loop
		{
			if( key.compare( terms[i].query ) == 0 ) //condition
			{
				first = i;
				break;
			}
		}

		for( int i=terms.size()-1; i>=0 ; i--)
		{
			if( key.compare( terms[i].query ) == 0 )//condition
			{
				last = i;
				break;
			}
		}
	}

//***********************************************************************//
/*Return the index number of the search key using binary search algorithm*/
int Autocomplete::BS_helper(vector<Term> terms,string key, int left, int right)
	{
		int mid = (left + right)/2;
		
		if( terms[mid].query.compare( key) == 0 )
			return mid;
		else if( terms[mid].query.compare( key) > 0 )
			return BS_helper(terms, key, left, mid );
		else 
			return BS_helper(terms, key, mid + 1, right );
		return -1;
	}
	
//*********************************************************************//
	/* Display all the terms */
	void Autocomplete::print()
	{
		for( int i=0; i<terms.size(); i++)
		{
			terms[i].print();
		}
	}
//End Of The Autocomplete.cpp 
