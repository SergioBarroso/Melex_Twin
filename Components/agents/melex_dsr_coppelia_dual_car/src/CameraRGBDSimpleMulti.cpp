//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.3
//
// <auto-generated>
//
// Generated from file `CameraRGBDSimpleMulti.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <CameraRGBDSimpleMulti.h>
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

const ::IceInternal::DefaultUserExceptionFactoryInit<::RoboCompCameraRGBDSimpleMulti::HardwareFailedException> iceC_RoboCompCameraRGBDSimpleMulti_HardwareFailedException_init("::RoboCompCameraRGBDSimpleMulti::HardwareFailedException");

const ::std::string iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_ids[2] =
{
    "::Ice::Object",
    "::RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti"
};
const ::std::string iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_ops[] =
{
    "getAll",
    "getDepth",
    "getImage",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};
const ::std::string iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getAll_name = "getAll";
const ::std::string iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getDepth_name = "getDepth";
const ::std::string iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getImage_name = "getImage";

}

RoboCompCameraRGBDSimpleMulti::HardwareFailedException::~HardwareFailedException()
{
}

const ::std::string&
RoboCompCameraRGBDSimpleMulti::HardwareFailedException::ice_staticId()
{
    static const ::std::string typeId = "::RoboCompCameraRGBDSimpleMulti::HardwareFailedException";
    return typeId;
}

bool
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::ice_isA(::std::string s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_ids, iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_ids + 2, s);
}

::std::vector<::std::string>
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector<::std::string>(&iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_ids[0], &iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_ids[2]);
}

::std::string
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::ice_staticId()
{
    static const ::std::string typeId = "::RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti";
    return typeId;
}

