// C++ program to create a directory in Linux
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;
int main()
{
	// Creating a directory
	if (mkdir("geeksforgeeks") == -1)
		cout << "Error creating file"<< endl;
	else
		cout << "Directory created";
}

