#include <gtest/gtest.h>
using namespace std;

#include<iostream>
using namespace std;

//--------------------------------------------------Question 1 --------------------------------------------------
TEST (bookSeats, T1) {

	int numOfRows = 9;
	char** bus = bookSeats(numOfRows); 
	
	// Select seats 1A, 2B, and 4C
	
    	char** testBus = new char*[numOfRows];

	for (int i = 0; i < numOfRows; i++)
		*(testBus+i) = new char[5];

	strcpy(*(testBus+0),"1XBCD");
	strcpy(*(testBus+1),"2AXCD");
	strcpy(*(testBus+2),"3ABCD");
	strcpy(*(testBus+3),"4ABXD");
	strcpy(*(testBus+4),"5ABCD");
	strcpy(*(testBus+5),"6ABCD");
	strcpy(*(testBus+6),"7ABCD");
	strcpy(*(testBus+7),"8ABCD");
	strcpy(*(testBus+8),"9ABCD");
	
	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < 5; j++) {
			EXPECT_EQ(testBus[i][j], bus[i][j]);
		}
	}
}

TEST (bookSeats, T2) {

	int numOfRows = 5;
	char** bus = bookSeats(numOfRows); 
	
	// Select seats 1A, 2B, 2C, 4D, and 5A
	
	char** testBus = new char*[numOfRows];

	for (int i = 0; i < numOfRows; i++)
		*(testBus+i) = new char[5];

	strcpy(*(testBus+0),"1XBCD");
	strcpy(*(testBus+1),"2AXXD");
	strcpy(*(testBus+2),"3ABCD");
	strcpy(*(testBus+3),"4ABCX");
	strcpy(*(testBus+4),"5XBCD");

	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < 5; j++) {
			EXPECT_EQ(testBus[i][j], bus[i][j]);
		}
	}
}


//-------------------------------------------------- Question 2A --------------------------------------------------

TEST (maxScore, T1) {

	int rows = 5, cols = 5;

	int** matrix = new int*[rows];

	for(int i = 0; i < rows; i++)
		matrix[i] = new int[cols];

	matrix[0][0] =	1;
	matrix[0][1] = 1;
	matrix[0][2] = -1;
	matrix[0][3] = 1;
	matrix[0][4] = 1;

	matrix[1][0] = 1;
	matrix[1][1] = 0;
	matrix[1][2] = 0;
	matrix[1][3] = -1;
	matrix[1][4] = 1;

	matrix[2][0] = 1;
	matrix[2][1] = 1;
	matrix[2][2] = 1;
	matrix[2][3] = 1;
	matrix[2][4] = -1;

	matrix[3][0] = -1;
	matrix[3][1] = -1;
	matrix[3][2] = 1;
	matrix[3][3] = 1;
	matrix[3][4] = 1;

	matrix[4][0] = 1;
	matrix[4][1] = 1;
	matrix[4][2] = -1;
	matrix[4][3] = -1;
	matrix[4][4] = 1;

	/*
		{ 1,  1, -1,  1,  1}
		{ 1,  0,  0, -1,  1}
		{ 1,  1,  1,  1, -1}
		{-1, -1,  1,  1,  1}
		{ 1,  1, -1, -1,  1}
	*/

	// Do not uncomment the above matrix!
	
	int score = maxScore(matrix, rows, cols);
	EXPECT_EQ(9, score);
   	
}

//-------------------------------------------------- Question 2B ---------------------------------------------------

