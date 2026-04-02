#include "Centrality_Analyzer.C"


int main(){
	Centrality_Analyzer my_cen_analyzer;
	//my_cen_analyzer.InputFiles.push_back("/Users/feng/Documents/physics_project/Lambda_AuAu/genEvent/JAM1/forFeng2_SMode_root/JAM1_SMode_7p7.root");
	//my_cen_analyzer.OutputFile = "/Users/feng/Documents/physics_project/Lambda_AuAu/genEvent/JAM1/forFeng2_SMode_root/JAM1_SMode_7p7_charged_multiplicity.root";
	my_cen_analyzer.InputFiles.push_back("/Users/feng/Documents/physics_project/Lambda_AuAu/genEvent/JAM1/forFeng_root/test.root");
	my_cen_analyzer.OutputFile = "/Users/feng/Documents/physics_project/Lambda_AuAu/genEvent/JAM1/forFeng_root/charged_multiplicity.root";
	my_cen_analyzer.Loop();
	return 0;
}