#include "macros.h"
#include "NativeNodeUtils.h"
#include <opencv2/features2d.hpp>

#ifndef FF_BFMATCHER_H_
#define FF_BFMATCHER_H_

class BFMatcher : public Nan::ObjectWrap {
public:
    cv::BFMatcher bfmatcher;

	int normType;
	bool crossCheck;

	static NAN_MODULE_INIT(Init);
	static NAN_METHOD(New);

	static FF_GETTER(BFMatcher, GetNormType, normType)
	static FF_GETTER(BFMatcher, GetCrossCheck, crossCheck)

  static Nan::Persistent<v8::FunctionTemplate> constructor;

	cv::BFMatcher* getNativeObjectPtr() { return &bfmatcher; }
	cv::BFMatcher getNativeObject() { return bfmatcher; }

	typedef InstanceConverter<BFMatcher, cv::BFMatcher> Converter;

	static NAN_METHOD(Clone);
	static NAN_METHOD(Create);
	static NAN_METHOD(IsMaskSupported);
	static NAN_METHOD(KnnMatchImpl);
	static NAN_METHOD(RadiusMatchImpl);

    static const char* getClassName() {
        return "BFMatcher";
    }
};

#endif