TEST (minCost, T1) {

	int rows = 5, cols = 5;

	int** matrix = new int*[rows];

	for(int i = 0; i < rows; i++)
		matrix[i] = new int[cols];

	matrix[0][0] = 4;
	matrix[0][1] = 7;
	matrix[0][2] = 8;
	matrix[0][3] = 6;
	matrix[0][4] = 4;

	matrix[1][0] = 6;
	matrix[1][1] = 7;
	matrix[1][2] = 3;
	matrix[1][3] = 9;
	matrix[1][4] = 2;

	matrix[2][0] = 3;
	matrix[2][1] = 8;
	matrix[2][2] = 1;
	matrix[2][3] = 2;
	matrix[2][4] = 4;

	matrix[3][0] = 7;
	matrix[3][1] = 1;
	matrix[3][2] = 7;
	matrix[3][3] = 3;
	matrix[3][4] = 7;

	matrix[4][0] = 2;
	matrix[4][1] = 9;
	matrix[4][2] = 8;
	matrix[4][3] = 9;
	matrix[4][4] = 3;

	/*
		{4, 7, 8, 6, 4}
		{6, 7, 3, 9, 2}
		{3, 8, 1, 2, 4}
		{7, 1, 7, 3, 7}
		{2, 9, 8, 9, 3}
	*/

	// Do not uncomment the above matrix!
	
	int cost = minCost(matrix, rows, cols);
	EXPECT_EQ(36, cost);	
}

TEST (minCost, T2) {

	int rows = 5, cols = 5;

	int** matrix = new int*[rows];

	for(int i = 0; i < rows; i++)
		matrix[i] = new int[cols];

	matrix[0][0] = 1;
	matrix[0][1] = 7;
	matrix[0][2] = 3;
	matrix[0][3] = 4;
	matrix[0][4] = 5;

	matrix[1][0] = 6;
	matrix[1][1] = 7;
	matrix[1][2] = 8;
	matrix[1][3] = 9;
	matrix[1][4] = 0;

	matrix[2][0] = 9;
	matrix[2][1] = 2;
	matrix[2][2] = 7;
	matrix[2][3] = 6;
	matrix[2][4] = 4;

	matrix[3][0] = 4;
	matrix[3][1] = 3;
	matrix[3][2] = 2;
	matrix[3][3] = 5;
	matrix[3][4] = 0;

	matrix[4][0] = 1;
	matrix[4][1] = 2;
	matrix[4][2] = 3;
	matrix[4][3] = 4;
	matrix[4][4] = 5;

	/*
		{1, 7, 3, 4, 5}
		{6, 7, 8, 9, 0}
		{9, 2, 7, 6, 4}
		{4, 3, 2, 5, 0}
		{1, 2, 3, 4, 5}
	*/

	// Do not uncomment the above matrix!

	
	int cost = minCost(matrix, rows, cols);
	EXPECT_EQ(29, cost);	
}



//-------------------------------------------------- Question 3 --------------------------------------------------


TEST(Question1, First) {
	int candidates = 3;
	char** names = allocateNames(candidates);
	
	setNames(candidates, names, "a");
	setNames(candidates, names, "b");
	setNames(candidates, names, "c");

	
	EXPECT_EQ(strcmp( names[0], "a") , 0 );
	EXPECT_EQ(strcmp(names[1], "b"), 0);
	EXPECT_EQ(strcmp(names[2], "c"), 0);

}

TEST(Question1, Second) {
	int candidates = 3;
	int* votes = allocateVotes(candidates);
	char** names = allocateNames(candidates);
	setNames(candidates, names, "a");
	setNames(candidates, names, "b");
	setNames(candidates, names, "c");

	setVotes(candidates, names, "a", votes, 100);
	setVotes(candidates, names, "b", votes, 200);
	setVotes(candidates, names, "c", votes, 300);


	EXPECT_EQ(votes[0], 100);
	EXPECT_EQ(votes[1], 200);
	EXPECT_EQ(votes[2], 300);
}

