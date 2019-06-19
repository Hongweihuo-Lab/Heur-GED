#include "global.h"

extern nodeEntry DUMMY_NODE = nodeEntry();
extern edgeEntry DUMMY_EDGE = edgeEntry();
extern int q[1000] = { -1 };

extern string gname = "";
extern string type = "";
extern string sequence = "";
extern string angle = "";
extern string x = "";
extern string y = "";

extern int INSERTED = 510;
extern int DELETED = 511;
extern int UNMAPPED = 512;
extern int DUMMY = 511;
extern u64 expand_nodes = 0;

//the cost of substituting vertices and edges
extern vector<vector<double > > nodeSubMatrix = {};
extern vector<vector<double > > edgeSubMatrix = {};
extern int node_row = 0;
extern int node_column = 0;
extern int edge_row = 0;
extern int edge_column = 0;


extern vector<vector<int> > adjList1 = {};
extern vector<vector<int > > adjList2 = {};
extern vector<vector<edgeEntry > > E1 = {};
extern vector<vector<edgeEntry > > E2 = {};
extern vector<int> unused_vertices_1 = {};
extern vector<int> unused_vertices_2 = {};
extern verifyNode gn1[1024] = {};
extern verifyNode gn2[1024] = {};
extern edgeEntry adj_edges_1[1024] = {};
extern edgeEntry adj_edges_2[1024] = {};

extern int adj_nums_1 = 0;
extern int adj_nums_2 = 0;

extern double UB = INF;
extern int LB_CALL = 3; //0, LED; 1, HED; 2, BED; 3, BED+
extern struct timeval time_start = timeval();
extern struct timeval time_now = timeval();
extern double time_set = 0.0;
extern bool time_flag = false;

//use for test and debug
extern bool DEBUG = false;

#ifdef WIN32
extern int gettimeofday(struct timeval *tp, void *tzp)
{
	time_t clock;
	struct tm tm;
	SYSTEMTIME wtm;
	GetLocalTime(&wtm);
	tm.tm_year = wtm.wYear - 1900;
	tm.tm_mon = wtm.wMonth - 1;
	tm.tm_mday = wtm.wDay;
	tm.tm_hour = wtm.wHour;
	tm.tm_min = wtm.wMinute;
	tm.tm_sec = wtm.wSecond;
	tm.tm_isdst = -1;
	clock = mktime(&tm);
	tp->tv_sec = clock;
	tp->tv_usec = wtm.wMilliseconds * 1000;
	return (0);
}
#endif
