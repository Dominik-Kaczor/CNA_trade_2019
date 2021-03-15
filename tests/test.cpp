/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <fstream>
#include "groundhog.hpp"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(occurs, swich, .init = redirect_all_std)
{
    float now = 0.1;
    float back = -0.2;
    int count = 0;
    std::string dest = swich(now, back, &count);
    cr_assert_str_eq(dest.c_str(), "a switch occurs");
}

Test(global, subject, .init = redirect_all_std)
{
    std::ifstream inFile;
    inFile.open("tests/commands/input");
    std::ifstream inFile2;
    inFile2.open("tests/res/normal");
    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string str = strStream.str();
    std::stringstream strStream2;
    strStream2 << inFile2.rdbuf();
    std::string str2 = strStream2.str();
    fprintf(cr_get_redirected_stdin(), "%s", str.c_str());
    char *av[] = {(char *)"a.out", (char *)"7", NULL};
    error_handling(2, av);
    cr_assert_str_eq(str2.c_str(), str2.c_str());
}

Test(stof_error, not_float, .init = redirect_all_std)
{
    std::ifstream inFile;
    inFile.open("tests/commands/tony");
    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string str = strStream.str();
    fprintf(cr_get_redirected_stdin(), "%s", str.c_str());
    char *av[] = {(char *)"a.out", (char *)"7", NULL};
    int dest = error_handling(2, av);
    cr_assert_eq(dest, 84);
}

Test(no_args, display_infos, .init = redirect_all_std)
{
    char *av[] = {(char *)"a.out", NULL};
    int dest = error_handling(1, av);
    cr_assert_eq(dest, 84);
}

Test(help, display_infos, .init = redirect_all_std)
{
    char *av[] = {(char *)"a.out", (char *)"-h", NULL};
    int dest = error_handling(2, av);
    cr_assert_eq(dest, 84);
}

Test(to_big_arg, display_infos, .init = redirect_all_std)
{
    std::ifstream inFile;
    inFile.open("tests/commands/input");
    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string str = strStream.str();
    fprintf(cr_get_redirected_stdin(), "%s", str.c_str());
    char *av[] = {(char *)"a.out", (char *)"2344", NULL};
    int dest = error_handling(2, av);
    cr_assert_eq(dest, 84);
}