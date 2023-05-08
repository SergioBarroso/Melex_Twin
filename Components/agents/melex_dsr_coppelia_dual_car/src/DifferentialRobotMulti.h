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

#ifndef __DifferentialRobotMulti_h__
#define __DifferentialRobotMulti_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/ValueF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Comparable.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/GCObject.h>
#include <Ice/Value.h>
#include <Ice/Incoming.h>
#include <Ice/FactoryTableInit.h>
#include <IceUtil/ScopedArray.h>
#include <Ice/Optional.h>
#include <Ice/ExceptionHelpers.h>
#include <GenericBase.h>
#include <IceUtil/UndefSysMacros.h>

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

namespace RoboCompDifferentialRobotMulti
{

class DifferentialRobotMulti;
class DifferentialRobotMultiPrx;

}

namespace RoboCompDifferentialRobotMulti
{

struct TMechParams
{
    int wheelRadius;
    int axisLength;
    int encoderSteps;
    int gearRatio;
    float temp;
    ::std::string device;
    ::std::string handler;
    float maxVelAdv;
    float maxVelRot;

    /**
     * Obtains a tuple containing all of the struct's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const int&, const int&, const int&, const int&, const float&, const ::std::string&, const ::std::string&, const float&, const float&> ice_tuple() const
    {
        return std::tie(wheelRadius, axisLength, encoderSteps, gearRatio, temp, device, handler, maxVelAdv, maxVelRot);
    }
};

using Ice::operator<;
using Ice::operator<=;
using Ice::operator>;
using Ice::operator>=;
using Ice::operator==;
using Ice::operator!=;

}

namespace RoboCompDifferentialRobotMulti
{

class DifferentialRobotMulti : public virtual ::Ice::Object
{
public:

    using ProxyType = DifferentialRobotMultiPrx;

    /**
     * Determines whether this object supports an interface with the given Slice type ID.
     * @param id The fully-scoped Slice type ID.
     * @param current The Current object for the invocation.
     * @return True if this object supports the interface, false, otherwise.
     */
    virtual bool ice_isA(::std::string id, const ::Ice::Current& current) const override;

    /**
     * Obtains a list of the Slice type IDs representing the interfaces supported by this object.
     * @param current The Current object for the invocation.
     * @return A list of fully-scoped type IDs.
     */
    virtual ::std::vector<::std::string> ice_ids(const ::Ice::Current& current) const override;

    /**
     * Obtains a Slice type ID representing the most-derived interface supported by this object.
     * @param current The Current object for the invocation.
     * @return A fully-scoped type ID.
     */
    virtual ::std::string ice_id(const ::Ice::Current& current) const override;

