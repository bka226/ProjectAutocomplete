/*
 File name: Term.cpp
 Author: Binod Katwal
 Date: April 10 2016
 */
#include <string> // use of string
#include "Term.h" //header file of the term.cpp coded file
using namespace std;

//******************************************************************//
/* Default constructor */
    Term::Term()
		{
			Term("",0); // construction declared term empty,0
		}
		
/* Initialize with the given query string and weight*/
Term::Term(string query, long weight)
		{
			this->query = query; // points query
			this->weight = weight; // points weight

		}
 
//***********************************************************************//
// Compares two terms in descending order by weight
 int Term::byReverseWeightOrder(Term that)
		{
            // if condition of this greater than that, return 1 else must be equal so return 0 if doesn't match either, return -1
			if( this->weight > that.weight )
				return 1;
			else if( this->weight == that.weight )
				return 0;
			else
				return -1;
		}

//***********************************************************************//
 //Compares two terms in lexicographic order by query
 
		int Term::compareTo(Term that)
		{
			return this->query.compare( that.query );//compare this and that
		}

//***********************************************************************//
//Comparestwo terms in lexicographic order but using only
 //the first r characters of each query
 

		int Term::byPrefixOrder(Term that, int r)
		{
			string t1 = "";
			string t2 = "";
// nested for and if loop condition
			for( int i=0; i<r; i++)
			{
				if( i<query.length() )
					t1 = t1 + query[i];
				if( i<that.query.length() )
					t2 = t2 + that.query[i];
			}

			return t1.compare( t2 ); // return
		}


 //******************************************************************//
/* Displays the term in the following format:
 the weight, followed by a tab key, followed by the query*/
void Term::print()
		{
			cout << weight << "\t" << query << endl;
		}


//*********************************************************************//
/* Retun  weight in the term of the function getweight*/
		long Term::getWeight()
		{
			return weight;
		}

//********************************************************************//
/* Retun query in  the term of the function getQuery*/
string Term::getQuery()
		{
			return query;
		}

// End Of The Term.cpp implementation file
