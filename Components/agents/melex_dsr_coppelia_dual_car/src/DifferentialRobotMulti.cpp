//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.3
//
// <auto-generated>
//
// Generated from file `DifferentialRobotMulti.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <DifferentialRobotMulti.h>
#include <IceUtil/PushDisableWarnings.h>
#include <Ice/LocalException.h>
#include <Ice/ValueFactory.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/InputStream.h>
#include <Ice/OutputStream.h>
#include <Ice/LocalException.h>
#include <IceUtil/PopDisableWarnings.h>

#if defined(_MSC_VER)
#   pragma warning(disable:4458) // declaration of ... hides class member
#elif defined(__clang__)
#   pragma clang diagnostic ignored "-Wshadow"
#elif defined(__GNUC__)
#   pragma GCC diagnostic ignored "-Wshadow"
#endif

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 307
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 >= 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 3
#       error Ice patch level mismatch!
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace
{

const ::std::string iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_ids[2] =
{
    "::Ice::Object",
    "::RoboCompDifferentialRobotMulti::DifferentialRobotMulti"
};
const ::std::string iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_ops[] =
{
    "getBaseState",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "setSpeedBase"
};
const ::std::string iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_getBaseState_name = "getBaseState";
const ::std::string iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_setSpeedBase_name = "setSpeedBase";

}

bool
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::ice_isA(::std::string s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_ids, iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_ids + 2, s);
}

::std::vector<::std::string>
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector<::std::string>(&iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_ids[0], &iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_ids[2]);
}

::std::string
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::ice_staticId()
{
    static const ::std::string typeId = "::RoboCompDifferentialRobotMulti::DifferentialRobotMulti";
    return typeId;
}

/// \cond INTERNAL
bool
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::_iceD_getBaseState(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    int iceP_robotid;
    istr->readAll(iceP_robotid);
    inS.endReadParams();
    ::RoboCompGenericBase::TBaseState iceP_state;
    this->getBaseState(iceP_robotid, iceP_state, current);
    auto ostr = inS.startWriteParams();
    ostr->writeAll(iceP_state);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::_iceD_setSpeedBase(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    int iceP_robotid;
    float iceP_adv;
    float iceP_rot;
    istr->readAll(iceP_robotid, iceP_adv, iceP_rot);
    inS.endReadParams();
    this->setSpeedBase(iceP_robotid, iceP_adv, iceP_rot, current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_ops, iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_ops + 6, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_ops)
    {
        case 0:
        {
            return _iceD_getBaseState(in, current);
        }
        case 1:
        {
            return _iceD_ice_id(in, current);
        }
        case 2:
        {
            return _iceD_ice_ids(in, current);
        }
        case 3:
        {
            return _iceD_ice_isA(in, current);
        }
        case 4:
        {
            return _iceD_ice_ping(in, current);
        }
        case 5:
        {
            return _iceD_setSpeedBase(in, current);
        }
        default:
        {
            assert(false);
            throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
        }
    }
}
/// \endcond

/// \cond INTERNAL
void
RoboCompDifferentialRobotMulti::DifferentialRobotMultiPrx::_iceI_getBaseState(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<::RoboCompGenericBase::TBaseState>>& outAsync, int iceP_robotid, const ::Ice::Context& context)
{
    _checkTwowayOnly(iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_getBaseState_name);
    outAsync->invoke(iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_getBaseState_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_robotid);
        },
        [](const ::Ice::UserException& ex)
        {
            try
            {
                ex.ice_throw();
            }
            catch(const ::RoboCompGenericBase::HardwareFailedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException&)
            {
            }
        });
}
/// \endcond

/// \cond INTERNAL
void
RoboCompDifferentialRobotMulti::DifferentialRobotMultiPrx::_iceI_setSpeedBase(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, int iceP_robotid, float iceP_adv, float iceP_rot, const ::Ice::Context& context)
{
    _checkTwowayOnly(iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_setSpeedBase_name);
    outAsync->invoke(iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_setSpeedBase_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_robotid, iceP_adv, iceP_rot);
        },
        [](const ::Ice::UserException& ex)
        {
            try
            {
                ex.ice_throw();
            }
            catch(const ::RoboCompGenericBase::HardwareFailedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException&)
            {
            }
        });
}
/// \endcond

/// \cond INTERNAL
::std::shared_ptr<::Ice::ObjectPrx>
RoboCompDifferentialRobotMulti::DifferentialRobotMultiPrx::_newInstance() const
{
    return ::IceInternal::createProxy<DifferentialRobotMultiPrx>();
}
/// \endcond

const ::std::string&
RoboCompDifferentialRobotMulti::DifferentialRobotMultiPrx::ice_staticId()
{
    return DifferentialRobotMulti::ice_staticId();
}

namespace Ice
{
}

#else // C++98 mapping

namespace
{

const ::std::string iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_getBaseState_name = "getBaseState";

const ::std::string iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_setSpeedBase_name = "setSpeedBase";

}

/// \cond INTERNAL
::IceProxy::Ice::Object* ::IceProxy::RoboCompDifferentialRobotMulti::upCast(DifferentialRobotMulti* p) { return p; }

void
::IceProxy::RoboCompDifferentialRobotMulti::_readProxy(::Ice::InputStream* istr, ::IceInternal::ProxyHandle< DifferentialRobotMulti>& v)
{
    ::Ice::ObjectPrx proxy;
    istr->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new DifferentialRobotMulti;
        v->_copyFrom(proxy);
    }
}
/// \endcond

