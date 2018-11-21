#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std; // shouldn't use this in a headerfile, but for easiness its ok

class matrixManip {
private: // Class variables that can only be accessed by THIS class
	wchar_t newMatrix[200000] = {}; // generated matrix of charas
	char letters[4] = { 'G','C','A','T' };  //array of characters that can be used
	char gen[4]; // temp storage for generated values
	int newMatrixSize = 0; // size of generated matrix
	int counter; // counter for number of repetitions
	string temp; // temp string to hold generated matrix comparisons in vector
	vector<string> combi; // combination vector 
	int vectcounter = 0; // size of vector 
	int iterator = 0;
	vector<char> generatedMatrix; // generated matrix vector
	vector<int> analysedData;
	int tempData;
public:
	

	vector<char> generateMatrix(int a) {
		srand(time(NULL));// seed of random generated number
		unsigned long int generateNumber;
		generateNumber = a;
		int randomNumber;
		int count = 0;

		for (int x = 0; x < generateNumber; x++)
		{
			count++;
			randomNumber = rand() % 4;
			if (randomNumber == 0) { newMatrix[x] = 'G'; generatedMatrix.push_back('G'); }
			if (randomNumber == 1) { newMatrix[x] = 'C'; generatedMatrix.push_back('C'); }
			if (randomNumber == 2) { newMatrix[x] = 'A'; generatedMatrix.push_back('A'); }
			if (randomNumber == 3) { newMatrix[x] = 'T'; generatedMatrix.push_back('T'); }
		}
		return generatedMatrix;
	}


	void printGeneratedMatrix() {
		for (std::vector<char>::iterator it = generatedMatrix.begin(); it != generatedMatrix.end(); ++it)
		{
			if (it == generatedMatrix.begin())
			{
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
						gen[0] = letters[position1];
						gen[1] = letters[position2];
						gen[2] = letters[position3];
						gen[3] = letters[position4];
						//analysed.push_back()
						counter = 0; // resets counter to 0 for function checker						
						temp = temp + gen[0] + gen[1] + gen[2] + gen[3];
						combi.push_back(temp);
						newMatrixSize = sizeof(newMatrix);
						newMatrixSize = newMatrixSize / 4;
						tempData = functionChecker();
						analysedData.push_back(tempData);
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

	int functionChecker() {  // internal check faster route
		for (int randomMatrixChecker = 0; randomMatrixChecker < newMatrixSize; randomMatrixChecker++) {
			if (newMatrix[randomMatrixChecker] == gen[0] && newMatrix[randomMatrixChecker + 1] == gen[1] && newMatrix[randomMatrixChecker + 2] == gen[2] && newMatrix[randomMatrixChecker + 3] == gen[3])
			{
				counter++;
			}
		}

		cout << gen[0] << gen[1] << gen[2] << gen[3] << " ," << counter << endl;
		return counter;
	}

	void functionChecker2() {
		for (std::vector<string>::iterator it = combi.begin(); it != combi.end(); ++it) {
			int index0 = 0;
			int index1 = 1;
			int index2 = 2;
			int index3 = 3;
			int counter = 0;

			for (std::vector<char>::iterator iit = generatedMatrix.begin(); iit != generatedMatrix.end(); ++iit)
			{
				string temp = "";
				if (index3 == generatedMatrix.size()) { break; }
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
				//cout << "Next Combi is" << *it; // can display it here or outside with return value.
				break;
			}
		}
		return temp;
	}

	void dataToCsvFile() {
		ofstream csvFile;
		csvFile.open("analysis.csv");
		
		for (int i = 0; i < combi.size(); i++) {



			csvFile << combi.at(i) << "," << analysedData.at(i) << endl;

		}
	}

};

