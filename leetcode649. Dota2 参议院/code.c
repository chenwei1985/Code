#include <string.h>
char * predictPartyVictory(char * senate){
    if (senate == NULL) {
        return NULL;
    }
    int len = strlen(senate);
    if (len == 0) {
        return NULL;
    }
    int dataR[2*len];
    int dataD[2*len];
    int rightR = 0;
    int rightD = 0;
    int i = 0;
    for (i = 0;i < len; ++i) {
        if (*(senate + i) == 'R') {
            dataR[rightR++] = i;
        } else if (*(senate + i) == 'D') {
            dataD[rightD++] = i;
        }
    }
    int leftR = 0;
    int leftD = 0;
    while (leftR < rightR && leftD < rightD) {
        if (dataR[leftR] < dataD[leftD]) {
            dataR[rightR++] = i++;
            leftR++;
            leftD++;
        } else {
            dataD[rightD++] = i++;
            leftD++;
            leftR++;
        }
    }
    char *ret = (char*)malloc(8);
    if (ret == NULL) {
        return NULL;
    }
    if (leftR < rightR) {
        memcpy(ret, "Radiant", 8);
    } else {
        memcpy(ret, "Dire", 5);
    }
    return ret;
}