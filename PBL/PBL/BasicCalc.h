#pragma once
#include <stdio.h>
#include <conio.h>
#include <math.h> 
#include <Windows.h>



#define ELECTRON_MASS 9.109E-31
#define ELECTRON_ENERGY 1.6E-19



double Energy_Electron = 0.0f; 
double Force_Electron = 0.0f;
double Acceleration_Electron = 0.0f;
double Velocity_Electron_TMAX = 0.0f;
double Displacement_Electron = 0.0f; 
double DistanceTravelled_Electron = 0.0f;


#pragma region Perpendicular Electric Field
double VerticalDisplacement_Y_ElectricField_Perpendicular = 0.0f;
double HorizontalDisplacement_X_ElectricField_Perpendicular = 0.0f;
double VerticalDisplacement_LeavingElectricField = 0.0f;
const double ElectronPlateWidth_L = 0.5f;
#pragma endregion


#pragma region Electron Prjected at an angle Electric Field
double HorizontalComponent_X_ElectrincField_Projection = 0.0f;
double VerticalCompoenet_Y_ElectricField_Projection = 0.0f;
double MaxVerticalDisplacement_Y_ElectricField_Projection = 0.0f;
double TimeTakenForMaxVerticalDisplacement_ElectricField_Projection = 0.0f;
double TimeOfFlightOfElectron_ElectricField_Projection = 0.0f;
double RangeOfElectron_ElectricField_Projection = 0.0f;
#pragma endregion

#pragma region Basic Calculations
	void Basic_Calculations(double PotentialDifference, double PlateDistance)
	{
		Energy_Electron = PotentialDifference / PlateDistance; //Energy of the electron
		Force_Electron = -1 * ELECTRON_ENERGY * Energy_Electron; //Force of the electorn on plate B ( The plate form which the electron enters into the field)
		Acceleration_Electron = fabs(Force_Electron) / ELECTRON_MASS; //Acceleration of the electron: negating by -1 to get a positive result for acceleration

		printf("\n%g", Energy_Electron);
		printf("\n%g", Force_Electron);
		printf("\n%g", Acceleration_Electron);

	}
#pragma endregion

#pragma region Parallel Electric Field
	void Velocity_Disp_Calc(double InitialVelocity_Electron, float Time_SecondsFromEpoch)
	{
		//Note : Add a time function to get the velocity over time
		Velocity_Electron_TMAX = InitialVelocity_Electron + (Acceleration_Electron * Time_SecondsFromEpoch);
		Displacement_Electron = (InitialVelocity_Electron * Time_SecondsFromEpoch) + (0.5f*Acceleration_Electron * (Time_SecondsFromEpoch*Time_SecondsFromEpoch));

		printf("\n%g\n%g", Velocity_Electron_TMAX, Displacement_Electron);
	}

#pragma endregion


	void TimeDependedCalcs(unsigned long int Time_SecondsFromEpoch)
	{
		DistanceTravelled_Electron = -1*(Force_Electron) / (2 * ELECTRON_MASS) * pow(Time_SecondsFromEpoch, 2);
	}


	
	void ElectronMovement_Perpendicular(double InitialVelocity_Electron,  float Time_Epoch)
	{
		
			HorizontalDisplacement_X_ElectricField_Perpendicular = InitialVelocity_Electron * Time_Epoch;
			VerticalDisplacement_Y_ElectricField_Perpendicular = -1 * (Force_Electron / 2 * ELECTRON_MASS) * Time_Epoch * Time_Epoch;
			VerticalDisplacement_LeavingElectricField = (ELECTRON_ENERGY / 2 * ELECTRON_MASS) * Energy_Electron * (ElectronPlateWidth_L / pow(InitialVelocity_Electron, 2));

			//printf("\n\n");
			//printf("\nHorizontal Disp : %g", HorizontalDisplacement_X_ElectricField_Perpendicular);
			//printf("\nVertical Disp : %g", VerticalDisplacement_Y_ElectricField_Perpendicular);
			//printf("\nVertical Displacement Leaving : %g", VerticalDisplacement_LeavingElectricField);
			//printf("\nTime : %f", Time_Epoch);
	}

	void ElectronMovement_Projectile(double InitialVelocity_Electron, float ProjectionAngle_Electron,float Time_Seconds)
	{
		
		double *Vx0 = (double *)malloc(sizeof(double));
		double *Vy0 = (double *)malloc(sizeof(double));

		*Vx0 = InitialVelocity_Electron * sin(ProjectionAngle_Electron);
		*Vy0 = InitialVelocity_Electron * cos(ProjectionAngle_Electron) * Time_Seconds;

		HorizontalComponent_X_ElectrincField_Projection = *Vx0 * Time_Seconds;
		VerticalCompoenet_Y_ElectricField_Projection = *Vy0 + (0.5 * Acceleration_Electron * pow(Time_Seconds, 2));

		free(Vx0);
		free(Vy0);

		printf("\n\n");
		printf("\nHorizontal Componenet : %g\nVertical Component :  %g\nTime Since Epoch : %g", HorizontalComponent_X_ElectrincField_Projection, VerticalCompoenet_Y_ElectricField_Projection, Time_Seconds);

		//MaxVerticalDisplacement_Y_ElectricField_Projection = ((pow(InitialVelocity_Electron, 2)) * (pow(sin(ProjectionAngle_Electron), 2))) / 2 * Acceleration_Electron;
		//TimeTakenForMaxVerticalDisplacement_ElectricField_Projection = (InitialVelocity_Electron * sin(ProjectionAngle_Electron)) / Acceleration_Electron;
		//
		//
		//TimeOfFlightOfElectron_ElectricField_Projection = 2 * TimeTakenForMaxVerticalDisplacement_ElectricField_Projection;
		//RangeOfElectron_ElectricField_Projection = (2 * sin(ProjectionAngle_Electron) * cos(ProjectionAngle_Electron) * pow(InitialVelocity_Electron, 2) ) / Acceleration_Electron;
	
		


		
	
	}