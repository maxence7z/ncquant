#ifndef EXIT_PARAMETERS_H
#define EXIT_PARAMETERS_H

#include <stddef.h>

typedef struct {
    long long open_time;    // opening timestamp
    long long close_time;   // closing timestamp
    double open;            // price @ open
    double high;            // highest price of candle
    double low;             // lowest price of candle
    double close;           // price @ close
    double volume;          // volume of asset
    double quote_volume;    // volume of quote asset
    int trades;             // n of trades during candle time
}; Candle;

typedef struct {
    Candle   *candles;
    size_t    count;        // n of Candle in candles
    size_t    capacity;     // current malloced size
    double    price_min;    // min price of CandleSet
    double    price_max;    // max price of CandleSet
    double    volume_max;
    long long time_start;   // open_time of first Candle
    long long time_end;
} CandleSet;

#endif
