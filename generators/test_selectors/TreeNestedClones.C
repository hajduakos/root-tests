#define TreeNestedClones_cxx

#include "../generated_selectors/TreeNestedClones.h"
#include <TH2.h>
#include <TStyle.h>


void TreeNestedClones::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeNestedClones::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeNestedClones::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   for (Int_t i = 0; i < arr_arr.GetSize(); ++i) {
      fprintf(stderr, "GetSize: %d\n", arr_arr[i].GetSize());
   }

   return kTRUE;
}

void TreeNestedClones::SlaveTerminate() { }

void TreeNestedClones::Terminate() { }
