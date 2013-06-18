/* openrtb_parsing.h                                               -*- C++ -*-
   Jeremy Barnes, 22 February 2013
   Copyright (c) 2013 Datacratic Inc.  All rights reserved.

   Code to parse OpenRTB bid requests.
*/

#pragma once

#include "soa/types/value_description.h"
#include "soa/types/basic_value_descriptions.h"
#include "soa/types/json_parsing.h"
#include "openrtb.h"
#include <boost/lexical_cast.hpp>

namespace Datacratic {

template<>
struct DefaultDescription<OpenRTB::TaggedBool>
    : public ValueDescriptionI<OpenRTB::TaggedBool, ValueKind::BOOLEAN> {
  
    virtual void parseJsonTyped(OpenRTB::TaggedBool * val,
                                JsonParsingContext & context) const
    {
        if (context.isBool())
            val->val = context.expectBool();
        else val->val = context.expectInt();
    }

    virtual void printJsonTyped(const OpenRTB::TaggedBool * val,
                                JsonPrintingContext & context) const
    {
        context.writeInt(val->val);
    }

    virtual bool isDefaultTyped(const OpenRTB::TaggedBool * val)
        const
    {
        return val->val == -1;
    }
};

template<int defValue>
struct DefaultDescription<OpenRTB::TaggedBoolDef<defValue> >
    : public ValueDescriptionI<OpenRTB::TaggedBoolDef<defValue>,
                               ValueKind::BOOLEAN> {
  
    virtual void parseJsonTyped(OpenRTB::TaggedBoolDef<defValue> * val,
                                JsonParsingContext & context) const
    {
        if (context.isBool())
            val->val = context.expectBool();
        else val->val = context.expectInt();
    }

    virtual void printJsonTyped(const OpenRTB::TaggedBoolDef<defValue> * val,
                                JsonPrintingContext & context) const
    {
        context.writeInt(val->val);
    }

    virtual bool isDefaultTyped(const OpenRTB::TaggedBoolDef<defValue> * val)
        const
    {
        return val->val == defValue;
    }
};

template<>
struct DefaultDescription<OpenRTB::TaggedInt>
    : public ValueDescriptionI<OpenRTB::TaggedInt,
                               ValueKind::INTEGER,
                               DefaultDescription<OpenRTB::TaggedInt> > {

    virtual void parseJsonTyped(OpenRTB::TaggedInt * val,
                                JsonParsingContext & context) const
    {
        if (context.isString()) {
            std::string s = context.expectStringAscii();
            val->val = boost::lexical_cast<int>(s);
        }
        else val->val = context.expectInt();
    }

    virtual void printJsonTyped(const OpenRTB::TaggedInt * val,
                                JsonPrintingContext & context) const
    {
        context.writeInt(val->val);
    }

    virtual bool isDefaultTyped(const OpenRTB::TaggedInt * val)
        const
    {
        return val->val == -1;
    }
};

template<int defValue>
struct DefaultDescription<OpenRTB::TaggedIntDef<defValue> >
    : public ValueDescriptionI<OpenRTB::TaggedIntDef<defValue>,
                               ValueKind::INTEGER> {

    virtual void parseJsonTyped(OpenRTB::TaggedIntDef<defValue> * val,
                                JsonParsingContext & context) const
    {
        if (context.isString()) {
            std::string s = context.expectStringAscii();
            val->val = boost::lexical_cast<int>(s);
        }
        else val->val = context.expectInt();
    }

    virtual void printJsonTyped(const OpenRTB::TaggedIntDef<defValue> * val,
                                JsonPrintingContext & context) const
    {
        context.writeInt(val->val);
    }

    virtual bool isDefaultTyped(const OpenRTB::TaggedIntDef<defValue> * val)
        const
    {
        return val->val == defValue;
    }
};

template<>
struct DefaultDescription<OpenRTB::TaggedInt64>
: public ValueDescriptionI<OpenRTB::TaggedInt64,
                           ValueKind::INTEGER,
                           DefaultDescription<OpenRTB::TaggedInt64> > {
    
    virtual void parseJsonTyped(OpenRTB::TaggedInt64 * val,
                                JsonParsingContext & context) const
    {
        if (context.isString()) {
            std::string s = context.expectStringAscii();
            val->val = boost::lexical_cast<int64_t>(s);
        }
        else val->val = context.expectInt64();
    }

    virtual void printJsonTyped(const OpenRTB::TaggedInt64 * val,
                                JsonPrintingContext & context) const
    {
        context.writeInt64(val->val);
    }

    virtual bool isDefaultTyped(const OpenRTB::TaggedInt64 * val) const
    {
        return val->val == -1;
    }
};

template<int64_t defValue>
struct DefaultDescription<OpenRTB::TaggedInt64Def<defValue> >
  : public ValueDescriptionI<OpenRTB::TaggedInt64Def<defValue>, ValueKind::INTEGER > {

    virtual void parseJsonTyped(OpenRTB::TaggedInt64Def<defValue> * val,
                                JsonParsingContext & context) const
    {
        if (context.isString()) {
            std::string s = context.expectStringAscii();
            val->val = boost::lexical_cast<int64_t>(s);
        }
        else val->val = context.expectInt64();
    }

    virtual void printJsonTyped(const OpenRTB::TaggedInt64Def<defValue> * val,
                                JsonPrintingContext & context) const
    {
        context.writeInt64(val->val);
    }

    virtual bool isDefaultTyped(const OpenRTB::TaggedInt64Def<defValue> * val) const
    {
        return val->val == defValue;
    }
};

template<>
struct DefaultDescription<OpenRTB::TaggedFloat>
    : public ValueDescriptionI<OpenRTB::TaggedFloat,
                               ValueKind::FLOAT> {

    virtual void parseJsonTyped(OpenRTB::TaggedFloat * val,
                                JsonParsingContext & context) const
    {
        val->val = context.expectFloat();
    }

    virtual void printJsonTyped(const OpenRTB::TaggedFloat * val,
                                JsonPrintingContext & context) const
    {
        context.writeDouble(val->val);
    }

    virtual bool isDefaultTyped(const OpenRTB::TaggedFloat * val) const
    {
        return isnan(val->val);
    }
};

template<int num, int den>
struct DefaultDescription<OpenRTB::TaggedFloatDef<num, den> >
    : public ValueDescriptionI<OpenRTB::TaggedFloatDef<num, den>,
                               ValueKind::FLOAT> {

    virtual void parseJsonTyped(OpenRTB::TaggedFloatDef<num, den> * val,
                                JsonParsingContext & context) const
    {
        val->val = context.expectFloat();
    }

    virtual void printJsonTyped(const OpenRTB::TaggedFloatDef<num, den> * val,
                                JsonPrintingContext & context) const
    {
        context.writeFloat(val->val);
    }

    virtual bool isDefaultTyped(const OpenRTB::TaggedFloatDef<num, den> * val) const
    {
        return val->val == (float)num / den;
    }
};

template<>
struct DefaultDescription<OpenRTB::TaggedDouble>
: public ValueDescriptionI<OpenRTB::TaggedDouble,
                           ValueKind::FLOAT> {
    virtual void parseJsonTyped(OpenRTB::TaggedDouble * val,
                                JsonParsingContext & context) const
    {
        val->val = context.expectDouble();
    }

    virtual void printJsonTyped(const OpenRTB::TaggedDouble * val,
                                JsonPrintingContext & context) const
    {
        context.writeDouble(val->val);
    }
    
    virtual bool isDefaultTyped(const OpenRTB::TaggedDouble * val) const
    {
        return isnan(val->val);
    }
};

template<int num, int den>
struct DefaultDescription<OpenRTB::TaggedDoubleDef<num, den> >
: public ValueDescriptionI<OpenRTB::TaggedDoubleDef<num, den>,
                           ValueKind::FLOAT> {

    virtual void parseJsonTyped(OpenRTB::TaggedDoubleDef<num, den> * val,
                                JsonParsingContext & context) const
    {
        val->val = context.expectDouble();
    }

    virtual void printJsonTyped(const OpenRTB::TaggedDoubleDef<num, den> * val,
                                JsonPrintingContext & context) const
    {
        context.writeDouble(val->val);
    }

    virtual bool isDefaultTyped(const OpenRTB::TaggedDoubleDef<num, den> * val) const
    {
        return val->val == (double)num / den;
    }
};

template<class Enum>
struct TaggedEnumDescription
    : public ValueDescriptionI<Enum, ValueKind::ENUM,
                               TaggedEnumDescription<Enum> > {

    virtual void parseJsonTyped(Enum * val,
                                JsonParsingContext & context) const
    {
        int index = context.expectInt();
        val->val = index;
    }

    virtual void printJsonTyped(const Enum * val,
                                JsonPrintingContext & context) const
    {
        context.writeInt(val->val);
    }

    virtual bool isDefaultTyped(const Enum * val) const
    {
        return val->val == -1;
    }
};

/// Parser for banner w or h.  This can either be:
/// single format: "w": 123
/// multiple formats: "w": [ 123, 456 ]
struct FormatListDescription
    : public ValueDescriptionI<OpenRTB::List<int> >,
      public ListDescriptionBase<int> {

    virtual void parseJsonTyped(OpenRTB::List<int> * val,
                                JsonParsingContext & context) const
    {
        if (context.isArray()) {
            auto onElement = [&] ()
                {
                    val->push_back(context.expectInt());
                };
            context.forEachElement(onElement);
        }
        else {
            val->push_back(context.expectInt());
        }
    }

    virtual void printJsonTyped(const OpenRTB::List<int> * val,
                                JsonPrintingContext & context) const
    {
        if (val->size() == 1) {
            this->inner->printJsonTyped(&(*val)[0], context);
        }
        else
            printJsonTypedList(val, context);
    }

    virtual bool isDefaultTyped(const OpenRTB::List<int> * val) const
    {
        return val->empty();
    }

};

struct CommaSeparatedListDescription
    : public ValueDescriptionI<std::string, ValueKind::STRING> {

    virtual void parseJsonTyped(std::string * val,
                                JsonParsingContext & context) const
    {
        if (context.isArray()) {
            std::string res;
            auto onElement = [&] ()
                {
                    std::string s = context.expectStringAscii();
                    if (!res.empty())
                        res += ", ";
                    res += s;
                        
                };
            context.forEachElement(onElement);
            *val = res;
        }
        else {
            *val = context.expectStringAscii();
        }
    }

    virtual void printJsonTyped(const std::string * val,
                                JsonPrintingContext & context) const
    {
        context.writeString(*val);
    }

    virtual bool isDefaultTyped(const std::string * val) const
    {
        return val->empty();
    }

};

template<typename T>
struct DefaultDescription<OpenRTB::Optional<T> >
    : public ValueDescriptionI<OpenRTB::Optional<T>, ValueKind::OPTIONAL> {

    DefaultDescription(ValueDescriptionT<T> * inner
                       = getDefaultDescription((T *)0))
        : inner(inner)
    {
    }

    std::unique_ptr<ValueDescriptionT<T> > inner;

    virtual void parseJsonTyped(OpenRTB::Optional<T> * val,
                                JsonParsingContext & context) const
    {
        if (context.isNull()) {
            context.expectNull();
            val->reset();
        }
        val->reset(new T());
        inner->parseJsonTyped(val->get(), context);
    }

    virtual void printJsonTyped(const OpenRTB::Optional<T> * val,
                                JsonPrintingContext & context) const
    {
        if (!val->get())
            context.skip();
        else inner->printJsonTyped(val->get(), context);
    }

    virtual bool isDefaultTyped(const OpenRTB::Optional<T> * val) const
    {
        return !val->get();
    }

    virtual void * optionalMakeValueTyped(OpenRTB::Optional<T> * val) const
    {
        if (!val->get())
            val->reset(new T());
        return val->get();
    }

    virtual const void * optionalGetValueTyped(const OpenRTB::Optional<T> * val) const
    {
        if (!val->get())
            throw ML::Exception("no value in optional field");
        return val->get();
    }

    virtual const ValueDescription & contained() const
    {
        return *inner;
    }
};

template<typename T>
struct DefaultDescription<OpenRTB::List<T> >
    : public ValueDescriptionI<OpenRTB::List<T>, ValueKind::ARRAY>,
      public ListDescriptionBase<T> {

    virtual void parseJsonTyped(OpenRTB::List<T> * val,
                                JsonParsingContext & context) const
    {
        this->parseJsonTypedList(val, context);
    }

    virtual void printJsonTyped(const OpenRTB::List<T> * val,
                                JsonPrintingContext & context) const
    {
        this->printJsonTypedList(val, context);
    }

    virtual bool isDefaultTyped(const OpenRTB::List<T> * val) const
    {
        return val->empty();
    }

    virtual size_t getArrayLength(void * val) const
    {
        const OpenRTB::List<T> * val2 = reinterpret_cast<const OpenRTB::List<T> *>(val);
        return val2->size();
    }

    virtual void * getArrayElement(void * val, uint32_t element) const
    {
        OpenRTB::List<T> * val2 = reinterpret_cast<OpenRTB::List<T> *>(val);
        return &val2->at(element);
    }

    virtual const void * getArrayElement(const void * val, uint32_t element) const
    {
        const OpenRTB::List<T> * val2 = reinterpret_cast<const OpenRTB::List<T> *>(val);
        return &val2->at(element);
    }

    virtual void setArrayLength(void * val, size_t newLength) const
    {
        OpenRTB::List<T> * val2 = reinterpret_cast<OpenRTB::List<T> *>(val);
        val2->resize(newLength);
    }
    
    virtual const ValueDescription & contained() const
    {
        return *this->inner;
    }

};

template<>
struct DefaultDescription<OpenRTB::ContentCategory>
    : public ValueDescriptionI<OpenRTB::ContentCategory> {

    DefaultDescription()
    {
    }

    virtual void parseJsonTyped(OpenRTB::ContentCategory * val,
                                JsonParsingContext & context) const
    {
        val->val = context.expectStringAscii();
    }

    virtual void printJsonTyped(const OpenRTB::ContentCategory * val,
                                JsonPrintingContext & context) const
    {
        context.writeString(val->val);
    }
};

template<>
struct DefaultDescription<OpenRTB::MimeType>
    : public ValueDescriptionI<OpenRTB::MimeType, ValueKind::STRING> {

    virtual void parseJsonTyped(OpenRTB::MimeType * val,
                                JsonParsingContext & context) const
    {
        val->type = context.expectStringAscii();
    }

    virtual void printJsonTyped(const OpenRTB::MimeType * val,
                                JsonPrintingContext & context) const
    {
        context.writeString(val->type);
    }
};

template<>
struct DefaultDescription<OpenRTB::VideoQuality>
    : public TaggedEnumDescription<OpenRTB::VideoQuality> {
    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::AuctionType>
    : public TaggedEnumDescription<OpenRTB::AuctionType> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::BannerAdType>
    : public TaggedEnumDescription<OpenRTB::BannerAdType> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::CreativeAttribute>
    : public TaggedEnumDescription<OpenRTB::CreativeAttribute> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::ApiFramework>
    : public TaggedEnumDescription<OpenRTB::ApiFramework> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::VideoLinearity>
    : public TaggedEnumDescription<OpenRTB::VideoLinearity> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::VideoBidResponseProtocol>
    : public TaggedEnumDescription<OpenRTB::VideoBidResponseProtocol> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::VideoPlaybackMethod>
    : public TaggedEnumDescription<OpenRTB::VideoPlaybackMethod> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::VideoStartDelay>
    : public TaggedEnumDescription<OpenRTB::VideoStartDelay> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::ConnectionType>
    : public TaggedEnumDescription<OpenRTB::ConnectionType> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::ExpandableDirection>
    : public TaggedEnumDescription<OpenRTB::ExpandableDirection> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::ContentDeliveryMethod>
    : public TaggedEnumDescription<OpenRTB::ContentDeliveryMethod> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::ContentContext>
    : public TaggedEnumDescription<OpenRTB::ContentContext> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::LocationType>
    : public TaggedEnumDescription<OpenRTB::LocationType> {

    DefaultDescription()
    {
    }
};


template<>
struct DefaultDescription<OpenRTB::DeviceType>
    : public TaggedEnumDescription<OpenRTB::DeviceType> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::VastCompanionType>
    : public TaggedEnumDescription<OpenRTB::VastCompanionType> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::MediaRating>
    : public TaggedEnumDescription<OpenRTB::MediaRating> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::FramePosition>
    : public TaggedEnumDescription<OpenRTB::FramePosition> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::SourceRelationship>
    : public TaggedEnumDescription<OpenRTB::SourceRelationship> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::AdPosition>
    : public TaggedEnumDescription<OpenRTB::AdPosition> {

    DefaultDescription()
    {
    }
};

template<>
struct DefaultDescription<OpenRTB::BidRequest>
    : public StructureDescription<OpenRTB::BidRequest> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::Impression>
    : public StructureDescription<OpenRTB::Impression> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::Banner>
    : public StructureDescription<OpenRTB::Banner> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::Video>
    : public StructureDescription<OpenRTB::Video> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::Content>
    : public StructureDescription<OpenRTB::Content> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::Context>
    : public StructureDescription<OpenRTB::Context> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::Site>
    : public StructureDescription<OpenRTB::Site> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::App>
    : public StructureDescription<OpenRTB::App> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::Device>
    : public StructureDescription<OpenRTB::Device> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::User>
    : public StructureDescription<OpenRTB::User> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::Publisher>
    : public StructureDescription<OpenRTB::Publisher> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::Geo>
    : public StructureDescription<OpenRTB::Geo> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::Data>
    : public StructureDescription<OpenRTB::Data> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::Segment>
    : public StructureDescription<OpenRTB::Segment> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::Bid>
    : public StructureDescription<OpenRTB::Bid> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::SeatBid>
    : public StructureDescription<OpenRTB::SeatBid> {
    DefaultDescription();
};

template<>
struct DefaultDescription<OpenRTB::BidResponse>
    : public StructureDescription<OpenRTB::BidResponse> {
    DefaultDescription();
};




} // namespace Datacratic
