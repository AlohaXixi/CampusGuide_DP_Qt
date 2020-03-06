#ifndef TSP_H
#define TSP_H
#include "process.h"
#include <queue>
#include <fstream>
#include <iostream>

#define allPlaceNum 15
#define velocity 70     //人正常的步行速度 70m/min
using namespace std;

class TSP {
private:
    int** matrix;                   //所选地点之间距离  用二维矩阵存储
    Process** dp;                         //状态压缩矩阵

public:
    int selectedPlace[allPlaceNum]{0};    //用于记录已选择的地点序号 便于后续赋值和行走路径地点确认
    int selectedPlaceNum{0};			//所选地点个数
    queue <int> route;                   //保存具体路径
    queue <double> time;                  //保存两两景点间步行所需时间
    fstream fp;

    TSP(int map[allPlaceNum][allPlaceNum]);
    void printSelectedPlace();           //打印matrix矩阵（已选择景点的距离矩阵）
    void getShortestDistance();         //动态规划求最短路径距离
    void getRoute();                    //求具体路径
};
#endif // TSP_H
