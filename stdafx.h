#ifndef _STDAFX_H
#define _STDAFX_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <set>
#include <ctime>
#include <queue>
#include <functional>
#include <algorithm>
#include <random>
#include <list>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdint.h>
#include <bitset>
#include <stack>
#include <pthread.h>
#include <limits>
#include <memory>

#ifdef WIN32
#include <direct.h>  
#include <io.h>     
#include <winsock.h> 
#else
#include <sys/time.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#define  _mkdir mkdir
#define  _access access
#define  ASSERT assert
#define _stati64 stat64
#define _fseeki64 fseeko
#define _FILE_OFFSET_BITS 64  
#endif


typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef clock_t wclock;

struct cost_constant
{
	double vertex_cost;
	double vertex_times;
	double edge_cost;
	double edge_times;
	double alpha;
	cost_constant(){}
	cost_constant(double vc, double vt, double ec, double et, double a) :
		vertex_cost(vc), vertex_times(vt), edge_cost(ec), edge_times(et), alpha(a){}
	~cost_constant(){}
};

using namespace std;

const string GREC_DB = "D:\\data\\database\\GREC\\db\\";
const string PROT_DB = "D:\\data\\database\\PRO\\db\\";
const string MUTA_DB = "D:\\data\\database\\Muta\\db\\";
const string PATH_DB = "D:\\data\\database\\PATH\\db\\";
const string CMU_DB = "D:\\data\\database\\CMU\\db\\";
const string SYN_DB = "D:\\data\\database\\SYN\\db\\";

const string GREC_CONFIG = "./config/GREC-config";
const string PROT_CONFIG = "./config/PRO-config";
const string MUTA_CONFIG = "./config/MUTA-config";
const string CMU_CONFIG = "./config/CMU-config";
const string SYN_CONFIG = "./config/SYN-config";

#endif
