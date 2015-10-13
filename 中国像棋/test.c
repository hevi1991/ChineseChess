//
//  test.c
//  中国像棋
//
//  Created by tarena27 on 15/7/10.
//  Copyright (c) 2015年 tarena. All rights reserved.
//

#include <stdio.h>

int main(){
//    char a[]="帅";
//    printf("%ld\n",sizeof(a));
//    printf("\033[31mHELLO\033[0mWORLD\n");
//
    int table[10][9]={0};
    table[5][7]=6;
    int redKingOnRow=0;
    int redKingOnColumn=0;
    for (int i=0; i<10; i++) {
        for (int j=0; j<9; j++) {
            if (table[i][j]==6) {
                redKingOnRow=i;
                redKingOnColumn=j;
                break;
            }
        }
    }
    printf("redKingOnRow:%d\n",redKingOnRow);
    printf("redKingOnColumn:%d\n",redKingOnColumn);
    
    
    
    
    
    return 0;
}