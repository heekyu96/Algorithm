//
// Created by imtt9 on 2017-11-20.
//

#include "Btree.h"

Btree::Btree() {
    this->root = nullptr;
}

int Btree::splitChild(BtreeNode *cur, int position) {
//    분할된 형태는 다음과 같다.
//    cur -> 왼쪽으로 가고
//    right -> 그 오른쪽으로 가고
//    parent -> cur와 right의 부모 노드가 됩니다.
    // cur노드를 분할하여 np1과 right을 할당합니다.
    int mid;
    BtreeNode *parent;
    BtreeNode *right;
    BtreeNode *temp;;

    /*
     분할된 형태는 다음과 같습니다.
     cur -> 왼쪽으로 가고
     right -> 그 오른쪽으로 가고
     parent -> cur와 right의 부모 노드가 됩니다.
    */

    right = new BtreeNode;
    right->setLeaf(true);

    // cur의 부모 노드가 없어 새롭게 부모 노드를 만들어주는 경우입니다.
    if (position == -1) {

        // MaxDataCount의 중간값을 기준으로 분할합니다.
        mid = cur->getData()[MaxDataCount / 2];
        cur->getData()[MaxDataCount / 2] = 0;
        cur->setDataCount(cur->getDataCount() - 1);
        parent = new BtreeNode;

        // parent는 부모노드이므로 리프 노드가 아닙니다.
        parent->setLeaf(false);
        cur->setLeaf(true);
        for (int j = MaxDataCount / 2 + 1; j < MaxDataCount; j++) {

            // right는 cur의 오른쪽 부분 노드를 가져갑니다.
            right->getData()[j - (MaxDataCount / 2 + 1)] = cur->getData()[j];
            right->getChildNodes()[j - (MaxDataCount / 2 + 1)] = cur->getChildNodes()[j];
            right->setDataCount(right->getDataCount() + 1);

            // cur는 반 쪼개서 왼쪽 부분 노드만 가지고 갑니다.
            cur->getData()[j] = 0;
            cur->setDataCount(cur->getDataCount() - 1);
        }

        // cur의 모든 자식 노드를 NULL로 만듭니다.
        for (int j = 0; j < MaxDataCount + 1; j++) {
            cur->getChildNodes()[j] = nullptr;
        }
        parent->getData()[0] = mid;
        parent->getChildNodes()[parent->getDataCount()] = cur;
        parent->getChildNodes()[parent->getDataCount() + 1] = right;
        parent->setDataCount(parent->getDataCount() + 1);

        // 루트 노드로 설정해줍니다.
        root = parent;
    } else // 이미 부모 노드가 있는 경우입니다.
    {
        temp = cur->getChildNodes()[position];
        mid = temp->getData()[MaxDataCount / 2];
        temp->getData()[MaxDataCount / 2] = 0;
        temp->setDataCount(temp->getDataCount() - 1);
        for (int j = (MaxDataCount / 2) + 1; j < MaxDataCount; j++) {

            // right은 cur의 오른쪽 자식 부분만 가져갑니다.
            right->getData()[j - (MaxDataCount / 2 + 1)] = temp->getData()[j];
            right->setDataCount(right->getDataCount() + 1);
            temp->getData()[j] = 0;
            temp->setDataCount(temp->getDataCount() - 1);
        }
        cur->getChildNodes()[position + 1] = temp;
        cur->getChildNodes()[position + 1] = right;
    }
    return mid;

}

void Btree::insert(int data) {
    int i, temp;
    BtreeNode *cur = root;

    // 만약에 루트 노드가 NULL이라면
    if (cur == nullptr) {
        root = new BtreeNode;
        cur = root;
    } else // 루트 노드가 NULL이 아니라면
    {

        // 현재 리프노드이고 크기가 꽉찼다면
        if (cur->isLeaf() == true && cur->getDataCount() == MaxDataCount) {
            temp = splitChild(cur, -1);
            cur = root;

            // 값을 이동하며 삽입될 자리를 찾습니다.
            for (i = 0; i < (cur->getDataCount()); i++) {
                if ((data > cur->getData()[i]) && (data < cur->getData()[i + 1])) {
                    i++;
                    break;
                } else if (data < cur->getData()[0]) {
                    break;
                } else {
                    continue;
                }
            }
            cur = cur->getChildNodes()[i];
        }

            // 리프노드가 아닐 때입니다.
        else {

            // 리프 노드까지 이동합니다.
            while (cur->isLeaf() == false) {
                for (i = 0; i < (cur->getDataCount()); i++) {
                    if ((data > cur->getData()[i]) && (data < cur->getData()[i + 1])) {
                        i++;
                        break;
                    } else if (data < cur->getData()[0]) {
                        break;
                    } else {
                        continue;
                    }
                }

                // 리프 노드 위에서도 만약에 최대치를 넘으면 분할해줍니다.
                if ((cur->getChildNodes()[i])->getDataCount() == MaxDataCount) {
                    temp = splitChild(cur, i);
                    cur->getData()[cur->getDataCount()] = temp;
                    cur->setDataCount(cur->getDataCount() + 1);
                    continue;
                } else {
                    cur = cur->getChildNodes()[i];
                }
            }
        }
    }
    cur->getData()[cur->getDataCount()] = data;
    cur->dataSort();
    cur->setDataCount(cur->getDataCount() + 1);
}

void Btree::traverse() {
    traverse(root);
}

void Btree::traverse(BtreeNode *btreeNode) {
    cout << endl;
    int i;
    // 즉, 첫번째 자식 노드부터 가장 마지막 자식 노드까지 전부 밑으로 내려가는 것입니다.
    for (i = 0; i < btreeNode->getDataCount(); i++) {
        // 리프 노드가 아니라면 더 밑으로 내려갑니다.
        if (btreeNode->isLeaf() == false) {
            traverse(btreeNode->getChildNodes()[i]);
        }
        // 데이터를 출력합니다.
        cout << " ";
        cout << btreeNode->getData()[i];
    }
    // 리프 노드가 아니라면 더 밑으로 내려갑니다.
    if (btreeNode->isLeaf() == false) {
        traverse(btreeNode->getChildNodes()[i]);
    }
    cout << endl;
}
