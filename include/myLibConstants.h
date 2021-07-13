#ifndef MYLIB_CONSTANTS_H
#define MYLIB_CONSTANTS_H

namespace HGCal
{
    constexpr double eta_lim_U = 3.0;
    constexpr double eta_lim_L = 1.5;
    constexpr int nlayer =50;
    constexpr int CEE_layer =28;
    constexpr int CEH_layer =22;
}
namespace particleId
{
    constexpr int d = 1 ;
    constexpr int u = 2 ;
    constexpr int s = 3 ;
    constexpr int electron = 11;
    constexpr int photon = 22;
    constexpr int gluon = 21;
    constexpr int pion = 111;
    constexpr int charged_pion = 211;
    constexpr int kaon = 311;
    constexpr int charged_kaon = 321;
    constexpr int kaon_S = 310;
    constexpr int kaon_L = 130;
    constexpr int undefined = -9999;
}
namespace free_parm
{
    constexpr double dRc_LC = 0.1;
    constexpr double Ec_LC = 0.;
    constexpr double jet_pt_slcU = 100.;
    constexpr double jet_pt_slcL = 80.;
    constexpr double part_pt_slc = 1.;
    constexpr double eta_lim_U = 2.;
    constexpr double eta_lim_L = 0.;
    constexpr double dimuon_mass_L = 70.0;
    constexpr double dimuon_mass_U = 110;
    constexpr double muon_pt_cut1 = 20.;
    constexpr double muon_pt_cut2 = 10.;
    constexpr double dphi_j_dimuon_cut = 2.5;
    constexpr double subleadingjet_pt_factor = 0.3;
    constexpr double pt_leadingjet_cut = 30;
}
namespace mesh
{
    constexpr double window_width = 1.2;
    constexpr double bin_size = 0.05;
}
namespace match
{
    constexpr double max_dR = 1.0;
    constexpr double pt_cut = 1;
}
#endif
