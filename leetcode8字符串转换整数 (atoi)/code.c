#include <limits.h>

int myAtoi(char * s){
    if (s == NULL) {
        return 0;
    }
    int data = 0;
    int fuhao = 1;
    char *str = s;
    while (*str != '\0' && *str == ' ') {
        str++;
    }
    if (*str == '\0') {
        return data;
    }
    if (*str == '+') {
        str++;
    } else if (*str == '-') {
        fuhao = -1;
        str++;
    }
    int tmpdata = 0;
    while (*str >= '0' && *str <= '9') {
        tmpdata = *str - '0';
        if (fuhao == 1) {
            if ((data > INT_MAX/10) || (data == INT_MAX/10 && tmpdata > INT_MAX % 10)) {
                return INT_MAX;
            }
        } else {
            if ((data < INT_MIN/10) || 
                (data  == INT_MIN/10 && tmpdata * fuhao < INT_MIN % 10)) {
                return INT_MIN;
            }
        }
        data = data * 10 + tmpdata * fuhao;
        str++;
    }
    return data;
}