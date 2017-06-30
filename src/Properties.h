#pragma once

#include <nan.h>

#include "obspp/obspp-properties.hpp"
#include "Common.h"

namespace osn {

class Properties : public Nan::ObjectWrap {
public:
    static Nan::Persistent<v8::FunctionTemplate> prototype;
    obs::properties handle;

    typedef common::Object<Properties, obs::properties> Object;
    friend Object;

    Properties(obs::properties &properties) = delete;
    Properties(obs::properties &&properties);
    Properties(std::string id, obs::properties::object_type type);

    static NAN_MODULE_INIT(Init);

    /* NOTE Can create properties with an id but if you want 
       properties that corresond to an object, call the properties
       method on that object. */
    static NAN_METHOD(New);

    static NAN_GETTER(status);
    static NAN_METHOD(first);
    static NAN_METHOD(count);
    static NAN_METHOD(get);
    static NAN_METHOD(apply);
    static NAN_METHOD(items);
};

class Property : public Nan::ObjectWrap {
public:
    static Nan::Persistent<v8::FunctionTemplate> prototype;
    obs::property handle;

    typedef common::Object<Property, obs::property> Object;
    friend Object;

    Property(obs::property &property);

    static NAN_MODULE_INIT(Init);
    /* Can only be created through properties */
    static NAN_GETTER(status);
    static NAN_GETTER(name);
    static NAN_GETTER(description);
    static NAN_GETTER(longDescription);
    static NAN_GETTER(type);
    static NAN_GETTER(enabled);
    static NAN_GETTER(visible);
    static NAN_METHOD(getListProperty);
    static NAN_METHOD(next);
};

class ListProperty : public Nan::ObjectWrap {
public:
    static NAN_MODULE_INIT(Init);
    static NAN_GETTER(items);
};

class IntegerProperty : public Nan::ObjectWrap {
public:
    static NAN_MODULE_INIT(Init);
};

class FloatProperty : public Nan::ObjectWrap {
public:
    static NAN_MODULE_INIT(Init);
};

class TextProperty : public Nan::ObjectWrap {
public:
    static NAN_MODULE_INIT(Init);
};

class PathProperty : public Nan::ObjectWrap {
public:
    static NAN_MODULE_INIT(Init);
};

}