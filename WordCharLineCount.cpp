/*********************** Sentence Censoring  ************************
 Name:  Chad Parnin
 Date:  Feb 7, 2014
 Homework#:  HW 2
 Source File:  Hw2.cpp
 Action:  A program that repeatedly asks the user for a sentence,
 then replaces all occurances of the word 'hell' with 'heck'.
 Maintains case sensitivity and all punctuations.
 ********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

void GetSentence(char Str[]);
void CopyString(char StrCopy[], char Str[]);
void MakeUpperCase(char StrCopy[]);
void InsertBlankStartEnd(char StrCopy[]);
void ReplacePuncWithBlanks(char StrCopy[]);
void SearchAndReplaceHell(char StrCopy[]);
void DeleteBlankStartEnd(char StrCopy[]);
void OriginalCaseAndPunc(char Str[], char StrCopy[]);

const int MAX_LENGTH = 100;

int main()
{
	char Str[MAX_LENGTH] = " ";
	char StrCopy[MAX_LENGTH] = " ";
    
	GetSentence(Str);
    
	while (Str[0] != '0')
	{
		CopyString(StrCopy, Str);
		MakeUpperCase(StrCopy);
		InsertBlankStartEnd(StrCopy);
		ReplacePuncWithBlanks(StrCopy);
		SearchAndReplaceHell(StrCopy);
		DeleteBlankStartEnd(StrCopy);
		OriginalCaseAndPunc(Str, StrCopy);
		GetSentence(Str);
	}
    
	cout << "Goodbye..." << endl;
    
	return 0;
}

/***********************  Get Sentence  **********************************
 Action:  Gets a sentence from user
 Parameters:
 IN:  Str, which points to array which will have original sentence
 MAX_LENGTH, max size of array
 OUT: Str
 Returns: None
 Precondition:  Str points to a character array
 ************************************************************************/

void GetSentence(char Str[])
{
	cout << "Enter a sentence ";
	cout << "(Enter 0 to quit) => ";
	cin.getline(Str, MAX_LENGTH);
	if (Str[0] == '0')
		return;
	else
		cout << "Original  :  " << "\"" << Str << "\"" << endl;
}

/**************** Make Copy Of Original Sentence ************************
 Action:  Makes a copy of original sentence
 Parameters:
 IN:  Str, which points to array which will have original sentence
 StrCopy, which points to copy of original
 OUT: Str
 StrCopy
 Returns: None
 Precondition:  Str and StrCopy point to a character array
 ************************************************************************/

void CopyString(char StrCopy[], char Str[])
{
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		StrCopy[i] = Str[i];
	}
}

/******************  Make All Uppercase ********************************
 Action:  Change to all uppercase
 Parameters:
 IN:  StrCopy, which points to copy of original
 OUT: StrCopy
 Returns: None
 Precondition:  StrCopy points to a character array
 ************************************************************************/

void MakeUpperCase(char StrCopy[])
{
	for (int i = 0; i < MAX_LENGTH; i++)
		StrCopy[i] = toupper(StrCopy[i]);
}

/****************  Insert Blank at Beginning and End ********************
 Action:  Insert blank space at beginning and end of StrCopy to test
 if "hell" starts or ends a sentence
 Parameters:
 IN:  StrCopy, which points to copy of original
 OUT: StrCopy
 Returns: None
 Precondition:  StrCopy points to a character array
 ************************************************************************/

void InsertBlankStartEnd(char StrCopy[])
{
	int i = 0;
	for (i = 0; StrCopy[i]; ++i);  // find null
	StrCopy[i] = ' ';  // insert blank where null was
	for ( ; i >= 0; --i)
		StrCopy[i + 1] = StrCopy[i];
	StrCopy[i + 1] = ' ';
}

/****************  Replace Punctuation with Blanks **********************
 Action:  Replaces all punctuation marks with blanks
 Parameters:
 IN:  StrCopy, which points to copy of original
 OUT: StrCopy
 Returns: None
 Precondition:  StrCopy points to a character array
 ************************************************************************/

void ReplacePuncWithBlanks(char StrCopy[])
{
	for (int i = 0; i< MAX_LENGTH; ++i)
		if (ispunct(StrCopy[i]))
			StrCopy[i] = ' ';
}

/****************  Replaces 'Hell' With 'Heck' *************************
 Action:  Replaces 'hell' with 'heck'
 Parameters:
 IN:  StrCopy, which points to copy of original
 OUT: StrCopy
 Returns: None
 Precondition:  StrCopy points to a character array
 ************************************************************************/

void SearchAndReplaceHell(char StrCopy[])
{
	for (int i = 0; i < MAX_LENGTH; ++i)
	{
		if (isblank(StrCopy[i]))
			if (StrCopy[i + 1] == 'H')
				if (StrCopy[i + 2] == 'E')
					if (StrCopy[i + 3] == 'L')
						if (StrCopy[i + 4] == 'L')
							if (isblank(StrCopy[i + 5]))
							{
								StrCopy[i + 3] = 'C';
								StrCopy[i + 4] = 'K';
							}
	}
}

/****************  Delete Blank at Beginning and End ********************
 Action:  Removes the leading and trailing spaces
 Parameters:
 IN:  StrCopy, which points to copy of original
 OUT: StrCopy
 Returns: None
 Precondition:  StrCopy points to a character array
 ************************************************************************/

void DeleteBlankStartEnd(char StrCopy[])
{
	int i = 0;
	for (i = 0; StrCopy[i]; ++i)  // remove leading space
		StrCopy[i] = StrCopy[i + 1];
    
	for (i = 0; i < MAX_LENGTH; ++i)
		if ((isspace(StrCopy[i])) && (StrCopy[i + 1] == '\0'))
			StrCopy[i] = '\0';
}

/***********  Change to Original Case and Punctuations ******************
 Action:  Re-enters the original case sensitivity and punctuations
 Parameters:
 IN:  Str, which points to original sentence array
 StrCopy, which points to copy of original sentence array
 OUT: Str
 StrCopy
 Returns: None
 Precondition:  Str and StrCopy point to a character array
 ************************************************************************/

void OriginalCaseAndPunc(char Str[], char StrCopy[])
{
	for (int i = 0; i < MAX_LENGTH; ++i)
	{
		if (ispunct(Str[i]))
			StrCopy[i] = Str[i];
		if (islower(Str[i]))
			StrCopy[i] = tolower(StrCopy[i]);
	}
	cout << "Censored  :  " << "\"" << StrCopy << "\"" << endl;
	cout << setfill('-') << setw(75) << "-" << endl;
}