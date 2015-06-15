void makeSimpleTreeArray(){
   // Create a file for saving the tree
   TFile *f = new TFile("simpleTreeArray.root", "RECREATE");
   // Create tree
   TTree *tree = new TTree("SimpleTreeArray", "Simple tree with array");
   
   TRandom r; // Random number generator for filling the tree
   
   // Leaf variables
   Float_t arr[10];
   
   // Each variable has a separate branch
   tree->Branch("arr", arr, "arr[10]/F");
   
   // Fill tree
   for (Int_t j = 0; j < 100; ++j){
      for(Int_t k = 0; k < 10; ++k)
         arr[k] = (Float_t)r.Gaus();
      
      tree->Fill();
   }
   
   // Print some information about the tree
   tree->Print();
   // Write tree to file
   f->Write();
}
