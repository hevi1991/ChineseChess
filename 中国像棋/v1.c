//
//  v1.c
//  中国像棋
//
//  Created by tarena27 on 15/7/10.
//  Copyright (c) 2015年 tarena. All rights reserved.
//

/*
 零一二三四五六七八9
 一一一一一一一一一十
 車馬象士將士象馬車|零
 十十十十十十十十十|一
 十炮十十十十十炮十|二
 卒十卒十卒十卒十卒|三
 十十十十十十十十十|四
 楚河     汉界
 十十十十十十十十十|五
 兵十兵十兵十兵十兵|六
 十泡十十十十十泡十|七
 十十十十十十十十十|八
 车马相仕帅仕相马车|九
 十
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COLUMN 9
int table[ROW][COLUMN]={0};
int turn=1;
int rOb=1;
//初始化棋盘
void change_set(int x);
void change_set(int x){
    switch (x) {
        case 0:
            printf("十");
            break;
        case 1:
            printf("\033[34m卒\033[0m");
            break;
        case 2:
            printf("\033[31m兵\033[0m");
            break;
        case 3:
            printf("\033[34m烰\033[0m");
            break;
        case 4:
            printf("\033[31m炮\033[0m");
            break;
        case 5:
            printf("\033[34m將\033[0m");
            break;
        case 6:
            printf("\033[31m帥\033[0m");
            break;
        case 7:
            printf("\033[34m士\033[0m");
            break;
        case 8:
            printf("\033[31m仕\033[0m");
            break;
        case 9:
            printf("\033[34m象\033[0m");
            break;
        case 10:
            printf("\033[31m相\033[0m");
            break;
        case 11:
            printf("\033[34m马\033[0m");
            break;
        case 12:
            printf("\033[31m馬\033[0m");
            break;
        case 13:
            printf("\033[34m车\033[0m");
            break;
        case 14:
            printf("\033[31m車\033[0m");
            //        case 1:
            //            printf("卒");
            //            break;
            //        case 2:
            //            printf("兵");
            //            break;
            //        case 3:
            //            printf("烰");
            //            break;
            //        case 4:
            //            printf("炮");
            //            break;
            //        case 5:
            //            printf("將");
            //            break;
            //        case 6:
            //            printf("帥");
            //            break;
            //        case 7:
            //            printf("士");
            //            break;
            //        case 8:
            //            printf("仕");
            //            break;
            //        case 9:
            //            printf("象");
            //            break;
            //        case 10:
            //            printf("相");
            //            break;
            //        case 11:
            //            printf("马");
            //            break;
            //        case 12:
            //            printf("馬");
            //            break;
            //        case 13:
            //            printf("车");
            //            break;
            //        case 14:
            //            printf("車");
            //
        default:
            break;
    }
}
//重置棋盘
void table_reset();
void table_reset(){
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COLUMN; j++) {
            table[i][j]=0;
        }
    }
    table[0][0]=table[0][8]=13; //车
    table[0][1]=table[0][7]=11; //马
    table[0][2]=table[0][6]=9;  //象
    table[0][3]=table[0][5]=7;  //士
    table[0][4]=5;              //將
    table[2][1]=table[2][7]=3;  //烰
    table[3][0]=table[3][2]=table[3][4]=table[3][6]=table[3][8]=1;//卒
    
    table[ROW-1][0]=table[ROW-1][8]=14;   //車
    table[ROW-1][1]=table[ROW-1][7]=12;   //馬
    table[ROW-1][2]=table[ROW-1][6]=10;   //相
    table[ROW-1][3]=table[ROW-1][5]=8;    //仕
    table[ROW-1][4]=6;                    //帥
    table[ROW-3][1]=table[ROW-3][7]=4;      //炮
    table[ROW-4][0]=table[ROW-4][2]=table[ROW-4][4]=table[ROW-4][6]=table[ROW-4][8]=2;//兵
    
}
//输出棋盘
void table_show();
void table_show(){
    printf("  列<-一二三四五六七八九->列\n");
    printf("-------------------------\n");
    for (int i=0; i<ROW; i++) {
        if (i<(ROW-1)) {
            printf(" ");
        }
        printf("%d行<-",i+1);
        for (int j=0; j<COLUMN; j++) {
            change_set(table[i][j]);
            if ((ROW/2-1)==i&&(COLUMN-1)==j) {
                printf("->%d行\n       楚河     汉界  ",i+1);
            }
        }
        if ((ROW/2-1)==i) {
            printf(" ===>第%d回合\n",turn);
        }
        else{
            printf("->%d行\n",i+1);
        }
    }
    printf("-------------------------\n");
    printf("  列<-一二三四五六七八九->列\n");
    
}
//执行游戏
void play(int onrow,int oncolumn,int gorow,int gocolumn);
void play(int onrow,int oncolumn,int gorow,int gocolumn){
    int temp=table[onrow][oncolumn];
    table[onrow][oncolumn]=0;
    table[gorow][gocolumn]=temp;
    table_show();
}
//红手或蓝手判断
bool redOrBlue(int onrow,int oncolumn);
bool redOrBlue(int onrow,int oncolumn){
    if (rOb%2==1) {
        if (table[onrow][oncolumn]%2!=0) {
            printf("请选择帥方的阵营棋子\n");
            return false;
        }
        else{
            return true;
        }
    }
    else if (rOb%2==0){
        if (table[onrow][oncolumn]%2!=1) {
            printf("请选择將方的阵营棋子\n");
            return false;
        }
        else{
            return true;
        }
    }
    return 0;
}

//规则
bool rule(int onrow,int oncolumn,int gorow,int gocolumn);
bool rule(int onrow,int oncolumn,int gorow,int gocolumn){
    if (onrow>=ROW||gorow>=ROW||oncolumn>=COLUMN||gocolumn>=COLUMN) {//上越界错误
        printf("选择错误,请重新输入!\n");
        return false;
    }
    if (onrow<0||gorow<0||oncolumn<0||gocolumn<0) {//下越界错误
        printf("选择错误,请重新输入!\n");
        return false;
    }
    if (onrow==gorow&&oncolumn==gocolumn) {//重复
        printf("重复错误,请重新输入!\n");
        return false;
    }
    if (table[onrow][oncolumn]==0) {
        printf("这里没有棋子,请重新输入\n");
        return false;
    }
    if ((table[onrow][oncolumn]-table[gorow][gocolumn])%2==0&&table[gorow][gocolumn]!=0) {
        printf("友军中枪,请重新输入!\n");
        return false;
    }
    //用车错误
    if (table[onrow][oncolumn]==13||table[onrow][oncolumn]==14) {
        if (gorow!=onrow&&gocolumn!=oncolumn) {
            printf("输入错误,请重新输入!\n");
            return false;
        }
        if (oncolumn==gocolumn) {//列相同
            if (gorow>onrow) {
                for (int i=onrow+1; i<gorow; i++) {
                    if ((((table[i][oncolumn]-table[i][gocolumn])%2==0)||((table[i][oncolumn]-table[i][gocolumn])%2==1))&&table[i][gocolumn]!=0) {
                        printf("撞车了,所以请重新输入\n");
                        return false;
                    }
                }
            }
            else if (onrow>gorow){
                for (int i=gorow+1; i<onrow; i++) {
                    if (((table[i][oncolumn]-table[i][gocolumn])%2==0||(table[i][oncolumn]-table[i][gocolumn])%2==1)&&table[i][gocolumn]!=0) {
                        printf("撞车了,所以请重新输入\n");
                        return false;
                    }
                }
            }
        }
        if (onrow==gorow) {
            if (gocolumn>oncolumn) {
                for (int i=oncolumn+1; i<gocolumn; i++) {
                    if (((table[onrow][i]-table[gorow][i])%2==0||(table[onrow][i]-table[gorow][i])%2==1)&&table[gorow][i]!=0) {
                        printf("撞车,所以请重新输入\n");
                        return false;
                    }
                }
            }
            else if (oncolumn>gocolumn){
                for (int i=gocolumn+1; i<oncolumn; i++) {
                    if (((table[onrow][i]-table[gorow][i])%2==0||(table[onrow][i]-table[gorow][i])%2==1)&&table[gorow][i]!=0) {
                        printf("撞车了,所以请重新输入\n");
                        return false;
                    }
                }
            }
        }
    }
    //用兵错误
    if (table[onrow][oncolumn]==1||table[onrow][oncolumn]==2) {
        if (table[onrow][oncolumn]==1) {
            if (gorow-onrow>1) {
                printf("你小兵会飞啊,请重新输入\n");
                return false;
            }
            if (onrow<=4&&gocolumn-oncolumn!=0) {
                printf("没过河,怎么横着走呢\n");
                return false;
            }
            if (gorow<onrow) {
                printf("当了兵还想回打完仗回老家结婚啊,请重新输入\n");
                return false;
            }
            if (gocolumn-oncolumn>1||oncolumn-gocolumn>1) {
                printf("过了河也不能飞啊,请重新输入\n");
                return false;
            }
        }
        if (table[onrow][oncolumn]==2) {
            if (onrow-gorow>1) {
                printf("你小兵会飞啊,请重新输入\n");
                return false;
            }
            if (onrow>=5&&gocolumn-oncolumn!=0) {
                printf("没过河,怎么横着走呢\n");
                return false;
            }
            if (onrow<gorow) {
                printf("当了兵还想回打完仗回老家结婚啊,请重新输入\n");
                return false;
            }
            if (gocolumn-oncolumn>1||oncolumn-gocolumn>1) {
                printf("过了河也不能飞啊,请重新输入\n");
                return false;
            }
        }
    }
    //用马错误
    if (table[onrow][oncolumn]==11||table[onrow][oncolumn]==12) {
        if (gorow==onrow+2||gorow==onrow-2||gocolumn==oncolumn+2||gocolumn==oncolumn-2) {
            if (gorow==onrow+2) {
                if (gocolumn==oncolumn+1&&table[gorow-1][oncolumn]==0) {
                    return true;
                }
                if (gocolumn==oncolumn-1&&table[gorow-1][oncolumn]==0) {
                    return true;
                }
                else{
                    printf("卡马脚了,请重新输入\n");
                    return false;
                }
            }
            if (gorow==onrow-2) {
                if (gocolumn==oncolumn+1&&table[gorow+1][oncolumn]==0) {
                    return true;
                }
                if (gocolumn==oncolumn-1&&table[gorow+1][oncolumn]==0) {
                    return true;
                }
                else{
                    printf("卡马脚了,请重新输入\n");
                    return false;
                }
            }
            if (gocolumn==oncolumn+2) {
                if (gorow==onrow+1&&table[onrow][gocolumn+1]==0) {
                    return true;
                }
                if (gorow==onrow-1&&table[onrow][gocolumn+1]==0) {
                    return true;
                }
                else{
                    printf("卡马脚了,请重新输入\n");
                    return false;
                }
                
            }
            if (gocolumn==oncolumn-2) {
                if (gorow==onrow+1&&table[onrow][gocolumn-1]==0) {
                    return true;
                }
                if (gorow==onrow-1&&table[onrow][gocolumn-1]==0) {
                    return true;
                }
                else{
                    printf("卡马脚了,请重新输入\n");
                    return false;
                }
                
            }
        }
        else{
            printf("马输入错误\n");
            return false;
        }
        
    }
    //用象错误
    if (table[onrow][oncolumn]==9||table[onrow][oncolumn]==10) {
        if (table[onrow][oncolumn]==9) {
            if (gorow>4) {
                printf("过河失败,请重新输入\n");
                return false;
            }
            if (gorow==onrow+2) {
                if (gocolumn==oncolumn+2&&table[onrow+1][oncolumn+1]==0) {
                    return true;
                }
                else if (gocolumn==oncolumn-2&&table[onrow+1][oncolumn-1]==0){
                    return true;
                }
                else{
                    printf("被绊倒了\n");
                    return false;
                }
            }
            if (gorow==onrow-2) {
                if (gocolumn==oncolumn+2&&table[onrow-1][oncolumn+1]==0) {
                    return true;
                }
                else if (gocolumn==oncolumn-2&&table[onrow-1][oncolumn-1]==0){
                    return true;
                }
                else{
                    printf("被绊倒了\n");
                    return false;
                }
            }
            else{
                printf("象输入错误\n");
                return 0;
            }
        }
        if (table[onrow][oncolumn]==10) {
            if (gorow<5) {
                printf("过河失败,请重新输入\n");
                return false;
            }
            if (gorow==onrow+2) {
                if (gocolumn==oncolumn+2&&table[onrow+1][oncolumn+1]==0) {
                    return true;
                }
                else if (gocolumn==oncolumn-2&&table[onrow+1][oncolumn-1]==0){
                    return true;
                }
                else{
                    printf("被绊倒了\n");
                    return false;
                }
            }
            if (gorow==onrow-2) {
                if (gocolumn==oncolumn+2&&table[onrow-1][oncolumn+1]==0) {
                    return true;
                }
                else if (gocolumn==oncolumn-2&&table[onrow-1][oncolumn-1]==0){
                    return true;
                }
                else{
                    printf("被绊倒了\n");
                    return false;
                }
            }
            else{
                printf("相输入错误\n");
                return 0;
            }
            
        }
        
    }
    //用士错误
    if (table[onrow][oncolumn]==7||table[onrow][oncolumn]==8) {
        if (table[onrow][oncolumn]==7) {
            if (gorow>2||gocolumn<3||gocolumn>6) {
                printf("越界啦\n");
                return false;
            }
            if (gorow+1==onrow||gorow-1==onrow) {
                if (gocolumn+1==oncolumn) {
                    return true;
                }
                else if (gocolumn-1==oncolumn) {
                    return true;
                }
                else{
                    printf("用士错误\n");
                    return false;
                }
            }
            else{
                printf("不按规则做事的士\n");
                return false;
            }
        }
        if (table[onrow][oncolumn]==8) {
            if (gorow<7||gocolumn<3||gocolumn>6) {
                printf("越界啦\n");
                return false;
            }
            if (gorow+1==onrow||gorow-1==onrow) {
                if (gocolumn+1==oncolumn) {
                    return true;
                }
                else if (gocolumn-1==oncolumn) {
                    return true;
                }
                else{
                    printf("用仕错误\n");
                    return false;
                }
            }
            else{
                printf("不按规则做事的仕\n");
                return false;
            }
        }
    }
    //用将错误
    if (table[onrow][oncolumn]==5||table[onrow][oncolumn]==6) {
        if (table[onrow][oncolumn]==5) {
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
            if (gorow==redKingOnRow) {
                int i;
                for (i=onrow+1; i<redKingOnRow; i++) {
                    if (table[i][oncolumn]!=0) {
                        printf("飞不起来,前面有墙\n");
                        return false;
                    }
                }
                if (i==redKingOnRow) {
                    return true;
                }
            }
            if (gorow>2||gocolumn>5||gocolumn<3) {
                printf("將军越界\n");
                return false;
            }
            if (gorow>onrow) {
                if (gorow-onrow==1&&gocolumn==oncolumn) {
                    return true;
                }
                else{
                    printf("起飞失败\n");
                    return false;
                }
            }
            if (gorow<onrow) {
                if (onrow-gorow==1&&gocolumn==oncolumn) {
                    return true;
                }
                else{
                    printf("起飞失败\n");
                    return false;
                }
                
            }
            if (gocolumn>oncolumn) {
                if (gocolumn-oncolumn==1&&gorow==onrow) {
                    return true;
                }
                else{
                    printf("起飞失败\n");
                    return false;
                }
                
            }
            if (gocolumn<oncolumn) {
                if (oncolumn-gocolumn==1&&gorow==onrow) {
                    return true;
                }
                else{
                    printf("起飞失败\n");
                    return false;
                }
                
            }
            else{
                printf("起飞失败\n");
                return false;
            }
        }
        if (table[onrow][oncolumn]==6) {
            int blueKingOnRow=0;
            int blueKingOnColumn=0;
            for (int i=0; i<10; i++) {
                for (int j=0; j<9; j++) {
                    if (table[i][j]==5) {
                        blueKingOnRow=i;
                        blueKingOnColumn=j;
                        break;
                    }
                }
            }
            if (gorow==blueKingOnRow) {
                int i;
                for (i=onrow-1; i>blueKingOnRow; i--) {
                    if (table[i][oncolumn]!=0) {
                        printf("飞不起来,前面有墙\n");
                        return false;
                    }
                }
                if (i==blueKingOnRow) {
                    return true;
                }
            }
            if (gorow<7||gocolumn>5||gocolumn<3) {
                printf("帥军越界\n");
                return false;
            }
            if (gorow>onrow) {
                if (gorow-onrow==1&&gocolumn==oncolumn) {
                    return true;
                }
                else{
                    printf("起飞失败\n");
                    return false;
                }
            }
            if (gorow<onrow) {
                if (onrow-gorow==1&&gocolumn==oncolumn) {
                    return true;
                }
                else{
                    printf("起飞失败\n");
                    return false;
                }
                
            }
            if (gocolumn>oncolumn) {
                if (gocolumn-oncolumn==1&&gorow==onrow) {
                    return true;
                }
                else{
                    printf("起飞失败\n");
                    return false;
                }
                
            }
            if (gocolumn<oncolumn) {
                if (oncolumn-gocolumn==1&&gorow==onrow) {
                    return true;
                }
                else{
                    printf("起飞失败\n");
                    return false;
                }
                
            }
            else{
                printf("起飞失败\n");
                return false;
            }
        }
    }
    //用炮错误
    if (table[onrow][oncolumn]==3||table[onrow][oncolumn]==4) {
        int bomCount=0;
        if(table[gorow][gocolumn]!=0){
            if (gocolumn==oncolumn) {
                if (gorow>onrow) {
                    for (int i=onrow+1; i<gorow; i++) {
                        if (table[i][gocolumn]>0) {
                            bomCount++;
                        }
                    }
                    if (bomCount!=1) {
                        printf("bom不过去啊\n");
                        return false;
                    }
                }
                if (onrow>gorow) {
                    for (int i=onrow-1; i>gorow; i--) {
                        if (table[i][gocolumn]>0) {
                            bomCount++;
                        }
                    }
                    if (bomCount!=1) {
                        printf("bom不过去啊\n");
                        return false;
                    }
                }
            }
            else if (gorow==onrow) {
                if (gocolumn>oncolumn) {
                    for (int i=oncolumn+1; i<gocolumn; i++) {
                        if (table[gorow][i]>0) {
                            bomCount++;
                        }
                    }
                    if (bomCount!=1) {
                        printf("bom不过去啊\n");
                        return false;
                    }
                }
                if (oncolumn>gocolumn) {
                    for (int i=oncolumn-1; i>gocolumn; i--) {
                        if (table[gorow][i]>0) {
                            bomCount++;
                        }
                    }
                    if (bomCount!=1) {
                        printf("bom不过去啊\n");
                        return false;
                    }
                }
            }
        }
        else if (table[gorow][gocolumn]==0){
            if (gorow==onrow) {
                if (gocolumn>oncolumn) {
                    for (int i=oncolumn+1; i<gocolumn; i++) {
                        if (table[gorow][i]>0) {
                            printf("打炮错误\n");
                            return false;
                        }
                    }
                }
                else if (oncolumn>gocolumn){
                    for (int i=oncolumn-1; i>gocolumn; i--) {
                        if (table[gorow][i]>0) {
                            printf("打炮错误\n");
                            return false;
                        }
                    }
                }
            }
            else if (gocolumn==oncolumn) {
                if (gorow>onrow) {
                    for (int i=onrow+1; i<gorow; i++) {
                        if (table[i][gocolumn]>0) {
                            printf("打炮错误\n");
                            return false;
                        }
                    }
                }
                else if (onrow>gorow){
                    for (int i=onrow-1; i>gorow; i--) {
                        if (table[i][gocolumn]>0) {
                            printf("打炮错误\n");
                            return false;
                        }
                    }
                }
            }
            
        }
    }
    return true;
}
//判定胜利
void winner();
void winner(){
    int redKingCount=0;
    int blueKingCount=0;
    for (int i=0; i<10; i++) {
        for (int j=0; j<9; j++) {
            if(table[i][j]==6) {
                redKingCount++;
            }
            if(table[i][j]==5){
                blueKingCount++;
            }
        }
    }
    if (redKingCount==0) {
        printf("將的胜利!\n");
        exit(0);
    }
    else if (blueKingCount==0){
        printf("帥的胜利!\n");
        exit(0);
    }
}
int main(int argc, const char * argv[]) {
    int onRow;
    int onColumn;
    int goRow;
    int goColumn;
    table_reset();
    table_show();
    printf("\n");
    
    while (1) {
        printf("第%d回合:\n",turn);
    Save:
        if (rOb%2==1) {
            printf("红方,");
        }
        else {
            printf("蓝方,");
        }
        
        printf("请输入你想选择的棋子所在位置(行,列):\n");
        scanf("%d,%d",&onRow,&onColumn);
        onRow--;onColumn--;
        if (!redOrBlue(onRow, onColumn)) {
            table_show();
            goto Save;
        }
        printf("请输入你想让它去的位置(行,列):\n");
        scanf("%d,%d",&goRow,&goColumn);
        goRow--;goColumn--;
        
        if (!(rule(onRow, onColumn, goRow, goColumn))) {
            table_show();
            goto Save;
        }
        play(onRow, onColumn, goRow, goColumn);
        winner();
        if (rOb%2==0) {
            turn++;
        }
        rOb++;
    }
    
    
    return 0;
}
