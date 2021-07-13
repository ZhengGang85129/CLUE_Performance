#ifndef CLUER_H
#define CLUER_H
#include "/wk_cms2/zhenggangchen/env/workspace/CMSSW_10_2_26/src/include/mycluster.h"
#include "/wk_cms2/zhenggangchen/env/workspace/CMSSW_10_2_26/src/include/myAnalyzer_base.h"
#include "myLibConstants.h"
#include "plot_tool.h"
#include "TFile.h"
#include "TTree.h"
#include <vector>
const int kmax = 10000;
class cluer : public myAnalyzer_base{
    public:
        virtual void beginJob(char *, char *, char *, char *) override; // set up 
        
        virtual void read(int ev) override;//read event
        
        virtual void clean() override;

        virtual void endJob() override; //plot or output something
        
        virtual int nevent() const override{
            return nev;
        };
        
    private:
        TFile *_file;
        TTree *_HD;
        TTree *_LD;
        TTree *_MIX;
        std::vector<mycluster> HD_cluster;
        std::vector<mycluster> LD_cluster;
        std::vector<mycluster> MIX_cluster;
       
        int _HD_cluster_track;
        int _HD_cluster_Layer[kmax];
        int _HD_cluster_thickness[kmax];
        double _HD_cluster_E[kmax];
        double _HD_cluster_phi[kmax];
        double _HD_cluster_eta[kmax];

        int _LD_cluster_track;
        int _LD_cluster_Layer[kmax];
        int _LD_cluster_thickness[kmax];
        double _LD_cluster_E[kmax];
        double _LD_cluster_phi[kmax];
        double _LD_cluster_eta[kmax];

        int _MIX_cluster_track;
        int _MIX_cluster_Layer[kmax];
        int _MIX_cluster_thickness[kmax];
        double _MIX_cluster_E[kmax];
        double _MIX_cluster_phi[kmax];
        double _MIX_cluster_eta[kmax];
        
        int LD_nLC_perLayer[HGCal::nlayer];
        int HD_nLC_perLayer[HGCal::nlayer];
        int MIX_nLC_perLayer[HGCal::nlayer];
};
#endif
