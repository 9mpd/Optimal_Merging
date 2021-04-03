Copyright (c) 2021, 9mpd
All rights reserved.

This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree. 
	
// IMPLEMENTATION OF OPTIMAL MERGE PATTERN 
#include <iostream>
#include <vector>
#include <iterator> 
#include <algorithm>    // sort()
#include <unistd.h>     // sleep()

using namespace std;

// Comaprator to sort vector pair.
bool comparator(const pair<int, int> &a, 
               const pair<int, int> &b)      
{ 
    return (a.second < b.second); 
} 
 
void vec_row_merge(vector <int>& v1,vector <int>& v2,vector <int>& l)
{
	int i=0,j=0;
	// Merging two sorted vectors.
	while(i<v1.size()&&j<v2.size())     
	{      
		if(v1[i]<=v2[j]){
			l.push_back(v1[i]);
			i=i+1;                           
		}
		else{
			l.push_back(v2[j]);
			j=j+1;
		}
	}
	// Adding the remaining elements of 1st vector, if any.
	while(i<v1.size())                 
	{
		l.push_back(v1[i]);
		i=i+1;
	}
	// Adding the remaining elements of 1st vector, if any.
	while(j<v2.size())
	{
		l.push_back(v2[j]);           
		j=j+1;
	}
}

int main()
{
	int n, x, data;
	cout<<"Enter the number of data sets you want to merge : ";
	cin>>n;                              
	
	// Making a 2D vector, vector of vectors, in which each sub-vector is a data set to merge using merge sort.
	vector<vector<int> > ml(n); 
	
	//Making two 1D vectors.       
	vector<int> l, mincomputation;       
	
	//Making a vector pair.              
	vector<pair<int, int> > v;
	
	for(int i = 0; i < n; i++)
	{
		cout<<"\nEnter the number of element(s) in "<<i+1<<"th data set : ";
		cin>>x;
		
		// Making each row of the 2D vector a vector.
		ml[i] = vector<int>(x);
		
		cout<<"Enter the "<<x<<" element(s) in "<<i+1<<"th data set : ";
		for(int j = 0; j < x; j++)
		{
			cin>>data;
			l.push_back(data);
		}
		
		//Sorting the data set entered by user.
		sort(l.begin(),l.end());
		
		//Transferring the data set from vector l into one of the rows of 2D vector.
		ml[i] = l;
		
		// Making a vector pair of indices of data-sets i  2D vector and their corresponding sizes.
		v.push_back(make_pair(i, l.size()));
		
		l.clear();
	}
	
	// Printing the data sets entered by user.
	cout<<"\nYou entered : "<<endl;
	for(int i = 0; i < n; i++)
	{
		sleep(2);
		cout<<"SET "<<i+1<<" : ";
		for(int j = 0; j < ml[i].size(); j++)
		{
			cout<<ml[i][j]<<" ";
		}
		cout<<"  SIZE : "<<v[i].second<<endl;
	}
    
    // Sorting the vector pair according to the size of data-sets in 2D vector.
	sort(v.begin(), v.end(), comparator);
	
	while(v.size()!=1)
	{	
	    // Merging two data - sets of smallest size in a vector l.
		vec_row_merge(ml[v[0].first], ml[v[1].first], l);
		
		cout<<"\nMerging data sets "<<v[0].first+1<<" and "<<v[1].first+1<<endl;
		sleep(2);
		cout<<"Merging of data sets "<<v[0].first+1<<" and "<<v[1].first+1<<" required "<<v[0].second+v[1].second<<" computations."<<endl;
		
		//Storing the computations required to calculate the final minimum computations required.
		mincomputation.push_back(v[0].second+v[1].second);
		
		// Transferring vector l in one of the row of the 2D vector.	  	
		ml[v[0].first] = l;
		
		// Printing the updated data-set after each merge.
		sleep(2);
		cout<<"\nUpdated data set "<<v[0].first+1<<" to : ";
		for(int i = 0; i < ml[v[0].first].size(); i++)
		cout<<ml[v[0].first][i]<<" ";
		cout<<"  NEW SIZE : "<<l.size()<<endl;
		
		l.clear();
		
		// Updating the vector pair.
		v.push_back(make_pair(v[0].first, (v[0].second + v[1].second)));
		
		// Removing the indices and size of two smallest data-dets that has been merged.
		v.erase(v.begin());
		v.erase(v.begin());
		
		//Sorting to the vector pair to access the two smallest data-sets to merge.
		sort(v.begin(), v.end(), comparator);
	}
	
	//Printing the final result after performing optimal merge on each pair data sets.
	sleep(2);
	cout<<"\n\nFinal data-set after performing optimal merge pattern on the given data-sets : "<<endl;	
	for(int i = 0; i < ml[v[0].first].size(); i++)
	cout<<ml[v[0].first][i]<<" ";
	
	//Printing the minimum computations required to optimally merge the given data-sets by following optimal merge pattern.
	int mincom = 0;
	for(int i = 0; i < mincomputation.size(); i++)
	{
		mincom = mincom + mincomputation.at(i);
	}
	sleep(2);
	cout<<"\n\nMinimum computations required to optimally merge the given data-sets by following optimal merge pattern = "<<mincom<<endl;
	
	return 0;
}
	
	
	
	
