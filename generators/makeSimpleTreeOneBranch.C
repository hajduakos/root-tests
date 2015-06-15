// Simple structure to hold the data
struct simple_t {
   Float_t xVal;
   Int_t   i;
   Bool_t  b;
   Short_t s;
};

simple_t simple; // An instance of the structure to generate the data

void makeSimpleTreeOneBranch(){
   // Create a file for saving the tree
   TFile *f = new TFile("simpleTreeOneBranch.root", "RECREATE");
   // Create tree
   TTree *tree = new TTree("SimpleTreeOneBranch", "Simple tree with one branch");
   
   TRandom r; // Random number generator for filling the tree
   
   // One branch will contain each variable
   tree->Branch("simple", &simple, "xVal/F:i/I:b/O:s/S");
   
   // Fill tree
   for (Int_t j = 0; j < 100; ++j){
      simple.xVal = (Float_t)r.Gaus();
      simple.i    = r.Integer(1000);
      simple.b    = r.Integer(2);
      simple.s    = (Short_t)r.Integer(20);
      tree->Fill();
   }
   
   // Print some information about the tree
   tree->Print();
   // Write tree to file
   f->Write();
}
