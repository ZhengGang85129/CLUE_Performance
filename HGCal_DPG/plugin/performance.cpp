#include <iostream>
#include "TROOT.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TFile.h"
#include "TMath.h"
#include "/wk_cms2/zhenggangchen/env/workspace/CMSSW_10_2_26/src/HGCal_DPG/interface/cluer.h"
#include "/wk_cms2/zhenggangchen/env/workspace/CMSSW_10_2_26/src/include/processor_base.h"
#include "plot_tool.h"
int main()
{
    char file1[128] = "./data/low_density.root";
    char file2[128] = "./data/high_density.root";
    char file3[128] = "./data/mix_density.root" ;
    char treename[128] = "ntuple";
    std::cout<<"Hello world"<<std::endl;
    processor_base processor;
    cluer *myanalyer = new cluer();
    processor.runAnalyzer(myanalyer,file1,file2,file3,treename);
    return 0;
}


