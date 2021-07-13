#include "plot_tool.h"
#include <iostream>

void plot1DHistogram(char (*ptr_name)[128], int bin_set[3], int data_set[] , const int &ptr_size, const int &set_size, const int & option)
{
    delete gROOT->FindObject("c");
    TCanvas *c = new TCanvas("c","c",2000,2000);
    c->cd();
    c->SetFixedAspectRatio();
    c->SetGrid();
    c->SetFillStyle(4050);
    c->SetLeftMargin(0.15);
    
    gStyle->SetTitleY(0.97);
    
    for(int i = 0 ; i < ptr_size ; i++)
        delete gROOT->FindObject(*(ptr_name));
    TH1D *h = new TH1D(*(ptr_name),*(ptr_name),bin_set[0],bin_set[1],bin_set[2]);
    TLegend *Legend = new TLegend(0.5,0.55,0.80,0.60);

    for(int i = 0 ; i < set_size ; i++)
    {
        h->Fill(i,data_set[i]);
    }
    h->SetLineColor(kBlack);
    h->SetFillColorAlpha(option,0.65);
    //h->SetFillStyle(3010);
    Legend->AddEntry(h,*(ptr_name+1),"f");
    double max = 1.2 * h->GetMaximum();

    h->SetMaximum(max);
    h->Draw("histo");
    h->GetXaxis()->SetTitle(*(ptr_name+2));
    h->GetYaxis()->SetTitle(*(ptr_name+3));
    float mysize = h->GetXaxis()->GetLabelSize();
    h->GetXaxis()->SetLabelSize(0.7*mysize);
    h->GetYaxis()->SetLabelSize(0.7*mysize);
    
    Legend->SetTextSize(0.025);
    Legend->SetLineColor(kWhite);
    Legend->Draw("same");

    char filename[128];
    sprintf(filename,"./plot/%s.png",*(ptr_name+4));
    c->Update();
    c->SaveAs(filename);



}
