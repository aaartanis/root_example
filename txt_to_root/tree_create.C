#include "Riostream.h"
#include "TFile.h"
#include "TTree.h"

void tree_create()
{
   
   //open ROOT file to save the TTree in
   TFile *ftree = new TFile("Test1.root","recreate");
   
   //creation of TTree
   TTree *t = new TTree("t", "a simple Tree with struct");

   Float_t s0e,s1e,s2e;
	
   // open the data file for reading
   ifstream file;
   file.open("Test1.txt");
      
   
   //creation of branches to hold the variables of the structure
   
   t->Branch("s0e_part", &s0e, "s0e/F");
   t->Branch("s1e_part", &s1e, "s1e/F");
   t->Branch("s2e_part", &s2e, "s2e/F");
   
      for(Int_t i=0; i <100000; i++)
   {
      
      	//read the properties of each particle
         file >> s0e;
         file >> s1e;
         file >> s2e;
      
      
      //fill the tree
      t->Fill();
    }
         
   file.close();
   
   //write and close the ROOT file
   t->Write();
 // delete ftree;
   
}
