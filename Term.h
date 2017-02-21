/*
 File name: Term.h
Author: Binod Katwal

Date: April 10 2016
*/
#ifndef TERM_H_
#define TERM_H_
#include <iostream>
using namespace std;

class Term
{
	public:
		/* default constructor */
		Term();

		/* initialize 
		with the given query string and weight*/

		Term(string query, long weight);
		/* compares 
		 two terms in descending order by weight */
		int byReverseWeightOrder(Term that);

		/*
		compares 
		two terms in lexicographic order by query*/
		int compareTo(Term that);

		/* compares 
		two terms in lexicographic order but using only 
		the first r characters of each query*/
		int byPrefixOrder(Term that, int r);

		/* displays the term in the following format:
		  the weight, followed by a tab key, followed by the query*/
		void print();
		// other member functions you need...

		long getWeight();
		string getQuery();

	bool operator<( Term rhs) const { return weight > rhs.getWeight(); }

	friend class Autocomplete;
	private:
	string query; // query string
	long weight; // weight as long
};

#endif
// Term.h Ends....

