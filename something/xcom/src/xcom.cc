/**
 * @file xcom.cc
 * @comment
 * 
 * @author niexw
 */

#include "Interfaces.h"
#include "SharedLibrary.h"
#include "Registry.h"

namespace xcom
{

DEFINE_INTERFACE_ID(IUnknown, "00000000-0000-0000-C000-000000000046");
DEFINE_INTERFACE_ID(IFactory, "00000001-0000-0000-C000-000000000046");
DEFINE_INTERFACE_ID(ISharedLibrary, "667fc98b-4511-4aeb-a066-a0e2cf3f8ca7");
DEFINE_INTERFACE_ID(IRegistry, "8675bb2a-0974-4040-85cf-912b4d491c38");

DEFINE_CLASS_ID(SharedLibrary, "b36e2004-7116-4044-aa99-33a10b2a6129");
DEFINE_CLASS_ID(Registry, "596d84ee-91bd-40ec-ab41-0bd81987fd1e");

}; // namespace xcom
