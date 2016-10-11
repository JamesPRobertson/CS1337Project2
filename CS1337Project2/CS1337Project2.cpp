//James Robertson
//jpr160030

#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <string>

using namespace std;

struct Contestant {
	string id;
	float score;
	char* answerStart;
}
Contestant_default = { 0,0,new char};
typedef struct Contestant_default;

int main() {
	char* answerStart;
	Contestant* contestants;

	ifstream inFile;
	ifstream contestantsFile;
	ofstream outFile;

	int answerCount = 0;
	int contestantCount = 0;

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
		*(contestants + i) = foo;
		contestantsFile >> foo.id;

		contestantCount++;

		foo.answerStart = new char;

		for (int x = 0; x < answerCount; x++) {
			contestantsFile >> *(foo.answerStart + x);
		}
	}

	for (int i = 0; i < contestantCount; i++) {
		int correct = 0;

		Contestant foo = *(contestants + i);

		for (int x = 0; x < answerCount; x++) {
			if (*(answerStart + x) == *(foo.answerStart + x)) {
				correct++;
			}
		}

		foo.score = (correct / answerCount) * 100;
	}

	for (int i = 0; i < contestantCount; i++) {
		Contestant foo = *(contestants + i);
		outFile << foo.id << "\n";
		outFile << foo.score << "\n";

		for (int x = 0; x < answerCount; x++) {
			if (*(answerStart + x) != *(foo.answerStart + x)) {
				outFile << x + 1 << " " << *(foo.answerStart + x) << " " << *(answerStart + x) << "\n";
			}	
		}
		outFile << "\n";
	}

	return 0;
}