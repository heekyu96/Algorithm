//
// Created by imtt9 on 2017-11-20.
//

#ifndef ALGORITHM_BTREENODE_H
#define ALGORITHM_BTREENODE_H
#define MaxDataCount 5

class BtreeNode {
    int* data;// 노드에 들어갈 자료의 배열입니다
    BtreeNode** childNodes;// 노드의 자식들에 대한 배열입니다.
    bool leaf;//리프노드인지 확인합니다.
    int DataCount; //자료의 개수를 확인합니다.
public:
    BtreeNode();
    void dataSort();
    int *getData() const;

    void setData(int *data);

    BtreeNode **getChildNodes() const;

    void setChildNodes(BtreeNode **childNodes);

    bool isLeaf() const;

    void setLeaf(bool leaf);

    int getDataCount() const;

    void setDataCount(int DataCount);

};


#endif //ALGORITHM_BTREENODE_H
