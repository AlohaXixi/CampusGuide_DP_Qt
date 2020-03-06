#include <iostream>
#include <cmath>
#include "tsp.h"
#include "process.h"
#include <QDebug>
using namespace std;

TSP::TSP(int map[allPlaceNum][allPlaceNum]) {
    /*cout << "请输入你选择的城市序号，以0结束:" << endl;
    int k=0;
    int x;
    cin >> x;
    while (x != 0) {
        selectedPlace[k] = x-1;      //存储的是序号对应成功时的下标
        k++;
        cin >> x;
    }
    selectedPlaceNum = k;*/

    int i, j;                                       //初始化所选择景点的距离矩阵
    matrix = (int**)new int* [selectedPlaceNum];
    for (i = 0; i < selectedPlaceNum; i++)
        matrix[i] = new int[selectedPlaceNum];
    for(i=0;i<selectedPlaceNum;i++)
        for (j = 0; j < selectedPlaceNum; j++) {
            matrix[i][j] = map[selectedPlace[i]][selectedPlace[j]];
        }

    dp = new Process* [selectedPlaceNum];
    for (int i = 0; i < selectedPlaceNum; i++) {
        dp[i] = new Process[1 << (selectedPlaceNum - 1)];
    }
}

void TSP::printSelectedPlace() {

    cout << "您选择的景点距离矩阵如下：" << endl;
    for (int i = 0; i < selectedPlaceNum; i++) {
        for (int j = 0; j < selectedPlaceNum; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void TSP::getShortestDistance() {
    int i, j, k;
    //初始化第一列
    for (i = 0; i < selectedPlaceNum; i++)
    {
        dp[i][0].distance = matrix[i][0];
        dp[i][0].pre = i;
        dp[i][0].now = 0;
    }
    //初始化剩余列
    for (j = 1; j < (1 << (selectedPlaceNum - 1)); j++)
    {
        for (i = 0; i < selectedPlaceNum; i++)
        {
            dp[i][j].distance = 0x7ffff;//设0x7ffff为无穷大

            //对于数字x，要看它的第i位是不是1，通过判断布尔表达式 (((x >> (i - 1) ) & 1) == 1的真值来实现

            if (((j >> (i - 1)) & 1) == 1)
            {
                continue;
            }
            for (k = 1; k < selectedPlaceNum; k++)
            {
                //不能达到k城市
                if (((j >> (k - 1)) & 1) == 0)
                {
                    continue;
                }
                if (dp[i][j].distance > matrix[i][k] + dp[k][j ^ (1 << (k - 1))].distance)
                {
                    dp[i][j].distance = matrix[i][k] + dp[k][j ^ (1 << (k - 1))].distance;
                    dp[i][j].pre = i;
                    dp[i][j].now = k;
                    dp[i][j].next = j ^ (1 << (k - 1));

                }
            }
        }
    }
    cout << "最短路径为" << dp[0][(1 << (selectedPlaceNum - 1)) - 1].distance << endl;
    cout << endl;

}


void TSP::getRoute() {
    fp.open("route.txt", ios::out | ios::in);
    int i = 0,j= (1 << (selectedPlaceNum - 1)) - 1;
    int temp_i, temp_j;
    double each_time = 0;
    for (int k = 0; k < selectedPlaceNum ; k++) {
        route.push(dp[i][j].pre);
        each_time = matrix[dp[i][j].pre][dp[i][j].now] / (velocity*1.0);
        time.push(each_time);
        temp_i = dp[i][j].now;
        temp_j = dp[i][j].next;
        i = temp_i;
        j = temp_j;
    }

    cout << "具体路径为：" << endl;
    while (!route.empty()) {
        int x = route.front();
        route.pop();
        cout << selectedPlace[x]+1 << " -> ";
        fp << selectedPlace[x] + 1 << " -> ";
    }
    cout << selectedPlace[0]+1<<endl;
    fp << selectedPlace[0] + 1 << endl;
    cout << endl;
    fp.close();

    cout << "景点两两之间的用时为(单位为分钟)：" << endl;
    while (!time.empty()) {
        double t = time.front();
        time.pop();
        cout << t << "  ";
    }
    cout << endl;
}













