#pragma once

#include <iostream>
#include <algorithm> // for std::erase_if
#include <cctype>    // for std::ispunct


using namespace std;
namespace StringLibrary
{


    enum enWhatToCount
    {
        smallLetter = 0,
        capitalLetter = 1,
        all = 2,
        punctuation = 3
    };

    string printTheWordAndSmallEachFirstLetter(string word)
    {
        bool isFirstLetter = true;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] != ' ' && isFirstLetter)
            {
                word[i] = tolower(word[i]);
            }
            isFirstLetter = (word[i] == ' ' ? true : false); // ternary operator
        }

        return word;
    }

    string readWordsFromUser()
    {
        cout << "Entet Your string? ";
        string word;
        getline(cin, word);

        return word;
    }

    string CapitlizeWord(string word)
    {
        for (int i = 0; i < word.length(); i++)
        {
            word[i] = toupper(word[i]);
        }

        return word;
    }

    string LowerCaseLetter(string word)
    {
        for (int i = 0; i < word.length(); i++)
        {
            word[i] = tolower(word[i]);
        }

        return word;
    }

    string printTheWordAndCapitalizeEachFirstLetter(string word)
    {
        bool isFirstLetter = true;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] != ' ' && isFirstLetter)
            {
                word[i] = toupper(word[i]);
            }
            isFirstLetter = (word[i] == ' ' ? true : false); // ternary operator
        }

        return word;
    }

    char invertLetterCase(char c1)
    {
        return isupper(c1) ? tolower(c1) : toupper(c1);
    }

    string invertLetterCase(string s1)
    {
        for (short i = 0; i < s1.length(); i++)
        {
            s1[i] = invertLetterCase(s1[i]);
        }

        return s1;
    }

    int stringLength(string s1)
    {
        return s1.length();
    }

    int countCapitalLetters(string s1)
    {
        int countCapitalLetters = 0;

        for (int i = 0; i < s1.length(); i++)
        {
            if (isupper(s1[i]))
            {
                countCapitalLetters++;
            }
        }

        return countCapitalLetters;
    }

    int countSmallLetters(string s1)
    {
        int countSmallLetters = 0;

        for (int i = 0; i < s1.length(); i++)
        {
            if (islower(s1[i]))
            {
                countSmallLetters++;
            }
        }

        return countSmallLetters;
    }

    // generic function to count the small and capital letters another solution to the previous two functions

    short countLetters(string s1, enWhatToCount whatToCount = enWhatToCount::all) // if no parameter pass for the what to count enum the default is count all the letters weather capital or small
    {

        if (whatToCount == enWhatToCount::all)
        {
            return s1.length();
        }

        int counter = 0;

        for (int i = 0; i < s1.length(); i++)
        {

            if (whatToCount == enWhatToCount::capitalLetter && isupper(s1[i]))
            {
                counter++;
            }

            else if (whatToCount == enWhatToCount::smallLetter && islower(s1[i]))
            {
                counter++;
            }

            else if (whatToCount == enWhatToCount::punctuation && ispunct(s1[i]))
            {
                counter++;
            }
        }
        return counter;
    }

    short countCharachterFrequency(string s1, char c)
    {
        short counter = 0;

        for (short i = 0; i < s1.length(); i++)
        {
            // this type of iteration called Linear Search
            if (s1[i] == c)
            {
                counter++;
            }
        }
        if (counter == 0)
            return -1;
        return counter;
    }

    short countCharachterFrequencyIgnoringCaseSensetive(string s1, char c, bool matchCase = true)
    {
        short counter = 0;
        for (short i = 0; i < s1.length(); i++)
        {
            // this type of iteration called Linear Search
            if (matchCase)
            {
                if (s1[i] == c)
                {
                    counter++;
                }
            }
            else
            {
                if (tolower(s1[i]) == tolower(c))
                {
                    counter++;
                }
            }
        }
        return counter;
    }

    bool checkIsVowel(char c)
    {
        return (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u');
    }

    short countVowel(string s1)
    {
        int counter = 0;

        for (short i = 0; i < s1.length(); i++)
        {
            if (checkIsVowel(s1[i]))
            {
                counter++;
            }
        }
        return counter;
    }

    void printVowelsInString(string s1)
    {

        cout << "All vowels: ";
        for (short i = 0; i < s1.length(); i++)
        {
            if (checkIsVowel(s1[i]))
            {
                cout << s1[i] << " ";
            }
        }
    }

    short countEachWordInString(string s1)
    {
        short counter = 0;
        string delm = " "; // delimiter
        short pos = 0;

        string sWord = "";

        while ((pos = s1.find(delm)) != string::npos)
        {
            sWord = s1.substr(0, pos);

            if (sWord != "")
            {
                counter++;
            }
            s1.erase(0, pos + delm.length());
        }

        if (s1 != "")
        {
            counter++;
        }
        return counter;
    }

    vector<string> splitString(string s1, string delm)
    {
        short pos = 0;
        vector<string> vWords;

        string sWord = "";

        while((pos = s1.find(delm)) != string::npos)
        {
            sWord = s1.substr(0, pos);

            if(sWord != "")
            {
                vWords.push_back(sWord);
            }

            s1.erase(0, pos + delm.length());
        }

        if(s1 != "")
        {
            vWords.push_back(s1);
        }

        return vWords;
    }


    string trimLeft(string s1)
    {  
        string trimedVersion = "";
        for (short i = 0; i < s1.length(); i++)
        {
            if(s1[i] == ' ')
            {
                continue;
            }
            else
            {
                trimedVersion = s1.substr(i, s1.length() - i); break;
            }

        }
        return trimedVersion;
    }

    string trimRight(string s1)
    {  
        string trimedVersion = "";
        for (short i = s1.length() - 1; i >= 0; i--)
        {
            if(s1[i] == ' ')
            {
                continue;
            }
            else
            {
                trimedVersion = s1.substr(0, i + 1); break;
            }

        }
        return trimedVersion;
    }

    string trim(string s1)
    {
        string trim = trimRight(trimLeft(s1));

        return trim;
    }

    string joinString(vector<string> vString, string delm)
    {
        string s1 = "";

        for(short i = 0; i < vString.size(); i++)
        {
            s1 += vString[i] + delm;
        }

        return s1.substr(0, s1.length() - delm.length()); // to delete the last delmiters
    }

    string joinString(string arr[], int length , string delm)
    {
        string s1 = "";

        for(short i = 0; i < length; i++)
        {
            s1 += arr[i] + delm;
        }

        return s1.substr(0, s1.length() - delm.length()); // to delete the last three delmiter
    }

    string reverseWord(vector<string> vWords)
    {
        vector<string> vReversedWords;
        vector<string>::iterator it = vWords.end(); // Declaration: ContainerType::iterator it;.

        while (it != vWords.begin())
        {
            it--;
            vReversedWords.push_back(*it);
        }
        

        return joinString(vReversedWords, " ");
    }

    string removePunction(string s1)
    {
        string s2 = "";
        for (short i = 0; i < s1.length(); i++)
        {
            if (! ispunct(s1[i]))
            {
                s2 += s1[i];
            }
        }

        return s2;
        
    }

    string replaceWord(string original, string wordWillBeReplaced, string newWord)
    {
        short pos = original.find(wordWillBeReplaced);

        while (pos != string::npos)
        {
            original.replace(pos, wordWillBeReplaced.length(), newWord);
            pos = original.find(wordWillBeReplaced);
        }
        return original;
    }

     string replaceWordCustom(string original, string wordWillBeReplaced, string newWord, bool matchCase = true)
    {
        vector<string> vWords = splitString(original, " ");

        
        for (string &word : vWords)
        {
            if(matchCase)
            {
                if(word == wordWillBeReplaced)
                {
                    word = newWord;
                }
            } else {
                if(LowerCaseLetter(word) == LowerCaseLetter(wordWillBeReplaced))
                {
                    word = newWord;
                }
            }
           
        }
        return joinString(vWords, " ");
    }


}