TEST(Question1, Third) {
	int candidates = 3;
	int* votes = allocateVotes(candidates);
	char** names = allocateNames(candidates);
	setNames(candidates, names, "a");
	setNames(candidates, names, "b");
	setNames(candidates, names, "c");

	setVotes(candidates, names, "a", votes, 100);
	setVotes(candidates, names, "b", votes, 200);
	setVotes(candidates, names, "c", votes, 300);

	float percA = (100 / float(600)) * 100;
	float percB = (200 / float(600)) * 100;
	float percC = (300 / float(600)) * 100;

	float* percentages = allocatePercentages(candidates, votes);

	EXPECT_EQ(percentages[0], percA);
	EXPECT_EQ(percentages[1], percB);
	EXPECT_EQ(percentages[2], percC);

	int totalVotes = returnTotalVotes(candidates, votes);
	EXPECT_EQ(totalVotes, 600);

}



//--------------------------------------------------Question 4 --------------------------------------------------

TEST(calculateHistogram, T1) {
  
	int* result; 
	int marks[] = { 10,70 ,65,50,65,70,50,30,65,65,70,65,65};
	int *expectedResult = new int[71];
	for (int i = 0; i < 71; i++) {
		expectedResult[i] = 0;
	}
	expectedResult[10] = 1;
	expectedResult[70] = 3;
	expectedResult[65] = 6;
	expectedResult[50] = 2;
	expectedResult[30] = 1;
	calculateHistogram(marks, result,13);
	for (int i = 0; i < 71; i++) { 
		EXPECT_EQ(expectedResult[i], result[i]);
	}
}

TEST(calculateHistogram, T2) {

	int* result;
	int marks[] = { 25,70 ,55,5,55,70,5,3,55,55,70,55,55 };
	int* expectedResult = new int[71];
	for (int i = 0; i < 71; i++) {
		expectedResult[i] = 0;
	}
	expectedResult[25] = 1;
	expectedResult[70] = 3;
	expectedResult[55] = 6;
	expectedResult[5] = 2;
	expectedResult[3] = 1;
	calculateHistogram(marks, result,13);
	for (int i = 0; i < 71; i++) {
		EXPECT_EQ(expectedResult[i], result[i]);
	}
}


//--------------------------------------------------Question 5 --------------------------------------------------

TEST(maximum, First) {
	int* Arr = new int[5];
	Arr[0]=8;
	Arr[1]=6;
	Arr[2]=1;
	Arr[3]=4;
	Arr[4]=2;
	
	ASSERT_EQ(maximum(Arr,5),8);
}

TEST(maximum, Second) {
	int* Arr = new int[5];
	Arr[0]=8;
	Arr[1]=9;
	Arr[2]=1;
	Arr[3]=0;
	Arr[4]=2;
	
	ASSERT_EQ(maximum(Arr,5),9);
}

TEST(Swap, First) {
	int a = 1;
	int b = 2;
	swap(&a, &b);
	ASSERT_EQ(a, 2);
	ASSERT_EQ(b, 1);

}


TEST(Swap, Second) {
	int a = -11;
	int b = 22;
	
	swap(&a, &b);
	ASSERT_EQ(a, 22);
	ASSERT_EQ(b, -11);

}


TEST(merge, First) {
	int* Arr = new int[5];
	Arr[0]=8;
	Arr[1]=9;
	Arr[2]=1;
	Arr[3]=0;
	Arr[4]=2;
	
	int* Arr2 = new int[5];
	Arr2[0]=8;
	Arr2[1]=9;
	Arr2[2]=1;
	Arr2[3]=0;
	Arr2[4]=2;
	
	int *a=merge(Arr,Arr2,5,5);
	
	ASSERT_EQ(a[0],8);
	ASSERT_EQ(a[5],8);
	ASSERT_EQ(a[6],9);
}


TEST(merge, Second) {
	int* Arr = new int[5];
	Arr[0]=1;
	Arr[1]=2;
	Arr[2]=3;
	Arr[3]=4;
	Arr[4]=5;
	
	int* Arr2 = new int[5];
	Arr2[0]=6;
	Arr2[1]=7;
	Arr2[2]=8;
	Arr2[3]=9;
	Arr2[4]=10;
	
	int *a=merge(Arr,Arr2,5,5);
	
	ASSERT_EQ(a[0],1);
	ASSERT_EQ(a[5],6);
	ASSERT_EQ(a[6],7);
}



