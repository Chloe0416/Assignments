#include <iostream>
using namespace std;

struct Highscore {
	int score;
	char* name = new char[24];
};


// let user enter every names and scores
void initializeData(Highscore scores[], int size) {

	for (int i = 0; i < size; i++) {
		char* name = new char[24];
		cout << "Please enter a name with no more than 23 characters: ";
		cin >> name;
		scores[i].name = name;

		int score;
		cout << "Please enter his/her score: ";
		cin >> score;
		scores[i].score = score;
	}

}

void sortData(Highscore scores[], int size) {

	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			if (scores[i].score > scores[j].score) {
				Highscore temp;
				temp = scores[i];
				scores[i] = scores[j];
				scores[j] = temp;
			}
		}
	}

}

void displayData(const Highscore scores[], int size) {
	for (int i = 0; i < size; i++) {
		cout << scores[i].name << " : " << scores[i].score << endl;
	}
}

int main() {

	int size;
	cout << "Please enter the size: ";
	cin >> size;

	// check user input of the size, should be > 0
	while (size <= 0) {
		cout << "Please enter a correct number of size: ";
		cin >> size;
	}

	Highscore *scores = new Highscore[size];

	initializeData(scores, size);
	// Output before sorting
	cout << "Datas before sorting: \n";
	displayData(scores, size);
	sortData(scores, size);
	//Output after sorting
	cout << "Datas after sorting: \n";
	displayData(scores, size);
	
	

	system("pause");
	return 0;
}