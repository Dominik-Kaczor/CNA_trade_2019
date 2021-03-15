/*
** EPITECH PROJECT, 2020
** groundhog
** File description:
** groudhog
*/

#include "trade.hpp"

char *cstr;

Trade::Trade()
{
    USDT = 0;
    USDT = 0;
    USDT = 0;
}

Trade::~Trade()
{

}

float get_med_center(int pos, int med, std::vector<float> infos)
{
    float res = 0.0;
    for (int i = 0; i < med; i++) {
        if (infos[pos - med + i] <= 0) {
            res += 0;
        } else {
            res += infos[pos - med + i];
        }
    }
    res = res / med;
    return res;
}

float get_average(int pos, int med, std::vector<float> infos)
{
    float res = 0.0;

    if (infos[pos - med] == 0)
        return 999.0;
    res = ((infos[pos] * 100) / std::abs(infos[pos - med])) - 100;
    return res;
}

float get_deviation(int pos, int med, std::vector<float> infos)
{
    float a = 0.0;
    float b = 0.0;

    for (int i = 0; i < med; i++) {
        a += infos[pos - med + i];
        b += std::pow(infos[pos - med + i], 2);
    }
    return std::sqrt(b/med - std::pow((a / med), 2));
}

std::string swich(float now, float back, int *count)
{
    if (now < 0 && back > 0) {
        (*count) += 1;
        return "a switch occurs";
    } else if (now > 0  && back < 0) {
        (*count) += 1;
        return "a switch occurs";
    } else {
        return "";
    }
}

void weirdest(std::vector<float> &weird, float sum, int count, float news)
{
    float medium = sum / count;
    int tmp = 0;
    for (size_t i = 0; i < 5; i++) {
        if (weird[i] == 0.0) {
            weird[i] = news;
            break;
        }
        if (std::abs(medium - weird[i]) < std::abs(medium - news)) {
            if (std::abs(medium - weird[tmp]) < std::abs(medium - news))
                tmp = i;
        }
    }
    weird[tmp] = news;
}

char *Trade::set_BTC_ETH(char *pch)
{
    char *ncstr = cstr;

    if (pch != NULL && strcmp(pch, "BTC_ETH") == 0) {
        if (cstr != NULL)
            cstr = NULL;
        pch = strtok (ncstr, ",; ");
        pch = strtok (NULL, ",; ");
        hight_BTC_ETH.push_back(std::atof(pch));
        pch = strtok (NULL, ",; ");
        low_BTC_ETH.push_back(std::atof(pch));
        pch = strtok (NULL, ",; ");
        open_BTC_ETH.push_back(std::atof(pch));
        pch = strtok (NULL, ",; ");
        close_BTC_ETH.push_back(std::atof(pch));
        pch = strtok (NULL, ",; ");
        volume_BTC_ETH.push_back(std::atof(pch));
    }
    return pch;
}

char *Trade::set_USDT_ETH(char *pch)
{
    char *ncstr = cstr;

    if (pch != NULL && strcmp(pch, "USDT_ETH") == 0) {
        if (cstr != NULL)
            cstr = NULL;
        pch = strtok (ncstr, ",; ");
        pch = strtok (NULL, ",; ");
        hight_USDT_ETH.push_back(std::atof(pch));
        pch = strtok (NULL, ",; ");
        low_USDT_ETH.push_back(std::atof(pch));
        pch = strtok (NULL, ",; ");
        open_USDT_ETH.push_back(std::atof(pch));
        pch = strtok (NULL, ",; ");
        close_USDT_ETH.push_back(std::atof(pch));
        pch = strtok (NULL, ",; ");
        volume_USDT_ETH.push_back(std::atof(pch));
    }
    return pch;
}

char *Trade::set_USDT_BTC(char *pch)
{
    char *ncstr = cstr;

    if (pch != NULL && strcmp(pch, "USDT_BTC") == 0) {
        if (cstr != NULL)
            cstr = NULL;
        pch = strtok (ncstr, ",; ");
        pch = strtok (NULL, ",; ");
        hight_USDT_BTC.push_back(std::atof(pch));
        pch = strtok (NULL, ",; ");
        low_USDT_BTC.push_back(std::atof(pch));
        pch = strtok (NULL, ",; ");
        open_USDT_BTC.push_back(std::atof(pch));
        pch = strtok (NULL, ",; ");
        close_USDT_BTC.push_back(std::atof(pch));
        pch = strtok (NULL, ",; ");
        volume_USDT_BTC.push_back(std::atof(pch));
    }
    return pch;
}

char *Trade::set_settings(char *pch)
{
    char *ncstr = cstr;

    if (pch != NULL && strcmp(pch, "settings") == 0) {
        if (cstr != NULL)
            cstr = NULL;
        pch = strtok (ncstr, ",; ");
        if (strcmp(pch, "timebank") == 0) {
            pch = strtok (NULL, ",; ");
            timebank = std::atoi(pch);
        }
        if (strcmp(pch, "time_per_move") == 0) {
            pch = strtok (NULL, ",; ");
            time_per_move = std::atoi(pch);
        }
        if (strcmp(pch, "candle_interval") == 0) {
            pch = strtok (NULL, ",; ");
            candle_interval = std::atoi(pch);
        }
        if (strcmp(pch, "candles_total") == 0) {
            pch = strtok (NULL, ",; ");
            candles_total = std::atoi(pch);
        }
        if (strcmp(pch, "candles_given") == 0) {
            pch = strtok (NULL, ",; ");
            candles_given = std::atoi(pch);
        }
        if (strcmp(pch, "initial_stack") == 0) {
            pch = strtok (NULL, ",; ");
            initial_stack = std::atof(pch);
            USDT = initial_stack;
        }
        if (strcmp(pch, "transaction_fee_percent") == 0) {
            pch = strtok (NULL, ",; ");
            transaction_fee_percent = std::atof(pch);
        }
    }
    return pch;
}

char *Trade::get_first_stock(void)
{
    char *pch;
    char *ncstr = cstr;

    if (cstr != NULL)
        cstr = NULL;
    pch = strtok (ncstr, ",; ");
    if (pch == NULL)
        return NULL;
    return pch;
}

char *Trade::Managment_trade(char *pch)
{
    char *ncstr = cstr;

    if (pch != NULL && strcmp(pch, "update") == 0) {
        if (cstr != NULL)
            cstr = NULL;
        pch = strtok (ncstr, ",; ");
        pch = strtok (NULL, ",; ");
        pch = strtok (NULL, ",; ");
        pch = set_BTC_ETH(pch);
        pch = set_USDT_ETH(pch);
        pch = set_USDT_BTC(pch);
    }
    return pch;
}

int Trade::core(int ac, char **av)
{
    std::string str;
    char *pch;

    if (ac == 2 && !std::string("-h").compare(std::string(av[1]))) {
        printf("SYNOPSIS\n\t./groundhog period\n\nDESCRIPTION\n\tperiod\tthe number of days defining a period\n");
        return 84;
    }
    while (std::getline(std::cin, str)) {
        char mcstr[str.size() + 1];
        strcpy(mcstr, str.c_str());
        cstr = mcstr;
        pch = cstr;
        while (pch != NULL) {
            pch = get_first_stock();
            pch = set_settings(pch);
            pch = Managment_trade(pch);
        }
        std::cout << "pass" << std::endl;
    }
    return 0;
}

int error_handling(int ac, char **av)
{
    std::unique_ptr<Trade> Trade_core(new Trade());
    int ret = 0;

    try  {
        ret = Trade_core->core(ac, av);
    } catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return ret;
}
