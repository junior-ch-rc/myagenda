/*
Author: @junior.ch.rc
The purpose of this program is implement a simple telephonic agenda that you can: add,
edit, list and delete contacts and save them permanently into a text file.
*/

#include "agendaLib.h"

int main()
{
	// Every time the program initiate, the function initProgram() will be called
	// to fill the contacts array with the contacts in the text file or let it empty.
	contact* contacts = initProgram();
	int sz = lengthOfFile(); // Represent the array size, initially with the length of text file.
	int qtElements = sz; // Represent the numbers of elements in the array.

	bool repit = true;
	while (repit)
	{
		system("cls");
		cout << "==== MY AGENDA ====" << endl;
		cout << "(a)dd a new contact" << endl;
		cout << "(e)dit an existing contact" << endl;
		cout << "(l)ist all contacts" << endl;
		cout << "(d)elete a contact" << endl;
		cout << "(c)lose the program\n" << endl;

		char opt;
		cout << "Choose an option by the first letter: [ ]\b\b";
		cin >> opt;

		switch (opt)
		{
			case 'a': case 'A':
			{
				system("cls");
				contact generic; // Generic contact to be a new one.

				cin.get();
				cout << "Digite o name do contato: ";
				cin.getline(generic.name, 20);
				cout << "Digite o número do contato: ";
				cin >> generic.number;

				// To add a new contact, the function addContact will verify if there is space in array
				// to add, if there isn't, a new array with size sz + 1 is created and used from now
				// with the new contact. If there is space, I had do create a new array with the same size
				// only to return a contact*.
				contacts = addContact(contacts, sz, qtElements, generic);
				break;
			}
			case 'e': case 'E':
			{
				system("cls");

				listAllContacts(contacts, qtElements);

				int num;
				cout << "Type the number of who you want to edit: ";
				cin >> num;

				contact generic; // Generic contact to be an edited contact.
				cout << "Enter the name: ";
				cin.get();
				cin.getline(generic.name, 20);
				cout << "Enter the telephone number: ";
				cin >> generic.number;

				contacts[num - 1] = generic; // Save the edited contact in the same position of the old one.
				break;
			}
			case 'l': case 'L':
			{
				system("cls");

				if (qtElements == 0)
				{
					cout << "Não há contatos!";
				}
				else
				{
					listAllContacts(contacts, qtElements); // A simple For.
				}
				
				break;
			}
			case 'd': case 'D':
			{
				system("cls");

				listAllContacts(contacts, qtElements);

				int num;
				cout << "Type the number of who you want to delete: ";
				cin >> num;

				// The same logic used when edit a contact, 
				// the difference is that I used a function to delete.
				deleteContact(contacts, qtElements,--num);

				break;
			}
			default:
			{
				cout << "Invalid option\n";
				system("pause");
				break;
			}
			case 'c': case 'C':
			{

			}
		}

		cout << "\n\nDo you want to close the program (s or S to yes): [ ]\b\b";
		cin >> opt;

		if (opt == 's' || opt == 'S')
		{
			closeProgram(contacts, qtElements); // Write the contacts array into a text file in the end.
			delete[] contacts;
			repit = false;
		}
	}
}