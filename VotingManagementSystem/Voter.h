#pragma once
using namespace std;
struct voter
{
	uint64_t cnic;
	int na;
	int pa;
	int block;
	string pollingStation;
};

void add(voter voters[], int voterEntries);
void save(voter voters[], int voterEntries);
void view(voter voters[], int voterEntries);
bool search(voter voters[], int voterEntries, uint64_t target);

void add(voter voters[], int voterEntries)
{
	cout << "Enter CNIC of Voter:";
	cin >> voters[voterEntries].cnic;
	cout << "Enter N.A Number of Voter:";
	cin >> voters[voterEntries].na;
	cout << "Enter P.A Number of Voter:";
	cin >> voters[voterEntries].pa;
	cout << "Enter Block Number of Voter:";
	cin >> voters[voterEntries].block;
	cout << "Enter Polling Station for Voter:";
	cin >> voters[voterEntries].pollingStation;
	save(voters, voterEntries);
}

void save(voter voters[], int voterEntries)
{
	ofstream fout;
	fout.open("Voters.txt");
	for (int i = 0; i < voterEntries + 1; i++)
	{
		fout << voters[i].cnic << " " << voters[i].na << " " << voters[i].pa 
			<< " " << voters[i].block << " " << voters[i].pollingStation << endl;

	}
	fout.close();
}

void view(voter voters[], int voterEntries)
{
	cout << "CNIC\t\tN.A\tP.A\tBlock\tPolling_Station\n";
	for (int i = 0; i < voterEntries; i++)
	{
		cout << voters[i].cnic << "\t" << voters[i].na << "\t" << voters[i].pa
			<< "\t" << voters[i].block << "\t" << voters[i].pollingStation << endl;
	}
}

bool search(voter voters[], int voterEntries, uint64_t target)
{
	for (int i = 0; i < voterEntries; i++)
	{
		if (voters[i].cnic == target)
		{
			return 1;
		}
	}
	return 0;
}

