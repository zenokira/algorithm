#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define LIMIT 51

struct POINT
{
	int x, y;
};

struct LINE
{
	POINT start, end;
};

using namespace std;

class CPOINT
{
public:
	
	POINT point;
	vector<CPOINT> v;

	CPOINT() { }
	CPOINT(POINT p) { point = p; }
	~CPOINT() { }

	int getCount()
	{
		return v.size();
	}
	void setPoint(POINT p)
	{
		point = p;
	}
	void push_back(POINT p)
	{
		v.push_back(p);
	}
	POINT getPoint()
	{
		return point;
	}
};

vector <CPOINT> vRed;
vector <CPOINT> vYellow;
vector <LINE> vLine;
set <POINT> sPoint;

void solv_Redpoint();
bool isPoint(POINT src, POINT des );

void solv()
{
			
}

int main()
{
	int X,Y;

	int RED, YELLOW_POINT, YELLOW_LINE;
	
	cin >> X >> Y ;

	cin >> RED;
	CPOINT dumi;
	vYellow.push_back(dumi);
	vRed.push_back(dumi);
	for(int i = 0; i < RED; i++)
	{
		POINT S, E;	
		cin >> S.x >> S.y >> E.x >> E.y;
		vLine.push_back({S,E});
		sPoint.insert(S); sPoint.insert(E);
	}

	cin >> YELLOW_POINT;

	for(int i = 0; i<YELLOW_POINT; i++)
	{
		CPOINT cy;
		cin >> cy.point.x  >> cy.point.y ;
		vYellow.push_back(cy);
	}
	
	for(int i = 0; i<YELLOW_LINE; i++)
	{
		int s, e;
		vYellow[s].v.push_back(vYellow[e]);		
		vYellow[e].v.push_back(vYellow[s]);
	}
}

bool isPoint(POINT src, POINT des )
{
	if( src.x == des.x && src.y == des.y) return true;
	else return false;
}

void solv_Redpoint()
{
	for(auto it = sPoint.begin(); it != sPoint.end(); it++)
	{
		CPOINT cp(*it);
		vRed.push_back(cp);
	}

	for(int i = 0; i < vLine.size(); i++)
	{
		for(int idx = 1; idx < vRed.size(); idx++)
		{
			if( isPoint( vLine[i].start, vRed[idx].getPoint() )) vRed[idx].push_back( vLine[i].end);
				
			if( isPoint( vLine[i].end, vRed[idx].getPoint() )) vRed[idx].push_back( vLine[i].start);
		}
	}
	
}
