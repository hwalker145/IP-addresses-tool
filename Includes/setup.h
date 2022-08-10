#ifndef SETUP_H
#define SETUP_H

#include <string>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <iomanip>

#ifdef _UNICODE
typedef		wchar_t				_TCHAR;
typedef		std::wstring		_TSTR;
typedef		std::wostringstream	_TOSTR;
typedef		std::wistringstream _TISTR;
constexpr	_TCHAR _TSLASH = L'/';
constexpr	_TCHAR _TPERIOD = L'.';
constexpr	_TCHAR _TCOLON = L':';
constexpr	_TCHAR * _TEMPTY_ADDRESS = L"0.0.0.0";

#else
typedef		char				_TCHAR;
typedef		std::string			_TSTR;
typedef		std::ostringstream	_TOSTR;
typedef		std::istringstream  _TISTR;
constexpr	_TCHAR _TSLASH = '/';
constexpr	_TCHAR _TPERIOD = '.';
constexpr	_TCHAR _TCOLON = ':';
constexpr	_TCHAR* _TEMPTY_ADDRESS = "0.0.0.0";

#endif
#endif
