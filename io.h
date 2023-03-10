#ifndef _IO_H_
#define _IO_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <algorithm>

#include "graph.h"

using namespace std;

/***
 * \file io.h
 * 
 * Module for input and output functionality, including a Graph object for
 * main data structures.
 * 
 * Some classes are declared friends to avoid cumbersome get/set calls.
 * 
 * \author Phillippe Samer <samer@uib.no>
 * \date 22.12.2022
 */
class IO
{
public:
    IO();
    virtual ~IO();

    bool parse_single_weight_input_file(string);
    bool parse_CR_input_file(string);

    void save_instance_info();
    void save_literature_info(string);
    void save_lpr_info(double, double);
    void save_ip_info(long, long, double, double, long, long, long);
    void write_summary_info(string);

    // instance data
    long num_subgraphs;

    bool recoloring_instance;
    vector<long> original_colouring;

    string instance_id;
    string instance_id_trimmed;

private:
    friend class CKSModel;
    friend class CKSCutGenerator;

    stringstream summary_info;  // latex table row summary

    Graph *graph;  // different representations of the original graph
};

#endif
