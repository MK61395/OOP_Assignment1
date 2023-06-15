#pragma once

#include <iostream>

using namespace std;




//--------------------------------------------------Question 1 --------------------------------------------------
char** bookSeats(int rows) {

	char** bus = new char* [rows];

	int totalSeats = rows * 4, seatsFilled = 0;

	for (int i = 0; i < rows; i++)
		*(bus + i) = new char[5];

	for (int i = 0; i < rows; i++)
	{
		char temp = '1' + i;
		string fixed = "ABCD", final = temp + fixed;
		int n = final.length();
		char* tempArray = new char[n + 1];
		strcpy(tempArray, final.c_str());
		strcpy(*(bus + i), tempArray);
	}

	string inp;

	while (inp != "x" && inp != "X" && seatsFilled != totalSeats)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << bus[i][j] << " ";
			}
			cout << endl;
		}
		cout << "\nTo exit type 'x' or 'X'\nEnter seat number to book: ";
		cin >> inp;
		system("CLS");
		if (inp != "x" && inp != "X")
		{
			if (bus[inp[0] - 49][inp[1] - 64] != 'X')
			{
				bus[inp[0] - 49][inp[1] - 64] = 'X';
				seatsFilled++;
			}
			else if (bus[inp[0] - 49][inp[1] - 64] == 'X')
			{
				cout << "Seat occupied. Select another.\n\n";
			}
		}

	}
	return bus;
	// Code Here
}


//-------------------------------------------------- Question 2A --------------------------------------------------


int maxScore(int**& matrix, int rows, int cols) {
	int score = 0, index1 = 0, index2 = 0;
	bool flag = false;
	if (matrix[index1][index2] == 1)
	{
		score++;
	}
	while (flag == false)
	{
		if (matrix[0][0] == -1)
		{
			flag = true;
		}
		if (index1 % 2 == 1) //odd
		{

			if ((matrix[index1][index2 - 1] == 0 || matrix[index1][index2 - 1] == 1) && index2 - 1 >= 0)
			{
				index2--;
				if (matrix[index1][index2] == 1)
				{
					score++;
				}
			}
			else if ((matrix[index1 + 1][index2] == 0 || matrix[index1 + 1][index2] == 1) && index1 + 1 < rows)
			{
				index1++;
				if (matrix[index1][index2] == 1)
				{
					score++;
				}

			}
			else
			{
				flag = true;
			}
		}
		else //even
		{
			if ((matrix[index1][index2 + 1] == 0 || matrix[index1][index2 + 1] == 1) && index2 + 1 < cols)
			{
				index2++;
				if (matrix[index1][index2] == 1)
				{
					score++;
				}
			}
			else if ((matrix[index1 + 1][index2] == 0 || matrix[index1 + 1][index2] == 1) && index1 + 1 < rows)
			{
				index1++;
				if (matrix[index1][index2] == 1)
				{
					score++;
				}

			}
			else
			{
				flag = true;
			}
		}
	}
	return score;
}

//void Question2()
//{
//	srand((unsigned)time(0));
//	int randomNumber;
//	int rows, cols;
//	cout << "\nEnter number of rows and cols: ";
//	cin >> rows >> cols;
//	int** matrix = new int* [rows];
//	for (int i = 0; i < rows; i++)
//	{
//		matrix[i] = new int[cols];
//	}
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			randomNumber = (rand() % 3) - 1;
//			matrix[i][j] = randomNumber;
//		}
//	}
//	cout << endl;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			cout << matrix[i][j] << "\t";
//		}
//		cout << endl;
//	}
//	int score = maxScore(matrix, rows, cols);
//	cout << "\nScore is: " << score << "\n\n";
//}

//-------------------------------------------------- Question 2B ---------------------------------------------------

int minCost(int**& matrix, int rows, int cols) {
	int index1 = 0, index2 = 0, cost = 0, minCost = 1000, randomNum;
	srand((unsigned)time(0));
	for (int i = 0; i < 300; i++)
	{
		cost = 0;
		cost += **matrix;
		index1 = 0;
		index2 = 0;
		while (index1 != rows - 1 || index2 != cols - 1)
		{
			randomNum = rand() % 2;
			/*if ((*(*(matrix + index1) + index2 + 1) < *(*(matrix + index1 + 1) + index2)) && index2 + 1 < cols)*/
			if (randomNum == 0 && index2 + 1 < cols)
			{
				index2++;
				cost += *(*(matrix + index1) + index2);
			}
			else if (index1 + 1 < rows)
			{
				index1++;
				cost += *(*(matrix + index1) + index2);
			}
		}
		if (cost < minCost)
		{
			minCost = cost;
		}
	}
	return minCost;
}

//-------------------------------------------------- Question 3 --------------------------------------------------

char** allocateNames(int n) {
	char** names = new char* [n];
	for (int i = 0; i < n; i++)
	{
		names[i] = new char[10];
		names[i][0] = '\0';
	}
	return names;
}

