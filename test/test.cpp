/**
 * @file test.cpp
 * @author hefvcjm (hef1995@qq.com)
 * @brief test bintree view
 * @version 0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "bintree_view.h"
#include <stdlib.h>
#include <time.h> 
#include <queue>

using namespace std;

struct BinTree
{
    int val;
    BinTree* left;
    BinTree* right;
    BinTree(int x): val(x), left(NULL), right(NULL){}
    ~BinTree(){
        if(left){
            delete left;
        }
        if(right){
            delete right;
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    BinTree tree(0);
    queue<BinTree*> q;
    q.push(&tree);
    int n = 20;
    vector<BinTree*> highlight_nodes;
    for(int i = 0; i < n; i++){
        if(!q.empty()){
            q.front()->left = new BinTree(rand() % 200);
            i++;
            if(i < n){
                q.front()->right = new BinTree(rand() % 200);
            }
            q.push(q.front()->left);
            q.push(q.front()->right);
            if(rand() % 5 == 0){
                highlight_nodes.push_back(q.front());
            }
        }
        q.pop();
    }
    view_tree<BinTree>(tree);
    view_tree<BinTree>(tree, highlight_nodes);
    return 0;
}

 


