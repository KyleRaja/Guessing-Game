#include<iostream>
using namespace std;

//Enter your 4 functions here
void hilo(int n);
void GuessNumber(int start, int stop);
void mysort(int nums[], int totalNum);
void sorthelp(int a[], int start, int n);

// hilo Method
void hilo(int n)
{
	cout << "Think of a number between 1 and " << n << endl;
	cout << "I will try and guess it with your help.\n";
	GuessNumber(1, n);
}

// GuessNumber Method
void GuessNumber(int start, int stop)
{
	int guess = (start + stop) / 2;
	// Base cases , to stop recursion
	if (guess == start + 1 && guess == stop - 1)
	{
		cout << "Your number is " << guess << endl;
	}
	else if (start >= stop - 1)
		cout << "You cheated!" << endl;
	else
	{
		char myValue;
		cout << "Is it " << guess << " (l,y,h) ? ";
		cin >> myValue;
		if (myValue == 'h')
		{
			stop = guess;
			GuessNumber(start, stop);
		}
		else if (myValue == 'l')
		{
			start = guess;
			GuessNumber(start, stop);
		}
		else
			cout << "Your number is " << guess << endl;
	}
}

// Sort Method
void mysort(int nums[], int totalNum){
	int start = 1;
	sorthelp(nums, start, totalNum);
}

// Sort Helper Method
void sorthelp(int a[], int start, int n)
{
	// Base case to stop recursion
	if (start == n)
		return;

	for (int i = 0; i < n - 1; i++) 
		if (a[i] > a[i + 1])
			swap(a[i], a[i + 1]);
	
	sorthelp(a, start, n - start);
}

int main()
{
	// Guess a number between 1 and 100
	// Your hilo() will call a slightly modified GuessNumber
	hilo(100);

	//Sort an array
	//Your mySort() will call a recursive helper function.
	int a[] = { 5,4,3,2,1 };
	const int n = 5;
	mysort(a, n);
	cout << "Sorted result:\n";

	for (int n : a)
		cout << n << endl;
	cout << endl;

	system("pause");
	return 0;
}

