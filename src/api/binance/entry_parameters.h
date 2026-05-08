#ifndef ENTRY_PARAM_H
#define ENTRY_PARAM_H

typedef enum {
	INTERVAL_1S, INTERVAL_1M, INTERVAL_5M, INTERVAL_15M, INTERVAL_30M,
    INTERVAL_1H, INTERVAL_2H, INTERVAL_4H,
    INTERVAL_1D, INTERVAL_1W, INTERVAL_1M_MONTH
} Interval;

typedef struct {
	const char *symbol;
	Interval interval;
	long long start_time;
	long long end_time;
	int limit;
} EntryParams;

#endif
