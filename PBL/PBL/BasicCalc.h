#pragma once
#include <stdio.h>
#include <conio.h>
#include <math.h>


#define ELECTRON_MASS 9.109E-31
#define ELECTRON_ENERGY 1.6E-19



double Energy_Electron = 0.0f;
double Force_Electron = 0.0f;
double Acceleration_Electron = 0.0f;
double Velocity_Electron = 0.0f;
double Displacement_Electron = 0.0f; 
double DistanceTravelled_Electron = 0.0f;

#pragma region Perpendicular Electric Field
double VerticalDisplacement_Y_ElectricField_Perpendicular;
double HorizontalDisplacement_X_ElectricField_Perpendicular;
double VerticalDisplacement_LeavingElectricField;
const double ElectronPlateWidth_L = 0.5f;
#pragma endregion


#pragma region Basic Calculations
	void Basic_Calculations(double PotentialDifference, double PlateDistance)
	{
		Energy_Electron = PotentialDifference / PlateDistance; //Energy of the electron
		Force_Electron = -1*ELECTRON_ENERGY * Energy_Electron; //Force of the electorn on plate B ( The plate form which the electron enters into the field)
		Acceleration_Electron = Force_Electron / ELECTRON_MASS; //Acceleration of the electron: negating by -1 to get a positive result for acceleration

		printf("\n%lf\n%lf\n%lf", Energy_Electron, Force_Electron, Acceleration_Electron);
	}

	void Velocity_Disp_Calc(double InitialVelocity_Electron, unsigned long int Time_SecondsFromEpoch)
	{
		//Note : Add a time function to get the velocity over time
		Velocity_Electron = InitialVelocity_Electron + (Acceleration_Electron * Time_SecondsFromEpoch);
		Displacement_Electron = (InitialVelocity_Electron * Time_SecondsFromEpoch) + (0.5f*Acceleration_Electron * (Time_SecondsFromEpoch*Time_SecondsFromEpoch));

		printf("\n%lf\n%lf", Velocity_Electron, Displacement_Electron);
	}

#pragma endregion




	void TimeDependedCalcs(unsigned long int Time_SecondsFromEpoch)
	{
		DistanceTravelled_Electron = (abs(Force_Electron) / (2 * ELECTRON_MASS)) * pow(Time_SecondsFromEpoch, 2);
	}


	
	void ElectronMovement_Perpendicular(double InitialVelocity_Electron, unsigned int Time_Epoch)
	{
		HorizontalDisplacement_X_ElectricField_Perpendicular = InitialVelocity_Electron * Time_Epoch;
		VerticalDisplacement_Y_ElectricField_Perpendicular = (abs(Force_Electron) / 2 * ELECTRON_MASS) * (pow(2, Time_Epoch));
		VerticalDisplacement_LeavingElectricField = (ELECTRON_ENERGY / 2 * ELECTRON_MASS) * Energy_Electron * (ElectronPlateWidth_L/pow(InitialVelocity_Electron,2));
	}