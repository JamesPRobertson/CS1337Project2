//James Robertson
//jpr160030

#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

struct Contestant {
	string id;
	float score;
	char* answerStart;
};

int main() {
	char* answerStart;
	vector<Contestant> contestants = vector<Contestant>();

	ifstream inFile;
	ifstream contestantsFile;
	ofstream outFile;

	int answerCount = 0;

	answerStart = new char;

	inFile.open("answers.txt");
	contestantsFile.open("contestants.txt");
	outFile.open("report.txt");
	
	if (inFile.fail() || contestantsFile.fail()) {
		cout << "\nFilestream read error\n" << endl;
		return 0;
	}

	for (int i = 0; !inFile.eof(); i++) {
		inFile >> *(answerStart + i);
		answerCount++;
	}

	for (int i = 0; !contestantsFile.eof(); i++) {
		Contestant foo;

		contestantsFile >> foo.id;
		foo.answerStart = new char;

		for (int x = 0; x < answerCount; x++) {
			contestantsFile >> *(foo.answerStart + x);
		}

		contestants.push_back(foo);

	}

	for (int i = 0; i < contestants.size(); i++) {
		int correct = 0;

		Contestant foo = contestants.at(i);

		for (int x = 0; x < answerCount; x++) {
			if (*(answerStart + x) == *(foo.answerStart + x)) {
				correct++;
			}
		}

		foo.score = ((float)correct / (float)answerCount) * 100;
	}

	for (int i = 0; i < contestants.size(); i++) {
		Contestant foo = contestants.at(i);
		outFile << foo.id << "\n";
		outFile << foo.score << "\n";

		for (int x = 0; x < answerCount; x++) {
			if (*(answerStart + x) != *(foo.answerStart + x)) {
				outFile << x + 1 << ") " << *(foo.answerStart + x) << " " << *(answerStart + x) << "\n";
			}	
		}
		outFile << "\n";
	}

	return 0;
}