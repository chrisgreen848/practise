/******************************************************************************

							  Online C++ Compiler.
			   Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

class matrixManip {
	wchar_t newMatrix[200000] = {};
	char letterss[4] = { 'G','C','A','T' };
	char gen[4] = {};
	int newMatrixSize = 0;
	int counter;
	string temp;
	vector<string> combi;
	int vectcounter = 0;
	int iterator = 0;
public:


	void generateMatrix(int a) {
		srand(time(NULL));
		unsigned long int generateNumber;
		generateNumber = a;
		int randomNumber;
		char letters[4] = { 'G','C','A','T' };
		int count = 0;


		for (int x = 0; x < generateNumber; x++) {

			count++;
			randomNumber = rand() % 4;



			if (randomNumber == 0)
			{
				newMatrix[x] = 'G';
			}

			if (randomNumber == 1) {
				newMatrix[x] = 'C';
			}
			if (randomNumber == 2)
			{
				newMatrix[x] = 'A';
			}
			if (randomNumber == 3)
			{
				newMatrix[x] = 'T';
			}
		}


		for (int x = 0; x < generateNumber + 1; x++) {

			if (x == 0) {
				cout << "[";
			}
			cout << " " << char(newMatrix[x]);

			if (newMatrix[x] == NULL) {
				cout << "]" << endl;
				break;
			}

		}
	}

	void generateCombinations() {


		for (int position1 = 0; position1 < 4; position1++)
		{

			for (int position2 = 0; position2 < 4; position2++)
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
						counter = 0;
						functionChecker();
						temp = temp + gen[0] + gen[1] + gen[2] + gen[3];
						combi.push_back(temp);

						newMatrixSize = sizeof(newMatrix);
						newMatrixSize = newMatrixSize / 4;
						vectcounter++;


					}
				}
			}
		}
	}

	void printAllCombinations() {
		for (std::vector<string>::iterator it = combi.begin(); it != combi.end(); ++it)
		{

			cout << *it << endl;

		}
	}

	void functionChecker() {
		for (int randomMatrixChecker = 0; randomMatrixChecker < newMatrixSize; randomMatrixChecker++) {
			if (newMatrix[randomMatrixChecker] == gen[0] && newMatrix[randomMatrixChecker + 1] == gen[1] && newMatrix[randomMatrixChecker + 2] == gen[2] && newMatrix[randomMatrixChecker + 3] == gen[3])
			{
				counter++;
			}
		}
	}

	string nextCombination(string a) {



		for (std::vector<string>::iterator it = combi.begin(); it != combi.end(); ++it)
		{


			if (a == *it) {
				it++;
				if (it == combi.end()) { temp = "AAAA"; return temp; }
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


	one.generateMatrix(number);
	one.generateCombinations();
	one.printAllCombinations();
	cout << "Enter the string you want for next combination checker" << endl;
	string combination = "";
	cin >> combination;
	combination = one.nextCombination(combination);
	cout << "combination is" << combination;
	int end; // just so the cmd tool stays to show outputs - remove this from code before submitting
	cin >> end;

}
