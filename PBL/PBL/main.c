#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

#include "BasicCalc.h"

#pragma warning (disable :4996) //disabling warning for safe function declarations
void Perpendicular_ElectricField(float, float, double);
void Projectile_ElectricField(float,float, double);
void Parallel_ElectricField(float, float);

struct Variables
{
	double *PotentialDifference;
	double *PlateDistance;
	double *InitialVelocity;
	float  *Time_Seconds;
	float  *StepSize;
	
};


int main(int argc,char* argv[])
{
	
	/* Backup in case the structure doesn't work
	double *PotentialDifference   = (double *)malloc(sizeof(double)); //allocating memory for velocity variable
    double *PlateDistance		  = (double *)malloc(sizeof(double)); //allocating memory for PlateDistance
    float  *Time_Seconds		  = (float *)malloc(sizeof(float)); //allocating memory for Time
    float  *StepSize			  = (float *)malloc(sizeof(float)); //assinging memory for Step Size
    double *InitialVelocity		  = (double *)malloc(sizeof(double)); //allocating memory for InitialVelocity
	
	*/
	struct Variables *RequiredVariables		 = (struct Variables *)malloc(sizeof(struct Variables));

	//struct Variables RequiredVariables;
	RequiredVariables->PotentialDifference   = (double *)malloc(sizeof(double));
	RequiredVariables->PlateDistance		 = (double *)malloc(sizeof(double));
	RequiredVariables->InitialVelocity		 = (double *)malloc(sizeof(double));
	RequiredVariables->Time_Seconds			 = (float *)malloc(sizeof(float));
	RequiredVariables->StepSize				 = (float *)malloc(sizeof(float));

	int choice;

#pragma region Input Section
	/*
	Note 1: All the units should be in their standard units
	

	Note 2 : Step Size is the update interval between the calculations.
	*/

	printf("\nEnter the values in their standard units");


	printf("\nEnter the Potential Difference between the plates");
	scanf("%lf", RequiredVariables->PotentialDifference); // In volts 

	printf("\nEnter the distance between the plate distance");
	scanf("%lf",RequiredVariables->PlateDistance); // In meters
	
	printf("\nEnter the Initial Velocity of the electron");
	scanf("%lf", RequiredVariables->InitialVelocity);

	printf("\nEnter the time you want to simulate for");
	scanf("%f",RequiredVariables->Time_Seconds);

	printf("\nEnter the step size");
	scanf("%f", RequiredVariables->StepSize); // stupid issue of not seeing that it was using **float has been resolved
#pragma endregion


	//Function calls for basic math
	Basic_Calculations(*RequiredVariables->PotentialDifference, *RequiredVariables->PlateDistance);//passing values of velocity and platedistance
	//Velocity_Disp_Calc(*RequiredVariables->InitialVelocity, *RequiredVariables->Time_Seconds);


	//Freeing Allocating memory
	free(RequiredVariables->PotentialDifference);
	free(RequiredVariables->PlateDistance);


	printf("\n1: Perpendicular Field\n2: Projectile Electric Field");
	scanf("%d", &choice);


	switch (choice)
	{
	case 1 :
		Parallel_ElectricField(*RequiredVariables->StepSize, *RequiredVariables->Time_Seconds);
		break;
	case 2 : 
		Perpendicular_ElectricField(*RequiredVariables->StepSize, *RequiredVariables->Time_Seconds,*RequiredVariables->InitialVelocity);
		break;

	case 3 : 
		Projectile_ElectricField(*RequiredVariables->StepSize,*RequiredVariables->Time_Seconds, *RequiredVariables->InitialVelocity);
		break;

	default : 
		return  EXIT_FAILURE;
		break;
	}
	
	free(RequiredVariables->StepSize); 
	free(RequiredVariables->InitialVelocity);
	
	system("pause");

}

void Perpendicular_ElectricField(float StepSize, float Time_Seconds,double InitialVelocity)
{
	float count = 0.0f;
	while (count <= Time_Seconds)
	{
		ElectronMovement_Perpendicular(InitialVelocity, count);
		//Sleep(StepSize * 1000); //for real-time simulation
		count+=StepSize;
	}
	
}

void Projectile_ElectricField(float StepSize,float Time_Seconds, double InitialVelocity)
{
	float count = 0.0f;
	float *ProjectionAngle = (float *)malloc(sizeof(float));
	
	printf("\nEnter the projection angle");
	scanf("%f", ProjectionAngle);


	while (count <= Time_Seconds)
	{
		ElectronMovement_Projectile(InitialVelocity, *ProjectionAngle, count);
		//Sleep(StepSize * 1000); //for realtime simulation
		count += StepSize;
	}

	free(ProjectionAngle);
}

void Parallel_ElectricField(float StepSize,float Time_Seconds)
{
	float count = 0.0f;

	while (count <= Time_Seconds)
	{
		ElectronMovement_Parallel(count);
		count += StepSize;
	}
}