#include <iostream>
#include <list>
#include <set>
using namespace std;

void print(const list<int>& alist);
bool member_of(const int value, const list<int>& alist, list<int>::const_iterator it);
void unique(list<int>& alist);
void unique1(list<int>& alist);
bool found_set(int value, const set<int>& s, set<int>::const_iterator it);
void uq(list<int>& alist);

int main()
{
    list<int> alist;

    for(int i; i < 10; i++)
    	alist.push_back(30);

    alist.push_back(40);
    alist.push_back(50);
    alist.push_back(60);

    print(alist);
    uq(alist);
    print(alist);
}

void print(const list<int>& alist)
{
    for (list<int>::const_iterator it = alist.begin(); it != alist.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

bool member_of(const int value, const list<int>& alist, list<int>::const_iterator it)
{
    if (it == alist.end()) return false;

    return (*it == value) || member_of(value, alist, ++it);
}

void unique(list<int>& alist)
{
    if (alist.size() <= 1) return;

    int first = alist.front();
    alist.erase(alist.begin());  // remove the first element

    unique(alist);  // make the rest of the list unique

    if (!member_of(first, alist, alist.begin()))
    {
        alist.push_front(first);  // put back the first element
    }
}

void unique1(list<int>& alist)
{
	list<int>::iterator it =  alist.begin();
	list<int> save;
	while(it != alist.end())
	{
	    if (!member_of(*it, save, save.begin()))
	    {
	        save.push_front(*it);  // put back the first element
	    }
	    else
	    {
	    	alist.erase(it);
	    }
		++it;
	}
}

void uq(list<int>& alist)
{
	list<int>::iterator it =  alist.begin();
	set<int> set1;
	while(it != alist.end())
	{
		set<int>::iterator setit = set1.begin();
	    if (!found_set(*it, set1, setit))
	    {
	        set1.insert(setit, *it);  // put back the first element
	    }
	    else
	    {
	    	alist.erase(it);
	    }
		++it;
	}
}

bool found_set(int value, const set<int>& s, set<int>::const_iterator it)
{
	if(it == s.end())
		return false;

	return (*it == value) || found_set(value, s, ++it);
}

//void found(int value, unordered_set<int> s, )'
