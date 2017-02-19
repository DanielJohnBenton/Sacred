#include <iostream>
#include <vector>
#include <map>
#include <fstream>

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
	
	const string fourteenCommandments[14] = {
		"()", ")(", "((", "))", "(", ")", "(((", ")))", "((()", "()))", "((()))", "((()()))", "())(", "()()"
	};
	
	vector<string> sacredCommandments;
	
	unsigned long nCommandments = commandments.size();
	
	for(unsigned long i = 0; i < nCommandments; i++)
	{
		bool isSacred = false;
		for(unsigned short allowed = 0; allowed < 14; allowed++)
		{
			if(commandments[i] == fourteenCommandments[allowed])
			{
				isSacred = true;
				break;
			}
		}
		
		if(isSacred)
		{
			sacredCommandments.push_back(commandments[i]);
		}
	}
	
	return sacredCommandments;
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
unsigned short Sacred(string sermon, vector<signed long> &chapter)
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
		
		return 1;
	}
	
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
				return 1;
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
					
					/* check should not be necessary since loop closing is tested above
					if(i >= nCommandments)
					{
						Error("Went beyond code.");
						return 1;
					}*/
					
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
					
					if(code.at(
				}
			}
		}
		else if(commandment == "(((") // output char
		{
		}
		else if(commandment == ")))") // input char
		{
		}
		else if(commandment == "((()") // output integer
		{
		}
		else if(commandment == "()))") // input integer
		{
		}
		else if(commandment == "((()))") // evaluate
		{
			
		}
		else if(commandment == "((()()))") // evaluate ad finitum
		{
		}
	}
	
	return 0;
}

int main(int argc, char* argv[])
{
	vector<signed long> chapter;
	chapter.push_back(0);
	
	Sacred("())( () () () () () () () () ( )) () () () () ( )) () () )) () () () )) () () () )) () (( (( (( (( )( ) )) () )) () )) )( )) )) () ( (( ) (( )( ) )) )) ((( )) )( )( )( ((( () () () () () () () ((( ((( () () () ((( )) )) ((( (( )( ((( (( ((( () () () ((( )( )( )( )( )( )( ((( )( )( )( )( )( )( )( )( ((( )) )) () ((( )) () () (((, chapter);
}






