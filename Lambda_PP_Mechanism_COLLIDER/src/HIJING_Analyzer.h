//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Sep 20 14:23:47 2025 by ROOT version 6.34.08
// from TTree genEvent/genEvent
// found on file: test.root
//////////////////////////////////////////////////////////

#ifndef HIJING_Analyzer_h
#define HIJING_Analyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class HIJING_Analyzer {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        b_phi;
   vector<double>  *px;
   vector<double>  *py;
   vector<double>  *pz;
   vector<double>  *E;
   vector<int>     *mother_index;
   vector<int>     *status;
   vector<int>     *pid;

   // List of branches
   TBranch        *b_b_phi;   //!
   TBranch        *b_px;   //!
   TBranch        *b_py;   //!
   TBranch        *b_pz;   //!
   TBranch        *b_E;   //!
   TBranch        *b_mother_index;   //!
   TBranch        *b_status;   //!
   TBranch        *b_pid;   //!

   std::vector<std::string> InputFiles;




   HIJING_Analyzer();
   virtual ~HIJING_Analyzer();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual bool     Notify();
   virtual void     Show(Long64_t entry = -1);



};

#endif

#ifdef HIJING_Analyzer_cxx
HIJING_Analyzer::HIJING_Analyzer() : fChain(0) 
{
   InputFiles.clear();
}

HIJING_Analyzer::~HIJING_Analyzer()
{
   //if (!fChain) return;
   //delete fChain->GetCurrentFile();
}

Int_t HIJING_Analyzer::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HIJING_Analyzer::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void HIJING_Analyzer::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   px = 0;
   py = 0;
   pz = 0;
   E = 0;
   mother_index = 0;
   status = 0;
   pid = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("b_phi", &b_phi, &b_b_phi);
   fChain->SetBranchAddress("px", &px, &b_px);
   fChain->SetBranchAddress("py", &py, &b_py);
   fChain->SetBranchAddress("pz", &pz, &b_pz);
   fChain->SetBranchAddress("E", &E, &b_E);
   fChain->SetBranchAddress("mother_index", &mother_index, &b_mother_index);
   fChain->SetBranchAddress("status", &status, &b_status);
   fChain->SetBranchAddress("pid", &pid, &b_pid);
   Notify();
}

bool HIJING_Analyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return true;
}

void HIJING_Analyzer::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HIJING_Analyzer::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef genEvent_cxx