TEST(Reverse, First) {
	char* Arr = new char[6];
	Arr[0] = 'a';
	Arr[1] = 'i';
	Arr[2] = 'z';
	Arr[3] = 'a';
	Arr[4] = 'z';
	Arr[5] = '\0';

	char* New = reverse(Arr);

	ASSERT_EQ(New[0], 'z');
	ASSERT_EQ(New[1], 'a');

}

TEST(Reverse, Second) {
	char* Arr = new char[9];
	Arr[0] = 'F';
	Arr[1] = 'o';
	Arr[2] = 'o';
	Arr[3] = 't';
	Arr[4] = 'b';
	Arr[5] = 'a';
	Arr[6] = 'l';
	Arr[7] = 'l';
	Arr[8] = '\0';

	char* New = reverse(Arr);

	ASSERT_EQ(New[0], 'l');
	ASSERT_EQ(New[7], 'F');

}


TEST(Even, First) {
	int* Arr = new int[5];
	Arr[0]=1;
	Arr[1]=2;
	Arr[2]=3;
	Arr[3]=4;
	Arr[4]=5;
	
	
   ASSERT_EQ(countEven(Arr,5),2);
	
}

TEST(Even, Second) {
	int* Arr = new int[5];
	Arr[0]=2;
	Arr[1]=2;
	Arr[2]=2;
	Arr[3]=2;
	Arr[4]=2;
	
	
   ASSERT_EQ(countEven(Arr,5),5);
	
}

TEST(compare, First) {
	char* Arr = new char[5];
		Arr[0]='a';
		Arr[1]='i';
		Arr[2]='z';
		Arr[3]='a';
		Arr[4]='z';
	
	
   ASSERT_EQ(compare(Arr,'l'),0);
	
}


TEST(Compare, Second) {
	char* Arr = new char[5];
		Arr[0]='a';
		Arr[1]='i';
		Arr[2]='z';
		Arr[3]='a';
		Arr[4]='z';
	
	
   ASSERT_EQ(compare(Arr,'a'),1);
	
}


//--------------------------------------------------Question 6 --------------------------------------------------


TEST(find, found) {
  
      int arr[]={2, 6, 1, 9, 4, 2, 0};
      int length=7;
      int target=9;

      EXPECT_EQ(3, find(arr, length, target));

 
}

TEST(find, notFound) {
  
      int arr[]={2, 6, 1, 9, 4, 2, 0};
      int length=7;
      int target=7;

      EXPECT_EQ(-1, find(arr, length, target));
   
}


TEST(isPalindrome, yes) {

      char str[]="adsda\0";
      int size=5;

      EXPECT_TRUE(isPalindrome(str, size));
  
}

TEST(isPalindrome, no) {
 
      char str[]="adsdaf\0";
      int size=6;

      EXPECT_FALSE(isPalindrome(str, size));
 
}


TEST(replace, two) {
 
      char* s1=new char[9]{'a', 's', 'd', 'f', 'a', 's', 'd', 'f', '\0'};
      char* s2=new char[9]{'e', 's', 'd', 'f', 'e', 's', 'd', 'f', '\0'};
      replace(s1, 'a', 'e');
      bool cmp=!strcmp(s1, s2);
      EXPECT_TRUE(cmp);
  
}

TEST(replace, three) {
   
      char *s1=new char[19]{'J','i','m',' ','h','a','s',' ','a',' ','p','a','s','s','p','o','r','t','\0'};
      char *s2=new char[19]{'J','i','m',' ','h','i','s',' ','i',' ','p','i','s','s','p','o','r','t','\0'};
      replace(s1, 'a', 'i');
      bool cmp=!strcmp(s1, s2);
      EXPECT_TRUE(cmp);
  
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

