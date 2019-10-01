#include <iostream>
#include <string>
#include <cstring>


using namespace std;

#include "libsqlite.hpp"                    // sqlite library

string accessDatabase(string tab, int col, int row)
{
	row = row - 1;
	col = col -1;

	sqlite::sqlite db("GameDatabaseV0.3.db");    // open database

	auto cur = db.get_statement();            // create query
	cur->set_sql(tab);
	cur->prepare();                            // run query
	vector<string> dbOut;
	string d;
	while (cur->step())
	{

		 d = cur->get_text(col);
		 dbOut.push_back(d);
	}


	return {dbOut.at(row)};

}
