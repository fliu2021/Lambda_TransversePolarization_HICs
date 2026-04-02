#include "JAM1_Analyzer.C"

int main(){

	JAM1_Analyzer jam1_analyzer;
	jam1_analyzer.sqrt_sNN = 3.0; //GeV
	jam1_analyzer.InputFiles.push_back("/Users/feng/Documents/physics_project/Lambda_AuAu/genEvent/JAM2/3_0GeV/JAM2_3p0.root");
	jam1_analyzer.OutputFile = Form("/Users/feng/Documents/physics_project/Lambda_AuAu/genEvent/JAM2/3_0GeV/3_0GeV_result/JAM2_sqrt_sNN_%.2f.root",jam1_analyzer.sqrt_sNN);
	//jam1_analyzer.InputFiles.push_back("/Users/feng/Documents/physics_project/Lambda_AuAu/genEvent/JAM1/forFeng_root/test.root");
	//jam1_analyzer.OutputFile = Form("/Users/feng/Documents/physics_project/Lambda_AuAu/genEvent/JAM1/forFeng_root/forFeng_result/JAM1_sqrt_sNN_%.2f.root",jam1_analyzer.sqrt_sNN);
	jam1_analyzer.Loop();
	return 0;


}