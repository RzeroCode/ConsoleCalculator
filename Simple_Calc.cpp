//Efehan Guner
#include<iostream>
#include<string>
#include"strutils.h"
using namespace std;

void sum(string inp) //+/- func
{
	int plusIndex=inp.find("+"),minusIndex=inp.find("-"),len=inp.length(); //next if statements check input if there are multiple operands next to each other.
	if(plusIndex!=-1)
	{
		if(inp.at(plusIndex)==inp.at(plusIndex+1))
		{
			cout<<"Invalid entry"<<endl<<endl;
			return;
		}
	}
	if(minusIndex!=-1)
	{
		if(inp.at(minusIndex)==inp.at(minusIndex+1))
		{
			cout<<"Invalid entry"<<endl<<endl;
			return;
		}
	}
	int startPoint=0;
	double sum=0.0;
	bool minus=false;
	for(int i=0;i<len;i++) //this loop make calculations for summation and substraction
	{
		if(inp.at(i)=='+'||inp.at(i)=='-'||i==len-1)
		{
			if(!minus)
			{
				sum+=atof(inp.substr(startPoint,i));
				startPoint=i;
				if(inp.at(i)=='-')
					minus=true;
			}
			else
			{
				sum+=atof(inp.substr(startPoint,i));
				startPoint=i;
				if(inp.at(i)=='+')
					minus=false;
			}
		}
	}
	cout<<sum<<endl<<endl; //succesful operation
}
void multi(string inp) // * and / calculations
{
	int multiIndex=inp.find("*"),divIndex=inp.find("/"),len=inp.length(); // next if statements check if there are multiple operands next to each other.
	if(multiIndex!=-1)
	{
		if(inp.at(multiIndex)==inp.at(multiIndex+1))
		{
			cout<<"Invalid entry"<<endl<<endl;
			return;
		}
	}
	if(divIndex!=-1)
	{
		if(inp.at(divIndex)==inp.at(divIndex+1))
		{
			cout<<"Invalid entry"<<endl<<endl;
			return;
		}
	}
	int startPoint=0;
	double multip=1.0;
	bool div=false,divZero=false;
	for(int i=0;i<len && divZero==false;i++) // this loop make division and multiply calculations.
	{
		if(inp.at(i)=='*'||inp.at(i)=='/'||i==len-1)
		{
			if(!div)
			{
				multip*=atof(inp.substr(startPoint,i));
				startPoint=i+1;
				if(inp.at(i)=='/')
					div=true;
			}
			else
			{
				if(atof(inp.substr(startPoint,i))!=0)
				{
					multip/=atof(inp.substr(startPoint,i));
					startPoint=i+1;
					if(inp.at(i)=='*')
						div=false;
				}
				else
					divZero=true;  //checks if there is division with zero.
			}
		}
	}
	if(!divZero)
		cout<<multip<<endl<<endl; //succesful operation
	else
		cout<<"You cannot divide by 0"<<endl<<endl;
}

void inputCheck(string inp)
{
	if(LowerString(inp)==UpperString(inp)) //checks if there are alphebetical chars.
	{
		string endChar=inp.substr(inp.length()-1,inp.length()); //next if elses checks if there are operands in begining and end of the string
		if(endChar=="+"||endChar=="-"||endChar=="*"||endChar=="/")
		{
			cout<<"Invalid entry"<<endl<<endl;
			return;
		}
		else
		{
			char startChar=inp.at(0);
			if(startChar=='+'||startChar=='-'||startChar=='*'||startChar=='/')
			{
				cout<<"Invalid entry"<<endl<<endl;
				return;
			}
			else
			{
				if(inp.find("+")!=-1 || inp.find("-")!=-1) //next if elses call first function if there are no errors.
				{
					sum(inp);

				}
				else if(inp.find("*")!=-1 || inp.find("/")!=-1)
				{
					multi(inp);
				}
				else
				{
					cout<<inp<<endl<<endl;
				}

			}
		}
	}
	else
	{
		if(inp!="QUIT"&&inp!="quit"&&inp!="EXIT"&&inp!="exit"&&inp!="end"&&inp!="END") //checks if there are terminating keywords.
			cout<<"Invalid entry"<<endl<<endl;
	}
}

int main()
{
	string inp;
	while(inp!="QUIT"&&inp!="quit"&&inp!="EXIT"&&inp!="exit"&&inp!="end"&&inp!="END") //checks if there are terminating keywords.
	{
		cout<<"Please enter the expression to calculate: ";
		cin>>inp;
		inputCheck(inp);

	}
	cout<<"GOOD BYE"<<endl;
	return 0;
}