// Copyright 2022 UNN-IASR
#include "fun.h"
#include "cstring"
#include "iostream"
#include <algorithm>
#include <vector>

unsigned int faStr1(const char *str) {
  /*Разработать функцию на языке С++,
  которая в переданной строке определяет слова,
  не содержащие цифр и подсчитывает количество таких слов.*/
  int cnt = 0;
  char *p;
  char *copy = strdup(str);
  p = strtok(copy, " ");

  std::vector<std::string> vec_of_string;

  while (p != NULL) {
    vec_of_string.push_back(p);
    p = strtok(NULL, " ");
  }

  for (auto i : vec_of_string) {
    cnt += std::all_of(i.begin(), i.end(),
                       [](char const &c) { return std::isalpha(c); });
    // std::cout << i << ' '<<std::all_of(i.begin(), i.end(), [](char const &c)
    // { return std::isalpha(c);}) <<'\n';
  }

  return cnt;
}

unsigned int faStr2(const char *str) {
  /*
  Разработать функцию на языке С++,
  которая в переданной строке подсчитывает количество слов, начинающиеся на
  заглавную латинскую букву, а среди других символов этих слов только латинские
  строчные буквы.
  */
  int cnt = 0;
  char *p;
  char *copy = strdup(str);
  p = strtok(copy, " ");

  std::vector<std::string> vec_of_string;

  while (p != NULL) {
    vec_of_string.push_back(p);
    p = strtok(NULL, " ");
  }

  for (auto w : vec_of_string) {
    bool flag = true;
    // std::cout << w << '\n';
    if (islower(w[0]) || (isalpha(w[0] == 0))) {
      continue;
    }
    for (int i = 1; i < w.size(); i++) {
      if (isupper(w[i]) || isalpha(w[i]) == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cnt += 1;
    }
  }
  return cnt;
}

unsigned int faStr3(const char *str) {
  /*
  Разработать функцию на языке С++,
  которая находит среднюю длину слова в строке,
  округляя ее до целого значения по правилам округления.
  */
  int cnt = 0;
  char *p;
  char *copy = strdup(str);
  p = strtok(copy, " ");

  std::vector<std::string> vec_of_string;

  while (p != NULL) {
    vec_of_string.push_back(p);
    p = strtok(NULL, " ");
  }
  for (auto i : vec_of_string) {
    cnt += i.size();
  }
  return static_cast<int>(cnt / vec_of_string.size());
}
