#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> vStr;


void left_print(string s, int n);
void right_print(string s, int n);
void center_print(string s, int n);
void divide(vector<string> v, int M);


int main()
{
	int N, M;

	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		string s;
		getline(cin, s);
		vStr.push_back(s);
	}
	
	divide(vStri, M);

	return 0;
}

void divide(vector<string> v, int M)
{
	int flag = 0;
	int size = v.size();
	for( int i = 0; i < size; i++)
	{
		if(v.front() == "<CENTER>" ) 
		{	flag = 1; v.erase(v.begin()); continue; }	
		else if( v.front() == "<RIGHT>" ) 
		{	flag = 2; v.erase(v.begin()); continue;}
		else if( v.front() == "</CENTER>" || v.front() == "</RIGHT>" ) 
		{	flag = 0; v.erase(v.begin()); continue;}
		
		if(flag == 1 ) { center_print(v.front(), M);}
		else if( flag == 2) { right_print(v.front(), M); }
		else if ( flag == 0 ) { left_print(v.front(), M);}

		v.erase(v.begin());	
	}



}


void center_print(string s, int n)
{
	vector<string> imsi;

	int len = 0;
	if ( n >= s.size() ) len = n - s.size();
	else
	{
		while(true)
		{
			auto it = find(s.begin(), s.end(), ' ');
			if(it != s.end() )
			{	
				s[it - s.begin()] = '\0';
				imsi.push_back( s.substr());
				s = s.substr(it-s.begin()+1);
			}
		}	
	}
	while(!imsi.empty())
	{
		len = n -  imsi.front().size();
		for (int i = 0; i < len / 2; i++) cout << '-';
		cout << imsi.front();
		if ( len % 2 == 1) len+1;
		for(int i = 0; i < len / 2; i++) cout << '-';
		imsi.erase(imsi.begin());
	}
}
void right_print(string s, int n)
{
	vector<string> imsi;

	int len = 0;
	if ( n >= s.size() ) len = n - s.size();
	else
	{
		while(true)
		{
			auto it = find(s.begin(), s.end(), ' ');
			if(it != s.end() )
			{	
				s[it - s.begin()] = '\0';
				imsi.push_back( s.substr());
				s = s.substr(it-s.begin()+1);
			}
		}	
	}
	while(!imsi.empty())
	{
		len = n -  imsi.front().size();
		for (int i = 0; i < len ; i++) cout << '-';
		cout << imsi.front()<< endl;
		imsi.erase(imsi.begin());
	}
}
void left_print(string s, int n)
{
	vector<string> imsi;

	int len = 0;
	if ( n >= s.size() ) len = n - s.size();
	else
	{
		while(true)
		{
			auto it = find(s.begin(), s.end(), ' ');
			if(it != s.end() )
			{	
				s[it - s.begin()] = '\0';
				imsi.push_back( s.substr());
				s = s.substr(it-s.begin()+1);
			}
		}	
	}
	while(!imsi.empty())
	{
		len = n -  imsi.front().size();
		cout << imsi.front();
		for(int i = 0; i < len; i++) cout << '-';
		cout << endl;
		imsi.erase(imsi.begin());
	}
}
