#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PhysicsCore

#include "Basic.hpp"


namespace SDK
{

// Enum PhysicsCore.EChaosBufferMode
// NumValues: 0x0005
enum class EChaosBufferMode : uint8
{
	Double                                   = 0,
	Triple                                   = 1,
	Num                                      = 2,
	Invalid                                  = 3,
	EChaosBufferMode_MAX                     = 4,
};

// Enum PhysicsCore.EChaosThreadingMode
// NumValues: 0x0006
enum class EChaosThreadingMode : uint8
{
	DedicatedThread                          = 0,
	TaskGraph                                = 1,
	SingleThread                             = 2,
	Num                                      = 3,
	Invalid                                  = 4,
	EChaosThreadingMode_MAX                  = 5,
};

// Enum PhysicsCore.EChaosSolverTickMode
// NumValues: 0x0005
enum class EChaosSolverTickMode : uint8
{
	Fixed                                    = 0,
	Variable                                 = 1,
	VariableCapped                           = 2,
	VariableCappedWithTarget                 = 3,
	EChaosSolverTickMode_MAX                 = 4,
};

}
