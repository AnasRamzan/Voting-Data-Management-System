#pragma once

using namespace std;

struct candidate
{
	int areaNo;
	string cnic;
	string name;
	string party;
};

void add(candidate na_candidates[], int naEntries, int identifier);
void save(candidate na_candidates[], int naEntries, int identifier);
void view(candidate na_candidates[], int naEntries);

void add(candidate na_candidates[], int naEntries, int identifier)
{
	cout << "Enter Area Number:";
	cin >> na_candidates[naEntries].areaNo;
	cout << "Enter Candidate's CNIC:";
	cin >> na_candidates[naEntries].cnic;
	cout << "Enter Candidate's Name:";
	cin >> na_candidates[naEntries].name;
	cout << "Enter Candidate's Political Party:";
	cin >> na_candidates[naEntries].party;
	save(na_candidates, naEntries, identifier);
}
void save(candidate na_candidates[], int naEntries, int identifier)
{
	ofstream fout;
	if (identifier == 1)
	{
		fout.open("NA_Candidates.txt");
	}
	else
	{
		fout.open("PA_Candidates.txt");
	}
	for (int i = 0; i < naEntries + 1; i++)
	{
		fout << na_candidates[i].areaNo << " " << na_candidates[i].cnic << " " 
			<< na_candidates[i].name << " " << na_candidates[i].party << endl;
	}
	fout.close();
}
void view(candidate na_candidates[], int naEntries)
{
	cout << "Area\tName\tParty\tCNIC\n";
	for (int i = 0; i < naEntries; i++)
	{
		cout << na_candidates[i].areaNo << "\t" << na_candidates[i].name << "\t"
			<< na_candidates[i].party << "\t" << na_candidates[i].cnic << endl;
	}
}

