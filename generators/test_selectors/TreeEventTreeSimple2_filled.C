#include "../generated_selectors/TreeEventTreeSimple2.h"
#include "../generated_selectors/TreeEventTreeSimple2.C"
#include <TH2.h>
#include <TStyle.h>

class TreeEventTreeSimple2_filled : public TreeEventTreeSimple2{
public:
   TreeEventTreeSimple2_filled(TTree * /*tree*/ =0) : TreeEventTreeSimple2(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeEventTreeSimple2_filled, 0);
};

void TreeEventTreeSimple2_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeEventTreeSimple2_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeEventTreeSimple2_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   fprintf(stderr, "EventSize: %d\n", *fEventSize);
   
   fprintf(stderr, "Px:");
   for(Int_t i = 0; i < fParticles_fPosX.GetSize(); ++i)
      fprintf(stderr, " %.1lf", fParticles_fPosX[i]);
   fprintf(stderr, "\n");

   fprintf(stderr, "Py:");
   for(Int_t i = 0; i < fParticles_fPosY.GetSize(); ++i)
      fprintf(stderr, " %.1lf", fParticles_fPosY[i]);
   fprintf(stderr, "\n");

   fprintf(stderr, "Pz:");
   for(Int_t i = 0; i < fParticles_fPosZ.GetSize(); ++i)
      fprintf(stderr, " %.1lf", fParticles_fPosZ[i]);
   fprintf(stderr, "\n");

   return kTRUE;
}

void TreeEventTreeSimple2_filled::SlaveTerminate() { }

void TreeEventTreeSimple2_filled::Terminate() { }
