#include <iostream>
#include <fstream>

using namespace std;

int main(){
	char* answerStart;
	ifstream inFile;

	answerStart = new char;
	
	inFile.open("../answers.txt", ios::in);

	//Failsafe, if we can't read the file don't even run the program
	if (inFile) {
		cout << "\nFilestream read error\n" << endl;

		system("pause");
		return 0;
	}

	for (int i = 0; i < 5; i++) {
		cin >> *(answerStart + i);
		cout << "Out: " << *(answerStart + i) << endl;
	}

	for (int i = 0; i < 5; i++) {
		cout << *(answerStart + i) << " ";
	}
	
	//assuming the file goes: a b c d e f. We can use ifstream.ignore to skip whitespace
	/*
	for (int i = 0; !inFile.eofbit; i++) {
		*(answerStart += i) = inFile.get();
		inFile.ignore();
		cout << *(answerStart + i) << endl;
	}
	

	for (int i = 0; i < 10; i++) {
		cout << endl << *(answerStart + i);
	}
	*/
	system("pause");
    return 0;
}
	