#include "JAM2_Analyzer.C"

int main(){

	JAM2_Analyzer JAM2_analyzer;
	JAM2_analyzer.sqrt_sNN = 3.0; //GeV
	for (int i =0 ; i < 56;i++){
		JAM2_analyzer.InputFiles.push_back(Form("/gpfs01/star/scratch/fengliu/JAM2/sqrt_sNN_3p0_root/JAM2_sqrt_3p0_%d.root",i));
	}
	JAM2_analyzer.OutputFile = Form("/gpfs01/star/pwg/fliu/Lambda_PP_Mechanism/Lambda_PP_Mechanism_FIXTARGET/src/JAM2_sqrt_sNN_%.2f.root",JAM2_analyzer.sqrt_sNN);
	JAM2_analyzer.Loop();
	return 0;


}
