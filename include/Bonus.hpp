/*
** EPITECH PROJECT, 2020
** my_sfml
** File description:
** include
*/

#ifndef MY_SFML
#define MY_SFML

#include <SFML/Graphics.hpp>

class Bonus
{
    public:
        Bonus();
        ~Bonus();
        void head();
        void graduation_left();
        void graduation_down();
        void display_curve();
        void uptade(std::string);
        void last();
        void graph();
        void new_info();
        void present();
        void loop(int);
        void weirdest_bonus();
    private:
        std::string nb_last;
        std::string g_last;
        std::string r_last;
        std::string s_last;

        std::string nb_new;
        std::string g_new;
        std::string r_new;
        std::string s_new;

        sf::RenderWindow window;
        sf::Font font;

        int biggest;
        int count;
        std::vector<float> infos;
        sf::Event event;
        std::string input;
        bool test;
        int sw_count;
        std::string tmp;
        float sum;
        int periode;
        std::vector<int> list;
        std::vector<float> file;
        std::vector<float> weird;
};

#endif /* !MY_SFML */
