//
// Created by imtt9 on 2017-11-20.
//

#include "BtreeNode.h"

BtreeNode::BtreeNode() {
    this->data = new int[MaxDataCount];// M개까지의 데이터를 가질 수 있습니다.
    this->childNodes = new BtreeNode*[MaxDataCount+1];// M + 1개의 자식 노드입니다.
    this->leaf= true;// 기본적으로 리프 노드입니다
    this->DataCount=0;// 자료의 개수는 0개입니다.
    for (int i = 0; i <MaxDataCount+1 ; i++) {
        this->childNodes[i]= nullptr;
    }
}

void BtreeNode::dataSort() {
    for(int i= 0;i<this->DataCount;i++){
        for(int j=0;j<=this->DataCount;j++){
            if(this->data[i]>this->data[j]){
                int temp = this->data[i];
                this->data[i]=this->data[j];
                this->data[j]=temp;
            }
        }
    }

}

int *BtreeNode::getData() const {
    return data;
}

void BtreeNode::setData(int *data) {
    BtreeNode::data = data;
}

BtreeNode **BtreeNode::getChildNodes() const {
    return childNodes;
}

void BtreeNode::setChildNodes(BtreeNode **childNodes) {
    BtreeNode::childNodes = childNodes;
}

int BtreeNode::getDataCount() const {
    return DataCount;
}

void BtreeNode::setDataCount(int DataCount) {
    BtreeNode::DataCount = DataCount;
}

bool BtreeNode::isLeaf() const {
    return leaf;
}

void BtreeNode::setLeaf(bool leaf) {
    BtreeNode::leaf = leaf;
}
