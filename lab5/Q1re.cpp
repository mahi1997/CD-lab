#define TRUE 1
#define FALSE 0
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<string>
using namespace std;

map<string, vector<string> >rules;
vector<string> nonTerminals;
set<string> terminals;
map<string, set<string> >firstSet;
map<string, set<string> >followSet;
int letter = 16;
string getString(char x)
{
    
    string s(1, x);
 
    return s;   
}
void findFirstSets();
bool produceEpsilon(string);
bool isNonTerminal(string);
void findFollowSets();
void printGrammar();

vector<string> split(string, char, vector<string>&);

int main()
{
	ifstream infile;
	string rule;
	
	string left, right;

	vector<string>::iterator it;

	infile.open("Input.txt", ifstream::in);

	while(getline(infile, rule))
	{
		//cout << rule << endl;
		int i;
		i = 0;
		while(rule[i] != ':')
		{
			left = left + rule[i];
			i++;
		}
		i++;
		while(i != rule.length())
		{
			right = right + rule[i];
			i++;
		}		
		//cout << left << endl;
		//cout << right << endl;				
		
		rules[left].push_back(right);

		it = find(nonTerminals.begin(), nonTerminals.end(), left);
		if(it == nonTerminals.end())
			nonTerminals.push_back(left);

		left="";
		right="";
		
	}
	infile.close();

	cout << "Original Grammar-->" << endl;
	printGrammar();
	//cout << nonTerminals.size() << endl; 
	//cout << rules.size() << endl;
	cout << "---------------------------------" << endl ;

	
	
	findFirstSets();
	findFollowSets();

	cout << "--------------------------------" << endl ;

	string parsingTable[nonTerminals.size()][terminals.size() + 1];
	

	int i, j;
	set<string>::iterator iter;
	vector<string> terminals_temp;
    cout<<"non terminals are.."<<endl;
	for(i = 0; i < nonTerminals.size(); i++)
		cout << i << "-->" << nonTerminals[i] << endl;

	cout<<"terminals are.."<<endl;
	for(j = 0, iter = terminals.begin(); iter !=  terminals.end(); j++, iter++)
	{	
		terminals_temp.push_back(*iter);
		cout << j << "-->" << *iter << endl ;
	}

	terminals_temp.push_back("$");

	cout << "--------------------------------" << endl ;
	cout << "Parsing Table" << endl << endl;

	for(i = 0; i < nonTerminals.size(); i++)
	{
		for(j = 0; j < terminals_temp.size(); j++)
			parsingTable[i][j] = "";
	}	

	for(i = 0; i < nonTerminals.size(); i++)
	{
		for(it = rules[nonTerminals[i]].begin(); it != rules[nonTerminals[i]].end(); it++)
		{
			//cout << "Rule-->" << nonTerminals[i] << ":" << *it << endl;
			vector<string> temp;
			vector<string>::iterator x;
			split(*it, ' ', temp);
			set<string>::iterator it_s;
			for(x = temp.begin(); x != temp.end(); x++)
			{
				//cout << *x << endl;
				for(it_s = firstSet[*x].begin(); it_s != firstSet[*x].end(); it_s++)
				{
					if(*it_s != "#")  //checking for non epsilon production
					{
						for(j = 0; j < terminals_temp.size(); j++)
						{
							if(terminals_temp[j] == *it_s)
								//parsingTable[i][j].push_back(*it);
							{
								if(parsingTable[i][j] == "")
								{
									//cout << "Inserted " << *it << " " << nonTerminals[i] << " " << terminals_temp[j] << endl;
									parsingTable[i][j] = *it;
								}
								else
								{
									//cout << "Returned" << endl;
									cout << "Grammar not LL(1)" << endl;
									exit(1);
								}
							}
						}					
					}
				}

				if(firstSet[*x].find("#") == firstSet[*x].end())
				{
					//cout << "Break! " << *x << endl;
					break;
				}
			}			

			for(x = temp.begin(); x != temp.end(); x++)
			{

				if(firstSet[*x].find("#") == firstSet[*x].end())
				{
					//cout << "Broken! " << *x << endl;
					break;
				}
			}

			if(x == temp.end())
			{
				for(it_s = followSet[nonTerminals[i]].begin(); it_s != followSet[nonTerminals[i]].end(); it_s++)
				{
					for(j = 0; j < terminals_temp.size(); j++)
					{
						if(terminals_temp[j] == *it_s)
							//parsingTable[i][j].push_back(*it);
						{
							if(parsingTable[i][j] == "")
							{
								//cout << "Inserted1 " << *it << " " << nonTerminals[i] << " " << terminals_temp[j] << endl;
								parsingTable[i][j] = *it;
							}
							else
							{
								//cout << "From Here" << endl;
								cout << "Grammar not LL(1)" << endl;
								exit(1);
							}
						}
					}					
				}					 
			}
		}
	}

	//cout << endl;
	for(i = 0; i < nonTerminals.size(); i++)
	{
		for(j = 0; j < terminals_temp.size(); j++)
		{
			if(parsingTable[i][j] == "")
				cout << "ERR\t";
			else
				cout << parsingTable[i][j] << "\t" ; 
		}
		cout << endl;
	}
	cout << "--------------------------------" << endl ;
	//string s;
	//s = parsingTable[0][5][0];
	//cout << s ;
while(1){
	string input;
	cout << "Enter an input string:" << endl;

	getline(cin, input);
	//cout << input << endl;
	
	
	vector<string>inp_split;
	//split(input, ' ', inp_split);
	for(int i=0;i<input.length();i++)
		inp_split.push_back(getString(input[i]));
	inp_split.push_back("$");
	/*

  if(input=="bda" || input=="da" || input=="ba" || input =="a")
		{
			cout<<"Accepted\n";
			return 0;
		}
		*/
	vector<string>::iterator it_inp;
	stack<string> t;
	int k;
	t.push("$");
	t.push(nonTerminals[0]);

	
	it_inp = inp_split.begin();
	
	while(1)	
	{
		cout << "TOP--> " << t.top() << " INPUT--> " << *it_inp << endl;
		if(*it_inp == "$" && t.top() == "$")
		{
			cout << "Accepted" << endl;
			break;
		}
		if(t.top() != "$" && terminals.find(t.top()) != terminals.end())
		{
			t.pop();
			it_inp++;
		}
		else
		{
			for(i = 0; i < nonTerminals.size(); i++)
			{	
				if(nonTerminals[i] == t.top())
					break;
			}
			for(j = 0; j < terminals_temp.size(); j++)
			{	
				if(terminals_temp[j] == *it_inp)
					break;
			}
			//cout << "I--> " << i << " J--> " << j << endl;
			if(parsingTable[i][j] == "")
			{
				cout << "Rejected" << endl;
				break;
			}
			else
			{
				//cout << "Inside" << endl;
				t.pop();
				string str;
				vector<string> str_v;
				str = parsingTable[i][j];
				//cout << "Entry--> " << str << endl;
				if(str != "#")
				{
					split(str, ' ', str_v);
					for(k = str_v.size() - 1; k >= 0; k--)
						t.push(str_v[k]);
				}
			}
		}
	}


//input while loop end
}
	return 0;
}

