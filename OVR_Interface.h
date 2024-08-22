#pragma once

#include "OVR_Types.h"
#include <atomic>
#include <vector>

#define OVR_INTERFACE_IREFCOUNTED_IMPL \
  private: \
    std::atomic<int> RefCount = {1}; \
  public: \
    void AddRef() { \
      RefCount.fetch_add(1, std::memory_order_relaxed); \
    } \
    void Release() { \
      if (RefCount.fetch_add(-1, std::memory_order_relaxed) - 1 == 0) { \
        delete this; \
      } \
    }

namespace OVRInterface {

class IRefCounted {
public:
  virtual ~IRefCounted() = default;
  virtual void AddRef() = 0;
  virtual void Release() = 0;
};
class IUnknown : public IRefCounted {
public:
  virtual void IUnknown_Unk03() { delete this; }
  virtual void* QueryInterface(uint64_t iid) = 0;
};

class IInterfaceFactory : public IUnknown {
public:
  virtual void* GetInterface(void** outInterface, uint64_t classId) = 0;
};

class IAggregateInterfaceFactory : public IInterfaceFactory {
public:
  virtual ovrBool IAggregateInterfaceFactory_Unk06(__int64* count, ovrInterfaceDesc* a3, uint64_t iid) = 0;
  virtual void RegisterInterface(IInterfaceFactory* factory, ovrInterfaceDesc* desc) = 0;
  
  // TODO(Kaitlyn): These are stubbed for now.
  virtual void IAggregateInterfaceFactory_Unk08() {}
  virtual void IAggregateInterfaceFactory_Unk09() {}
  virtual void IAggregateInterfaceFactory_Unk10() {}
  virtual void IAggregateInterfaceFactory_Unk11() {}
};

// TODO(Kaitlyn): Cleanup, this class is poorly RE'd and barely works.
class OVRAggregateInterfaceFactory : public IAggregateInterfaceFactory {
  OVR_INTERFACE_IREFCOUNTED_IMPL

private:
  // No clue what this is actually called.
  typedef struct ovrInterfaceDesc2_ {
    IInterfaceFactory* Factory;
    ovrInterfaceDesc Desc;
  } ovrInterfaceDesc2;

  std::vector<ovrInterfaceDesc2> Interfaces = {};

public:
  void* QueryInterface(uint64_t iid) {
    if (iid - 1 <= 3) {
      return this;
    }
    return nullptr;
  }

  void* GetInterface(void** outInterface, uint64_t classId) {
    for (auto it = Interfaces.begin(); it != Interfaces.end(); it++) {
      if (it->Desc.ClassId == classId) {
        it->Factory->GetInterface(&*outInterface, classId);
        return outInterface;
      }
    }

    *outInterface = 0;
    return outInterface;
  }

  ovrBool IAggregateInterfaceFactory_Unk06(__int64* count, ovrInterfaceDesc* a3, uint64_t iid) {
    __int64 v4 = *count;
    *count = 0LL;

    auto it = Interfaces.begin();
    if (it == Interfaces.end()) {
      return ovrTrue;
    }

    while (true) {
      if (iid != -1 &&
          (*it).Desc.InterfaceId != iid &&
          (*it).Desc.Reserved1 != iid &&
          (*it).Desc.Reserved2 != iid &&
          (*it).Desc.Reserved3 != iid) {
        goto iterateVector;
      }

      if (a3) {
        break;
      }

    incrementCount:
      ++*count;

    iterateVector:
      if (++it == Interfaces.end()) {
        return ovrTrue;
      }
    }

    if (*count != v4) {
      a3[*count] = (*it).Desc;
      goto incrementCount;
    }
    return ovrFalse;
  }

  void RegisterInterface(IInterfaceFactory* factory, ovrInterfaceDesc* desc) {
    ovrInterfaceDesc2 interfaceDesc;
    interfaceDesc.Factory = factory;
    interfaceDesc.Desc = *desc;
    Interfaces.push_back(interfaceDesc);
  }
};

class OVRInterfaceManager : public OVRAggregateInterfaceFactory {
public:
  // ...
};

} // OVRInterface
