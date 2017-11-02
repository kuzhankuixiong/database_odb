#include <memory>
#include <odb/core.hxx>
#include <odb/lazy-ptr.hxx>
#include <set>
#include <string>

#pragma db view
class StarCount{
public:
	StarCount(){}
	StarCount(int stars_in,int count_in):stars(stars_in),count(count_in){}

	int stars;
	int count;
};

#pragma db view query("select top 1 text, last_elapsed_time from sys.dm_exec_query_stats cross apply sys.dm_exec_sql_text(sql_handle) order by last_execution_time desc")
class LastQueryTime{
public:
	std::string text;
	long elapsed_time;
};

// ---------------------------------------------
// No need to change anything above this line
// ---------------------------------------------

class review;
class hours;
class user;
class business;

#pragma db object table("USER")
class user{
public:
user() {}

#pragma db id not_null column("ID") type("VARCHAR(22)")
std::string id;

#pragma db column("NAME") type("VARCHAR(255)")
std::string name;
/*
#pragma db value_not_null unordered
std::vector<std::shared_ptr<review>> reviews;
*/
friend class odb::access;

};


#pragma db object table("REVIEW")
class review{
public:
review() {}

#pragma db id not_null column("ID") type("VARCHAR(22)")
std::string id;

#pragma db not_null column("USER_ID") type("VARCHAR(22)")
std::string user_id;

#pragma db not_null column("BUSINESS_ID") type("VARCHAR(22)")
std::string business_id;
/*
#pragma db value_not_null unordered
std::vector<std::shared_ptr<hours>> hours_vec;
*/
friend class odb::access;

};


#pragma db object table("HOURS")
class hours{
public:
hours() {}

#pragma db id not_null column("ID") type("VARCHAR(22)")
std::string id;

#pragma db column("HOURS") type("VARCHAR(255)")
std::string hours_;

#pragma db not_null column("BUSINESS_ID") type("VARCHAR(22)")
std::string business_id;

friend class odb::access;

};




#pragma db object table("BUSINESS")
class business{
public:
business() {}

#pragma db id not_null column("ID") type("VARCHAR(22)")
std::string id;

#pragma db column("LATITUDE") type("FLOAT")
double latitude;

#pragma db column("LONGITUDE") type("FLOAT")
double longitude;

#pragma db column("STARS") type("FLOAT")
double stars;



friend class odb::access;

};















