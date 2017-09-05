//g++ Energy.cpp `root-config --libs --cflags` -o Energy


#include<iostream>
#include<fstream>
#include <iomanip>
#include <TH1F.h>
#include <TH2D.h>
#include <TApplication.h>
#include <cstring>
#include <string>
#include <vector>
#include<math.h>


using namespace std;

using std::string;
using std::cin;
 

int main(int argc, char **argv)
{

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*************************************************Initialization**********************************************************//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    TApplication* theApp = new TApplication("App", &argc, argv);
	    //TH2D *hist_Single = new TH2D("hist_Single", "Energy deposition vs Theta Angle",180,0,180,100,0,515);
		TH1F *hist_Single = new TH1F("hist_Single","Count Rate",200,0,200);

	int pi =  3.14159 ;
	int count = 0;

	std::vector<int> evtID, step_no,  parentID, copy_no;
   
	int   my_evtID, my_step_no,  my_ParentID, my_copy_no;
	
	std::vector<double> Energy_dep, Kine_Energy, Phi_Angle, theta_Angle_PreStep, theta_Angle_PostStep, x_value, y_value, z_value;
	 
    	double my_Energy_dep, my_Kine_Energy, my_Phi_Angle, my_theta_Angle_PreStep, my_theta_Angle_PostStep, my_x_value, my_y_value, my_z_value;

    	string my_Particle_name, my_Energy_dep_unit, my_Kine_Energy_unit, my_Volume, my_Process, my_Phi_Angle_unit, my_theta_Angle_PreStep_unit, my_theta_Angle_PostStep_unit, my_x_value_unit, my_y_value_unit, my_z_value_unit;
	
	std::vector<string> Particle_name, Energy_dep_unit, Kine_Energy_unit, Volume, Process, Phi_Angle_unit, theta_Angle_PreStep_unit, theta_Angle_PostStep_unit, x_value_unit, y_value_unit, z_value_unit;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//***********************************************Read Input File***********************************************************//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
    


	ifstream input;

	input.open("xaa.txt");

	int i = 0;
    

while(!input.eof())

	    {
        input>>my_evtID>>my_step_no>>my_Particle_name>>my_ParentID>>my_Energy_dep>>my_Energy_dep_unit>>my_copy_no>>
	my_Kine_Energy>>my_Kine_Energy_unit>>my_Volume>>my_Process>>my_Phi_Angle>>my_Phi_Angle_unit>>my_theta_Angle_PreStep>>	my_theta_Angle_PreStep_unit>>my_theta_Angle_PostStep>>my_theta_Angle_PostStep_unit>>my_x_value>>my_x_value_unit>>my_y_value>>my_y_value_unit>>my_z_value>>my_z_value_unit;


		

		if(my_Energy_dep_unit == "eV") my_Energy_dep = my_Energy_dep/1000;
	        if(my_Kine_Energy_unit == "eV") my_Kine_Energy = my_Kine_Energy/1000;


		
		if(my_Phi_Angle_unit=="rad")
		{
		my_Phi_Angle = my_Phi_Angle*180/pi;			
		}
		else if(my_Phi_Angle_unit=="mrad")
		{
		my_Phi_Angle = (my_Phi_Angle*180)/(pi*1000) ;
		}



		if(my_theta_Angle_PreStep_unit=="rad")
		{
		my_theta_Angle_PreStep = (my_theta_Angle_PreStep*180)/(pi);			
		}
		else if(my_theta_Angle_PreStep_unit=="mrad")
		{
		my_theta_Angle_PreStep = (my_theta_Angle_PreStep*180)/(pi*1000) ;
		}




		if(my_theta_Angle_PostStep_unit=="rad")
		{
		my_theta_Angle_PostStep = (my_theta_Angle_PostStep*180)/(pi);			
		}
		else if(my_theta_Angle_PostStep_unit=="mrad")
		{
		my_theta_Angle_PostStep = (my_theta_Angle_PostStep*180)/(pi*1000) ;
		}

		

		evtID.push_back(my_evtID);
		step_no.push_back(my_step_no);
		Particle_name.push_back(my_Particle_name);
		parentID.push_back(my_ParentID);
		Energy_dep.push_back(my_Energy_dep);
		Energy_dep_unit.push_back(my_Energy_dep_unit);
		copy_no.push_back(my_copy_no);
		Kine_Energy.push_back(my_Kine_Energy);
		Kine_Energy_unit.push_back(my_Kine_Energy_unit);
		Volume.push_back(my_Volume);
		Process.push_back(my_Process);
		Phi_Angle.push_back(my_Phi_Angle);
		Phi_Angle_unit.push_back(my_Phi_Angle_unit);
		theta_Angle_PreStep.push_back(my_theta_Angle_PreStep);
		theta_Angle_PreStep_unit.push_back(my_theta_Angle_PreStep_unit);
		theta_Angle_PostStep.push_back(my_theta_Angle_PostStep);
		theta_Angle_PostStep_unit.push_back(my_theta_Angle_PostStep_unit);
		x_value.push_back(my_x_value);
		x_value_unit.push_back(my_x_value_unit);
		y_value.push_back(my_y_value);
		y_value_unit.push_back(my_y_value_unit);		
		z_value.push_back(my_z_value);
		z_value_unit.push_back(my_z_value_unit);


		//cout<<Process[i];
		
		/*if(my_Process=="compt")
		{
		
		//double sz = my_theta_Angle_PreStep;
		//double sy = abs(my_Phi_Angle);
		//cout<<Particle_name<<"	"<<my_theta_Angle<<"	"<<my_Kine_Energy<<endl;
		//double sx = sz * cos(sy);		
		hist_Single->Fill(my_copy_no);
			}
		*/

		double sz = my_theta_Angle_PreStep;
		double sy = abs(my_Phi_Angle);
		//cout<<Particle_name[j]<<"	"<<theta_Angle_PreStep[j]<<"	"<<Kine_Energy[j]<<endl;
		double sx = sz * cos(sy);		
		hist_Single->Fill(sx);		
		

	//cout<<i<<endl;
		
	i++;
   
	 }
	
	//int size = evtID.size();
	//int value = evtID.size[size];
	//for (int j=0; j<=evtID.size(); j++)
	//{
	//cout<<Process[j];		
	//if(Process[j] == "compt")
	//	{
	//	double sz = theta_Angle_PreStep[j];
	//	double sy = abs(Phi_Angle[j]);
		//cout<<Particle_name[j]<<"	"<<theta_Angle_PreStep[j]<<"	"<<Kine_Energy[j]<<endl;
	//	double sx = sz * cos(sy);		
	//	hist_Single->Fill(sx);
	//}


	//	}
		

    input.close();

   	hist_Single->Draw();
		/*for (int j=0; j<=evtID.size(); j++)
		{
		if(evtID[j]==evtID[j-1])
		{			
		count = count+1;
		}
		}
  		cout<<count;
		*/
    theApp->Run();
      return 0;


}

