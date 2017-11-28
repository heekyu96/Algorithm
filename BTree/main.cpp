//
// Created by imtt9 on 2017-11-20.
//
#include <iostream>
#include "Btree.h"
using namespace std;


int main(void)
{
    int data;
    int cnt;
    Btree* btree = new Btree;

    cout << "How many numbers do you Insert? : ";
    cin >> cnt;
    for(int i = 0; i < cnt; i++)
    {
        cout << "Enter a number : ";
        cin >> data;
        btree->insert(data);
    }
    cout << "Travers Tree!" << endl;
    btree->traverse();
    return 0;
}