# include <stdio.h>

int linear_search(char *p,int size,char item){
    for (int i = 0; i < size; i++) {
        if(p[i]==item){
            return i;
        }
    }
    return -1;
}