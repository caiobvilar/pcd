#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

fillData(std::string filename)
{
	std::vector<std::string> testvector;
	std::vector<std::string>::iterator itr,itr2;
	std::ifstream file("out2.csv");	
	std::string inpudata;
	std::size_t start=0,end=0;
	while(file.good())
	{
		getline(file,inpudata,'\n');
		testvector.push_back(inpudata);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////

	for(itr = testvector.begin();itr != testvector.end();itr++)
	{
		end = (*itr).find(",",start);
		set.AccelX.push_back((*itr).substr(start,end));
		(*itr).erase(start,end+1);
		end = (*itr).find(",",start);
		set.AccelY.push_back((*itr).substr(start,end));
		(*itr).erase(start,end+1);
		set.AccelZ.push_back((*itr));
	}

	for(itr2 = set.AccelX.begin(),
			itr3 = set.AccelY.begin(),
			itr4 = set.AccelZ.begin();
			itr2 != set.AccelX.end(),
			itr3 != set.AccelY.end();
			itr2++,
			itr3++,
			itr4++)
	{
	}
	return set;
}

