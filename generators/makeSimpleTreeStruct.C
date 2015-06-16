// Simple structure to hold the data
struct simple_t {
   Float_t px, py, pz;
   // When using structures as a single branch, the size of the variables
   // must be the same (https://root.cern.ch/root/htmldoc/guides/users-guide/Trees.html#adding-a-branch-to-hold-a-list-of-variables)
   // so the double member must be omitted
   //Double_t random;
   Int_t ev;
};

simple_t simple; // An instance of the structure to generate the data

void makeSimpleTreeStruct(){
   // Create a file for saving the tree
   TFile f("simpleTreeStruct.root", "RECREATE");
   // Create tree
   TTree tree("SimpleTreeStruct", "Simple tree from a C struct with one branch");
   
   TRandom r; // Random number generator for filling the tree
   
   // One branch will contain each variable
   tree.Branch("simple", &simple, "px/F:py/F:pz/F:ev/I");
   
   // Fill tree
   for (Int_t i = 0; i < 100; ++i){
      r.Rannor(simple.px, simple.py);
      simple.pz = simple.px*simple.px + simple.py*simple.py;
      simple.ev = i;
      tree.Fill();
   }
   
   // Print some information about the tree
   tree.Print();
   // Write tree to file
   f.Write();
   f.Close();
}