/// \cond INTERNAL
bool
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::_iceD_getAll(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    int iceP_robotid;
    ::std::string iceP_camera;
    istr->readAll(iceP_robotid, iceP_camera);
    inS.endReadParams();
    TRGBD ret = this->getAll(iceP_robotid, ::std::move(iceP_camera), current);
    auto ostr = inS.startWriteParams();
    ostr->writeAll(ret);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::_iceD_getDepth(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    int iceP_robotid;
    ::std::string iceP_camera;
    istr->readAll(iceP_robotid, iceP_camera);
    inS.endReadParams();
    TDepth ret = this->getDepth(iceP_robotid, ::std::move(iceP_camera), current);
    auto ostr = inS.startWriteParams();
    ostr->writeAll(ret);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::_iceD_getImage(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    int iceP_robotid;
    ::std::string iceP_camera;
    istr->readAll(iceP_robotid, iceP_camera);
    inS.endReadParams();
    TImage ret = this->getImage(iceP_robotid, ::std::move(iceP_camera), current);
    auto ostr = inS.startWriteParams();
    ostr->writeAll(ret);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_ops, iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_ops + 7, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_ops)
    {
        case 0:
        {
            return _iceD_getAll(in, current);
        }
        case 1:
        {
            return _iceD_getDepth(in, current);
        }
        case 2:
        {
            return _iceD_getImage(in, current);
        }
        case 3:
        {
            return _iceD_ice_id(in, current);
        }
        case 4:
        {
            return _iceD_ice_ids(in, current);
        }
        case 5:
        {
            return _iceD_ice_isA(in, current);
        }
        case 6:
        {
            return _iceD_ice_ping(in, current);
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
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMultiPrx::_iceI_getAll(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<::RoboCompCameraRGBDSimpleMulti::TRGBD>>& outAsync, int iceP_robotid, const ::std::string& iceP_camera, const ::Ice::Context& context)
{
    _checkTwowayOnly(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getAll_name);
    outAsync->invoke(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getAll_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_robotid, iceP_camera);
        },
        [](const ::Ice::UserException& ex)
        {
            try
            {
                ex.ice_throw();
            }
            catch(const HardwareFailedException&)
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
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMultiPrx::_iceI_getDepth(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<::RoboCompCameraRGBDSimpleMulti::TDepth>>& outAsync, int iceP_robotid, const ::std::string& iceP_camera, const ::Ice::Context& context)
{
    _checkTwowayOnly(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getDepth_name);
    outAsync->invoke(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getDepth_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_robotid, iceP_camera);
        },
        [](const ::Ice::UserException& ex)
        {
            try
            {
                ex.ice_throw();
            }
            catch(const HardwareFailedException&)
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
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMultiPrx::_iceI_getImage(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<::RoboCompCameraRGBDSimpleMulti::TImage>>& outAsync, int iceP_robotid, const ::std::string& iceP_camera, const ::Ice::Context& context)
{
    _checkTwowayOnly(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getImage_name);
    outAsync->invoke(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getImage_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_robotid, iceP_camera);
        },
        [](const ::Ice::UserException& ex)
        {
            try
            {
                ex.ice_throw();
            }
            catch(const HardwareFailedException&)
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
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMultiPrx::_newInstance() const
{
    return ::IceInternal::createProxy<CameraRGBDSimpleMultiPrx>();
}
/// \endcond

const ::std::string&
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMultiPrx::ice_staticId()
{
    return CameraRGBDSimpleMulti::ice_staticId();
}

namespace Ice
{
}

#else // C++98 mapping

namespace
{

const ::std::string iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getAll_name = "getAll";

const ::std::string iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getDepth_name = "getDepth";

const ::std::string iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getImage_name = "getImage";

}

namespace
{

const ::IceInternal::DefaultUserExceptionFactoryInit< ::RoboCompCameraRGBDSimpleMulti::HardwareFailedException> iceC_RoboCompCameraRGBDSimpleMulti_HardwareFailedException_init("::RoboCompCameraRGBDSimpleMulti::HardwareFailedException");

}

RoboCompCameraRGBDSimpleMulti::HardwareFailedException::HardwareFailedException(const ::std::string& what) :
    ::Ice::UserException(),
    what(what)
{
}

RoboCompCameraRGBDSimpleMulti::HardwareFailedException::~HardwareFailedException() throw()
{
}

::std::string
RoboCompCameraRGBDSimpleMulti::HardwareFailedException::ice_id() const
{
    return "::RoboCompCameraRGBDSimpleMulti::HardwareFailedException";
}

RoboCompCameraRGBDSimpleMulti::HardwareFailedException*
RoboCompCameraRGBDSimpleMulti::HardwareFailedException::ice_clone() const
{
    return new HardwareFailedException(*this);
}

void
RoboCompCameraRGBDSimpleMulti::HardwareFailedException::ice_throw() const
{
    throw *this;
}

/// \cond STREAM
void
RoboCompCameraRGBDSimpleMulti::HardwareFailedException::_writeImpl(::Ice::OutputStream* ostr) const
{
    ostr->startSlice("::RoboCompCameraRGBDSimpleMulti::HardwareFailedException", -1, true);
    ::Ice::StreamWriter< HardwareFailedException, ::Ice::OutputStream>::write(ostr, *this);
    ostr->endSlice();
}

void
RoboCompCameraRGBDSimpleMulti::HardwareFailedException::_readImpl(::Ice::InputStream* istr)
{
    istr->startSlice();
    ::Ice::StreamReader< HardwareFailedException, ::Ice::InputStream>::read(istr, *this);
    istr->endSlice();
}
/// \endcond

/// \cond INTERNAL
::IceProxy::Ice::Object* ::IceProxy::RoboCompCameraRGBDSimpleMulti::upCast(CameraRGBDSimpleMulti* p) { return p; }

void
::IceProxy::RoboCompCameraRGBDSimpleMulti::_readProxy(::Ice::InputStream* istr, ::IceInternal::ProxyHandle< CameraRGBDSimpleMulti>& v)
{
    ::Ice::ObjectPrx proxy;
    istr->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new CameraRGBDSimpleMulti;
        v->_copyFrom(proxy);
    }
}
/// \endcond

::Ice::AsyncResultPtr
IceProxy::RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::_iceI_begin_getAll(::Ice::Int iceP_robotid, const ::std::string& iceP_camera, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    _checkTwowayOnly(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getAll_name, sync);
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getAll_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getAll_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_robotid);
        ostr->write(iceP_camera);
        result->endWriteParams();
        result->invoke(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getAll_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

::RoboCompCameraRGBDSimpleMulti::TRGBD
IceProxy::RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::end_getAll(const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getAll_name);
    ::RoboCompCameraRGBDSimpleMulti::TRGBD ret;
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::RoboCompCameraRGBDSimpleMulti::HardwareFailedException&)
        {
            throw;
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(ret);
    result->_endReadParams();
    return ret;
}

::Ice::AsyncResultPtr
IceProxy::RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::_iceI_begin_getDepth(::Ice::Int iceP_robotid, const ::std::string& iceP_camera, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    _checkTwowayOnly(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getDepth_name, sync);
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getDepth_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getDepth_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_robotid);
        ostr->write(iceP_camera);
        result->endWriteParams();
        result->invoke(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getDepth_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

::RoboCompCameraRGBDSimpleMulti::TDepth
IceProxy::RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::end_getDepth(const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getDepth_name);
    ::RoboCompCameraRGBDSimpleMulti::TDepth ret;
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::RoboCompCameraRGBDSimpleMulti::HardwareFailedException&)
        {
            throw;
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(ret);
    result->_endReadParams();
    return ret;
}

::Ice::AsyncResultPtr
IceProxy::RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::_iceI_begin_getImage(::Ice::Int iceP_robotid, const ::std::string& iceP_camera, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    _checkTwowayOnly(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getImage_name, sync);
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getImage_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getImage_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_robotid);
        ostr->write(iceP_camera);
        result->endWriteParams();
        result->invoke(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getImage_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

::RoboCompCameraRGBDSimpleMulti::TImage
IceProxy::RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::end_getImage(const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_getImage_name);
    ::RoboCompCameraRGBDSimpleMulti::TImage ret;
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::RoboCompCameraRGBDSimpleMulti::HardwareFailedException&)
        {
            throw;
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(ret);
    result->_endReadParams();
    return ret;
}

/// \cond INTERNAL
::IceProxy::Ice::Object*
IceProxy::RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::_newInstance() const
{
    return new CameraRGBDSimpleMulti;
}
/// \endcond

const ::std::string&
IceProxy::RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::ice_staticId()
{
    return ::RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::ice_staticId();
}

RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::~CameraRGBDSimpleMulti()
{
}

/// \cond INTERNAL
::Ice::Object* RoboCompCameraRGBDSimpleMulti::upCast(CameraRGBDSimpleMulti* p) { return p; }

/// \endcond

namespace
{
const ::std::string iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_ids[2] =
{
    "::Ice::Object",
    "::RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti"
};

}

bool
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::ice_isA(const ::std::string& s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_ids, iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_ids + 2, s);
}

::std::vector< ::std::string>
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_ids[0], &iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_ids[2]);
}

const ::std::string&
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::ice_staticId()
{
#ifdef ICE_HAS_THREAD_SAFE_LOCAL_STATIC
    static const ::std::string typeId = "::RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti";
    return typeId;
#else
    return iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_ids[1];
#endif
}

/// \cond INTERNAL
bool
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::_iceD_getAll(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    ::Ice::Int iceP_robotid;
    ::std::string iceP_camera;
    istr->read(iceP_robotid);
    istr->read(iceP_camera);
    inS.endReadParams();
    TRGBD ret = this->getAll(iceP_robotid, iceP_camera, current);
    ::Ice::OutputStream* ostr = inS.startWriteParams();
    ostr->write(ret);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::_iceD_getDepth(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    ::Ice::Int iceP_robotid;
    ::std::string iceP_camera;
    istr->read(iceP_robotid);
    istr->read(iceP_camera);
    inS.endReadParams();
    TDepth ret = this->getDepth(iceP_robotid, iceP_camera, current);
    ::Ice::OutputStream* ostr = inS.startWriteParams();
    ostr->write(ret);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::_iceD_getImage(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    ::Ice::Int iceP_robotid;
    ::std::string iceP_camera;
    istr->read(iceP_robotid);
    istr->read(iceP_camera);
    inS.endReadParams();
    TImage ret = this->getImage(iceP_robotid, iceP_camera, current);
    ::Ice::OutputStream* ostr = inS.startWriteParams();
    ostr->write(ret);
    inS.endWriteParams();
    return true;
}
/// \endcond

namespace
{
const ::std::string iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_all[] =
{
    "getAll",
    "getDepth",
    "getImage",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

}

/// \cond INTERNAL
bool
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_all, iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_all + 7, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_RoboCompCameraRGBDSimpleMulti_CameraRGBDSimpleMulti_all)
    {
        case 0:
        {
            return _iceD_getAll(in, current);
        }
        case 1:
        {
            return _iceD_getDepth(in, current);
        }
        case 2:
        {
            return _iceD_getImage(in, current);
        }
        case 3:
        {
            return _iceD_ice_id(in, current);
        }
        case 4:
        {
            return _iceD_ice_ids(in, current);
        }
        case 5:
        {
            return _iceD_ice_isA(in, current);
        }
        case 6:
        {
            return _iceD_ice_ping(in, current);
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
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::_iceWriteImpl(::Ice::OutputStream* ostr) const
{
    ostr->startSlice(ice_staticId(), -1, true);
    ::Ice::StreamWriter< CameraRGBDSimpleMulti, ::Ice::OutputStream>::write(ostr, *this);
    ostr->endSlice();
}

void
RoboCompCameraRGBDSimpleMulti::CameraRGBDSimpleMulti::_iceReadImpl(::Ice::InputStream* istr)
{
    istr->startSlice();
    ::Ice::StreamReader< CameraRGBDSimpleMulti, ::Ice::InputStream>::read(istr, *this);
    istr->endSlice();
}
/// \endcond

/// \cond INTERNAL
void
RoboCompCameraRGBDSimpleMulti::_icePatchObjectPtr(CameraRGBDSimpleMultiPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = CameraRGBDSimpleMultiPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(CameraRGBDSimpleMulti::ice_staticId(), v);
    }
}
/// \endcond

namespace Ice
{
}

#endif
