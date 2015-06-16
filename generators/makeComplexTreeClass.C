#include "SampleClasses.h"

void makeComplexTreeClass(Int_t splitlevel = 0) {
   // Load class if not available
   // Build SampleClasses.h with the command '.L SampleClasses.h+'
   if (!TClassTable::GetDict("ClassB")) {
      gSystem->Load("test/generators/SampleClasses_h.so");
   }
   
   // Create a file for saving the tree
   TFile f("complexTreeClass.root", "RECREATE");
   // Create tree
   TTree tree("ComplexTreeClass", "Complex tree with nested classes");
   
   TRandom r; // Random number generator for filling the tree
   
   ClassB *classB = new ClassB();
   
   // Create branch for ClassB
   tree.Branch("ClassB_branch", "ClassB", &classB, 32000, splitlevel);
      
   // Fill tree
   for (Int_t i = 0; i < 100; ++i){
     classB->Set((Float_t)r.Gaus(), i, (Float_t)r.Gaus());
     tree.Fill();
   }
   
   // Print some information about the tree
   tree.Print();
   // Write tree to file
   f.Write();
   f.Close();
}
