//
//  main.cpp
//  Happy Password
//
//  Created by Alex Crist on 2/21/14.
//  Copyright (c) 2014 WH External Projects. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

bool IsLeft(string testword, int index)
{
    if (testword.at(index) == 'q' || testword.at(index) == 'a' || testword.at(index) == 'z' || testword.at(index) == 'w' || testword.at(index) == 's' || testword.at(index) == 'x' || testword.at(index) == 'e' || testword.at(index) == 'd' || testword.at(index) == 'c' || testword.at(index) == 'r' || testword.at(index) == 'f' || testword.at(index) == 'v' || testword.at(index) == 't' || testword.at(index) == 'g' || testword.at(index) == 'b')
    {
        if ( index == testword.length()-1 )
            return true;
        else if (IsLeft(testword, index+1))
            return true;
        else
            return false;
    }
    
    else
        return false;
}

bool IsRight(string testword, int index)
{
    if (testword.at(index) == 'y' || testword.at(index) == 'h' || testword.at(index) == 'n' || testword.at(index) == 'u' || testword.at(index) == 'j' || testword.at(index) == 'm' || testword.at(index) == 'i' || testword.at(index) == 'k' || testword.at(index) == 'o' || testword.at(index) == 'l' || testword.at(index) == 'p')
    {
        if ( index == testword.length()-1 )
            return true;
        else if ( IsRight(testword, index+1) )
            return true;
        else
            return false;
    }
    
    else
        return false;
}




int main(int argc, const char * argv[])
{
    const int MAX = 50;
    const int MIN = 5;
    
    int words = 0;
    int lefts = 0;
    int rights = 0;
    
    ifstream fin( argv[1] );
    ofstream rightfout( argv[2] );
    ofstream leftfout( argv[3] );
    
    if(!fin.is_open())
	{
		cout << "File open failed." << endl;
		return -1;
	}
	
	
    string word;
    while (fin >> word)
    {
        if( word.length() > MAX || word.length() < MIN) //if too short or too long, continue to next word
            continue;
        
        else if ( IsLeft(word, 0) )
        {
            leftfout << word << endl;
            lefts++;
        }
        
        else if ( IsRight(word, 0))
        {
            rightfout << word << endl;
            rights++;
        }

        words++;
    }
    
    cout << "\t\t\t\t\t\tWords\t  %Total" << endl;
    cout << "Total Words: \t\t\t" << words << endl;
    cout << "Left-Handed Words: \t\t" << lefts << "\t\t" << (double)lefts/(double)words*100 << "%" << endl;
    cout << "Right-Handed Words:\t\t" << rights << "\t\t    " << (double)rights/(double)words*100 << "%" << endl;
    cout << "Both-Handed Words: \t\t" << words-(lefts+rights) << "\t\t" << (double)(words-(lefts+rights))/(double)words*100 << "%" << endl;
    
	return 0;
}