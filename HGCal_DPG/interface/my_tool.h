#ifndef QGSEPERATION_MY_TOOL_H
#define QGSEPERATION_MY_TOOL_H
#include "mygenparticle.h"
#include "mypfjet.h"
#include "myLibConstants.h"
#include "TMath.h"
#include "GenparticleCollection.h"
#include "PFJetCollection.h"
#include "TH1D.h"
#include "THStack.h"
#include <string>
#include "TROOT.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TCanvas.h"

void Jet_matching(std::vector<mygenparticle> ,std::vector<mypfjet>,double, double ,std::vector<int> &,\
        std::vector<double> &);
void jetflavor_match(GenparticleCollection,PFJetCollection&,double,std::vector<double> &);
void plot_stack(std::vector<std::vector<double>> ,std::vector<std::vector<double>>,std::vector<std::string>, std::vector<std::string>,double*,const char*,const char*,const char*);
#endif
