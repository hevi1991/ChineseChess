//
//  main.c
//  中国像棋
//
//  Created by tarena27 on 15/7/10.
//  Copyright (c) 2015年 tarena. All rights reserved.
//
/*
 零一二三四五六七八
 一一一一一一一一一十
 車馬象士將士象馬車|零
 十十十十十十十十十|一
 十炮十十十十十炮十|二
 卒十卒十卒十卒十卒|三
 十十十十十十十十十|四
 一一一一一一一一一|五
 楚河     汉界
 一一一一一一一一一|六
 十十十十十十十十十|七
 兵十兵十兵十兵十兵|八
 十泡十十十十十泡十|九
 十十十十十十十十十|十
 车马相仕帅仕相马车|十一
 */
#include <stdio.h>
char* table[12][9];
void table_set();
void table_set(){
    for (int i=0; i<12; i++) {
        for (int j=0; j<9; j++) {
            table[i][j]="十";
            if (i==5||i==6) {
                table[i][j]="一";
            }
        }
        table[0][0]=table[0][8]="車";
        table[0][1]=table[0][7]="馬";
        table[0][2]=table[0][6]="象";
        table[0][3]=table[0][5]="士";
        table[0][4]="將";
        table[2][1]=table[2][7]="炮";
        table[3][0]=table[3][2]=table[3][4]=table[3][6]=table[3][8]="卒";
        
        table[11][0]=table[11][8]="车";
        table[11][1]=table[11][7]="马";
        table[11][2]=table[11][6]="相";
        table[11][3]=table[11][5]="仕";
        table[11][4]="帅";
        table[9][1]=table[9][7]="泡";
        table[8][0]=table[8][2]=table[8][4]=table[8][6]=table[8][8]="兵";
        
    }
    for (int i=0; i<12; i++) {
        for (int j=0; j<9; j++) {
            
            printf("%s",table[i][j]);
            if (5==i&&8==j) {
                printf("\n  楚河     汉界  ");
            }
        }
        printf("\n");

    }


}
void chess_set();
void chess_set(){


}

int main(int argc, const char * argv[]) {
    table_set();
    
    return 0;
}
