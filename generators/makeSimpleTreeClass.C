#include "SampleClasses.h"

void makeSimpleTreeClass(){
   
   if (!TClassTable::GetDict("ClassC")) {
      gSystem->Load("test/generators/SampleClasses_h.so");
   }
   
   // Create a file for saving the tree
   TFile *f = new TFile("simpleTreeClass.root", "RECREATE");
   // Create tree
   TTree *tree = new TTree("SimpleTreeClass", "Simple tree with a class");
   
   TRandom r; // Random number generator for filling the tree
   
   ClassC *classC = new ClassC();
   
   // Create branch for ClassC
   tree->Branch("ClassC_branch", "ClassC", &classC, 32000, 0);
      
   // Fill tree
   for (Int_t i = 0; i < 100; ++i){
     classC->Set((Float_t)r.Gaus(), i);
     tree->Fill();
   }
   
   // Print some information about the tree
   tree->Print();
   // Write tree to file
   f->Write();
}
