nclude <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct Info
{
	int type;
	int dmg;
};

vector<Info> mon;
vector<Info> hero;

bool isMonsterDie(Info mon, Info hero);

void solv()
{
	for (int i = 0; i < (hero.size() - mon.size() + 1); i++)
	{
		int n = 0;
		for (int x = 0; x < mon.size(); x++)
		{
			if (isMonsterDie(mon[x], hero[i + x])) n++;
			else break;
		}
		if (mon.size() == n) cout << "1";
		else cout << "0";
	}
}

int main()
{
	int N, M; // N 몬스터 , M 원정대

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		Info a;
		cin >> a.type >> a.dmg;
		mon.push_back(a);
	}

	for (int i = 0; i < M; i++)
	{
		Info a;
		cin >> a.type >> a.dmg;
		hero.push_back(a);
	}
	solv();

	return 0;
}

bool isMonsterDie(Info mon, Info hero)
{
	if (mon.type != hero.type)	return mon.dmg <= hero.dmg;
	else						return mon.dmg <= floor(hero.dmg / 2);
}
