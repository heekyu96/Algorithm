//
// Created by imtt9 on 2017-11-20.
//

#ifndef ALGORITHM_BTREE_H
#define ALGORITHM_BTREE_H

#include <iostream>
#include "BtreeNode.h"
using namespace std;

class Btree {
    BtreeNode* root;

    int splitChild(BtreeNode* cur,int position);
    void traverse(BtreeNode* btreeNode);
public:
    Btree();
    void insert(int data);
    void traverse();

};


#endif //ALGORITHM_BTREE_H

