/*
** EPITECH PROJECT, 2020
** trade
** File description:
** include
*/

#ifndef MY_TRADE
#define MY_TRADE

#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <algorithm>
#include <exception>
#include <cmath>
#include <iomanip>
#include <cstring>

class Trade
{
    public:
        Trade();
        ~Trade();
        char *get_first_stock();
        char *set_settings(char *);
        int core(int, char **);
        char *set_BTC_ETH(char *);
        char *set_USDT_ETH(char *);
        char *set_USDT_BTC(char *);
        char *Managment_trade(char *);
    private:
        /*Variable settings*/
        int timebank;
        int time_per_move;
        int candle_interval;
        int candles_total;
        int candles_given;
        float initial_stack;
        int transaction_fee_percent;
        /*Variable settings*/

        /*BTC_ETH*/
        std::vector <float> hight_BTC_ETH;
        std::vector <float> low_BTC_ETH;
        std::vector <float> open_BTC_ETH;
        std::vector <float> close_BTC_ETH;
        std::vector <float> volume_BTC_ETH;
        /*BTC_ETH*/

        /*USDT_ETH*/
        std::vector <float> hight_USDT_ETH;
        std::vector <float> low_USDT_ETH;
        std::vector <float> open_USDT_ETH;
        std::vector <float> close_USDT_ETH;
        std::vector <float> volume_USDT_ETH;
        /*USDT_ETH*/

        /*USDT_BTC*/
        std::vector <float> hight_USDT_BTC;
        std::vector <float> low_USDT_BTC;
        std::vector <float> open_USDT_BTC;
        std::vector <float> close_USDT_BTC;
        std::vector <float> volume_USDT_BTC;
        /*USDT_BTC*/

        /*Generral*/
        float BTC;
        float ETH;
        float USDT;
        /*Generral*/
};

int error_handling(int ac, char **av);
float get_med_center(int pos, int med, std::vector<float> infos);
float get_average(int pos, int med, std::vector<float> infos);
float get_deviation(int pos, int med, std::vector<float> infos);
std::string swich(float now, float back, int *count);
std::pair<float, float> get_interval(float moyenn, std::vector<float> infos);
void weirdest(std::vector<float> &weird, float sum, int count, float news);

#endif /* !MY_TRADE */
