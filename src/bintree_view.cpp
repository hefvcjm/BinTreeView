/**
 * @file bintree_view.cpp
 * @author hefvcjm (hef1995@qq.com)
 * @brief visualize bintree tool
 * @version 0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <gvc.h>
#include "opencv/cv.hpp"
#include <iostream>

/**
 * @brief Use graphviz to visualize dot language string
 * 
 * @param dot_string: dot language string
 */
void view_dot_graph(const char *dot_string){
    char* out_path = "temp.bintree.out.visualization.png";
    Agraph_t *g;
    GVC_t *gvc;
    gvc = gvContext();
    g = agmemread(dot_string);
    // std::cout << dot_string << std::endl;
    if(gvc == NULL || g == NULL){
        return;
    }
    gvLayout(gvc, g, "dot");
    gvRenderFilename (gvc, g, "png", out_path);
    gvFreeLayout(gvc, g);
    agclose(g);
    gvFreeContext(gvc);
    cv::Mat img = cv::imread(out_path);
    cv::imshow("out.png", img);
    cv::waitKey(0);
}
