#include "/wk_cms2/zhenggangchen/env/workspace/CMSSW_10_2_26/src/HGCal_DPG/interface/cluer.h"
#include <iostream>
void cluer::beginJob(char *filename1 , char *filename2 , char *filename3, char *tree_name)
{
   _file = TFile::Open(filename1);
   _LD = (TTree*)_file->Get(tree_name);
   _LD->SetBranchAddress("layercluster_number",&_LD_cluster_track);
   _LD->SetBranchAddress("layercluster_layer",_LD_cluster_Layer);
   _LD->SetBranchAddress("layercluster_energy",_LD_cluster_E);
   _LD->SetBranchAddress("layercluster_eta",_LD_cluster_eta);
   _LD->SetBranchAddress("layercluster_phi",_LD_cluster_phi);
   _LD->SetBranchAddress("thickness_type",_LD_cluster_thickness);
   _file = TFile::Open(filename2);
   _HD = (TTree*)_file->Get(tree_name);
   _HD->SetBranchAddress("layercluster_number",&_HD_cluster_track);
   _HD->SetBranchAddress("layercluster_layer",_HD_cluster_Layer);
   _HD->SetBranchAddress("layercluster_energy",_HD_cluster_E);
   _HD->SetBranchAddress("layercluster_eta",_HD_cluster_eta);
   _HD->SetBranchAddress("layercluster_phi",_HD_cluster_phi);
   _HD->SetBranchAddress("thickness_type",_HD_cluster_thickness);
   _file = TFile::Open(filename3);
   _MIX = (TTree*)_file->Get(tree_name);
   _MIX->SetBranchAddress("layercluster_number",&_MIX_cluster_track);
   _MIX->SetBranchAddress("layercluster_layer",_MIX_cluster_Layer);
   _MIX->SetBranchAddress("layercluster_energy",_MIX_cluster_E);
   _MIX->SetBranchAddress("layercluster_eta",_MIX_cluster_eta);
   _MIX->SetBranchAddress("layercluster_phi",_MIX_cluster_phi);
   _MIX->SetBranchAddress("thickness_type",_MIX_cluster_thickness);
   nev = 500;
}
void cluer::read(int ev)
{
    int ID = 0;
    _LD->GetEntry(ev);
    for(int i = 0 ; i < _LD_cluster_track; i++)
    {
        mycluster cluster;
        cluster.setId(ID);
        cluster.seteta(_LD_cluster_eta[i]);
        cluster.setphi(_LD_cluster_phi[i]);
        cluster.setenergy(_LD_cluster_E[i]);
        cluster.setLayer(_LD_cluster_Layer[i]);
        cluster.setsensor_type(_LD_cluster_thickness[i]);
        LD_cluster.push_back(cluster);
        ID++;
    }
    _HD->GetEntry(ev);
    for(int i = 0 ; i < _HD_cluster_track; i++)
    {
        mycluster cluster;
        cluster.setId(ID);
        cluster.seteta(_HD_cluster_eta[i]);
        cluster.setphi(_HD_cluster_phi[i]);
        cluster.setenergy(_HD_cluster_E[i]);
        cluster.setLayer(_HD_cluster_Layer[i]);
        cluster.setsensor_type(_HD_cluster_thickness[i]);
        HD_cluster.push_back(cluster);
        ID++;
    }
    _MIX->GetEntry(ev);
    for(int i = 0 ; i < _MIX_cluster_track; i++)
    {
        mycluster cluster;
        cluster.setId(ID);
        cluster.seteta(_MIX_cluster_eta[i]);
        cluster.setphi(_MIX_cluster_phi[i]);
        cluster.setenergy(_MIX_cluster_E[i]);
        cluster.setLayer(_MIX_cluster_Layer[i]);
        cluster.setsensor_type(_MIX_cluster_thickness[i]);
        MIX_cluster.push_back(cluster);
        ID++;
    }
    for( auto cluster : HD_cluster)
    {
        HD_nLC_perLayer[cluster.Layer()] += 1 ;
    }
    for( auto cluster : LD_cluster)
    {
        LD_nLC_perLayer[cluster.Layer()] += 1 ;
    }
}
void cluer::clean()
{


}
void cluer::endJob()
{
    char name1[5][128] = {"Single Photon contained in Fully LD region","Low-Density LayerClusters","Layer","number of LCs","LDLayercluster"};
    int bin_set1[3] = {HGCal::nlayer,1,HGCal::nlayer};
    int color_option_1 =2 ;
    plot1DHistogram(name1,bin_set1,LD_nLC_perLayer,5,HGCal::nlayer,color_option_1);
    char name2[5][128] = {"Single Photon contained in Fully HD region","High-Density LayerClusters","Layer","number of LCs","HDLayercluster"};
    int bin_set2[3] = {HGCal::nlayer,1,HGCal::nlayer};
    int color_option_2 =4 ;
    plot1DHistogram(name2,bin_set2,HD_nLC_perLayer,5,HGCal::nlayer,color_option_2);
    
    char name3[5][128] = {"Single Photon contained in Fully Mixed-Density region","Mixed-Density LayerClusters","Layer","number of LCs","MIX-Layercluster"};
    int bin_set3[3] = {HGCal::nlayer,1,HGCal::nlayer};
    int color_option_3 =6 ;
    plot1DHistogram(name3,bin_set3,LD_nLC_perLayer,5,HGCal::nlayer,color_option_3);
}

