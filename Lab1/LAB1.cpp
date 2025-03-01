//LAB 1

//Problema 1

#include <stdio.h>
#include<bits/stdc++.h>

int myatoi(const char *s)
{
int rez=0,i=0;
while(s[i]>='0' && s[i]<='9')
    {
    rez=rez*10+(s[i]-'0');
    i++;
    }
return rez;
}

int main() {
    FILE *file=fopen("in.txt","r");
    char linie[100];
    int suma=0;
    while(fgets(linie,sizeof(linie),file))
    {
    suma+=myatoi(linie);
    }
    fclose(file);
    printf("%d\n", suma);
}



//Problema 2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    char *word1 = *(char **)a;
    char *word2 = *(char **)b;
    int len1 = strlen(word1), len2 = strlen(word2);
    return (len1 != len2) ? len2 - len1 : strcmp(word1, word2);
}

int main() {
    char input[256], *words[50];
    int count = 0;

    fgets(input, sizeof(input), stdin);
    for (char *token = strtok(input, " \n"); token; token = strtok(NULL, " \n"))
        words[count++] = strdup(token);

    qsort(words, count, sizeof(char *), compare);

    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }
}



//Problema 3

#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int tr = 2; tr <= n / 2; tr++)
        if ((n % tr) == 0)
            return false;
    return true;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    if (isPrime(n))
        std::cout << n << " is prime!";
    else
        std::cout << n << " is NOT prime!";
    return 0;
}



//EXTRA

//header.h:

#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

enum VALORI {
    INMULTIRE = 0,
    SUMA,
    REZERVAT1,
    DIFERENTA,
    REZERVAT2,
    IMPARTIRE
};

typedef int (*func)(int, int);

struct Content {
    int p1;
    int p2;
};

int Sum(int a, int b);
int Dif(int a, int b);
int Mul(int a, int b);
int Div(int a, int b);


//source.cpp:

#include "header.h"

int Sum(int a, int b) { return a + b; }
int Dif(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return (b != 0) ? a / b : 0; }

int main(int argc, char* argv[]) {
    char input[50] = "---H***E+++L+++L///O---P+++O/+-**O---";
    func Operatori[4] = {Sum, Dif, Mul, Div};
    int S = 0;
    int idx = 0;
    Content x = {0, 0};

    for (int i = 0; i < (int)strlen(input); i++) {
        switch (input[i] - 42) {
            case INMULTIRE:
                idx = 2;
                x.p1 = 3;
                x.p2 = 3;
                break;
            case SUMA:
                idx = 0;
                x.p1 = 7;
                x.p2 = 5;
                break;
            case DIFERENTA:
                idx = 1;
                x.p1 = 10;
                x.p2 = 1;
                break;
            case IMPARTIRE:
                idx = 3;
                x.p1 = 8;
                x.p2 = 4;
                break;
            default:
                continue;
        }

        S += Operatori[idx](x.p1, x.p2);
    }

    printf("S = %d\n", S);
    return 0;
}