    /**
     * Obtains the Slice type ID corresponding to this class.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

    virtual void getBaseState(int robotid, ::RoboCompGenericBase::TBaseState& state, const ::Ice::Current& current) = 0;
    /// \cond INTERNAL
    bool _iceD_getBaseState(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    virtual void setSpeedBase(int robotid, float adv, float rot, const ::Ice::Current& current) = 0;
    /// \cond INTERNAL
    bool _iceD_setSpeedBase(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    /// \cond INTERNAL
    virtual bool _iceDispatch(::IceInternal::Incoming&, const ::Ice::Current&) override;
    /// \endcond
};

}

namespace RoboCompDifferentialRobotMulti
{

class DifferentialRobotMultiPrx : public virtual ::Ice::Proxy<DifferentialRobotMultiPrx, ::Ice::ObjectPrx>
{
public:

    void getBaseState(int robotid, ::RoboCompGenericBase::TBaseState& state, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        state = _makePromiseOutgoing<::RoboCompGenericBase::TBaseState>(true, this, &DifferentialRobotMultiPrx::_iceI_getBaseState, robotid, context).get();
    }

    template<template<typename> class P = ::std::promise>
    auto getBaseStateAsync(int robotid, const ::Ice::Context& context = ::Ice::noExplicitContext)
        -> decltype(::std::declval<P<::RoboCompGenericBase::TBaseState>>().get_future())
    {
        return _makePromiseOutgoing<::RoboCompGenericBase::TBaseState, P>(false, this, &DifferentialRobotMultiPrx::_iceI_getBaseState, robotid, context);
    }

    ::std::function<void()>
    getBaseStateAsync(int robotid,
                      ::std::function<void(::RoboCompGenericBase::TBaseState)> response,
                      ::std::function<void(::std::exception_ptr)> ex = nullptr,
                      ::std::function<void(bool)> sent = nullptr,
                      const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _makeLamdaOutgoing<::RoboCompGenericBase::TBaseState>(response, ex, sent, this, &RoboCompDifferentialRobotMulti::DifferentialRobotMultiPrx::_iceI_getBaseState, robotid, context);
    }

    /// \cond INTERNAL
    void _iceI_getBaseState(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<::RoboCompGenericBase::TBaseState>>&, int, const ::Ice::Context&);
    /// \endcond

    void setSpeedBase(int robotid, float adv, float rot, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        _makePromiseOutgoing<void>(true, this, &DifferentialRobotMultiPrx::_iceI_setSpeedBase, robotid, adv, rot, context).get();
    }

    template<template<typename> class P = ::std::promise>
    auto setSpeedBaseAsync(int robotid, float adv, float rot, const ::Ice::Context& context = ::Ice::noExplicitContext)
        -> decltype(::std::declval<P<void>>().get_future())
    {
        return _makePromiseOutgoing<void, P>(false, this, &DifferentialRobotMultiPrx::_iceI_setSpeedBase, robotid, adv, rot, context);
    }

    ::std::function<void()>
    setSpeedBaseAsync(int robotid, float adv, float rot,
                      ::std::function<void()> response,
                      ::std::function<void(::std::exception_ptr)> ex = nullptr,
                      ::std::function<void(bool)> sent = nullptr,
                      const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _makeLamdaOutgoing<void>(response, ex, sent, this, &RoboCompDifferentialRobotMulti::DifferentialRobotMultiPrx::_iceI_setSpeedBase, robotid, adv, rot, context);
    }

    /// \cond INTERNAL
    void _iceI_setSpeedBase(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>&, int, float, float, const ::Ice::Context&);
    /// \endcond

    /**
     * Obtains the Slice type ID of this interface.
     * @return The fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

protected:

    /// \cond INTERNAL
    DifferentialRobotMultiPrx() = default;
    friend ::std::shared_ptr<DifferentialRobotMultiPrx> IceInternal::createProxy<DifferentialRobotMultiPrx>();

    virtual ::std::shared_ptr<::Ice::ObjectPrx> _newInstance() const override;
    /// \endcond
};

}

/// \cond STREAM
namespace Ice
{

template<>
struct StreamableTraits<::RoboCompDifferentialRobotMulti::TMechParams>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 30;
    static const bool fixedLength = false;
};

template<typename S>
struct StreamReader<::RoboCompDifferentialRobotMulti::TMechParams, S>
{
    static void read(S* istr, ::RoboCompDifferentialRobotMulti::TMechParams& v)
    {
        istr->readAll(v.wheelRadius, v.axisLength, v.encoderSteps, v.gearRatio, v.temp, v.device, v.handler, v.maxVelAdv, v.maxVelRot);
    }
};

}
/// \endcond

/// \cond INTERNAL
namespace RoboCompDifferentialRobotMulti
{

using DifferentialRobotMultiPtr = ::std::shared_ptr<DifferentialRobotMulti>;
using DifferentialRobotMultiPrxPtr = ::std::shared_ptr<DifferentialRobotMultiPrx>;

}
/// \endcond

#else // C++98 mapping

namespace IceProxy
{

namespace RoboCompDifferentialRobotMulti
{

class DifferentialRobotMulti;
/// \cond INTERNAL
void _readProxy(::Ice::InputStream*, ::IceInternal::ProxyHandle< DifferentialRobotMulti>&);
::IceProxy::Ice::Object* upCast(DifferentialRobotMulti*);
/// \endcond

}

}

namespace RoboCompDifferentialRobotMulti
{

class DifferentialRobotMulti;
/// \cond INTERNAL
::Ice::Object* upCast(DifferentialRobotMulti*);
/// \endcond
typedef ::IceInternal::Handle< DifferentialRobotMulti> DifferentialRobotMultiPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti> DifferentialRobotMultiPrx;
typedef DifferentialRobotMultiPrx DifferentialRobotMultiPrxPtr;
/// \cond INTERNAL
void _icePatchObjectPtr(DifferentialRobotMultiPtr&, const ::Ice::ObjectPtr&);
/// \endcond

}

namespace RoboCompDifferentialRobotMulti
{

struct TMechParams
{
    ::Ice::Int wheelRadius;
    ::Ice::Int axisLength;
    ::Ice::Int encoderSteps;
    ::Ice::Int gearRatio;
    ::Ice::Float temp;
    ::std::string device;
    ::std::string handler;
    ::Ice::Float maxVelAdv;
    ::Ice::Float maxVelRot;
};

}

namespace RoboCompDifferentialRobotMulti
{

/**
 * Base class for asynchronous callback wrapper classes used for calls to
 * IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_getBaseState.
 * Create a wrapper instance by calling ::RoboCompDifferentialRobotMulti::newCallback_DifferentialRobotMulti_getBaseState.
 */
class Callback_DifferentialRobotMulti_getBaseState_Base : public virtual ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_DifferentialRobotMulti_getBaseState_Base> Callback_DifferentialRobotMulti_getBaseStatePtr;

/**
 * Base class for asynchronous callback wrapper classes used for calls to
 * IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_setSpeedBase.
 * Create a wrapper instance by calling ::RoboCompDifferentialRobotMulti::newCallback_DifferentialRobotMulti_setSpeedBase.
 */
class Callback_DifferentialRobotMulti_setSpeedBase_Base : public virtual ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_DifferentialRobotMulti_setSpeedBase_Base> Callback_DifferentialRobotMulti_setSpeedBasePtr;

}

namespace IceProxy
{

namespace RoboCompDifferentialRobotMulti
{

class DifferentialRobotMulti : public virtual ::Ice::Proxy<DifferentialRobotMulti, ::IceProxy::Ice::Object>
{
public:

