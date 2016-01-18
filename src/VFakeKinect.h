#pragma once

#include "VKinect.h"

namespace V {
    class FakeKinect : public Kinect
    {
    public:
        FakeKinect(){};
        ~FakeKinect(){};
        
        using Kinect::setup;
        void setup(const ci::ivec2 & _depthSize, const ci::ivec2 & _colorSize, int nodeTypeFlags);
        void update(){};
        
        ci::ImageSourceRef getColorImage(){ return tex_Color->createSource(); }
        ci::ImageSourceRef getDepthImage(){ return tex_Depth->createSource(); }
        
        class FakeDevice
        {
        public:
            void setAlignWithDepthGenerator(){};
            bool isDepthDataNew(){ return true; };
            bool isColorDataNew(){ return true; };
        };
        
        XnPoint3D * getDepthMapRealWorld() { return depthMapRealWorld; };
        FakeDevice * getDevice() { return &device; };
        
    private:
        FakeDevice device;
        XnPoint3D *depthMapRealWorld;
    };
}