/*#include "data.h"
#include <string>

int main() {

	matrixManip one;  
	cout << "Enter amount of letters you want to generate";
	int number;
	cin >> number;
	one.generateMatrix(number);  // generates random matrix 
	one.generateCombinations();
	one.printAllCombinations();
	one.functionChecker2();
	cout << "Enter the string you want for next combination checker" << endl;
	string combination = "";
	cin >> combination;
	one.nextCombination(combination);
	int end; // just so the cmd tool stays to show outputs - remove this from code before submitting
	cin >> end;
	
}*/
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

class matrixManip {
private: // Class variables that can only be accessed by THIS class
	wchar_t newMatrix[200000] = {};
	char letterss[4] = { 'G','C','A','T' };
	char gen[4];
	int newMatrixSize = 0;
	int counter;
	string temp;
	vector<string> combi;
	int vectcounter = 0;
	int iterator = 0;
	vector<char> generatedMatrix;

public:


	vector<char> generateMatrix(int a) {
		srand(time(NULL));
		unsigned long int generateNumber;
		generateNumber = a;
		int randomNumber;
		char letters[4] = { 'G','C','A','T' }; //Stores useable characters
		int count = 0;

		for (int x = 0; x < generateNumber; x++) {
			count++;
			randomNumber = rand() % 4;

			if (randomNumber == 0) { generatedMatrix.push_back('G'); }

			if (randomNumber == 1) { generatedMatrix.push_back('C'); }

			if (randomNumber == 2) { generatedMatrix.push_back('A'); }

			if (randomNumber == 3) { generatedMatrix.push_back('T'); }
		}
		return generatedMatrix;
	}
	void printGeneratedMatrix() {
		for (std::vector<char>::iterator it = generatedMatrix.begin(); it != generatedMatrix.end(); ++it)
		{
			if (it == generatedMatrix.begin()) {
				cout << "[ ";
			}
			cout << *it << " ";
		}
		cout << "]" << endl;
	}

	vector<string> generateCombinations() {


		for (int position1 = 0; position1 < 4; position1++)
		{

			for (int position2 = 0; position2< 4; position2++)
			{

				for (int position3 = 0; position3 < 4; position3++)
				{

					for (int position4 = 0; position4 < 4; position4++)
					{
						temp = {};
						gen[0] = letterss[position1];
						gen[1] = letterss[position2];
						gen[2] = letterss[position3];
						gen[3] = letterss[position4];
						counter = 0; // resets counter to 0 for function checker
									 //functionChecker();
						temp = temp + gen[0] + gen[1] + gen[2] + gen[3];
						combi.push_back(temp);

						newMatrixSize = sizeof(newMatrix);
						newMatrixSize = newMatrixSize / 4;
						vectcounter++;


					}
				}
			}
		}
		return combi;
	}

	void printAllCombinations() {
		for (std::vector<string>::iterator it = combi.begin(); it != combi.end(); ++it)
		{

			cout << *it << endl;

		}
	}

	void functionChecker() {  // internal check
		for (int randomMatrixChecker = 0; randomMatrixChecker < newMatrixSize; randomMatrixChecker++) {
			if (newMatrix[randomMatrixChecker] == gen[0] && newMatrix[randomMatrixChecker + 1] == gen[1] && newMatrix[randomMatrixChecker + 2] == gen[2] && newMatrix[randomMatrixChecker + 3] == gen[3])
			{
				counter++;
			}
		}
		cout << "," << counter << endl;
	}

	void functionChecker2() {


		for (std::vector<string>::iterator it = combi.begin(); it != combi.end(); ++it) {
			int index0 = 0;
			int index1 = 1;
			int index2 = 2;
			int index3 = 3;
			int counter = 0;
			// cout <<"current combi" <<*it << endl;

			for (std::vector<char>::iterator iit = generatedMatrix.begin(); iit != generatedMatrix.end(); ++iit)
			{
				string temp = "";
				if (index3 == (size(generatedMatrix))) { break; }
				temp = temp + generatedMatrix.at(index0) + generatedMatrix.at(index1) + generatedMatrix.at(index2) + generatedMatrix.at(index3);
				//cout << "combi at blah is" << *it << "amd temp is" << temp << endl;
				if (*it == temp) {
					//cout << *it << "amd" << temp << endl;
					counter++;
				}

				
				index0++; index1++; index2++; index3++;




			} cout << *it << ", " << counter << endl;

		}
	}

	string nextCombination(string a) {



		for (std::vector<string>::iterator it = combi.begin(); it != combi.end(); ++it)
		{


			if (a == *it) {
				it++;
				if (it == combi.end()) { temp = "AAAA"; return temp; } // if the last value of vectors entered. Starts again
				temp = *it;
				cout << "Next Combi is" << *it;
				break;
			}
		}
		return temp;
	}
};

int main() {

	matrixManip one;
	cout << "Enter amount of letters you want to generate";
	int number;
	cin >> number;
	vector <char> generatedMatrix;
	vector <string> allCombinations;

	generatedMatrix = one.generateMatrix(number);
	one.printGeneratedMatrix();
	allCombinations = one.generateCombinations();
	one.printAllCombinations();
	one.functionChecker2();
	//cout << "Enter the string you want for next combination checker" << endl;
	//string combination = "";
	//	cin >> combination;
	//combination = one.nextCombination(combination);
	//cout << "combination is" << combination;
	int end; // just so the cmd tool stays to show outputs - remove this from code before submitting
	cin >> end;

}
