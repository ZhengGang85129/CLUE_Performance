#ifndef PLOT_TOOL_H
#define PLOT_TOOL_H
#include "TH1D.h"
#include "TH1I.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TROOT.h"

void plot1DHistogram(char (*)[128] ,int [3], int [], const int & ,const int & ,const int &);
#endif
