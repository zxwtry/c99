/*
    url: leetcode.com/problems/regular-expression-matching/
    _match:     64ms  6.40%
    _match_dp:   9ms 83.74%
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

char L010__access_char_array(char *s, int sn, int i) {
    if (i >= sn) return '\0';
    return *(s + i);
}

bool L010__judge(char sc, char pc) {
    return sc == pc || (pc == '.' && sc != '\0');
}

//use trace back
bool L010__match(char* s, int sn, int si, char* p, int pn, int pi) {
    char sc = L010__access_char_array(s, sn, si);
    char pc = L010__access_char_array(p, pn, pi);
    if (pc == '\0') return sc == '\0';
    if (L010__access_char_array(p, pn, pi + 1) == '*') {
        while (L010__judge(sc, pc)) {
            if (L010__match(s, sn, si, p, pn, pi + 2))
                return 1;
            sc = L010__access_char_array(s, sn, ++ si);
        }
        return L010__match(s, sn, si, p, pn, pi + 2);
    }
    return L010__judge(sc, pc) && L010__match(s, sn, si + 1, p, pn, pi + 1);
}

//use dp
bool L010__match_dp(char* s, char* p) {
    int sn = strlen(s), pn = strlen(p);
    int si = 0, pi = 0;
    int sic = 0;
    char sc = '\0', pc = '\0';
    char ** dp = (char **) malloc(sizeof(char *) * (sn + 1));
    for (si = 0; si < sn + 1; si ++)
        * (dp + si) = (char *) malloc(sizeof(char) * (pn + 1));
    for (si = 0; si < sn + 1; si ++)                //set default 0
        memset(*(dp + si), 0, pn + 1);              //diff with java
    **dp = 1;                                       //""(p) match ""(s)
    for (si = 0, pi = 0; pi < pn; pi ++) {
        if (*(p + pi) == '*' && *(*(dp + si) + pi - 1)) {
            *(*(dp + si) + pi + 1) = 1;             //how p match ""(s)
        }
    }
    for (si = 0; si < sn; si ++) {
        for (pi = 0; pi < pn; pi ++) {
            if (*(s + si) == *(p + pi) || *(p + pi) == '.') {
                *(*(dp + si + 1) + pi + 1) = *(*(dp + si) + pi);
            } else if (*(p + pi) == '*') {
                if (*(p + pi - 1) != *(s + si) && *(p + pi - 1) != '.') //only use zero
                    *(*(dp + si + 1) + pi + 1) = *(*(dp + si + 1) + pi - 1);
                else
                    *(*(dp + si + 1) + pi + 1) = 
                        *(*(dp + si) + pi + 1) ||       //* use many times
                        *(*(dp + si + 1) + pi) ||       //* use zero times
                        *(*(dp + si + 1) + pi - 1);     //* use one time
            } else {
                *(*(dp + si + 1) + pi + 1) = 0;         //p[0,pi] can not match s[0,si]
            }
        }
    }

    //ans
    sic = *(*(dp + sn) + pn);
    for (si = 0; si < sn + 1; si ++)
        free(*(dp + si));
    free(dp);
    return sic;
}

bool L010_isMatch(char* s, char* p) {
    if (s == NULL || p == NULL) return s == NULL && p == NULL;
    return L010__match(s, strlen(s), 0, p, strlen(p), 0);
}



int L010() {
    
    char *s = "aa";
    char *p = "aa";
    printf("answer is %d\r\n", L010_isMatch(s, p));
    printf("dp answer is %d\r\n", L010__match_dp(s, p));
    return 0;
}