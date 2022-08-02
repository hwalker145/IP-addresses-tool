#ifndef SETUP_H
#define SETUP_H

#include <string>
#include <sstream>

#ifdef _UNICODE
typedef		wchar_t				_TCHAR;
typedef		std::wstring		_TSTR;
typedef		std::wostringstream	_TOSTR;
typedef		std::wistringstream _TISTR;

#else
typedef		char				_TCHAR;
typedef		std::string			_TSTR;
typedef		std::ostringstream	_TOSTR;
typedef		std::istringstream  _TISTR;

#endif
#endif
