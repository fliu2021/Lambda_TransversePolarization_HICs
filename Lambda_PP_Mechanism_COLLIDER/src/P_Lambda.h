
//probability density function for lambda-> p + pi-
#include <TF1.h>
class Lambda_decay_RestFrame{
public:
	double xF;
	double alpha;
	double mass_lambda;
	double mass_proton;
	double mass_pion_minus;
	double E_proton;
	double E_pion_minus;
	double P_proton;
	double P_pion_minus;
	double t; // t = cos (\theta ) 
	TF1 *dN_dcos_theta;
	Lambda_decay_RestFrame()
		:mass_lambda(0),xF(0) 
	{
		//alpha = 0.642 ;
		alpha = 0.747;
		mass_proton = 0.93827208943;
		mass_pion_minus = 0.13957039 ;
		
		dN_dcos_theta = new TF1("dN_dcos_theta","0.5*(1+[0]*[1]*x)",-1,1);
		
	}

	double P_Lambda(){
		return (-0.00294943)+(-0.125304)*xF+(-0.451084)*xF*xF;
	}

	void set_xF(double x_F){
		xF = x_F;
	}
	void set_mass_lambda(double M_lambda){
		mass_lambda = M_lambda;
		E_proton = (mass_lambda*mass_lambda + mass_proton*mass_proton - mass_pion_minus*mass_pion_minus )/(2*mass_lambda);
		E_pion_minus = mass_lambda - E_proton;
		P_proton = TMath::Sqrt(E_proton*E_proton - mass_proton*mass_proton );
		P_pion_minus = P_proton;
	}
	double calculate_theta(){
		double temp =P_Lambda();
		
		
		dN_dcos_theta->SetParameters(alpha,temp);
		t = dN_dcos_theta->GetRandom();
		
		return t;
	}

	double calculate_probability(double cos_theta){
		double temp =P_Lambda();
		
		
		dN_dcos_theta->SetParameters(alpha,temp);
		return dN_dcos_theta->Eval(cos_theta);

	}




};