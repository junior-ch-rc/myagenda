#include <iostream>
#include <fstream>
using namespace std;

struct contact
{
	char name[20];
	char number[9];
};

contact* initProgram();

int lengthOfFile();

contact* addContact(contact*, int&, int&, contact); // Passed some variables for reference to modify them.

void listAllContacts(contact*, int);

void deleteContact(contact*, int&, int);

void closeProgram(contact*, int);