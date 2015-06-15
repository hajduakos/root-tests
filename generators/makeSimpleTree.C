void makeSimpleTree(){
   // Create a file for saving the tree
   TFile *f = new TFile("simpleTree.root", "RECREATE");
   // Create tree
   TTree *tree = new TTree("SimpleTree", "Simple tree");
   
   TRandom r; // Random number generator for filling the tree
   
   // Leaf variables
   Float_t px, py, pz;
   Double_t random;
   Int_t ev;
   
   // Each variable has a separate branch
   tree->Branch("px",&px,"px/F");
   tree->Branch("py",&py,"py/F");
   tree->Branch("pz",&pz,"pz/F");
   tree->Branch("random",&random,"random/D");
   tree->Branch("ev",&ev,"ev/I");
      
   // Fill tree
   for (Int_t i = 0; i < 100; ++i){
     r.Rannor(px,py);
     pz = px*px + py*py;
     random = gRandom->Rndm();
     ev = i;
     tree->Fill();
   }
   
   // Print some information about the tree
   tree->Print();
   // Write tree to file
   f->Write();
}
