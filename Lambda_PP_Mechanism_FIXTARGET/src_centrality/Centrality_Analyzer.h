#ifndef Centrality_Analyzer_h
#define Centrality_Analyzer_h

#include <TROOT.h>
#include <TTree.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <string> 

class Centrality_Analyzer {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        b;
   std::vector<double>  *px;
   std::vector<double>  *py;
   std::vector<double>  *pz;
   std::vector<double>  *E;
   std::vector<double>  *mass;
   std::vector<int>     *pid;


   // List of branches
   TBranch        *b_b;   //!
   TBranch        *b_px;   //!
   TBranch        *b_py;   //!
   TBranch        *b_pz;   //!
   TBranch        *b_E;   //!
   TBranch        *b_mass;
   TBranch        *b_pid;   //!

   std::vector<std::string> InputFiles;
   std::string OutputFile;
   double sqrt_sNN = 0.0; //[GeV]
   double Centrality_Eta_Cut = 0.5 ;
   int charged_multiplicity_Upper = 1000;

   Centrality_Analyzer();
   virtual ~Centrality_Analyzer();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual bool     Notify();
   virtual void     Show(Long64_t entry = -1);


};

#endif

#ifdef Centrality_Analyzer_cxx
Centrality_Analyzer::Centrality_Analyzer() : fChain(0) 
{
   InputFiles.clear();
}

Centrality_Analyzer::~Centrality_Analyzer()
{
   //if (!fChain) return;
   //delete fChain->GetCurrentFile();
}

Int_t Centrality_Analyzer::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Centrality_Analyzer::LoadTree(Long64_t entry)
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

void Centrality_Analyzer::Init(TTree *tree)
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
   mass= 0;
   pid = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("b", &b, &b_b);
   fChain->SetBranchAddress("px", &px, &b_px);
   fChain->SetBranchAddress("py", &py, &b_py);
   fChain->SetBranchAddress("pz", &pz, &b_pz);
   fChain->SetBranchAddress("E", &E, &b_E);
   //fChain->SetBranchAddress("mass",&mass,&b_mass);
   fChain->SetBranchAddress("pid", &pid, &b_pid);
   Notify();
}

bool Centrality_Analyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return true;
}

void Centrality_Analyzer::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Centrality_Analyzer::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef genEvent_cxx
