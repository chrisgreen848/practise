#include "data.h"
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
	//one.printAllCombinations();
	//one.functionChecker2(); //checks outside of function - functionchecker inside checks internally as the matrix is generated for speed.
	cout << "Enter the string you want for next combination checker" << endl;
	string combination = "";
	cin >> combination;
	combination = one.nextCombination(combination);
	cout << "combination is " << combination;

	one.dataToCsvFile();
	int end; // just so the cmd tool stays to show outputs - remove this from code before submitting
	cin >> end;

}
