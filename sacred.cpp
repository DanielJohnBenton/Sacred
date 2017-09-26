#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

// Set to true for debug mode
#define PRAYINGFORMIRACLES true

using namespace std;

void Confess(string message)
{
	cout <<"Error: "<< message << endl;
}

string Sanctify(string sermon)
{
	string sacrosanct = "";
	
	bool spaced = true;
	
	signed long lSermon = sermon.length();
	
	for(signed long i = 0; i < lSermon; i++)
	{
		char c = sermon.at(i);
		
		switch(c)
		{
			case '(':
			case ')':
			{
				sacrosanct += c;
				
				spaced = false;
				
				break;
			}
			
			case ' ':
			case '\t':
			case '\n':
			case '\r':
			{
				if(!spaced)
				{
					sacrosanct +=' ';
					
					spaced = true;
				}
				
				break;
			}
			
			default:
			{
				break;
			}
		}
	}
	
	return sacrosanct;
}

vector<string> Bless(string sermon)
{
	unsigned long lSermon = sermon.length();
	
	vector<string> commandments;
	commandments.push_back("");
	
	unsigned long chapter = 0;
	
	for(unsigned long i = 0; i < lSermon; i++)
	{
		char c = sermon.at(i);
		
		if(c == '(' || c == ')')
		{
			commandments[chapter] += c;
		}
		else if(c == ' ')
		{
			commandments.push_back("");
			chapter++;
		}
	}
	
	return commandments;
}

/*
	()	Increments the current byte.
	)(	Decrements the current byte.
	((	Go left in the data strip.
	))	Go right in the data strip.
	(	Jump past the matching ) if the byte is zero.
	)	Jump back to the matching ( if the byte is non-zero.
	(((	Outputs the current byte as an ASCII character.
	)))	Takes a single-character input as an ASCII character.
	((()	Takes a numeric input.
	()))	Outputs the byte as a number.
	((()))	Converts the data strip into characters and evaluates them as if they were code.
	((()()))	Converts the data strip into characters and evaluates them as if they were code. Places this command at the end of the program to evaluate again the strip ad infinitum.
*/
string Sacred(string sermon)
{
	vector<string> commandments = Bless(Sanctify(sermon));
	signed long nCommandments = commandments.size();
	
	map< unsigned int, unsigned int > loops;
	signed int loop = 0;
	
	for(signed long i = 0; i < nCommandments; i++)
	{
		if(commandments[i] == "(")
		{
			loop++;
			
			loops[i] = loop;
		}
		else if(commandments[i] == ")")
		{
			loop--;
			
			loops[i] = loop;
		}
	}
	
	if(loop != 0)
	{
		string sins = "Unopened or unclosed loop detected. Commands:\n";
		
		for(signed long i = 0; i < nCommandments; i++)
		{
			sins +=" "+ commandments[i];
		}
		
		Confess(sins);
		
		return "";
	}
	
	vector<signed long> chapter;
	chapter.push_back(0);
	signed long verse = 0;
	
	for(signed long i = 0; i < nCommandments; i++)
	{
		string commandment = commandments[i];
		
		if(commandment == "()") // increment
		{
			chapter[verse]++;
		}
		else if(commandment == ")(") // decrement
		{
			chapter[verse]--;
		}
		else if(commandment == "((") // move left
		{
			verse--;
			
			if(verse < 0)
			{
				Confess("Cannot point to a position before 0.");
				return "";
			}
		}
		else if(commandment == "))") // move right
		{
			verse++;
			
			if(verse >= chapter.size())
			{
				chapter.push_back(0);
			}
		}
		else if(commandment == "(") // start loop
		{
			if(chapter[verse] == 0)
			{
				unsigned int targetLoopLevel = loops[verse] - 1;
				unsigned int xLoop = loops[verse];
				
				while(xLoop != targetLoopLevel)
				{
					i++;
					
					if(commandments[i] == "(")
					{
						xLoop++;
					}
					else if(commandments[i] == ")")
					{
						xLoop--;
					}
				}
			}
		}
		else if(commandment == ")") // end loop
		{
			if(chapter[verse] != 0)
			{
				unsigned int targetLoopLevel = loops[verse] + 1;
				unsigned int xLoop = loops[verse];
				
				while(xLoop != targetLoopLevel)
				{
					i--;
					
					if(commandments[i] == "(")
					{
						xLoop++;
					}
					else if(commandments[i] == ")")
					{
						xLoop--;
					}
				}
			}
		}
		else if(commandment == "(((") // output char
		{
			cout << (char)chapter[verse];
		}
		else if(commandment == ")))") // input char
		{
			string input = "";
			
			do
			{
				getline(cin, input);
			} while(input.length() == 0);
			
			chapter[verse] = (signed long)input.at(0);
		}
		else if(commandment == "()))") // output integer
		{
			cout << chapter[verse];
		}
		else if(commandment == "((()") // input integer
		{
			string input = "";
			
			const char allowed[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-'};
			bool validInteger = false;
			
			do
			{
				getline(cin, input);
				
				unsigned long l = input.length();
				for(unsigned long iInput = 0; iInput < l; iInput++)
				{
					char inputC = input.at(iInput);
					
					bool isAllowed = false;
					
					for(short iAllowed = 0; iAllowed < 11; iAllowed++)
					{
						if(inputC == allowed[iAllowed])
						{
							isAllowed = true;
							break;
						}
					}
					
					if(!isAllowed)
					{
						validInteger = false;
						break;
					}
					else
					{
						validInteger = true;
					}
				}
			} while(!validInteger);
			
			// Compiler bug workaround http://stackoverflow.com/a/20770206
			chapter[verse] = strtol(input.c_str(), 0, 10);
		}
		else if(commandment == "((()))" || commandment == "((()()))") // evaluate memory as Sacred
		{
			string code = "";
			
			signed long nChapter = chapter.size();
			for(signed long iChapter = 0; iChapter < nChapter; iChapter++)
			{
				code += (char)chapter[iChapter];
			}
			
			if(commandment == "((()()))") // eternally evaluate memory as Sacred
			{
				code +=" ((()()))";
			}
			
			return code;
		}
	}
	
	return "";
}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cout <<"Please specify a file."<< endl;
		cout <<"Usage: .\\sacred FILENAME.sacred"<< endl;
		
		return 0;
	}
	
	ifstream scroll(argv[1]);
	
	if(!scroll.good())
	{
		scroll.close();
		
		cout <<"File '"<< argv[1] <<"' not found."<< endl;
		
		return 0;
	}
	
	string code = "";
	string line = "";
	int nLines = 0;
	
	while(getline(scroll, line))
	{
		nLines++;
		
		code += ((nLines > 1) ? "\n"+ line : line);
	}
	
	scroll.close();
	
	while(code != "")
	{
		code = Sacred(code);
	}
	
	cout << endl;
	
	return 0;
}
