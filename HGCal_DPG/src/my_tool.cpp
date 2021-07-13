#include "my_tool.h"
#include <algorithm>
double eta_L = free_parm::eta_lim_L;
double eta_U = free_parm::eta_lim_U;
double pt_slc = match::pt_cut; 
typedef std::vector<mypfjet&> JetRefCollection; 

void Jet_matching(std::vector<mygenparticle> g,std::vector<mypfjet> p,double cut, double pt \
        ,std::vector<int> &idx,std::vector<double> &arr_dr)
{
    int g_idx = 0 ;
    for(auto &g_itr : g)
    {
        idx.push_back(-100);
        double min_dR = 100.;
        int idx_p = 0.;
        for(auto &p_itr : p)
        {
            double dR = TMath::Sqrt((p_itr.eta()-g_itr.eta())*(p_itr.eta()-g_itr.eta())\
                    + (p_itr.phi()-g_itr.phi())*(p_itr.phi()-g_itr.phi()));
            if(dR < min_dR && dR < cut && p_itr.pt() > pt && TMath::Abs(g_itr.eta()) < eta_U && \
                    TMath::Abs(g_itr.eta()) > eta_L)
            {
                idx.at(g_idx) = idx_p ;
                min_dR = dR;              
            }
        }
        if(min_dR <100)
            arr_dr.push_back(min_dR);
    }
}

void jetflavor_match(GenparticleCollection genpartons , PFJetCollection& jets ,double dR_cut ,std::vector<double> &distance)
{
    int idx_jet = 0 ;
    for(auto jet : jets)
    {
        double min_dR = 100;
        int answer=0 ;
        int idx = 0 ;
        bool nopass = true;
        for(auto parton : genpartons)
        {
            double deta = jet.eta() - parton.eta();
            double dphi = jet.phi() - parton.phi();
            double dR = TMath::Sqrt(deta*deta+dphi*dphi);
            if( dR < min_dR && dR < dR_cut)
            {
                min_dR = dR;
                answer = idx ;       
                nopass = false;
            }
            idx++;
        }
        if(!nopass)
        {
            jet.setInitparton(genpartons.at(answer).pdgId());
            distance.push_back(min_dR);
        }
        idx_jet++;
    }
}
bool mycompare(TH1D *h1, TH1D *h2)
{
    return h1->Integral() < h2->Integral();
}
void plot_stack(std::vector<std::vector<double>> dataset,std::vector<std::vector<double>> hstyle,std::vector<std::string> selectionname,std::vector<std::string> hname, double *hnumber,const char *xtitle,const char *pdfname , const char *title)
{

    dataset.shrink_to_fit();
    hstyle.shrink_to_fit();
    selectionname.shrink_to_fit();
    hname.shrink_to_fit();
    delete gROOT->FindObject("c");
    TCanvas *c = new TCanvas("c","c",2000,2000);
    c->cd();
    c->SetFixedAspectRatio();
    c->SetGrid();
    c->SetFillStyle(4050); 
    c->SetLeftMargin(0.15);
    gStyle->SetTitleY(0.97);
    THStack *hs = new THStack("hs",title);
    TLegend *Legend =new TLegend(0.6, 0.75, 0.90, 0.90);
    int index = 0 ;
    std::vector<TH1D *> hvec;
    for(auto ds : dataset)
    {
        char histname[128];
        sprintf(histname,hname.at(index).c_str());
        delete gROOT->FindObject(histname);
        TH1D *h = new TH1D(histname,histname,*(hnumber),*(hnumber+1),*(hnumber+2));
        for(auto data : ds)
        {
            h->Fill(data);
        }
        h->SetLineColor(hstyle.at(0).at(index));
        h->SetFillColorAlpha(hstyle.at(1).at(index),0.65);
        h->SetFillStyle(hstyle.at(2).at(index));
        Legend->AddEntry(h,h->GetName(),"f");
        hvec.push_back(h);
        index++;
    }
    std::sort(hvec.begin(),hvec.end(),mycompare);
    double max = 0;
    for(auto hist : hvec)
    {
        max += hist->GetMaximum();
        hs->Add(hist);
    }
    max = 1.2*max;
    hs->Draw();
    hs->SetMaximum(max);
    hs->GetXaxis()->SetTitle(xtitle);
    hs->GetYaxis()->SetTitle("Event");
    hs->SetTitle(title);
    Float_t mysize = hs->GetXaxis()->GetLabelSize();
    hs->GetXaxis()->SetLabelSize(0.7*mysize);
    hs->GetYaxis()->SetLabelSize(0.7*mysize);
    
    Legend->SetTextSize(0.025);
    Legend->SetLineColor(kWhite);
    Legend->Draw("same");
    
    double dy =0;
    TLatex latex;
    for(auto name :selectionname)
    {
        latex.SetTextFont(43);
        latex.SetTextSize(65);
        latex.DrawLatexNDC(0.2,0.85-dy*0.05,name.c_str());
        dy+=1;
    }
    char filename[128];
    sprintf(filename,"./plot/reproduce/%s.png",pdfname);
    c->Update();
    c->SaveAs(filename);
}


