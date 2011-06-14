#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

map<string, list<string> >	clonelist;
list<string>				parentOrder;
list<string>				usedGames;
map<int, list<string> >		driverSetList;

//Process games.txt and driver list(drivers.txt) to add set number to stdout
int main	()
{
	//First load drivers
	ifstream ist("drivers.txt");
	int set = 0;
	while(ist.good() && !ist.eof())
	{
		string line;
		getline(ist, line);

		if(!line.empty())
		{
			if(line.find("ifdef") == 1)
			{
				set = atoi(line.c_str() + 15);
			}

			if(line.find("DRIVER"))
			{
				line = line.substr(line.find("(") + 1);
				line = line.substr(0, line.find(")"));
				driverSetList[set].push_back(line);
			}
		}		
	}
	ist.close();

	ist.open("games.txt");

	while(ist.good() && !ist.eof())
	{
		string line;
		getline(ist, line);

		if(!line.empty())
		{
			string title = line.substr(0, 17);
			title = title.substr(0, title.find(" "));

			for(map<int, list<string> >::iterator i = driverSetList.begin(); i != driverSetList.end(); i ++)
			{
				if(std::find(i->second.begin(), i->second.end(), title) != i->second.end())
				{
					printf("%2d %s\n", i->first, line.c_str());
				}
			}
		}
	}
}

#if 0
//Process clones.txt(mame -listclones) and fulls.txt(mame -listfull) to produce the sorted driver list
int main	()
{
	ifstream ist("clones.txt");

	while(ist.good() && !ist.eof())
	{
		string line;
		getline(ist, line);

		if(!line.empty())
		{
			string parent = line.substr(17);
			string clone = line.substr(0, 18);
			parent = parent.substr(0, parent.find(" "));
			clone = clone.substr(0, clone.find(" "));

			clonelist[parent].push_back(clone);
			usedGames.push_back(clone);
		}
	}

	ist.close();
	ist.open("clones.txt");

	while(ist.good() && !ist.eof())
	{
		string line;
		getline(ist, line);

		if(!line.empty())
		{
			string parent = line.substr(17);
			parent = parent.substr(0, parent.find(" "));

			if(find(parentOrder.begin(), parentOrder.end(), parent) == parentOrder.end())
			{
				parentOrder.push_back(parent);
				usedGames.push_back(parent);
			}
		}
	}

	ist.close();
	ist.open("fulls.txt");

	while(ist.good() && !ist.eof())
	{
		string line;
		getline(ist, line);

		if(!line.empty())
		{
			string title = line.substr(0, 17);
			title = title.substr(0, title.find(" "));

			bool found = false;

			if(find(usedGames.begin(), usedGames.end(), title) == usedGames.end())
			{
				parentOrder.push_back(title);
			}
		}
	}

	for(list<string>::iterator i = parentOrder.begin(); i != parentOrder.end(); i ++)
	{
		printf("//PARENT\n");
		printf("\tDRIVER(%s)\n", (*i).c_str());

		for(list<string>::iterator j = clonelist[*i].begin(); j != clonelist[*i].end(); j ++)
		{
			printf("\tDRIVER(%s)\n", (*j).c_str());
		}
	}
}
#endif
