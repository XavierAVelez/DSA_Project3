#include "FilmInfo.h"
#include <iomanip>


FilmInfo::FilmInfo()
{
	_rating = -1;
}


FilmInfo::~FilmInfo()
{
}

std::wostream & operator<<(std::wostream & os, const FilmInfo & info)
{
	os.setf(std::ios::fixed);

	os << info._name << std::endl;
	if (!info._directors.empty()) os << L"director: " << info._directors << std::endl;
	if (!info._screenwriters.empty()) os << L"screenwriter: " << info._screenwriters << std::endl;
	if (!info._stars.empty()) os << L"starring: " << info._stars << std::endl;
	if (!info._genres.empty()) os << L"type: " << info._genres << std::endl;
	if (!info._regions.empty()) os << L"country of production: " << info._regions << std::endl;
	if (!info._languages.empty()) os << L"language: " << info._languages << std::endl;
	if (!info._dates.empty()) os << L"release date: " << info._dates << std::endl;
	if (!info._durations.empty()) os << L"Length: " << info._durations << std::endl;
	if (!info._alternates.empty()) os << L"aka: " << info._alternates << std::endl;
	if (!info._tags.empty()) os << L"Label: " << info._tags << std::endl;
	if (info._rating != -1) os << L"score: " << std::fixed << std::setprecision(1) << info._rating << std::endl;
	if (!info._introduction.empty()) os << L"Synopsis: \n" << info._introduction << std::endl;

	os.unsetf(std::ios::fixed);
	return os;
}
