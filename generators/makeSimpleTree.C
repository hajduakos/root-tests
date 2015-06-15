void makeSimpleTree(){
   // Create a file for saving the tree
   TFile *f = new TFile("simpleTree.root", "RECREATE");
   // Create tree
   TTree *tree = new TTree("SimpleTree", "Simple tree");
   
   TRandom r; // Random number generator for filling the tree
   
   // Leaf variables
   Float_t xVal;
   Int_t   i;
   Bool_t  b;
   Short_t s;
   
   // Each variable has a separate branch
   tree->Branch("xVal", &xVal, "xVal/F");
   tree->Branch("i"   , &i   , "i/I");
   tree->Branch("b"   , &b   , "b/O");
   tree->Branch("s"   , &s   , "s/S");
   
   // Fill tree
   for (Int_t j = 0; j < 100; ++j){
      xVal = (Float_t)r.Gaus();
      i    = r.Integer(1000);
      b    = r.Integer(2);
      s    = (Short_t)r.Integer(20);
      tree->Fill();
   }
   
   // Print some information about the tree
   tree->Print();
   // Write tree to file
   f->Write();
}