::Ice::AsyncResultPtr
IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::_iceI_begin_getBaseState(::Ice::Int iceP_robotid, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    _checkTwowayOnly(iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_getBaseState_name, sync);
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_getBaseState_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_getBaseState_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_robotid);
        result->endWriteParams();
        result->invoke(iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_getBaseState_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::end_getBaseState(::RoboCompGenericBase::TBaseState& iceP_state, const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_getBaseState_name);
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::RoboCompGenericBase::HardwareFailedException&)
        {
            throw;
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(iceP_state);
    result->_endReadParams();
}

void IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::_iceI_end_getBaseState(::RoboCompGenericBase::TBaseState& iceP_state, const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_getBaseState_name);
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::RoboCompGenericBase::HardwareFailedException&)
        {
            throw;
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(iceP_state);
    result->_endReadParams();
}

::Ice::AsyncResultPtr
IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::_iceI_begin_setSpeedBase(::Ice::Int iceP_robotid, ::Ice::Float iceP_adv, ::Ice::Float iceP_rot, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    _checkTwowayOnly(iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_setSpeedBase_name, sync);
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_setSpeedBase_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_setSpeedBase_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_robotid);
        ostr->write(iceP_adv);
        ostr->write(iceP_rot);
        result->endWriteParams();
        result->invoke(iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_setSpeedBase_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::end_setSpeedBase(const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_setSpeedBase_name);
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::RoboCompGenericBase::HardwareFailedException&)
        {
            throw;
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    result->_readEmptyParams();
}

/// \cond INTERNAL
::IceProxy::Ice::Object*
IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::_newInstance() const
{
    return new DifferentialRobotMulti;
}
/// \endcond

const ::std::string&
IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::ice_staticId()
{
    return ::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::ice_staticId();
}

RoboCompDifferentialRobotMulti::DifferentialRobotMulti::~DifferentialRobotMulti()
{
}

/// \cond INTERNAL
::Ice::Object* RoboCompDifferentialRobotMulti::upCast(DifferentialRobotMulti* p) { return p; }

/// \endcond

namespace
{
const ::std::string iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_ids[2] =
{
    "::Ice::Object",
    "::RoboCompDifferentialRobotMulti::DifferentialRobotMulti"
};

}

bool
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::ice_isA(const ::std::string& s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_ids, iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_ids + 2, s);
}

::std::vector< ::std::string>
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_ids[0], &iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_ids[2]);
}

const ::std::string&
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::ice_staticId()
{
#ifdef ICE_HAS_THREAD_SAFE_LOCAL_STATIC
    static const ::std::string typeId = "::RoboCompDifferentialRobotMulti::DifferentialRobotMulti";
    return typeId;
#else
    return iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_ids[1];
#endif
}

/// \cond INTERNAL
bool
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::_iceD_getBaseState(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    ::Ice::Int iceP_robotid;
    istr->read(iceP_robotid);
    inS.endReadParams();
    ::RoboCompGenericBase::TBaseState iceP_state;
    this->getBaseState(iceP_robotid, iceP_state, current);
    ::Ice::OutputStream* ostr = inS.startWriteParams();
    ostr->write(iceP_state);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::_iceD_setSpeedBase(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    ::Ice::Int iceP_robotid;
    ::Ice::Float iceP_adv;
    ::Ice::Float iceP_rot;
    istr->read(iceP_robotid);
    istr->read(iceP_adv);
    istr->read(iceP_rot);
    inS.endReadParams();
    this->setSpeedBase(iceP_robotid, iceP_adv, iceP_rot, current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

namespace
{
const ::std::string iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_all[] =
{
    "getBaseState",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "setSpeedBase"
};

}

/// \cond INTERNAL
bool
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_all, iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_all + 6, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_RoboCompDifferentialRobotMulti_DifferentialRobotMulti_all)
    {
        case 0:
        {
            return _iceD_getBaseState(in, current);
        }
        case 1:
        {
            return _iceD_ice_id(in, current);
        }
        case 2:
        {
            return _iceD_ice_ids(in, current);
        }
        case 3:
        {
            return _iceD_ice_isA(in, current);
        }
        case 4:
        {
            return _iceD_ice_ping(in, current);
        }
        case 5:
        {
            return _iceD_setSpeedBase(in, current);
        }
        default:
        {
            assert(false);
            throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
        }
    }
}
/// \endcond

/// \cond STREAM
void
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::_iceWriteImpl(::Ice::OutputStream* ostr) const
{
    ostr->startSlice(ice_staticId(), -1, true);
    ::Ice::StreamWriter< DifferentialRobotMulti, ::Ice::OutputStream>::write(ostr, *this);
    ostr->endSlice();
}

void
RoboCompDifferentialRobotMulti::DifferentialRobotMulti::_iceReadImpl(::Ice::InputStream* istr)
{
    istr->startSlice();
    ::Ice::StreamReader< DifferentialRobotMulti, ::Ice::InputStream>::read(istr, *this);
    istr->endSlice();
}
/// \endcond

/// \cond INTERNAL
void
RoboCompDifferentialRobotMulti::_icePatchObjectPtr(DifferentialRobotMultiPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = DifferentialRobotMultiPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(DifferentialRobotMulti::ice_staticId(), v);
    }
}
/// \endcond

namespace Ice
{
}

#endif