void setNames(int len, char**& names, char* n) {
	int index = 0;
	while (names[index][0] != '\0')
	{
		index++;
	}
	names[index] = n;
}

int* allocateVotes(int n) {
	int* votes = new int[n];
	for (int i = 0; i < n; i++)
	{
		votes[i] = 0;
	}
	return votes;
}

void setVotes(int len, char** names, char* name, int*& votes, int v) {
	int index = 0;
	while (votes[index] != 0)
	{
		index++;
	}
	votes[index] = v;
}

int returnTotalVotes(int n, int* candidateVotes) {
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += candidateVotes[i];
	}
	return total;
}

float* allocatePercentages(int n, int* candidateVotes) {
	int totalVotes = returnTotalVotes(n, candidateVotes);
	float* percentages = new float[n];
	for (int i = 0; i < n; i++)
	{
		percentages[i] = (candidateVotes[i] / float(totalVotes)) * 100;
	}
	return percentages;
}

//--------------------------------------------------Question 4 --------------------------------------------------


void calculateHistogram(int* marks, int*& histogram, int noOfMarks) {
	int max = 0;
	for (int i = 0; i < noOfMarks; i++)
	{
		if (marks[i] > max)
		{
			max = marks[i];
		}
	}
	histogram = new int[max + 1];
	for (int i = 0; i < max + 1; i++)
	{
		histogram[i] = 0;
	}
	for (int i = 0; i < noOfMarks; i++)
	{
		histogram[marks[i]]++;
	}
}


////--------------------------------------------------Question 5 --------------------------------------------------

int maximum(int* Arr, int size)
{
	int max = *Arr;
	int* newArr = new int[size + 1];
	newArr = Arr;
	newArr[size] = -1;
	while (*newArr != -1) {
		if ((*(newArr + 1)) > max) {
			max = *(newArr + 1);
		}
		newArr++;
	}
	return max;
}



void swap(int* a, int* b) {
	int* temp = new int;
	*temp = *a;
	*a = *b;
	*b = *temp;
}





int* merge(int* Arr1, int* Arr2, int size1, int size2) {

	int* merged = new int[size1 + size2];
	for (int i = 0; i < size1; i++) {
		merged[i] = Arr1[i];
	}
	int k = 0;
	for (int i = size1; i < size1 + size2; i++) {
		merged[i] = Arr2[k];
		k++;
	}
	return merged;
}



char* reverse(char* a) {
	int size = 0;
	while (1) {
		if (a[size] == '\0') {
			break;
		}
		size++;

	}
	//cout << "size is " << size << endl;
	int j = size - 1;
	char* reverse = new char[size];
	for (int k = 0; k < size; k++) {
		reverse[k] = a[j];
		j--;
	}
	return reverse;
}


void Populateplanets(char** Arr, int size)
{
	char** newArray = new char* [size];
	for (int i = 0; i < size; i++) {
		newArray[i] = new char[size];
	}

	newArray = Arr;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cout << *((newArray + i) + j);

}



int countEven(int* Arr, int size) {
	int num = 0;
	for (int i = 0; i < size; i++) {
		if (Arr[i] % 2 == 0) {
			num++;
		}
	}
	return num;
}



bool compare(char* arr, char a) {

	if (*arr == a) {
		return true;
	}
	else
		return false;

}



//--------------------------------------------------Question 6 --------------------------------------------------

int find(int array[], int length, int target) {
	if (array[length - 1] == target)
	{
		return length - 1;
	}
	else if (length - 1 != 0)
	{
		find(array, length - 1, target);
	}
	else
	{
		return -1;
	}
}

bool isPalindrome(char str[], int size) {
	if (size - 1 != strlen(str) / 2)
	{
		isPalindrome(str, size - 1);
	}
	if (str[size - 1] == str[strlen(str) - (size)])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PrintPattern1(int n, int k, char ch1, char ch2) {
	if (n <= k)
	{
		cout << n;
		for (int i = 0; i < n; i++)
		{
			cout << ch1;
		}
		PrintPattern1(n + 1, k, ch1, ch2);
	}
	if (n > 2)
	{
		cout << n - 2;
		for (int i = 0; i < n - 2; i++)
		{
			cout << ch2;
		}
	}
}

void PrintSpaces(int value, char ch)
{
	if (value > 0)
	{
		cout << " ";
		PrintSpaces(value - 1, ch);
	}
}

void PrintCh(int value, char ch)
{
	if (value > 0)
	{
		cout << ch;
		PrintSpaces(value - 1, ch);
	}
}

void PrintPattern(int value, char ch) {
	if (value > 0)
	{
		PrintSpaces(value, ch);
		cout << endl;

		PrintPattern(value - 1, ch);
	}
}

void replace(char* s1, char ch1, char ch2) {
	if (*s1 == '\0')
	{
		return;
	}
	if (*s1 == ch1)
	{
		*s1 = ch2;
	}
	replace(s1 + 1, ch1, ch2);
}
