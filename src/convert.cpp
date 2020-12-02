#include "../include/convert.h"


// convert utc time string to an int timestamp (number of seconds since posix epoch)
int get_epoch_ime(const std::wstring& date_time)
{
       static const std::wstring dateTimeFormat{ L"%Y-%m-%dT%H:%M:%SZ" };
       std::wistringstream ss{ date_time };
       std::tm dt;
       ss >> std::get_time(&dt, dateTimeFormat.c_str());
       return std::mktime(&dt);
}