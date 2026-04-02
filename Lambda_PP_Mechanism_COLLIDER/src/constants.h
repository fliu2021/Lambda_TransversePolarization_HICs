const int rapidity_bin = 10 ;
const double rapidity_bin_low[rapidity_bin]  = { -1.0 , -0.8 , -0.6 , -0.4 , -0.2 , 0.0 , 0.2 , 0.4 , 0.6 , 0.8  }; 
const double rapidity_bin_high[rapidity_bin] = { -0.8 , -0.6 , -0.4 , -0.2 , 0.0  , 0.2 , 0.4 , 0.6 , 0.8 , 1.0  }; 


//acceptance of STAR detectors
const double BBCpos_eta_high =  5.0;
const double BBCpos_eta_low  =  3.3;
const double BBCneg_eta_high = -5.0;
const double BBCneg_eta_low  = -3.3;
const double TPC_eta =   1.0;
const double ZDCpos_eta_low  =  6.3; 
const double ZDCneg_eta_low  = -6.3;
const double Centrality_eta_high =  0.5; 
const double Centrality_eta_low  = -0.5; 

const double charged_track_v1_pT_lowCut = 0.2; // GeV/c
const double proton_v1_pt_lowCut        = 0.4; 
const double proton_v1_pt_highCut       = 2.0;
const double charged_pion_v1_pt_lowCut  = 0.2;
const double charged_pion_v1_p_highCut   = 1.6;  

const double lambda_v1_pt_lowCut        = 0.2;
const double lambda_v1_pt_highCut       = 5.0;



const double lambda_GlobalPol_etaCut     = 1.0; 
const double lambda_GlobalPol_yCut     = 1.0; 
const double lambda_GlobalPol_pT_lowCut  = 0.4; 
const double lambda_GlobalPol_pT_highCut = 3.0; 
const double track_pt_low_cut = 0.2; // GeV/c

const int centrality_Nclass = 7;

//int centrality_sqrt_sNN_7_7_charged_multi_higher[centrality_Nclass] = {1000000 ,212 ,178 ,130 , 95 , 67 ,46 };
//int centrality_sqrt_sNN_7_7_charged_multi_lower[centrality_Nclass] =  {212     ,178 ,130 ,95  , 67 , 46 ,30 };

int centrality_sqrt_sNN_7_7_charged_multi_higher[centrality_Nclass] = {1000000 ,1000000 ,1000000 ,1000000, 1000000 , 1000000 ,1000000};
int centrality_sqrt_sNN_7_7_charged_multi_lower[centrality_Nclass] =  {0     ,0,0 ,0  , 0 , 0 ,0 };


int centrality_sqrt_sNN_7_7_centra_lower[centrality_Nclass]  = {0, 5 , 10, 20, 30, 40, 50 };
int centrality_sqrt_sNN_7_7_centra_higher[centrality_Nclass] = {5, 10, 20, 30, 40, 50, 60 };


const int centrality_10_sqrt_sNN_10_5 = 0;
const int centrality_40_sqrt_sNN_10_5 = 0;
const int centrality_20_sqrt_sNN_10_5 = 0; 
const int centrality_50_sqrt_sNN_10_5 = 0;