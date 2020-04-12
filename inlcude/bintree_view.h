/**
 * @file bintree_view.h
 * @author hefvcjm (hef1995@qq.com)
 * @brief visualize bintree tool
 * @version 0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef __BINTREE_VIEW_H__
#define __BINTREE_VIEW_H__

#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Use graphviz to visualize dot language string
 * 
 * @param dot_string: dot language string
 */
void view_dot_graph(const char *dot_string);

/**
 * @brief generate dot string according to the bintree
 * 
 * @tparam T: bintree class
 *         class T should have public attributions as follow:
 *         val: node data
 *         left: left node, pointer to T
 *         right: right node, pointer to T
 * @param tree: bintree reference
 * @param highlight_nodes: tree node pointers which will be highlight
 */
template<typename T>
void view_tree(const T& tree, vector<T*> highlight_nodes={}){
    using NodeType = T;
    string highlight_format = "[shape=box, style=filled, fillcolor=red];";
    stringstream dot_string;
    dot_string << "digraph graphname { node [shape=box]; " << "edge [arrowhead=vee];";
    queue<pair<int, const NodeType*>> q;
    int i = 0;
    q.push(make_pair(i, &tree));
    dot_string << i << " [label=\"" << tree.val << "\"];";
    auto placeholder = [&i, &dot_string, &q](int group=-1){
        i++;
        if(group != -1){
            dot_string << i << " [label=\"\", width=0.1, style=invis, group=" << group << "];";
        }else{
            dot_string << i << " [label=\"\", width=0.1, style=invis];";
        }
        dot_string << q.front().first << " -> " << i << " [style=invis];";
    };
    while(!q.empty()){
        if(q.front().second->left == NULL && q.front().second->right == NULL){
            q.pop();
            continue;
        }
        if(q.front().second->left){
            i++;
            q.push(make_pair(i, q.front().second->left));
            dot_string << i << " [label=\"" << q.front().second->left->val << "\" group=" << i << "];";
            if(find(highlight_nodes.begin(),highlight_nodes.end(), q.front().second->left) != highlight_nodes.end()){
                dot_string << i << " " << highlight_format;
            }
            dot_string << q.front().first << " -> " << i << ";";
        }else{
            placeholder();
        }
        placeholder(q.front().first);
        if(q.front().second->right){
            i++;
            q.push(make_pair(i, q.front().second->right));
            dot_string << i << " [label=\"" << q.front().second->right->val << "\" group=" << i << "];";
            if(find(highlight_nodes.begin(),highlight_nodes.end(), q.front().second->right) != highlight_nodes.end()){
                dot_string << i << " " << highlight_format;
            }
            dot_string << q.front().first << " -> " << i << ";";
        }
        q.pop();
    }
    dot_string << "}";
    view_dot_graph(dot_string.str().c_str());
}



#endif // !__BINTREE_VIEW_H__