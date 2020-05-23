#include "agendaLib.h"

contact* initProgram()
{
	int sz = lengthOfFile();

	if (sz)
	{
		ifstream fin;
		contact* contacts = new contact[sz];
		contact generic;

		fin.open("list.txt");

		for (int i = 0; i < sz; i++)
		{
			fin.get(generic.name, 20, '|');
			fin.get();
			fin >> generic.number;
			fin.get();
			contacts[i] = generic;
		}
		
		fin.close();
		return contacts;
	}
	else
	{
		contact* contacts = new contact[0];
		return contacts;
	}
}

int lengthOfFile()
{	
	ifstream fin;
	
	fin.open("list.txt");
	if (fin.is_open())
	{
		contact generic;
		int sz = 0;

		while (fin.get(generic.name, 20, '|') && fin.get() != EOF) // Count a new contact while it isn't the last one.
		{
			fin.get();
			fin >> generic.number;
			sz++;
		}

		fin.close();
		return sz;
	}
	else
	{
		fin.close();
		return 0;
	}
}

contact* addContact(contact* contacts, int& sz, int& qtElements, contact generic)
{
	if (!(sz - qtElements)) // If there is no space, increase. 
	{
		contact* backup = new contact[sz]; // Save contacts of the old array to a backup.

		for (int i = 0; i < qtElements; i++)
		{
			backup[i] = contacts[i];
		}

		delete[] contacts; // Delete the old array.

		contact* newOne = new contact[sz + 1]; // Create a new one.

		for (int i = 0; i < qtElements; i++) // Fill the new array with the backup content.
		{
			newOne[i] = backup[i];
		}

		delete[] backup;
		newOne[sz] = generic; // Add the new contact.
		sz++;
		qtElements++;

		return newOne; // Return the new array.
	}
	else
	{
		// The same logic viewed before, but there is no new array.

		contact* backup = new contact[qtElements];

		for (int i = 0; i < qtElements; i++)
		{
			backup[i] = contacts[i];
		}

		delete[] contacts;

		backup[qtElements] = generic;
		qtElements++;

		return backup;
	}
		
}

void listAllContacts(contact* contacts, int qtElements)
{
	for (int i = 0; i < qtElements; i++)
	{
		cout << i + 1 << " - " << contacts[i].name << " | " << contacts[i].number << endl;
	}
}

void deleteContact(contact* contacts, int& qtElements, int num)
{
	if (num == qtElements - 1) // If the element is the last of the list, decrease the quantity of Elements.
		qtElements--;
	else
	{
		// Go to the penultimate, to avoid the risk of accessing a wrong place, from the 
		// contact's position the user want to delete and replace for the next contact.
		for (; num < qtElements - 2; num++)
		{
			contacts[num] = contacts[num + 1];
		}

		// After that, deal with the last one out of the For structure. 
		contacts[num] = contacts[num + 1];
		qtElements--;
	}
}

void closeProgram(contact* contacts, int qtElements)
{
	ofstream fout;

	fout.open("list.txt");

	for (int i = 0; i < qtElements; i++)
	{
		fout << contacts[i].name << "|" << contacts[i].number;
		fout << endl;
	}

	fout.close();
}
