const int rapidity_bin = 10 ;
const double rapidity_bin_low[rapidity_bin]  = { -1.0 , -0.9 , -0.8 , -0.7 , -0.6 , -0.5 , -0.4 , -0.3 , -0.2 , -0.1  }; 
const double rapidity_bin_high[rapidity_bin] = { -0.9 , -0.8 , -0.7 , -0.6 , -0.5 , -0.4 , -0.3 , -0.2 , -0.1 ,  0.0  }; 


//acceptance of STAR detectors @ FIX TARGET mode 

const double EPD_A_v1_eta_lower  = -5.3;
const double EPD_A_v1_eta_higher = -2.6;

const double EPD_A_GP_eta_lower  = -2.84;
const double EPD_A_GP_eta_higher = -2.55;

const double TPC_B_eta_lower  = -0.5;
const double TPC_B_eta_higher = -0.4;

const double TPC_C_eta_lower  = -0.2;
const double TPC_C_eta_higher = -0.1;



const double TPC_eta_lower  =   -2.0;
const double TPC_eta_higher =    0.0;


const double Centrality_eta_high =    0.0; 
const double Centrality_eta_low  =   -2.0; 

const double charged_track_v1_pT_lowCut = 0.2; // GeV/c

const double proton_v1_pt_lowCut        = 0.4; 
const double proton_v1_pt_highCut       = 2.0;

const double charged_pion_v1_pt_lowCut  = 0.2;
const double charged_pion_v1_pt_highCut   = 1.6;  

const double lambda_v1_pt_lowCut        = 0.4;
const double lambda_v1_pt_highCut       = 2.0;

const double lambda_GlobalPol_y_lowCut      =-0.2 ; 
const double lambda_GlobalPol_y_highCut     = 1.0 ; 

const double lambda_GlobalPol_pT_lowCut  = 0.7; 
//const double lambda_GlobalPol_pT_highCut = 3.0; 
const double track_pt_low_cut = 0.2; // GeV/c

const int centrality_Nclass = 7;

//int centrality_sqrt_sNN_7_7_charged_multi_higher[centrality_Nclass] = {1000000 ,212 ,178 ,130 , 95 , 67 ,46 };
//int centrality_sqrt_sNN_7_7_charged_multi_lower[centrality_Nclass] =  {212     ,178 ,130 ,95  , 67 , 46 ,30 };

int centrality_sqrt_sNN_3_0_charged_multi_higher[centrality_Nclass] = {1000000   ,172  ,150  ,117 ,93 , 75  ,61 };
int centrality_sqrt_sNN_3_0_charged_multi_lower[centrality_Nclass] =  {172       ,150  ,117  , 93 ,75 , 61  ,52  };



int centrality_sqrt_sNN_3_0_centra_lower[centrality_Nclass]  = {0, 5 , 10, 20, 30, 40, 50 };
int centrality_sqrt_sNN_3_0_centra_higher[centrality_Nclass] = {5, 10, 20, 30, 40, 50, 60 };


const double PI = 3.14159265359;


const int bin_phi_lambda_phi_p = 12;















