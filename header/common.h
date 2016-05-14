#pragma once
#pragma warning(push)
#pragma warning(disable: 4060)         // switch statement contains no 'case' or 'default' labels
#pragma warning(disable: 4065)         // switch statement contains 'default' but no 'case' labels
#pragma warning(disable: 4101)         // unreferenced local variable
#pragma warning(disable: 4996)         // std::basic_string<>::copy: Function call with parameters that may be unsafe


#include <sstream>
#include "stdafx.h"


typedef unsigned   int   uint;
typedef          __int64 int64;
typedef unsigned __int64 uint64;


/**
 * Ermittelt die Gr��e eines Elements eines Typs ohne vorhandene Instanz.
 */
#define sizeofMember(type, member) sizeof(((type*)NULL)->member)


/**
 * Schickt einen Text mit Tracking-Infos an die Debugger-Ausgabe.
 */
#define debug(...)   _debug(__FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)

int   _debug(char* fileName, char* funcName, const int line, const char*        format, ...);
int   _debug(char* fileName, char* funcName, const int line, const std::string &format, ...);
void __debug(char* fileName, char* funcName, const int line, const char*        format, const va_list &args);


/**
 * to_string()-Ersatz f�r fehlenden C++11-Support in Visual Studio 2008.
 *
 * VS 2005 - not supported
 * VS 2008 - not supported
 * VS 2010 - supported
 *
 * @param  <typename T> value
 *
 * @return std::string
 *
 * @note   Template functions have to be declared and defined in the same file.
 */
template <typename T> std::string to_string(T value) {
   std::ostringstream os;
   os << value;
   return(os.str());
}


/**
 * Pseudo-Funktionen, die ihrem Namen entsprechende feste Werte zur�ckzugeben. Alle Parameter werden ignoriert.
 */
int  _NULL    (...);
int  _CLR_NONE(...);
BOOL _TRUE    (...);
BOOL _FALSE   (...);
bool _true    (...);
bool _false   (...);


/**
 * Pseudo-Funktionen, die ihrem Namen entsprechende Werte variable zur�ckzugeben. Alle au�er dem ersten Parameter werden ignoriert.
 */
bool   _bool  (bool   value, ...);
char   _char  (char   value, ...);
int    _int   (int    value, ...);
float  _float (float  value, ...);
double _double(double value, ...);