void printGrammar()
{
	for(int i = 0; i < nonTerminals.size(); i++)
	{
		for(int j = 0; j < rules[nonTerminals[i]].size(); j++)
		{
			cout << nonTerminals[i] << "\t" << rules[nonTerminals[i]][j] << endl ; 
		}	
	}
}



void findFirstSets()
{
	int i, j, k;
	bool result;
	vector<string>::iterator pos;
	vector<string> t;
	set<string>::iterator it;
	map<string, set<string> >::iterator xy;

	for(i = 0; i < nonTerminals.size(); i++)
	{
		for(k = 0; k < rules[nonTerminals[i]].size(); k++)
		{
			split(rules[nonTerminals[i]][k], ' ', t);				
		
			for(j = 0; j < t.size(); j++)
			{
			//cout << "Split " << t[j] << endl;
				pos = find(nonTerminals.begin(), nonTerminals.end(), t[j]);
				if(pos == nonTerminals.end())
				{
					firstSet[t[j]].insert(t[j]);
					terminals.insert(t[j]);
				}
			}
		}
		result = produceEpsilon(nonTerminals[i]);
		if(result)
			firstSet[nonTerminals[i]].insert("#");
		//cout << nonTerminals[i] << "S-->" << result << endl;
	
		t.clear();
	}

	t.clear();

	vector<string>::iterator iter, iter_v;

	
	result = TRUE;
	
	while(result)
	{
		result = FALSE;

		//cout << "New Iteration" << endl;
		for(iter = nonTerminals.begin(); iter != nonTerminals.end(); iter++)
		{
			for(iter_v = rules[*iter].begin(); iter_v != rules[*iter].end(); iter_v++)
			{
				vector<string> temp;
				vector<string>::iterator it_temp;
				split(*iter_v, ' ', temp);
				for(it_temp = temp.begin(); it_temp != temp.end(); it_temp++)
				{
					if(isNonTerminal(*it_temp))
					{
						if(!produceEpsilon(*it_temp))
						{  // if not produces epsilon
							set<string>::iterator it_s;
							if(firstSet.find(*it_temp) != firstSet.end())
							{						
								for(it_s = firstSet[*it_temp].begin(); it_s != firstSet[*it_temp].end(); it_s++)
								{
									if(firstSet[*iter].find(*it_s) == firstSet[*iter].end())
										result = TRUE;
									firstSet[*iter].insert(*it_s);
								}
								//cout << "END" << endl;
							}
							break;
						}
						else
						{ //produces epsilon then insert all first of that non terminal
							set<string>::iterator it_s;
							if(firstSet.find(*it_temp) != firstSet.end())
							{						
								for(it_s = firstSet[*it_temp].begin(); it_s != firstSet[*it_temp].end(); it_s++)
								{
									if(firstSet[*iter].find(*it_s) == firstSet[*iter].end())
										result = TRUE;
									firstSet[*iter].insert(*it_s);
								}
								
							}
							
						}
						
					}
					else
					{  //put terminals direclty
						if(*it_temp != "")
						{
							if(firstSet[*iter].find(*it_temp) == firstSet[*iter].end())
							{
								//cout << "Insert " << *it_temp << " in first " << *iter << endl; 
								result = TRUE;
							}
							firstSet[*iter].insert(*it_temp);
							break;
						}
					}
				}				
			}
		}
	}

	//cout << "Terminals" << endl;
	//for(it = terminals.begin(); it != terminals.end(); it++)
	//	cout << *it << endl;


	cout << "---------------------------------" << endl;
	cout << "First Sets-->" << endl;

	for(xy = firstSet.begin(); xy != firstSet.end(); xy++)
	{	
		cout << xy->first << "--> ";
		for(it = xy->second.begin(); it != xy->second.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}


vector<string> split(string s, char delim, vector<string> &elems)
{
        stringstream ss(s);
        string item;
        while(getline(ss, item, delim))
	{
                elems.push_back(item);
        }
        return elems;
}

bool produceEpsilon(string str)
{
	//cout << "Called-->" << str << endl;
	int i, j;
	vector<string> x;
	vector<string>::iterator it;
	bool yes;
	
	for(i = 0; i < rules[str].size(); i++)
	{
		//cout << "Rules " << rules[str][i] << endl;
		if(rules[str][i] == "#"){//cout << "dir #\n";
			return TRUE;	}	
	}

	//cout << "Size" << rules[str].size();

	for(i = 0; i < rules[str].size(); i++)
	{
		split(rules[str][i], ' ', x);

		//cout << "Length " << rules[str][i] << " " << rules[str][i].length() << endl;
		int has;

		for(j = 0; j < x.size(); j++)
		{
			has = 0;
			//cout << "x[j] -->" << x[j] << endl;
		
			yes = isNonTerminal(x[j]);
			if(yes)
			{  // checking recursively 
				if(!produceEpsilon(x[j]))//{ cout << "not produce\n";
					return FALSE;//}
				else
					has = 1;
			}
			else
				break;
		}
		x.clear();
		if(has)
			return TRUE;
	}	
	return FALSE;
}



bool isNonTerminal(string s)
{
	vector<string>::iterator it;
	for(it = nonTerminals.begin(); it != nonTerminals.end(); it++)
	{
		if(*it == s)
			return TRUE;
	}
	return FALSE;
}

void findFollowSets(){
	set<string>::iterator it;
	int i,j;
	vector<string>::iterator x;
	vector<string>::iterator itnt;

	followSet[nonTerminals[0]].insert("$");  // starting has $ as follow

	for(itnt = nonTerminals.begin(); itnt != nonTerminals.end(); itnt++)
	{
		for(x = rules[*itnt].begin(); x != rules[*itnt].end(); x++)
		{  
			vector<string> temp;
			int k;
			split(*x, ' ', temp);
			for(k = 0; k < temp.size() - 1; k++)
			{
				set<string>::iterator it_set;
				for(it_set = firstSet[temp[k + 1]].begin(); it_set != firstSet[temp[k+1]].end(); it_set++)
				{
					if(*it_set != "#")
						followSet[temp[k]].insert(*it_set);
				}
			}
		}
	}	


	map<string ,set<string> >::iterator xy;
	set<string>::iterator z;

	

	bool result = TRUE;

	while(result)
	{
		result = FALSE;
		for(itnt = nonTerminals.begin(); itnt != nonTerminals.end(); itnt++)
		{
			for(x = rules[*itnt].begin(); x != rules[*itnt].end(); x++)
			{
				vector<string> temp;
				split(*x, ' ', temp);
				for(i = 0; i < temp.size() - 1; i++)
				{
					for(j = i + 1; j < temp.size(); j++)
					{
						if(firstSet[temp[j]].find("#") == firstSet[temp[j]].end())
							break;
					}
					if(j == temp.size())
					{   //in S -> AX  follow (X) will contain follow(S)
						set<string>::iterator it_s;
						if(followSet.find(*itnt) != followSet.end())
						{
							for(it_s = followSet[*itnt].begin(); it_s != followSet[*itnt].end(); it_s++)
							{
								if(followSet[temp[i]].find(*it_s) == followSet[temp[i]].end())
									result = TRUE;
								followSet[temp[i]].insert(*it_s);
							}	
						}
					}
				}

				set<string>::iterator s_it;
				if(followSet.find(*itnt) != followSet.end())
				{
					for(s_it = followSet[*itnt].begin(); s_it != followSet[*itnt].end(); s_it++)
					{	
						if(followSet[temp[i]].find(*s_it) == followSet[temp[i]].end())
							result = TRUE;
						followSet[temp[i]].insert(*s_it);
					}
				}
			}			
		}
	}

	cout << "-------------------------------------" << endl;
	cout << "Follow Sets" << endl;
	
	for(xy = followSet.begin(); xy != followSet.end(); xy++)
	{
		if(xy->first != "#")
		{
			cout << xy->first << "--> " ;
			for(z = xy->second.begin(); z != xy->second.end(); z++)
				cout << *z << " ";
			cout << endl;
		}
		
	}
}
/*
E:T X
X:+ E
X:#
T:( E )
T:int Y
Y:* T
Y:#
*/
/*
S:A a
A:B D
B:b
B:#
D:d
D:#

*/