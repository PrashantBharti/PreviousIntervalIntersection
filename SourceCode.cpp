#include <iostream>
#include <utility>
#include <vector>
using namespace std; 

typedef pair<int, int> INTERVAL;
typedef vector<INTERVAL> INTERVALLIST;

void Swap(INTERVAL &interval1, INTERVAL &interval2)
{
INTERVAL intervaltemp = interval1;
interval1 = interval2;
interval2 = intervaltemp;
}

bool IsIntersecting(INTERVAL interval1, INTERVAL interval2)
{
if(interval2.first < interval1.second && interval2.first >= interval1.first)
	return true;

if(interval2.second > interval1.first && interval2.second <= interval1.second)
	return true;

if(interval2.first < interval1.first && interval2.second > interval1.second)
	return true;

return false;
}

void TestTheIntervals(INTERVALLIST &intervallist)
{
for(unsigned int i = 1; i < intervallist.size(); ++i)
	{
	for(int j = i - 1; j >= 0; --j)
		{
		if(IsIntersecting(intervallist[j], intervallist[j+1]))
			cout << "[" << intervallist[j+1].first << "," << intervallist[j+1].second << "]" << " intersects with " << "[" << intervallist[j].first << "," << intervallist[j].second << "]" << endl;

		if(intervallist[j].first > intervallist[j+1].first)
			Swap(intervallist[j], intervallist[j+1]);
		else
			break;
		}
	}
}

int main(void)
{
INTERVALLIST intervallist;
intervallist.push_back(INTERVAL(2, 5));
intervallist.push_back(INTERVAL(8, 10));
intervallist.push_back(INTERVAL(2, 6));
intervallist.push_back(INTERVAL(1, 6));

TestTheIntervals(intervallist);

return 0;
}