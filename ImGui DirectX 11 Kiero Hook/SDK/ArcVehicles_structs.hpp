#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ArcVehicles

#include "Basic.hpp"

#include "Engine_structs.hpp"


namespace SDK
{

// Enum ArcVehicles.EArcVehicleSeatChangeType
// NumValues: 0x0005
enum class EArcVehicleSeatChangeType : uint8
{
	Invalid                                  = 0,
	EnterVehicle                             = 1,
	ExitVehicle                              = 2,
	SwitchSeats                              = 3,
	EArcVehicleSeatChangeType_MAX            = 4,
};

// ScriptStruct ArcVehicles.ArcVehicleSeatChangeEvent
// 0x0018 (0x0018 - 0x0000)
struct FArcVehicleSeatChangeEvent final 
{
public:
	uint8                                         Pad_126C[0x10];                                    // 0x0000(0x0010)(Fixing Size After Last Property [ Dumper-7 ])
	class APlayerState*                           Player;                                            // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
//(alignof(FArcVehicleSeatChangeEvent) == 0x000008, "Wrong alignment on FArcVehicleSeatChangeEvent");
//(sizeof(FArcVehicleSeatChangeEvent) == 0x000018, "Wrong size on FArcVehicleSeatChangeEvent");
//(offsetof(FArcVehicleSeatChangeEvent, Player) == 0x000010, "Member 'FArcVehicleSeatChangeEvent::Player' has a wrong offset!");

// ScriptStruct ArcVehicles.ArcVehicleTurretMovementPostPhysicsTickFunction
// 0x0008 (0x0030 - 0x0028)
struct FArcVehicleTurretMovementPostPhysicsTickFunction final  : public FTickFunction
{
public:
	uint8                                         Pad_126D[0x8];                                     // 0x0028(0x0008)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
//(alignof(FArcVehicleTurretMovementPostPhysicsTickFunction) == 0x000008, "Wrong alignment on FArcVehicleTurretMovementPostPhysicsTickFunction");
//(sizeof(FArcVehicleTurretMovementPostPhysicsTickFunction) == 0x000030, "Wrong size on FArcVehicleTurretMovementPostPhysicsTickFunction");

// ScriptStruct ArcVehicles.ArcVehicleSeatReference
// 0x0010 (0x0010 - 0x0000)
struct FArcVehicleSeatReference final 
{
public:
	class AArcBaseVehicle*                        Vehicle;                                           // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         SeatID;                                            // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_126E[0x4];                                     // 0x000C(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
//(alignof(FArcVehicleSeatReference) == 0x000008, "Wrong alignment on FArcVehicleSeatReference");
//(sizeof(FArcVehicleSeatReference) == 0x000010, "Wrong size on FArcVehicleSeatReference");
//(offsetof(FArcVehicleSeatReference, Vehicle) == 0x000000, "Member 'FArcVehicleSeatReference::Vehicle' has a wrong offset!");
//(offsetof(FArcVehicleSeatReference, SeatID) == 0x000008, "Member 'FArcVehicleSeatReference::SeatID' has a wrong offset!");

// ScriptStruct ArcVehicles.ArcOwnerAttachmentReference
// 0x0010 (0x0010 - 0x0000)
struct FArcOwnerAttachmentReference final 
{
public:
	class FName                                   ComponentName;                                     // 0x0000(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   SocketName;                                        // 0x0008(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
//(alignof(FArcOwnerAttachmentReference) == 0x000004, "Wrong alignment on FArcOwnerAttachmentReference");
//(sizeof(FArcOwnerAttachmentReference) == 0x000010, "Wrong size on FArcOwnerAttachmentReference");
//(offsetof(FArcOwnerAttachmentReference, ComponentName) == 0x000000, "Member 'FArcOwnerAttachmentReference::ComponentName' has a wrong offset!");
//(offsetof(FArcOwnerAttachmentReference, SocketName) == 0x000008, "Member 'FArcOwnerAttachmentReference::SocketName' has a wrong offset!");

}
