#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

struct state                                             
{
  string country;
  string capital;
  string government;
  string language;
  string religion;
  string continent;
  float area;
  int population;
}; 
state read_state(ifstream &file)
{
	state ctr;
	getline(file,ctr.country);
	getline(file,ctr.capital);
	getline(file,ctr.government);
	getline(file,ctr.language);
	getline(file,ctr.religion);
	getline(file,ctr.continent);
	file>>ctr.area;
	file.ignore();
	file>>ctr.population;
	file.get();
	return ctr;
}

void print_state(state ctr)
{
	cout<<"\nCountry : ";
	cout<<ctr.country<<endl;
	cout<<"\nCapital : ";
	cout<<ctr.capital<<endl;
	cout<<"\nGoverment : ";
	cout<<ctr.continent<<endl;
	cout<<"\nLanguage : ";
	cout<<ctr.language<<endl;
	cout<<"\nReligion : ";
	cout<<ctr.religion<<endl;
	cout<<"\nArea : ";
	cout<<ctr.area<<endl;
	cout<<"\nPopulation : ";
	cout<<ctr.population<<endl;
	cout<<"\n-----------##------------";
}

void Sum(state ct[], int num ,string acontinent)
{
	ofstream outfile("sum.txt");
	float sumarea = 0;
	int sumpop = 0;
	for (int i = 0; i < num; i++)
	{
        if (ct[i].continent == acontinent)                    
	    {
	    	sumarea += ct[i].area;
	    	sumpop += ct[i].population;  
        }
    }
    cout<<"\nSum area : "<<sumarea<<endl;
    cout<<"Sum population : "<<sumpop<<endl;
    outfile<<"Sum area : "<<sumarea<<endl;
    outfile<<"Sum population : "<<sumpop<<endl;
	outfile.close();    
}

void   find( state st[],int num,string lang)
{
	ofstream outfile("ex2.txt");
	int max = st[0].population;
	int j = 0;
	for(int i = 1; i <= num; i++)
    {
        if(st[i].language == lang)
    	{
    	    if(max < st[i].population)
    	{
    		max = st[i].population;
    		j = i;
		}
	  }
	}
	cout<<"\nName and capital of the largest state in terms of population :"<<endl;
	cout<<"Country : "<<st[j].country<<endl;
	cout<<"Capital : "<<st[j].capital<<endl;
	outfile<<"Name and capital of the largest state in terms of population :"<<endl;
	outfile<<"Country : "<<st[j].country<<endl;
	outfile<<"Capital : "<<st[j].capital<<endl;
	outfile.close();
}

int main(int argc, char** argv) {
	int N;
	ifstream infile ("state.txt");
	if(infile.is_open())
	infile >> N;
	infile.get(); 
	state* ct = new state[N];
	
	for(int i = 0; i < N; i++) 
	{
		ct[i] = read_state(infile); 
    }
    infile.close();
    for (int i = 0; i < N; i++) 
    {
        print_state(ct[i]);	
    }
    
    string scontinent;
	cout<<"\n+Enter the continent : ";
	getline(cin, scontinent);
	Sum(ct,N,scontinent);
	
	string slanguage;
	cout<<"\n+Enter the language : ";
	getline(cin, slanguage);
	find(ct,N,slanguage);
	delete[] ct;
	return 0;
}
