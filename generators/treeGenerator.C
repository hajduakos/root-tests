R__LOAD_LIBRARY(test/generators/SampleClasses_h.so)
#include "SampleClasses.h"
#include <string>
#include <vector>

// This macro generates different types of trees.
// It can be used in the following ways:
//   1) .x treeGenerator.C      Generate all trees
//   2) .L treeGenerator.C      Load macro
//      generateTree("MyTree")  Generate trees independently

void generateTree(std::string const &name = "Tree"){
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Simple tree with only leaf variables"); // Create tree
      
   // Leaf variables
   Float_t px, py, pz;
   Double_t random;
   Int_t ev;
   
   // Each variable has a separate branch
   tree.Branch("px",&px,"px/F");
   tree.Branch("py",&py,"py/F");
   tree.Branch("pz",&pz,"pz/F");
   tree.Branch("random",&random,"random/D");
   tree.Branch("ev",&ev,"ev/I");
      
   // Fill tree
   for (Int_t i = 0; i < 100; ++i){
      gRandom->Rannor(px,py);
      pz = px*px + py*py;
      random = gRandom->Rndm();
      ev = i;
      tree.Fill();
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void generateTreeArray(std::string const &name = "TreeArray"){
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree with a fixed size array"); // Create tree
      
   // Leaf variables
   Float_t arr[10];
   
   // Each variable has a separate branch
   tree.Branch("arr", arr, "arr[10]/F");
   
   // Fill tree
   for (Int_t j = 0; j < 100; ++j){
      for(Int_t k = 0; k < 10; ++k)
         arr[k] = (Float_t)gRandom->Gaus();
      
      tree.Fill();
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void generateTreeVector(std::string const &name = "TreeVector"){
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree with vectors"); // Create tree
      
   // Leaf variables
   std::vector<Float_t> vpx;
   std::vector<Float_t> vpy;
   
   // Each variable has a separate branch
   tree.Branch("vpx", &vpx);
   tree.Branch("vpy", &vpy);
   
   // Fill tree
   for (Int_t j = 0; j < 100; ++j) {
      vpx.clear();
      vpy.clear();
      
      for(Int_t k = 0; k < 10; ++k) {
         Float_t px, py;
         gRandom->Rannor(px, py);
         vpx.push_back(px);
         vpy.push_back(py);
      }
      
      tree.Fill();
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

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

void generateTreeStruct(std::string const &name = "TreeStruct"){
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree from a C structure"); // Create tree
      
   // A single branch contains all variables
   tree.Branch("simple", &simple, "px/F:py/F:pz/F:ev/I");
   
   // Fill tree
   for (Int_t i = 0; i < 100; ++i){
      gRandom->Rannor(simple.px, simple.py);
      simple.pz = simple.px*simple.px + simple.py*simple.py;
      simple.ev = i;
      tree.Fill();
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void generateTreeClass(std::string const &name = "TreeClass", Int_t splitlevel = 0) {
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree from a class"); // Create tree
      
   ClassC *classC = new ClassC(); // One instance to fill the tree
   
   // Create branch for ClassC
   tree.Branch("ClassC_branch", "ClassC", &classC, 32000, splitlevel);
      
   // Fill tree
   for (Int_t i = 0; i < 100; ++i){
      classC->Set((Float_t)gRandom->Gaus(), i);
      tree.Fill();
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void generateTreeClassNested(std::string const &name = "TreeClassNested", Int_t splitlevel = 0) {
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree with nested classes"); // Create tree
   
   ClassB *classB = new ClassB(); // One instance to fill the tree
   
   // Create branch for ClassB
   tree.Branch("ClassB_branch", "ClassB", &classB, 32000, splitlevel);
      
   // Fill tree
   for (Int_t i = 0; i < 100; ++i){
      classB->Set((Float_t)gRandom->Gaus(), i, (Float_t)gRandom->Gaus());
      tree.Fill();
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void generateTreeClassWithArray(std::string const &name = "TreeClassWithArray") {
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree with a class containing an array"); // Create tree
   
   ClassWithArray *classWithArray = new ClassWithArray(); // One instance to fill the tree
   
   // Create branch for ClassCollections
   tree.Branch("ClassWithArray_branch", "ClassWithArray", &classWithArray, 32000, 99);
   
   // Fill tree
   for (Int_t i = 0; i < 20; ++i) {
      for(Int_t j = 0; j < 10; ++j)
         classWithArray->arr[j] = i + j;
   
      tree.Fill();
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void treeGenerator(){
   Info("TreeGenerator", "Generating trees");
   generateTree();
   generateTreeArray();
   generateTreeStruct();
   generateTreeClass("TreeClass0", 0);
   generateTreeClass("TreeClass2", 2);
   generateTreeClassNested("TreeClassNested0", 0);
   generateTreeClassNested("TreeClassNested2", 2);
   generateTreeClassWithArray();
}