    void getBaseState(::Ice::Int robotid, ::RoboCompGenericBase::TBaseState& state, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        end_getBaseState(state, _iceI_begin_getBaseState(robotid, context, ::IceInternal::dummyCallback, 0, true));
    }

    ::Ice::AsyncResultPtr begin_getBaseState(::Ice::Int robotid, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _iceI_begin_getBaseState(robotid, context, ::IceInternal::dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_getBaseState(::Ice::Int robotid, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_getBaseState(robotid, ::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_getBaseState(::Ice::Int robotid, const ::Ice::Context& context, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_getBaseState(robotid, context, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_getBaseState(::Ice::Int robotid, const ::RoboCompDifferentialRobotMulti::Callback_DifferentialRobotMulti_getBaseStatePtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_getBaseState(robotid, ::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_getBaseState(::Ice::Int robotid, const ::Ice::Context& context, const ::RoboCompDifferentialRobotMulti::Callback_DifferentialRobotMulti_getBaseStatePtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_getBaseState(robotid, context, cb, cookie);
    }

    void end_getBaseState(::RoboCompGenericBase::TBaseState& state, const ::Ice::AsyncResultPtr& result);
    /// \cond INTERNAL

    void _iceI_end_getBaseState(::RoboCompGenericBase::TBaseState& iceP_state, const ::Ice::AsyncResultPtr&);
    /// \endcond

private:

    ::Ice::AsyncResultPtr _iceI_begin_getBaseState(::Ice::Int, const ::Ice::Context&, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& cookie = 0, bool sync = false);

public:

    void setSpeedBase(::Ice::Int robotid, ::Ice::Float adv, ::Ice::Float rot, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        end_setSpeedBase(_iceI_begin_setSpeedBase(robotid, adv, rot, context, ::IceInternal::dummyCallback, 0, true));
    }

    ::Ice::AsyncResultPtr begin_setSpeedBase(::Ice::Int robotid, ::Ice::Float adv, ::Ice::Float rot, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _iceI_begin_setSpeedBase(robotid, adv, rot, context, ::IceInternal::dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_setSpeedBase(::Ice::Int robotid, ::Ice::Float adv, ::Ice::Float rot, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_setSpeedBase(robotid, adv, rot, ::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_setSpeedBase(::Ice::Int robotid, ::Ice::Float adv, ::Ice::Float rot, const ::Ice::Context& context, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_setSpeedBase(robotid, adv, rot, context, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_setSpeedBase(::Ice::Int robotid, ::Ice::Float adv, ::Ice::Float rot, const ::RoboCompDifferentialRobotMulti::Callback_DifferentialRobotMulti_setSpeedBasePtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_setSpeedBase(robotid, adv, rot, ::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_setSpeedBase(::Ice::Int robotid, ::Ice::Float adv, ::Ice::Float rot, const ::Ice::Context& context, const ::RoboCompDifferentialRobotMulti::Callback_DifferentialRobotMulti_setSpeedBasePtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_setSpeedBase(robotid, adv, rot, context, cb, cookie);
    }

    void end_setSpeedBase(const ::Ice::AsyncResultPtr& result);

private:

    ::Ice::AsyncResultPtr _iceI_begin_setSpeedBase(::Ice::Int, ::Ice::Float, ::Ice::Float, const ::Ice::Context&, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& cookie = 0, bool sync = false);

public:

    /**
     * Obtains the Slice type ID corresponding to this interface.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

protected:
    /// \cond INTERNAL

    virtual ::IceProxy::Ice::Object* _newInstance() const;
    /// \endcond
};

}

}

namespace RoboCompDifferentialRobotMulti
{

class DifferentialRobotMulti : public virtual ::Ice::Object
{
public:

    typedef DifferentialRobotMultiPrx ProxyType;
    typedef DifferentialRobotMultiPtr PointerType;

    virtual ~DifferentialRobotMulti();

    /**
     * Determines whether this object supports an interface with the given Slice type ID.
     * @param id The fully-scoped Slice type ID.
     * @param current The Current object for the invocation.
     * @return True if this object supports the interface, false, otherwise.
     */
    virtual bool ice_isA(const ::std::string& id, const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains a list of the Slice type IDs representing the interfaces supported by this object.
     * @param current The Current object for the invocation.
     * @return A list of fully-scoped type IDs.
     */
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains a Slice type ID representing the most-derived interface supported by this object.
     * @param current The Current object for the invocation.
     * @return A fully-scoped type ID.
     */
    virtual const ::std::string& ice_id(const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains the Slice type ID corresponding to this class.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

    virtual void getBaseState(::Ice::Int robotid, ::RoboCompGenericBase::TBaseState& state, const ::Ice::Current& current = ::Ice::emptyCurrent) = 0;
    /// \cond INTERNAL
    bool _iceD_getBaseState(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    virtual void setSpeedBase(::Ice::Int robotid, ::Ice::Float adv, ::Ice::Float rot, const ::Ice::Current& current = ::Ice::emptyCurrent) = 0;
    /// \cond INTERNAL
    bool _iceD_setSpeedBase(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    /// \cond INTERNAL
    virtual bool _iceDispatch(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

protected:

    /// \cond STREAM
    virtual void _iceWriteImpl(::Ice::OutputStream*) const;
    virtual void _iceReadImpl(::Ice::InputStream*);
    /// \endcond
};

/// \cond INTERNAL
inline bool operator==(const DifferentialRobotMulti& lhs, const DifferentialRobotMulti& rhs)
{
    return static_cast<const ::Ice::Object&>(lhs) == static_cast<const ::Ice::Object&>(rhs);
}

inline bool operator<(const DifferentialRobotMulti& lhs, const DifferentialRobotMulti& rhs)
{
    return static_cast<const ::Ice::Object&>(lhs) < static_cast<const ::Ice::Object&>(rhs);
}
/// \endcond

}

/// \cond STREAM
namespace Ice
{

template<>
struct StreamableTraits< ::RoboCompDifferentialRobotMulti::TMechParams>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 30;
    static const bool fixedLength = false;
};

template<typename S>
struct StreamWriter< ::RoboCompDifferentialRobotMulti::TMechParams, S>
{
    static void write(S* ostr, const ::RoboCompDifferentialRobotMulti::TMechParams& v)
    {
        ostr->write(v.wheelRadius);
        ostr->write(v.axisLength);
        ostr->write(v.encoderSteps);
        ostr->write(v.gearRatio);
        ostr->write(v.temp);
        ostr->write(v.device);
        ostr->write(v.handler);
        ostr->write(v.maxVelAdv);
        ostr->write(v.maxVelRot);
    }
};

template<typename S>
struct StreamReader< ::RoboCompDifferentialRobotMulti::TMechParams, S>
{
    static void read(S* istr, ::RoboCompDifferentialRobotMulti::TMechParams& v)
    {
        istr->read(v.wheelRadius);
        istr->read(v.axisLength);
        istr->read(v.encoderSteps);
        istr->read(v.gearRatio);
        istr->read(v.temp);
        istr->read(v.device);
        istr->read(v.handler);
        istr->read(v.maxVelAdv);
        istr->read(v.maxVelRot);
    }
};

}
/// \endcond

namespace RoboCompDifferentialRobotMulti
{

/**
 * Type-safe asynchronous callback wrapper class used for calls to
 * IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_getBaseState.
 * Create a wrapper instance by calling ::RoboCompDifferentialRobotMulti::newCallback_DifferentialRobotMulti_getBaseState.
 */
template<class T>
class CallbackNC_DifferentialRobotMulti_getBaseState : public Callback_DifferentialRobotMulti_getBaseState_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)(const ::RoboCompGenericBase::TBaseState&);

    CallbackNC_DifferentialRobotMulti_getBaseState(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), _response(cb)
    {
    }

    /// \cond INTERNAL
    virtual void completed(const ::Ice::AsyncResultPtr& result) const
    {
        DifferentialRobotMultiPrx proxy = DifferentialRobotMultiPrx::uncheckedCast(result->getProxy());
        ::RoboCompGenericBase::TBaseState iceP_state;
        try
        {
            proxy->end_getBaseState(iceP_state, result);
        }
        catch(const ::Ice::Exception& ex)
        {
            ::IceInternal::CallbackNC<T>::exception(result, ex);
            return;
        }
        if(_response)
        {
            (::IceInternal::CallbackNC<T>::_callback.get()->*_response)(iceP_state);
        }
    }
    /// \endcond

private:

    Response _response;
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_getBaseState.
 */
template<class T> Callback_DifferentialRobotMulti_getBaseStatePtr
newCallback_DifferentialRobotMulti_getBaseState(const IceUtil::Handle<T>& instance, void (T::*cb)(const ::RoboCompGenericBase::TBaseState&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_DifferentialRobotMulti_getBaseState<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_getBaseState.
 */
template<class T> Callback_DifferentialRobotMulti_getBaseStatePtr
newCallback_DifferentialRobotMulti_getBaseState(T* instance, void (T::*cb)(const ::RoboCompGenericBase::TBaseState&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_DifferentialRobotMulti_getBaseState<T>(instance, cb, excb, sentcb);
}

/**
 * Type-safe asynchronous callback wrapper class with cookie support used for calls to
 * IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_getBaseState.
 * Create a wrapper instance by calling ::RoboCompDifferentialRobotMulti::newCallback_DifferentialRobotMulti_getBaseState.
 */
template<class T, typename CT>
class Callback_DifferentialRobotMulti_getBaseState : public Callback_DifferentialRobotMulti_getBaseState_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const ::RoboCompGenericBase::TBaseState&, const CT&);

    Callback_DifferentialRobotMulti_getBaseState(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), _response(cb)
    {
    }

    /// \cond INTERNAL
    virtual void completed(const ::Ice::AsyncResultPtr& result) const
    {
        DifferentialRobotMultiPrx proxy = DifferentialRobotMultiPrx::uncheckedCast(result->getProxy());
        ::RoboCompGenericBase::TBaseState iceP_state;
        try
        {
            proxy->end_getBaseState(iceP_state, result);
        }
        catch(const ::Ice::Exception& ex)
        {
            ::IceInternal::Callback<T, CT>::exception(result, ex);
            return;
        }
        if(_response)
        {
            (::IceInternal::Callback<T, CT>::_callback.get()->*_response)(iceP_state, CT::dynamicCast(result->getCookie()));
        }
    }
    /// \endcond

private:

    Response _response;
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_getBaseState.
 */
template<class T, typename CT> Callback_DifferentialRobotMulti_getBaseStatePtr
newCallback_DifferentialRobotMulti_getBaseState(const IceUtil::Handle<T>& instance, void (T::*cb)(const ::RoboCompGenericBase::TBaseState&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_DifferentialRobotMulti_getBaseState<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_getBaseState.
 */
template<class T, typename CT> Callback_DifferentialRobotMulti_getBaseStatePtr
newCallback_DifferentialRobotMulti_getBaseState(T* instance, void (T::*cb)(const ::RoboCompGenericBase::TBaseState&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_DifferentialRobotMulti_getBaseState<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Type-safe asynchronous callback wrapper class used for calls to
 * IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_setSpeedBase.
 * Create a wrapper instance by calling ::RoboCompDifferentialRobotMulti::newCallback_DifferentialRobotMulti_setSpeedBase.
 */
template<class T>
class CallbackNC_DifferentialRobotMulti_setSpeedBase : public Callback_DifferentialRobotMulti_setSpeedBase_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)();

    CallbackNC_DifferentialRobotMulti_setSpeedBase(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), _response(cb)
    {
    }

    /// \cond INTERNAL
    virtual void completed(const ::Ice::AsyncResultPtr& result) const
    {
        DifferentialRobotMultiPrx proxy = DifferentialRobotMultiPrx::uncheckedCast(result->getProxy());
        try
        {
            proxy->end_setSpeedBase(result);
        }
        catch(const ::Ice::Exception& ex)
        {
            ::IceInternal::CallbackNC<T>::exception(result, ex);
            return;
        }
        if(_response)
        {
            (::IceInternal::CallbackNC<T>::_callback.get()->*_response)();
        }
    }
    /// \endcond

private:

    Response _response;
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_setSpeedBase.
 */
template<class T> Callback_DifferentialRobotMulti_setSpeedBasePtr
newCallback_DifferentialRobotMulti_setSpeedBase(const IceUtil::Handle<T>& instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_DifferentialRobotMulti_setSpeedBase<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_setSpeedBase.
 */
template<class T> Callback_DifferentialRobotMulti_setSpeedBasePtr
newCallback_DifferentialRobotMulti_setSpeedBase(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_DifferentialRobotMulti_setSpeedBase<T>(instance, 0, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_setSpeedBase.
 */
template<class T> Callback_DifferentialRobotMulti_setSpeedBasePtr
newCallback_DifferentialRobotMulti_setSpeedBase(T* instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_DifferentialRobotMulti_setSpeedBase<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_setSpeedBase.
 */
template<class T> Callback_DifferentialRobotMulti_setSpeedBasePtr
newCallback_DifferentialRobotMulti_setSpeedBase(T* instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_DifferentialRobotMulti_setSpeedBase<T>(instance, 0, excb, sentcb);
}

/**
 * Type-safe asynchronous callback wrapper class with cookie support used for calls to
 * IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_setSpeedBase.
 * Create a wrapper instance by calling ::RoboCompDifferentialRobotMulti::newCallback_DifferentialRobotMulti_setSpeedBase.
 */
template<class T, typename CT>
class Callback_DifferentialRobotMulti_setSpeedBase : public Callback_DifferentialRobotMulti_setSpeedBase_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const CT&);

    Callback_DifferentialRobotMulti_setSpeedBase(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), _response(cb)
    {
    }

    /// \cond INTERNAL
    virtual void completed(const ::Ice::AsyncResultPtr& result) const
    {
        DifferentialRobotMultiPrx proxy = DifferentialRobotMultiPrx::uncheckedCast(result->getProxy());
        try
        {
            proxy->end_setSpeedBase(result);
        }
        catch(const ::Ice::Exception& ex)
        {
            ::IceInternal::Callback<T, CT>::exception(result, ex);
            return;
        }
        if(_response)
        {
            (::IceInternal::Callback<T, CT>::_callback.get()->*_response)(CT::dynamicCast(result->getCookie()));
        }
    }
    /// \endcond

private:

    Response _response;
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_setSpeedBase.
 */
template<class T, typename CT> Callback_DifferentialRobotMulti_setSpeedBasePtr
newCallback_DifferentialRobotMulti_setSpeedBase(const IceUtil::Handle<T>& instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_DifferentialRobotMulti_setSpeedBase<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_setSpeedBase.
 */
template<class T, typename CT> Callback_DifferentialRobotMulti_setSpeedBasePtr
newCallback_DifferentialRobotMulti_setSpeedBase(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_DifferentialRobotMulti_setSpeedBase<T, CT>(instance, 0, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_setSpeedBase.
 */
template<class T, typename CT> Callback_DifferentialRobotMulti_setSpeedBasePtr
newCallback_DifferentialRobotMulti_setSpeedBase(T* instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_DifferentialRobotMulti_setSpeedBase<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompDifferentialRobotMulti::DifferentialRobotMulti::begin_setSpeedBase.
 */
template<class T, typename CT> Callback_DifferentialRobotMulti_setSpeedBasePtr
newCallback_DifferentialRobotMulti_setSpeedBase(T* instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_DifferentialRobotMulti_setSpeedBase<T, CT>(instance, 0, excb, sentcb);
}

}

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif