#pragma once
#include "Builder.h"

class Director
{
public:
	void BuildUp(Builder& builder)
	{
		builder.BuildComputer();
		builder.AddCpu();
		builder.AddMainboard();
		builder.AddMemory();
		builder.AddGpu();
		builder.AddStorage();
		builder.AddPowersupply();
		builder.AddRadiator();
		builder.AddCase();
	}
};