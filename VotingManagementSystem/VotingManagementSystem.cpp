
#include <iostream>
#include <fstream>
#include"Candidate.h"
#include"Voter.h"
using namespace std;

void menu();
void NA_CandidateMenu(candidate na_candidates[], int naEntries);
void PA_CandidateMenu(candidate pa_candidates[], int paEntries);
void voterMenu(voter voters[], int voterEntries);

int main()
{
    cout << "Voting Management System\n";
	menu();
}

void menu()
{
	const int naSize = 5;
	candidate na_candidates[naSize];
	ifstream fin;
	fin.open("NA_Candidates.txt");
	try {
		if (fin.fail())
			throw runtime_error("There is no previously added NA Candidate record\n");
	}
	catch (runtime_error & e)
	{ 
		cout << e.what();
	}
	int naEntries = 0;
	if (!fin.fail()) {
		while (!fin.eof())
		{
			fin >> na_candidates[naEntries].areaNo >> na_candidates[naEntries].cnic >> na_candidates[naEntries].name >> na_candidates[naEntries].party;
			naEntries++;
		}
		naEntries -= 1;
	}
	const int paSize = 5;
	candidate pa_candidates[paSize];
	ifstream inputFile;
	inputFile.open("PA_Candidates.txt");
	try {
		if (inputFile.fail())
			throw runtime_error("There is no previously added PA Candidate record\n");
	}
	catch (runtime_error & e)
	{
		cout << e.what();
	}
	int paEntries = 0;
	if (!inputFile.fail())
	{
		while (!inputFile.eof())
		{
			inputFile >> pa_candidates[paEntries].areaNo >> pa_candidates[paEntries].cnic >> pa_candidates[paEntries].name >> pa_candidates[paEntries].party;
			paEntries++;
		}
		paEntries -= 1;
	}
	const int votersSize = 5;
	voter voters[votersSize];
	ifstream fileIn;
	fileIn.open("Voters.txt");
	try {
		if (fileIn.fail())
		{
			throw runtime_error("There is no previously added voter record\n");
		}
	}
	catch (runtime_error & e)
	{
		cout << e.what();
	}
	int voterEntries = 0;
	if (!fileIn.fail())
	{
		while (!fileIn.eof())
		{
			fileIn >> voters[voterEntries].cnic >> voters[voterEntries].na >> voters[voterEntries].pa >> voters[voterEntries].block >> voters[voterEntries].pollingStation;
			voterEntries++;
		}
		voterEntries -= 1;
	}

	while (1)
	{
		cout << "1.Manage N.A Candidate\n2.Manage P.A Candidate\n3.Manage Voter Detail\n4.Exit\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "N.A Candidate Management System\n";
			NA_CandidateMenu(na_candidates, naEntries);
			break;
		case 2:
			cout << "P.A Candidate Management System\n";
			PA_CandidateMenu(pa_candidates, paEntries);
			break;
		case 3:
			cout << "Voter Details Management System\n";
			voterMenu(voters, voterEntries);
			break;
		case 4:
			cout << "Program Ends\n";
			exit(0);
			break;

		default:
			cout << "You have entered invalid option!\n";
		}
	}

}

void NA_CandidateMenu(candidate na_candidates[], int naEntries)
{
	while (1)
	{
		cout << "1.Add\n2.View\n3.Back to main menu\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Add N.A Candidate Details(Area = N.A Number)\n";
			add(na_candidates, naEntries, 1);
			break;
		case 2:
			cout << "Viewing N.A Candidates' Details(Area = N.A Number)\n";
			view(na_candidates, naEntries);
			break;
		case 3:
			cout << "Going back to main menu!\n";
			menu();
			break;
		default:
			cout << "You have entered invalid option!\n";
		}
	}
}

void PA_CandidateMenu(candidate pa_candidates[], int paEntries)
{
	while (1)
	{
		cout << "1.Add\n2.View\n3.Back to main menu\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Add P.A Candidate Details(Area = P.A Number)\n";
			add(pa_candidates, paEntries, 2);
			break;
		case 2:
			cout << "Viewing P.A Candidates' Details(Area = P.A Number)\n";
			view(pa_candidates, paEntries);
			break;
		case 3:
			cout << "Going back to main menu!\n";
			menu();
			break;
		default:
			cout << "You have entered invalid option!\n";
		}
	}
}

void voterMenu(voter voters[], int voterEntries)
{
	while (1)
	{
		cout << "1.Add\n2.View\n3.Search\n4.Back to main menu\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Add Voter Details\n";
			add(voters, voterEntries);
			break;
		case 2:
			cout << "Viewing Voter Details\n";
			view(voters, voterEntries);
			break;
		case 3:
			cout << "Search the Voter\n";
			cout << "Enter voter's CNIC:";
			uint64_t searchCNIC;
			cin >> searchCNIC;
			bool flag;
			flag = search(voters, voterEntries, searchCNIC);
			if (flag)
			{
				cout << "Record of this voter has already been entered!\n";
			}
			else
			{
				cout << "Record of this voter does not exist!\n";
			}
			break;
		case 4:
			cout << "Going back to main menu!\n";
			menu();
		default:
			cout << "You have entered invalid option\n";
		}
	}
}
