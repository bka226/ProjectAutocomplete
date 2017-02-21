/*
 File name: Autocomplete.h
 Date: April 11 2016
 The purpose of the program to implement autocomplete for a given set of N terms, where a term is a
query string and an associated nonnegative weight. That is, given a prefix, find all queries
that start with the given prefix, in descending order of weight.
 */

#ifndef AUTOCOMPLETE_H_
#define AUTOCOMPLETE_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Term.h"

using namespace std;


class Autocomplete
{
	public:
	/* inserts the newterm to the sequence */
	void insert(Term newterm);

	/* returns all terms that start with the given prefix, 
	  in descending order of weight<T>*/
	vector<Term> allMatches(string prefix);

	/* first: the index of the first query that equals 
	 the search key, or -1 if no such key
	 last: the index of the last query that equals 
	 the search key, or -1 if no such key */
	void Search(string key, int& first, int& last);

	/* return the index number of the search key 
	using binary search algorithm*/
	int BS_helper(vector<Term> terms, string key, int left, int right);
	
	/* display all the terms */
	void print();

	// other member functions you need...
	
	private:
	//choose your own data structure to represent the sequence of Term objects<T> terms;
	vector<Term> terms;
};

struct greaterTerm
{
	template<class T> 
	bool operator()(T a, T b) const { return a.getWeight() > b.getWeight(); }
};
#endif
// End of the Autocomplete.h
