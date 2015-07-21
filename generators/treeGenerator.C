R__LOAD_LIBRARY(test/generators/SampleClasses_h.so)
#include "SampleClasses.h"
#include <string>
#include <vector>
#include <set>
#include <list>
#include <stack>
#include "TObjArray.h"
#include "TClonesArray.h"

// This macro generates different types of trees.
// It can be used in the following ways:
//   1) .x treeGenerator.C      Generate all trees
//   2) .L treeGenerator.C      Load macro
//      generateTree("MyTree")  Generate trees independently

void generateTree(std::string const &name = "Tree") {
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree with basic leaf variables"); // Create tree
      
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
   for (Int_t i = 0; i < 100; ++i) {
      gRandom->Rannor(px, py);
      pz = px*px + py*py;
      random = gRandom->Rndm();
      ev = i;
      tree.Fill();
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void generateTreeArray(std::string const &name = "TreeArray") {
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree with a fixed size array"); // Create tree
      
   // Leaf variables
   Float_t arr[10];
   
   // Each variable has a separate branch
   tree.Branch("arr", arr, "arr[10]/F");
   
   // Fill tree
   for (Int_t j = 0; j < 100; ++j) {
      for(Int_t k = 0; k < 10; ++k)
         arr[k] = (Float_t)gRandom->Gaus();
      
      tree.Fill();
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void generateTreeVector(std::string const &name = "TreeVector") {
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree with vectors of built in types"); // Create tree
      
   // Leaf variables
   std::vector<Float_t> vpx;
   std::vector<Float_t> vpy;
   std::vector<Bool_t> vb;
   
   // Each variable has a separate branch
   tree.Branch("vpx", &vpx);
   tree.Branch("vpy", &vpy);
   tree.Branch("vb" , &vb );
   
   // Fill tree
   for (Int_t j = 0; j < 100; ++j) {
      vpx.clear();
      vpy.clear();
      
      for (Int_t k = 0; k < 10; ++k) {
         Float_t px, py;
         gRandom->Rannor(px, py);
         vpx.push_back(px);
         vpy.push_back(py);
         vb.push_back((k * j % 2) == 0);
      }
      
      tree.Fill();
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void generateTreeVectorClass(std::string const &name = "TreeVectorClass", Int_t splitlevel = 0) {
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree with a vector containing objects"); // Create tree
      
   // Leaf variables
   std::vector<Particle> vp;
   Particle p;
   
   // Create branch
   tree.Branch("vp", &vp, 32000, splitlevel);
   
   // Fill tree
   for (Int_t j = 0; j < 20; ++j) {
      vp.clear();
      
      for (Int_t k = 0; k < 5; ++k) {
         p.fPosX = gRandom->Gaus();
         p.fPosY = gRandom->Gaus();
         p.fPosZ = gRandom->Gaus();
         vp.push_back(p);
      }
      
      tree.Fill();
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void generateTreeContainers(std::string const &name = "TreeContainers") {
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree with containers of built in types"); // Create tree
      
   // Leaf variables
   std::vector<Int_t> vi;
   std::set<Int_t> si;
   std::list<Int_t> li;
   std::stack<Int_t> sti;
   
   // Each variable has a separate branch
   tree.Branch("vectorBranch", &vi);
   tree.Branch("setBranch", &si);
   tree.Branch("listBranch", &li);
   tree.Branch("stackBranch", &sti);
   
   // Fill tree
   for (Int_t j = 0; j < 10; ++j) {
      vi.clear();
      si.clear();
      li.clear();
      while (!sti.empty()) sti.pop();
      
      for (Int_t k = 0; k < 10; ++k) {
         vi.push_back(k%2);
         si.insert(k%2);
         li.push_back(k%2);
         sti.push(k%2);
      }
      
      tree.Fill();
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void generateTreeTObjArray(std::string const &name = "TreeTObjArray") {
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree with a TObjArray"); // Create tree
   
   // Leaf variables
   TObjArray arr;
   arr.SetOwner(kTRUE);
   
   // Create branch
   tree.Branch("arr", &arr);
   
   // Fill tree
   for (Int_t i = 0; i < 20; ++i) {
      
      for (Int_t j = 0; j < 5; ++j) 
         arr.Add(new ClassC((Float_t)gRandom->Gaus(), i + j));
      
      tree.Fill();
      arr.Delete(); // FIXME: can I delete the array after the tree was filled?
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void generateTreeTClonesArray(std::string const &name = "TreeTClonesArray", Int_t splitlevel = 0) {
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree with a TClonesArray"); // Create tree
   
   // Leaf variables
   TClonesArray arr("ClassC", 5);
   arr.SetOwner(kTRUE);   
   
   // Create branch
   tree.Branch("arr", &arr, 32000, splitlevel);
   
   // Fill tree
   for (Int_t i = 0; i < 20; ++i) {
      for (Int_t j = 0; j < 5; ++j)
         new (arr[j]) ClassC((Float_t)gRandom->Gaus(), i + j);
      
      tree.Fill();
      arr.Clear(); // FIXME: can I delete the array after the tree was filled?
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

void generateTreeStruct(std::string const &name = "TreeStruct") {
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree from a C structure with basic variables"); // Create tree
      
   // A single branch contains all variables
   tree.Branch("simple", &simple, "px/F:py/F:pz/F:ev/I");
   
   // Fill tree
   for (Int_t i = 0; i < 100; ++i) {
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
   for (Int_t i = 0; i < 100; ++i) {
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
   for (Int_t i = 0; i < 100; ++i) {
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
   
   // Create branch for ClassWithArray
   tree.Branch("ClassWithArray_branch", &classWithArray);
   
   // Fill tree
   for (Int_t i = 0; i < 20; ++i) {
      for(Int_t j = 0; j < 10; ++j)
         classWithArray->arr[j] = i + j;
   
      tree.Fill();
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void generateTreeClassWithVector(std::string const &name = "TreeClassWithVector") {
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree with a class containing a vector"); // Create tree
   
   ClassWithVector *classWithVector = new ClassWithVector(); // One instance to fill the tree
   
   // Create branch for ClassWithVector
   tree.Branch("ClassWithVector_branch", &classWithVector);
   
   // Fill tree
   for (Int_t i = 0; i < 20; ++i) {
      classWithVector->vec.clear();
      for(Int_t j = 0; j < 10; ++j)
         classWithVector->vec.push_back(i + j);
   
      tree.Fill();
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void generateTreeClassWithClones(std::string const &name = "TreeClassWithClones") {
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree with a class containing a TClonesArray"); // Create tree

   ClassWithClones *classWithClones = new ClassWithClones(); // One instance to fill the tree
   classWithClones->arr.SetOwner(kTRUE);

   // Create branch for ClassWithClones
   tree.Branch("ClassWithClones_branch", &classWithClones, 32000, 99);

   // Fill tree
   for (Int_t i = 0; i < 20; ++i) {
      classWithClones->arr.Clear();
      for(Int_t j = 0; j < 5; ++j) {
         new (classWithClones->arr[j]) Particle();
         Particle *p = (Particle*)classWithClones->arr[j];
         p->fPosX = gRandom->Gaus();
         p->fPosY = gRandom->Gaus();
         p->fPosZ = gRandom->Gaus();
      }
      tree.Fill();
   }

   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void generateTreeEventTreeSimple(std::string const &name = "TreeEventTreeSimple", Int_t splitlevel = 0) {
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Simplified version of the EventTree from the intro tutorial"); // Create tree
   
   EventData *event = new EventData();
   Particle p;
   
   tree.Branch("Event_branch", &event, 32000, splitlevel);
   
   for (Int_t i = 0; i < 20; ++i) {
      event->Clear();
      
      int nParticles = 10;
      for (Int_t ip = 0; ip < nParticles; ++ip) {
         p.fPosX = gRandom->Gaus();
         p.fPosY = gRandom->Gaus();
         p.fPosZ = gRandom->Gaus();
         event->AddParticle(p);
      }
      
      event->SetSize();
      
      tree.Fill();
   }

   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void generateTreeNestedVector(std::string const &name = "TreeNestedVector") {
   TFile f((name + ".root").c_str(), "RECREATE"); // Create file
   TTree tree(name.c_str(), "Tree with a vector of a class containing a vector"); // Create tree

   std::vector<EventData> vec;
   
   // Create branch for ClassWithVector
   tree.Branch("vec_branch", &vec, 32000, 99);
   
   // Fill tree
   for (Int_t i = 0; i < 20; ++i) {
      vec.clear();
      for(Int_t j = 0; j < 10; ++j) {
         EventData ed;
         Particle p;
         for (Int_t ip = 0; ip < 10; ++ip) {
            p.fPosX = gRandom->Gaus();
            p.fPosY = gRandom->Gaus();
            p.fPosZ = gRandom->Gaus();
            ed.AddParticle(p);
         }
         vec.push_back(ed);
      }
      tree.Fill();
   }
   
   tree.Print(); // Print some information about the tree
   f.Write(); f.Close(); // Write tree to file
}

void treeGenerator() {
   Info("TreeGenerator", "Generating trees");
   generateTree();
   generateTreeArray();
   generateTreeVector();
   generateTreeVectorClass("TreeVectorClass0", 0);
   generateTreeVectorClass("TreeVectorClass2", 2);
   generateTreeContainers();
   generateTreeTObjArray();
   generateTreeTClonesArray("TreeTClonesArray0", 0);
   generateTreeTClonesArray("TreeTClonesArray2", 2);
   generateTreeStruct();
   generateTreeClass("TreeClass0", 0);
   generateTreeClass("TreeClass2", 2);
   generateTreeClassNested("TreeClassNested0", 0);
   generateTreeClassNested("TreeClassNested1", 1);
   generateTreeClassNested("TreeClassNested2", 2);
   generateTreeClassWithArray();
   generateTreeClassWithVector();
   generateTreeEventTreeSimple("TreeEventTreeSimple0", 0);
   generateTreeEventTreeSimple("TreeEventTreeSimple1", 1);
   generateTreeEventTreeSimple("TreeEventTreeSimple2", 2);
}
