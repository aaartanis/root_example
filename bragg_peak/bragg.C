void bragg()
{
    TFile *ipf=new TFile("mynewdose-tree.root");
    TTree *tree=(TTree*)ipf->Get("tree");
    tree->Draw("total_edep:z>>h(120,0,120,2000,0,8000000)");
    TH2D *h=(TH2D*)gROOT->FindObject("h");
    
    Double_t a,b;
    a=h->GetMaximumBin();
    b=h->GetBinContent(a);
    cout<<a<<"and"<<b<<endl;
    TGraph *gr=new TGraph(tree->GetSelectedRows(),tree->GetV2(),tree->GetV1());
    gr->Draw("ACP");
}