#ifndef PROCESS_H
#define PROCESS_H

class Process {              //状态压缩矩阵的结点，用于寻找路径
public:
    int distance;
    int pre{-1};
    int now{-1};
    int next{-1};
};

#endif // PROCESS_H
