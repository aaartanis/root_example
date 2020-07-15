void TH_tree()
{
    TFile *ipf=new TFile("single.root");
    TH3F *h=(TH3F*)ipf->Get("histo");

    TFile *opf=new TFile("mynewdose-tree.root","recreate");
    TTree *opt=new TTree("tree","tree");

    Int_t z;
    Double_t total_edep=0;
    
    opt->Branch("z",&z,"z/I");
    opt->Branch("total_edep",&total_edep,"total_edep/D");

    for(int i=0;i<100;i++)
    {
        z=i;
        for(int j=0;j<100;j++)
        {
            for(int k=0;k<100;k++)
            {
                Double_t edep=h->GetBinContent(j,k,i);
                total_edep +=edep;
            }
        }
        opt->Fill();
        total_edep=0;
    }

    opt->Write();
    opf->Close();
    ipf->Close();
}