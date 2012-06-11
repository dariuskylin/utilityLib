/**
 * @file SharedLibrary.h
 * @comment
 * 
 * @author niexw
 */

#ifndef _XCOM_SHAREDLIBRARY_H_
#define _XCOM_SHAREDLIBRARY_H_

#include "Policies.h"
#include <string>

namespace xcom
{

#include <dlfcn.h>

BEGIN_DECLARE_INTERFACE(ISharedLibrary, IUnknown)
	virtual bool isLoaded() = 0;
	virtual long load(const char *name) = 0;
	virtual bool unload() = 0;
	virtual void* symbol(const char *str) = 0;
	virtual long lock(bool lo) = 0;
END_DECLARE_INTERFACE(ISharedLibrary)

DEFINE_POLICY(Class, PSharedLibrary)
{
protected:
	void *handle_;
	std::string path_;
	bool locked_;

public:
	PSharedLibrary() : handle_(NULL), locked_(false)
	{ }
	~PSharedLibrary()
	{ if (handle_ != NULL && !locked_) unload(); }

	bool isLoaded()
	{ return handle_ != NULL; }

	long load(const char *name)
	{
		if (path_ == name && handle_ != NULL)
			return SUCCESS;
		else
		{
			unload();
			handle_ = dlopen(name, RTLD_LAZY | RTLD_LOCAL);
			if (handle_ == NULL)
				return ERROR;
			path_ = name;
			return SUCCESS;
		}
	}

	bool unload()
	{
		ulong ret = false;
		if (handle_ != NULL)
			ret = (dlclose(handle_) == 0);
		handle_ = NULL;
		path_.clear();
		return ret;
	}

	void* symbol(const char *name)
	{ return dlsym(handle_, name); }

	long lock(bool lo)
	{ return SUCCESS; }
};

class SharedLibrary : public Component<ComponentTraits
	< Interfaces<ISharedLibrary>::type
	, Policies<SharedLibrary, PUnknown, PFactory, PSharedLibrary>::type> >
{ };
extern ClsID const CLSID_SharedLibrary;

}; // namespace xcom
#endif /* _XCOM_SHAREDLIBRARY_H_ */
